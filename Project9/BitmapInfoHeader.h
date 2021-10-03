#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include <iostream>
#include "Converter.h"

class BitmapInfoHeader {
private:
    uint32_t bisize = 40;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bitcount;
    uint32_t compression = 0;
    uint32_t sizeimage;
    uint32_t xpelspermeter = 0;
    uint32_t ypelspermeter = 0;
    uint32_t clrused;
    uint32_t clrimportant;
public:
    void parse(char* bytes);
    char* toBytes();
    uint32_t getHeight();
    uint32_t getWidth();
    void setWidth(uint32_t width);
    void setHeight(uint32_t height);
    void setSizeImage(uint32_t sizeimage);
};

#endif