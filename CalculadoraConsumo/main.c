#include <stdio.h>
#include "config.h"
#include "veiculo.h"
#include "abastecimento.h"

int main()
{
    int opcao;
    char placa[TAM_PLACA];

    do {
        printf("\n===== CALCULADORA DE CONSUMO (KM/L) =====\n");
        printf("1 - Cadastrar veiculo\n");
        printf("2 - Listar veiculos\n");
        printf("3 - Registrar abastecimento\n");
        printf("4 - Consultar historico por placa\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrarVeiculo();
        }
        else if (opcao == 2) {
            listarVeiculos();
        }
        else if (opcao == 3) {
            printf("Digite a placa do veiculo: ");
            scanf("%7s", placa);

            if (existeVeiculo(placa) == 1) {
                registrarAbastecimento(placa);
            } else {
                printf("Veiculo nao encontrado! Cadastre-o primeiro.\n");
            }
        }
        else if (opcao == 4) {
            printf("Digite a placa do veiculo: ");
            scanf("%7s", placa);
            listarHistorico(placa);
        }
        else if (opcao == 0) {
            printf("Encerrando...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
