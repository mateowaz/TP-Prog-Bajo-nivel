#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
   Nodo *Lista = NULL;

   Alumno e1;
   strcpy(e1.nombre, "Martin");
   e1.edad = 10;
   e1.Legajo = 124124;
   e1.promedio = 7.7;

   Alumno e2;
   strcpy(e2.nombre, "Jose");
   e2.edad = 20;
   e2.Legajo = 52131;
   e2.promedio = 4.5;

   Alumno e3;
   strcpy(e3.nombre, "Steban");
   e3.edad = 25;
   e3.Legajo = 52231;
   e3.promedio = 8.5;

   Lista = agregar(copiar_estudiante(e1), tipo_Alumno, Lista);
   printf("\n");
   Lista = agregar(copiar_estudiante(e2), tipo_Alumno, Lista);
    printf("\n");
   Lista = agregar(copiar_estudiante(e3), tipo_Alumno, Lista);

 
  
   printf("Lista actual:\n");
    ListarEst(Lista);

  Lista = DarDeAlta(Lista);

   int largo = LargoLista(Lista);
   printf("el largo es: %d \n" ,largo);

  printf("Lista actual:\n");
    ListarEst(Lista);

   Lista = EliminarEst(Lista, 52231);
   Lista = BuscarPorNombre(Lista, "Jose");
   
   printf("La lista es: \n");
   ListarEst(Lista);

 

   return 0;
} 


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
    return sum;
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

void *copiar_estudiante(Alumno est){
  Alumno *nuevoAlumno = malloc(sizeof(Alumno));
  if(nuevoAlumno == NULL){
    return NULL;
  }

  *nuevoAlumno = est;
  return (void*)nuevoAlumno;
}

//Da la lista con todos los estudiantes, separado por comas
void ListarEst(Nodo *Head){
    Nodo *Indice = Head;
    printf("--- Inicio de la Lista ---\n");

    while(Indice != NULL){
        //obtenemos los datos de todos los alumnos
        Alumno *e = (Alumno *)Indice->dato;   
        printf("Nombre: %s, Edad: %d, Promedio: %.2f, Legajo: %d\n", 
               e->nombre, e->edad, e->promedio, e->Legajo); 
        Indice = Indice->siguiente;    
    }
    
    printf("--- Fin de la Lista ---\n");
}

//damos de alta a un alumno asignandole sus valores
Nodo* DarDeAlta(Nodo *Head){
  Alumno NuevoAlumno;
  
  printf("Porfavor ingrese sus datos: \n");
  printf("Nombre: \n");
  scanf("%s", NuevoAlumno.nombre);
  printf("Edad: \n");
  scanf("%d", NuevoAlumno.edad);
  printf("Legajo: \n");
  scanf("%d", NuevoAlumno.Legajo);

  void *DatosCopiados = copiar_estudiante(NuevoAlumno);
  if(DatosCopiados == NULL){
    printf("Error al agregar Alumno");
    return Head;
  }
  
  Head = agregar(DatosCopiados,tipo_Alumno, Head);
  printf("Estudiante %s (%d) Agregado Exitosamente \n", NuevoAlumno.nombre, NuevoAlumno.Legajo);

  return Head;

}

//Buscamos un alumno por legajo y lo modificamos
Nodo* Modificar(Nodo *Head){
    Nodo *indice = Head;
    int LegajoBuscado;

    //si esta vacia devuelve el head
    if(Head == NULL){
         printf("Lista vacia \n");
         return Head;
    }


    printf("Ingrese el Legajo del Alumno: ");
        if(scanf(" %d", &LegajoBuscado) != 1){
            //eliminar cualquier carácter restante 
            while (getchar() != '\n');
            printf("Error Alumno no encontrado \n");
            return Head;
        }
    while (indice != NULL){
      if(indice->datos.Legajo == LegajoBuscado){
        printf("Alumno %s encontrado, porfavor cambie los datos: \n", indice->datos.nombre);
        printf("Ingrese nuevo nombre: \n");
        scanf("%s", indice->datos.nombre);
        printf("Ingrese nueva edad: \n");
        scanf("%d", indice->datos.edad);
        //si el dato no es un entero, se rompe
        if(scanf("%d", &indice->datos.edad !=1)){
            printf("Edad invalida");

        }

        printf("\n Datos de Alumno (Legajo: %d) modificados con Exito! \n ", indice->datos.Legajo);
        printf("Nuevo nombre: %s  \n", indice->datos.nombre);
        printf("Nueva edad: %d  \n", indice->datos.edad);
        return Head;
        
      }
      indice = indice->siguiente;
    }
    //devolvemos error si no fue encontrado
     printf("\n Alumno no encontrado, Legajo: %d no encontrado \n ", indice->datos.Legajo);
     return Head
}

Nodo* BuscarPorNombre(Nodo *Head, char *nombBuscado){
    Nodo *indice = Head;
    
    while (indice != NULL){
        
        if(indice->tipo == tipo_Alumno){
            Alumno *e = (Alumno *)indice->dato;
            //strcmp devuelve 0 si las cadenas son iguales.
            if (strcmp(e->nombre, nombBuscado) == 0){
                
                printf("Alumno: %s\n", e->nombre);
                return indice; 
            }
        }
        indice = indice->siguiente;
    }
    return NULL;
}

void BuscarPorEdad(Nodo *Head, int minEdad, int maxEdad) {
    
    Nodo *indice = Head;
    int contador = 0; 
    
    while (indice != NULL) {
        
     
        if (indice->tipo == tipo_Alumno) {
            Alumno *e = (Alumno *)indice->dato;
            if (e->edad >= minEdad && e->edad <= maxEdad) {
                printf("Los alumnos son: \n");
                printf("Nombre: %s, Edad: %d, Legajo: %d\n", 
                       e->nombre, e->edad, e->Legajo);
                contador++;
            }
        }
        
        indice = indice->siguiente;
    }
    if (contador == 0) {
        printf("No se encontraron alumnos en ese rango de edad.\n");
    }
    printf("--- Fin de la Busqueda (Total: %d) ---\n", contador);
}

Nodo* EliminarEst(Nodo *Head, int legajoBuscado) {
    Nodo *actual = Head;
    Nodo *previo = NULL;

    while (actual != NULL) {
        
        int encontrado = 0;
        if (actual->tipo == tipo_Alumno) {
            Alumno *e = (Alumno *)actual->dato; 
            if (e->Legajo == legajoBuscado) {
                encontrado = 1;
            }
        }
        
        if (encontrado) {
            if (previo == NULL) {
                Head = actual->siguiente;
            } else {
                previo->siguiente = actual->siguiente;
            }
            
            free((void *)actual->dato);
            free(actual);
            
            return Head; 
        }
        
        previo = actual;
        actual = actual->siguiente;
      }
    return Head;
}


