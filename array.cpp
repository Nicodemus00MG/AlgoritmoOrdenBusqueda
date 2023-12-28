/*
? Crear un programa que contenga los siguientes elementos en su menú
? OPCION A Generar un array de posiciones seleccionadas por el usuario que se llene de números randomicos hasta el numero 100
? OPCION B Ordenar los elementos con el algoritmo de la burbuja
? OPCION C Ordenar los elementos con el algoritmo de inserción lineal
? OPCION D Ordenar los elementos con el algoritmo de selección
? OPCION E Ordenar los elementos con el algoritmo de HeapSort(árbol)
? OPCION F Ordenar los elementos con el algoritmo de QuickSort(rápido)
? OPCION G Generar búsqueda de elemento con el algoritmo de búsqueda lineal
? OPCION H Generar búsqueda de elemento con el algoritmo de búsqueda binaria
? Todas las opciones del menú deben tener su propia función.

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
void ordenHeapSort(int tamanio,int array[]);
void ordenQuickSort(int tamanio,int array[]);
int main()
{
    srand(time(0));

    // Ingrese el tamaño del array
    int tamanio;
    cout << "Ingrese el tamanio del array (total de numeros): ";
    cin >> tamanio;
    int array[tamanio];
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
        cout << endl;
        switch (op)
        {
        case 'A':
            cout << "\n......GENERANDO ARRAY.......\n";

            generarArray(tamanio, array);

            break;
        case 'B':
            cout << "\n......ORDEN BURBUJA.......\n";
            ordenBurbuja(tamanio, array);
            listarArray(tamanio, array);
            break;
            case 'C':
            cout<<"\n.....ORDEN INSERCION LINEAL.......\n";
            ordenInsercion(tamanio,array);
            listarArray(tamanio,array);
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
    for (int i = 1; i < tamanio; ++i) {
        int valorActual = array[i];
        int j = i - 1;

        // Mover los elementos mayores que el valor actual a la derecha
        while (j >= 0 && array[j] > valorActual) {
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

void ordenSeleccion(int tamanio, int array[]){
for (int i = 0; i < tamanio - 1; ++i) {
        // Encontrar el índice del elemento más pequeño en el resto del array
        int indiceMenor = i;
        for (int j = i + 1; j < tamanio; ++j) {
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Intercambiar el elemento más pequeño con el primer elemento no ordenado
        int temp = array[i];
        array[i] = array[indiceMenor];
        array[indiceMenor] = temp;
    }
}
void ordenHeapSort(int tamanio,int array[]){

}
void ordenQuickSort(int tamanio,int array[]){
    
}
