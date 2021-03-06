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

#ifndef QQUICKCALENDAR_P_H
#define QQUICKCALENDAR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobject.h>
#include <QtCore/qdatetime.h>
#include <QtQml/qqml.h>
#include <QtQuickTemplates2/private/qquickpage_p.h>

QT_BEGIN_NAMESPACE

class QQuickCalendarPrivate;


class QQuickCalendar : public QQuickPage
{
    Q_OBJECT

public:
    explicit QQuickCalendar();

    enum Month {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };
    Q_ENUM(Month)

protected:
    void componentComplete() override;
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void paddingChange(const QMarginsF &newPadding, const QMarginsF &oldPadding) override;
    void updatePolish() override;

private:
    Q_DISABLE_COPY(QQuickCalendar)
    Q_DECLARE_PRIVATE(QQuickCalendar)

};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickCalendar)

#endif // QQUICKCALENDAR_P_H
