TEMPLATE = subdirs
SUBDIRS += \
    quickcalendartemplate \
    quickcalendar \
    imports

quickcalendar.depends = quickcalendartemplate
imports.depends = quickcalendar quickcalendartemplate
