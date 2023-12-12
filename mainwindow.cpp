#include "mainwindow.h"
#include "ui_mainwindow.h"

QMutex mutex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _currentPage = 1;
    _rowsPerPage = 10;
    _maxPageModel = 5;
    _minPageModel = 1;
    _limit = _rowsPerPage * _maxPageModel;
    _filterDialog = new FilterDialog(this);
    _resultIsFound = false;
    _typeSearch = "%";

    _searchTimer.setSingleShot(true);
    _goToPageTimer.setSingleShot(true);

    _typeSort =
    {
        {0, " ASC"},
        {1, " DESC"}
    };

    // Устанавливаем жирный шрифт для заголовков столбцов
    QFont font = ui->tableView->horizontalHeader()->font();
    font.setBold(true);
    ui->tableView->horizontalHeader()->setFont(font);

    //Скраваю номер строк в tableView
    ui->tableView->verticalHeader()->setVisible(false);

    // Устанавливаем растягивание для заголовков строк и столбцов
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Заперт редактирования данных в ячейке
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Для выделения всей строки
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    _query = QSharedPointer<QSqlQueryModel>::create();
    _db = QSharedPointer<QSqlDatabase>::create(QSqlDatabase::addDatabase("QSQLITE"));
    _db->setDatabaseName("Database/name.sqlite");

    for(int i = 0; i < 3; i++)
        _models.push_back(QSharedPointer<QSqlTableModel>::create(this, *_db));

    _nextWatcher = QSharedPointer<MyThread>::create();
    _prevWatcher = QSharedPointer<MyThread>::create();
    _startWatcher = QSharedPointer<MyThread>::create();
    _getMaxPageWatcher = QSharedPointer<MyThread>::create();
    _searchWatcher = QSharedPointer<MyThread>::create();

    connect(_startWatcher.get(), &MyThread::taskFinished, this, &MainWindow::startLoadModelFinished);
    connect(_nextWatcher.get(), &MyThread::taskFinished, this, &MainWindow::threadFinished);
    connect(_prevWatcher.get(), &MyThread::taskFinished, this, &MainWindow::threadFinished);
    connect(_getMaxPageWatcher.get(), &MyThread::taskFinished, this, &MainWindow::loadingStartModel);
    connect(_searchWatcher.get(), &MyThread::taskFinished, this, [&]()
    {
        if(_resultIsFound)
            goToPage(_currentPage);
        else
            QMessageBox::warning(this, "Внимание", "Данных нет!", QMessageBox::Ok);
    });

    connect(_filterDialog, &FilterDialog::filterSelected, this, &MainWindow::setFilter);

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::refreshStartModel);
    connect(ui->comboBox_type_sort, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::refreshStartModel);
    connect(ui->pushButton_sort, &QPushButton::clicked, this, &MainWindow::refreshStartModel);

    connect(&_searchTimer, &QTimer::timeout, this, [=]()
    {
        if(!ui->searchText->text().isEmpty())
            searchInModels();
    });

    connect(&_goToPageTimer, &QTimer::timeout, this, [=]()
    {
        if(!ui->goToPage->text().isEmpty())
            goToPage(ui->goToPage->text().toInt());
    });

    ui->searchText->setValidator(new QRegExpValidator(QRegExp("[^\\d\\W_]+")));
    ui->goToPage->setValidator(new QIntValidator);

    refreshStartModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::completion(QSharedPointer<QSqlTableModel> model, QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, int limit, int offset, const QString& filters, const QString& sort)
{
    QMutexLocker locker(&mutex);
    QThread::sleep(2);

    db->open();

    QString filterLimit = QString(" LIMIT %1 OFFSET %2").arg(limit).arg(offset);

    QString request("CREATE TEMPORARY TABLE temp_name_pred AS SELECT ROW_NUMBER() OVER () AS №, sorted_data.* FROM "
                    "(SELECT * FROM name_pred ORDER BY " + sort + ") AS sorted_data WHERE 1=1" + filters + filterLimit);

//    qDebug() << request;

    query->setQuery(request, *db);
    model->setTable("temp_name_pred");
    model->select();
}

void MainWindow::getMaxPage(QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, int& maxPage, int rowsPerPage, const QString& filters)
{
    QMutexLocker locker(&mutex);
    db->open();

    QString request("SELECT COUNT(*) FROM name_pred WHERE 1=1 " + filters);
    query->setQuery(request, *db);
    double rowCount = query->data(query->index(0, 0)).toDouble();
    maxPage = static_cast<int>(std::ceil(rowCount / rowsPerPage));
}

void MainWindow::searchInDB(QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, const QString& column, const QString& like, const QString& typeSearch, const QString& filters, const QString& sort, int& currentPage, bool& resultIsFound)
{
    QMutexLocker locker(&mutex);
    db->open();

    QString request("SELECT numbered_rows.№ FROM (SELECT ROW_NUMBER() OVER "
                    "(ORDER BY " + sort + ") AS №, * FROM name_pred WHERE 1=1 " + filters +  ") AS numbered_rows WHERE numbered_rows." + column + " LIKE '" + like + typeSearch + "' LIMIT 1;");

//    qDebug() << request;

    query->setQuery(request, *db);

    if(query->rowCount() > 0)
    {
        double row = query->data(query->index(0, 0)).toDouble();
        currentPage = static_cast<int>(std::ceil(row / 10));
        resultIsFound = true;
    }
    else
        resultIsFound = false;
}

void MainWindow::loadingStartModel()
{
    if(_maxPage == 0)
    {
        QMessageBox::warning(this, "Внимание", "Данных нет!", QMessageBox::Ok);
        return;
    }

    ui->statusBar->showMessage("Идёт загрузка данных...");
    ui->tableView->setModel(nullptr);

    int setPages = _currentPage - currentPageInModel();

    int startOffset = setPages * _rowsPerPage;
    int nextOffset = (setPages + _maxPageModel) * _rowsPerPage;
    int prevOffset = (setPages - _maxPageModel) * _rowsPerPage;

    loadingModel(_startWatcher, _models[0], startOffset);
    loadingModel(_nextWatcher, _models[1], nextOffset);
    loadingModel(_prevWatcher, _models[2], prevOffset);
}

void MainWindow::loadingModel(QSharedPointer<MyThread> thread, QSharedPointer<QSqlTableModel> model, int offset)
{
    thread->setTask([=]() {
        completion(model, _query, _db, _limit, offset, std::ref(_filter), std::ref(_sort));
    });
    thread->start();
}


void MainWindow::startLoadModelFinished()
{
    blockingInterface(true);
    ui->statusBar->clearMessage();
    setModel(_models[0]);

    if(!_like.isEmpty())
        searchInModels();
}

void MainWindow::threadFinished()
{
    ui->nextButton->setEnabled(true);
    ui->prevButton->setEnabled(true);
}

void MainWindow::on_clearSearch_clicked()
{
    ui->searchText->clear();
}

void MainWindow::updateTablePage()
{
    updateCurrentPageInLabel();

    int startIndex = (currentPageInModel() - 1) * _rowsPerPage;
    int endIndex = startIndex + _rowsPerPage;

    _rowCountModel = ui->tableView->model()->rowCount();
    for (int row = 0; row < _rowCountModel; row++)
    {
        bool rowVisible = (row >= startIndex && row < endIndex);
        ui->tableView->setRowHidden(row, !rowVisible);
    }
}

void MainWindow::updateCurrentPageInLabel()
{
    ui->currentPage->setText(QString::number(_currentPage));
    ui->maxPage->setText(QString::number(_maxPage));
}

void MainWindow::on_goToPage_textChanged()
{
    if(ui->goToPage->text() == "0")
        ui->goToPage->clear();

    _goToPageTimer.start(1500);
}

void MainWindow::goToPage(int currentPage)
{
    _currentPage = (currentPage > _maxPage) ? _maxPage : currentPage;

    blockingInterface(false);
    loadingStartModel();
}

void MainWindow::on_prevButton_clicked()
{
    if(_currentPage > 1)
    {
        if(currentPageInModel() == _minPageModel)
        {
            if (!_prevWatcher->isRunning())
                goToPrevModel();
            else
                ui->prevButton->setEnabled(false);
        }
        else
        {
            _currentPage--;
            updateTablePage();
        }
    }
}

void MainWindow::on_nextButton_clicked()
{
    if(_currentPage < _maxPage)
    {
        if(currentPageInModel() == _maxPageModel)
        {
            if(!_nextWatcher->isRunning())
                goToNextModel();
            else
                ui->nextButton->setEnabled(false);
        }
        else
        {
            _currentPage++;
            updateTablePage();
        }
    }
    else
        QMessageBox::warning(this, "Внимание", "Данных больше нет!", QMessageBox::Ok);
}

void MainWindow::setModel(QSharedPointer<QSqlTableModel> model)
{
    ui->tableView->setModel(model.get());

    _rowCountModel = ui->tableView->model()->rowCount();

    if(model->columnCount() > 0)
        ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 14pt; }");

    updateTablePage();
}

void MainWindow::goToNextModel()
{
    _currentPage++;

    setModel(_models[1]);
    std::rotate(_models.begin(), _models.begin() + 1, _models.end());

    int nextOffset = (_currentPage + _maxPageModel - 1) * _rowsPerPage;
    loadingModel(_nextWatcher, _models[1], nextOffset);
}

void MainWindow::goToPrevModel()
{
    _currentPage--;

    setModel(_models[2]);
    std::rotate(_models.begin(), _models.begin() + (_models.size() - 1), _models.end());

    int prevOffset = (_currentPage - _maxPageModel * 2) * _rowsPerPage;
    loadingModel(_prevWatcher, _models[2], prevOffset);
}

void MainWindow::blockingInterface(bool flag)
{
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    for(QPushButton* button : buttons)
        button->setEnabled(flag);

    QList<QComboBox*> comboBoxs = ui->centralwidget->findChildren<QComboBox*>();
    for(QComboBox* comboBox : comboBoxs)
        comboBox->setEnabled(flag);

    ui->goToPage->setEnabled(flag);
}

void MainWindow::refreshStartModel()
{
    QString typeSort = _typeSort[ui->comboBox_type_sort->currentIndex()];
    QString column = ui->comboBox_2->currentText();
    _sort = column + typeSort;
    _like.clear();

    blockingInterface(false);

    ui->goToPage->clear();
    _currentPage = 1;

    _getMaxPageWatcher->setTask([=]() {
        getMaxPage(_query, _db, std::ref(_maxPage), _rowsPerPage, std::ref(_filter));
    });

    _getMaxPageWatcher->start();
}

void MainWindow::setFilter(const QString &filter)
{
    _filter = filter;
}

void MainWindow::on_addFilter_clicked()
{
    if (_filterDialog->exec() == QDialog::Accepted)
    {
        if(!_filter.isEmpty())
            refreshStartModel();
    }
}

void MainWindow::on_clearFilter_clicked()
{
    if(!_filter.isEmpty())
    {
        _filter.clear();
        _filterDialog->clearFilter();
        refreshStartModel();
    }
}

int MainWindow::currentPageInModel()
{
    int pageModel = _currentPage % _maxPageModel;

    if(pageModel == 0)
        pageModel = _maxPageModel;

    return pageModel;
}

void MainWindow::searchInModels()
{
    bool resultSearchInModel = false;
    _like = ui->searchText->text();
    _column = ui->comboBox->currentText();

    for (QSharedPointer<QSqlTableModel> model : _models)
    {
        for (int row = 0; row < model->rowCount(); row++)
        {
            QModelIndex index = model->index(row, ui->comboBox->currentIndex() + 1);
            QVariant data = model->data(index);

            if (_typeSearch == "%")
                resultSearchInModel = data.toString().startsWith(_like, Qt::CaseInsensitive);
            else
                resultSearchInModel = (data.toString().compare(_like, Qt::CaseInsensitive) == 0);

            if (resultSearchInModel)
            {
                double resultRow = model->data(model->index(row, 0)).toDouble();
                _currentPage = std::ceil(resultRow / _rowsPerPage);
                setModel(model);
                ui->tableView->setCurrentIndex(index);
                ui->tableView->setFocus();
                return;
            }
        }
    }

    _searchWatcher->setTask([=]() {
        searchInDB(_query, _db,  std::ref(_column),  std::ref(_like),  std::ref(_typeSearch),  std::ref(_filter), std::ref(_sort), std::ref(_currentPage), std::ref(_resultIsFound));
    });
    _searchWatcher->start();

}

void MainWindow::on_searchText_textChanged()
{
    _searchTimer.start(1000);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);

    if(!_like.isEmpty())
        searchInModels();
}

void MainWindow::on_resetTable_clicked()
{
    blockSignals(true);
    ui->searchText->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_type_sort->setCurrentIndex(0);
    blockSignals(false);

    _filterDialog->clearFilter();
    refreshStartModel();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 2)
        _typeSearch.clear();
    else if(arg1 == 0)
        _typeSearch = '%';
}

void MainWindow::on_pushButton_search_clicked()
{
    if(!ui->searchText->text().isEmpty())
        searchInModels();
}
