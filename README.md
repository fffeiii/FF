# 学生信息管理系统 (SIMS)

[![Qt](https://img.shields.io/badge/Qt-6.9.0-green.svg)](https://www.qt.io/)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## 功能特点

- 📝 完整的学生信息管理（增删改查）
- 🎓 支持本科生和研究生差异化管理
- 🔍 智能搜索功能
- 💾 数据持久化存储
- 🎨 现代化界面设计


## 项目结构

```
SIMS/
├── src/
│   ├── main.cpp          # 程序入口
│   ├── widget.cpp        # 主窗口实现
│   ├── addwidget.cpp     # 添加/编辑窗口
│   ├── stu.cpp          # 学生类实现
│   ├── stuList.cpp      # 学生列表管理
│   └── tool.cpp         # 工具类实现
├── include/
│   ├── widget.h         # 主窗口声明
│   ├── stu.h           # 学生类声明
│   ├── config.h        # 配置文件
│   └── tool.h          # 工具类声明
├── ui/
│   ├── widget.ui        # 主窗口界面
│   ├── addwidget.ui     # 添加窗口界面
│   └── suredialog.ui    # 确认对话框界面
└── SIMS.pro             # 项目文件
```

## 核心功能

### 1. 学生信息管理
- 添加新学生记录
- 修改已有信息
- 删除学生记录
- 查看详细信息

### 2. 智能搜索
- 按学号搜索
- 按姓名搜索
- 模糊匹配支持

### 3. 数据持久化
- 自动保存数据
- 文件异常处理
- 数据完整性校验

## 技术特点

1. **面向对象设计**
   - 继承与多态的应用
   - 封装与信息隐藏

2. **设计模式应用**
   - 单例模式管理学生列表
   - MVC架构设计

3. **现代C++特性**
   - 智能指针管理资源
   - STL容器使用
