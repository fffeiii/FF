#include"stu.h"

// 学生基类的实现
Student::Student()
{
    // 初始化所有成员变量为默认值
    id = "";
    name = "";
    gender = "";
    age = 0;
    credits = 0;
}

Student::Student(QString &id, QString &name, QString &gender, int &age, double &credits)
{
    // 使用参数初始化成员变量
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->credits = credits;
}

Student::~Student()
{
    // 虚析构函数，确保正确释放派生类资源
}

// Setter方法实现
void Student::setId(const QString &id){
    this->id = id;
}

void Student::setName(const QString &name){
    this->name = name;
}

void Student::setGender(const QString &gender)
{
    this->gender = gender;
}

void Student::setAge(const int &age){
    this->age = age;
}

void Student::setCredits(const double &credits){
    this->credits = credits;
}

// Getter方法实现
QString Student::getId() const{
    return id;
}

QString Student::getName() const{
    return name;
}

QString Student::getGender() const{
    return gender;
}

int Student::getAge() const{
    return age;
}

// 本科生类特有方法实现
double Undergraduate::getCredits() const{
    return credits * 1.5;  // 本科生学分计算：原始学分 × 1.5
}

// 研究生类特有方法实现
double Postgraduate::getCredits() const{
    return credits * 2.0;  // 研究生学分计算：原始学分 × 2.0
}

// 本科生构造函数实现
Undergraduate::Undergraduate() : Student() {
    // 调用基类默认构造函数
}

Undergraduate::Undergraduate(QString &id, QString &name, QString &gender, int &age, double &credits)
    : Student(id, name, gender, age, credits) {
    // 调用基类带参构造函数
}

// 研究生构造函数实现
Postgraduate::Postgraduate() : Student() {
    // 调用基类默认构造函数
}

Postgraduate::Postgraduate(QString &id, QString &name, QString &gender, int &age, double &credits)
    : Student(id, name, gender, age, credits) {
    // 调用基类带参构造函数
}
