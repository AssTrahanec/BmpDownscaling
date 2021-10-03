#include "Image.h"
#include <fstream>
Image::Image() {
    palette = (Pixel*)malloc(sizeof(Pixel) * 256);
    for (size_t i = 0; i < 256; i++) {
        palette[i] = Pixel(i);
    }
    for (size_t i = 0; i < 10005; i++) {
        pixels[i] = new uint8_t[10005];
    }
}
Image::~Image() {
    delete[] palette;
    for (size_t i = 0; i < 10005; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
}
void Image::loadFromFile(string path) {
    std::ifstream infile(path, std::ios_base::binary);
    char *buffer = new char[11000 * 10000];
    infile.seekg(0, infile.end);
    int length = infile.tellg();
    infile.seekg(0, infile.beg);
    infile.read(buffer, length);
    infile.close();
    
    fileHeader.parse(buffer);
    infoHeader.parse(buffer);
    for (size_t i = 0; i < 256; i++) {
        palette[i].parse(buffer);
    }
    size_t rowSize = infoHeader.getWidth() + (4 - infoHeader.getWidth() % 4);
    for (size_t i = 0; i < infoHeader.getHeight(); i++) {
        for (size_t j = 0; j < rowSize; j++) {
            pixels[i][j] = Converter::getuint8(buffer, 54 + 256 * 4 + i * rowSize + j);
        }
    }
    delete[] buffer;
}
void Image::saveToFile(string path) {
    size_t rowSize = infoHeader.getWidth() + (4 - infoHeader.getWidth() % 4);
    char* buffer = new char[54 + 256 * 4 + rowSize * infoHeader.getHeight()];
    char* fhb = fileHeader.toBytes();
    char* ihb = infoHeader.toBytes();
    for (size_t i = 0; i < 14; i++) {
        buffer[i] = fhb[i];
    }
    for (size_t i = 14; i < 54; i++) {
        buffer[i] = ihb[i - 14];
    }
    for (size_t i = 0; i < 256; i++) {
        char* palettebuffer = palette[i].toBytes();
        for (size_t j = 0; j < 4; j++) {
            buffer[54 + i * 4 + j] = palettebuffer[j];
        }
        delete[] palettebuffer;
    }
    for (size_t i = 0; i < infoHeader.getHeight(); i++) {
        for (size_t j = 0; j < rowSize; j++) {
            buffer[54 + 256 * 4 + i * rowSize + j] = pixels[i][j];
        }
    }
    ofstream fout(path,ofstream::binary);
    fout.write(buffer, 54 + 256 * 4 + rowSize * infoHeader.getHeight());
    fout.close();
    delete[] buffer;
    delete[] fhb;
    delete[] ihb;
}
void Image::downscale(size_t v, size_t h) {
    if (infoHeader.getHeight() % v != 0 || infoHeader.getWidth() % h != 0)
        return;
    uint32_t height = infoHeader.getHeight() / v;
    uint32_t width = infoHeader.getWidth() / h;
    size_t rowSize = width + ((4 - width % 4)) % 4;
    uint8_t** newpixels = new uint8_t*[10005];
    for (size_t i = 0; i < 10005; i++) {
        newpixels[i] = new uint8_t[10005];
    }
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < rowSize; j++) {
            if(j >= width){
                newpixels[i][j] = 0;
            }
            else
            newpixels[i][j] = pixels[i*v][j*h];
        }
    }
    infoHeader.setHeight(height);
    infoHeader.setWidth(width);
    infoHeader.setSizeImage(height * rowSize);
    fileHeader.setbmpSize(54 + 256 * 4 + height * rowSize);
    for (size_t i = 0; i < 10005; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
    pixels = newpixels;
}