#include "addwidget.h"
#include "ui_addwidget.h"
#include "widget.h"
#include <QMessageBox>
#include "stuList.h"
#include "tool.h"
#include "suredialog.h"
#include "config.h"

addwidget::addwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addwidget)
    , editingStudent(nullptr)
    , isEditMode(false)
{
    ui->setupUi(this);
    this->setWindowTitle("添加学生");
    setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint); // 设置窗口始终在最顶层
}

addwidget::addwidget(Student* student, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addwidget)
    , editingStudent(student)
    , isEditMode(true)
{
    ui->setupUi(this);
    this->setWindowTitle("修改学生信息");
    setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint); // 设置窗口始终在最顶层

    // 填充现有学生信息到表单
    ui->idEdit->setText(student->getId());
    ui->idEdit->setEnabled(false);  // 学号不允许修改
    ui->nameEdit->setText(student->getName());
    
    // 设置性别选择
    int genderIndex = student->getGender() == "男" ? 0 : 1;
    ui->genderEdit->setCurrentIndex(genderIndex);
    
    // 设置学历类型选择
    int typeIndex = student->getType() == "本科生" ? 0 : 1;
    ui->typeEdit->setCurrentIndex(typeIndex);
    
    // 设置年龄和学分
    ui->ageEdit->setText(QString::number(student->getAge()));
    ui->creditsEdit->setText(QString::number(student->getRawCredits()));
}

addwidget::~addwidget()
{
    delete ui;
}

void addwidget::on_cancelpushButton_clicked()
{
    this->close();
}

void addwidget::on_surepushButton_clicked()
{
    // 获取表单数据
    QString id = ui->idEdit->text().trimmed();
    QString name = ui->nameEdit->text().trimmed();
    QString gender = ui->genderEdit->currentText();
    QString type = ui->typeEdit->currentText();
    QString ageText = ui->ageEdit->text().trimmed();
    QString creditsText = ui->creditsEdit->text().trimmed();

    // 表单验证：检查必填字段
    if(id.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "错误", "学号和姓名不能为空！");
        return;
    }

    // 在添加模式下检查学号是否重复
    if (!isEditMode) {
        for (const auto* student : *StuList::get()) {
            if (student->getId() == id) {
                QMessageBox::warning(this, "错误", "该学号已存在！");
                return;
            }
        }
    }

    // 验证年龄和学分的数值有效性
    bool ok1, ok2;
    int age = ageText.toInt(&ok1);
    double credits = creditsText.toDouble(&ok2);

    if (!ok1 || age <= 0) {
        QMessageBox::warning(this, "错误", "年龄必须是正整数！");
        return;
    }
    if (!ok2 || credits < 0) {
        QMessageBox::warning(this, "错误", "学分必须是非负数！");
        return;
    }

    // 显示确认对话框
    QString message = isEditMode ? 
        QString("确认要修改学生 %1 的信息吗？").arg(name) :
        QString("确认要添加学生 %1 吗？").arg(name);
    
    sureDialog dialog(message, this);
    dialog.exec();

    if (!dialog.isConfirmed()) {
        return;  // 用户取消操作
    }

    if (isEditMode) {
        // 修改模式：更新现有学生信息
        editingStudent->setName(name);
        editingStudent->setGender(gender);
        editingStudent->setAge(age);
        editingStudent->setCredits(credits);
        
        // 如果学历类型改变，需要创建新的对象
        if (editingStudent->getType() != type) {
            Student* newStudent = nullptr;
            if (type == "本科生") {
                newStudent = new Undergraduate(id, name, gender, age, credits);
            } else {
                newStudent = new Postgraduate(id, name, gender, age, credits);
            }
            
            // 在列表中替换学生对象
            auto stulist = StuList::get();
            for (auto it = stulist->begin(); it != stulist->end(); ++it) {
                if ((*it)->getId() == id) {
                    delete *it;  // 删除旧对象
                    *it = newStudent;  // 替换为新对象
                    break;
                }
            }
        }
    } else {
        // 添加模式：创建新学生
        Student* newStudent = nullptr;
        if (type == "本科生") {
            newStudent = new Undergraduate(id, name, gender, age, credits);
        } else {
            newStudent = new Postgraduate(id, name, gender, age, credits);
        }
        
        if (newStudent) {
            StuList::get()->push_back(newStudent);
        }
    }

    try {
        // 保存更改到文件
        Tool::writeAllStudents(StuList::get(), Config::filePath);
        
        // 更新主窗口显示（通过父窗口指针）
        if (Widget* mainWindow = qobject_cast<Widget*>(this->parentWidget())) {
            mainWindow->showList(StuList::get());
        }
        
        // 关闭当前窗口
        this->close();
    } catch (const QString& error) {
        QMessageBox::critical(this, "错误", error);
        return;
    }
}

