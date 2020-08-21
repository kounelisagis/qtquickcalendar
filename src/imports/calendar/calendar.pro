TARGET = qtquickcalendarplugin
TARGETPATH = QtQuick/Calendar
IMPORT_VERSION = 2.0

QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private quickcontrols2-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

include(calendar.pri)

OTHER_FILES += \
    qmldir \
    $$QML_FILES

SOURCES += \
    $$PWD/qtquickcalendarplugin.cpp

#RESOURCES += \
#    $$PWD/qtquickcontrols2plugin.qrc

#qtConfig(quick-designer): include(designer/designer.pri)
#include(doc/doc.pri)

CONFIG += no_cxx_module install_qml_files builtin_resources qtquickcompiler

load(qml_plugin)

requires(qtConfig(quickcontrols2-default))
