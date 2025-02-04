# Controle de LEDs com Botão - Wokwi

## Autor
**Kauan Souza Teles**

## Descrição
Este projeto implementa um sistema de controle de LEDs utilizando um botão na Raspberry Pi Pico. Quando o botão é pressionado, os LEDs azul, vermelho e verde são acesos simultaneamente e depois são desligados sequencialmente a cada 3 segundos. O código foi testado e executado no simulador [Wokwi](https://wokwi.com/).

## Componentes Utilizados
- Raspberry Pi Pico
- LED azul (conectado ao pino 11)
- LED vermelho (conectado ao pino 12)
- LED verde (conectado ao pino 13)
- Botão (conectado ao pino 5)

## Funcionamento
1. Inicializa os pinos de saída para os LEDs e o pino de entrada para o botão com pull-up ativado.
2. No loop principal:
   - Verifica se o botão foi pressionado.
   - Se pressionado, acende os três LEDs e inicia um temporizador para desligá-los sequencialmente.
3. A função `turn_off_callback`:
   - Desliga primeiro o LED azul e inicia um novo temporizador.
   - Em seguida, desliga o LED vermelho após mais 3 segundos.
   - Por fim, desliga o LED verde e redefine o estado.

## Como Executar no Wokwi
1. Abra o projeto no vscode
2. Use a extensão do Wokwi do vscode
3. Compile o codigo fonte
4. Execute o diagrama que está no arquivo diagram.json
