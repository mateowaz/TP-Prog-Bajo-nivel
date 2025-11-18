#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void AnotarseMateria(Nodo *Head);
Nodo *agregarResultadoMateria(Nodo *Head, ResultadoMateria res);
void RendirMateria(Nodo *Head);


