#include <vector>

// ... (restante do seu código)

struct Navio {
    char tipo;
    int tamanho;
    std::vector<std::pair<int, int>> coordenadas;
    bool afundado;
};

// ... (restante do seu código)

void atirar(char tabuleiroAdversario[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
            char tabuleiroAtual[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
            std::vector<Navio>& navios) {
    int linha, coluna;

    do {
        // Obter as coordenadas do tiro do usuário
        // ... (código existente)

        if (!validarCoordenadas(linha, coluna)) {
            cout << "Coordenadas inválidas. Tente novamente." << endl;
        } else {
            break;
        }
    } while (true);

    // Verificar se a posição já foi atacada
    if (tabuleiroAtual[linha][coluna] != AGUA) {
        cout << "Você já atirou nessa posição. Escolha outra coordenada." << endl;
        return;
    }

    // Marcar o tiro no tabuleiro atual
    tabuleiroAtual[linha][coluna] = TIRO_AGUA;

    // Verificar se algum navio foi atingido
    bool acertou = false;
    for (Navio& navio : navios) {
        for (auto& coordenada : navio.coordenadas) {
            if (coordenada.first == linha && coordenada.second == coluna) {
                acertou = true;
                tabuleiroAdversario[linha][coluna] = TIRO_NAVIO;
                navio.coordenadas.erase(std::remove(navio.coordenadas.begin(), navio.coordenadas.end(), coordenada), navio.coordenadas.end());

                if (navio.coordenadas.empty()) {
                    navio.afundado = true;
                    cout << "Você afundou um " << navio.tipo << "!" << endl;
                } else {
                    cout << "Acerto!" << endl;
                }
                break;
            }
        }
        if (acertou) {
            break;
        }
    }

    if (!acertou) {
        cout << "Água!" << endl;
    }
}