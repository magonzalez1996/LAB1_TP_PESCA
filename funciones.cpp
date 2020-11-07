#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"

void registrar_capturas(int veccodespecie[], float vechora[], float vecpeso[]){
int codpescador,codespecie;
float hora, peso;
cls();
cout << "CARGA DE CAPTURAS" << endl;
cout << "---------------------------" << endl;
cout << "Codigo de pescador" << endl;
cin>>codpescador;
while( codpescador!=0){
    cout << "Codigo de especie" << endl;
    cin>>codespecie;
    cout << "Hora de captura" << endl;
    cin>>hora;
    cout << "Kilogramos del pez" << endl;
    cin>>peso;
    cout << "---------------------------" << endl;
    cout << "Codigo de pescador" << endl;
    cin>>codpescador;
}
}


#include "funciones.h"
