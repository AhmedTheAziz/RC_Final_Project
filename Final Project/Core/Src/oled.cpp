#include "oled.h"
#include "font.h" // Include the fonts header file (assuming you have one)

Oled::Oled(I2C& i2c) : mI2c(i2c), mDataChanged(true) {}

void Oled::init() {
    // Initialize the SSD1306 OLED screen
    mI2c.I2C_INIT(); // Initialize the I2C bus

    // Send the initialization sequence to the SSD1306
    mI2c.I2C_Transmit(0xAE); // Display off
    mI2c.I2C_Transmit(0xD5); // Set display clock divide ratio/oscillator frequency
    mI2c.I2C_Transmit(0x80); // Set display clock divide ratio/oscillator frequency
    mI2c.I2C_Transmit(0xA8); // Set multiplex ratio
    mI2c.I2C_Transmit(0x3F); // Set multiplex ratio
    mI2c.I2C_Transmit(0xD3); // Set display offset
    mI2c.I2C_Transmit(0x00); // Set display offset
    mI2c.I2C_Transmit(0x40); // Set start line
    mI2c.I2C_Transmit(0xA1); // Set segment re-map
    mI2c.I2C_Transmit(0xC8); // Set COM output scan direction
    mI2c.I2C_Transmit(0xDA); // Set COM pins hardware configuration
    mI2c.I2C_Transmit(0x12); // Set COM pins hardware configuration
    mI2c.I2C_Transmit(0x81); // Set contrast control
    mI2c.I2C_Transmit(0xCF); // Set contrast control
    mI2c.I2C_Transmit(0xA4); // Set entire display on
    mI2c.I2C_Transmit(0xA6); // Set inverse display
    mI2c.I2C_Transmit(0xAF); // Display on
}

void Oled::sendString(const char* str, uint8_t x, uint8_t y, uint8_t fontSize, uint8_t fontColor, uint8_t orientation) {
    // Send the string to the OLED screen at (x, y) coordinates
    uint8_t cursorX = x;
    uint8_t cursorY = y;

    while (*str != '\0') {
        char c = *str++;
        if (c == '\n') {
            cursorX = x;
            cursorY += 8; // Move to the next line
        } else {
            // Send the character to the OLED screen
            mI2c.I2C_Transmit(0x00); // Command mode
            mI2c.I2C_Transmit(0xB0 | cursorY); // Set page address
            mI2c.I2C_Transmit(0x00 | cursorX); // Set column address
            mI2c.I2C_Transmit(0x00); // Command mode
            mI2c.I2C_Transmit(getFontData(c, fontSize, fontColor, orientation)); // Send the character data
            cursorX += 6; // Move to the next character position
        }
    }
}

void Oled::clearScreen() {
    // Clear the OLED screen
    mI2c.I2C_Transmit(0x00); // Command mode
    mI2c.I2C_Transmit(0xB0); // Set page address
    mI2c.I2C_Transmit(0x00); // Set column address
    mI2c.I2C_Transmit(0x00); // Command mode
    for (uint8_t i = 0; i < 128 * 8; i++) {
        mI2c.I2C_Transmit(0x00); // Send zeros to clear the screen
    }
}

void Oled::setDisplayOptions(uint8_t fontSize, uint8_t fontColor, uint8_t orientation) {
    mFontSize = fontSize;
    mFontColor = fontColor;
    mOrientation = orientation;
}

void Oled::display(const char* str) {
    clearScreen();
    sendString(str, 0, 0, mFontSize, mFontColor, mOrientation);
   // mI2C.I2C_Transmit();
}

uint8_t Oled::getFontData(char c, uint8_t fontSize, uint8_t fontColor, uint8_t orientation) {
    // Return the font data for the character c, taking into account fontSize, fontColor, and orientation
    // You'll need to implement the logic to retrieve the correct font data based on these parameters
    return fontData[c - ' ']; // This is just a placeholder, you'll need to update this implementation
}
