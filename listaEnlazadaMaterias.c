#include "estudiantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 30


int main(){
  Nodo *Lista = NULL;
  int opcion = 0;

  Materia m1 = {"Algebra", 10};
  Lista = agregar(copiar_Materia(m1), tipo_Materia, Lista);
  Materia m2 = {"ED", 25};
  Lista = agregar(copiar_Materia(m2), tipo_Materia, Lista);
  Materia m3 = {"Ppp", 30};
  Lista = agregar(copiar_Materia(m3), tipo_Materia, Lista);
  printf("Materias: \n ");
  Alumno a1 = {"Juan Perez", 20, 8.5, 1001};
  Lista = agregar(copiar_estudiante(a1), tipo_Alumno, Lista);

  printf("Lista actual Materias:\n");
  ListarMat(Lista);
  

  // printf("Ingrese materia \n");
  // Lista = DarDeAltaMateria(Lista);
  // printf("Materias: \n ");
  // ListarMat(Lista);

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
        
        case 0: 
        printf("\nSaliendo del programa. Liberando memoria...\n");
        break;

        default:
          printf("\nOpción no válida. Intente de nuevo.\n");
          break;
        }
         
  }
  while (opcion != 0);
  LiberarEspacioLista(Lista);
  return 0;
}

void MostrarMenu(){
    printf("\n=====================================\n");
    printf("       GESTOR DE MATERIAS       \n");
    printf("=====================================\n");
    printf("1. Dar de Alta (Agregar nueva Materia)\n");
    printf("2. Listar todas las materias\n");
    printf("3. Buscar Materia por Nombre\n");
    printf("4. Eliminar Materia\n");
    printf("5. Modificar \n");
    printf("6. Anotarse a Materia\n");
    printf("7. \n");
    printf("0. Salir\n");
    printf("Ingrese su opción: ");
}

Nodo *ObtenerUltimo(Nodo *Head)
{

  Nodo *Indice = Head;
  if (Indice == NULL)
  {
    return NULL;
  }
  // Mientras el siguiente sea distinto de Null, lo recorro hasta el final
  while (Indice->siguiente != NULL)
  {
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

  while (Indice != NULL)
  {

    switch (Indice->tipo)
    {

    case tipo_int: // <<-- ¡USANDO MINÚSCULAS!
      // CORRECCIÓN CLAVE: Usar Indice->DATO y desreferenciar
      printf("%d", *((int *)Indice->dato));
      break;

    case tipo_string: // <<-- ¡USANDO MINÚSCULAS!
      // CORRECCIÓN CLAVE: Usar Indice->DATO
      printf("%s", (char *)Indice->dato);
      break;

    default:
      // Esto solo debería ejecutarse si se inserta un tipo inválido.
      printf("Tipo Desconocido/Error");
      break;
    }

    // Lógica de coma
    if (Indice->siguiente != NULL)
    {
      printf(", ");
    }

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
    // Solo compara si los tipos coinciden
    if (actual->tipo == tipoBuscado)
    {
      switch (tipoBuscado)
      {
      case tipo_int:
        // Compara el entero almacenado con el entero buscado
        if (*((int *)actual->dato) == *((int *)tipoBuscado))
        {
          encontrado = 1;
        }
        break;
      case tipo_string:
        // Compara la cadena almacenada con la cadena buscada usando strcmp
        if (strcmp((char *)actual->dato, (char *)tipoBuscado) == 0)
        {
          encontrado = 1;
        }
        break;
      }
    }
    if (encontrado)
    {
      // 2. Encontrado: Reenlazar los nodos
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
    // Si no es el nodo buscado avanzamos
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

    // Usa el campo 'tipo' para decidir la impresión
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
      // Esto maneja el caso donde el tipo es inválido
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

// Ayuda a crear una copia de un int para agregar
void *copiar_int(int valor)
{
  int *ptr = (int *)malloc(sizeof(int));
  if (ptr != NULL)
  {
    *ptr = valor;
  }
  return (void *)ptr;
}

// Ayuda a crear una copia de un string para agregar
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

void *copiar_Materia(Materia m)
{
  Materia *nuevaMateria = malloc(sizeof(Materia));
  if (nuevaMateria == NULL)
  {
    return NULL;
  }

  *nuevaMateria = m;
  return (void *)nuevaMateria;
}

Nodo *DarDeAltaMateria(Nodo *Head)
{
  Materia NuevaMateria;
  printf("Porfavor ingrese los datos de la nueva Materia: \n");
  printf("Nombre: ");
  //%29s es el limite de caracteres para escribir el nombre de la materia
  scanf("%29s", NuevaMateria.nombre);

  NuevaMateria.cantidadAlumnos = 0;

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

void ListarMat(Nodo *Head)
{
  Nodo *Actual = Head;
  printf("--- Inicio de la Lista ---\n");

  if (Head == NULL) {
        printf("La lista de materias está vacía.\n");
        return;
    }

  while (Actual != NULL)
  {
    if(Actual->tipo == tipo_Materia){
      Materia *m = (Materia *)Actual->dato;
    printf("Nombre: %s, Cant. Alumnos: %d \n", m->nombre, m->cantidadAlumnos);
    
    }
    Actual = Actual->siguiente;
  }
  printf("--- Fin de la Lista ---\n");
}

Nodo *BuscarMatPorNombre(Nodo *Head, char *nombBuscado)
{
  Nodo *Actual = Head;
  while (Actual != NULL)
  {

    if (Actual->tipo == tipo_Materia)
    {
      Materia *m = (Materia *)Actual->dato;

      if (strcmp(m->nombre, nombBuscado) == 0)
      {

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
    // Eliminar cualquier carácter restante
     int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada inválida o error de lectura.\n");
        return Head;
    }
    // Limpiar buffer después de scanf
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
                strcpy(Eliminado, m->nombre); // Guardar el nombre antes de liberar

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
    
    // Variables para almacenar los nodos encontrados
    Nodo *nodoAlumnoEncontrado = NULL; 
    Nodo *nodoMateriaEncontrada = NULL;

    printf("\n--- Inscripción a Materia ---\n");
    
    // 1. Obtener Legajo del Alumno
    printf("Ingrese el Legajo del Alumno a inscribir: ");
    if (scanf("%d", &legajoBuscado) != 1) {
        printf("❌ Error al leer el Legajo.\n");
        // Limpiar buffer después de scanf
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    // Limpiar buffer después de scanf
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    // 2. Obtener Nombre de la Materia
    printf("Ingrese el Nombre de la Materia para inscribirse: ");
    if (fgets(nombreMateriaBuscada, MAX_NOMBRE, stdin) != NULL) {
        size_t len = strlen(nombreMateriaBuscada);
        if (len > 0 && nombreMateriaBuscada[len - 1] == '\n') {
            nombreMateriaBuscada[len - 1] = '\0';
        }
    } else {
        printf("❌ Error de lectura para la materia.\n");
        return;
    }

    // 3. BÚSQUEDA INTEGRADA EN LA LISTA
    Nodo *Actual = Head;
    while (Actual != NULL) {
        
        // Buscar Alumno por Legajo (si aún no se encuentra)
        if (Actual->tipo == tipo_Alumno && nodoAlumnoEncontrado == NULL) {
            Alumno *a = (Alumno *)Actual->dato;
            if (a->Legajo == legajoBuscado) {
                nodoAlumnoEncontrado = Actual;
            }
        }
        
        // Buscar Materia por Nombre (si aún no se encuentra)
        if (Actual->tipo == tipo_Materia && nodoMateriaEncontrada == NULL) {
            Materia *m = (Materia *)Actual->dato;
            if (strcmp(m->nombre, nombreMateriaBuscada) == 0) {
                nodoMateriaEncontrada = Actual;
            }
        }
        
        // Si ambos fueron encontrados, podemos detener la búsqueda
        if (nodoAlumnoEncontrado != NULL && nodoMateriaEncontrada != NULL) {
            break;
        }
        
        Actual = Actual->siguiente;
    } 

    // 4. Verificación de Resultados
    if (nodoAlumnoEncontrado == NULL) {
        printf("❌ Alumno con Legajo %d no encontrado.\n", legajoBuscado);
        return;
    }
    if (nodoMateriaEncontrada == NULL) {
        printf("❌ Materia '%s' no encontrada.\n", nombreMateriaBuscada);
        return;
    }
    
    // 5. ANOTAR AL ALUMNO (Incrementar el contador)
    Alumno *a = (Alumno *)nodoAlumnoEncontrado->dato;
    Materia *m = (Materia *)nodoMateriaEncontrada->dato;
    
    // Esta es la acción de "anotarse"
    m->cantidadAlumnos++; 

    printf("\n============================================\n");
    printf("✅ Alumno **%s** (Legajo: %d) inscrito exitosamente a la materia **%s**.\n", 
           a->nombre, a->Legajo, m->nombre);
    printf("La materia '%s' ahora tiene **%d** alumnos inscritos.\n", 
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