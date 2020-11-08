#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"

int main(){
    int opcion;
    int veccodespecie[9], maxPescador = 0, horaInicio = 6, horaFin = 23, minCodPescador = 100, maxCodPescador = 114;
    float vechora[horaFin-horaInicio], vecpeso[9], maxPeso = 0;

    //Tabla Comparativa de datos del torneo
    const int vMasterCodEsp[9] = {10,20,30,40,50,60,70,80,90};
    const char *vMasterNomEsp[9] = { "Anchoa", "Pejerrey", "Bagre", "Boga", "Caballa", "Carpa", "Trucha patagonica", "Dorado", "Lisa" };
    const float vMasterPesoMin[9] = {500,2,4,5,1,5,1.5,3,2.5};

    do{
        cls();
        setColor(LIGHTBLUE);
        cout << "MENU PRINCIPAL" << endl;
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
                registrar_capturas( veccodespecie, vechora, vecpeso, &maxPescador, &maxPeso, vMasterCodEsp, *vMasterNomEsp, vMasterPesoMin, horaInicio, horaFin);
            break;
            case 2:
                cout << " REPORTE A" << endl;
                reporte_A(maxPeso, maxPescador);
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
