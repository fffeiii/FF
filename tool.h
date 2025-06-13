#ifndef TOOL_H
#define TOOL_H

#include "stu.h"
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>

/**
 * @brief 工具类
 * 
 * 提供文件操作和学生信息查找的工具方法
 */
class Tool
{
public:
    /**
     * @brief 从文件加载所有学生信息
     * @param stulist 学生列表指针
     * @param filePath 文件路径
     * @throw QString 如果文件无法打开
     */
    static void loadAllStudents(std::vector<Student*> *stulist, QString filePath);

    /**
     * @brief 将学生信息保存到文件
     * @param stulist 学生列表指针
     * @param filePath 文件路径
     * @throw QString 如果文件无法写入
     */
    static void writeAllStudents(std::vector<Student*> *stulist, QString filePath);

    /**
     * @brief 按条件搜索学生
     * @param stulist 要搜索的学生列表
     * @param keyword 搜索关键字
     * @param matchId 是否匹配学号
     * @param matchName 是否匹配姓名
     * @param exactMatch 是否精确匹配（true:完全匹配, false:包含匹配）
     * @return 返回匹配的学生列表指针（调用者负责释放内存）
     */
    static std::vector<Student*>* findStudents(std::vector<Student*>* stulist, 
        const QString& keyword, bool matchId = true, bool matchName = true, 
        bool exactMatch = false);

};
#endif // TOOL_H
