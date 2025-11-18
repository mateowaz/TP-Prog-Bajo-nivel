#ifndef estudiantes_H
#define estudiantes_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ESTUDIANTE_H
#define MAX_NOMBRE 30
#include <stdbool.h>

typedef enum
{
  tipo_int,
  tipo_string,
  tipo_Alumno,
  tipo_Materia,
  tipo_Resultado,
} tipoDato;

struct Nodo;

typedef struct Nodo
{
  void *dato;
  tipoDato tipo;
  struct Nodo *siguiente;
} Nodo;

typedef struct
{
  char nombre[MAX_NOMBRE];
  int edad;
  float promedio;
  int Legajo;
  int cantMaterias;
  int TotalNotas;
  struct Nodo *historialRendidas;
} Alumno;

typedef struct 
{
  char nombre[MAX_NOMBRE];
  int cantidadAlumnos;
  struct Nodo *alumnosInscritos;
  char correlativa_requerida[MAX_NOMBRE];
} Materia;

typedef struct {
    char nombreMateria[MAX_NOMBRE]; 
    int nota;                       
    int aprobada;                   
} ResultadoMateria;

#endif