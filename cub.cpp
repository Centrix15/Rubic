#include "Cub.h"

//конструктор с 1 аргументом
Cub::Cub(){
	int* width = new int;
	int* height = new int;
	
	*width = 3;
	*height = 3;
	
	int* kletki_cubs = new int [NumberStoron][*width][*height];
}
