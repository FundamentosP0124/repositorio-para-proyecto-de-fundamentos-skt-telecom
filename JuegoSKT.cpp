#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

#define META 50
#define NUM_CABALLOS 5

struct Jugador
{
    string nombre;
    int caballo;
    int apuesta;
};

void mostrarCaballo(int posicion)
{
    for (int i = 0; i < posicion; ++i)
    {
        cout << " ";
    }
    cout << ">\n";
}

void mostrarCarrera(int posiciones[NUM_CABALLOS])
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (int i = 0; i < NUM_CABALLOS; ++i)
    {
        mostrarCaballo(posiciones[i]);
    }
}

void mostrarMenu()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Bienvenido al juego de apuestas de caballos\n";
    cout << "               By SKT Telecom\n";
    cout << "( o - o )\n";
    cout << "                                       >__<\n";
    cout << "             ( ^ - ^ )\n";
    cout << "                            > ^---^ <\n";
    cout << "               Menu principal:\n";
    cout << "                   1. Jugar\n";
    cout << "                 2. Como jugar\n";
    cout << "                 3. Integrantes\n";
    cout << "                   4. Salir\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "              Seleccione una opcion: ";
}

int main()
{
    int opcion;
    srand(time(NULL));
    int posiciones[NUM_CABALLOS] = {0};

    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            int numJugadores;
            cout << "Cuantos jugadores van a jugar? (Maximo 3): ";
            cin >> numJugadores;
            if (numJugadores < 1 || numJugadores > 3)
            {
                cout << "Numero de jugadores invalido. Debe ser entre 1 y 3.\n";
                break;
            }

            // Ingresar nombres y apuestas
            Jugador *jugadores = new Jugador[numJugadores];
            for (int i = 0; i < numJugadores; ++i)
            {
                cout << "Jugador numero " << i + 1 << " ingrese su nombre: ";
                cin >> jugadores[i].nombre;
                cout << "Ingrese el numero del caballo (1-" << NUM_CABALLOS << ") en el que desea apostar: ";
                cin >> jugadores[i].caballo;
                jugadores[i].caballo--; // ajustar a indice del array
                cout << "Ingrese su apuesta: ";
                cin >> jugadores[i].apuesta;
            }

            // Carrera
            bool fin = false;
            while (!fin)
            {
                for (int i = 0; i < NUM_CABALLOS; ++i)
                {
                    posiciones[i] += rand() % 3; // El caballo se mueve entre 0 y 2 posiciones
                    if (posiciones[i] >= META)
                    {
                        fin = true;
                    }
                }
                mostrarCarrera(posiciones);
                usleep(200000); // Pausa de 200 milisegundos
            }

            // Resultados
            int ganador = 0;
            for (int i = 1; i < NUM_CABALLOS; ++i)
            {
                if (posiciones[i] > posiciones[ganador])
                {
                    ganador = i;
                }
            }
            cout << "El caballo " << ganador + 1 << " ha ganado la carrera!\n";

            for (int i = 0; i < numJugadores; ++i)
            {
                if (jugadores[i].caballo == ganador)
                {
                    cout << "Felicidades " << jugadores[i].nombre << "! Has ganado " << jugadores[i].apuesta * 2 << " unidades.\n";
                }
                else
                {
                    cout << "Lo siento " << jugadores[i].nombre << ", has perdido tu apuesta de " << jugadores[i].apuesta << " unidades.\n";
                }
            }

            delete[] jugadores; // Liberar memoria
            break;
        }
        case 2:
            cout << "\n";
            cout << "---------------------------------------------------------------------------------------------------------------------------\n";
            cout << "has seleccionado el apartado como jugar:\n";
            cout << "Bienvenido al juego de carrera de caballos el juego es simple \n";
            cout << "Al momento de darle jugar nos solicitara que indiquemos cuantos jugadores jugaran la partida\n";
            cout << "Despues de indicar nos pedira nuestro nombre para poder dar un ganador a la hora de finalizar la carrera\n";
            cout << "Luego nos solicitara que ingresemos el numero del caballo al que deseamos apoyar y la apuesta que deseamos ingresar\n";
            cout << "Y este proceso repetira dependiendo del numero de jugadores que jugaran\n";
            cout << "Esperemos disfrutes el juego! nos vemos en la pista de carreras\n";
            cout << "---------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n";

            break;
        case 3:
            cout << "\n";
            cout << "***************************************************************************\n";
            cout << "Has seleccionado el apartdado para ver los integrantes de SKT Telecom:\n";
            cout << "Daniel Adalberto Alvarado Flores, 00048524\n";
            cout << "Hector Ernesto Argueta Constanza, 00012424\n";
            cout << "Xavier Ernesto Garcia Villacorta, 00014624\n";
            cout << "***************************************************************************\n";
            cout << "\n";

            break;
        case 4:
            cout << "Saliendo del juego...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}