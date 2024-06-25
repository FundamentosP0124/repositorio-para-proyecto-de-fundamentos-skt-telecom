#include <iostream>
#include <string>

using namespace std;

void mostrarMenu()
{
    cout << "SKT Telecom\n";
    cout << " /_/\  \n";
    cout << "( o - o )\n";
    cout << " > ^ <\n";
    cout << "__/\n";
    cout << "( ^ - ^ )\n" ;
    cout << " > ^ <\n" ;
    cout << "Menu:\n";
    cout << "1. Jugar\n";
    cout << "2. Opciones\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Jugando...\n";
            // Código para jugar el juego
            break;
        case 2:
            cout << "Opciones:\n";
            // Código para mostrar opciones del juego
            break;
        case 3:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}