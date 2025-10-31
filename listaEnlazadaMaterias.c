#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Nodo* ObtenerUltimo(Nodo *Head){

  Nodo *Indice = Head;
  if(Indice == NULL){
    return NULL;
  }
  //Mientras el siguiente sea distinto de Null, lo recorro hasta el final
  while (Indice->siguiente != NULL){
    Indice = Indice->siguiente;
  } 
  return Indice;
}

//Agregar un elemento
Nodo* agregar(void *dato, tipoDato tipo, Nodo *Head){

  Nodo *nuevoNodo = malloc(sizeof(Nodo));
   nuevoNodo -> dato = dato;
   nuevoNodo -> tipo = tipo;
   nuevoNodo -> siguiente = NULL;
  
  //Si el head es null lo pongo como nuevo head
   if (Head == NULL){
    Head = nuevoNodo;
  }else{ 
    //Si no, ir al final y enlazarlo
    Nodo *ultimonodo = ObtenerUltimo(Head);
    ultimonodo -> siguiente = nuevoNodo;

  }

  return Head;
}

//Obtener un elemento N
Nodo *Buscar(void *datoBuscado, tipoDato tipoBuscado, Nodo *Head){
  Nodo *Indice = Head;
    printf("Lista: [");
    
    while (Indice != NULL) {
        
        switch (Indice->tipo) {
            
            case tipo_int: // <<-- ¡USANDO MINÚSCULAS!
                // CORRECCIÓN CLAVE: Usar Indice->DATO y desreferenciar
                printf("%d", *((int*)Indice->dato)); 
                break;
            
            case tipo_string: // <<-- ¡USANDO MINÚSCULAS!
                // CORRECCIÓN CLAVE: Usar Indice->DATO
                printf("%s", (char*)Indice->dato);
                break;

            default: 
                // Esto solo debería ejecutarse si se inserta un tipo inválido.
                printf("Tipo Desconocido/Error"); 
                break;
        } 
        
        // Lógica de coma
        if (Indice->siguiente != NULL) {
            printf(", ");
        }
        
        Indice = Indice->siguiente;
    }
    
    printf("]\n");
}

//Eliminar elemento
Nodo* eliminar(void *datoBuscado, tipoDato tipoBuscado,Nodo *Head){
  Nodo *actual = Head;
  Nodo *anterior = NULL;

while (actual != NULL) {
        int encontrado = 0;
        // Solo compara si los tipos coinciden
        if (actual->tipo == tipoBuscado) {
            switch (tipoBuscado) {
                case tipo_int:
                    // Compara el entero almacenado con el entero buscado
                    if (*((int*)actual->dato) == *((int*)tipoBuscado)) {
                        encontrado = 1;
                    }
                    break;
                case tipo_string:
                    // Compara la cadena almacenada con la cadena buscada usando strcmp
                    if (strcmp((char*)actual->dato, (char*)tipoBuscado) == 0) {
                        encontrado = 1;
                    }
                    break;
            }
        }
        if (encontrado) {
            // 2. Encontrado: Reenlazar los nodos
            if (anterior == NULL) {
                Head = actual->siguiente; // Caso Head
            } else {
                anterior->siguiente = actual->siguiente;
            }
            
            free((void *)actual->dato);
            free(actual);
            
            return Head;
        }
        // Si no es el nodo buscado avanzamos
        anterior = actual;
        actual = actual->siguiente;
    }
    return Head; 
}

//Imprimir la lista
void ImprimirLista(Nodo *Head) {
    Nodo *Indice = Head;
    printf("---Inicio de la Lista---\n");
    
    while (Indice != NULL) {
        
        //Usa el campo 'tipo' para decidir la impresión
        switch (Indice->tipo) {
            
            case tipo_int: 
                
                printf("%d", *((int*)Indice->dato)); 
                break;
            
            case tipo_string:
                printf("%s", (char*)Indice->dato);
                break;

            case tipo_Alumno:
            Alumno *e = (Indice->dato);
            printf("Nombre: %s, Edad: %d, Promedio: %2f, Legajo: %d\n", e->nombre, e->edad, e->promedio, e->Legajo);
            break;

            default: 
                // Esto maneja el caso donde el tipo es inválido
                printf("(Tipo Desconocido)");
                break;
        } 
        
        Indice = Indice->siguiente;
    }
    printf("---Fin de la Lista---\n");
}

//Obtener el largo de la lista
int LargoLista(Nodo *Head){
  int sum = 0;
  Nodo *Indice = Head;
    while (Indice != NULL){
      sum++;
      Indice = Indice->siguiente;
    }
   
    return printf("El largo de la lista es: %d", sum);
  }

//Ayuda a crear una copia de un int para agregar  
void *copiar_int(int valor) {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = valor;
    }
    return (void*)ptr;
}

//Ayuda a crear una copia de un string para agregar
void *copiar_string(const char *str) {
  //strdup asigna memoria y copia la cadena
    return (void*)strdup(str);
}

void LiberarEspacioLista(Nodo *Head){   
    Nodo *Actual = Head;
    Nodo *Siguiente = NULL;

    while (Actual != NULL)
    {
    //avanzamos y liberamos el nodo actual
     Siguiente = Actual->siguiente;
     free(Actual);
     Actual = Siguiente;
    }
    
}

void *copiar_Materia(Materia m){
  Materia *nuevaMateria = malloc(sizeof(Materia));
  if(nuevaMateria == NULL){
    return NULL;
  }

  *nuevaMateria = m;
  return (void*)nuevaMateria;
}