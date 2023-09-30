#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "ISensor.h"
#include "../BoardConfig.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

class TemperatureSensor : public ISensor
{
public:
    virtual void Initialize() override
    {
        Serial.println("Init TemperatureSensor");
        sensors.begin();
    }

    virtual String GetData() override
    {
        sensors.requestTemperatures();
        float tempC = sensors.getTempCByIndex(0);

        if (tempC != DEVICE_DISCONNECTED_C)
        {
            return String(tempC);
        }
        else
        {
            return "XX";
        }
    }

    virtual String GetName() override
    {
        return "Temp";
    }
};
