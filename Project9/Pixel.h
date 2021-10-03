#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
class Pixel {
private:
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;
    size_t palettePosition;
public:
    Pixel(size_t palettePosition);
    void parse(char* byte);
    char* toBytes();
};

#endif
