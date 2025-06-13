#include"stuList.h"

// 初始化静态成员变量
std::vector<Student*>* StuList::stulist = new std::vector<Student*>();

// 私有构造函数实现
StuList::StuList(){}

std::vector<Student*>* StuList::get(){
    // 确保列表存在，如果不存在则创建
    if(stulist==nullptr){
        StuList::stulist = new std::vector<Student*>;
    }
    return StuList::stulist;
}

StuList::~StuList(){
    // 清理所有资源
    if(stulist != nullptr){
        // 删除每个学生对象
        for(auto* student : *stulist){
            delete student;
        }
        // 清空并删除列表
        stulist->clear();
        delete stulist;
        stulist = nullptr;
    }
}
