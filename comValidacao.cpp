#include <iostream>
#include <iomanip> // Inclua para usar setw
#include <cstdlib> // Para a fun��o atoi
#include <string>
using namespace std;

// Criando constantes para selecionar o SO
#if defined(_WIN32)
#define Plataforma 'w'
#elif defined(_WIN64)
#define Plataforma 'w'
#elif defined(__linux__)
#define Plataforma 'l'
#endif

const char AGUA = 'O';
// const char NAVIO = 'X';
const char HIDROAVIAO = 'H';
//titulo da embarcação 
const string H = "HIDROAVIAO";
// const char TIRO_AGUA = '~';
// const char TIRO_NAVIO = '*';

// Constantes para as cores
#define AMARELO "\x1b[33m"
#define RESET "\x1b[0m"
#define PRETO "\x1b[30m"
#define VERDE "\x1b[32m"
#define BRANCO "\x1B[37m"
#define FBRANCO "\x1b[47m"
#define VERMELHO "\x1b[91m"
#define VERDEC "\x1b[92m"
#define AZUL "\x1b[94m"
#define AZULC "\x1b[96m"
#define FCINZA "\x1b[100m"
// variaveis Globais
const int TAMANHO_TABULEIRO = 15;
char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char tabuleiro1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char tabuleiro2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[H";
#endif
}

void inicializarTabuleiro(char tabuleiro[15][15])
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}

class Embarcacoes
{
public:
    int posicao1;
    int posicao2;
    bool isTrue = true;
    bool isFalse = false;
    bool entrada =false;
     
    // validações padrão inicio

    bool limiteLetra(char indice)
    {
        /*if (indice >= 'A' && indice <= 'J') {
            return true;
        }*/
        return indice >= 'A' && indice <= 'J';
    }
    bool limiteNumero(int indice)
    {
        // if (indice >= 0 && indice <= 9)
        return indice >= 0 && indice <= TAMANHO_TABULEIRO;
    }
    bool casaOcupada(char indice, int numero)
    {
        return tabuleiro[numero][indice] != AGUA;
    }

    bool validaEntrada(int p1, int p2, char m[15][15])
    {
        if (p1 >= 0 && p1 <= 14 && p2 >= 0 && p2 <= 14 && m[p1][p2] == AGUA)
        {
            return true;
        }
        return false;
    }
    // Validações padrões fim
    
    //Le a posição letra
    int LerIndiceLetra(int ordinal,string embarcacao ){
    
         char letra; 
          int p;
           //cout << AMARELO << nomeJogador;
           cout << endl <<" Digite o [ LETRA ] da " << ordinal <<" posicoes para " << embarcacao << endl;
           cout << endl;
           cin >> letra;

           // Deixa a letra maiuscula 
           letra = toupper(letra);
           p = letra - 'A';
          // p--;
           cout << "letra digitada equivale a " << p;
          do{
                
                if (limiteNumero(p)) // veriica se o valor informado esta dentro das dimensões do tabuleiro
                {
                    entrada = true; cout <<" Entrada valida";
                } else {
                    entrada =false; cout << " Entrada Invalida ";
                }
                if( ! ( entrada ) )
                {
                    cout << endl << "valor fora do limite do tabuleiro"; 
                    LerIndiceLetra(ordinal,embarcacao );
                }
                
            }while( ! (entrada) );
            
          return p ;
        }
        // Fazendo a função ler indide numero
        /*
         int LerIndiceNumero(int ordinal, string embarcacao ){
               int p;
               cout << endl <<" Digite o [ NUMERO] da " << ordinal <<" posicoes para " << embarcacao << endl;
                cin >> p;
                cout << endl;   
                p--;
                do
            {
                cout << endl
                     << " Digite o [ Numero ] da " << i << " posicoes para HidroAviao " << endl;
                cin >> hidrohaviao1.posicao1;
                cout << endl;
                cout << AMARELO << nomeJogador;

                if (hidrohaviao1.limiteNumero(hidrohaviao1.posicao1)) // veriica se o valor informado esta dentro das dimensões do tabuleiro
                {
              return p;
          } */
        

    virtual bool validarPosicao(int p1, int p2, char m[15][15]) = 0;
};

class hidrohaviao : public Embarcacoes
{
public:
    int p3;
    int p4;

    bool validarPrimeiroNumero(int p1)
    {
        if (p1 == 1 || p1 == 14)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool validarPosicao(int p1, int p2, char m[15][15]) override
    {
        // User insert 1 but it should be 0
        if (m[p1][p2] == '0')
        {
            return true;
        }
        return false;
    }
};

// TODO a impressão do tabuleiro tem que ser
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    char vetorLetras[TAMANHO_TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    const int LARGURA_COLUNA = 3; // Largura de cada coluna, ajuste conforme necess�rio

    // Imprimir os n�meros na parte superior
    cout << "   "; // Espa�o inicial para alinhar n�meros
    for (int i = 1; i < TAMANHO_TABULEIRO + 1; i++)
    {
        cout << AMARELO << setw(LARGURA_COLUNA) << i; // Imprime o n�mero da coluna com largura fixa
    }
    cout << endl;
    cout << endl; // Pula uma linha depois de escrever os numeros

    // Imprimir o tabuleiro com letras na vertical
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        cout << AMARELO << setw(2) << vetorLetras[i] << " "; // Imprime a letra da linha com espa�amento fixo

        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == HIDROAVIAO)
                cout << BRANCO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            else
                cout << AZULC << setw(LARGURA_COLUNA) << tabuleiro[i][j];
        }
        cout << endl;
    }
}

void displayTabuleiro()
{
    limparTela();
    inicializarTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
}

void BatalhaPvp()
{
    inicializarTabuleiro(tabuleiro1);
    inicializarTabuleiro(tabuleiro2);
    string nomeJogador = "Wesley";
    char letra;
    hidrohaviao hidrohaviao1;
    int encoracadop1;
    int encoracadop2;
    int portaAviaop1;
    int portaAviaop2;
    

    limparTela();

    displayTabuleiro();

    // Le o nome do Jogador
    cout << BRANCO << endl;
    cout << "Jogador 1 informe o seu nome: " << endl;
    //getline(cin, nomeJogador);

    for (int j = 1; j < 2; j++)
    {
        for (int i = 1; i < 3; i++)
        {

            do
            {
                cout << endl
                     << " Digite o [ Numero ] da " << i << " posicoes para HidroAviao " << endl;
                cin >> hidrohaviao1.posicao1;
                cout << endl;
                cout << AMARELO << nomeJogador;

                if (hidrohaviao1.limiteNumero(hidrohaviao1.posicao1)) // veriica se o valor informado esta dentro das dimensões do tabuleiro
                {
                    if (i == 1)
                    {
                        if (hidrohaviao1.validarPrimeiroNumero(hidrohaviao1.posicao1)) // verifica é possivel formar o desenho
                        {
                            hidrohaviao1.posicao1 = true;
                            cout << " primeiro numero  Valido ";
                        }
                        else
                        {
                            hidrohaviao1.posicao1 = false;
                            cout << " primeiro numero  Invalido ";
                        }
                    }
                    if (!(hidrohaviao1.posicao1))
                    {
                        cout << "Posicao Invalida" << endl;
                    }
                } else
                        {
                            hidrohaviao1.posicao1 = false;
                            cout << " primeiro numero  Invalido ";
                        }

            } while (!(hidrohaviao1.posicao1));
            
            
           // hidrohaviao1.LerIndiceLetra( i, H);
            
            
            tabuleiro1[ hidrohaviao1.LerIndiceLetra( i, H)  ][ hidrohaviao1.posicao1 ] = HIDROAVIAO;
            limparTela();
            imprimirTabuleiro(tabuleiro1);
        }

        /*cout << endl;
        cout << "  Digite o [ Numero ] 1 para encoracado";
        cin encoracadop1;
        cout << endl <<" Digite a [ letra ] da " <<"1°" << "  posicoes para Encoracado ";
        cout << endl;
        cin >> letra;

        cout << endl;
        cout << " Digite a posição 2 para encoracado";
        cin encoracadop2;
        cout << endl <<" Digite a [ letra ] da " <<"2°" << "  posicoes para Encoracado ";
        cout << endl;
        cin >> letra;

        for(int i= 0; i <= 3){

        }
        cout << endl;
        cout << "  Digite o [ Numero ] 1 para porta Aviao";
        cin >> portaAviaop1;
        cout << endl <<" Digite a [ letra ] da " <<"1°" << "  posicoes para porta Aviao ";
        cout << endl;
        cin >> letra;

        cout << endl;
        cout << " Digite a posição 2 para porta Aviao";
        cin >> portaAviaop2;
        cout << endl <<" Digite a [ letra ] da " <<"2°" << "  posicoes para porta Aviao ";
        cout << endl;
        cin >> letra;

        for(int i= 0; i <= 5){

        }*/

        /*cout <<"Entrou no if";
         if(hidrohaviao1.validaEntrada(hidrohaviao1.posicao1, hidrohaviao1.posicao2, tabuleiro1)){
            cout << "Posicao valida" << endl;

            // Marcar a position on tabuleiro
            tabuleiro1[hidrohaviao1.posicao2][hidrohaviao1.posicao1] = HIDROAVIAO;
            cout << endl << "Tabuleiro com a posição inserida" << endl;
            limparTela();
            imprimirTabuleiro(tabuleiro1);
        } else {
            cout << "Posicao invalida" << endl;
        }*/
    }
    for (int i = 1; i < 3; i++)
    {

        do
        {
            cout << endl
                 << " Digite o [ Numero ] da " << i << " posicoes para SUBMARINO " << endl;
            cin >> hidrohaviao1.posicao1;
            cout << endl;
            cout << AMARELO << nomeJogador;
            if (hidrohaviao1.limiteNumero(hidrohaviao1.posicao1))
            {
                cout << "Posicao valida" << endl;
            }
        } while (hidrohaviao1.limiteNumero(hidrohaviao1.posicao1)); // Verifica se a primeira posição é valida

        cout << endl
             << " Digite o [ letra ] da" << i << "  posicoes para SUBMARINO ";
        cout << endl;
        cin >> letra;
        // Deixa a letra maiuscula
        letra = toupper(letra);

        hidrohaviao1.posicao2 = letra - 'A';
        hidrohaviao1.posicao1--;
        tabuleiro1[hidrohaviao1.posicao2][hidrohaviao1.posicao1] = HIDROAVIAO;
        limparTela();
        imprimirTabuleiro(tabuleiro1);
    }
}

void menuBatalhaNaval()
{
    limparTela();
    int resp = 0;
    cout << "Estrutura de Dados - Matrizes" << endl;
    cout << "Bem vindo ao jogo Batalha Naval" << endl;
    cout << "Digite 1 para P x P " << endl;
    cout << "Digite 2 para P x CPU " << endl;
    cout << "Digite 3 para CPU x P " << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch (resp)
    {
    case 1:
        cout << "Tu escolheu P x P" << endl;
        BatalhaPvp();
        break;
    case 2:
        cout << "Tu escolheu P x CPU" << endl;
        break;
    case 3:
        cout << "Tu escolheu CPU x P" << endl;
        break;
    }
}

void Programa2()
{
    limparTela();
    int resp = 0;
    cout << "Bem-vindo ao Programa2, mundo que ainda n�o � mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}

void Programa3()
{
    limparTela();
    int resp = 0;
    cout << "Bem-vindo ao Programa3, mundo que ainda n�o � mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}

void Programa4()
{
    limparTela();
    int resp = 0;
    cout << "Bem-vindo ao Programa4, mundo que ainda n�o � mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}

void MatrizesVetores()
{
    limparTela();
    int resp = 0;
    cout << "Estrutura de Dados Matrizes e Vetores" << endl;
    cout << endl;
    cout << "[1] Batalha Naval " << endl;
    cout << "[2] Programa 2" << endl;
    cout << "[3] Programa 3" << endl;
    cout << "[4] Programa 4" << endl;
    cout << "[0] Digite  para sair " << endl;
    cout << "Entre com a op��o desejada" << endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch (resp)
    {
    case 1:
        BatalhaPvp();
        break;
    case 2:
        Programa2();
        break;
    case 3:
        Programa3();
        break;
    case 4:
        Programa4();
        break;
    }
}

void menuPrincipal()
{
    limparTela();
    int resp = 0;
    cout << "Estrutura de Dados" << endl;
    cout << endl;
    cout << "[1] Matrizes e Vetores " << endl;
    cout << "[2] Programa 2" << endl;
    cout << "[3] Programa 3" << endl;
    cout << "[4] Programa 4" << endl;
    cout << "[0] Digite para sair " << endl;
    cout << "Entre com a op��o desejada" << endl;
    cin >> resp;
    cin.ignore(80, '\n');
    switch (resp)
    {
    case 1:
        BatalhaPvp();
        break;
    case 2:
        Programa2();
        break;
    case 3:
        Programa3();
        break;
    case 4:
        Programa4();
        break;
    }
}

int main(void)
{

    setlocale(LC_ALL, "Portuguese");
    int resp = 0;
    do
    {
        BatalhaPvp();
        cin >> resp;
        cin.ignore(80, '\n');
    } while (resp != 0);
    return 0;
}