#ifndef OLED_H
#define OLED_H

#include "i2c.h" // Include the I2C class

class Oled {

public:
    Oled(I2C& i2c); // Constructor that takes an I2C object as a parameter
    void init(); // Initialize the SSD1306 OLED screen
    void sendString(const char* str, uint8_t x, uint8_t y, uint8_t fontSize, uint8_t fontColor, uint8_t orientation) ;
    void clearScreen(); // Clear the OLED screen
    uint8_t getFontData(char c, uint8_t fontSize, uint8_t fontColor, uint8_t orientation) ;
    void setDisplayOptions(uint8_t fontSize, uint8_t fontColor, uint8_t orientation) ;
    void display(const char* str) ;
private:
    I2C& mI2c; // Reference to the I2C object
    uint8_t mFontSize;
    uint8_t mFontColor;
    uint8_t mOrientation;
    bool mDataChanged;
};

#endif // OLED_H
