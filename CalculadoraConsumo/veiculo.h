#ifndef VEICULO_H
#define VEICULO_H
 
#include "config.h"
 
struct Veiculo {
    char placa[TAM_PLACA];
    char modelo[TAM_MODELO];
    int ano;
};
 
void cadastrarVeiculo();
void listarVeiculos();
int existeVeiculo(char placa[]);
 
#endif
