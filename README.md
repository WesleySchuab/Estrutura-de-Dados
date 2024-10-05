# Estrutura de Dados: Jogo Batalha Naval

## Descrição

Este projeto implementa o clássico jogo Batalha Naval utilizando a linguagem C++. O objetivo é simular um jogo entre dois jogadores (neste caso, duas CPUs) e demonstrar a aplicação de estruturas de dados para representar o tabuleiro e as posições dos navios.
## Formato das Embarcações
![image](https://github.com/user-attachments/assets/d83a9d31-782c-40ee-8959-929e4f753843)

## Link para Compilar

* **Opção 1:** https://www.onlinegdb.com/online_c++_compiler
* **Opção 2:** https://www.programiz.com/cpp-programming/online-compiler/

## Funcionamento
### Player x Player

1. **Inicialização:** O programa inicializa dois tabuleiros, um para cada jogador, o Jogador deve então escolher as posições que deseja posicionar suas embarcações passando as coordenadas em uma combinação onde a letra e a linha e o numero a coluna.
2. **Rodadas:** Em cada rodada, os jogadores alternam seus turnos, escolhendo uma coordenada para atacar.
3. **Verificação de Acerto:** O programa verifica se a coordenada escolhida contém um navio. Caso sim, o navio é atingido, caso não a posição com água é marcada para que o jogador não volte atirar no mesmo lugar.
4. **Fim de Jogo:** O jogo termina quando todos os navios de um jogador forem afundados.

### CPU x CPU
1. **Inicialização:** O programa inicializa dois tabuleiros, um para cada jogador, e posiciona os navios aleatoriamente.
2. **Rodadas:** Em cada rodada, os jogadores alternam seus turnos, escolhendo uma coordenada para atacar.
3. **Verificação de Acerto:** O programa verifica se a coordenada escolhida contém um navio. Caso sim, o navio é atingido.
4. **Fim de Jogo:** O jogo termina quando todos os navios de um jogador forem afundados.

## Estruturas de Dados Utilizadas

* **Matriz:** De tamnho 15 x 15. Utilizada para representar o tabuleiro de jogo, onde cada elemento indica se há um navio naquela posição ou não.
* **Estrutura:** Foi utilizado uma letra diferente para carda tipo de embarcação sendo: S submarino, H hidroavião, E encoraçãdo, P portaavião e C cruzado.

## Algoritmos

* ** Foi utilizada a técnica de POO Programação Orientada a Objeto, aplicando conceitos como classe, herança, contrutor entre outros.
* **Posicionamento Aleatório dos Navios:** Implementado utilizando um gerador de números aleatórios para escolher as coordenadas iniciais dos navios e verificar se a posição é válida (não sobrepõe outros navios).
* **Verificação de Acerto:** Implementado percorrendo a matriz do tabuleiro e verificando se a coordenada escolhida corresponde à posição de um navio.

## Desafios

* **Validação de Coordenadas:** Garantir que as coordenadas escolhidas pelos jogadores sejam válidas (dentro dos limites do tabuleiro).
* **Gerenciamento de Navios:** Manter um registro dos navios e suas partes para verificar se um navio foi totalmente afundado.

## Resultados

As imagens a seguir ilustram diferentes momentos do jogo:

* **CPU1 posicionando os barcos:**
    * ![image](https://github.com/user-attachments/assets/102dd250-9931-4791-abac-4aa10fca3098)

    * ![image](https://github.com/user-attachments/assets/b0a24cbe-2318-4128-a20f-a34983a31fa1)

* **Resultado do jogo CPU x CPU:**
    * ![image](https://github.com/user-attachments/assets/0f8c80c9-dddb-4af6-9c81-0b644c418f90)

## Próximos Passos

* **Interface Gráfica:** Implementar uma interface gráfica para tornar o jogo mais interativo.
* **Multijogador:** Permitir que dois jogadores humanos joguem um contra o outro.
* **Dificuldade:** Adicionar diferentes níveis de dificuldade, ajustando a inteligência artificial dos jogadores da CPU.

## Contribuições

Contribuições são bem-vindas! Se você encontrar algum bug ou tiver alguma sugestão de melhoria, por favor, abra um issue ou faça um pull request.
