#include "VehicleEngineFactGroup.h"
#include "QGCApplication.h"

const char* VehicleEngineFactGroup::_healthFactName = "health";
const char* VehicleEngineFactGroup::_ecuIndexFactName = "ecuIndex";
const char* VehicleEngineFactGroup::_rpmFactName = "rpm";
const char* VehicleEngineFactGroup::_fuelConsumedFactName = "fuelConsumed";
const char* VehicleEngineFactGroup::_fuelFlowFactName = "fuelFlow";
const char* VehicleEngineFactGroup::_engineLoadFactName = "engineLoad";
const char* VehicleEngineFactGroup::_throttlePositionFactName = "throttlePosition";
const char* VehicleEngineFactGroup::_sparkDwellTimeFactName = "sparkDwellTime";
const char* VehicleEngineFactGroup::_barometricPressureFactName = "barometricPressure";
const char* VehicleEngineFactGroup::_intakeManifoldPressureFactName = "intakeManifoldPressure";
const char* VehicleEngineFactGroup::_intakeManifoldTemperatureFactName = "intakeManifoldTemperature";
const char* VehicleEngineFactGroup::_cylinderHeadTemperatureFactName = "cylinderHeadTemperature";
const char* VehicleEngineFactGroup::_ignitionTimingFactName = "ignitionTiming";
const char* VehicleEngineFactGroup::_injectionTimingFactName = "injectionTiming";
const char* VehicleEngineFactGroup::_exhaustGasTemperatureFactName = "exhaustGasTemperature";
const char* VehicleEngineFactGroup::_throttleOutFactName = "throttleOut";
const char* VehicleEngineFactGroup::_ptCompensationFactName = "ptCompensation";
const char* VehicleEngineFactGroup::_ignitionVoltageFactName = "ignitionVoltage";
const char* VehicleEngineFactGroup::_fuelPressureFactName = "fuelPressure";

VehicleEngineFactGroup::VehicleEngineFactGroup(QObject *parent)
    : FactGroup{1000, ":json/Vehicle/EngineFact.json", parent}
    , _healthFact                   (0, _healthFactName, FactMetaData::valueTypeUint8)
    , _ecuIndexFact                 (0, _ecuIndexFactName, FactMetaData::valueTypeFloat)
    , _rpmFact                      (0, _rpmFactName, FactMetaData::valueTypeFloat)
    , _fuelConsumedFact             (0, _fuelConsumedFactName, FactMetaData::valueTypeFloat)
    , _fuelFlowFact                 (0, _fuelFlowFactName, FactMetaData::valueTypeFloat)
    , _engineLoadFact               (0, _engineLoadFactName, FactMetaData::valueTypeFloat)
    , _throttlePositionFact         (0, _throttlePositionFactName, FactMetaData::valueTypeFloat)
    , _sparkDwellTimeFact           (0, _sparkDwellTimeFactName, FactMetaData::valueTypeFloat)
    , _baromatricPressureFact       (0, _barometricPressureFactName, FactMetaData::valueTypeFloat)
    , _intakeManifoldPressureFact   (0, _intakeManifoldPressureFactName, FactMetaData::valueTypeFloat)
    , _intakeManifoldTemperatureFact(0, _intakeManifoldTemperatureFactName, FactMetaData::valueTypeFloat)
    , _cylinderHeadTemperatureFact  (0, _cylinderHeadTemperatureFactName, FactMetaData::valueTypeFloat)
    , _ignitionTimingFact           (0, _ignitionTimingFactName, FactMetaData::valueTypeFloat)
    , _injectionTimingFact          (0, _injectionTimingFactName, FactMetaData::valueTypeFloat)
    , _exhaustGasTemperatureFact    (0, _exhaustGasTemperatureFactName, FactMetaData::valueTypeFloat)
    , _throttleOutFact              (0, _throttleOutFactName, FactMetaData::valueTypeFloat)
    , _ptCompensationFact           (0, _ptCompensationFactName, FactMetaData::valueTypeFloat)
    , _ignitionVoltageFact          (0, _ignitionVoltageFactName, FactMetaData::valueTypeFloat)
    , _fuelPressureFact             (0, _fuelPressureFactName, FactMetaData::valueTypeFloat)
    , _temperatureUnits             (new Fact(this))
{
    _addFact(&_healthFact,                    _healthFactName);
    _addFact(&_ecuIndexFact,                  _ecuIndexFactName);
    _addFact(&_rpmFact,                       _rpmFactName);
    _addFact(&_fuelConsumedFact,              _fuelConsumedFactName);
    _addFact(&_fuelFlowFact,                  _fuelFlowFactName);
    _addFact(&_engineLoadFact,                _engineLoadFactName);
    _addFact(&_throttlePositionFact,          _throttlePositionFactName);
    _addFact(&_sparkDwellTimeFact,            _sparkDwellTimeFactName);
    _addFact(&_baromatricPressureFact,        _barometricPressureFactName);
    _addFact(&_intakeManifoldPressureFact,    _intakeManifoldPressureFactName);
    _addFact(&_intakeManifoldTemperatureFact, _intakeManifoldTemperatureFactName);
    _addFact(&_cylinderHeadTemperatureFact,   _cylinderHeadTemperatureFactName);
    _addFact(&_ignitionTimingFact,            _ignitionTimingFactName);
    _addFact(&_injectionTimingFact,           _injectionTimingFactName);
    _addFact(&_exhaustGasTemperatureFact,     _exhaustGasTemperatureFactName);
    _addFact(&_throttleOutFact,               _throttleOutFactName);
    _addFact(&_ptCompensationFact,            _ptCompensationFactName);
    _addFact(&_ignitionVoltageFact,           _ignitionVoltageFactName);
    _addFact(&_fuelPressureFact,              _fuelPressureFactName);

    _healthFact.setRawValue((uint8_t)engineHealthState::OFF);
    _ecuIndexFact.setRawValue(qQNaN());
    _rpmFact.setRawValue(qQNaN());
    _fuelConsumedFact.setRawValue(qQNaN());
    _fuelFlowFact.setRawValue(qQNaN());
    _engineLoadFact.setRawValue(qQNaN());
    _throttlePositionFact.setRawValue(qQNaN());
    _sparkDwellTimeFact.setRawValue(qQNaN());
    _baromatricPressureFact.setRawValue(qQNaN());
    _intakeManifoldPressureFact.setRawValue(qQNaN());
    _intakeManifoldTemperatureFact.setRawValue(qQNaN());
    _cylinderHeadTemperatureFact.setRawValue(qQNaN());
    _ignitionTimingFact.setRawValue(qQNaN());
    _injectionTimingFact.setRawValue(qQNaN());
    _exhaustGasTemperatureFact.setRawValue(qQNaN());
    _throttleOutFact.setRawValue(qQNaN());
    _ptCompensationFact.setRawValue(qQNaN());
    _ignitionVoltageFact.setRawValue(qQNaN());
    _fuelPressureFact.setRawValue(qQNaN());
    _temperatureUnits.setRawValue(int(engineTemperatureUnits::FAHRENHEIT));

    _healthFact.setRawValue(2);
    _rpmFact.setRawValue(1200);
    _throttlePositionFact.setRawValue(75);
    _cylinderHeadTemperatureFact.setRawValue(80);
}

void VehicleEngineFactGroup::handleMessage(Vehicle *vehicle, mavlink_message_t &message)
{
    if( message.msgid == MAVLINK_MSG_ID_EFI_STATUS ) {
        mavlink_efi_status_t efiStatus;
        mavlink_msg_efi_status_decode(&message, &efiStatus);

        _healthFact.setRawValue(efiStatus.health);
        _ecuIndexFact.setRawValue(efiStatus.ecu_index);
        _rpmFact.setRawValue(efiStatus.rpm);
        _fuelConsumedFact.setRawValue(efiStatus.fuel_consumed);
        _fuelFlowFact.setRawValue(efiStatus.fuel_flow);
        _engineLoadFact.setRawValue(efiStatus.engine_load);
        _throttlePositionFact.setRawValue(efiStatus.throttle_position);
        _sparkDwellTimeFact.setRawValue(efiStatus.spark_dwell_time);
        _baromatricPressureFact.setRawValue(efiStatus.barometric_pressure);
        _intakeManifoldPressureFact.setRawValue(efiStatus.intake_manifold_pressure);
        _intakeManifoldTemperatureFact.setRawValue(efiStatus.intake_manifold_temperature);
        _cylinderHeadTemperatureFact.setRawValue(efiStatus.cylinder_head_temperature);
        _ignitionTimingFact.setRawValue(efiStatus.ignition_timing);
        _injectionTimingFact.setRawValue(efiStatus.injection_time);
        _exhaustGasTemperatureFact.setRawValue(efiStatus.exhaust_gas_temperature);
        _throttleOutFact.setRawValue(efiStatus.throttle_out);
        _ptCompensationFact.setRawValue(efiStatus.pt_compensation);

        // Not implemented in mavlink struct
        // _ignitionVoltageFact.setRawValue(efiStatus.ignition_voltage);
        // _fuelPressureFact.setRawValue(efiStatus.fuel_pressure);

        switch( efiStatus.health ) {
        case (int)engineHealthState::OFF:
            _statusText.setRawValue("OFF");
            break;
        case (int)engineHealthState::ON:
            _statusText.setRawValue("ON");
            break;
        case (int)engineHealthState::HOT:
            _statusText.setRawValue("HOT");
            break;
        case (int)engineHealthState::OVERHEATING:
            _statusText.setRawValue("OVERHEATING");
            break;
        case (int)engineHealthState::ERROR:
            _statusText.setRawValue("ERROR");
            break;
        default:
            break;
        }

        emit efiStatusChanged();
    }
}

Fact VehicleEngineFactGroup::statusText() const
{
    return _statusText;
}

Fact VehicleEngineFactGroup::temperatureUnits() const
{
    return _temperatureUnits;
}
