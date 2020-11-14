#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void calcularGanador(float peso, float *maxPeso, int codpescador, int *maxPescador);
void validacionHora(float *hora, int hIni, int hFin);
float buscarPesoMinimoParaEspecie(const int vEsp[], int esp, const float vPeso[]);
void validarPesoMinimoPorEspecie(const int vEsp[], const float vPeso[], int especie, float peso);
int buscarEspcie(const int vEsp[], int *esp);
int validarExisteEspecie(const int vEsp[], const char *vDescEsp, int *esp);
void registrar_capturas(int veccodespecie[], int vechora[], float vecpeso[], int *maxPescador, float *maxPeso,const int vEsp[], const char *vDescEsp,const float vPeso[],int hInicio,int hFin, int codIniPescador, int codFinPescador);
void reporte_A(float maxPeso, int maxPescador);
void validacionPescador(int *codPescador, int codIniPescador, int codFinPescador);
void ponercerovec (int vector [], int tam);
void contarCapturasporEspecies(int esp,int veccodespecie[]);
void Mostrarespeciescapturadas(int veccodespecie []);

void contarcapturasporhora(int hora, int horaInicio, int vechora[]);
int obtenertotalcapturas(int vechoras[]);
void porcentajedecapturas(int horaInicio, int vechora []);
#endif // FUNCIONES_H_INCLUDED
