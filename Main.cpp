#include "LibroCalificaciones.h"
#include <iostream>

int main() {

	
	static const int ESTUDIANTES = 10;
	static const int EXAMENES = 3;
	
	//llena de valores la matriz
	int calificaciones[ESTUDIANTES][EXAMENES] = {
		{87, 96, 70}, {68, 87, 90}, {94, 100, 90}, {100, 81, 82}, {83, 65, 85},
		{78, 87, 65}, {85, 75, 83}, {91, 94, 100}, {76, 72, 84},  {87, 93, 73}
	};

	//muestra por pantalla las notas y el promedio 
	LibroCalificaciones libroCalificaciones("Curso Progra I", calificaciones);

	std::cout<< libroCalificaciones.obtenerReporteNotas() << std::endl;
	std::cout << libroCalificaciones.obtenerReporteNotasMaxMin() << std::endl;


	return 0;
}