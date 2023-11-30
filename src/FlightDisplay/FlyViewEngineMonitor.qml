
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

    // property var       _activeVehicle:   QGroundControl.multiVehicleManager.activeVehicle ? QGroundControl.multiVehicleManager.activeVehicle : QGroundControl.multiVehicleManager.offlineEditingVehicle
    // property FactGroup _engineFactGroup: _activeVehicle.getFactGroup("engine")
    property int _rpm: 7200 //_engineFactGroup.rpm
    property int _cylinderHeadTemperature: 280 //(_engineFactGroup.temperatureUnits === 1 ? _engineFactGroup.cylinderHeadTemperature : ( ( _engineFactGroup.cylinderHeadTemperature.value * 1.8 ) + 32 ) )
    property string _cylinderHeadTemperatureUnits: "°F" //(_engineFactGroup.temperatureUnits.value === 1 ? "°F" : "°C")
    property int _throttle: 75 // _engineFactGroup.throttlePosition
    property int _engineStatus: 2 // _engineFactGroup.health
    property string _engineStatusText: "HOT" //_engineFactGroup.statusText

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
                    text: "RPM: " + ( isNaN(_rpm) ? "-" : _rpm )
                    color: ( _rpm > 7000 ? "red" : ( _rpm > 6500 ? "orange" : qgcPal.text ) )
                    width:  _labelWidth
                    height: _labelHeight
                }
                QGCLabel {
                    text: "Throttle: " + ( isNaN(_throttle) ? "-" : _throttle + "%" )
                    width:  _labelWidth
                    height: _labelHeight.valueString
                }
            }

            RowLayout {
                spacing: ScreenTools.defaultFontPixelWidth
                Layout.fillHeight: true
                Layout.fillWidth:  true
                Layout.margins:    _margins

                QGCLabel {
                    text: "CHT: " + ( isNaN(_cylinderHeadTemperature) ? "-" : _cylinderHeadTemperature + _cylinderHeadTemperatureUnits )
                    color: ( _cylinderHeadTemperature > 290 ? "red" : ( _cylinderHeadTemperature > 275 ? "orange" : qgcPal.text ) )
                    width:  _labelWidth
                    height: _labelHeight
                }
                QGCLabel {
                    text:  _engineStatusText
                    color: ( _engineStatus === 3 ? "red" : ( _engineStatus === 2 ? "orange" : qgcPal.text ) )
                    width:  _labelWidth
                    height: _labelHeight
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }
    }
}

