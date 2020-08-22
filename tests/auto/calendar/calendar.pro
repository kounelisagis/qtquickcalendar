TEMPLATE = app
TARGET = tst_calendar
CONFIG += qmltestcase
CONFIG-=create_cmake

SOURCES += \
    $$PWD/tst_calendar.cpp

OTHER_FILES += \
    $$PWD/data/*.qml

TESTDATA += \
    $$PWD/data/tst_*
