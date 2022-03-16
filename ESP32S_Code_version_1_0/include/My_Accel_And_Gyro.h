#ifndef __MY_ACCEL_AND_GYRO_H__
#define __MY_ACCEL_AND_GYRO_H__

#include <Wire.h>
#include "MPU6050.h"

#define MPU6050_AO_HIGH 0x69
#define MPU6050_AO_LOW  0x68

class ESP32S_MPU6050
{
private:
    MPU6050 mpu; //Так как мы на напряжение будем вешать, ну если что можно и поменять
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
public:
    ESP32S_MPU6050(int i2c_adress = MPU6050_AO_LOW)
    {
        MPU6050 mpu1(i2c_adress);
        mpu = mpu1;
        mpu.initialize();
        ax = ay = az = gx = gy = gz = 0;
    }

    void PrintDataInSerial()
    {
        mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        Serial.print("1) Показание аксселерометра: ");
        Serial.println(ax);
        Serial.print("2) Показание аксселерометра: ");
        Serial.println(ay);
        Serial.print("3) Показание аксселерометра: ");
        Serial.println(az);
        Serial.print("4) Показание гироскопа: ");
        Serial.println(gx);
        Serial.print("5) Показание гироскопа: ");
        Serial.println(gy);
        Serial.print("6) Показание гироскопа: ");
        Serial.println(gz);
    }
};

#endif