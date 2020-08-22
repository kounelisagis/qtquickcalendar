TARGET = qtquickcalendartemplateplugin
TARGETPATH = QtQuick/CalendarTemplate
IMPORT_VERSION = 2.0

QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quickcalendartemplate-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

OTHER_FILES += \
    qmldir

SOURCES += \
    $$PWD/qtquickcalendartemplateplugin.cpp

CONFIG += no_cxx_module
load(qml_plugin)
