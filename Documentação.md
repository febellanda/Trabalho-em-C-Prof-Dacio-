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
