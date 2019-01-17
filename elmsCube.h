//заголовочный файл elmsCube.h
#ifndef ELMSCUBE_H
#define ELMSCUBE_H

#include <iostream>
using namespace std;

typedef unsigned short int usi;

//константы
const usi NumberFacesCube = 6;
const usi MaxNumberColoredFaces = 3;//допускаются кубы >= 2x2x2

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

//элемент(деталь) куба
class elementCub{
public:
	//количество закрашенных цветов
	//определяет тип детали(угловая, ребёрная, граневая, внутренняя)
	usi* number_colored_faces;
	usi* arrElm;// указатель на массив.раскраски куба
	
	elementCub(void);
	
	friend ostream& operator<< (ostream& s, elementCub& e);
};

elementCub::elementCub(void){
	//по умолчанию угловая деталь
	number_colored_faces = new usi(3);
	arrElm = new usi[NumberFacesCube];
	for (int i = 0;i < NumberFacesCube;i++){
		(*(arrElm + i)) = none;
	}
}

#endif ELMSCUBE_H
