QT       += core gui widgets

CONFIG += c++17

INCLUDEPATH += $$[QT_INSTALL_HEADERS]
LIBS += -L$$[QT_INSTALL_LIBS]

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    stu.cpp \
    stuList.cpp \
    suredialog.cpp \
    tool.cpp \
    widget.cpp \
    addwidget.cpp

HEADERS += \
    config.h \
    stu.h \
    stuList.h \
    suredialog.h \
    tool.h \
    widget.h \
    addwidget.h

FORMS += \
    suredialog.ui \
    widget.ui \
    addwidget.ui

TRANSLATIONS +=
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    students.dat

# 添加 QStringConverter 支持
DEFINES += QT_USE_QSTRINGBUILDER

# 设置数据文件复制
win32 {
    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK += $(COPY) $$shell_quote($$PWD\\students.dat) $$shell_quote($$OUT_PWD\\debug) $$escape_expand(\\n\\t)
    } else {
        QMAKE_POST_LINK += $(COPY) $$shell_quote($$PWD\\students.dat) $$shell_quote($$OUT_PWD\\release) $$escape_expand(\\n\\t)
    }
}
