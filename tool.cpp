#include "tool.h"
#include <QFile>
#include <QTextStream>

void Tool::loadAllStudents(std::vector<Student*> *stulist, QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw QString("无法打开文件：%1").arg(filePath);
    }

    QTextStream in(&file);
    // 设置文件编码为UTF-8
    in.setEncoding(QStringConverter::Utf8);

    // 逐行读取文件内容
    while(!in.atEnd()) {
        QString line = in.readLine();
        if(line.trimmed().isEmpty()) continue;  // 跳过空行
        
        // 解析每行数据
        QStringList fields = line.split(" ", Qt::SkipEmptyParts);
        if(fields.size() < 6) continue;  // 确保数据完整性
        
        // 提取字段
        QString tempId = fields[0];
        QString tempName = fields[1];
        QString tempGender = fields[2];
        int tempAge = fields[3].toInt();
        double tempCredits = fields[4].toDouble();
        QString tempType = fields[5];

        // 根据学生类型创建对应的对象
        Student* newStudent = nullptr;
        if(tempType == "研究生") {
            newStudent = new Postgraduate(tempId, tempName, tempGender, tempAge, tempCredits);
        }
        else if(tempType == "本科生") {
            newStudent = new Undergraduate(tempId, tempName, tempGender, tempAge, tempCredits);
        }

        // 将新创建的学生对象添加到列表中
        if(newStudent) {
            stulist->push_back(newStudent);
        }
    }
    
    file.close();
}

void Tool::writeAllStudents(std::vector<Student*> *stulist, QString filePath)
{
    // 以写入模式打开文件，如果存在则清空内容
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        throw QString("无法写入文件：%1").arg(filePath);
    }

    QTextStream out(&file);
    // 遍历学生列表，将每个学生信息写入文件
    for(const Student* stu : *stulist) {
        out << stu->getId() << " "
            << stu->getName() << " "
            << stu->getGender() << " "
            << stu->getAge() << " "
            << stu->getRawCredits() << " "  // 使用getRawCredits获取原始学分
            << stu->getType() << "\n";
    }

    file.close();
}


std::vector<Student*>* Tool::findStudents(std::vector<Student*>* stulist, 
    const QString& keyword, bool matchId, bool matchName, bool exactMatch) 
{
    // 创建一个新的向量，用于存储匹配到的学生对象指针
    std::vector<Student*>* results = new std::vector<Student*>();
    
    // 检查是否有有效的搜索条件，如果关键词为空或者既不匹配学号也不匹配姓名，则直接返回空结果
    if(keyword.isEmpty() || (!matchId && !matchName)) {
        return results;
    }
    
    for(Student* stu : *stulist) {
        // 标记当前学生是否匹配搜索条件，初始化为 false
        bool matched = false;
        // 如果需要匹配学号
        if(matchId) {
            // 如果是精确匹配模式
            if(exactMatch) {
                // 检查学生的学号是否与关键词完全相等
                matched = stu->getId() == keyword;
            } else {
                // 非精确匹配模式，检查学生的学号是否包含关键词（不区分大小写）
                matched = stu->getId().contains(keyword, Qt::CaseInsensitive);
            }
        }
        // 如果学号未匹配且需要匹配姓名
        if(!matched && matchName) {
            // 如果是精确匹配模式
            if(exactMatch) {
                // 检查学生的姓名是否与关键词完全相等
                matched = stu->getName() == keyword;
            } else {
                // 非精确匹配模式，检查学生的姓名是否包含关键词（不区分大小写）
                matched = stu->getName().contains(keyword, Qt::CaseInsensitive);
            }
        }
        // 如果当前学生匹配搜索条件
        if(matched) {
            // 将该学生对象指针添加到结果向量中
            results->push_back(stu);
        }
    }
    // 返回存储匹配学生对象指针的向量
    return results;
}
