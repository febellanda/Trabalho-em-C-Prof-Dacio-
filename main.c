#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char placa[20];
    char marca[100];
    char modelo[100];
    int ano;
    float consumo;
};

struct Abastecimento {
    char placa[20];
    float litros;
    float km;
    float consumo;
};

int main() {

    struct Veiculo veiculos[100];
    struct Abastecimento abastecimentos[100];

    int total_veiculos = 0;
    int total_abastecimentos = 0;
    int opcao;

    char marca[100];
    char modelo[100];
    char placa[20];

    int ano;
    float consumo;

    do {

        printf("\n========================================\n");
        printf("       SISTEMA DE CONSUMO (KM/L)        \n");
        printf("========================================\n");

        printf("1 - Cadastrar Veiculo\n");
        printf("2 - Listar Veiculos\n");
        printf("3 - Registrar Abastecimento\n");
        printf("4 - Consultar Historico por Placa\n");
        printf("0 - Sair\n");

        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("======= CADASTRO DO VEICULO ========\n");

            printf("\nInforme a marca do veiculo: \n");
            scanf(" %99[^\n]", marca);

            printf("Informe o modelo: \n");
            scanf(" %99[^\n]", modelo);

            printf("Informe a placa do Veiculo: \n");
            scanf(" %19s", placa);

            printf("Informe o ano do veiculo: ");
            scanf("%d", &ano);

            printf("Informe o consumo medio do veiculo: \n");
            scanf("%f", &consumo);

            strcpy(veiculos[total_veiculos].marca, marca);
            strcpy(veiculos[total_veiculos].modelo, modelo);
            strcpy(veiculos[total_veiculos].placa, placa);

            veiculos[total_veiculos].ano = ano;
            veiculos[total_veiculos].consumo = consumo;

            total_veiculos++;

            printf("\nVeiculo cadastrado com sucesso!\n");

        }

    } while (opcao != 0);

    return 0;

}
