#include <stdio.h>
#include <string.h>
#include "abastecimento.h"
 
void registrarAbastecimento(char placa[])
{
    struct Abastecimento a;
    strcpy(a.placa, placa);
 
    printf("Litros abastecidos: ");
    scanf("%f", &a.litros);
 
    printf("Km rodado desde o ultimo abastecimento: ");
    scanf("%f", &a.km);
 
    a.consumo = a.km / a.litros;
 
    FILE *arq = fopen(ARQ_ABASTECIMENTOS, "a");
 
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de abastecimentos.\n");
        return;
    }
 
    fprintf(arq, "%s %.2f %.2f %.2f\n", a.placa, a.litros, a.km, a.consumo);
    fclose(arq);
 
    printf("Abastecimento registrado! Consumo: %.2f km/l\n", a.consumo);
}
 
void listarHistorico(char placa[])
{
    FILE *arq = fopen(ARQ_ABASTECIMENTOS, "r");
 
    if (arq == NULL) {
        printf("Nenhum abastecimento encontrado para essa placa.\n");
        return;
    }
 
    struct Abastecimento a;
    int encontrou = 0;
    float somaConsumo = 0;
    int quantidade = 0;
 
    while (fscanf(arq, "%7s %f %f %f", a.placa, &a.litros, &a.km, &a.consumo) == 4) {
        if (strcmp(a.placa, placa) == 0) {
            printf("Litros: %.2f | Km: %.2f | Consumo: %.2f km/l\n",
                   a.litros, a.km, a.consumo);
 
            somaConsumo = somaConsumo + a.consumo;
            quantidade = quantidade + 1;
            encontrou = 1;
        }
    }
 
    fclose(arq);
 
    if (encontrou == 0) {
        printf("Nenhum abastecimento encontrado para essa placa.\n");
        return;
    }
 
    printf("Consumo medio: %.2f km/l\n", somaConsumo / quantidade);
}
