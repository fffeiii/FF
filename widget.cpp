#include "widget.h"
#include "ui_widget.h"
#include "addwidget.h"
#include <QMessageBox>
#include "suredialog.h"
#include "stuList.h"
#include "tool.h"
#include "config.h"
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("学生信息管理系统");
    // 设置窗口在关闭时自动释放内存
    setAttribute(Qt::WA_DeleteOnClose);
    
    // 清空学生列表中的所有学生信息
    StuList::get()->clear();
    
    try {
        // 尝试从指定文件中加载所有学生信息到学生列表中
        Tool::loadAllStudents(StuList::get(), Config::filePath);
    } catch (const QString& error) {
        // 若加载学生信息时出现异常，弹出警告框显示错误信息
        QMessageBox::warning(this, "错误", error);
        // 尝试创建一个新的文件，若文件不存在则创建
        QFile file(Config::filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // 打开文件成功后关闭文件
            file.close();
        }
    }

    // 初始化表格，设置表格的行数为学生列表的大小，列数为 7
    initTable(StuList::get()->size(),7);

    // 在表格中显示学生列表中的所有学生信息
    showList(StuList::get());
}

Widget::~Widget()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if(item) {
                delete item;
            }
        }
    }
    delete ui;
}

void Widget::initTable(int row,int col) {
    ui->tableWidget->resizeRowsToContents();

    // 创建一个字符串列表，用于存储表格的表头信息
    QStringList header;
    // 向字符串列表中添加表头内容
    header << "学号" << "姓名" << "性别" << "年龄" << "学分" << "学历" << "是否选择";
    // 根据表头信息的数量设置表格的列数
    ui->tableWidget->setColumnCount(header.size());
    // 设置表格的行数
    ui->tableWidget->setRowCount(row);

    // 设置表格水平表头的列宽调整模式为自动拉伸，使各列均匀分布
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置表格的水平表头标签为之前创建的字符串列表内容
    ui->tableWidget->setHorizontalHeaderLabels(header);
    // 设置表格水平表头的样式
    ui->tableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "   padding: 5px;"  // 设置表头单元格的内边距为 5 像素
        "   background-color: #f0f0f0;"  // 设置表头单元格的背景颜色为浅灰色
        "   border: none;"  // 取消表头单元格的边框
        "   border-right: 1px solid #d0d0d0;"  // 设置表头单元格的右边框为 1 像素的浅灰色实线
        "   border-bottom: 1px solid #d0d0d0;"  // 设置表头单元格的下边框为 1 像素的浅灰色实线
        "}"
    );

    // 设置表格的编辑触发条件为禁止编辑，即用户无法直接在表格中编辑内容
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置表格的选择行为为整行选择，即用户点击表格时会选中整行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 隐藏表格的垂直表头
    ui->tableWidget->verticalHeader()->setVisible(false);

    // 为输入框设置占位文本，提示用户输入姓名或学号进行查找
    ui->lineEdit->setPlaceholderText("请输入姓名或学号查找");
}

void Widget::showList(std::vector<Student*>* stulist) {
    // 清空表格中的所有现有项
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            // 从表格中取出指定位置的项
            QTableWidgetItem* item = ui->tableWidget->takeItem(i, j);
            // 如果项存在，则释放其内存
            if(item) {
                delete item;
            }
        }
    }
    
    // 根据学生列表的大小设置表格的行数
    ui->tableWidget->setRowCount(stulist->size());
    
    // 遍历学生列表，将每个学生的信息显示在表格中
    for(size_t i = 0; i < stulist->size(); i++) {
        // 获取当前索引对应的学生对象
        Student* stu = stulist->at(i);
        
        // 创建一个新的表格项，用于显示学生的学号，并设置文本居中对齐
        QTableWidgetItem* idItem = new QTableWidgetItem(stu->getId());
        idItem->setTextAlignment(Qt::AlignCenter);
        // 将学号项设置到表格的对应位置
        ui->tableWidget->setItem(i, 0, idItem);
        
        // 创建一个新的表格项，用于显示学生的姓名，并设置文本居中对齐
        QTableWidgetItem* nameItem = new QTableWidgetItem(stu->getName());
        nameItem->setTextAlignment(Qt::AlignCenter);
        // 将姓名项设置到表格的对应位置
        ui->tableWidget->setItem(i, 1, nameItem);
        
        // 创建一个新的表格项，用于显示学生的性别，并设置文本居中对齐
        QTableWidgetItem* genderItem = new QTableWidgetItem(stu->getGender());
        genderItem->setTextAlignment(Qt::AlignCenter);
        // 将性别项设置到表格的对应位置
        ui->tableWidget->setItem(i, 2, genderItem);
        
        // 创建一个新的表格项，用于显示学生的年龄，并将年龄转换为字符串，设置文本居中对齐
        QTableWidgetItem* ageItem = new QTableWidgetItem(QString::number(stu->getAge()));
        ageItem->setTextAlignment(Qt::AlignCenter);
        // 将年龄项设置到表格的对应位置
        ui->tableWidget->setItem(i, 3, ageItem);
        
        // 创建一个新的表格项，用于显示学生的学分，并将学分转换为字符串，设置文本居中对齐
        QTableWidgetItem* creditsItem = new QTableWidgetItem(QString::number(stu->getCredits()));
        creditsItem->setTextAlignment(Qt::AlignCenter);
        // 将学分项设置到表格的对应位置
        ui->tableWidget->setItem(i, 4, creditsItem);
        
        // 创建一个新的表格项，用于显示学生的学历，并设置文本居中对齐
        QTableWidgetItem* typeItem = new QTableWidgetItem(stu->getType());
        typeItem->setTextAlignment(Qt::AlignCenter);
        // 将学历项设置到表格的对应位置
        ui->tableWidget->setItem(i, 5, typeItem);
        
        // 创建一个新的表格项，用于显示选择状态，初始状态为未选中，并设置文本居中对齐
        QTableWidgetItem* checkItem = new QTableWidgetItem();
        checkItem->setCheckState(Qt::Unchecked);
        checkItem->setTextAlignment(Qt::AlignCenter);
        // 将选择状态项设置到表格的对应位置
        ui->tableWidget->setItem(i, 6, checkItem);
    }
}

void Widget::on_tableWidget_cellClicked(int row, int col)
{
    if(col == 6) {
        QTableWidgetItem* item = ui->tableWidget->item(row, col);
        if(item->checkState() == Qt::Checked) {
            item->setCheckState(Qt::Unchecked);
        } else {
            item->setCheckState(Qt::Checked);
        }
    }
}

void Widget::on_addButton_clicked()
{
    addwidget* aw = new addwidget(this);
    aw->setAttribute(Qt::WA_DeleteOnClose);
    aw->show();
}

void Widget::on_selectButton_clicked()
{
    QString keyword = ui->lineEdit->text().trimmed();
    if (keyword.isEmpty()) {
        showList(StuList::get());
        return;
    }

    std::vector<Student*>* results = nullptr;
    bool hasResult = false;
    
    // 首先尝试精确文本搜索
    results = Tool::findStudents(
        StuList::get(), 
        keyword,
        true,    // 匹配学号
        true,    // 匹配姓名
        true     // 使用精确匹配
    );
    
    // 如果精确匹配没找到，尝试模糊匹配
    if (!results || results->empty()) {
        if (results) {
            delete results;
        }
        results = Tool::findStudents(
            StuList::get(),
            keyword,
            true,   // 匹配学号
            true,   // 匹配姓名
            false   // 使用模糊匹配
        );
    } else {
        hasResult = true;
    }

    // 确保 results 不为空
    if (!results) {
        results = new std::vector<Student*>();
    }
    
    if (!hasResult && results->empty()) {
        // 在显示消息框之前先显示完整列表
        showList(StuList::get());
        
        // 创建并配置消息框
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("提示");
        msgBox.setText("未找到匹配的学生信息");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowModality(Qt::WindowModal);  // 设置为窗口级别的模态对话框
        msgBox.setStandardButtons(QMessageBox::Ok);
        
        // 显示消息框并等待用户响应
        msgBox.exec();
    } else {
        showList(results);
    }
    
    // 释放结果内存
    delete results;
    
    // 确保主窗口保持在前台并获得焦点
    this->show();
    this->raise();
    this->activateWindow();
}

void Widget::on_updateButton_clicked()
{
    // 记录用户选中的学生数量
    int selectedCount = 0;
    // 记录选中学生所在的行号，初始化为 -1 表示未选中
    int selectedRow = -1;
    // 遍历表格的每一行
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        // 检查第 i 行第 6 列的复选框是否被选中
        if(ui->tableWidget->item(i, 6)->checkState() == Qt::Checked) {
            // 若选中，选中学生数量加 1
            selectedCount++;
            // 记录当前选中学生所在的行号
            selectedRow = i;
        }
    }

    // 检查是否没有选中任何学生
    if(selectedCount == 0) {
        // 若未选中，弹出警告框提示用户选择要修改的学生
        QMessageBox::warning(this, "警告", "请先选择要修改的学生！");
        // 直接返回，结束函数执行
        return;
    }
    // 检查是否选中了多个学生
    if(selectedCount > 1) {
        // 若选中多个，弹出警告框提示用户一次只能修改一个学生
        QMessageBox::warning(this, "警告", "一次只能修改一个学生！");
        // 直接返回，结束函数执行
        return;
    }

    // 获取选中学生的学号
    QString id = ui->tableWidget->item(selectedRow, 0)->text();
    
    // 用于存储选中的学生对象指针，初始化为 nullptr
    Student* selectedStudent = nullptr;
    // 遍历全局学生列表
    for(Student* stu : *StuList::get()) {
        // 检查当前学生的学号是否与选中学生的学号一致
        if(stu->getId() == id) {
            // 若一致，将该学生对象指针赋值给 selectedStudent
            selectedStudent = stu;
            // 找到后跳出循环
            break;
        }
    }

    // 检查是否成功找到选中的学生对象
    if(selectedStudent) {
        // 若找到，创建一个新的添加/修改窗口，并传入选中的学生对象和父窗口指针
        addwidget* aw = new addwidget(selectedStudent, this);
        // 设置窗口在关闭时自动释放内存
        aw->setAttribute(Qt::WA_DeleteOnClose);
        // 显示添加/修改窗口
        aw->show();
    }
}

void Widget::on_deleteButton_clicked()
{
    // 用于存储用户选中要删除的学生的学号
    std::vector<QString> selectedIds;

    // 遍历表格的每一行，检查第 6 列的复选框是否被选中
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        if(ui->tableWidget->item(i, 6)->checkState() == Qt::Checked) {
            selectedIds.push_back(ui->tableWidget->item(i, 0)->text());
        }
    }


    if(selectedIds.empty()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的学生！");
        return;
    }


    QString message = QString("确认要删除选中的 %1 个学生吗？此操作不可撤销！").arg(selectedIds.size());

    sureDialog dialog(message, this);

    dialog.exec();

    // 检查用户是否确认删除
    if(!dialog.isConfirmed()) {
        // 如果用户取消，直接返回
        return;
    }

    // 获取全局的学生列表
    auto stulist = StuList::get();
    // 标记学生列表是否被修改
    bool modified = false;
    

    for(auto it = stulist->begin(); it != stulist->end();) {
        // 检查当前学生的学号是否在选中的学号列表中， 如果在列表中，删除该学生对象， 如果不在列表中，移动到下一个学生对象
        if(std::find(selectedIds.begin(), selectedIds.end(), (*it)->getId()) != selectedIds.end()) {

            delete *it;
            it = stulist->erase(it);
            // 标记学生列表已被修改
            modified = true;
        } else {
            ++it;
        }
    }

    // 检查学生列表是否被修改
    if(modified) {
        try {
            // 尝试将更新后的学生列表写入文件
            Tool::writeAllStudents(stulist, Config::filePath);

            showList(stulist);

            QMessageBox::information(this, "提示", "删除成功！");
        } catch (const QString& error) {
            // 如果写入文件时出现异常，弹出错误框显示错误信息
            QMessageBox::critical(this, "错误", error);
        }
    }
}

