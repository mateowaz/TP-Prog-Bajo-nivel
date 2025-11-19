#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 
#include "funciones.h"

void Test_AgregarAlumno(){
Nodo *Lista = NULL;
Alumno a;
strcpy(a.nombre, "Carlos");
a.edad = 10;
a.Legajo = 1;

Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);
//la lista no debe estar vacia, para eso el assert
assert(Lista != NULL);
Alumno *res = (Alumno *)Lista->dato;
assert(res->Legajo = a.Legajo);
assert(strcmp(res->nombre, "Carlos") == 0);

LiberarEspacioLista(Lista);
printf("Test de Agregar Alumno Pasado\n");
}

void Test_AgregarAlumno_EdadErronea(){
Nodo *Lista = NULL;
Alumno a;
strcpy(a.nombre, "Carlos2");
a.edad = 1220;
a.Legajo = 1;

void *datos = copiar_estudiante(a);
//datos == Null significa que fallo
assert(datos == NULL);
Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);
assert(Lista != NULL);

LiberarEspacioLista(Lista);
printf("Test Edad Erronea Pasado\n");
}



int main(){
printf("Empezando Los Test\n");
Test_AgregarAlumno();
Test_AgregarAlumno_EdadErronea();

printf("Todos los Test Pasados Correctamente");
return 0;
}