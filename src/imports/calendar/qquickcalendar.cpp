/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Calendar.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qquickcalendar_p.h"
#include "qquickcalendarmodel_p.h"

#include <QtQuickTemplates2/private/qquickcontrol_p_p.h>
#include <QtQuickTemplates2/private/qquickpage_p.h>

QT_BEGIN_NAMESPACE

/*!
    \qmltype Calendar
    \inherits QObject
//! \instantiates QQuickCalendar
    \inqmlmodule QtQuick.Calendar
    \brief A calendar namespace.

    The Calendar singleton provides miscellaneous calendar related
    utilities.

    \include zero-based-months.qdocinc

    \sa MonthGrid, DayOfWeekRow, WeekNumberColumn
*/

class QQuickCalendarPrivate : public QQuickControlPrivate
{
    Q_DECLARE_PUBLIC(QQuickCalendar)

public:
    void resizeItems();

    static void setContextProperty(QQuickItem *item, const QString &name, const QVariant &value);

    QVariant source;
    QQuickCalendarModel *model;
};

void QQuickCalendarPrivate::resizeItems()
{
    if (!contentItem)
        return;

    QSizeF itemSize;
    itemSize.setWidth((contentItem->width() - 6 * spacing) / 7);
    itemSize.setHeight((contentItem->height() - 5 * spacing) / 6);

    const auto childItems = contentItem->childItems();
    for (QQuickItem *item : childItems) {
        if (!QQuickItemPrivate::get(item)->isTransparentForPositioner())
            item->setSize(itemSize);
    }
}


void QQuickCalendarPrivate::setContextProperty(QQuickItem *item, const QString &name, const QVariant &value)
{
    QQmlContext *context = qmlContext(item);
    if (context && context->isValid()) {
        context = context->parentContext();
        if (context && context->isValid())
            context->setContextProperty(name, value);
    }
}


QQuickCalendar::QQuickCalendar(): QQuickPage()
{
    Q_D(QQuickCalendar);
    setFlag(ItemIsFocusScope);
    setActiveFocusOnTab(true);
    setAcceptedMouseButtons(Qt::LeftButton);
#if QT_CONFIG(cursor)
    setCursor(Qt::ArrowCursor);
#endif

    d->model = new QQuickCalendarModel(this);
    d->source = QVariant::fromValue(d->model);
}



void QQuickCalendar::componentComplete()
{
    Q_D(QQuickCalendar);
    QQuickControl::componentComplete();
    if (d->contentItem) {
        const auto childItems = d->contentItem->childItems();
        for (QQuickItem *child : childItems) {
            if (!QQuickItemPrivate::get(child)->isTransparentForPositioner())
                d->setContextProperty(child, QStringLiteral("pressed"), false);
        }
    }
    d->resizeItems();
}


void QQuickCalendar::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    Q_D(QQuickCalendar);
    QQuickControl::geometryChanged(newGeometry, oldGeometry);
    if (isComponentComplete())
        d->resizeItems();
}

void QQuickCalendar::paddingChange(const QMarginsF &newPadding, const QMarginsF &oldPadding)
{
    Q_D(QQuickCalendar);
    QQuickControl::paddingChange(newPadding, oldPadding);
    if (isComponentComplete())
        d->resizeItems();
}

void QQuickCalendar::updatePolish()
{
    Q_D(QQuickCalendar);
    QQuickControl::updatePolish();
    d->resizeItems();
}


QT_END_NAMESPACE
