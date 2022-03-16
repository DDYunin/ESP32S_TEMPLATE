#include <Arduino.h>
#include <Wire.h>
#include <BluetoothSerial.h>
#include <Check_tire_of_I2c.h>
#include <My_Accel_And_Gyro.h>
#include <My_Display.h>
#include <My_time.h>

#define SDA_1 21
#define SCL_1 22

BluetoothSerial SerialBT;
ESP32S_Display dsp;

MPU6050 mpu(0x69); //Так как мы на напряжение будем вешать, ну если что можно и поменять
int16_t ax, ay, az;
int16_t gx, gy, gz;

ESP32S_Time clock1;

void CHECK_I2C_ID_BL();
void CHECK_MPU6050();

void setup() {
  Wire.begin();
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
 
  mpu.initialize();
}

void loop() {
  CHECK_I2C_ID_BL();
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  CHECK_MPU6050();
  delay(1000);
}

void CHECK_I2C_ID_BL(){
  
  byte error, address; //variable for error and I2C address
  int nDevices;

  SerialBT.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      SerialBT.print("I2C device found at address 0x");
      if (address < 16)
        SerialBT.print("0");
      SerialBT.print(address, HEX);
      SerialBT.println("  !");
      nDevices++;
    }
    else if (error == 4)
    {
      SerialBT.print("Unknown error at address 0x");
      if (address < 16)
        SerialBT.print("0");
      SerialBT.println(address, HEX);
    }
  }
  if (nDevices == 0)
    SerialBT.println("No I2C devices found\n");
  else
    SerialBT.println("done\n");
}

void CHECK_MPU6050()
{
  SerialBT.print("1) Показание аксселерометра: ");
  SerialBT.println(ax);
  SerialBT.print("2) Показание аксселерометра: ");
  SerialBT.println(ay);
  SerialBT.print("3) Показание аксселерометра: ");
  SerialBT.println(az);
  SerialBT.print("4) Показание гироскопа: ");
  SerialBT.println(gx);
  SerialBT.print("5) Показание гироскопа: ");
  SerialBT.println(gy);
  SerialBT.print("6) Показание гироскопа: ");
  SerialBT.println(gz);
}