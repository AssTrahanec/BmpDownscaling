#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
static class Converter {
public:
    static uint8_t getuint8(char* bytes, size_t pos);
    static uint16_t getuint16(char* bytes, size_t pos);
    static uint32_t getuint32(char* bytes, size_t pos);
    static void setuint8(uint8_t x, char* bytes, size_t pos);
    static void setuint16(uint16_t x, char* bytes, size_t pos);
    static void setuint32(uint32_t x, char* bytes, size_t pos);
};

#endif