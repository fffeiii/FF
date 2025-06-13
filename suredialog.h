#ifndef SUREDIALOG_H
#define SUREDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class sureDialog;
}

/**
 * @brief 通用确认对话框类
 * 
 * 用于显示操作确认对话框，包含确认和取消按钮。
 * 调用者可以通过 isConfirmed() 检查用户的选择。
 */
class sureDialog : public QDialog
{
    Q_OBJECT

public:

    explicit sureDialog(const QString &message, QWidget *parent = nullptr);
    
    ~sureDialog();

    /**
     * @brief 检查用户是否确认了操作
     * @return 如果用户点击了确认按钮返回true，否则返回false
     */
    bool isConfirmed() const { return confirmed; }

private slots:
    /** @brief 确认按钮点击处理函数 */
    void on_surePushButton_clicked();

    /** @brief 取消按钮点击处理函数 */
    void on_cancelPushButton_clicked();

private:
    Ui::sureDialog *ui;    ///< UI对象指针
    bool confirmed;        ///< 用户是否确认的标志
};

#endif // SUREDIALOG_H
