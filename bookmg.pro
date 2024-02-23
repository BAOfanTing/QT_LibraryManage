QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


#让生成的可执行程序放到指定文件夹
DESTDIR  = $$PWD/./bin

#添加两个路径
include($$PWD/cell/cell.pri)
include($$PWD/lib/lib.pri)

# # Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc

RC_FILE = $$PWD/res/app.rc
