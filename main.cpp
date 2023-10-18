#include <iostream>
#include "Cola.h"
#include <locale>

int main()
{
    Cola MiCola;
    alumno x;
    int opcion;

    do
    {
        setlocale(LC_ALL,"");
        std::cout << "\nMENÚ - COLA ESTÁTICA (BÚSQUEDAS)\n" << std::endl;
        std::cout << "1. Dar de alta la solicitud de un alumno" << std::endl;
        std::cout << "2. Elaborar una constancia" << std::endl;
        std::cout << "3. Buscar una solicitud (búsqueda lineal)" << std::endl;
        std::cout << "4. Buscar una solicitud (búsqueda binaria)" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "\nSeleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::cout << "\nIngrese los datos del alumno\n";
            std::cout << "----------------------------";
            std::cin >> x;
            MiCola.enqueue(x);
            break;

        case 2:
            if (!MiCola.vacia())
            {
                x = MiCola.dequeue();
                std::cout << "\nSe ha elaborado una constancia para el alumno\n";
                std::cout << "------------------------------------------------------------------------------------\n";
                std::cout << x << std::endl;
            }
            else
            {
                std::cout << "\nNo hay solicitudes en la cola, debe dar de alta una solicitud primero.\n" << std::endl;
            }
            break;

        case 3:
            if (!MiCola.vacia())
            {
                std::cout << "\nIngrese los datos del alumno a buscar\n";
                std::cout << "-------------------------------------";
                std::cin >> x;
                int posicion = MiCola.busquedaLineal(x);
                if (posicion == -1)
                {
                    std::cout << "Ese usuario no ha generado una constancia." << std::endl;
                }
                else
                {
                    int constanciasAntes = posicion /*+ 1*/;
                    std::cout << "\nEl usuario tiene la posición: " << posicion +1 << std::endl;
                    std::cout << "\nConstancias que deben elaborarse antes del alumno: " << constanciasAntes << std::endl;
                }
            }
            else
            {
                std::cout << "\nNo hay solicitudes en la cola, debe dar de alta una solicitud primero.\n" << std::endl;
            }
            break;

        case 4:
            if (!MiCola.vacia())
            {
                std::cout << "Ingrese la persona a buscar: ";
                std::cin >> x;
                int posicion = MiCola.busquedaBinaria(x);
                if (posicion == -1)
                {
                    std::cout << "Ese usuario no ha generado una constancia." << std::endl;
                }
                else
                {
                    int constanciasAntes = posicion;
                    std::cout << "El usuario tiene la posición: " << posicion +1 << std::endl;
                    std::cout << "Constancias que deben elaborarse antes de su turno: " << constanciasAntes << std::endl;
                }
            }
            else
            {
                std::cout << "\nNo hay solicitudes en la cola, debe dar de alta una solicitud primero.\n" << std::endl;
            }
            break;

        case 5:
            std::cout << "\nSaliendo del programa...\n" << std::endl;
            break;

        default:
            std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }
    }
    while (opcion != 5);

    return 0;
}
