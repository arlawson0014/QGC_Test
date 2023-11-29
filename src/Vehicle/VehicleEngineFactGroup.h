#pragma once

#include <FactGroup.h>
#include "QGCMAVLink.h"

class Vehicle;

class VehicleEngineFactGroup : public FactGroup
{
    Q_OBJECT

    enum class engineHealthState{
        OFF = 0,
        ON = 1,
        HOT = 2,
        OVERHEATING = 3,
        ERROR = 4
    };

    enum class engineTemperatureUnits {
        CELSIUS = 0,
        FAHRENHEIT = 1
    };

public:
    VehicleEngineFactGroup(QObject *parent = nullptr);

    Q_PROPERTY(Fact health                    READ health                    CONSTANT)
    Q_PROPERTY(Fact ecuIndex                  READ ecuIndex                  CONSTANT)
    Q_PROPERTY(Fact rpm                       READ rpm                       CONSTANT)
    Q_PROPERTY(Fact fuelConsumed              READ fuelConsumed              CONSTANT)
    Q_PROPERTY(Fact fuelFlow                  READ fuelFlow                  CONSTANT)
    Q_PROPERTY(Fact engineLoad                READ engineLoad                CONSTANT)
    Q_PROPERTY(Fact throttlePosition          READ throttlePosition          CONSTANT)
    Q_PROPERTY(Fact sparkDwellTime            READ sparkDwellTime            CONSTANT)
    Q_PROPERTY(Fact baromatricPressure        READ baromatricPressure        CONSTANT)
    Q_PROPERTY(Fact intakeManifoldPressure    READ intakeManifoldPressure    CONSTANT)
    Q_PROPERTY(Fact intakeManifoldTemperature READ intakeManifoldTemperature CONSTANT)
    Q_PROPERTY(Fact cylinderHeadTemperature   READ cylinderHeadTemperature   CONSTANT)
    Q_PROPERTY(Fact ignitionTiming            READ ignitionTiming            CONSTANT)
    Q_PROPERTY(Fact injectionTiming           READ injectionTiming           CONSTANT)
    Q_PROPERTY(Fact exhaustGasTemperature     READ exhaustGasTemperature     CONSTANT)
    Q_PROPERTY(Fact throttleOut               READ throttleOut               CONSTANT)
    Q_PROPERTY(Fact ptCompensation            READ ptCompensation            CONSTANT)
    Q_PROPERTY(Fact ignitionVoltage           READ ignitionVoltage           CONSTANT)
    Q_PROPERTY(Fact fuelPressure              READ fuelPressure              CONSTANT)

    Q_PROPERTY(Fact temperatureUnits READ temperatureUnits CONSTANT)
    Q_PROPERTY(Fact statusText READ statusText CONSTANT)

    Fact health() const { return _healthFact; };
    Fact ecuIndex() const { return _ecuIndexFact; };
    Fact rpm() const { return _rpmFact; };
    Fact fuelConsumed() const { return _fuelConsumedFact; };
    Fact fuelFlow() const { return _fuelFlowFact; };
    Fact engineLoad() const { return _engineLoadFact; };
    Fact throttlePosition() const { return _throttlePositionFact; };
    Fact sparkDwellTime() const { return _sparkDwellTimeFact; };
    Fact baromatricPressure() const { return _sparkDwellTimeFact; };
    Fact intakeManifoldPressure() const { return _intakeManifoldPressureFact; };
    Fact intakeManifoldTemperature() const { return _intakeManifoldTemperatureFact; };
    Fact cylinderHeadTemperature() const { return _cylinderHeadTemperatureFact; };
    Fact ignitionTiming() const { return _ignitionTimingFact; };
    Fact injectionTiming() const { return _injectionTimingFact; };
    Fact exhaustGasTemperature() const { return _exhaustGasTemperatureFact; };
    Fact throttleOut() const { return _throttleOutFact; };
    Fact ptCompensation() const { return _ptCompensationFact; };
    Fact ignitionVoltage() const { return _ignitionVoltageFact; };
    Fact fuelPressure() const { return _fuelPressureFact; };

    Fact temperatureUnits() const;
    Fact statusText() const;

    static const char* _healthFactName;
    static const char* _ecuIndexFactName;
    static const char* _rpmFactName;
    static const char* _fuelConsumedFactName;
    static const char* _fuelFlowFactName;
    static const char* _engineLoadFactName;
    static const char* _throttlePositionFactName;
    static const char* _sparkDwellTimeFactName;
    static const char* _barometricPressureFactName;
    static const char* _intakeManifoldPressureFactName;
    static const char* _intakeManifoldTemperatureFactName;
    static const char* _cylinderHeadTemperatureFactName;
    static const char* _ignitionTimingFactName;
    static const char* _injectionTimingFactName;
    static const char* _exhaustGasTemperatureFactName;
    static const char* _throttleOutFactName;
    static const char* _ptCompensationFactName;
    static const char* _ignitionVoltageFactName;
    static const char* _fuelPressureFactName;

    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

signals:
    void efiStatusChanged();
    void temperatureUnitsChanged();

    void statusTextChanged();

private:
    Fact _healthFact;
    Fact _ecuIndexFact;
    Fact _rpmFact;
    Fact _fuelConsumedFact;
    Fact _fuelFlowFact;
    Fact _engineLoadFact;
    Fact _throttlePositionFact;
    Fact _sparkDwellTimeFact;
    Fact _baromatricPressureFact;
    Fact _intakeManifoldPressureFact;
    Fact _intakeManifoldTemperatureFact;
    Fact _cylinderHeadTemperatureFact;
    Fact _ignitionTimingFact;
    Fact _injectionTimingFact;
    Fact _exhaustGasTemperatureFact;
    Fact _throttleOutFact;
    Fact _ptCompensationFact;
    Fact _ignitionVoltageFact;
    Fact _fuelPressureFact;

    Fact _temperatureUnits;
    Fact _statusText;
};
