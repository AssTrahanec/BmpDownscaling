#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <iostream>
#include "Converter.h"

class BitmapFileHeader {
private:
    uint16_t bfType = 0x4D42;
    uint32_t bmpSize;
    uint16_t reserved1 = 0;
    uint16_t reserved2 = 0;
    uint32_t offBits;
public:
    void parse(char* bytes);
    char* toBytes();
    void setbmpSize(uint32_t bmpSize);
};

#endif