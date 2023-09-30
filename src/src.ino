#include "inc/LedDisplay.h"
#include "inc/Sensors/Co2Sensor.h"
#include "inc/Sensors/TemperatureSensor.h"

LedDisplay ledDisplay;
Co2Sensor co2Sensor;
TemperatureSensor temperatureSensor;

void setup()
{
  Serial.begin(9600);
  Serial.println("starting...");

  co2Sensor.Initialize();
  ledDisplay.Initialize();
  temperatureSensor.Initialize();

}

void loop()
{
  ledDisplay.Print(temperatureSensor.GetName() + " = " + temperatureSensor.GetData(), 0);
  ledDisplay.Print(co2Sensor.GetName() + " = " + co2Sensor.GetData(), 1);
  delay(3000);
}