/********************************************************************************
** Form generated from reading UI file 'addwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIDGET_H
#define UI_ADDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addwidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Idlabel;
    QLineEdit *idEdit;
    QLabel *namelabel;
    QLineEdit *nameEdit;
    QLabel *genderlabel;
    QComboBox *genderEdit;
    QLabel *agelabel;
    QLineEdit *ageEdit;
    QLabel *creditslabel;
    QLineEdit *creditsEdit;
    QLabel *typelabel;
    QComboBox *typeEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *surepushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelpushButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *addwidget)
    {
        if (addwidget->objectName().isEmpty())
            addwidget->setObjectName("addwidget");
        addwidget->resize(500, 500);
        addwidget->setMinimumSize(QSize(500, 500));
        addwidget->setMaximumSize(QSize(500, 500));
        verticalLayout = new QVBoxLayout(addwidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(15);
        Idlabel = new QLabel(addwidget);
        Idlabel->setObjectName("Idlabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, Idlabel);

        idEdit = new QLineEdit(addwidget);
        idEdit->setObjectName("idEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, idEdit);

        namelabel = new QLabel(addwidget);
        namelabel->setObjectName("namelabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, namelabel);

        nameEdit = new QLineEdit(addwidget);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        genderlabel = new QLabel(addwidget);
        genderlabel->setObjectName("genderlabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, genderlabel);

        genderEdit = new QComboBox(addwidget);
        genderEdit->addItem(QString());
        genderEdit->addItem(QString());
        genderEdit->setObjectName("genderEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderEdit);

        agelabel = new QLabel(addwidget);
        agelabel->setObjectName("agelabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, agelabel);

        ageEdit = new QLineEdit(addwidget);
        ageEdit->setObjectName("ageEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ageEdit);

        creditslabel = new QLabel(addwidget);
        creditslabel->setObjectName("creditslabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, creditslabel);

        creditsEdit = new QLineEdit(addwidget);
        creditsEdit->setObjectName("creditsEdit");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, creditsEdit);

        typelabel = new QLabel(addwidget);
        typelabel->setObjectName("typelabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, typelabel);

        typeEdit = new QComboBox(addwidget);
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->setObjectName("typeEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, typeEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        surepushButton = new QPushButton(addwidget);
        surepushButton->setObjectName("surepushButton");

        horizontalLayout->addWidget(surepushButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelpushButton = new QPushButton(addwidget);
        cancelpushButton->setObjectName("cancelpushButton");

        horizontalLayout->addWidget(cancelpushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(addwidget);

        QMetaObject::connectSlotsByName(addwidget);
    } // setupUi

    void retranslateUi(QWidget *addwidget)
    {
        addwidget->setWindowTitle(QCoreApplication::translate("addwidget", "\346\267\273\345\212\240/\344\277\256\346\224\271\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        addwidget->setStyleSheet(QCoreApplication::translate("addwidget", "QWidget {\n"
"    background-color: #f5f6fa;\n"
"    color: #2c3e50;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #2c3e50;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit, QComboBox {\n"
"    padding: 8px;\n"
"    border: 2px solid #dcdde1;\n"
"    border-radius: 6px;\n"
"    background-color: white;\n"
"    selection-background-color: #74b9ff;\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border: 2px solid #74b9ff;\n"
"}\n"
"\n"
"QComboBox {\n"
"    padding-right: 20px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #74b9ff;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 20px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    min-width: 80px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:h"
                        "over {\n"
"    background-color: #0984e3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #6c5ce7;\n"
"}\n"
"\n"
"#surepushButton {\n"
"    background-color: #00b894;\n"
"}\n"
"\n"
"#surepushButton:hover {\n"
"    background-color: #00a884;\n"
"}\n"
"\n"
"#cancelpushButton {\n"
"    background-color: #ff7675;\n"
"}\n"
"\n"
"#cancelpushButton:hover {\n"
"    background-color: #e66767;\n"
"}", nullptr));
        Idlabel->setText(QCoreApplication::translate("addwidget", "\345\255\246\345\217\267\357\274\232", nullptr));
        namelabel->setText(QCoreApplication::translate("addwidget", "\345\247\223\345\220\215\357\274\232", nullptr));
        genderlabel->setText(QCoreApplication::translate("addwidget", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderEdit->setItemText(0, QCoreApplication::translate("addwidget", "\347\224\267", nullptr));
        genderEdit->setItemText(1, QCoreApplication::translate("addwidget", "\345\245\263", nullptr));

        agelabel->setText(QCoreApplication::translate("addwidget", "\345\271\264\351\276\204\357\274\232", nullptr));
        creditslabel->setText(QCoreApplication::translate("addwidget", "\345\255\246\345\210\206\357\274\232", nullptr));
        typelabel->setText(QCoreApplication::translate("addwidget", "\345\255\246\345\216\206\357\274\232", nullptr));
        typeEdit->setItemText(0, QCoreApplication::translate("addwidget", "\346\234\254\347\247\221\347\224\237", nullptr));
        typeEdit->setItemText(1, QCoreApplication::translate("addwidget", "\347\240\224\347\251\266\347\224\237", nullptr));

        surepushButton->setText(QCoreApplication::translate("addwidget", "\347\241\256\345\256\232", nullptr));
        cancelpushButton->setText(QCoreApplication::translate("addwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addwidget: public Ui_addwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIDGET_H
