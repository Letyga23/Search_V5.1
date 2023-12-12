#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QCheckBox>

namespace Ui {
class filterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT
    Ui::filterDialog *ui;
    QString _filter;
    QMap<int, QString> _sign;
    QMap<QLineEdit*, QCheckBox*> _filterSelection;

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

    void clearFilter();

private slots:
    void on_pushButton_clicked();
    void filterSelection();

signals:
    void filterSelected(QString filter);

};

#endif // FILTERDIALOG_H
