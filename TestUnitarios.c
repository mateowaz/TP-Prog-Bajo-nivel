#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "funciones.h"

void Test_AgregarAlumno()
{
    Nodo *Lista = NULL;
    Alumno a;
    strcpy(a.nombre, "Carlos");
    a.edad = 18;
    a.Legajo = 1;
    a.promedio = 0.0;
    a.cantMaterias = 0;
    a.TotalNotas = 0;
    a.historialRendidas = NULL;

    Lista = agregar(copiar_estudiante(a), tipo_Alumno, Lista);

    assert(Lista != NULL);
    Alumno *res = (Alumno *)Lista->dato;
    assert(res->Legajo == a.Legajo);
    assert(strcmp(res->nombre, "Carlos") == 0);

    LiberarEspacioLista(Lista);
    printf("Test de Agregar Alumno Pasado\n");
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

    assert(Lista == NULL);

    printf("Test Edad Erronea Pasado\n");
}

void Test_BuscarPorLegajo()
{
    Nodo *Lista = NULL;
    Alumno a1, a2;

    // // Crear a1
    strcpy(a1.nombre, "Ana");
    a1.edad = 20;
    a1.Legajo = 101;
    a1.promedio = 8.5;
    a1.cantMaterias = 0;
    a1.TotalNotas = 0;
    a1.historialRendidas = NULL;

    // // Crear a1
    strcpy(a2.nombre, "Beto");
    a2.edad = 21;
    a2.Legajo = 102;
    a2.promedio = 7.0;
    a2.cantMaterias = 0;
    a2.TotalNotas = 0;
    a2.historialRendidas = NULL;

    Lista = agregar(copiar_estudiante(a1), tipo_Alumno, Lista);
    Lista = agregar(copiar_estudiante(a2), tipo_Alumno, Lista);

    // Buscar existente
    Nodo *encontrado = BuscarPorLegajo(Lista, 101);
    assert(encontrado != NULL);
    Alumno *dato = (Alumno *)encontrado->dato;
    assert(dato->Legajo == 101);
    assert(strcmp(dato->nombre, "Ana") == 0);

    // Buscar no existente
    Nodo *noEncontrado = BuscarPorLegajo(Lista, 999);
    assert(noEncontrado == NULL);

    LiberarEspacioLista(Lista);
    printf("Test Buscar Por Legajo Pasado\n");
}

void Test_ObtenerUltimo()
{
    Nodo *Lista = NULL;
    Alumno a1, a2;

    // Crear a1
    strcpy(a1.nombre, "Ana");
    a1.edad = 20;
    a1.Legajo = 101;
    a1.promedio = 0;
    a1.cantMaterias = 0;
    a1.TotalNotas = 0;
    a1.historialRendidas = NULL;

    // Crear a2
    strcpy(a2.nombre, "Beto");
    a2.edad = 21;
    a2.Legajo = 102;
    a2.promedio = 0;
    a2.cantMaterias = 0;
    a2.TotalNotas = 0;
    a2.historialRendidas = NULL;

    // Agregar a1
    Lista = agregar(copiar_estudiante(a1), tipo_Alumno, Lista);
    Nodo *ultimo = ObtenerUltimo(Lista);
    assert(ultimo != NULL);
    assert(((Alumno *)ultimo->dato)->Legajo == 101);

    // Agregar a2
    Lista = agregar(copiar_estudiante(a2), tipo_Alumno, Lista);
    ultimo = ObtenerUltimo(Lista);
    assert(ultimo != NULL);
    assert(((Alumno *)ultimo->dato)->Legajo == 102);

    LiberarEspacioLista(Lista);
    printf("Test Obtener Ultimo Pasado\n");
}

int main()
{
    setbuf(stdout, NULL);

    printf("Empezando Los Test\n");
    Test_AgregarAlumno();
    Test_AgregarAlumno_EdadErronea();
    Test_BuscarPorLegajo();
    Test_ObtenerUltimo();

    printf("Todos los Test Pasados Correctamente\n");
    return 0;
}