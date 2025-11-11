#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 50

int main(){

Nodo *Lista = NULL; 
Materia m1 = {"Algebra", 10};
Lista = agregar(copiar_Materia(m1) ,tipo_Materia, Lista);
Materia m2 = {"ED", 25};
Lista = agregar(copiar_Materia(m2) ,tipo_Materia, Lista);
Materia m3 = {"Ppp", 30};
Lista = agregar(copiar_Materia(m3) ,tipo_Materia, Lista);
printf("Materias: \n ");
ListarMat(Lista);

printf("Ingrese materia \n");
Lista = DarDeAltaMateria(Lista);
printf("Materias: \n ");
ListarMat(Lista);

char nombreBuscado[50]; 
printf("Ingrese el Nombre de la Materia a buscar: ");
scanf("%s", nombreBuscado); 
while (getchar() != '\n'); 

Nodo *encontrado = BuscarMatPorNombre(Lista, nombreBuscado);   

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
  
  if(nuevoNodo == NULL){
      return Head;
  }

  //Si el head es null lo pongo como nuevo head
   if (Head == NULL){
    return nuevoNodo;
  }
    //Si no, ir al final y enlazarlo
    Nodo *ultimonodo = ObtenerUltimo(Head);
    if (ultimonodo != NULL) {
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

Nodo* DarDeAltaMateria(Nodo *Head){
  Materia NuevaMateria;
  printf("Porfavor ingrese los datos de la nueva Materia: \n");
  printf("Nombre: ");
  //%29s es el limite de caracteres para escribir el nombre de la materia
  scanf("%29s", NuevaMateria.nombre);

  NuevaMateria.cantidadAlumnos = 0;

  void *datos = copiar_Materia(NuevaMateria);

  if(datos == NULL){
    printf("Error al generar Materia");
    return Head;
  }
  Head = agregar(datos, tipo_Materia, Head);
  printf("Materia %s agregada exitosamente!", NuevaMateria.nombre);
  return Head;

}

void ListarMat(Nodo *Head){
  Nodo *Actual = Head;
   printf("--- Inicio de la Lista ---\n");

  while (Actual != NULL){
    Materia *m = (Materia *)Actual->dato;
    printf("Nombre: %s, Cant. Alumnos: %d \n", m->nombre, m->cantidadAlumnos );
    Actual =  Actual->siguiente;
  }
     printf("--- Fin de la Lista ---\n");

  }


Nodo* BuscarMatPorNombre(Nodo *Head, char *nombBuscado){
  Nodo *Actual = Head;
 while (Actual != NULL) {
  
        if(Actual->tipo == tipo_Materia){ 
            Materia *m = (Materia *)Actual->dato;
          
            if(strcmp(m->nombre, nombBuscado) == 0){
               
                printf("Materia %s encontrado.\n", m->nombre);
                printf("- Datos de la Materia - \n");
                printf("Nombre: %s, Alumnos: %d \n", m->nombre, m->cantidadAlumnos);
                return Actual; // Retorna el nodo encontrado
            }
        }
        Actual = Actual->siguiente; 
    } 
    printf("Materia no encontrada \n");
    return NULL;
}


/*
void AnotarseMateria(Nodo *Head){
   Nodo *nodomateria = NULL;
   Nodo *nodoalumno = NULL;
   char NombreMatBuscado[Max_nombre];
   char NombreAlumBuscado[Max_nombre];

   printf("\n--- Inscripción a Materia ---\n");
   printf("Ingrese Primero el Nombre del Alumno: ");
   //fgets ayuda a que no hayan errores de lectura
   if(fgets(NombreAlumBuscado, MAX_NOMBRE, stdin) != NULL){ //satdin indica que la lectura se hará desde el teclado
    //se obtiene la longitud actual de la cadena
    size_t lenAl = strlen(NombreAlumBuscado); 
  //con esto vamos a comprobar si la cadena no está vacía y tambien si el último carácter es un salto de línea
  if (lenAl > 0 && NombreAlumBuscado[lenAl - 1] == '\n') {
    //se corta el salto de linea al final
    NombreAlumBuscado[lenAl - 1] = '\0'; 
}
   }else{
    printf("Error en la lectura");
    return;
   }
   //buscamos por el nombre que ingresamos
   nodoalumno = BuscarPorNombre(Head, NombreAlumBuscado);
   if(nodoalumno == NULL){
    printf("Error al buscar Alumno %s", NombreAlumBuscado);
    return;
   }  

   printf("Alumno %s Encontrado Exitosamente \n", NombreAlumBuscado);
   printf("Ingrese el Nombre de la Materia: ");

   if(fgets(NombreMatBuscado, MAX_NOMBRE, stdin) != NULL){
    size_t lenMat = strlen(NombreMatBuscado);
    if(lenMat > 0 && NombreMatBuscado[lenMat - 1] == '\n'){
      NombreMatBuscado[lenMat - 1] =  '\0';
    }
   }else{
    printf("Error en la lectura");
    return;
   }

   nodomateria = BuscarMatPorNombre(Head, NombreMatBuscado);
   if(nodomateria == NULL){
    printf("Error al buscar Materia %s", NombreMatBuscado);
    return;
   }
   printf("Materia %s Encontrado Exitosamente \n", NombreMatBuscado);
  
  //inicializamos la materia y alumnos
  Materia *m = (Materia *)nodomateria->dato;
  Alumno *a = (Alumno *)nodoalumno->dato;
  //aumentamos la cantidad de alumnos de la materia
  m->cantidadAlumnos++;  

printf("\nAlumno %s (Legajo: %d) inscrito exitosamente a la materia '%s'.\n", 
           a->nombre, a->Legajo, m->nombre);
printf("Ahora la materia %s tiene %d alumnos.\n", m->nombre, m->cantidadAlumnos);
}
*/