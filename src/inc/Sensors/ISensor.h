#pragma once

#include <Arduino.h>

class ISensor
{
public:
    virtual void Initialize() = 0;

    virtual String GetData() = 0;

    virtual String GetName() = 0;
};