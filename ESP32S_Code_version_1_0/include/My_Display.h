#ifndef __MY_DISPLAY_H__
#define __MY_DISPLAY_H__

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

class ESP32S_Display {
private:
    Adafruit_SSD1306 display; 
public:
    ESP32S_Display(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT)
    {
        display = Adafruit_SSD1306(width, height, &Wire, -1);
    } 

    void _init_()
    { 
        if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // Address 0x3D for 128x64 
        { 
            Serial.println(F("SSD1306 allocation failed"));
            for(;;);
        }
    }

    void PrintText(String text){  
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        display.println(text);
        display.display(); 
    }
    
    void PrintText(String text, int color = WHITE, int size = 1, int posX = 0 , int posY = 0){
        display.clearDisplay();
        display.setTextSize(size);
        display.setTextColor(color);
        display.setCursor(posX, posY);
        display.println(text);
        display.display(); 
    }
};

#endif