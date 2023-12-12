#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QTableView>
#include <QSqlTableModel>
#include <QTimer>
#include <math.h>
#include <QMutex>
#include <QMutexLocker>
#include <QKeyEvent>
#include <QSqlQuery>
#include "filterdialog.h"
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow* ui;

    int _currentPage;
    int _rowsPerPage;
    int _maxPageModel;
    int _minPageModel;
    int _limit;
    int _maxPage;
    int _rowCountModel;
    QString _filter;
    QString _sort;
    QString _typeSearch;
    bool _resultIsFound;

    QMap<int, QString> _typeSort;

    QSharedPointer<QSqlQueryModel> _query;
    QSharedPointer<QSqlDatabase> _db;
    std::vector<QSharedPointer<QSqlTableModel>> _models;

    QSharedPointer<MyThread> _startWatcher;
    QSharedPointer<MyThread> _nextWatcher;
    QSharedPointer<MyThread> _prevWatcher;
    QSharedPointer<MyThread> _getMaxPageWatcher;
    QSharedPointer<MyThread> _searchWatcher;

    QString _like;
    QString _column;
    FilterDialog* _filterDialog;

    QTimer _searchTimer;
    QTimer _goToPageTimer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateCurrentPageInLabel();
    void updateTablePage();
    void loadingStartModel();
    void loadingModel(QSharedPointer<MyThread> thread, QSharedPointer<QSqlTableModel> model, int offset);
    void setModel(QSharedPointer<QSqlTableModel> model);
    void setFilter(const QString& filter);
    void refreshStartModel();
    void blockingInterface(bool flag);
    void startLoadModelFinished();
    void threadFinished();
    void goToPage(int currentPage);
    void goToNextModel();
    void goToPrevModel();
    void searchInModels();
    int currentPageInModel();
    static void getMaxPage(QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, int& maxPage, int rowsPerPage, const QString& filters);
    static void completion(QSharedPointer<QSqlTableModel> model, QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, int limit, int offset, const QString& filters, const QString& sort);
    static void searchInDB(QSharedPointer<QSqlQueryModel> query, QSharedPointer<QSqlDatabase> db, const QString& column, const QString& like, const QString& typeSearch, const QString& filters, const QString& sort, int& currentPage, bool& resultIsFound);

private slots:
    void on_clearSearch_clicked();
    void on_goToPage_textChanged();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_addFilter_clicked();
    void on_clearFilter_clicked();
    void on_searchText_textChanged();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_resetTable_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_pushButton_search_clicked();
};
#endif // MAINWINDOW_H
