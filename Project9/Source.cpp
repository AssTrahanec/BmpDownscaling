
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include "Pixel.h"
#include "Image.h"
#include <fstream>
int main() 
{
    {Image a;
    a.loadFromFile("original.bmp");
    a.saveToFile("copy.bmp");
    a.downscale(2, 2);
    a.saveToFile("downscale.bmp");
    }
    system("pause");
}