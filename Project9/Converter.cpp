#include <iostream>
#include "Converter.h"

uint8_t Converter::getuint8(char* bytes, size_t pos) {
    return uint32_t((unsigned char)(bytes[pos]));
}
uint16_t Converter::getuint16(char* bytes, size_t pos) {
    return uint32_t((unsigned char)(bytes[pos]) | (unsigned char)(bytes[pos + 1]) << 8);
}
uint32_t Converter::getuint32(char* bytes, size_t pos) {
    return uint32_t ((unsigned char)(bytes[pos]) | (unsigned char)(bytes[pos + 1]) << 8 | (unsigned char)(bytes[pos + 2]) << 16 | (unsigned char)(bytes[pos + 3]) << 24);
}

void Converter::setuint8(uint8_t x, char* bytes, size_t pos) {
    bytes[pos] = x;
}
void Converter::setuint16(uint16_t x, char* bytes, size_t pos) {
    bytes[pos] = x;
    bytes[pos + 1] = x >> 8;
}
void Converter::setuint32(uint32_t x, char* bytes, size_t pos) {
    bytes[pos] = x;
    bytes[pos + 1] = x >> 8;
    bytes[pos + 2] = x >> 16;
    bytes[pos + 3] = x >> 24;
}