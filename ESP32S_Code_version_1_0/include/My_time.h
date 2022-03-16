#ifndef __MY_TIME_H__
#define __MY_TIME_H__

#include "RTClib.h"
#include <time.h>

class ESP32S_Time  
{
private:
    RTC_DS3231 rtc;

public: 
    void _init_()
    {

        if (! rtc.begin()) 
        {
            Serial.println("Couldn't find RTC");
            while (1);
        }

        if (rtc.lostPower()) 
            Serial.println("RTC lost power, lets set the time!");
    }

    // Return String of Time type of 
    // Thu, 16 Apr 2020 18:34:56

    String GetCurrentDateString()
    {
        String sbuff = " DD MMM (DDD) YYYY hh:mm:ss";
        const char* cbuff =  sbuff.c_str();

        DateTime now = rtc.now();
        String Time = String(now.toString((char*)cbuff));      
        return Time;
    }

    // Return String of Time type of 
    // 18:34:56

    String GetCurrentTimeString()
    {
        String sbuff = "hh:mm:ss";
        const char* cbuff =  sbuff.c_str();

        DateTime now = rtc.now();
        String Time = String(now.toString((char*)cbuff));      
        return Time;
    }

};

#endif