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
void validacionHora(float *hora, int hIni, int hFin){
    while (*hora < hIni || *hora > hFin){
        cout<<"la hora es invalida, el rango de horario es de "<< hIni << "am a "<< hFin << "pm.\n";
        cout << "Ingrese hora de captura nuevamente" << endl;
        cin>>*hora;
    }
}

float buscarPesoMinimoParaEspecie(const int vEsp[], int esp, const float vPeso[]){
    int indiceEnDondeSeEncuentraElPesoDeLaEspecie = 0;
    for(int i = 0; i < 9; i++){
        if(vEsp[i] == esp){
            indiceEnDondeSeEncuentraElPesoDeLaEspecie = i;
            break;
        }
    }            
    return vPeso[indiceEnDondeSeEncuentraElPesoDeLaEspecie];
}
void validarPesoMinimoPorEspecie(const int vEsp[], const float vPeso[], int especie, float peso){
    float minimo = buscarPesoMinimoParaEspecie(vEsp, especie, vPeso);
    while (peso < minimo){
        cout<<"el peso es invalido, el peso debe ser mayor a " << minimo << endl;
        cout << "Ingrese peso nuevamente" << endl;
        cin>>peso;
    }
}

int buscarEspcie(const int vEsp[], int *esp){
	for(int i = 0; i < 9; i++){
        if(vEsp[i] == *esp){
            return i;
            break;
        }
    }
    return -1;
}
int validarExisteEspecie(const int vEsp[], const char *vDescEsp, int *esp){
    int exist = buscarEspcie(vEsp, esp);
	
	while (exist == -1){
        cout<<"la especie ingresada no es valida.\nLos codigos de especie permitidos son: 10, 20, 30, 40, 50, 60, 70, 80, 90" << endl;
        cout << "Ingrese especie nuevamente" << endl;
        cin>>*esp;
        validarExisteEspecie(vEsp, vDescEsp, esp);
	}
//	if(exist != -1){
//		cout << " - "  vDescEsp[exist] << endl;
//	}
}

void registrar_capturas(int veccodespecie[], float vechora[], float vecpeso[], int *maxPescador, float *maxPeso,const int vEsp[], const char *vDescEsp,const float vPeso[],int hInicio,int hFin, int codIniPescador, int codFinPescador){
    int codpescador,codespecie;
    float hora, peso;
    cls();
    cout << "CARGA DE CAPTURAS" << endl;
    cout << "---------------------------" << endl;
    cout << "Codigo de pescador" << endl;
    cin>>codpescador;
    //validacionPescador(codPescador, codIniPescador, codFinPescador);
    
    while( codpescador!=0){
        cout << "Codigo de especie" << endl;
        cin>>codespecie;
        //no funciona bien
        validarExisteEspecie(vEsp, vDescEsp, &codespecie);
        
        cout << "Hora de captura" << endl;
        cin>>hora;
        validacionHora(&hora, hInicio, hFin);

        cout << "Kilogramos del pez" << endl;
        cin>>peso;
        validarPesoMinimoPorEspecie(vEsp, vPeso, codespecie, peso);

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

