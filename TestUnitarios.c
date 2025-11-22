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

LiberarEspacioLista(Lista);
}

void Test_AgregarAlumno_EdadErronea()
{
    Nodo *Lista = NULL;
    Alumno a;
    strcpy(a.nombre, "Carlos2");
    a.edad = 1220; // Edad inválida
    a.Legajo = 1;
    void *datos = copiar_estudiante(a);
    assert(datos == NULL);
    
//datos == Null significa que fallo
assert(datos == NULL);
Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);
assert(Lista != NULL);
printf("Test Edad Erronea Pasado\n");
LiberarEspacioLista(Lista);
}

void Test_BuscarAlumnoPorLegajo(){
  Nodo *Lista = NULL;
  Alumno a;
strcpy(a.nombre, "Carlos3");
a.edad = 20;
a.Legajo = 150;
Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);

Nodo *Busc = BuscarPorLegajo(Lista, 150);

assert(Busc != NULL);
Alumno *dato = (Alumno*)Busc->dato;
assert(dato->Legajo == 150);
assert(Lista != NULL);
printf("Test Buscar Por Legajo Pasado\n");
LiberarEspacioLista(Lista);
}

void Test_BuscarAlumnoPorLegajoError(){
    Nodo *Lista = NULL;
  Alumno a;
strcpy(a.nombre, "Carlos4");
a.edad = 20;
a.Legajo = 90;
Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);

Nodo *NoBusc = BuscarPorLegajo(Lista, 150);

assert(NoBusc == NULL);
printf("Test Buscar Por Legajo Erroneo Pasado\n");
LiberarEspacioLista(Lista);
}

int main(){
printf("Empezando Los Test\n");
Test_AgregarAlumno();
printf("Test de Agregar Alumno Pasado\n");
Test_AgregarAlumno_EdadErronea();
Test_BuscarAlumnoPorLegajo();
Test_BuscarAlumnoPorLegajoError();

printf("\nTodos los Test Pasados Correctamente");
return 0;
}