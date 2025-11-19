#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h> 

#define MAX_NOMBRE 30


typedef enum {
    tipo_int,
    tipo_string,
    tipo_Alumno,
    tipo_Materia,
    tipo_Resultado
} tipoDato;


struct Nodo; 

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    int Legajo;
    int cantMaterias;
    int TotalNotas;
    struct Nodo *historialRendidas;
} Alumno;

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidadAlumnos;
    struct Nodo *alumnosInscritos;
    bool Aprobada;
    char correlativa_requerida[MAX_NOMBRE];
} Materia;

typedef struct {
    char nombreMateria[MAX_NOMBRE];
    int nota;
    int aprobada;
} ResultadoMateria;

typedef struct Nodo {
    void *dato;
    tipoDato tipo;
    struct Nodo *siguiente;
} Nodo;

#endif