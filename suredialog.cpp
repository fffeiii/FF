#include "suredialog.h"
#include "ui_suredialog.h"

sureDialog::sureDialog(const QString &message, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sureDialog)
    , confirmed(false)
{
    ui->setupUi(this);
    
    // 设置窗口标题和属性
    this->setWindowTitle("确认");
    setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint); // 设置窗口始终在最顶层
    
    // 设置确认消息
    ui->label->setText(message);
}

sureDialog::~sureDialog()
{
    delete ui;
}

void sureDialog::on_surePushButton_clicked()
{
    confirmed = true;
    accept();
}

void sureDialog::on_cancelPushButton_clicked()
{
    confirmed = false;
    reject();
}

