TARGET = QtQuickCalendar
MODULE = quickcalendar

QT += quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

HEADERS += \
    $$PWD/qtquickcalendarglobal.h \
    $$PWD/qtquickcalendarglobal_p.h \
    $$PWD/qtquickcalendar-config_p.h

#include(quickcalendar.pri)
load(qt_module)
