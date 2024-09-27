# Estrutura de Dados: Jogo Batalha Naval

## Descrição

Este projeto implementa o clássico jogo Batalha Naval utilizando a linguagem C++. O objetivo é simular um jogo entre dois jogadores (neste caso, duas CPUs) e demonstrar a aplicação de estruturas de dados para representar o tabuleiro e as posições dos navios.

## Link para Compilar

* **Opção 1:** https://www.onlinegdb.com/online_c++_compiler
* **Opção 2:** https://www.programiz.com/cpp-programming/online-compiler/

## Funcionamento
### CPU x CPU

1. **Inicialização:** O programa inicializa dois tabuleiros, um para cada jogador, e posiciona os navios aleatoriamente.
2. **Rodadas:** Em cada rodada, os jogadores alternam seus turnos, escolhendo uma coordenada para atacar.
3. **Verificação de Acerto:** O programa verifica se a coordenada escolhida contém um navio. Caso sim, o navio é atingido.
4. **Fim de Jogo:** O jogo termina quando todos os navios de um jogador forem afundados.

## Estruturas de Dados Utilizadas

* **Matriz:** Utilizada para representar o tabuleiro de jogo, onde cada elemento indica se há um navio naquela posição ou não.
* **Estrutura:** Utilizada para representar um navio, com informações como tamanho e posições das partes.

## Algoritmos

* **Posicionamento Aleatório dos Navios:** Implementado utilizando um gerador de números aleatórios para escolher as coordenadas iniciais dos navios e verificar se a posição é válida (não sobrepõe outros navios).
* **Verificação de Acerto:** Implementado percorrendo a matriz do tabuleiro e verificando se a coordenada escolhida corresponde à posição de um navio.

## Desafios

* **Validação de Coordenadas:** Garantir que as coordenadas escolhidas pelos jogadores sejam válidas (dentro dos limites do tabuleiro).
* **Gerenciamento de Navios:** Manter um registro dos navios e suas partes para verificar se um navio foi totalmente afundado.

## Resultados

As imagens a seguir ilustram diferentes momentos do jogo:

* **CPU1 posicionando os barcos:**
    * [Imagem 1]([https://github.com/user-attachments/assets/aebbd08d-734d-499c-89b7-62f5193831f5])
    * [Imagem 2]([https://github.com/user-attachments/assets/00746933-647a-4501-a9f9-6d5b6c66e15e])
* **Resultado do jogo CPU x CPU:**
    * [Imagem 3]([https://github.com/user-attachments/assets/0f8c80c9-dddb-4af6-9c81-0b644c418f90])

## Próximos Passos

* **Interface Gráfica:** Implementar uma interface gráfica para tornar o jogo mais interativo.
* **Multijogador:** Permitir que dois jogadores humanos joguem um contra o outro.
* **Dificuldade:** Adicionar diferentes níveis de dificuldade, ajustando a inteligência artificial dos jogadores da CPU.

## Contribuições

Contribuições são bem-vindas! Se você encontrar algum bug ou tiver alguma sugestão de melhoria, por favor, abra um issue ou faça um pull request.
