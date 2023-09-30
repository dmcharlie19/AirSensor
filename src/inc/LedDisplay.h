// #include <GyverOLED.h>
// GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

// class LedDisplay
// {
// public:
//     void Initialize()
//     {
//         oled.init();
//         oled.clear();
//         oled.setScale(2);
//         oled.home();
//         oled.print("starting...");
//         delay(200);
//     }

//     void Print(String data)
//     {
//         oled.clear();
//         oled.home();
//         oled.print(data);
//     }
// };

#include "OLED_I2C.h"

OLED myOLED(SDA, SCL);
extern uint8_t SmallFont[];

class LedDisplay
{
public:
    void Initialize()
    {
        bool res = myOLED.begin(SSD1306_128X64);
        if (!res)
        {
            Serial.print("LedDisplay init failed");
        }

        myOLED.setFont(SmallFont);
    }

    void Print(String data, int line)
    {
        myOLED.print(data, LEFT, line*10);
        myOLED.update();
        delay(2000);
    }
};
