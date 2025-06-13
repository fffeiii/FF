#ifndef STU_H
#define STU_H
#include<QString>

/**
 * @brief 学生基类
 * 
 * 这是所有学生类型的基类，包含学生的基本信息和操作。
 * 提供了学生信息的存取方法和虚函数接口。
 */
class Student
{
    protected:
        QString id;      ///< 学号
        QString name;    ///< 姓名
        QString gender;  ///< 性别
        int age;        ///< 年龄
        double credits; ///< 原始学分
    public:

        Student();

        /**
         * @brief 带参数的构造函数
         * @param id 学号
         * @param name 姓名
         * @param gender 性别
         * @param age 年龄
         * @param credits 学分
         */
        Student(QString &id, QString &name, QString &gender, int &age, double &credits);
        
        virtual ~Student();

        // Setters
        void setId(const QString &id);      ///< 设置学号
        void setName(const QString &name);  ///< 设置姓名
        void setGender(const QString &gender); ///< 设置性别
        void setAge(const int &age);        ///< 设置年龄
        void setCredits(const double &credits); ///< 设置学分

        // Getters
        QString getId() const;      ///< 获取学号
        QString getName() const;    ///< 获取姓名
        QString getGender() const;  ///< 获取性别
        int getAge() const;        ///< 获取年龄
        double getRawCredits() const { return credits; } ///< 获取原始学分

        /**
         * @brief 获取计算后的学分
         * @return 返回根据学生类型计算后的学分
         */
        virtual double getCredits() const = 0;

        /**
         * @brief 获取学生类型
         * @return 返回学生类型的字符串描述
         */
        virtual QString getType() const = 0;
};

/**
 * @brief 本科生类
 * 
 * 继承自Student类，实现本科生特有的学分计算方式（学分×1.5）
 */
class Undergraduate : public Student {
public:
    int type = 0;  ///< 类型标识，0表示本科生
    
    Undergraduate();

    /**
     * @brief 带参数的构造函数
     * @param id 学号
     * @param name 姓名
     * @param gender 性别
     * @param age 年龄
     * @param credits 学分
     */
    Undergraduate(QString &id, QString &name, QString &gender, int &age, double &credits);
    
    virtual ~Undergraduate() = default;

    /**
     * @brief 获取计算后的学分
     * @return 返回原始学分×1.5的结果
     */
    virtual double getCredits() const override;

    /**
     * @brief 获取学生类型
     * @return 返回"本科生"
     */
    virtual QString getType() const override { return "本科生"; }
};

/**
 * @brief 研究生类
 * 
 * 继承自Student类，实现研究生特有的学分计算方式（学分×2.0）
 */
class Postgraduate : public Student {
public:
    int type = 1;  ///< 类型标识，1表示研究生
    
    Postgraduate();

    /**
     * @brief 带参数的构造函数
     * @param id 学号
     * @param name 姓名
     * @param gender 性别
     * @param age 年龄
     * @param credits 学分
     */
    Postgraduate(QString &id, QString &name, QString &gender, int &age, double &credits);
    
    virtual ~Postgraduate() = default;

    /**
     * @brief 获取计算后的学分
     * @return 返回原始学分×2.0的结果
     */
    virtual double getCredits() const override;

    /**
     * @brief 获取学生类型
     * @return 返回"研究生"
     */
    virtual QString getType() const override { return "研究生"; }
};

#endif // STU_H
