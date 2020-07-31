TEMPLATE = app
TARGET = examplecalendar
QT += qml

QML_IMPORT_NAME = App
QML_IMPORT_MAJOR_VERSION = 1

SOURCES += examplecalendar.cpp

RESOURCES += \
    examplecalendar.qml \
    qtquickcontrols2.conf

target.path = $$[QT_INSTALL_EXAMPLES]/quickcalendar/examplecalendar
INSTALLS += target
