#include <ctime>  // Para gerar números aleatórios
#include <cstdlib>

void adicionarBarcosAleatoriamente(char tabuleiro[15][15], char tipoBarco, int tamanhoBarco) {
    bool barcoAdicionado = false;
    int linha, coluna, direcao;  // Direção: 0 para horizontal, 1 para vertical

    while (!barcoAdicionado) {
        linha = rand() % TAMANHO_TABULEIRO;
        coluna = rand() % TAMANHO_TABULEIRO;
        direcao = rand() % 2;  // 0 ou 1

        bool espacoDisponivel = true;

        if (direcao == 0) { // Horizontal
            if (coluna + tamanhoBarco <= TAMANHO_TABULEIRO) { // Verifica se há espaço suficiente
                for (int i = 0; i < tamanhoBarco; i++) {
                    if (tabuleiro[linha][coluna + i] != AGUA) {
                        espacoDisponivel = false;
                        break;
                    }
                }
                if (espacoDisponivel) {
                    for (int i = 0; i < tamanhoBarco; i++) {
                        tabuleiro[linha][coluna + i] = tipoBarco;
                    }
                    barcoAdicionado = true;
                }
            }
        } else { // Vertical
            if (linha + tamanhoBarco <= TAMANHO_TABULEIRO) { // Verifica se há espaço suficiente
                for (int i = 0; i < tamanhoBarco; i++) {
                    if (tabuleiro[linha + i][coluna] != AGUA) {
                        espacoDisponivel = false;
                        break;
                    }
                }
                if (espacoDisponivel) {
                    for (int i = 0; i < tamanhoBarco; i++) {
                        tabuleiro[linha + i][coluna] = tipoBarco;
                    }
                    barcoAdicionado = true;
                }
            }
        }
    }
}

// Exemplo de como adicionar os barcos ao tabuleiro
void adicionarTodosBarcosAleatoriamente(char tabuleiro[15][15]) {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    adicionarBarcosAleatoriamente(tabuleiro, HIDROAVIAO, 3);  // Hidroavião
    adicionarBarcosAleatoriamente(tabuleiro, ENCORACADO, 4);  // Encouraçado
    adicionarBarcosAleatoriamente(tabuleiro, PORTAAVIAO, 5);  // Porta-aviões
    adicionarBarcosAleatoriamente(tabuleiro, CRUZADOR, 3);    // Cruzador
    adicionarBarcosAleatoriamente(tabuleiro, SUBMARINO, 1);   // Submarino
}
