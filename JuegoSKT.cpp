#include <iostream>
using namespace std;
int main(){

  for (int i = 0; i < numJugadores; ++i) {
        cout<< "Jugador " << i + 1 << " ingrese su nombre: ";
        cin>> jugadores[i].nombre;
        cout << "Ingrese el numero del caballo (1-" << NUM_CABALLOS << ") en el que desea apostar: ";
        cin >> jugadores[i].caballo;
        jugadores[i].caballo--; // ajustar a índice del array
        cout << "Ingrese su apuesta: ";
        cin >> jugadores[i].apuesta;
    }

void mostrarReglas()
{
    cout << "\nReglas del Juego:\n";
    cout << "1. Cada jugador apuesta por uno de los " << NUM_CABALLOS << " caballos.\n";
    cout << "2. El primer caballo en alcanzar la meta (META = " << META << ") gana la carrera.\n";
    cout << "3. Si el caballo por el que apostaste gana, tu apuesta se duplica.\n";
    cout << "4. Si el caballo por el que apostaste pierde, pierdes tu apuesta.\n\n";
}





  
}

