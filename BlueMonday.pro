
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = BlueMonday
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
include(src/src.pri)
RESOURCES += \
    $$PWD/resources/resource.qrc
DISTFILES += \
    appveyor.yml \
    README.md
