#ifndef funciones_H
#define funciones_H

#include "estudiantes.h"

void MostrarMenu();
void MostrarMenuMaterias();
void MostrarMenuEstudiantes();

// Lista
Nodo *ObtenerUltimo(Nodo *Head);
Nodo *agregar(void *dato, tipoDato tipo, Nodo *Head);
Nodo *Buscar(void *DatoBuscado, tipoDato TipoBuscado, Nodo *Head);
Nodo *eliminar(void *DatoBuscado, tipoDato TipoBuscado, Nodo *Head);
void ImprimirLista(Nodo *Head);
int LargoLista(Nodo *Head);
void LiberarEspacioLista(Nodo *Head);
void *copiar_int(int valor);
void *copiar_string(const char *str);
void *copiar_estudiante(Alumno est);
Nodo* CargarDatosIniciales(Nodo *Head);

// Estudiantes
Nodo *DarDeAlta(Nodo *Head);
void ListarEst(Nodo *Head);
Nodo *Modificar(Nodo *Head);
Nodo *EliminarEst(Nodo *Head);
Nodo *BuscarPorLegajo(Nodo *Head, int LegajoBusc);
Nodo* BuscarPorNombre(Nodo *Head, char *nombBuscado);
void BuscarPorEdad(Nodo *Head, int minEdad, int maxEdad);
Nodo *EliminarPorLegajoDeMateria(Nodo *Head, int LegajoBus);

// Materias
void *copiar_Materia(Materia m);
void *copiar_resultado(ResultadoMateria res);
Nodo *DarDeAltaMateria(Nodo *Head);
void ListarMat(Nodo *Head);
Nodo* ModificarMat(Nodo *Head);
Nodo* EliminarMat(Nodo *Head);
Nodo* BuscarMatPorNombre(Nodo *Head, char *nombBuscado);
Nodo* VerificarMateriaYaRendida(Nodo *Historial, const char *nombreBusc);
Nodo* VerificarMateriaCorrelativa(Nodo *Head, const char *nombreCorrelativa);
void AnotarseMateria(Nodo *Head);
Nodo *agregarResultadoMateria(Nodo *Head, ResultadoMateria res);
void RendirMateria(Nodo *Head);

#endif