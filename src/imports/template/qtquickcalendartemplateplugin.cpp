/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Templates 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/private/qqmlglobal_p.h>

#include <QtQuickCalendarTemplate/private/qquickcalendar_p.h>
#include <QtQuickCalendarTemplate/private/qquickcalendarmodel_p.h>
#include <QtQuickCalendarTemplate/private/qquickdayofweekmodel_p.h>
#include <QtQuickCalendarTemplate/private/qquickdayofweekrow_p.h>
#include <QtQuickCalendarTemplate/private/qquickmonthgrid_p.h>
#include <QtQuickCalendarTemplate/private/qquickmonthmodel_p.h>
#include <QtQuickCalendarTemplate/private/qquickweeknumbercolumn_p.h>
#include <QtQuickCalendarTemplate/private/qquickweeknumbermodel_p.h>


//#if QT_CONFIG(shortcut)
//// qtdeclarative/src/quick/util/qquickshortcut.cpp
//typedef bool (*ShortcutContextMatcher)(QObject *, Qt::ShortcutContext);
//extern ShortcutContextMatcher qt_quick_shortcut_context_matcher();
//extern void qt_quick_set_shortcut_context_matcher(ShortcutContextMatcher matcher);
//#endif

QT_BEGIN_NAMESPACE

class QtQuickCalendarTemplatePlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    QtQuickCalendarTemplatePlugin(QObject *parent = nullptr);
    ~QtQuickCalendarTemplatePlugin();

    void registerTypes(const char *uri) override;
    void unregisterTypes();

private:
    bool registered;
//#if QT_CONFIG(shortcut)
//    ShortcutContextMatcher originalContextMatcher;
//#endif
};

QtQuickCalendarTemplatePlugin::QtQuickCalendarTemplatePlugin(QObject *parent)
    : QQmlExtensionPlugin(parent), registered(false)
{
}

QtQuickCalendarTemplatePlugin::~QtQuickCalendarTemplatePlugin()
{
    // Intentionally empty: we use register/unregisterTypes() to do
    // initialization and cleanup, as plugins are not unloaded on macOS.
}

void QtQuickCalendarTemplatePlugin::registerTypes(const char *uri)
{
//#if QT_CONFIG(shortcut)
//    originalContextMatcher = qt_quick_shortcut_context_matcher();
//    qt_quick_set_shortcut_context_matcher(QQuickShortcutContext::matcher);
//#endif

    registered = true;

    // The minor version used to be the current Qt 5 minor. For compatibility it is the last
    // Qt 5 release.
    qmlRegisterModule(uri, 2, 15);

    // QtQuick.Templates 2.0 (originally introduced in Qt 5.7)
    qmlRegisterType<QQuickDayOfWeekRow>(uri, 2, 0, "AbstractDayOfWeekRow");
    qmlRegisterType<QQuickMonthGrid>(uri, 2, 0, "AbstractMonthGrid");
    qmlRegisterType<QQuickWeekNumberColumn>(uri, 2, 0, "AbstractWeekNumberColumn");
    qmlRegisterType<QQuickCalendarModel>(uri, 2, 0, "CalendarModel");
    qmlRegisterType<QQuickCalendar>(uri, 2, 0, "AbstractCalendar");

}

void QtQuickCalendarTemplatePlugin::unregisterTypes()
{
//#if QT_CONFIG(shortcut)
//    qt_quick_set_shortcut_context_matcher(originalContextMatcher);
//#endif
}

QT_END_NAMESPACE

#include "qtquickcalendartemplateplugin.moc"
