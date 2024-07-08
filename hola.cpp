#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int balance;
    int betAmount;
    int numeroEscogido;
    int numeroRuleta;

    cout << "---Bienvenido al juego de la ruleta!---" << endl;
    cout << "Ingrese la cantidad de dinero que quieres agregar a tu cuenta: $";
    cin >> balance;

    system("cls");

    while (balance > 0) {
        cout << "Escoje un numero entre 1 y 20: ";
        cin >> numeroEscogido;

        while (numeroEscogido < 1 || numeroEscogido > 20) {
            cout << "Numero invalido. Por favor escoje otro numero que cumpla las condiciones: ";
            cin >> numeroEscogido;
        }

        cout << "Cuanto dinero quieres apostar en esta ocasion? $";
        cin >> betAmount;

        while (betAmount > balance || betAmount <= 0) {
            cout << "Apuesta denegada. Esta cantidad de dinero sobrepasa el que tienes en tu cuenta. Por favor ingresa un monto valido: $";
            cin >> betAmount;
        }

        numeroRuleta = rand() % 20 + 1;
        cout << "El numero ganador es: " << numeroRuleta << endl;

        if (numeroEscogido == numeroRuleta) {
            cout << "Felicidades, has ganado! No te olvides de dejar una buena propina. Tu ganancia es de: $" << betAmount * 2 << "!" << endl;
            balance += betAmount;
        } else {
            cout << "Mas suerte para la proxima! Has perdido: $" << betAmount << "." << endl;
            balance -= betAmount;
        }

        cout << "Tu balance actual es: $" << balance << endl;
        char choice;
        cout << "Quieres seguir jugando? (s/n): ";
        cin >> choice;

        if (choice != 's' && choice != 'S') {
            break;
        }
        system("cls");
    }

    


    cout << "Gracias por jugar! Tu balance final es de: $" << balance << endl;
    return 0;
}
