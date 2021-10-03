#include <iostream>
#include "Converter.h"
#include "BitmapFileHeader.h"

using namespace std;

void BitmapFileHeader::parse(char* bytes) {
    bfType = Converter::getuint16(bytes, 0);
    bmpSize = Converter::getuint32(bytes, 2);
    reserved1 = Converter::getuint16(bytes, 6);
    reserved2 = Converter::getuint16(bytes, 8);
    offBits = Converter::getuint32(bytes, 10);
}

char* BitmapFileHeader::toBytes() {
    char* bytes = new char[14];
    Converter::setuint16(bfType, bytes, 0);
    Converter::setuint32(bmpSize, bytes, 2);
    Converter::setuint16(reserved1, bytes, 6);
    Converter::setuint16(reserved2, bytes, 8);
    Converter::setuint32(offBits, bytes, 10);
    return bytes;
}

void BitmapFileHeader::setbmpSize(uint32_t bmpSize)
{
    this->bmpSize = bmpSize;
}
