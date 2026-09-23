# Calculadora de Consumo — Km/L
Sistema em linguagem C para cadastro de veículos, registro de abastecimentos e cálculo do consumo médio (quilômetros por litro), desenvolvido como trabalho prático da disciplina Linguagem e Técnicas de Programação.

# 1. Descrição do Problema
Motoristas costumam ter dificuldade em acompanhar de forma organizada quanto de combustível seus veículos consomem ao longo do tempo, o que dificulta decisões como comparar o rendimento entre veículos, identificar quedas de desempenho (possível sinal de manutenção necessária) e planejar gastos com combustível.

# 2. Solução Proposta
Um sistema de linha de comando que permite:
- Cadastrar veículos (placa, modelo, ano).
- Registrar abastecimentos (litros, valor pago, km rodado desde o último abastecimento) associados a um veículo.
- Calcular automaticamente o consumo (km/l) de cada abastecimento e a média histórica por veículo.
- Buscar o histórico de abastecimentos de um veículo pela placa.
- Persistir todos os dados em arquivos, para que fiquem disponíveis entre execuções.

# 3. Funcionalidades
| Funcionalidade | Descrição |
|---|---|
| Cadastrar veículo | Insere um novo veículo (placa, modelo, ano) no arquivo de veículos. |
| Listar veículos | Exibe todos os veículos cadastrados. |
| Registrar abastecimento | Associa litros, valor e km rodado a uma placa existente e calcula o km/l do abastecimento. |
| Consultar histórico | Busca por placa e lista todos os abastecimentos e o consumo médio do veículo. |
| Relatório geral | Exibe o veículo mais econômico e o menos econômico da frota. |
| Remover veículo | Remove um veículo e seus registros associados. |

# 4. Informações Armazenadas
Veículo:
- Placa
- Modelo
- Ano

Abastecimento:
- Placa do veículo
- Litros abastecidos
- Km rodado
- Consumo calculado (km/l)

# 5. Organização dos Arquivos do Projeto
projeto/\
├── main.c              # Menu principal e fluxo do programa\
├── config.h             # Constantes usadas no projeto\
├── veiculo.h             # Funções relacionadas a veículo\
├── veiculo.c\
├── abastecimento.h       # Funções relacionadas a abastecimento\
├── abastecimento.c\
├── dados/\
│   ├── veiculos.dat\
│   └── abastecimentos.dat\
└── README.md\

# 6. Salvamento em Arquivo
- Ao abrir o programa, os dados salvos anteriormente são carregados dos arquivos veiculos.dat e abastecimentos.dat.
- Ao sair do programa, tudo é salvo novamente nesses arquivos.
- Se o arquivo não puder ser aberto ou criado, o programa avisa o usuário com uma mensagem de erro.
- Se o usuário buscar uma placa que não existe, o programa também avisa que não encontrou nada.

# 7. Como Calcular o Consumo
consumo (km/l) = km rodado / litros abastecidos

