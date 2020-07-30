TEMPLATE = app
TARGET = eventcalendar
QT += sql qml

CONFIG += qmltypes
QML_IMPORT_NAME = App
QML_IMPORT_MAJOR_VERSION = 1

SOURCES += eventcalendar.cpp

RESOURCES += \
    eventcalendar.qml \
    qtquickcontrols2.conf

target.path = $$[QT_INSTALL_EXAMPLES]/quickcalendar/eventcalendar
INSTALLS += target
