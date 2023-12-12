/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_filterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *filter_1;
    QComboBox *comboBox;
    QLineEdit *nameLenght;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *filter_2;
    QComboBox *comboBox_2;
    QLineEdit *surnameLenght;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *filter_3;
    QComboBox *comboBox_3;
    QLabel *label_2;
    QLineEdit *ending;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *filter_4;
    QComboBox *comboBox_4;
    QLabel *label_4;
    QLineEdit *beginning;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *filterDialog)
    {
        if (filterDialog->objectName().isEmpty())
            filterDialog->setObjectName(QString::fromUtf8("filterDialog"));
        filterDialog->resize(427, 257);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterDialog->sizePolicy().hasHeightForWidth());
        filterDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(filterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filter_1 = new QCheckBox(filterDialog);
        filter_1->setObjectName(QString::fromUtf8("filter_1"));
        filter_1->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filter_1->sizePolicy().hasHeightForWidth());
        filter_1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        filter_1->setFont(font);
        filter_1->setChecked(false);

        horizontalLayout->addWidget(filter_1);

        comboBox = new QComboBox(filterDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);

        nameLenght = new QLineEdit(filterDialog);
        nameLenght->setObjectName(QString::fromUtf8("nameLenght"));
        nameLenght->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLenght->sizePolicy().hasHeightForWidth());
        nameLenght->setSizePolicy(sizePolicy2);
        nameLenght->setFont(font);

        horizontalLayout->addWidget(nameLenght);

        label = new QLabel(filterDialog);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filter_2 = new QCheckBox(filterDialog);
        filter_2->setObjectName(QString::fromUtf8("filter_2"));
        filter_2->setEnabled(true);
        sizePolicy1.setHeightForWidth(filter_2->sizePolicy().hasHeightForWidth());
        filter_2->setSizePolicy(sizePolicy1);
        filter_2->setFont(font);
        filter_2->setChecked(false);

        horizontalLayout_2->addWidget(filter_2);

        comboBox_2 = new QComboBox(filterDialog);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(true);
        comboBox_2->setFont(font);

        horizontalLayout_2->addWidget(comboBox_2);

        surnameLenght = new QLineEdit(filterDialog);
        surnameLenght->setObjectName(QString::fromUtf8("surnameLenght"));
        surnameLenght->setEnabled(true);
        sizePolicy2.setHeightForWidth(surnameLenght->sizePolicy().hasHeightForWidth());
        surnameLenght->setSizePolicy(sizePolicy2);
        surnameLenght->setFont(font);

        horizontalLayout_2->addWidget(surnameLenght);

        label_3 = new QLabel(filterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        filter_3 = new QCheckBox(filterDialog);
        filter_3->setObjectName(QString::fromUtf8("filter_3"));
        filter_3->setEnabled(true);
        sizePolicy1.setHeightForWidth(filter_3->sizePolicy().hasHeightForWidth());
        filter_3->setSizePolicy(sizePolicy1);
        filter_3->setFont(font);
        filter_3->setChecked(false);

        horizontalLayout_3->addWidget(filter_3);

        comboBox_3 = new QComboBox(filterDialog);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(true);
        comboBox_3->setFont(font);

        horizontalLayout_3->addWidget(comboBox_3);

        label_2 = new QLabel(filterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        ending = new QLineEdit(filterDialog);
        ending->setObjectName(QString::fromUtf8("ending"));
        ending->setEnabled(true);
        sizePolicy2.setHeightForWidth(ending->sizePolicy().hasHeightForWidth());
        ending->setSizePolicy(sizePolicy2);
        ending->setFont(font);

        horizontalLayout_3->addWidget(ending);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        filter_4 = new QCheckBox(filterDialog);
        filter_4->setObjectName(QString::fromUtf8("filter_4"));
        filter_4->setEnabled(true);
        filter_4->setChecked(false);

        horizontalLayout_5->addWidget(filter_4);

        comboBox_4 = new QComboBox(filterDialog);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setFont(font);

        horizontalLayout_5->addWidget(comboBox_4);

        label_4 = new QLabel(filterDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        beginning = new QLineEdit(filterDialog);
        beginning->setObjectName(QString::fromUtf8("beginning"));
        beginning->setFont(font);

        horizontalLayout_5->addWidget(beginning);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(filterDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(filterDialog);

        QMetaObject::connectSlotsByName(filterDialog);
    } // setupUi

    void retranslateUi(QDialog *filterDialog)
    {
        filterDialog->setWindowTitle(QApplication::translate("filterDialog", "Dialog", nullptr));
        filter_1->setText(QApplication::translate("filterDialog", "\320\222 \320\270\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(0, QApplication::translate("filterDialog", "\320\261\320\276\320\273\321\214\321\210\320\265", nullptr));
        comboBox->setItemText(1, QApplication::translate("filterDialog", "\320\274\320\265\320\275\321\214\321\210\320\265", nullptr));

        label->setText(QApplication::translate("filterDialog", "\320\261\321\203\320\272\320\262", nullptr));
        filter_2->setText(QApplication::translate("filterDialog", "\320\222 \321\204\320\260\320\274\320\270\320\273\320\270\320\270", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("filterDialog", "\320\261\320\276\320\273\321\214\321\210\320\265", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("filterDialog", "\320\274\320\265\320\275\321\214\321\210\320\265", nullptr));

        label_3->setText(QApplication::translate("filterDialog", "\320\261\321\203\320\272\320\262", nullptr));
        filter_3->setText(QString());
        comboBox_3->setItemText(0, QApplication::translate("filterDialog", "\320\230\320\274\321\217", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("filterDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));

        label_2->setText(QApplication::translate("filterDialog", "\320\267\320\260\320\272\320\260\320\275\321\207\320\270\320\262\320\260\320\265\321\202\321\201\321\217 \320\275\320\260 ", nullptr));
        filter_4->setText(QString());
        comboBox_4->setItemText(0, QApplication::translate("filterDialog", "\320\230\320\274\321\217", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("filterDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));

        label_4->setText(QApplication::translate("filterDialog", "\320\275\320\260\321\207\320\270\320\275\320\260\321\216\321\202\321\201\321\217 \320\275\320\260", nullptr));
        pushButton->setText(QApplication::translate("filterDialog", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterDialog: public Ui_filterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
