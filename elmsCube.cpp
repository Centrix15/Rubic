#include "elmsCube.h"
#include <iostream>
using namespace std;

//вывод elementCub, используя потоки
friend ostream& operator<< (ostream& s, elementCub& e){
	s << '\t' << e.arrElm << endl;
	s << '\t' << e.arrElm << endl;
	s << e.arrElm << "  ";
	s << e.arrElm << "  ";
	s << e.arrElm << endl;
	s << '\t' << e.arrElm << endl;
	return e;	
}
