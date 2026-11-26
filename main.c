#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adicionamos a String.h para que possamos usar as funções strcpy e strcmp

struct Veiculo { //Struct é uma estrutura para armazenarmos varias informações dentro de uma mesma variavel
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
	float valorLitro;
    float valorTotal;
};

struct Veiculo veiculos[100]; // Veiculos é o indice da estrutura, e veiculos é o nome da variavel que desejamos usar
struct Abastecimento abastecimentos[100];
int total_veiculos = 0; 
int total_abastecimentos = 0;

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

    strcpy(veiculos[total_veiculos].marca, marca); // strcpy serve para copiar as informações que o usuario digitiar e salvar a mesma
    strcpy(veiculos[total_veiculos].modelo, modelo);
    strcpy(veiculos[total_veiculos].placa, placa);

    veiculos[total_veiculos].ano = ano;

    total_veiculos++; // incremento para que sempre o um novo veiculo seja somado

	printf("\n================================\n");
    printf("       CADASTRO CONCLUIDO!\n");
    printf("================================\n");

    printf("\n===== DADOS DO PROJETO =====\n");
    printf("Marca do veiculo: %s\n", veiculos[total_veiculos - 1].marca); // total_veiculos - 1] serve para acessarmos a ultima informação salva
    printf("Modelo: %s\n", veiculos[total_veiculos - 1].modelo);
    printf("Placa: %s\n", veiculos[total_veiculos - 1].placa);
    printf("ano: %d \n", veiculos[total_veiculos - 1].ano);

    printf("\nVeiculo cadastrado com sucesso!\n");
}

void listarVeiculo(){
    int i;
    
    printf("\n========VEICULOS CADASTRADOS=======\n");
	for(i=0; i<total_veiculos; i++){
		printf("Veiculo: \n%s %s \n%s \n%d", veiculos[i].marca, veiculos[i].modelo, veiculos[i].placa, veiculos[i].ano);
		printf("\n================================\n");
	}
}

void registrarAbastecimento(){
    float litros, KM_rod, consumo;
    float valorLitro, valorTotal;
	char placa3[20];
	int i;
	int encontrado = 0;
	
	printf("Informe a placa do veiculo: \n");
	scanf("%19s", placa3);

	for(i=0; i<total_veiculos; i++){
		if (strcmp(placa3, veiculos[i].placa) == 0) {
			
			encontrado = 1;

			printf("Informe a quantidade de litros abastecidos: \n");
			scanf("%f", &litros);
				
			printf("Informe a quantidade de KM rodados: \n");
			scanf("%f", &KM_rod);

			printf("Informe o valor do litro do combustivél: \n");
			scanf("%f", &valorLitro);
		
		
			valorTotal = (litros * valorLitro);
			consumo = (KM_rod / litros);

			strcpy(abastecimentos[total_abastecimentos].placa, placa3);
			abastecimentos[total_abastecimentos].litros = litros;
			abastecimentos[total_abastecimentos].km = KM_rod;
			abastecimentos[total_abastecimentos].consumo = consumo;
			abastecimentos[total_abastecimentos].valorLitro = valorLitro;
			abastecimentos[total_abastecimentos].valorTotal = valorTotal;
			total_abastecimentos++;
					
			printf("O consumo médio do seu veiculo é de: %.2f Km/L\n", consumo); 
			printf("O valor gasto durante o trajeto e de: %.2f \n", valorTotal );
			
			break;
		} 
		} 
		if(encontrado == 0){
    printf("Placa nao encontrada! Cadastre o veiculo pelo menu principal.\n");
}
		}
		
	}

void consultarHistorico(){
    char placaBusca[20];
    int i;
    int qtdEncontrada = 0;
    float somaConsumo = 0;

    printf("Informe a placa do veiculo: \n");
    scanf(" %19s", placaBusca);

    for(i=0; i<total_abastecimentos; i++){
        if (strcmp(placaBusca, abastecimentos[i].placa) == 0) {
            printf("\n================================\n");
            printf("Litros: %.2f\n", abastecimentos[i].litros);
            printf("KM rodados: %.2f\n", abastecimentos[i].km);
            printf("Consumo: %.2f Km/L\n", abastecimentos[i].consumo);
            printf("Valor do litro: R$ %.2f\n", abastecimentos[i].valorLitro);
			printf("Valor total: R$ %.2f\n", abastecimentos[i].valorTotal);
			
            somaConsumo = somaConsumo + abastecimentos[i].consumo;
            qtdEncontrada++;
        }
    }

    if (qtdEncontrada > 0) {
        printf("\n================================\n");
        printf("Consumo medio do veiculo: %.2f Km/L\n", somaConsumo / qtdEncontrada);
        printf("================================\n");
    } else {
        printf("Nenhum abastecimento encontrado para esta placa!\n");
    }
}
void relatorioGeral() {
    int i;
    float somaLitros = 0, somaKm = 0, mediaGeral = 0;
    int indiceMelhor = 0, indicePior = 0;

    printf("\n======= RELATORIO GERAL DA FROTA =======\n");
    printf("Total de veiculos cadastrados: %d\n", total_veiculos);
    printf("Total de abastecimentos registrados: %d\n", total_abastecimentos);

    if (total_abastecimentos == 0) {
        printf("\nNenhum abastecimento registrado ainda para calcular medias.\n");
        printf("========================================\n");
        return;
    }

    for (i = 0; i < total_abastecimentos; i++) {
        somaLitros += abastecimentos[i].litros;
        somaKm += abastecimentos[i].km;

        if (abastecimentos[i].consumo > abastecimentos[indiceMelhor].consumo) {
            indiceMelhor = i;
        }
        if (abastecimentos[i].consumo < abastecimentos[indicePior].consumo) {
            indicePior = i;
        }
    }

    mediaGeral = somaKm / somaLitros;

    printf("Total de KM rodados: %.2f Km\n", somaKm);
    printf("Total de combustivel gasto: %.2f Litros\n", somaLitros);
    printf("Consumo medio geral: %.2f Km/L\n", mediaGeral);
    printf("----------------------------------------\n");
    printf("Melhor consumo: Placa %s (%.2f Km/L)\n", 
           abastecimentos[indiceMelhor].placa, abastecimentos[indiceMelhor].consumo);
    printf("Pior consumo:   Placa %s (%.2f Km/L)\n", 
           abastecimentos[indicePior].placa, abastecimentos[indicePior].consumo);
    printf("========================================\n");
}
int main() {
    int opcao;

    do {

        printf("\n========================================\n");
        printf("       SISTEMA DE CONSUMO (KM/L)        \n");
        printf("========================================\n");

        printf("1 - Cadastrar Veiculo\n");
        printf("2 - Listar Veiculos\n");
        printf("3 - Registrar Abastecimento\n");
        printf("4 - Consultar Historico por Placa\n");
		printf("5 - relatorio geral da Frota\n"); 
        printf("0 - Sair\n");

        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
			cadastroVeiculo();
        } else if (opcao == 2) {
        	listarVeiculo();
		} else if (opcao == 3) {
			registrarAbastecimento();
		} else if (opcao == 4) {
			consultarHistorico();
		} else if (opcao == 5){
		    relatorioGeral();
		} else if (opcao == 0 ){
			printf("Encerrando o sistema...\n");
		} else {
			printf("Opcao invalida!");
		}

	}while (opcao != 0);

    return 0;

}
