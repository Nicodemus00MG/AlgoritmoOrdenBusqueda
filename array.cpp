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

void generarArray(int tamanio, int array[]);

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
            generarArray(tamanio, array);

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

void ordenBurbuja(int tamanio,int array[]){


    
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
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento "
             << "[" << i + 1 << "]"
             << ": " << array[i] << endl;
    }

    // Llenado de array según la posición
    for (int i = 0; i < tamanio; ++i)
    {
        int posicion;
        cout << " elemento :" << i + 1 << ":10" << endl;
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
        for (int i = 0; i < tamanio; i++)
        {
            cout << "Elemento "
                 << "[" << i + 1 << "]"
                 << ": " << array[i] << endl;
        }
    }
    cout << endl;

    // Listar array
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i + 1 << " : " << array[i] << endl;
    }
}
