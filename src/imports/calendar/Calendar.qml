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

import QtQuick 2.15
import QtQuick.Calendar 1.0
import QtQuick.Layouts 1.15

import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15


AbstractCalendar {
    id: control

//    required property EventDatabase eventDatabase

    readonly property date currentDate: new Date()

//    header: ToolBar {
//        Label {
//            text: window.currentDate.toLocaleString(locale, "MMMM yyyy")
//            font.pixelSize: Qt.application.font.pixelSize * 1.25
//            anchors.centerIn: parent
//        }
//    }

//  used for debugging
    Component.onCompleted: print(width, height);

    GridLayout {
        anchors.fill: parent
        columns: 2

        DayOfWeekRow {
            id: dayOfWeekRow
            locale: grid.locale
            font.bold: false
            delegate: Label {
                text: model.shortName
                font: dayOfWeekRow.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Layout.column: 1
            Layout.fillWidth: true
        }

        WeekNumberColumn {
            month: grid.month
            year: grid.year
            locale: grid.locale
            font.bold: false

            Layout.fillHeight: true
        }

        MonthGrid {
            id: grid
            month: window.currentDate.getMonth()
            year: window.currentDate.getFullYear()
            spacing: 0

            readonly property int gridLineThickness: 1

            Layout.fillWidth: true
            Layout.fillHeight: true

//            delegate: MonthGridDelegate {
//                id: gridDelegate
//                visibleMonth: grid.month
//                eventDatabase: window.eventDatabase
//            }

            background: Item {
                x: grid.leftPadding
                y: grid.topPadding
                width: grid.availableWidth
                height: grid.availableHeight

                // Vertical lines
                Row {
                    spacing: (parent.width - (grid.gridLineThickness * rowRepeater.model)) / rowRepeater.model

                    Repeater {
                        id: rowRepeater
                        model: 7
                        delegate: Rectangle {
                            width: 1
                            height: grid.height
                            color: "#ccc"
                        }
                    }
                }

                // Horizontal lines
                Column {
                    spacing: (parent.height - (grid.gridLineThickness * columnRepeater.model)) / columnRepeater.model

                    Repeater {
                        id: columnRepeater
                        model: 6
                        delegate: Rectangle {
                            width: grid.width
                            height: 1
                            color: "#ccc"
                        }
                    }
                }
            }
        }
    }

}
