#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Pixel.h"
#include <string>

using namespace std;

class Image{
private:
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    Pixel* palette;
    uint8_t** pixels = new uint8_t*[10005];
public:
    Image();
    void loadFromFile(string path); 
    void saveToFile(string path);
    ~Image();
    void downscale(size_t v,size_t h);
};

#endif
