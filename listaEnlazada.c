#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
   Nodo *Lista = NULL;
   int opcion = 0;

   Alumno e1 = {"Martin", 10, 4.4, 777};
   Alumno e2 = {"Manuel", 15, 6.8 , 8}; 
   Alumno e3 = {"Steban", 16, 8.2, 4};
    
   Lista = agregar(copiar_estudiante(e1), tipo_Alumno, Lista);
   printf("\n");
   Lista = agregar(copiar_estudiante(e2), tipo_Alumno, Lista);
    printf("\n");
   Lista = agregar(copiar_estudiante(e3), tipo_Alumno, Lista);

   printf("Lista actual:\n");
    ListarEst(Lista);

    do{
        MostrarMenu();

        if (scanf("%d", &opcion) != 1) {
            // Limpiar buffer en caso de entrada no numérica
            while (getchar() != '\n');
            opcion = -1; // Opción inválida
        } else {
            // Limpiar el caracter de nueva línea restante
            while (getchar() != '\n'); 
        }

        switch (opcion)
        {
        case 1:
            Lista = DarDeAlta(Lista);
            break;
        case 2: 
            Lista = Modificar(Lista);
            break;
        case 3:
            ListarEst(Lista);
            break;
        case 4:
            LargoLista(Lista);
            break;

        case 5: 
            char nombreBuscado[50]; //Maximo de la entrada

            printf("Ingrese el Nombre del Alumno a buscar: ");
            scanf("%s", nombreBuscado); // Lee el nombre ingresado por el usuario
            while (getchar() != '\n'); // Limpiar el buffer

            //llamada a la funcion
            Nodo *encontrado = BuscarPorNombre(Lista, nombreBuscado);

            // Manejar el resultado de la búsqueda si es necesario
            if (encontrado != NULL) {
            // Ya se imprimió la información en BuscarPorNombre
                        }
            break;
        
        case 6:
          int minEdad;
          int maxEdad;
          printf("Ingrese el rango de edad de los Alumnos a buscar: \n");
          printf("Ingrese el rango minimo: \n");
          if (scanf("%d", &maxEdad) != 1) {
          while (getchar() != '\n');
            printf("Entrada minima invalida.\n");
            break;
            }
          while (getchar() != '\n');
          printf("Ingrese el rango maximo: \n");
          if (scanf("%d", &maxEdad) != 1) {
          while (getchar() != '\n');
            printf("Entrada máxima invalida.\n");
            break;
            }
            while (getchar() != '\n');
          if (minEdad > maxEdad) {
            printf("El rango mínimo no puede ser mayor que el máximo.\n");
         break;
    }
            
         BuscarPorEdad(Lista, minEdad, maxEdad);
         break; 
         
        case 7:
           Lista = EliminarEst(Lista);             
        break;
                
        case 0:
            printf("\nSaliendo del programa. Liberando memoria...\n");
            break;
        
        default:
            printf("\nOpción no válida. Intente de nuevo.\n");
            break;
        }
    }
    while (opcion != 0);

   //Liberación de Memoria al salir 
    LiberarEspacioLista(Lista); 
    
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

void MostrarMenu(){
    printf("\n=====================================\n");
    printf("       GESTOR DE ALUMNOS       \n");
    printf("=====================================\n");
    printf("1. Dar de Alta (Agregar nuevo alumno)\n");
    printf("2. Modificar alumno por Legajo\n");
    printf("3. Listar todos los alumnos\n");
    printf("4. Mostrar largo de la lista\n");
    printf("5. Buscar Alumno por Nombre\n");
    printf("6. Buscar Alumnos por Edad\n");
    printf("7. Eliminar Alumno\n");
    printf("0. Salir\n");
    printf("Ingrese su opción: ");
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
  //scanf siempre necesita la dirección de memoria
  if (scanf("%d", &NuevoAlumno.edad) != 1) {
    printf("Edad inválida.\n");
    while (getchar() != '\n');
            };
  printf("Legajo: \n");
  scanf("%d", &NuevoAlumno.Legajo);

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
        if(scanf("%d", &LegajoBuscado) != 1){
            //eliminar cualquier carácter restante 
            while (getchar() != '\n');
            printf("Error Alumno no encontrado \n");
            return Head;
        }
   while (indice != NULL) {
    if (indice->tipo == tipo_Alumno) {
        Alumno *alum = (Alumno *)indice->dato;

        if (alum->Legajo == LegajoBuscado) {
            printf("Alumno %s encontrado.\n", alum->nombre);

            printf("Ingrese nuevo nombre: ");
            if(scanf("%s", alum->nombre) != 1){
                while (getchar() != '\n');
                printf("Nombre invalido.\n");
            }
                
            printf("Ingrese nueva edad: ");
            if (scanf("%d", &alum->edad) != 1) {
                printf("Edad inválida.\n");
                while (getchar() != '\n');
            }

            printf("\nDatos modificados con éxito.\n");
            printf("Nuevo nombre: %s\n", alum->nombre);
            printf("Nueva edad: %d\n", alum->edad);
            return Head;
        }
    }
    indice = indice->siguiente;
}
    //devolvemos error si no fue encontrado
     printf("\n Alumno no encontrado, Legajo: %d no encontrado \n ", LegajoBuscado);
     return Head;
}


Nodo* BuscarPorNombre(Nodo *Head, char *nombBuscado){
    Nodo *indice = Head;
    printf("Ingrese el Nombre del Alumno: ");
    while (indice != NULL){
        if(indice->tipo == tipo_Alumno){
            Alumno *alum = (Alumno *)indice->dato;

        if (strcmp(alum->nombre, nombBuscado) == 0){
            printf("Alumno %s encontrado.\n", alum->nombre);
            printf("- Datos de Alumno - \n");
            printf("Nombre: %s, Edad: %d, Promedio: %f, Legajo: %d ", alum->nombre, alum->edad, alum->promedio, alum->Legajo);
           return indice; 
        }
    }
    indice = indice->siguiente;
}
printf("Alumno no encontrado");
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

Nodo* EliminarEst(Nodo *Head) {
    Nodo *actual = Head;
    Nodo *previo = NULL;
    int LegajoBuscado;

    // Verificamos si la lista está vacía
    if (Head == NULL) {
        printf("Lista vacía. No hay alumnos para eliminar.\n");
        return Head;
    }

    printf("Ingrese el Legajo del Alumno: ");
    if (scanf("%d", &LegajoBuscado) != 1) {
        // Eliminar cualquier carácter restante
        while (getchar() != '\n');
        printf("Entrada inválida. Intente de nuevo.\n");
        return Head;
    }
    while (getchar() != '\n'); // limpiar buffer

    // Recorremos la lista
    while (actual != NULL) {
        if (actual->tipo == tipo_Alumno) {
            Alumno *e = (Alumno *)actual->dato;

            if (e->Legajo == LegajoBuscado) {
                // Encontrado → eliminamos el nodo
                if (previo == NULL) {
                    // Caso: el nodo a eliminar es el primero
                    Head = actual->siguiente;
                } else {
                    // Caso: nodo intermedio o final
                    previo->siguiente = actual->siguiente;
                }
                

                free(actual->dato);     // liberar el dato (Alumno)
                free(actual);    // liberar el nodo
                printf("Alumno con legajo %d eliminado correctamente.\n", LegajoBuscado);
                return Head;
            }
        }

        // Avanzamos en la lista
        previo = actual;
        actual = actual->siguiente;
    }

    // Si llegamos aquí, no se encontró el alumno
    printf("No se encontró ningún alumno con el legajo %d.\n", LegajoBuscado);
    return Head;
}


