#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;

void calcularGanador(float peso, float *maxPeso, int codpescador, int *maxPescador){
    if (peso>*maxPeso){
        *maxPeso=peso;
        *maxPescador=codpescador;
    }
}
void ValidacionHora(float hora){
	while(hora < 6 || hora > 23){
        cout<<"la hora es invalida, el rango de horario es de 6am a 23pm" << endl;
        cout << "Ingrese hora de captura nuevamente" << endl;
        cin>>hora;
    }
}
void registrar_capturas(int[], float[], float[]);void registrar_capturas(int veccodespecie[], float vechora[], float vecpeso[], int *maxPescador, float *maxPeso){
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
        ValidacionHora(hora);

        cout << "Kilogramos del pez" << endl;
        cin>>peso;

        calcularGanador(peso, maxPeso, codpescador, maxPescador);

        cout << "---------------------------" << endl;
        cout << "Codigo de pescador" << endl;
        cin>>codpescador;
    }
}

void reporte_A(float maxPeso, int maxPescador){
    if(maxPescador != 0){
        cout << "el pescador ganador es: " << maxPescador << " con un total de " << maxPeso << endl ;
    }else{
        cout << "aun no hay registros para calcula un pescador ganador" << endl ;
    }
}



#endif // FUNCIONES_H_INCLUDED
