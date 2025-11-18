#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NOMBRE 30


void VerAlumnosDeMat(Nodo *Head); 
void AnotarseMateria(Nodo *Head);
Nodo *ObtenerUltimo(Nodo *Head);
Nodo *BuscarPorLegajo(Nodo *Head, int LegajoBusc);
Nodo* BuscarPorNombre(Nodo *Head, char *nombBuscado);

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
            printf("\nVolviendo al Menú Principal...\n");
            break;
        
        default:
            printf("\nOpción no válida. Intente de nuevo.\n");
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
            printf("\nVolviendo al Menú Principal...\n");
            break;

        default:
                printf("\nOpción no válida. Intente de nuevo.\n");
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
    printf("Ingrese su opción: ");
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
    printf("0. Salir\n");
    printf("Ingrese su opción: ");
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
    printf("0. Salir\n");
    printf("Ingrese su opción: ");
}

Nodo* CargarDatosIniciales(Nodo *Head) {
    const char *nombres_base[] = {"Algebra", "Fisica", "Quimica", "Historia", "Literatura", "Algoritmos", "Redes", "BaseDeDatos", "Ingles", "Taller", "Calculo", "Probabilidad", "Sistemas", "Arquitectura", "IA", "Prog Bajo Nivel", "Diseño Logico", "Arquitectura"};
    const char *apellidos_alumnos[] = {"Gomez", "Lopez", "Perez", "Rodriguez", "Sanchez", "Martinez", "Fernandez", "Garcia", "Silva", "Nuñez" };
    const char *nombres_alumnos[] = {"Ana", "Luis", "Carlos", "Sofia", "Diego", "Maria", "Elena", "Pedro", "Julio", "Laura", "Mateo", "Valentina", "Elias", "Brenda", "Simon", "Mateo", "Fede"};
    
    int i;
    int legajoActual = 100; //Legajos desde 100
    
    //generacion de materias
    printf("\n--- Generando 20 Materias ---\n");
    for (i = 0; i < 20; i++) {
        Materia m;
        //creamos un nombre único 
        snprintf(m.nombre, MAX_NOMBRE, "%s %s", nombres_base[i % 15], (i < 5) ? "I" : (i < 10) ? "II" : "III");
        
        // asignamos una correlativa simple 
        if (i > 0) {
            // asigna la materia anterior como prerrequisito
            snprintf(m.correlativa_requerida, MAX_NOMBRE, "%s", nombres_base[(i - 1) % 15]);
        } else {
            m.correlativa_requerida[0] = '\0'; // No tiene correlativa
        }

        m.cantidadAlumnos = 0; 
        m.alumnosInscritos = NULL; // inicializamos la lista interna de cada materia hehca
        
        Head = agregar(copiar_Materia(m), tipo_Materia, Head);
    }
    
  
    printf("\n--- Generando 25 Alumnos ---\n");
    for (i = 0; i < 25; i++) {
        Alumno a;
        
        // generamos un nombre completo aleatorio
        const char *nombre_pila = nombres_alumnos[rand() % (sizeof(nombres_alumnos) / sizeof(nombres_alumnos[0]))];
        const char *apellido = apellidos_alumnos[rand() % (sizeof(apellidos_alumnos) / sizeof(apellidos_alumnos[0]))];
        
        snprintf(a.nombre, MAX_NOMBRE, "%s %s", nombre_pila, apellido);
        
        a.edad = 18 + (rand() % 5); 
        a.promedio = 6.00 + (float)(rand() % 400) / 100.0; // promedio entre 6.00 y 9.99
        a.Legajo = legajoActual++; // legajo único
        
        a.TotalNotas = 0; 
        a.cantMaterias = 0;
        a.historialRendidas = NULL;

        Head = agregar(copiar_estudiante(a), tipo_Alumno, Head);
    }
    
    printf("\n--- Carga Automática de Datos Finalizada ---\n");
    return Head;
}

Nodo *ObtenerUltimo(Nodo *Head){
  Nodo *Indice = Head;
  if (Indice == NULL) {
    return NULL;
  }
  // Mientras el siguiente sea distinto de Null, lo recorro hasta el final
  while (Indice->siguiente != NULL){
    Indice = Indice->siguiente;
  }
  return Indice;
}

// Agregar un elemento
Nodo *agregar(void *dato, tipoDato tipo, Nodo *Head)
{

  Nodo *nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->tipo = tipo;
  nuevoNodo->siguiente = NULL;

  if (nuevoNodo == NULL)
  {
    return Head;
  }

  // Si el head es null lo pongo como nuevo head
  if (Head == NULL)
  {
    return nuevoNodo;
  }
  // Si no, ir al final y enlazarlo
  Nodo *ultimonodo = ObtenerUltimo(Head);
  if (ultimonodo != NULL)
  {
    ultimonodo->siguiente = nuevoNodo;
  }

  return Head;
}

// Obtener un elemento N
Nodo *Buscar(void *datoBuscado, tipoDato tipoBuscado, Nodo *Head)
{
  Nodo *Indice = Head;
  printf("Lista: [");

  while (Indice != NULL){
    switch (Indice->tipo)
    {

    case tipo_int:
      printf("%d", *((int *)Indice->dato));
      break;

    case tipo_string:
      printf("%s", (char *)Indice->dato);
      break;

    default:
      // Esto solo debería ejecutarse si se inserta un tipo invalido
      printf("Tipo Desconocido/Error");
      break;
    }

    //por si hay una coma
    if (Indice->siguiente != NULL)
    {
      printf(", ");
    }
    //avanzamos
    Indice = Indice->siguiente;
  }

  printf("]\n");
}

// Eliminar elemento
Nodo *eliminar(void *datoBuscado, tipoDato tipoBuscado, Nodo *Head)
{
  Nodo *actual = Head;
  Nodo *anterior = NULL;

  while (actual != NULL)
  {
    int encontrado = 0;
    // solo compara si los tipos coinciden
    if (actual->tipo == tipoBuscado)
    {
      switch (tipoBuscado)
      {
      case tipo_int:
        // compara el entero almacenado con el entero buscado
        if (*((int *)actual->dato) == *((int *)tipoBuscado))
        {
          encontrado = 1;
        }
        break;
      case tipo_string:
        // compara la cadena almacenada con la cadena buscada usando strcmp
        if (strcmp((char *)actual->dato, (char *)tipoBuscado) == 0)
        {
          encontrado = 1;
        }
        break;
      }
    }
    if (encontrado)
    {
      // encontrado, reenlazar los nodos
      if (anterior == NULL)
      {
        Head = actual->siguiente; // Caso Head
      }
      else
      {
        anterior->siguiente = actual->siguiente;
      }

      free((void *)actual->dato);
      free(actual);

      return Head;
    }
    // y si no es el nodo buscado, avanzamos
    anterior = actual;
    actual = actual->siguiente;
  }
  return Head;
}

// Imprimir la lista
void ImprimirLista(Nodo *Head)
{
  Nodo *Indice = Head;
  printf("---Inicio de la Lista---\n");

  while (Indice != NULL)
  {

    // usamos el campo 'tipo' para decidir la impresión
    switch (Indice->tipo)
    {

    case tipo_int:

      printf("%d", *((int *)Indice->dato));
      break;

    case tipo_string:
      printf("%s", (char *)Indice->dato);
      break;

    case tipo_Alumno:
      Alumno *e = (Indice->dato);
      printf("Nombre: %s, Edad: %d, Promedio: %2f, Legajo: %d\n", e->nombre, e->edad, e->promedio, e->Legajo);
      break;

    default:
  
      printf("(Tipo Desconocido)");
      break;
    }

    Indice = Indice->siguiente;
  }
  printf("---Fin de la Lista---\n");
}

// Obtener el largo de la lista
int LargoLista(Nodo *Head)
{
  int sum = 0;
  Nodo *Indice = Head;
  while (Indice != NULL)
  {
    sum++;
    Indice = Indice->siguiente;
  }

  return printf("El largo de la lista es: %d", sum);
}

// ayuda a crear una copia de un int para agregar
void *copiar_int(int valor)
{
  int *ptr = (int *)malloc(sizeof(int));
  if (ptr != NULL)
  {
    *ptr = valor;
  }
  return (void *)ptr;
}

// ayuda a crear una copia de un string para agregar
void *copiar_string(const char *str)
{
  // strdup asigna memoria y copia la cadena
  return (void *)strdup(str);
}

void LiberarEspacioLista(Nodo *Head)
{
  Nodo *Actual = Head;
  Nodo *Siguiente = NULL;

  while (Actual != NULL)
  {
    // avanzamos y liberamos el nodo actual
    Siguiente = Actual->siguiente;
    free(Actual);
    Actual = Siguiente;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////MATERIAS////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ayuda a crear una copia de una materia para agregar
void *copiar_Materia(Materia m){
  Materia *nuevaMateria = malloc(sizeof(Materia));
  if (nuevaMateria == NULL){
    return NULL;
  }

  strcpy(nuevaMateria->nombre, m.nombre);
  nuevaMateria->alumnosInscritos = NULL;
  nuevaMateria->cantidadAlumnos = 0;
  return (void *)nuevaMateria;
}

void *copiar_resultado(ResultadoMateria res) {
    //guardamos la memoria del resultado
    ResultadoMateria *nuevaCopia = (ResultadoMateria *)malloc(sizeof(ResultadoMateria));
    //chequeo de error
    if (nuevaCopia == NULL) {
        return NULL; 
    }
    //creamos la copia
    *nuevaCopia = res; 
    return (void *)nuevaCopia;
}

Nodo *DarDeAltaMateria(Nodo *Head)
{
  Materia NuevaMateria;
  printf("Porfavor ingrese los datos de la nueva Materia: \n");
  printf("Nombre: ");
  //%29s es el limite de caracteres para escribir el nombre de la materia
  scanf("%29s", NuevaMateria.nombre);

  Nodo *MateriaRepetida = BuscarMatPorNombre(Head, NuevaMateria.nombre);
  if(MateriaRepetida != NULL){
    printf("Error: Materia %s ya existe", NuevaMateria.nombre);
    return Head;
  }

  NuevaMateria.cantidadAlumnos = 0;
  NuevaMateria.alumnosInscritos = NULL;

  void *datos = copiar_Materia(NuevaMateria);

  if (datos == NULL)
  {
    printf("Error al generar Materia");
    return Head;
  }
  Head = agregar(datos, tipo_Materia, Head);
  printf("Materia %s agregada exitosamente!", NuevaMateria.nombre);
  return Head;
}

void ListarMat(Nodo *Head){
  Nodo *Actual = Head;
  int cantMat = 0;
  printf("--- Inicio de la Lista ---\n");

  if (Head == NULL) {
        printf("La lista de materias está vacía.\n");
        return;
    }

  while (Actual != NULL){
    if(Actual->tipo == tipo_Materia){
      Materia *m = (Materia *)Actual->dato;
      cantMat++;
    printf("Nombre: %s, Cant. Alumnos: %d \n", m->nombre, m->cantidadAlumnos);
    }
    Actual = Actual->siguiente;
    
  }
  printf("Cantidad De Materias: %d\n", cantMat);
  printf("--- Fin de la Lista ---\n");
}

Nodo *BuscarMatPorNombre(Nodo *Head, char *nombBuscado) {
    Nodo *Actual = Head;
    
    while (Actual != NULL) { 
        if (Actual->tipo == tipo_Materia) {
            Materia *m = (Materia *)Actual->dato;
            if (strcmp(m->nombre, nombBuscado) == 0) {
                return Actual; // retorna el nodo encontrado
            }
        }
        Actual = Actual->siguiente; 
    }
    printf("Materia no encontrada\n"); 
    return NULL;
}

Nodo *EliminarMat(Nodo *Head){
  char nombEliminar[MAX_NOMBRE];
  Nodo *nodoActual = Head;
  Nodo *nodoAnterior = NULL;

  printf("\n-- Eliminación de Materia ---\n");

  if(Head == NULL){
    printf("No hay Materias");
    return Head;
  }

  printf("\nIngrese el Nombre de la Materia a eliminar: ");

  if (scanf("%29s", nombEliminar) != 1) {
    //eliminar cualquier carácter restante
     int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada inválida o error de lectura.\n");
        return Head;
    }
    //limpiar buffer después de scanf
    int c; while ((c = getchar()) != '\n' && c != EOF);

  while (nodoActual != NULL)
  {
    if (nodoActual->tipo == tipo_Materia){
      Materia *m = (Materia *)nodoActual->dato;

      if (strcmp(m->nombre, nombEliminar) == 0) {
          
                if (nodoAnterior == NULL) {
                    Head = nodoActual->siguiente;
                } else {
                    nodoAnterior->siguiente = nodoActual->siguiente;
                }
                
               
                char Eliminado[MAX_NOMBRE]; 
                strcpy(Eliminado, m->nombre); //guardar el nombre antes de liberar

                free(nodoActual->dato); 
                free(nodoActual);       
                
                printf("Materia '%s' eliminada exitosamente!\n", Eliminado);
                return Head; 
            }
        }
        
        
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
}
printf("Error al eliminar Materia \n");
  return Head;
}


void AnotarseMateria(Nodo *Head) {
    char nombreMateriaBuscada[MAX_NOMBRE];
    int legajoBuscado;
    
    Nodo *nodoAlumnoEncontrado = NULL; 
    Nodo *nodoMateriaEncontrada = NULL;

    printf("\n--- Inscripción a Materia ---\n");
    
    //obtener legajo del alumno
    printf("Ingrese el Legajo del Alumno a inscribir: ");
    if (scanf("%d", &legajoBuscado) != 1) {
        printf("Error al leer el Legajo.\n");
        // limpiar buffer después de scanf
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    // limpiar buffer después de scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // obtener Nombre de la Materia
    printf("Ingrese el Nombre de la Materia para inscribirse: ");
    if (fgets(nombreMateriaBuscada, MAX_NOMBRE, stdin) != NULL) {
        size_t len = strlen(nombreMateriaBuscada);
        if (len > 0 && nombreMateriaBuscada[len - 1] == '\n') {
            nombreMateriaBuscada[len - 1] = '\0';
        }
    } else {
        printf("Error para encontrar la materia.\n");
        return;
    }

    Nodo *Actual = Head;
    while (Actual != NULL) {
        
        // buscar Alumno por Legajo (si aun no se encuentra)
        if (Actual->tipo == tipo_Alumno && nodoAlumnoEncontrado == NULL) {
            Alumno *a = (Alumno *)Actual->dato;
            if (a->Legajo == legajoBuscado) {
                nodoAlumnoEncontrado = Actual;
            }
        }
        
        // buscar Materia por Nombre 
        if (Actual->tipo == tipo_Materia && nodoMateriaEncontrada == NULL) {
            Materia *m = (Materia *)Actual->dato;
            if (strcmp(m->nombre, nombreMateriaBuscada) == 0) {
                nodoMateriaEncontrada = Actual;
            }
        }
        
        // si ambos fueron encontrados, podemos detener la busqueda
        if (nodoAlumnoEncontrado != NULL && nodoMateriaEncontrada != NULL) {
            break;
        }
        
        Actual = Actual->siguiente;
    } 

    //verificación de Resultados
    if (nodoAlumnoEncontrado == NULL) {
        printf("Alumno con Legajo %d no encontrado.\n", legajoBuscado);
        return;
    }
    if (nodoMateriaEncontrada == NULL) {
        printf("Materia '%s' no encontrada.\n", nombreMateriaBuscada);
        return;
    }
    
    
    Alumno *a = (Alumno *)nodoAlumnoEncontrado->dato;
    Materia *m = (Materia *)nodoMateriaEncontrada->dato;
    //verificamos que ya esten
    Nodo *alumnoYaInscrito = BuscarPorLegajo(m->alumnosInscritos, a->Legajo);
    
    if (alumnoYaInscrito != NULL) {
        printf("\n ERROR: El alumno %s (Legajo: %d) ya está inscrito en la materia %s.\n", 
               a->nombre, a->Legajo, m->nombre);
        return; 
    }

    //crea una copia de los datos del alumno 
    void *copia_alumno = copiar_estudiante(*a);
    //lo agrega 
    m->alumnosInscritos = agregar(copia_alumno, tipo_Alumno, m->alumnosInscritos);
    // esta es la acción de "anotarse"
    m->cantidadAlumnos++; 

    printf("\n============================================\n");
    printf("Alumno %s (Legajo: %d) inscrito exitosamente a la materia %s.\n", 
           a->nombre, a->Legajo, m->nombre);
    printf("La materia '%s' ahora tiene %d alumnos inscritos.\n", 
           m->nombre, m->cantidadAlumnos);
    printf("============================================\n");
}



Nodo *ModificarMat(Nodo *Head)
{
  char nombBuscado[MAX_NOMBRE];
  char nuevoNombre[MAX_NOMBRE];
  int nuevaCantidad;

  if (scanf("%49s", nombBuscado) != 1)
  {
    printf("Error al leer el nombre.\n");
    while (getchar() != '\n');
    return Head;
  }
  while (getchar() != '\n');

  Nodo *nodoActual = Head;

  while (nodoActual != NULL)
  {
    if (nodoActual->tipo == tipo_Materia)
    {
      Materia *m = (Materia *)nodoActual->dato;

      if (strcmp(m->nombre, nombBuscado) == 0)
      {
        printf("\nIngrese los nuevos datos:\n", m->nombre);

        printf("Ingrese Nuevo nombre (actual: %s): ", m->nombre);
        if (scanf("%49s", nuevoNombre) == 1)
        {
          strcpy(m->nombre, nuevoNombre);
        }
        while (getchar() != '\n');

        do
        {
          printf("Nueva cantidad de alumnos (actual: %d): ", m->cantidadAlumnos);

          if (scanf("%d", &nuevaCantidad) == 1)
          {

            while (getchar() != '\n');

            if (nuevaCantidad > 0)
            {
              m->cantidadAlumnos = nuevaCantidad;
              break;
            }
            else
            {
              printf("La cantidad de alumnos debe ser mayor a 0.\n");
            }
          }
          else
          {
            printf("Error al leer la cantidad de alumnos.\n");
            while (getchar() != '\n');
          }
        } while (1);

        printf("\nSe ha modificado: \"%s\"\n", m->nombre);
        return Head;
      }
    }
    nodoActual = nodoActual->siguiente;
  }

  printf("No se pudo modificar.\n", nombBuscado);
  return Head;
}

void VerAlumnosDeMat(Nodo *Head){
  Nodo *Actual = Head;  
  char MatBuscado[MAX_NOMBRE];
  Nodo *nodoMateriaEncontrada = NULL;
  
  
  if(Head == NULL){
    printf("Lista vacia");
    return;
  }

   printf("Ingrese el Nombre de la Materia para ver los Alumnos: ");
    if (fgets(MatBuscado, MAX_NOMBRE, stdin) != NULL) {
        size_t len = strlen(MatBuscado);
        if (len > 0 && MatBuscado[len - 1] == '\n') {
           MatBuscado[len - 1] = '\0';
        }
    } else {
        printf("Error para encontrar la materia.\n");
        return;
    }

  while(Actual != NULL){
    if(Actual->tipo == tipo_Materia){
      Materia *m = (Materia *)Actual->dato;
            if (strcmp(m->nombre, MatBuscado) == 0) {
                nodoMateriaEncontrada = Actual;
                break; //encontrada 
            }
        }
      Actual = Actual->siguiente;

    }
    if (nodoMateriaEncontrada == NULL) {
        printf("Materia '%s' no encontrada.\n", MatBuscado);
        return;
    }
    Materia *m = (Materia *)nodoMateriaEncontrada->dato;

    printf("\n------------------------------------------\n");
    printf("Alumnos Inscritos en la Materia: %s\n", m->nombre);
    printf("Total de alumnos: %d\n", m->cantidadAlumnos);
    printf("--------------------------------------------\n");
  
    if (m->alumnosInscritos != NULL) {
        
        ListarEst(m->alumnosInscritos); 
    } else {
        printf("No hay alumnos inscritos en esta materia.\n");
    }
    printf("============================================\n");
    
}

Nodo *agregarResultadoMateria(Nodo *Head, ResultadoMateria res){
  //copiamos los datos del resultado
  void *datos = copiar_resultado(res);
  if(datos == NULL){
    printf("Error al copiar datos");
    return Head;
  }
  //asignamos el nodo para realizar las operaciones
  Nodo *N = (Nodo *)malloc(sizeof(N));

  //si falla la asignacion liberamos los datos
  if(N == NULL){
    free(datos);
    return Head;
  }

  //asignamos los datos al nodo y lo insertamos en el Head
  N->dato = datos;
  N->tipo = tipo_Resultado;
  N->siguiente = Head;

  return N;
}

void RendirMateria(Nodo *Head){
  char NombreBuscado[MAX_NOMBRE];
  int LegajoBuscado;

  Nodo *AlumnoBuscado = NULL;
  Nodo *MateriaBuscada = NULL;

  printf("Ingrese el Legajo del Alumno: ");
    if (scanf("%d", &LegajoBuscado) != 1) {
        printf("Error al leer el Legajo.\n");
        // limpiar buffer después de scanf
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    // limpiar buffer después de scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}


     // obtener Nombre de la Materia
    printf("Ingrese el Nombre de la Materia para inscribirse: ");
    if (fgets(NombreBuscado, MAX_NOMBRE, stdin) != NULL) {
        size_t len = strlen(NombreBuscado);
        if (len > 0 && NombreBuscado[len - 1] == '\n') {
            NombreBuscado[len - 1] = '\0';
        }
    } else {
        printf("Error para encontrar la materia.\n");
        return;
    }

  Nodo *actual = Head;

  while(actual != NULL){
    //buscamos alumno
    if (actual->tipo == tipo_Materia && MateriaBuscada == NULL){
      Materia *m = (Materia *)actual->dato;
      if (strcmp(m->nombre, NombreBuscado) == 0){
        MateriaBuscada = actual;
      }
    }
    
    if(actual->tipo == tipo_Alumno && AlumnoBuscado == NULL){
      Alumno *a = (Alumno *)actual->dato;
      if(a->Legajo == LegajoBuscado){
        AlumnoBuscado = actual;
    }
     // si ambos fueron encontrados, podemos detener la busqueda
        if (AlumnoBuscado != NULL && MateriaBuscada != NULL) {
            break;
        }
        
    }
    //avanzamos
    actual = actual->siguiente;
  }
  //verificación de Resultados
    if (AlumnoBuscado == NULL) {
        printf("Alumno con Legajo %d no encontrado.\n", LegajoBuscado);
        return;
    }
    if (MateriaBuscada == NULL) {
        printf("Materia '%s' no encontrada.\n", NombreBuscado);
        return;
    }
    
    
    Alumno *a = (Alumno *)AlumnoBuscado->dato;
    Materia *m = (Materia *)MateriaBuscada->dato;
    //verificamos que ya esten
    Nodo *alumnoYaInscrito = BuscarPorLegajo(m->alumnosInscritos, a->Legajo);
    
    if (alumnoYaInscrito == NULL) {
        printf("\n ERROR: El alumno %s (Legajo: %d) no está inscrito en la materia %s.\n", 
               a->nombre, a->Legajo, m->nombre);
        return; 
    }
    //generar nota random 
    int nota = (rand() % 10) + 1;
    //si aprueba verificamos que no pueda seguir rindiendola
    int aprobado;
    if(nota < 4){
      aprobado = 0;
    }else{
      aprobado = 1;
    }


    a->cantMaterias++;
    a->TotalNotas+=nota;
    //calculamos el promedio
    a->promedio = (float)a->TotalNotas / a->cantMaterias;

    //Guardamos el resultado
    ResultadoMateria nuevoResultado;
    strcpy(nuevoResultado.nombreMateria, m->nombre);
    nuevoResultado.nota = nota;
    nuevoResultado.aprobada = aprobado;
    a->historialRendidas = agregarResultadoMateria(a->historialRendidas, nuevoResultado);

    //Lo sacamos de la materia ya que la rindio
    m->alumnosInscritos = EliminarPorLegajoDeMateria(m->alumnosInscritos, a->Legajo);
    m->cantidadAlumnos--;

    printf("\n============================================\n");
    printf("Alumno: %s (Legajo: %d)\n", a->nombre, a->Legajo);
    printf("Materia: %s\n", m->nombre);
    printf("--------------------------------------------\n");
    printf("Nota Sacada: %d\n", nota);
    if(nota<4){
      printf("Desaprobaste! Aprueba otra Materia antes de volver a Anotarte!\n");
    }else{
      printf("Aprobaste la Cursada! Ya puedes seguir con las demas Materias!\n");
    }
    printf("--------------------------------------------\n");
    printf("Nuevo Promedio De Alumno: %.2f\n", a->promedio);

    

    printf("\n============================================\n");

}


  



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////ESTUDIANTES////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    int cantEst = 0;
    printf("--- Inicio de la Lista ---\n");
   
    while(Indice != NULL){
        //obtenemos los datos de todos los alumnos
        if(Indice->tipo == tipo_Alumno){
           Alumno *e = (Alumno *)Indice->dato;
           cantEst++;   
        printf("Nombre: %s, Edad: %d, Promedio: %.2f, Legajo: %d\n", 
               e->nombre, e->edad, e->promedio, e->Legajo); 
          
        }
         Indice = Indice->siguiente;
    }
    printf("Cantidad de Alumnos: %d\n", cantEst);
    printf("--- Fin de la Lista ---\n");
}

//damos de alta a un alumno asignandole sus valores
Nodo* DarDeAlta(Nodo *Head){
  Alumno NuevoAlumno;
  Nodo *alumnoDuplicado = NULL;
  int c;
  int EdadValida;
  
  printf("Porfavor ingrese sus datos: \n");
  printf("Nombre: ");
  scanf("%s", NuevoAlumno.nombre);

  do{
    EdadValida = 1;
    printf("Edad: ");
  //scanf siempre necesita la dirección de memoria
  if (scanf("%d", &NuevoAlumno.edad) != 1) {
    printf("Edad inválida.\n");
    while (getchar() != '\n');
    EdadValida = 0;
            };
  if(NuevoAlumno.edad < 18 || NuevoAlumno.edad>100){
    printf("Edad No correspondida para Rendir\n");
    EdadValida = 0;
  }
  }while (EdadValida == 0);
  

  do {
  printf("Legajo: ");
  scanf("%d", &NuevoAlumno.Legajo);
  alumnoDuplicado = (Nodo*)1;
  continue;
  }while ((c = getchar()) != '\n' && c != EOF); 

  alumnoDuplicado = BuscarPorLegajo(Head, NuevoAlumno.Legajo);
  if(alumnoDuplicado != NULL){
    printf("Este Legajo ya exite, intente otro");
  }while (alumnoDuplicado != NULL);

  NuevoAlumno.promedio = 0.0;

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


Nodo *BuscarPorLegajo(Nodo *Head, int LegajoBusc) {
    Nodo *indice = Head;
    
    while (indice != NULL) {
        if (indice->tipo == tipo_Alumno) { 
            Alumno *alum = (Alumno *)indice->dato;

            if (alum->Legajo == LegajoBusc) {
        
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
                // encontrado eliminamos el nodo
                if (previo == NULL) {
                    //si el nodo a eliminar es el primero
                    Head = actual->siguiente;
                } else {
                    // caso de si el nodo es intermedio o final
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

Nodo *EliminarPorLegajoDeMateria(Nodo *Head, int LegajoBus){
  Nodo *actual = Head;
  Nodo *previo = NULL;

  while(actual != NULL){
    if(actual->tipo == tipo_Alumno){
      Alumno *a = (Alumno*)actual->dato;
      if(a->Legajo == LegajoBus){
        //si es el Head solo
        if(previo == NULL){
          Head = actual->siguiente;
        }else{
          previo->siguiente = actual->siguiente;
        }

        free(actual->dato);
        free(actual);
        return Head;
      }
    }
    previo = actual;
    actual = actual->siguiente;
  }
  return Head;
}