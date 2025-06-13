#ifndef STULIST_H
#define STULIST_H

#include <vector>
#include "stu.h"

/**
 * @brief 学生列表管理类
 * 
 * 使用单例模式管理全局学生列表，提供学生数据的访问接口
 */
class StuList
{
public:
    /** 
     * @brief 获取学生列表实例
     * @return 返回存储学生对象的向量指针
     */
    static std::vector<Student*>* get();

    ~StuList();

private:
    /** @brief 私有构造函数，防止直接创建实例 */
    StuList();
    
    static std::vector<Student*>* stulist;  ///< 存储所有学生对象的向量指针
};

#endif // STULIST_H
