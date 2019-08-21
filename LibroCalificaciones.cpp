#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>


LibroCalificaciones::LibroCalificaciones(){}


LibroCalificaciones::LibroCalificaciones(const std::string nombreCurso, int arreglocalificaciones[][EXAMENES]){

	setNombreCurso(nombreCurso);

	//copiar notas de arreglo

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {
		
			calificaciones[estudiante][examen] = arreglocalificaciones[estudiante][examen];
		
		}

	}



}

//Obtiene la nota minima
int LibroCalificaciones::obtenerNotaMinima() {

	int notaMinima = 100;

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {

			if (calificaciones[estudiante][examen] < notaMinima) {
			
				notaMinima = calificaciones[estudiante][examen];
			
			}
		}
	}

	return notaMinima;
}

//obtiene la nota maxima
int LibroCalificaciones::obtenerNotaMaxima() {

	int notaMaxima = 0;

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {
		for (int examen = 0; examen < EXAMENES; ++examen) {

			if (calificaciones[estudiante][examen] > notaMaxima) {

				notaMaxima = calificaciones[estudiante][examen];

			}
		}
	}
	
	return notaMaxima;

}

//Obtiene el promedio
double LibroCalificaciones::obtenerPromedio(const int estudiante, const int examen){

	float pro = 0;

	float sum = 0;

	for (int exam = 0; exam < examen; exam++) {

		sum = sum + calificaciones[estudiante][examen];
	}

	pro = sum / 3;

	return pro;
}

//Da el reporte de notas
std::string LibroCalificaciones::obtenerReporteNotas() {

	std::string rpnt = "\nLas siguientes son las notas del curso [Curso Progra I]: \n\t\t\t\tExamen 1\tExamen 2\tExamen 3\tPromedio\n";

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {


		rpnt = rpnt + "Estudiante [" + std::to_string(estudiante) + "] \t\t ["
			+ std::to_string(calificaciones[estudiante][0]) + "]\t\t ["
			+ std::to_string(calificaciones[estudiante][1]) + "] \t\t [" 
			+ std::to_string(calificaciones[estudiante][2]) + "] \t\t ["
			+ std::to_string(obtenerPromedio(estudiante, 3)) + "] \t\t";

	}

	return rpnt;
}


std::string LibroCalificaciones::obtenerReporteNotasMaxMin() {

	std::string rpt = "";

	rpt = "La nota minima es:[" + std::to_string(obtenerNotaMinima()) + "] \n  ";
	rpt += "La nota maxima es:[" + std::to_string(obtenerNotaMaxima()) + "] \n ";

	return rpt;
}

//Metodos Set y Get
std::string LibroCalificaciones::getNombreCurso() {

	return nombreCurso;
}

void LibroCalificaciones::setNombreCurso(){

	LibroCalificaciones nombreCurso = nombreCurso;

}
