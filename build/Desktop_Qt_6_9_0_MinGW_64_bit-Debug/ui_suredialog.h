/********************************************************************************
** Form generated from reading UI file 'suredialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUREDIALOG_H
#define UI_SUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *surePushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelPushButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *sureDialog)
    {
        if (sureDialog->objectName().isEmpty())
            sureDialog->setObjectName("sureDialog");
        sureDialog->resize(400, 200);
        sureDialog->setMinimumSize(QSize(400, 200));
        verticalLayout = new QVBoxLayout(sureDialog);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        label = new QLabel(sureDialog);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        surePushButton = new QPushButton(sureDialog);
        surePushButton->setObjectName("surePushButton");

        horizontalLayout->addWidget(surePushButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelPushButton = new QPushButton(sureDialog);
        cancelPushButton->setObjectName("cancelPushButton");

        horizontalLayout->addWidget(cancelPushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(sureDialog);

        QMetaObject::connectSlotsByName(sureDialog);
    } // setupUi

    void retranslateUi(QDialog *sureDialog)
    {
        sureDialog->setWindowTitle(QCoreApplication::translate("sureDialog", "\347\241\256\350\256\244\346\223\215\344\275\234", nullptr));
        sureDialog->setStyleSheet(QCoreApplication::translate("sureDialog", "QDialog {\n"
"    background-color: #f5f6fa;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 15px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton {\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 25px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    min-width: 100px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"#surePushButton {\n"
"    background-color: #00b894;\n"
"}\n"
"\n"
"#surePushButton:hover {\n"
"    background-color: #00a884;\n"
"}\n"
"\n"
"#cancelPushButton {\n"
"    background-color: #ff7675;\n"
"}\n"
"\n"
"#cancelPushButton:hover {\n"
"    background-color: #e66767;\n"
"}", nullptr));
        surePushButton->setText(QCoreApplication::translate("sureDialog", "\347\241\256\345\256\232", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("sureDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sureDialog: public Ui_sureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUREDIALOG_H
