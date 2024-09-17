#include <iostream> // controla entra e saida
#include <iomanip>  // Inclua para usar setw
#include <cstdlib>  // Para a funo?=o?=o atoi
#include <string>
#include <ncurses.h>
#include <cctype> // para veriica entrada numero
#include <random> // Gerar numeros aleatorios
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
const char ENCORACADO = 'E';
const char PORTAAVIAO = 'P';
const char SUBMARINO = 'S';
const char CRUZADOR = 'C';

const char TIRO_AGUA = '~';
const char TIRO_NAVIO = '*';

// titulo da embarcaC'C#o
const string H = "HIDROAVIAO";
const string E = "ENCORACADO";
const string P = "PORTAAVIAO";
const string S = "SUBMARINO";
const string C = "CRUZADOR";

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

#define RESET "\x1b[0m"
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"

#define INVERSE "\x1b[7m"

// Cores de fundo
#define BBLACK "\x1b[40m"
#define BRED "\x1b[41m"
#define BGREEN "\x1b[42m"
#define BYellow "\x1b[43m"
#define BBLUE "\x1b[44m"
#define BMAGENTA "\x1b[45m"
#define BCYAN "\x1b[46m"
#define BWHITE "\x1b[47m"

/*
 std::cout << BOLD << "Texto em negrito" << RESET << std::endl;
    std::cout << UNDERLINE << "Texto sublinhado" << RESET << std::endl;
    std::cout << INVERSE << "Texto invertido" << RESET << std::endl;

    std::cout << RED << "Texto vermelho" << RESET << std::endl;
    std::cout << BGREEN << "Texto com fundo verde" << RESET << std::endl;
    std::cout << YELLOW << "Texto amarelo" << BBLUE << " com fundo azul" << RESET << std::endl;
    */

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

int validarNumero()
{
    int numero;
    do
    {
        cout << "Digite um numero inteiro positivo: ";
        cin >> numero;
        cout << endl
             << " numero digitado " << numero << endl;

        if (cin.fail() || numero <= 0)
        {
            cout << "Entrada invalida. Digite um numero inteiro positivo." << endl;
            cin.clear();          // Limpa o estado de falha do cin
            cin.ignore(80, '\n'); // Ignora caracteres restantes na linha
        }
    } while (cin.fail() || numero <= 0);
    return numero;
}

class Embarcacoes
{
public:
    int posicao1;
    int posicao2;
    bool isTrue = true;
    bool isFalse = false;
    bool entrada = false;

    // validar inicio

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
    // ValidaC'C5es padrC5es fim

    // Le a posiC'C#o letra
    int LerIndiceLetra(int ordinal, string embarcacao)
    {

        char letra;
        int p;
        do
        {
            // cout << AMARELO << nomeJogador;
            cout << BRANCO;
            // cout << endl <<" Digite a [ LETRA ] da" << ordinal <<" coordenada posicoes para " << embarcacao << endl;
            cout << endl
                 << " Digite a [ LETRA \ Linha] da " << ordinal << " coordenada posicoes para " << embarcacao << endl;
            cout << endl;
            cin >> letra;

            // Deixa a letra maiuscula
            letra = toupper(letra);
            p = letra - 'A';

            if (limiteNumero(p)) // veriica se o valor informado esta dentro das dimensC5es do tabuleiro
            {
                entrada = true;
                cout << BRANCO;
            }
            else
            {
                entrada = false;
            }
            if (!(entrada))
            {
                cout << VERMELHO << endl
                     << "Letra fora do limite do tabuleiro";
                cout << BRANCO;
            }

        } while (!(entrada));

        return p;
    }
    // Fazendo a funCao ler indice numero

    int LerIndiceNumero(bool &entrada, int ordinal, string embarcacao)
    {
        int p;

        do
        {
            cout << BRANCO << endl
                 << " Digite 0 [ Numero / coluna] da " << ordinal << " posicoes para " << embarcacao << endl;
            // cin >> p;
            p = validarNumero();
            cout << endl;
            p--;

            if (limiteNumero(p)) // veriica se o valor informado esta dentro das dimensC5es do tabuleiro
            {
                entrada = true;
            }
            else
            {
                entrada = false;
                cout << VERMELHO << endl
                     << " Entrada Invalida fora do limite do tabuleiro ";
                cout << BRANCO;
            }
            if (!(entrada))
            {
                cout << VERMELHO << endl
                     << "valor fora do limite do tabuleiro";
                cout << BRANCO;
            }
        } while (!(entrada));
        cout << endl;
        return p;
    }

    virtual bool validarPosicao(int p1, int p2, char m[15][15]) = 0;
};

class Hidrohaviao : public Embarcacoes
{
public:
    int p3;
    int p4;

    bool validarPrimeiroNumero(int p1)
    {
        if (p1 == 0 || p1 == 14)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool validarFormaHidro(int colunaNumero1, int colunaNumero2, int letra1, int letra2, char m[15][15])
    {
        bool retorno = false;
        //  validando segunda entrada
        if ((colunaNumero2 == colunaNumero1 + 1) || (colunaNumero2 == colunaNumero1 - 1) && (m[letra2][colunaNumero2] == AGUA)) // verifica nas colunas ao lado
        {

            cout << endl
                 << " Validou colunas hidro";

            if ((letra2 == letra1 + 1) || (letra2 == letra1 - 1))
            {
                cout << AMARELO << endl
                     << " Letra valida" << endl ;
                cout << BRANCO;
                retorno = true;
            }
            else
            {
                cout << VERMELHO << endl
                     << " Letra Invalida" << endl;
                cout << BRANCO;
                retorno = false;
            }
        }

        return retorno;
    }
    bool validarTerceiraFormaHidro(int colunaNumero2, int colunaNumero3,  int letra2, int letra3, char m[15][15])
    {
        bool retorno = false;
        // quando a coluna é igual a letra tem que ser diferente e vice versa
        if ( (colunaNumero3 == colunaNumero2) && (letra3 > letra2 +1) || (letra3 < letra2 -1)  ) // verifica nas colunas ao lado
        {
            if ( m[letra3][colunaNumero3] == AGUA ){
                cout << AMARELO << endl
                 << " Letra valida";
            cout << BRANCO;
            retorno = true;
            }
            
        }else if ( (letra3 == letra2) && (colunaNumero3 > colunaNumero2 +1) || (colunaNumero3 < colunaNumero2 -1)  ) { // verifica nas colunas ao lado
            if (  m[letra3][colunaNumero3] == AGUA ){
                cout << AMARELO << endl
                 << " Letra valida";
            cout << BRANCO;
            retorno = true;
            }
        }else{
            return false;
        }
        return retorno;
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

class Barcos : public Embarcacoes
{
public:
    Barcos(int tamanho) : tamanho(tamanho) {}
    int tamanho = 0;
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

class PortaAviao : public Barcos
{
public:
    //	int tamanho = 5;
    PortaAviao() : Barcos(5) {}

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

class Encoracado : public Barcos
{
public:
    // int tamanho = 3;
    Encoracado() : Barcos(3) {}

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

class Cruzador : public Barcos
{
public:
    // int tamanho = 3;
    Cruzador() : Barcos(2) {}

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

class Submarino : public Barcos
{
public:
    // int tamanho = 3;
    Submarino() : Barcos(1) {}

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

// TODO a impressC#o do tabuleiro tem que ser
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    char vetorLetras[TAMANHO_TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    const int LARGURA_COLUNA = 3; // Largura de cada coluna, ajuste conforme necesso?=rio

    // Imprimir os no?=meros na parte superior
    cout << "   "; // Espao?=o inicial para alinhar no?=meros
    for (int i = 1; i < TAMANHO_TABULEIRO + 1; i++)
    {
        cout << AMARELO << setw(LARGURA_COLUNA) << i; // Imprime o no?=mero da coluna com largura fixa
    }
    cout << endl;
    cout << endl; // Pula uma linha depois de escrever os numeros

    // Imprimir o tabuleiro com letras na vertical
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        cout << AMARELO << setw(2) << vetorLetras[i] << " "; // Imprime a letra da linha com espao?=amento fixo

        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == HIDROAVIAO) // Hidro C) branco
            {
                cout << BRANCO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            }
            else if (tabuleiro[i][j] == ENCORACADO) // EncoraC'C#do C) amarelo
            {
                cout << VERMELHO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            }
            else if (tabuleiro[i][j] == PORTAAVIAO) // Porta AviC#o C) amarelo
            {
                cout << AMARELO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            }
            else if (tabuleiro[i][j] == CRUZADOR) // amarelo
            {
                cout << AMARELO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            }
            else if (tabuleiro[i][j] == SUBMARINO) // amarelo
            {
                cout << AMARELO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
            }
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
void adicionarHidroaviao(int quantBarcos, Hidrohaviao hidrohaviao1, char tabuleiro[15][15])
{
    bool entradaValida = false;
    int linhaLetra1 = 0;
    int linhaLetra2 = 0;
    int linhaLetra3 = 0;
    int colunaNumero1 = 0;
    int colunaNumero2 = 0;
    int colunaNumero3 = 0;
    for (int j = 1; j <= 2; j++)
    {
        // cout <<endl <<j <<" " << H;
        for (int i = 1; i <= quantBarcos; i++)
        {

            do
            {

                if (i == 1) // Verifica se a primeira coor para o hidro
                {
                    do
                    {
                        colunaNumero1 = hidrohaviao1.LerIndiceNumero(entradaValida, i, H);

                        if (hidrohaviao1.validarPrimeiroNumero(colunaNumero1)) // verifica se e possivel formar o desenho
                        {
                            linhaLetra1 = hidrohaviao1.LerIndiceLetra(i, H); // como indice numero esta ok le o indice letra

                            entradaValida = true;
                        }
                        else
                        {
                            entradaValida = false;
                            cout << VERMELHO << endl
                                 << " primeiro numero  Invalido para formar o desenho ";
                        }
                        if (tabuleiro[linhaLetra1][colunaNumero1] != AGUA)
                        {
                            entradaValida = false;
                            cout << VERMELHO << endl
                                 << " primeiro numero  Invalido para formar o desenho ";
                        }

                    } while (!entradaValida); // verifica se a coordenda passada foi usada
                    tabuleiro[linhaLetra1][colunaNumero1] = HIDROAVIAO;
                }
                else if (i == 2) // Verifica a segunda e terceria coordenada par ao hidrohaviao
                {
                    // TODO esta voltando para inserir a primeira posicao caso de alguim erro
                    //
                    //  verifica se as demais coordenada sao valida

                    colunaNumero2 = hidrohaviao1.LerIndiceNumero(entradaValida, i, H);

                    linhaLetra2 = hidrohaviao1.LerIndiceLetra(i, H);

                    if (hidrohaviao1.validarFormaHidro(colunaNumero1, colunaNumero2, linhaLetra1, linhaLetra2, tabuleiro))
                    {
                        entradaValida = true;
                        tabuleiro[linhaLetra2][colunaNumero2] = HIDROAVIAO;
                    }
                    else
                    {
                        entradaValida = false;
                        cout << endl
                             << VERMELHO << "Nao forma HIDROAVIAO" << endl;

                        // TODO posso dividir a funcao validar hidro para não excluir a primeira posicao se for valida
                        tabuleiro[linhaLetra1][colunaNumero1] = AGUA;
                        i--;
                    }
                }
                else if (i == 3)
                {
                    colunaNumero3 = hidrohaviao1.LerIndiceNumero(entradaValida, i, H);

                    linhaLetra3 = hidrohaviao1.LerIndiceLetra(i, H);

                    //validarTerceiraFormaHidro(int colunaNumero2, int colunaNumero3,  int letra2, int letra3, char m[15][15])

                    if (hidrohaviao1.validarTerceiraFormaHidro( colunaNumero2, colunaNumero3,  linhaLetra2, linhaLetra3, tabuleiro))
                    {
                        entradaValida = true;
                        tabuleiro[linhaLetra3][colunaNumero3] = HIDROAVIAO;
                    }
                    else
                    {
                        entradaValida = false;
                        cout << endl
                             << VERMELHO << "Nao forma HIDROAVIAO" << endl;

                        // TODO posso dividir a funcao validar hidro para não excluir a primeira posicao se for valida
                        tabuleiro[linhaLetra1][colunaNumero1] = AGUA;
                        tabuleiro[linhaLetra2][colunaNumero2] = AGUA;
                        i--;
                        i--;
                    }
                }

            } while (!(entradaValida));
            //limparTela();
            cout << endl << "Vai imprimir tabuleiro " << endl;
            imprimirTabuleiro(tabuleiro);

        } // fim do HIDROAVIAO
    }
}
void adicionarBarcos(int quantBarcos, Barcos &barco, string tipoBarco, char simbolo, char tabuleiro[15][15])
{
    //	char letra1;
    cout << endl
         << AMARELO << " Vamos adicionar " << tipoBarco << endl;
    cout << BRANCO;
    int indiceNumero;
    int indiceLetra1;
    int tamanhoParaExibir = barco.tamanho + 1;
    // barco.tamanho;

    for (int i = 1; i <= quantBarcos; i++)
    {

        bool entradaValida = false;

        int direcao;

        cout << endl
             << " tamanho do barco " << tamanhoParaExibir << endl;
        cout << endl
             << " caracter que sera grvado " << simbolo << endl;
        cout << " digite [ 1 ] inserir na Horizontal e [ 2 ] para inserir na vertical " << endl;
        cin >> direcao;

        do
        {

            indiceNumero = barco.LerIndiceNumero(entradaValida, i, tipoBarco);

            // trocar por encoracadop2
            indiceLetra1 = barco.LerIndiceLetra(i, tipoBarco);
            if (barco.tamanho == 1)
            {

                tabuleiro[indiceLetra1][indiceNumero] = simbolo;
            }
            else if (direcao == 1)
            {
                int j = indiceNumero + barco.tamanho; // para controlar o laC'o
                if (TAMANHO_TABULEIRO - indiceLetra1 >= barco.tamanho)
                { // verifica se possivel posicionar na vertical
                    entradaValida = true;
                    for (indiceNumero; indiceNumero <= j; indiceNumero++)
                    {
                        tabuleiro[indiceLetra1][indiceNumero] = simbolo;
                    }
                }
                else
                {
                    entradaValida = false;
                }
            }
            else if (direcao == 2)
            {

                int j = indiceLetra1 + barco.tamanho; // para controlar o laco
                if (TAMANHO_TABULEIRO - indiceNumero >= barco.tamanho)
                { // verifica se possivel posicionar na horizontal
                    entradaValida = true;
                    for (indiceLetra1; indiceLetra1 <= j; indiceLetra1++)
                    {
                        tabuleiro[indiceLetra1][indiceNumero] = simbolo;
                    }
                }
            }
            if (!(entradaValida))
                cout << endl
                     << "Coordendas Invalidas";

        } while (!(entradaValida));

        // limparTela();
        imprimirTabuleiro(tabuleiro);

    } // for add ENCORACADO
}

int numeroAleatorio(int limite)
{
    srand(time(0));
    int numeroAleatorio;

    if (limite == 14)
    {
        numeroAleatorio = rand() % limite;
    }
    else
    {
        // Gera um número aleatório entre 0 e 12 (inclusive)
        numeroAleatorio = rand() % 13;

        // Adiciona 2 ao número gerado para obter o intervalo desejado (2 a 14)
        numeroAleatorio += 2;
    }
    return numeroAleatorio;
}
int gerarNumeroAleatorio(int min, int max)
{
    // Cria um gerador de números aleatórios usando a semente do relógio
    std::random_device rd;
    std::mt19937 gerador(rd());                             // mt19937 é um gerador de números aleatórios Mersenne Twister
    std::uniform_int_distribution<> distribuicao(min, max); // Define a distribuição uniforme no intervalo [min, max]

    return distribuicao(gerador); // Gera e retorna o número aleatório
}

void cpuAdicionaHidro(int quantBarcos, Hidrohaviao hidrohaviao1, char tabuleiro[15][15])
{
    // linha = rand() % TAMANHO_TABULEIRO;
    // coluna = rand() % TAMANHO_TABULEIRO;
    bool entradaValida = false;
    int linhaLetra1 = 0;
    int linhaLetra2 = 0;
    int linhaLetra3 = 0;
    int colunaNumero1 = 0;
    int colunaNumero2 = 0;
    int colunaNumero3 = 0;
    
    int pause;
    
    srand(time(0));

    for (int j = 1; j <= quantBarcos; j++)
    {
        cout <<endl <<j <<" " << H << endl;
        for (int i = 1; i <= 3; i++)
        {

            do
            {   
                cout <<endl << "coordenada " << i  << endl;

                if (i == 1) // Verifica se a primeira coor para o hidro
                {
                    do
                    {

                        colunaNumero1 = gerarNumeroAleatorio(1, 13);

                        if (hidrohaviao1.validarPrimeiroNumero(colunaNumero1)) // verifica se e possivel formar o desenho
                        {
                            linhaLetra1 = gerarNumeroAleatorio(0, 14);

                            entradaValida = true;
                        }
                        else
                        {
                            entradaValida = false;
                            cout << VERMELHO << endl
                                 << " primeiro numero  Invalido para formar o desenho ";
                        }
                        if (tabuleiro[linhaLetra1][colunaNumero1] != AGUA)
                        {
                            entradaValida = false;
                            cout << VERMELHO << endl
                                 << " primeiro numero  Invalido para formar o desenho ";
                        }

                    } while (!entradaValida); // verifica se a coordenda passada foi usada
                    tabuleiro[linhaLetra1][colunaNumero1] = HIDROAVIAO;
                    imprimirTabuleiro(tabuleiro);
                }
                else if (i == 2) // Verifica a segunda e coordenada par ao hidrohaviao
                {
                    // TODO esta voltando para inserir a primeira posicao caso de alguim erro
                    //
                    //  verifica se as demais coordenada sao valida

                    // colunaNumero2 = hidrohaviao1.LerIndiceNumero(entradaValida, i, H);

                    // linhaLetra2 = hidrohaviao1.LerIndiceLetra(i, H);

                    colunaNumero2 = gerarNumeroAleatorio(colunaNumero1 - 1, colunaNumero1 + 1);

                    linhaLetra2 = gerarNumeroAleatorio(linhaLetra1 - 1, linhaLetra1 + 1);

                    if (hidrohaviao1.validarFormaHidro(colunaNumero1, colunaNumero2, linhaLetra1, linhaLetra2, tabuleiro))
                    {
                        entradaValida = true;
                        tabuleiro[linhaLetra2][colunaNumero2] = HIDROAVIAO;
                         cout << endl << "mostrando tabuleiro depois da coordenada " << i << endl;
                    imprimirTabuleiro(tabuleiro);
                    }
                    else
                    {
                        entradaValida = false;
                        cout << endl
                             << VERMELHO << "Nao forma HIDROAVIAO" << endl;

                        // TODO posso dividir a funcao validar hidro para não excluir a primeira posicao se for valida
                        
                        tabuleiro[linhaLetra1][colunaNumero1] = AGUA;
                        i--;
                    }
                    
                } else if (i == 3)
                {
                    colunaNumero3 = gerarNumeroAleatorio(colunaNumero1 - 1, colunaNumero1 + 1);

                    linhaLetra3 = gerarNumeroAleatorio(linhaLetra1 - 1, linhaLetra1 + 1);

                    //validarTerceiraFormaHidro(int colunaNumero2, int colunaNumero3,  int letra2, int letra3, char m[15][15])

                    if (hidrohaviao1.validarTerceiraFormaHidro( colunaNumero2, colunaNumero3,  linhaLetra2, linhaLetra3, tabuleiro))
                    {
                        entradaValida = true;
                        tabuleiro[linhaLetra3][colunaNumero3] = HIDROAVIAO;
                    }
                    else
                    {
                        entradaValida = false;
                        cout << endl
                             << VERMELHO << "Nao forma HIDROAVIAO" << endl;

                        // TODO posso dividir a funcao validar hidro para não excluir a primeira posicao se for valida
                        tabuleiro[linhaLetra1][colunaNumero1] = AGUA;
                        tabuleiro[linhaLetra2][colunaNumero2] = AGUA;
                        i--;
                        i--;
                    }
                }

            } while (!(entradaValida));
            // limparTela();
            cout << endl << "analise o desenho " << endl;
            //cin  >> pause;
            imprimirTabuleiro(tabuleiro);

        } // fim do HIDROAVIAO
    } // Fim do for que adiciona hidro
}

void atirar(char tabuleiroAdversario[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    int posicaoNumero;
    int posicaoLetra;
    bool entradaValida = false;

    cout << "Digite a letra da coordenada para o tiro (A-J): ";
    char letra;
    do
    {
        cin >> letra;
        letra = toupper(letra);
        posicaoLetra = letra - 'A';
        if (posicaoLetra >= 0 && posicaoLetra < TAMANHO_TABULEIRO)
        {
            entradaValida = true;
        }
        else
        {
            cout << "Letra fora do limite. Digite novamente (A-J): ";
        }
    } while (!entradaValida);

    entradaValida = false;
    cout << "Digite o nC:mero da coordenada para o tiro (1-15): ";
    do
    {
        posicaoNumero = validarNumero();
        posicaoNumero--; // Ajusta para o C-ndice de 0 a 14
        if (posicaoNumero >= 0 && posicaoNumero < TAMANHO_TABULEIRO)
        {
            entradaValida = true;
        }
        else
        {
            cout << "NC:mero fora do limite. Digite novamente (1-15): ";
        }
    } while (!entradaValida);

    // Verificar se a posiC'C#o jC! foi atacada
    if (tabuleiroAdversario[posicaoLetra][posicaoNumero] == TIRO_AGUA || tabuleiroAdversario[posicaoLetra][posicaoNumero] == TIRO_NAVIO)
    {
        cout << "VocC* jC! atirou nessa posiC'C#o. Escolha outra coordenada." << endl;
        return;
    }

    // Atualizar o tabuleiro de tiros
    if (tabuleiroAdversario[posicaoLetra][posicaoNumero] != AGUA)
    {
        // Acertou um navio
        tabuleiroAdversario[posicaoLetra][posicaoNumero] = TIRO_NAVIO;
        cout << "VocC* acertou um navio!" << endl;
        // Opcional: Adicionar lC3gica para verificar se o navio foi afundado
    }
    else
    {
        // Errou o tiro
        tabuleiroAdversario[posicaoLetra][posicaoNumero] = TIRO_AGUA;
        cout << "Cgua. Tiro perdido!" << endl;
    }

    // Mostrar o tabuleiro atual de tiros
}
/*
void adicionarBarcosAleatoriamente(char tabuleiro[15][15], char tipoBarco, int tamanhoBarco) {
    bool barcoAdicionado = false;
    while (!barcoAdicionado) {
        linha = rand() % TAMANHO_TABULEIRO;
        coluna = rand() % TAMANHO_TABULEIRO;
        for(int i = 1; i <= quantBarcos; i++) {

            bool entradaValida =false;
            do {

                indiceNumero = barco.LerIndiceNumero( entradaValida, i,tipoBarco);

                // trocar por encoracadop2
                indiceLetra1 = barco.LerIndiceLetra(i,tipoBarco);
                if(barco.tamanho == 1) {

                    tabuleiro[indiceLetra1][indiceNumero ] = simbolo;

                } else if(direcao == 1) {
                    int j = indiceNumero  + barco.tamanho ; // para controlar o laC'o
                    if(TAMANHO_TABULEIRO - indiceLetra1 >= barco.tamanho) {// verifica se possivel posicionar na vertical
                        entradaValida = true;
                        for(indiceNumero ; indiceNumero  <= j; indiceNumero++) {
                            tabuleiro[indiceLetra1][indiceNumero ] = simbolo;
                        }
                    } else
                    {
                        entradaValida = false;
                    }

                } else if( direcao == 2 ) {

                    int j = indiceLetra1  + barco.tamanho ; // para controlar o laco
                    if(TAMANHO_TABULEIRO - indiceNumero >= barco.tamanho) { // verifica se possivel posicionar na horizontal
                        entradaValida = true;
                        for(indiceLetra1; indiceLetra1 <= j; indiceLetra1++) {
                            tabuleiro[indiceLetra1][indiceNumero] = simbolo;
                        }

                    }

                }
                if(! (entradaValida))
                    cout << endl <<"Coordendas Invalidas";

            } while(! ( entradaValida ) );


            //limparTela();
            imprimirTabuleiro(tabuleiro);

        }
    }
*/
void BatalhaPvp()
{
    inicializarTabuleiro(tabuleiro1);
    inicializarTabuleiro(tabuleiro2);
    // inicializarTabuleiro(tabuleiroJogador2);
    string nomeJogador = "Wesley";
    int quantBarcos = 3 ;

    Submarino submarino1;
    Cruzador cruzador1;
    PortaAviao portaaviao1;
    Hidrohaviao hidrohaviao1;
    Encoracado encoracado;
    int continuar = 0;

    limparTela();

    displayTabuleiro();

    cout << endl
         << " Jogador " << nomeJogador << " Insira seus barcos" << endl;

    // Le o nome do Jogador
    cout << BRANCO << endl;
    // cout << "Jogador 1 informe o seu nome: " << endl;
    // getline(cin, nomeJogador);

    //adicionarHidroaviao(quantBarcos, hidrohaviao1, tabuleiro1);
     cpuAdicionaHidro(quantBarcos, hidrohaviao1, tabuleiro1);

    //	adicionarBarcos(quantBarcos, encoracado, E, ENCORACADO, tabuleiro1);
    // adicionarBarcos(quantBarcos, portaaviao1, P, PORTAAVIAO, tabuleiro1);
    //	adicionarBarcos(quantBarcos, cruzador1, C, CRUZADOR, tabuleiro1);
    // adicionarBarcos(quantBarcos, submarino1, S, SUBMARINO, tabuleiro1);

    cout << endl
         << " acabou ";
    cout << "Tecle < Qualquer numero > e < Enter> para trocar de jogador...";
    cout << endl;
    cin >> continuar;

    limparTela();
    cout << endl
         << "Jogador 2 ira colocar os barcos " << endl;
    cout << endl
         << " acabou ";

    // adicionarBarcos(quantBarcos, encoracado, E, ENCORACADO, tabuleiro2);
    //adicionarBarcos(quantBarcos, portaaviao1, P, PORTAAVIAO, tabuleiro2);
    //	adicionarBarcos(quantBarcos, cruzador1, C, CRUZADOR, tabuleiro2);
    // adicionarBarcos(quantBarcos, submarino1, S, SUBMARINO, tabuleiro2);

    cout << endl
         << " acabou ";
    cout << "Tecle < Qualquer numero > e < Enter> para trocar de jogador...";
    cout << endl;
    cin >> continuar;

    // passa o tabuleiro do adversC!rio  e o do jogador para marcar a jogada
    atirar(tabuleiro2);
    // imprimirTabuleiro(tabuleiroJogador1);
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
    cout << "Bem-vindo ao Programa2, mundo que ainda no?=o o?= mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}

void Programa3()
{
    limparTela();
    int resp = 0;
    cout << "Bem-vindo ao Programa3, mundo que ainda no?=o o?= mundo" << endl;
    cout << "Digite 0 para sair " << endl;
    cin >> resp;
    cin.ignore(80, '\n');
}

void Programa4()
{
    limparTela();
    int resp = 0;
    cout << "Bem-vindo ao Programa4, mundo que ainda no?=o o?= mundo" << endl;
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
    cout << "Entre com a opo?=o?=o desejada" << endl;
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
    cout << "Entre com a opo?=o?=o desejada" << endl;
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