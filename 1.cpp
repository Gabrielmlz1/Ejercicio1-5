#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int obtenerEleccionJugador() {
    int eleccion;
    cout << "Elige una opcion (0 = Piedra, 1 = Papel, 2 = Tijeras): ";
    cin >> eleccion;
    while (eleccion < 0 || eleccion > 2) {
        cout << "Opcion invalida. Intenta de nuevo: ";
        cin >> eleccion;
    }
    return eleccion;
}

int obtenerEleccionComputadora() {
    return rand() % 3;
}

string mostrarEleccion(int eleccion) {
    switch(eleccion) {
        case 0: return "Piedra";
        case 1: return "Papel";
        case 2: return "Tijeras";
        default: return "Desconocido";
    }
}

string determinarGanador(int eleccionJugador, int eleccionComputadora) {
    if (eleccionJugador == eleccionComputadora) {
        return "Empate";
    } else if ((eleccionJugador == 0 && eleccionComputadora == 2) || 
               (eleccionJugador == 1 && eleccionComputadora == 0) || 
               (eleccionJugador == 2 && eleccionComputadora == 1)) {
        return "Jugador";
    } else {
        return "Computadora";
    }
}

int main() {

    int menu = 0;
    int menu2 = 0;
    bool continuar = true;
    bool continuar2 = true;
    string nombre[100] = {};
    string usuario[100] = {};
    string contrasena[100] = {};
    int indiceUsuario = 0;
    string usuarioTemporal = "";
    string contrasenaTemporal = "";
    bool inicioSesion = false;
    const int NUM_PARTIDAS = 3;
    int resultados[NUM_PARTIDAS][2];

    do {
        cout << endl << endl << "--- BIENVENIDO AL SISTEMA DE REGISTRO E INICIO DE SESION DEL CASINO ---" << endl << endl;
        cout << "1.) Inicio de sesion \n2.) Registro \n3.) Salir \n";
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "Ingresa tu nombre de usuario: ";
            cin >> usuarioTemporal;
            for (int i = 0; i < 100; i++) {
                if (usuarioTemporal == usuario[i]) {
                    do {
                        cout << "Ingrese la contrasena: ";
                        cin >> contrasenaTemporal;
                        if (contrasenaTemporal == contrasena[i]) {
                            inicioSesion = true;
                            break;
                        } else {
                            cout << "Contrasena incorrecta. \n";
                        }
                    } while (true);
                }
            }

            if (!inicioSesion) {
                cout << "El usuario no existe!\n";
            }

            if (inicioSesion) {
                do {
                    system("cls");
                    cout << "---Bienvenido al casino, elige tu juego y empieza a divertirte!---\n  1.) Ruleta de la suerte.\n 2. Piedra, Papel o Tijeras.\n 3. Salir." << endl;
                    cin >> menu2;

                    switch (menu2) {
                    case 1:
                        cout << "RULETA DE LA SUERTE\n";
                        break;

                    case 2:
                        system("cls");

                        srand(static_cast<unsigned int>(time(0)));

                        cout << "Bienvenido al juego de Piedra, Papel o Tijeras!" << endl;

                        for (int i = 0; i < NUM_PARTIDAS; ++i) {
                            int eleccionJugador = obtenerEleccionJugador();
                            int eleccionComputadora = obtenerEleccionComputadora();

                            resultados[i][0] = eleccionJugador;
                            resultados[i][1] = eleccionComputadora;

                            cout << "Jugador elige: " << mostrarEleccion(eleccionJugador) << endl;
                            cout << "Computadora elige: " << mostrarEleccion(eleccionComputadora) << endl;
                            cout << "Ganador: " << determinarGanador(eleccionJugador, eleccionComputadora) << endl << endl;
                        }

                        cout << "Resultados de las partidas:" << endl;
                        for (int i = 0; i < NUM_PARTIDAS; ++i) {
                            cout << "Partida " << i + 1 << ": Jugador (" << mostrarEleccion(resultados[i][0])
                                << ") vs Computadora (" << mostrarEleccion(resultados[i][1]) << ") - ";
                            cout << "Ganador: " << determinarGanador(resultados[i][0], resultados[i][1]) << endl;
                        }
                        break;

                    case 3:
                        continuar2 = false;
                        break;

                    default:
                        cout << "Opcion no valida. \n";
                        break;
                    }
                } while (continuar2);
            }
            break;

        case 2:
            cout << "Ingrese nombre de usuario: ";
            cin >> usuario[indiceUsuario];
            cout << "Ingrese contrasena: ";
            cin >> contrasena[indiceUsuario];
            indiceUsuario++;
            break;

        case 3:
            continuar = false;
            break;

        default:
            cout << "Opcion no valida.\n";
            break;
        }
    } while (continuar);

    return 0;

}