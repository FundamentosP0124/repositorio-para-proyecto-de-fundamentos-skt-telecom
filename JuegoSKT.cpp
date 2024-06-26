#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

#define META 50
#define NUM_CABALLOS 5

struct Jugador {
    string nombre;
    int caballo;
    int apuesta;
};

void mostrarCaballo(int posicion) {
    for (int i = 0; i < posicion; ++i) {
        cout<<" ";
    }
    cout<< "  __/>\\  \n";
    for (int i = 0; i < posicion; ++i) {
        cout << " ";
    }
    cout<< " /  _  \\ \n";
    for (int i = 0; i < posicion; ++i) {
        cout<< " ";
    }
    cout << "(' / \\-' )\n";
    for (int i = 0; i < posicion; ++i) {
        cout<< " ";
    }
    cout << " `\\   |'\n";
    for (int i = 0; i < posicion; ++i) {
        cout << " ";
    }
    cout << "   `\\  \n\n";
}

void mostrarCarrera(int posiciones[NUM_CABALLOS]) {
    system("clear");
    for (int i = 0; i < NUM_CABALLOS; ++i) {
        mostrarCaballo(posiciones[i]);
    }
}

int main() {
    srand(time(NULL));

    int numJugadores;
    cout << "Cuantos jugadores van a jugar? (Maximo 3): ";
    cin >> numJugadores;
    if (numJugadores < 1 || numJugadores > 3) {
        cout << "Numero de jugadores invalido. Debe ser entre 1 y 3.\n";
        return 1;
    }

    Jugador jugadores[numJugadores];
    int posiciones[NUM_CABALLOS] = {0};

    // Ingresar nombres y apuestas
    for (int i = 0; i < numJugadores; ++i) {
        cout<< "Jugador " << i + 1 << " ingrese su nombre: ";
        cin>> jugadores[i].nombre;
        cout << "Ingrese el numero del caballo (1-" << NUM_CABALLOS << ") en el que desea apostar: ";
        cin >> jugadores[i].caballo;
        jugadores[i].caballo--; // ajustar a índice del array
        cout << "Ingrese su apuesta: ";
        cin >> jugadores[i].apuesta;
    }

    // Carrera
    bool fin = false;
    while (!fin) {
        for (int i = 0; i < NUM_CABALLOS; ++i) {
            posiciones[i] += rand() % 3; // El caballo se mueve entre 0 y 2 posiciones
            if (posiciones[i] >= META) {
                fin = true;
            }
        }
        mostrarCarrera(posiciones);
        usleep(200000); // Pausa de 200 milisegundos
    }

    // Resultados
    int ganador = 0;
    for (int i = 1; i < NUM_CABALLOS; ++i) {
        if (posiciones[i] > posiciones[ganador]) {
            ganador = i;
        }
    }
    cout << "El caballo " << ganador + 1 << " ha ganado la carrera!\n";

    for (int i = 0; i < numJugadores; ++i) {
        if (jugadores[i].caballo == ganador) {
            cout << "¡Felicidades " << jugadores[i].nombre << "! Has ganado " << jugadores[i].apuesta * 2 << " unidades.\n";
        } else {
            cout << "Lo siento " << jugadores[i].nombre << ", has perdido tu apuesta de " << jugadores[i].apuesta << " unidades.\n";
        }
    }

    return 0;
}