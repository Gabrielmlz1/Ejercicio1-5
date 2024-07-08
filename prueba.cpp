#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void opciones(int jugador, int compu);

void opciones(int jugador, int compu) {
    if (jugador == compu) {
        cout << "Es un empate!\n";
    } else if ((jugador == 1 && compu == 3) ||
               (jugador == 2 && compu == 1) ||
               (jugador == 3 && compu == 2)) {
        cout << "Ganaste!\n";
    } else {
        cout << "La computadora gana!\n";
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

    do {
        system("cls");
        cout << "--- BIENVENIDO AL SISTEMA DE REGISTRO E INICIO DE SESION DEL CASINO ---" << endl << endl;
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
                    cout << "--- Bienvenido al arcade, elige tu juego y empieza a divertirte! ---\n 1.) Ruleta de la suerte.\n 2.) Piedra, Papel o Tijeras.\n 3.) Salir." << endl;
                    cin >> menu2;

                    switch (menu2) {
                    case 1:
                        cout << "RULETA DE LA SUERTE\n";
                        break;

                    case 2: {
                        bool jugarOtraVez = true;
                        do {
                            system("cls");

                            srand(static_cast<unsigned int>(time(nullptr)));

                            int seleccionjugador;

                            cout << "--- Bienvenido a Piedra Papel o Tijera! ---" << endl << endl;
                            cout << "Piensa en una opcion para jugar" << endl;
                            cout << "1. Piedra ";
                            cout << "2. Papel ";
                            cout << "3. Tijera ";
                            cin >> seleccionjugador;

                            system("cls");

                            if (seleccionjugador < 1 || seleccionjugador > 3) {
                                cout << "Opcion no valida" << endl;
                                break;
                            }

                            cout << "Turno de la computadora" << endl;
                            int seleccioncomputadora = rand() % 3 + 1;

                            cout << "Tu elegiste: ";
                            if (seleccionjugador == 1) cout << "Piedra" << endl;
                            else if (seleccionjugador == 2) cout << "Papel" << endl;
                            else if (seleccionjugador == 3) cout << "Tijera" << endl;

                            cout << "Y la computadora elige... " << endl;

                            cout << endl;
                            
                            system("pause");

                            cout << endl;

                            if (seleccioncomputadora == 1) cout << "Piedra!" << endl;
                            else if (seleccioncomputadora == 2) cout << "Papel!" << endl;
                            else if (seleccioncomputadora == 3) cout << "Tijeras!" << endl;

                            opciones(seleccionjugador, seleccioncomputadora);

                            char respuesta;
                            cout << "Quieres jugar otra vez? (s/n): ";
                            cin >> respuesta;
                            jugarOtraVez = (respuesta == 's' || respuesta == 'S');
                        } while (jugarOtraVez);
                        break;
                    }

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
            cout << "Ingresa tu nombre de usuario: ";
            cin >> usuario[indiceUsuario];
            cout << "Ingresa tu contrasena: ";
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



