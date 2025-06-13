#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "stu.h"
#include "tool.h"
#include "stuList.h"

class addwidget;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

/**
 * @brief 主窗口类
 * 负责学生信息的展示和管理
 */
class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    
    ~Widget();

    /**
     * @brief 显示学生列表
     * @param stulist 学生列表指针
     */
    void showList(std::vector<Student*>* stulist);

private slots:
    /**
     * @brief 处理表格单元格点击
     * @param row 行号
     * @param col 列号
     */
    void on_tableWidget_cellClicked(int row, int col);

    /** @brief 处理添加按钮点击 */
    void on_addButton_clicked();

    /** @brief 处理搜索按钮点击 */
    void on_selectButton_clicked();

    /** @brief 处理修改按钮点击 */
    void on_updateButton_clicked();

    /** @brief 处理删除按钮点击 */
    void on_deleteButton_clicked();

private:
    Ui::Widget *ui;    ///< UI对象指针

    /**
     * @brief 初始化表格
     * @param row 行数
     * @param col 列数
     */
    void initTable(int row, int col);
};

#endif // WIDGET_H
