/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectButton;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(250, 36));
        lineEdit->setMaximumSize(QSize(350, 36));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        selectButton = new QPushButton(Widget);
        selectButton->setObjectName("selectButton");
        selectButton->setMinimumSize(QSize(90, 36));

        horizontalLayout->addWidget(selectButton);

        addButton = new QPushButton(Widget);
        addButton->setObjectName("addButton");
        addButton->setMinimumSize(QSize(90, 36));

        horizontalLayout->addWidget(addButton);

        updateButton = new QPushButton(Widget);
        updateButton->setObjectName("updateButton");
        updateButton->setMinimumSize(QSize(90, 36));

        horizontalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(Widget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMinimumSize(QSize(90, 36));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        Widget->setStyleSheet(QCoreApplication::translate("Widget", "QWidget {\n"
"    background-color: #f5f6fa;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 2px solid #dcdde1;\n"
"    border-radius: 6px;\n"
"    background-color: white;\n"
"    selection-background-color: #74b9ff;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #74b9ff;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #74b9ff;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 15px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    min-width: 60px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0984e3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #6c5ce7;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: white;\n"
"    alternate-background-color: #f8f9fa;\n"
"    border: 1px solid #dcdde1;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    gridline-color: #dcdde1;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"    border-bottom: 1px solid #"
                        "dcdde1;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #74b9ff;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #dfe6e9;\n"
"    color: #2d3436;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-right: 1px solid #b2bec3;\n"
"    border-bottom: 1px solid #b2bec3;\n"
"    font-weight: bold;\n"
"}", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215\346\210\226\345\255\246\345\217\267\346\237\245\346\211\276\345\255\246\347\224\237...", nullptr));
        selectButton->setText(QCoreApplication::translate("Widget", "\346\237\245\346\211\276", nullptr));
        addButton->setStyleSheet(QCoreApplication::translate("Widget", "background-color: #00b894;", nullptr));
        addButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        updateButton->setStyleSheet(QCoreApplication::translate("Widget", "background-color: #fdcb6e;", nullptr));
        updateButton->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271", nullptr));
        deleteButton->setStyleSheet(QCoreApplication::translate("Widget", "background-color: #ff7675;", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
