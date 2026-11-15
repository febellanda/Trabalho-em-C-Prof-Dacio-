#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char placa[20];
    char marca[100];
    char modelo[100];
    int ano;
};

struct Abastecimento {
    char placa[20];
    float litros;
    float km;
    float consumo;
};

struct Veiculo veiculos[100];
struct Abastecimento abastecimentos[100];
int total_veiculos = 0; 

void cadastroVeiculo(){
	char marca[100];
    char modelo[100];
    char placa[20];
    int ano;
	
	printf("======= CADASTRO DO VEICULO ========\n");

    printf("\nInforme a marca do veiculo: \n");
    scanf(" %99[^\n]", marca);

    printf("Informe o modelo: \n");
    scanf(" %99[^\n]", modelo);

    printf("Informe a placa do Veiculo: \n");
    scanf(" %19s", placa);

    printf("Informe o ano do veiculo: ");
    scanf("%d", &ano);

    strcpy(veiculos[total_veiculos].marca, marca);
    strcpy(veiculos[total_veiculos].modelo, modelo);
    strcpy(veiculos[total_veiculos].placa, placa);

    veiculos[total_veiculos].ano = ano;

    total_veiculos++;

    printf("\nVeiculo cadastrado com sucesso!\n");

}

void listarVeiculo(){
	char marca[100];
    char modelo[100];
    char placa[20];
    int ano, i;
    
	for(i=0; i<total_veiculos; i++){
		printf("Veiculo: \n%c \n%c", marca[i], modelo[i]);
	} 
}

int main() {
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
			cadastroVeiculo();
        } else if(opcao == 2) {
        	listarVeiculo();
			
		} else if (opcao == 3) {
			printf("Informe a placa do veiculo: \n");
			scanf("%d", &placa3);
			
			if (placa3 == placa[20]) {
				printf("Informe a quantidade de litros abastecidos: \n");
				scanf("%f", &litros);
				
				printf("Informe a quantidade de KM rodados: \n");
				scanf("%d", &KM_rod);
				
				consumo = (KM_rod / litros);
				
				printf("O consumo médio do seu veiculo é de: %.2f", consumo); 
			} else {

    } while (opcao != 0);

    return 0;

}
