#ifndef CUB_H
#define CUB_H

#include <iostream>
using namespace std;

typedef unsigned short int usi;


//константы для класса Cub
const int NumberStoron = 6; //количество сторон
const int MaxWidthCub = 20;
const int MinWidthCub = 1;

//цвета раскраски
enum Color{	
	white,
	blue,
	red,
	yellow,
	orange,
	green,
	invisible,//расположен внутри куба
	none//без цвета
};


//класс куб Cub
class Cub{
public:
	usi* Width;//размер куба
	usi* arrColor;/*массив расцветки куба
		 ||
		 ||
		\||/
		 \/
	0  1  2
	3  4  5 <--фронтальная сторона
	6  7  8
	
	9  10 11		18 19 20		27 28 29		36 37 38
	12 13 14		21 22 23		30 31 32		39 40 41
	15 16 17		24 25 26		33 34 35		42 43 44
	
	45 46 47
	48 49 50
	51 52 53
	*/
	
public:
	Cub();
	usi Size();
	void SetStor(usi stor, usi color);
	friend ostream& operator << (ostream& o, Cub& c);
};

//конструкторы класса Cub
Cub::Cub(){
	Width = new usi; *Width = 3;
	arrColor = new usi[Size()];
	for (int i = 0;i < NumberStoron;i++){
		SetStor(i,i);
	}
}


//деструктор класса Cub


//методы класса Cub
usi Cub::Size(){
	return 6*(*Width)*(*Width);
}

void Cub::SetStor(usi stor, usi color){
	usi s_osn = Size()/6;
	usi nachalPos = stor * s_osn;
	for (int i = stor * s_osn;i < (stor + 1)*s_osn;i++){
		*(arrColor + i) = color;
	}
}

ostream& operator << (ostream& o, Cub& c){
	int Sosn = c.Size() / 6;
	for (int j = 0;j < *(c.Width);j++){
		for (int k = 0;k < *(c.Width);k++){
			o << *(c.arrColor + j * (*(c.Width)) + k);
			if (k == (*(c.Width)) - 1){
				o << endl;
			} else {
				o << ' ';
			}
		}
	}
	o << endl;
		
	for (int u = 0;u < *(c.Width);u++){
		for (int j = 0;j < 4;j++){
			for (int k = 0;k < *(c.Width);k++){
				o << *(c.arrColor + (j + 1) * Sosn + u * (*(c.Width)) + k);
				if (k == (*(c.Width)) - 1){
					cout << "    ";
				} else {
					cout << ' ';
				}
			}
		}
		o << endl;
	}
	o << endl;
	
	for (int j = 0;j < *(c.Width);j++){
		for (int k = 0;k < *(c.Width);k++){
			o << *(c.arrColor + j * (*(c.Width)) + k + 5 * Sosn);
			if (k == (*(c.Width)) - 1){
				o << endl;
			} else {
				o << ' ';
			}
		}
	}
	return o;
}

#endif
