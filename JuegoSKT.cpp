#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <limits>
#include <fstream>
#include <algorithm>


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
     printf("\3");  printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");     printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");   printf("\3");printf("\3\n");
     
    cout << "Bienvenido al juego de apuestas de caballos\n";
    cout << "               By SKT Telecom\n";
    cout << "( o - o )\n";
    cout << "                                       >__<\n";
    cout << "             ( ^ - ^ )\n";
    cout << "                            > ^---^ <\n";
    cout << "                 Menu principal:\n";
   cout << "                   1. Jugar"; printf("\21\n");
    cout << "                 2. Como jugar";printf("\21\n");
    cout << "                 3. Integrantes";printf("\21\n");
    cout << "                   4. Salir"; printf("\21\n");
    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");     printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");    printf("\3");printf("\3");   printf("\3");printf("\3\n");

   
    cout << "              Seleccione una opcion:";
     
}
bool volverAlMenu()
{
    char respuesta;
    cout << "Desea volver al menu principal? (s/n): ";
    cin >> respuesta;
    return respuesta == 's' || respuesta == 'S';
}
bool jugarOtraVez()
{
    char respuesta;
    cout << "Desean jugar otra vez? (s/n): ";
    cin >> respuesta;
    return respuesta == 's' || respuesta == 'S';
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
            bool seguirJugando;
            do
            {
                int numJugadores;
                do
                {
                    cout << "Cuantos jugadores van a jugar? (Maximo 3): ";
                    cin >> numJugadores;
                    if (numJugadores < 1 || numJugadores > 3)
                    {
                        cout << "\n";
                        cout << "Error## Numero de jugadores invalido. Debe ser entre 1 y 3.\n";
                        cout << "\n";
                    }
                } while (numJugadores < 1 || numJugadores > 3);

                // Zona de recoleccion de nombres y apuestas
Jugador *jugadores = new Jugador[numJugadores];
for (int i = 0; i < numJugadores; ++i)
{
    cout << "Jugador numero " << i + 1 << " ingrese su nombre: ";
    cin >> jugadores[i].nombre;

    // Validar que solo se permitan letras en el nombre
    while (!all_of(jugadores[i].nombre.begin(), jugadores[i].nombre.end(), ::isalpha)) {
        cout << "Error## El nombre solo debe contener letras. Intente de nuevo.\n";
        cin >> jugadores[i].nombre;
    }

    // Valida número de caballo para que sea solo los del rango
    do
    {
        cout << "Ingrese el numero del caballo (1-" << NUM_CABALLOS << ") en el que desea apostar: ";
        cin >> jugadores[i].caballo;

        if (cin.fail() || jugadores[i].caballo < 1 || jugadores[i].caballo > NUM_CABALLOS)
        {
            cout << "Error## Numero de caballo invalido. Intente de nuevo.\n";
            cin.clear();                                         // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
        }
    } while (jugadores[i].caballo < 1 || jugadores[i].caballo > NUM_CABALLOS);
    jugadores[i].caballo--; // Ajustar a índice del array

    // Validar que solo se permitan números en la apuesta
    do
    {
        cout << "Ingrese su apuesta: ";
        cin >> jugadores[i].apuesta;

        if (cin.fail() || jugadores[i].apuesta <= 0)
        {
            cout << "Error## Apuesta invalida. Debe ser un numero positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || jugadores[i].apuesta <= 0);
}

                // Carrera
                bool fin = false;
                // Reinicia las posiciones antes de cada carrera
                for (int i = 0; i < NUM_CABALLOS; ++i)
                {
                    posiciones[i] = 0;
                }

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
                 
                



         // Guardar resultados en un archivo de texto
ofstream archivo("resultado_partida.txt", ios::app);
if (archivo.is_open()) {
    archivo << "Resultado de la partida:\n";
    archivo << "------------------------\n";
    for (int i = 0; i < numJugadores; ++i) {
        if (jugadores[i].caballo == ganador) {
            archivo << "Ganador: " << jugadores[i].nombre << " - Apuesta: " << jugadores[i].apuesta << " unidades - Caballo: " << jugadores[i].caballo + 1 << "\n";
        } else {
            archivo << "Perdedor: " << jugadores[i].nombre << " - Apuesta: " << jugadores[i].apuesta << " unidades - Caballo: " << jugadores[i].caballo + 1 << "\n";
        }
    }
    archivo << "------------------------\n";
    archivo.close();
    cout << "Resultado guardado en archivo 'esultado_partida.txt'\n";
} else {
    cout << "Error al guardar resultado en archivo\n";
}



                delete[] jugadores; // Liberar memoria
                seguirJugando = jugarOtraVez();

            } while (seguirJugando);

            break;
        }
        case 2:
            system("cls");

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
            if (!volverAlMenu())
            {
                opcion = 4;
            }
            break;
        case 3:
            system("cls");

            cout << "\n";
            cout << "***************************************************************************\n";
            cout << "Has seleccionado el apartdado para ver los integrantes de SKT Telecom:\n";
            cout << "Daniel Adalberto Alvarado Flores, 00048524\n";
            cout << "Hector Ernesto Argueta Constanza, 00012424\n";
            cout << "Xavier Ernesto Garcia Villacorta, 00014624\n";
            cout << "***************************************************************************\n";
            cout << "\n";
            if (!volverAlMenu())
            {
                opcion = 4;
            }
            break;
        case 4:
            cout << "Saliendo del juego...\n";
            break;
        default:
            system("cls");
            cout << "\n";
            cout << "\n";
            cout << "ERROR###       Opcion invalida. Intente de nuevo.\n";
            cout << "\n";
            cout << "\n";
        }
    } while (opcion != 4);

    return 0;
}
