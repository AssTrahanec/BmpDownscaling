#include <iostream>
#include "Converter.h"
#include "BitmapInfoHeader.h"

using namespace std;

void BitmapInfoHeader::parse(char* bytes) {
    bisize = Converter::getuint32(bytes, 14);
    width = Converter::getuint32(bytes, 18);
    height= Converter::getuint32(bytes, 22);
    planes = Converter::getuint16(bytes, 26);
    bitcount = Converter::getuint16(bytes, 28);
    compression = Converter::getuint32(bytes, 30);
    sizeimage = Converter::getuint32(bytes, 34);
    xpelspermeter = Converter::getuint32(bytes, 38);
    ypelspermeter = Converter::getuint32(bytes, 42);
    clrused = Converter::getuint32(bytes, 46);
    clrimportant = Converter::getuint32(bytes, 50);
}

char* BitmapInfoHeader::toBytes() {
    char* bytes = new char[40];
    Converter::setuint32(bisize, bytes, 0);
    Converter::setuint32(width, bytes, 4);
    Converter::setuint32(height, bytes, 8);
    Converter::setuint16(planes, bytes, 12);
    Converter::setuint16(bitcount, bytes, 14);
    Converter::setuint32(compression, bytes, 16);
    Converter::setuint32(sizeimage, bytes, 20);
    Converter::setuint32(xpelspermeter, bytes, 24);
    Converter::setuint32(ypelspermeter, bytes, 28);
    Converter::setuint32(clrused, bytes, 32);
    Converter::setuint32(clrimportant, bytes, 36);
    return bytes;
}
uint32_t BitmapInfoHeader::getHeight() {
    return height;
}
uint32_t BitmapInfoHeader::getWidth() {
    return width;
}

void BitmapInfoHeader::setWidth(uint32_t width)
{
    this->width = width;
}

void BitmapInfoHeader::setHeight(uint32_t height)
{
    this->height = height;
}

void BitmapInfoHeader::setSizeImage(uint32_t sizeimage)
{
    this->sizeimage = sizeimage;
}
