TARGET = qtquickcalendarmaterialstyleplugin
TARGETPATH = QtQuick/Calendar/Material

IMPORT_NAME = QtQuick.Calendar.Material
IMPORT_VERSION = 2.0

QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private quickcontrols2-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

#include(material.pri)

OTHER_FILES += \
    qmldir \
    $$QML_FILES

SOURCES += \
    $$PWD/qtquickcalendarmaterialstyleplugin.cpp

RESOURCES += \
    $$PWD/qtquickcalendarmaterialstyleplugin.qrc

CONFIG += no_cxx_module install_qml_files builtin_resources qtquickcompiler
load(qml_plugin)

requires(qtConfig(quickcalendar-material))
