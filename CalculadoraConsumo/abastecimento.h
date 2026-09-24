#ifndef ABASTECIMENTO_H
#define ABASTECIMENTO_H
 
#include "config.h"
 
struct Abastecimento {
    char placa[TAM_PLACA];
    float litros;
    float km;
    float consumo;
};
 
void registrarAbastecimento(char placa[]);
void listarHistorico(char placa[]);
 
#endif
