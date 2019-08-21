#ifndef CALIFICACIONES_LIBROCALIFIACIONES_H
#define CALIFICACIONES_LIBROCALIFICACIONES_h

#include <string>

//Matriz
static const int ESTUDIANTES = 10;
static const int EXAMENES = 3;

class LibroCalificaciones {

	//Atributos de la clase
	std::string nombreCurso;
	int calificaciones[ESTUDIANTES][EXAMENES];

	//Metodos privados
	int obtenerNotaMinima();
	int obtenerNotaMaxima();

	double obtenerPromedio(const int estudiante, const int examen);

	

public:
	//constructores con y sin parametros 

	LibroCalificaciones();

	LibroCalificaciones(const std::string& nombreCurso, int arreglocalificaciones[][EXAMENES]);
	
	LibroCalificaciones(const std::string nombreCurso,int calificaciones[][EXAMENES]);


	//Metodos publicos
	std::string obtenerReporteNotas();
	std::string obtenerReporteNotasMaxMin();


	//Metodos set y get
	std::string getNombreCurso();

	void setNombreCurso();


};

#endif