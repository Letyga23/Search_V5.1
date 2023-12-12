/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *clearSearch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QComboBox *comboBox_type_sort;
    QPushButton *pushButton_sort;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *resetTable;
    QLineEdit *searchText;
    QPushButton *addFilter;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_search;
    QPushButton *clearFilter;
    QComboBox *comboBox;
    QLabel *label;
    QTableView *tableView;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QLabel *currentPage;
    QLabel *label_5;
    QLabel *maxPage;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *goToPage;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 656);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        clearSearch = new QPushButton(centralwidget);
        clearSearch->setObjectName(QString::fromUtf8("clearSearch"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clearSearch->sizePolicy().hasHeightForWidth());
        clearSearch->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        clearSearch->setFont(font);
        clearSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(clearSearch, 0, 5, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        comboBox_2->setFont(font1);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #0E9252;\n"
"    border: 1px solid #2980b9;\n"
"    color: #ffffff;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #42A977; \n"
"    border: 1px solid #1c6da5;\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"    background-color: #d3d3d3;    \n"
"    color: #555555;\n"
"    border: 1px solid #a3a3a3;\n"
"}"));

        horizontalLayout_2->addWidget(comboBox_2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        comboBox_type_sort = new QComboBox(centralwidget);
        comboBox_type_sort->addItem(QString());
        comboBox_type_sort->addItem(QString());
        comboBox_type_sort->setObjectName(QString::fromUtf8("comboBox_type_sort"));
        comboBox_type_sort->setFont(font1);
        comboBox_type_sort->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #0E9252;\n"
"    border: 1px solid #2980b9;\n"
"    color: #ffffff;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #42A977; \n"
"    border: 1px solid #1c6da5;\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"    background-color: #d3d3d3;    \n"
"    color: #555555;\n"
"    border: 1px solid #a3a3a3;\n"
"}"));

        horizontalLayout_2->addWidget(comboBox_type_sort);

        pushButton_sort = new QPushButton(centralwidget);
        pushButton_sort->setObjectName(QString::fromUtf8("pushButton_sort"));
        pushButton_sort->setFont(font);
        pushButton_sort->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_sort);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 6);

        resetTable = new QPushButton(centralwidget);
        resetTable->setObjectName(QString::fromUtf8("resetTable"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        resetTable->setFont(font2);
        resetTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(resetTable, 5, 9, 1, 1);

        searchText = new QLineEdit(centralwidget);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchText->sizePolicy().hasHeightForWidth());
        searchText->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(12);
        searchText->setFont(font3);

        gridLayout->addWidget(searchText, 0, 2, 1, 1);

        addFilter = new QPushButton(centralwidget);
        addFilter->setObjectName(QString::fromUtf8("addFilter"));
        addFilter->setFont(font);
        addFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(addFilter, 0, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 6, 1, 1);

        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setFont(font);
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(pushButton_search, 0, 4, 1, 1);

        clearFilter = new QPushButton(centralwidget);
        clearFilter->setObjectName(QString::fromUtf8("clearFilter"));
        clearFilter->setFont(font);
        clearFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(clearFilter, 0, 9, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        comboBox->setFont(font4);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #0E9252;\n"
"    border: 1px solid #2980b9;\n"
"    color: #ffffff;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #42A977; \n"
"    border: 1px solid #1c6da5;\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"    background-color: #d3d3d3;    \n"
"    color: #555555;\n"
"    border: 1px solid #a3a3a3;\n"
"}"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Segoe UI"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setWeight(50);
        label->setFont(font5);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font6;
        font6.setPointSize(12);
        tableView->setFont(font6);
        tableView->setWordWrap(false);

        gridLayout->addWidget(tableView, 8, 0, 1, 10);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        currentPage = new QLabel(centralwidget);
        currentPage->setObjectName(QString::fromUtf8("currentPage"));
        currentPage->setFont(font1);

        horizontalLayout_3->addWidget(currentPage);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_3->addWidget(label_5);

        maxPage = new QLabel(centralwidget);
        maxPage->setObjectName(QString::fromUtf8("maxPage"));
        maxPage->setFont(font1);

        horizontalLayout_3->addWidget(maxPage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        horizontalLayout->addWidget(prevButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label_2);

        goToPage = new QLineEdit(centralwidget);
        goToPage->setObjectName(QString::fromUtf8("goToPage"));
        sizePolicy4.setHeightForWidth(goToPage->sizePolicy().hasHeightForWidth());
        goToPage->setSizePolicy(sizePolicy4);
        goToPage->setMaximumSize(QSize(50, 16777215));
        goToPage->setFont(font3);

        horizontalLayout->addWidget(goToPage);

        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #3498db;\n"
"	border: 1px solid #2980b9;\n"
"	 color: #ffffff;\n"
"	padding: 5px 10px;\n"
"	border-radius: 3px;\n"
"}\n"
"                      \n"
"QPushButton:hover {\n"
"background-color: #2184cb;border: 1px solid #1c6da5;\n"
"}\n"
"                      \n"
"QPushButton:pressed {\n"
"	background-color: #1a548b;\n"
"	border: 1px solid #174172;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #d3d3d3;	\n"
"	color: #555555;\n"
"	border: 1px solid #a3a3a3;\n"
"}"));

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        clearSearch->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:</p></body></html>", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "\320\277\320\276", nullptr));
        comboBox_type_sort->setItemText(0, QApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216 (\320\220-\320\257)", nullptr));
        comboBox_type_sort->setItemText(1, QApplication::translate("MainWindow", "\320\243\320\261\321\213\320\262\320\260\320\275\320\270\321\216 (\320\257-\320\220)", nullptr));

        pushButton_sort->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        resetTable->setText(QApplication::translate("MainWindow", "C\320\261\321\200\320\276\321\201\320\270\321\202\321\214\n"
"\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        addFilter->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        pushButton_search->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        clearFilter->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \321\204\320\270\320\273\321\214\321\202\321\200\320\260", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));

        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\320\265\n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260: ", nullptr));
        currentPage->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "/", nullptr));
        maxPage->setText(QApplication::translate("MainWindow", "0", nullptr));
        prevButton->setText(QApplication::translate("MainWindow", "<<", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:</p></body></html>", nullptr));
        nextButton->setText(QApplication::translate("MainWindow", ">>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
