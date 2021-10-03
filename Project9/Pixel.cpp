#include "Pixel.h"
#include "Converter.h"

Pixel::Pixel(size_t palettePosition) {
    this->palettePosition = palettePosition;
}
void Pixel::parse(char* bytes) {
    blue = Converter::getuint8(bytes, palettePosition * 4 + 54);
    green = Converter::getuint8(bytes, palettePosition * 4 + 1 + 54);
    red = Converter::getuint8(bytes, palettePosition * 4 + 2 + 54);
    reserved = Converter::getuint8(bytes, palettePosition * 4 + 3 + 54);
}
char* Pixel::toBytes() {
    char* bytes = new char[4];
    Converter::setuint8(blue, bytes, 0);
    Converter::setuint8(green, bytes, 1);
    Converter::setuint8(red, bytes, 2);
    Converter::setuint8(reserved, bytes, 3);
    return bytes;
}
