#include <Arduino.h>
#include <MHZ19_uart.h>
#include "ISensor.h"
#include "../BoardConfig.h"

MHZ19_uart mhz19;

class Co2Sensor : public ISensor
{
public:
    virtual void Initialize() override
    {
        Serial.println("Init Co2Sensor");

        mhz19.begin(MHZ_TX, MHZ_RX);
        mhz19.setAutoCalibration(false);
        mhz19.getStatus();    // первый запрос, в любом случае возвращает -1
        delay(500);
        if (mhz19.getStatus() == 0) 
        {
            Serial.println(F("OK"));
        }
        else 
        {
            Serial.println(F("ERROR"));
        }
    }

    virtual String GetData() override
    {
        int PpmCo2 = mhz19.getPPM();
        return String(PpmCo2);
    }

    virtual String GetName() override
    {
        return "CO2";
    }
};
