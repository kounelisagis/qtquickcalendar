TARGET = QtQuickCalendarTemplate
MODULE = quickcalendartemplate

QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private
qtHaveModule(qmlmodels): QT += qmlmodels-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

HEADERS += \
    $$PWD/qtquickcalendartemplateglobal_p.h

include(quickcalendartemplate.pri)
load(qt_module)
