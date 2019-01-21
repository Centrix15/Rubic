//заголовочный файл elmsCube.h

#include <iostream>
using namespace std;

typedef unsigned short int usi;

//константы
const usi NumberFacesCube = 6;
const usi MaxNumberColoredFaces = 3;
//допускаются кубы >= 2x2x2

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
	usi* arrColor;// указатель на массив.раскраски куба
	usi* location;//определяет местопроложение 1ого элемента куба
	//0(front), 1(down), 2(right),
	//3(back), 4(left), 5(up), 6(not defined)
	
	elementCub(void);
	elementCub(usi* color);
	elementCub(elementCub& el);
	elementCub& operator = (elementCub& el);
	void SetLocation();
	void SetLocation(usi loc);
	usi GetLocation();
	~elementCub(void);
	friend ostream& operator<< (ostream& s, elementCub& e);
};


//определения методов класса elementCub
elementCub::elementCub(void){
	arrColor = new usi[NumberFacesCube];
	location = new usi;
	*location = 6;
	for (int i = 0;i < NumberFacesCube;i++){
		(*(arrColor + i)) = none;
	}
}

elementCub::elementCub(usi* color){
	arrColor = new usi[NumberFacesCube];
	location = new usi;
	*location = 6;
	for (int i = 0;i < NumberFacesCube;i++){
		*(arrColor + i) = *(color + i);
	}
}

elementCub::elementCub(elementCub& el){
	arrColor = new usi[NumberFacesCube];
	location = new usi;
	*location = *(el.location);
	for (int i = 0;i < NumberFacesCube;i++){
		*(arrColor + i) = *(el.arrColor + i);
	}
}

elementCub::~elementCub(void){
	delete [] location;
	delete [] arrColor;
}

elementCub& elementCub::operator = (elementCub& el){
	*location = *(el.location);
	for (int i = 0;i < NumberFacesCube;i++){
		*(arrColor + i) = *(el.arrColor + i);
	}
}

void elementCub::SetLocation(){
	//по умолчанию местоположение not defined
	*location = 4;
}

void elementCub::SetLocation(usi loc){
	*location = loc;
}

usi elementCub::GetLocation(){
	return *location;
}

ostream& operator<< (ostream& s, elementCub& e){
	s << *(e.arrColor) << endl;
	s << *(e.arrColor + 1) << ' ';
	s << *(e.arrColor + 2) << ' ';
	s << *(e.arrColor + 3) << ' ';
	s << *(e.arrColor + 4) << endl;
	s << *(e.arrColor + 5) << endl;
	s << "location: " << *(e.location) << endl;
	return s;	
}
