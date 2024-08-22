#include<iostream>
#include<iomanip>
using namespace std;
#include <cstdlib>

const int TAMANHO_TABULEIRO = 15;
char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

/*
Função que preenche a matriz com um caracter que representa a água
*/
void inicializarTabuleiro(){
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '#';
        }
    }

}
void imprimirTabuleiro() {
    char vetorLetras [15] {'A','B','C','D','E','F','G','H','I','J','k','L','M','N','O'};
    cout << "  ";
    for (char vogal : vetorLetras) {
        cout << vogal << " "; // Esse espaço deixa o desenho mais bonito
      }

    cout << endl;

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        cout << i << "  ";
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}
void displayTabuleiro (){
     system("cls"); // Limpa a tela (funciona apenas no Windows)
    inicializarTabuleiro();
    imprimirTabuleiro();
}
void BatalhaPvp(){
     system("cls"); // Limpa a tela
    cout << " Jogador 1 informe o seu nome: " << endl;
    displayTabuleiro();
}
void menuBatalhaNaval(){
     system("cls"); // Limpa a tela
    int resp = 0;
     cout << "Estrutura de Dados - Matrizes" << endl;
    cout << "Bem vindo ao jogo Batalha Naval" << endl;
    cout << "Digite 1 para P x P " << endl;
    cout << "Digite 2 para P x CPU " << endl;
    cout << "Digite 3 para CPU x P " << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch(resp)
            {
            case 1: cout <<" tu escolheu P x P" << endl;
                displayTabuleiro();
            break;
            case 2: cout <<" tu escolheu P x CPU" << endl;
            break;
            case 3: cout <<" tu escolheu CPU x P" << endl;
            break;
            }
}
void Programa2(){
     system("cls"); // Limpa a tela
    int resp = 0;
    cout << "Bem vindo a o Programa2 mundo que ainda não é mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}
void Programa3(){
     system("cls"); // Limpa a tela
    int resp = 0;
    cout << "Bem vindo a o Programa3 mundo que ainda não é mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}
void Programa4(){
     system("cls"); // Limpa a tela
    int resp = 0;
    cout << "Bem vindo a o Programa4 mundo que ainda não é mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}
void MatrizesVetores(){
    system("cls"); // Limpa a tela

    int resp = 0;

    cout << "Estrutura de Dados Matrizes e Vetores" << endl;
    cout <<endl;

    cout << "[1] Batalha Naval " <<endl;
    cout << "[2] Programa 2" <<endl;
    cout << "[3] Programa 3" <<endl;
    cout << "[4] Programa 4" <<endl;
    cout << "[0] Digite  para sair " << endl;

     cout << "Entre com a opção desejada" <<endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch(resp)
            {
            case 1: menuBatalhaNaval();
            break;
            case 2: Programa2();
            break;
            case 3: Programa3();
            break;
            case 4: Programa4();
            break;
            }
}
void menuPrincipal(){
     system("cls"); // Limpa a tela
    int resp = 0;
    cout << "Estrutura de Dados" << endl;
    cout <<endl;
    cout << "[1] Matrizes e Vetores " <<endl;
    cout << "[2] Programa 2" <<endl;
    cout << "[3] Programa 3" <<endl;
    cout << "[4] Programa 4" <<endl;
    cout << "[0] Digite  para sair " << endl;

     cout << "Entre com a opção desejada" <<endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch(resp)
            {
            case 1: MatrizesVetores();
            break;
            case 2: Programa2();
            break;
            case 3: Programa3();
            break;
            case 4: Programa4();
            break;
            }
}




int main (void)
{
    int resp = 0;

    do
    {
        menuPrincipal();
        cin >> resp;
        cin.ignore(80, '\n');
    }
        while(resp != 0);
        return 0;
}
