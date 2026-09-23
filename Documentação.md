# Calculadora de Consumo (Km/L)

## 1. Descrição do Sistema

O projeto consiste em um sistema para controle de consumo de combustível de veículos, desenvolvido em linguagem C. O sistema permitirá o cadastro de veículos e o registro dos abastecimentos realizados por cada um, calculando automaticamente o consumo (km/l) de cada abastecimento e o consumo médio do veículo. O programa utilizará arquivos de texto para persistência de dados, garantindo que as informações de veículos e abastecimentos não sejam perdidas ao fechar a aplicação.

O foco principal é resolver a problemática do controle manual (ou inexistente) do consumo de combustível, automatizando o cálculo do rendimento e permitindo consultar rapidamente o histórico de um veículo pela placa.

## 2. Fluxo de Utilização Esperado para o Sistema

1. Ao iniciar o programa, o usuário visualizará um menu principal com as opções:
   * `1. Cadastrar Veículo`
   * `2. Listar Veículos`
   * `3. Registrar Abastecimento`
   * `4. Consultar Histórico por Placa`
   * `0. Sair`
2. Caso o usuário escolha `1`, o sistema solicitará Placa, Modelo e Ano. Em seguida, gravará esses dados no arquivo `veiculos.txt`.
3. Se escolher `3`, o sistema pedirá a placa do veículo. O programa verificará se a placa já está cadastrada e, em caso positivo, solicitará os litros abastecidos e o km rodado, calculará o consumo (km/l) e registrará o abastecimento no arquivo `abastecimentos.txt`.
4. Se escolher `4`, o sistema pedirá a placa do veículo e mostrará todos os abastecimentos já registrados para ela, junto com o consumo médio calculado.
5. As operações de erro (ex: veículo não encontrado, arquivo que não pôde ser aberto, busca sem resultado) exibirão mensagens claras e retornarão o usuário ao menu principal.

## 3. Fluxograma da Lógica do Sistema




## 4. Estrutura de Dados

O sistema utilizará as seguintes estruturas heterogêneas para gerenciar as informações:

```c
// Estrutura para armazenamento dos Veículos
struct Veiculo {
    char placa[8];
    char modelo[50];
    int ano;
};

// Estrutura para armazenamento dos Abastecimentos
struct Abastecimento {
    char placa[8];      // placa do veiculo que abasteceu
    float litros;        // litros abastecidos
    float km;            // km rodado desde o ultimo abastecimento
    float consumo;        // km / litros, calculado pelo programa
};
```

Cada veículo cadastrado é gravado como uma linha no arquivo `veiculos.txt`, e cada abastecimento como uma linha no arquivo `abastecimentos.txt`, relacionado ao veículo através do campo `placa`.
