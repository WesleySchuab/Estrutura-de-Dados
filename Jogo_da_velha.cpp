#include <iostream>
using namespace std;

// Criando constantes para selecionar o SO
#if defined(_WIN32)
#define Plataforma 'w'
#elif defined(_WIN64)
#define Plataforma 'w'
#elif defined(__linux__)
#define Plataforma 'l'
#endif

char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char jogadorAtual = 'X';

void limparTela()
{
#ifdef _WIN32
	system("cls");
#else
	cout << "\033[2J\033[H";
#endif
}


void desenharTabuleiro() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool verificarVitoria() {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return true;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ') {
            return true;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return true;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true;
    }

    return false; // Se nenhuma condição de vitória for encontrada
}

void fazerJogada() {
    int linha, coluna;
    cout << "Jogador " << jogadorAtual << ", escolha a linha (1-3): ";
    cin >> linha;
    cout << "Jogador " << jogadorAtual << ", escolha a coluna (1-3): ";
    cin >> coluna;

    // Verificar se a posição está válida e livre
    if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ') {
        tabuleiro[linha - 1][coluna - 1] = jogadorAtual;
    } else {
        cout << "Jogada inválida. Tente novamente." << endl;
        fazerJogada();
    }
}

int main() {
    while(  ( verificarVitoria ) )
    {
    limparTela();
    desenharTabuleiro();
    fazerJogada();
    desenharTabuleiro();
    verificarVitoria();
    }
}