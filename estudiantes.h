#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESTUDIANTE_H
#define Max_nombre 30

typedef enum{
  tipo_int,
  tipo_string,
  tipo_Alumno,
  tipo_Materia,
}tipoDato;

typedef struct{
char nombre[Max_nombre];
int edad;
float promedio;
int Legajo;
}Alumno;

typedef struct{ 
char nombre[Max_nombre];
}Materia;

typedef struct Nodo {
    void *dato;
    tipoDato tipo;
    struct Nodo *siguiente; 
    Alumno datos; 
} Nodo;



Nodo* ObtenerUltimo(Nodo *Head);
Nodo* agregar(void *dato, tipoDato tipo, Nodo *Head);
Nodo *Buscar(void *DatoBuscado, tipoDato TipoBuscado, Nodo *Head);
Nodo* eliminar(void *DatoBuscado, tipoDato TipoBuscado, Nodo *Head);
void ImprimirLista(Nodo *Head);
int LargoLista(Nodo *Head);
void *copiar_int (int valor);
void *copiar_string(const char *str);
void *copiar_estudiante(Alumno est);

Nodo* DarDeAlta(Nodo *Head);
void ListarEst(Nodo *Head);
void modificarEst();
Nodo* EliminarEst(Nodo *Head, int legajoBuscado);
Nodo* BuscarPorNombre(Nodo *Head, char *nombBuscado);
void BuscarPorEdad(Nodo *Head, int minEdad, int maxEdad);