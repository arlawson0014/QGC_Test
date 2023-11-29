
import QtQuick         2.12
import QtQuick.Layouts 1.3

import QGroundControl               1.0
import QGroundControl.Airspace      1.0
import QGroundControl.Airmap        1.0
import QGroundControl.Controls      1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Palette       1.0
import QGroundControl.FactSystem    1.0
import QGroundControl.FactControls  1.0
import QGroundControl.Controllers   1.0
import QGroundControl.PX4           1.0

Item {
    id: _root

    width: backgroundRectangle.width
    height: backgroundRectangle.height

    property var       _activeVehicle:   QGroundControl.multiVehicleManager.activeVehicle ? QGroundControl.multiVehicleManager.activeVehicle : QGroundControl.multiVehicleManager.offlineEditingVehicle
    property FactGroup _engineFactGroup: _activeVehicle.getFactGroup("engine")
    property Fact _rpm: _engineFactGroup.rpm
    property var _cylinderHeadTemperature: (_engineFactGroup.temperatureUnits === 1 ? _engineFactGroup.cylinderHeadTemperature : ( ( _engineFactGroup.cylinderHeadTemperature.value * 1.8 ) + 32 ) )
    property var _cylinderHeadTemperatureUnits: (_engineFactGroup.temperatureUnits.value === 1 ? "°F" : "°C")
    property Fact _throttle: _engineFactGroup.throttlePosition
    property Fact _engineStatus: _engineFactGroup.health
    property Fact _engineStatusText: _engineFactGroup.statusText

    readonly property int _margins: ScreenTools.defaultFontPixelWidth
    readonly property int _labelWidth: ScreenTools.defaultFontPixelWidth
    readonly property int _labelHeight: ScreenTools.defaultFontPixelHeight

    Rectangle {
        id: backgroundRectangle
        radius: 5
        width: engineMonitorColumn.width
        height: engineMonitorColumn.height
        anchors.fill: parent
        color: qgcPal.windowShade

        ColumnLayout {
            id: engineMonitorColumn

            RowLayout {
                spacing: ScreenTools.defaultFontPixelWidth
                Layout.fillHeight: true
                Layout.fillWidth:  true
                Layout.margins:    _margins

                QGCLabel {
                    text: "RPM: " + ( isNaN(_rpm.value) ? "-" : _rpm.value )
                    width:  _labelWidth
                    height: _labelHeight
                }
                QGCLabel {
                    text: "Throttle: " + ( isNaN(_throttle.value) ? "-" : _throttle.value + "%" )
                    width:  _labelWidth
                    height: _labelHeight
                }
            }

            RowLayout {
                spacing: ScreenTools.defaultFontPixelWidth
                Layout.fillHeight: true
                Layout.fillWidth:  true
                Layout.margins:    _margins

                QGCLabel {
                    text: "CHT: " + ( isNaN(_cylinderHeadTemperature.value) ? "-" : _cylinderHeadTemperature.value + _coreHeadTemperatureUnits )
                    width:  _labelWidth
                    height: _labelHeight
                }
                QGCLabel {
                    text:  _engineStatusText.valueString
                    color: _engineStatus.value === 3 ? "red" : ( _engineStatus.value === 2 ? "orange" : qgcPal.text )
                    width:  _labelWidth
                    height: _labelHeight
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }
    }
}

