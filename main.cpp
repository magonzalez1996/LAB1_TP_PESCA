#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"

int main(){
    int opcion;
    int veccodespecie[9];
    float  vechora[9], vecpeso[9];



    do{
        cls();
        setColor(WHITE);
        cout << "MENÚ PRINCIPAL" << endl;
        cout << "--------------------------------" << endl;
        cout << "1 - REGISTRAR CAPTURAS" << endl;
        cout << "2 - REPORTE A" << endl;
        cout << "3 - REPORTE B" << endl;
        cout << "4 - REPORTE C" << endl;
        cout << "5 - CREDITOS" << endl;
        cout << "--------------------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                registrar_capturas( veccodespecie, vechora, vecpeso);
            break;
            case 2:
                cout << " REPORTE A" << endl;
            break;
            case 3:
                cout << "REPORTE B" << endl;
            break;
            case 4:
                cout << "REPORTE C" << endl;
            break;
            case 5:
                cout << "CREDITOS" << endl;
            break;
            case 0:

            break;
        }
        cin.ignore();
        anykey();
    }while(opcion != 0);

    return 0;
}
