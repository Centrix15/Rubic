#ifndef CUB_H
#define CUB_H

#include <iostream>


//константы для класса Cub
const int NumberStoron = 6; //количество сторон
const int MaxWidthCub = 20;
const int MaxHeightCub = 20;
const int MinWidthCub = 2;
const int MinHeightCub = 2;
enum colorCub{white, green, red, blue, orange, yellow};


//класс куб
class Cub{
public:
	int* kletki_cubs[MaxWidthCub][MaxHeightCub];
	int* width;
	int* height;
public:
	Cub();
};
#endif
