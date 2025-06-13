#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QComboBox>
#include "stu.h"

class Widget;

namespace Ui {
class addwidget;
}

/**
 * @brief 添加/修改学生信息窗口类
 * 
 * 该类用于处理学生信息的添加和修改操作，
 * 包含表单验证、学号查重等功能
 */
class addwidget : public QWidget
{
    Q_OBJECT

public:

    explicit addwidget(QWidget *parent = nullptr);

    explicit addwidget(Student* student, QWidget *parent = nullptr);

    ~addwidget();

private slots:
    /** @brief 取消按钮点击处理函数 */
    void on_cancelpushButton_clicked();

    /** @brief 确定按钮点击处理函数 */
    void on_surepushButton_clicked();

private:
    Ui::addwidget *ui;           ///< UI对象指针
    Student* editingStudent;      ///< 正在编辑的学生对象指针
    bool isEditMode;             ///< 是否为修改模式
};

#endif // ADDWIDGET_H
