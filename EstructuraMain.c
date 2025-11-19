#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#define MAX_NOMBRE 30


int main(){
  Nodo *Lista = NULL;
  int opcionPrincipal = 0;
  int opcionSubmenu = 0;
  int c;
  srand(time(NULL));
  
  printf("Cargando datos de prueba...\n");
    Lista = CargarDatosIniciales(Lista);


  do{
    MostrarMenu();
    if (scanf("%d", &opcionPrincipal) != 1) {
            opcionPrincipal = -1; // Inválida
        }
        while ((c = getchar()) != '\n' && c != EOF); 

        switch (opcionPrincipal) {

          case 1:
          do{
            MostrarMenuEstudiantes();
            if (scanf("%d", &opcionSubmenu) != 1) {
            // Limpiar buffer en caso de entrada no numérica
            while (getchar() != '\n');
            opcionSubmenu = -1; // Opción inválida
        } else {
            // Limpiar el caracter de nueva línea restante
            while (getchar() != '\n'); 
        }
        switch (opcionSubmenu){
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
            printf("Entrada maxima invalida.\n");
            break;
            }
            while (getchar() != '\n');
          if (minEdad > maxEdad) {
            printf("El rango minimo no puede ser mayor que el maximo.\n");
         break;
    }
            
         BuscarPorEdad(Lista, minEdad, maxEdad);
         break; 
         
        case 7:
           Lista = EliminarEst(Lista);             
        break;
                
        case 0:
            printf("\nVolviendo al Menú Principal...\n");
            break;
        
        default:
            printf("\nOpcion no valida. Intente de nuevo.\n");
            break;

        }

          }while (opcionSubmenu != 0);
                opcionSubmenu = 0; //reiniciar la opción del submenú
                break;

          case 2:
          do{
            MostrarMenuMaterias();
            
        if (scanf("%d", &opcionSubmenu) != 1) {
            // Limpiar buffer en caso de entrada no numérica
            while (getchar() != '\n');
            opcionSubmenu = -1; // Opción inválida
        } else {
            // Limpiar el caracter de nueva línea restante
            while (getchar() != '\n'); 
        }
        switch (opcionSubmenu)
        {
        case 1:
        Lista = DarDeAltaMateria(Lista);
        break;

        case 2: 
         printf("\nMaterias: \n ");
         ListarMat(Lista);
         break;

        case 3:
        char nombreBuscado[50];
        printf("Ingrese el Nombre de la Materia a buscar: ");
        scanf("%s", nombreBuscado);
        while (getchar() != '\n');

        Nodo *encontrado = BuscarMatPorNombre(Lista, nombreBuscado); 
        break;
        
        case 4:   
        Lista = EliminarMat(Lista);
        break;

        case 5:
        printf("\nIngrese materia para Modificar: \n");
        Lista = ModificarMat(Lista);
        break;
        
        case 6:
        AnotarseMateria(Lista);
        break;

        case 7:
        RendirMateria(Lista);
        break;

        case 8:
        VerAlumnosDeMat(Lista);
        break;
        
        case 0: 
            printf("\nVolviendo al Menu Principal...\n");
            break;

        default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
                break;
        } 
    
    } while (opcionSubmenu != 0);
    opcionSubmenu = 0;
    break;

}
}while (opcionPrincipal != 0);
  printf("Saliendo, Liberando memoria...\n");
  LiberarEspacioLista(Lista);
  return 0;
}

void MostrarMenu(){
    printf("\n=====================================\n");
    printf("       MENU PRINCIPAL       \n");
    printf("=====================================\n");
    printf("1. Mostrar Menu de Alumnos\n");
    printf("2. Mostrar Menu de Materias\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
}

void MostrarMenuMaterias(){
    printf("\n=====================================\n");
    printf("       GESTOR DE MATERIAS       \n");
    printf("=====================================\n");
    printf("1. Dar de Alta (Agregar nueva Materia)\n");
    printf("2. Listar todas las materias\n");
    printf("3. Buscar Materia por Nombre\n");
    printf("4. Eliminar Materia\n");
    printf("5. Modificar \n");
    printf("6. Anotarse a Materia\n");
    printf("7. Rendir Materia\n");
    printf("8. Ver Alumnos De Materia\n");
    printf("0. Volver\n");
    printf("Ingrese su opcion: ");
}

void MostrarMenuEstudiantes(){
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
    printf("0. Volver\n");
    printf("Ingrese su opcion: ");
}

