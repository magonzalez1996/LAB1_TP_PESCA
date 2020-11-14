#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "funciones.h"

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
int validarExisteEspecie(const int vEsp[], const char *vDescEsp, int *esp, int *exist){
    *exist = buscarEspcie(vEsp, esp);
    

	while (*exist == -1){
        cout<<"la especie ingresada no es valida.\nLos codigos de especie permitidos son: 10, 20, 30, 40, 50, 60, 70, 80, 90" << endl;
        cout << "Ingrese especie nuevamente" << endl;
        cin>>*esp;
        validarExisteEspecie(vEsp, vDescEsp, esp, exist);
	}
//	if(exist != -1){
//		cout << " - "  vDescEsp[exist] << endl;
//	}
}
void ponercerovec (int vector[], int tam){
	int i=0;
	for (i; i<tam;i++){
		vector[i]=0;
	}
}
 
void contarCapturasporEspecies (int esp,int vecespecies[]){
	int indice= esp/10-1;
	vecespecies[indice]++;
}


void registrar_capturas(int veccodespecie[], int vechora[], float vecpeso[], int *maxPescador, float *maxPeso,const int vEsp[], const char *vDescEsp,const float vPeso[],int hInicio,int hFin, int codIniPescador, int codFinPescador){
    int codpescador,codespecie, exist = -1;
    float hora, peso;
    cls();
    cout << "CARGA DE CAPTURAS" << endl;
    cout << "---------------------------" << endl;
    cout << "Codigo de pescador" << endl;
    cin>>codpescador;
    validacionPescador(&codpescador, codIniPescador, codFinPescador);

    while( codpescador!=0){
        cout << "Codigo de especie" << endl;
        cin>>codespecie;
        validarExisteEspecie(vEsp, vDescEsp, &codespecie, &exist);

        cout << "Hora de captura" << endl;
        cin>>hora;
        validacionHora(&hora, hInicio, hFin);

        cout << "Peso del pez (Ejemplo: Kg.grs = 0.5 Kg)" << endl;
        cin>>peso;
        validarPesoMinimoPorEspecie(vEsp, vPeso, codespecie, peso);

        calcularGanador(peso, maxPeso, codpescador, maxPescador);
        
        contarCapturasporEspecies(codespecie,veccodespecie);
        
        contarcapturasporhora(hora, hInicio, vechora);

        cout << "---------------------------" << endl;
        cout << "Codigo de pescador" << endl;
        cin>>codpescador;
    }
}
void Mostrarespeciescapturadas(int veccodesp[]){
     int i;
	 for(i=0;i<9;i++){
	 	cout<<"La especie:"<< (i+1)*10 << "  fue capturada:" << veccodesp [i] << endl;
	 }
}

void reporte_A(float maxPeso, int maxPescador){
    if(maxPescador != 0){
        cout << "el pescador ganador es: " << maxPescador << " con un total de " << maxPeso << endl ;
    }else{
        cout << "aun no hay registros para calcula un pescador ganador" << endl ;
    }
}

void validacionPescador(int *codPescador, int codIniPescador, int codFinPescador){
	 while (*codPescador < codIniPescador || *codPescador > codFinPescador){
        cout<<"El codigo ingreado es invalido, el rango es de "<< codIniPescador << " A "<< codFinPescador<<endl;
        cout << "Ingrese el codigo de paticipante nuevamente" << endl;
        cin>>*codPescador;
    }	
}

void contarcapturasporhora(int hora, int horaInicio, int vechora[]){
	 vechora[hora - horaInicio]++;
}

int obtenertotalcapturas(int vechoras[]){
	int total = 0;
	for(int i = 0; i <= 17; i ++){
		total += vechoras[i];
	}
	return total;
}

void porcentajedecapturas(int horaInicio, int vechora []){
	int total = obtenertotalcapturas(vechora);
	for(int i=0; i <= 17; i++){
		float porcentaje  = vechora[i] * 100 / total;
		cout << "En la hora " << i+horaInicio << " el porcentaje de capturas es: " << porcentaje << endl;
	}
}

#include "funciones.h"
