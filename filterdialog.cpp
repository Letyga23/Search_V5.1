#include "filterdialog.h"
#include "ui_filterdialog.h"
#include <QDebug>
#include <QIntValidator>

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filterDialog)
{
    ui->setupUi(this);

    QIntValidator* intValidator = new QIntValidator(this);
    ui->nameLenght->setValidator(intValidator);
    ui->surnameLenght->setValidator(intValidator);
    ui->ending->setValidator(new QRegExpValidator(QRegExp("[^\\d\\W_]+")));
    ui->beginning->setValidator(new QRegExpValidator(QRegExp("[^\\d\\W_]+")));

    _sign =
    {
        {0, ">"},
        {1, "<"}
    };

    _filterSelection =
    {
        {ui->nameLenght, ui->filter_1},
        {ui->surnameLenght, ui->filter_2},
        {ui->ending, ui->filter_3},
        {ui->beginning, ui->filter_4}
    };


    QList<QLineEdit*> lineEdits = findChildren<QLineEdit*>();
    for(QLineEdit* lineEdit : lineEdits)
        connect(lineEdit, &QLineEdit::textChanged, this, &FilterDialog::filterSelection);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::on_pushButton_clicked()
{
    _filter.clear();

    if(ui->filter_1->isChecked())
    {
        QString lenght = ui->nameLenght->text();
        lenght = (lenght.isEmpty()) ? "0" : lenght;
        QString sign = _sign[ui->comboBox->currentIndex()];
        _filter += " AND LENGTH(Имя) " + sign + " " + lenght;
    }

    if(ui->filter_2->isChecked())
    {
        QString lenght = ui->surnameLenght->text();
        lenght = (lenght.isEmpty()) ? "0" : lenght;
        QString sign = _sign[ui->comboBox_2->currentIndex()];
        _filter += " AND LENGTH(Фамилия) " + sign + " " + lenght;
    }

    if(ui->filter_3->isChecked())
    {
        if(!ui->ending->text().isEmpty())
            _filter += " AND " + ui->comboBox_3->currentText() + " LIKE '%" + ui->ending->text() + "'";
    }

    if(ui->filter_4->isChecked())
    {
        if(!ui->beginning->text().isEmpty())
            _filter += " AND " + ui->comboBox_4->currentText() + " LIKE '" + ui->beginning->text() + "%'";
    }

    emit filterSelected(_filter);
    accept();
}

void FilterDialog::clearFilter()
{
    for(QCheckBox* filter : findChildren<QCheckBox*>())
        filter->setChecked(false);

    for(QLineEdit* text : findChildren<QLineEdit*>())
        text->clear();

    emit filterSelected("");
}

void FilterDialog::filterSelection()
{
    QLineEdit *lineEdit = (QLineEdit*)sender();
    if(lineEdit->text().isEmpty())
        _filterSelection[lineEdit]->setChecked(false);
    else
        _filterSelection[lineEdit]->setChecked(true);
}

