/*
 *Autor: Rosario
 *fecha:29/12/23
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//! prototipos funciones
void generarArray(int tamanio, int array[]);
void listarArray(int tamanio, int array[]);
void ordenBurbuja(int tamanio, int array[]);
void ordenInsercion(int tamanio, int array[]);
void ordenSeleccion(int tamanio, int array[]);

void ordenQuickSort(int tamanio, int array[]);
void intercambiar(int &a, int &b);
int particion(int array[], int bajo, int alto);
void ordenQuickSort(int array[], int bajo, int alto, int tamanio);
void heapify(int array[], int tamanio, int indice);
void ordenHeapSort(int tamanio, int array[]);
int busquedaLineal(int tamanio, int array[], int valorBuscar);
int busquedaBinaria(int tamanio, int array[], int valorBuscar);
int main()
{
    srand(time(0));

    // Ingrese el tamaño del array
    int tamanio;
    int elemento;
    int indiceElementoEcontrado;
    cout << "Ingrese el tamanio del array (total de numeros): ";
    cin >> tamanio;
    int array[tamanio];
    int arrayOriginal[tamanio];
    bool flag = true;
    char op;

    while (flag)
    {

        cout << "------ MENU - ARRAY 2023-2024 APP C++------------\n";

        cout << "A. Generar array nums aleatorios 1:100" << endl;

        cout << "B. Ordenamiento por Burbuja" << endl;
        cout << "C. Ordenamiento por Insercion Lineal" << endl;
        cout << "D. Ordenamiento por Seleccion" << endl;
        cout << "E. Ordenamiento por HeapSort (arbol)" << endl;
        cout << "F. Ordenamiento por QuickSort" << endl;
        cout << "G. Busqueda lineal" << endl;
        cout << "H. Busqueda binaria" << endl;
        cout << "S. Salir" << endl;

        cout << "Ingrese opcion: " << endl;
        cin >> op;
        op = toupper(op);

        cout << endl;
        switch (op)
        {
        case 'A':
            cout << "\n......GENERANDO ARRAY.......\n";

            generarArray(tamanio, array);

            for (int i = 0; i < tamanio; i++)
            {
                arrayOriginal[i] = array[i];
            }

            break;
        case 'B':
            cout << "\n......ORDEN BURBUJA.......\n";
            ordenBurbuja(tamanio, array);

            cout << "Array original: \n";
            listarArray(tamanio, arrayOriginal);
            cout << "\n+++++ARRAY ORDENADO POR BURBUJA (DESCENDENTE)+++++: \n";
            listarArray(tamanio, array);
            break;
        case 'C':
            cout << "\n.....ORDEN INSERCION LINEAL.......\n";
            ordenInsercion(tamanio, array);

            cout << "Array original: \n";
            listarArray(tamanio, arrayOriginal);
            cout << "\n+++++ARRAY ORDENADO POR INSERCION+++++: \n";
            listarArray(tamanio, array);
            break;
        case 'D':
            cout << "\n......ORDEN SELECCION.......\n";
            ordenSeleccion(tamanio, array);
            cout << "Array original: \n";
            listarArray(tamanio, arrayOriginal);
            cout << "\n+++++ARRAY ORDENADO POR SELECCION+++++: \n";

            listarArray(tamanio, array);
            break;
        case 'E':
            cout << "\n........ ORDEN HEAPSORT........\n";

            ordenHeapSort(tamanio, array);
            cout << "Array original: \n";
            listarArray(tamanio, arrayOriginal);

            cout << "\n+++++ARRAY ORDENADO POR HEAPSORT+++++: \n";

            listarArray(tamanio, array);
            break;
        case 'F':
            cout << "\n........0RDEN QUICKSORT........\n";
            ordenQuickSort(array, 0, tamanio - 1, tamanio);
            cout << "Array original: \n";
            listarArray(tamanio, arrayOriginal);
            cout << "\n+++++ARRAY ORDENADO POR QUICKSORT+++++: \n";
            listarArray(tamanio, array);
            break;

        case 'G':
            cout << "\n........BUSQUEDA LINEAL...........\n";

            cout << "\nIngrese elemento a buscar: \n";
            cin >> elemento;
            indiceElementoEcontrado = busquedaLineal(tamanio, array, elemento);
            if (indiceElementoEcontrado != -1)
            {
                cout << "Elemento encontrado con exito! : \n";
                cout << "Elemento= " << elemento << " / "
                     << " Posicion: " << indiceElementoEcontrado + 1 << endl;
            }
            else
            {

                cout << "Elemento no esta en el array  :(  " << endl;
            }
            break;
        case 'H':
            cout << "\n........BUSQUEDA BINARIA...........\n";

            cout << "\nIngrese elemento a buscar: \n";
            cin >> elemento;
            indiceElementoEcontrado = busquedaBinaria(tamanio, array, elemento);
            if (indiceElementoEcontrado != -1)
            {
                cout << "Elemento encontrado con exito! : \n";
                cout << "Elemento= " << elemento << " / "
                     << " Posicion: " << indiceElementoEcontrado + 1 << endl;
            }
            else
            {

                cout << "Elemento no esta en el array  :(  " << endl;
            }
            break;

        case 'S':
            cout << "\nGracias por usar esta app!" << endl;
            flag = false;
            break;
        default:
            cout << "\nDato ingresado no valido" << endl;
            break;
        }
    }
    return 0;
}

void listarArray(int tamanio, int array[])
{
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento "
             << "[" << i + 1 << "]"
             << ": " << array[i] << endl;
    }
}

void ordenBurbuja(int tamanio, int array[])
{
    // El bucle externo representa cada pase a través del array
    for (int i = 0; i < tamanio - 1; ++i)
    {
        // El bucle interno compara y realiza intercambios
        for (int j = 0; j < tamanio - i - 1; ++j)
        {
            // Comparar elementos adyacentes
            if (array[j] > array[j + 1])
            {
                // Intercambiar si están en el orden incorrecto
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void ordenInsercion(int tamanio, int array[])
{
    // Comenzamos desde el segundo elemento, ya que asumimos que el primer elemento está "ordenado"
    for (int i = 1; i < tamanio; ++i)
    {
        int valorActual = array[i];
        int j = i - 1;

        // Mover los elementos mayores que el valor actual a la derecha
        while (j >= 0 && array[j] > valorActual)
        {
            array[j + 1] = array[j];
            --j;
        }

        // Colocar el valor actual en su posición correcta
        array[j + 1] = valorActual;
    }
}

void generarArray(int tamanio, int array[])
{

    // Llenar array con 0's
    for (int i = 0; i < tamanio; i++)
    {
        array[i] = 0;
    }

    cout << "\nIngrese la posicion que desea para ingrear valor aleatorio de 1 a 100 \n";
    // Listar array de 0's para saber la posición y pedir datos al usuario según la posición
    listarArray(tamanio, array);

    // Llenado de array según la posición
    for (int i = 0; i < tamanio; ++i)
    {
        int posicion;
        cout << " elemento :" << i + 1 << ":" << tamanio << endl;
        cout << "\nposicion seleccionada:";
        cin >> posicion;

        if (posicion - 1 < 0 || posicion - 1 >= tamanio)
        {
            cout << "Posición inválida. Inténtalo de nuevo." << endl;
            --i; // Decrementar i para repetir la misma posición en el siguiente ciclo
            continue;
        }

        // Llenar la posición con un número aleatorio hasta llegar a 100
        array[posicion - 1] = rand() % 100 + 1;
        listarArray(tamanio, array);
    }
    cout << endl;

    // Listar array
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << " : " << array[i] << endl;
    }
}

void ordenSeleccion(int tamanio, int array[])
{
    for (int i = 0; i < tamanio - 1; ++i)
    {
        // Encontrar el índice del elemento más pequeño en el resto del array
        int indiceMenor = i;
        for (int j = i + 1; j < tamanio; ++j)
        {
            if (array[j] < array[indiceMenor])
            {
                indiceMenor = j;
            }
        }

        // Intercambiar el elemento más pequeño con el primer elemento no ordenado
        int temp = array[i];
        array[i] = array[indiceMenor];
        array[indiceMenor] = temp;
    }
}

// Función para intercambiar dos elementos en un array
void intercambiar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Función para encontrar el índice del pivote y dividir el array en dos partes
int particion(int array[], int bajo, int alto)
{
    int pivote = array[alto]; // Elegir el último elemento como pivote
    int i = (bajo - 1);       // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; ++j)
    {
        // Si el elemento actual es más pequeño o igual al pivote
        if (array[j] <= pivote)
        {
            // Incrementar el índice del elemento más pequeño
            ++i;
            intercambiar(array[i], array[j]);
        }
    }

    // Intercambiar el pivote con el elemento en la posición correcta
    intercambiar(array[i + 1], array[alto]);
    return i + 1;
}

// Función principal de QuickSort
void ordenQuickSort(int array[], int bajo, int alto, int tamanio)
{
    if (bajo < alto)
    {
        // Obtener el índice del pivote
        int indicePivote = particion(array, bajo, alto);

        // Ordenar recursivamente los elementos antes y después del pivote
        ordenQuickSort(array, bajo, indicePivote - 1, tamanio);
        ordenQuickSort(array, indicePivote + 1, alto, tamanio);
    }
}

void heapify(int array[], int tamanio, int indice)
{
    int mayor = indice; // Inicializar el nodo raíz como el mayor
    int izquierda = 2 * indice + 1;
    int derecha = 2 * indice + 2;

    // Verificar si el hijo izquierdo es mayor que la raíz
    if (izquierda < tamanio && array[izquierda] > array[mayor])
    {
        mayor = izquierda;
    }

    // Verificar si el hijo derecho es mayor que la raíz o el hijo izquierdo
    if (derecha < tamanio && array[derecha] > array[mayor])
    {
        mayor = derecha;
    }

    // Si el mayor no es la raíz, intercambiar y seguir heapificando
    if (mayor != indice)
    {
        intercambiar(array[indice], array[mayor]);
        heapify(array, tamanio, mayor);
    }
}

void ordenHeapSort(int tamanio, int array[])
{
    // Construir un montículo (heap)
    for (int i = tamanio / 2 - 1; i >= 0; --i)
    {
        heapify(array, tamanio, i);
    }

    // Extraer elementos del montículo uno por uno
    for (int i = tamanio - 1; i > 0; --i)
    {
        intercambiar(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int busquedaLineal(int tamanio, int array[], int valorBuscar)
{
    for (int i = 0; i < tamanio; ++i)
    {
        if (array[i] == valorBuscar)
        {
            return i; // Se encontró el valor, se devuelve la posición
        }
    }
    return -1; // El valor no se encontró en el array
}

int busquedaBinaria(int tamanio, int array[], int valorBuscar)
{
    int izquierda = 0, derecha = tamanio - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Verificar si el valor está en el medio
        if (array[medio] == valorBuscar)
            return medio;

        // Si el valor está en la mitad derecha del array, descartar la mitad izquierda
        if (array[medio] < valorBuscar)
            izquierda = medio + 1;
        // Si el valor está en la mitad izquierda del array, descartar la mitad derecha
        else
            derecha = medio - 1;
    }

    // El valor no se encuentra en el array
    return -1;
}