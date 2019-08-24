#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>

//llamado de los constructores
LibroCalificaciones::LibroCalificaciones(){
	
}


LibroCalificaciones::LibroCalificaciones(const std::string& nombreCurso, int arreglocalificaciones[][EXAMENES]){

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
double LibroCalificaciones::obtenerPromedio(const int estudiante, const int){
	
	double sum = 0;

	for (int exam = 0; exam < EXAMENES; exam++) {

		sum += calificaciones[estudiante][exam];
		
	}
	
	return sum / EXAMENES;
}

//Da el reporte de notas
std::string LibroCalificaciones::obtenerReporteNotas() {

	std::string rpnt = "\nLas siguientes son las notas del curso [Curso Progra I]: \n\t\t\tExamen1 \tExamen2 \tExamen3 \tPromedio\n";

	for (int estudiante = 0; estudiante < ESTUDIANTES; ++estudiante) {


		rpnt = rpnt + "\nEstudiante[" + std::to_string(estudiante+1) + "]\t\t" + std::to_string(calificaciones[estudiante][0]) + "\t\t"
			+ std::to_string(calificaciones[estudiante][1]) + "\t\t" + std::to_string(calificaciones[estudiante][2]) + "\t\t"
			+ std::to_string(obtenerPromedio(estudiante,3)) + "\t\t";

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
const std::string LibroCalificaciones::getNombreCurso() {

	return nombreCurso;
}

void LibroCalificaciones::setNombreCurso( const std::string& nombreCurso){

	 LibroCalificaciones::nombreCurso = nombreCurso;

}
