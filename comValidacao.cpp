#include <iostream>
#include <iomanip> // Inclua para usar setw
#include <cstdlib> // Para a funo?=o?=o atoi
#include <string>
#include <ncurses.h>
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
//titulo da embarcaC'C#o
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

	// validaC'C5es padrC#o inicio

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

	bool validaEntrada( int p1, int p2, char m[15][15])
	{
		if (p1 >= 0 && p1 <= 14 && p2 >= 0 && p2 <= 14 && m[p1][p2] == AGUA)
		{
			return  true;
		}
		return false;
	}
	// ValidaC'C5es padrC5es fim

	//Le a posiC'C#o letra
	int LerIndiceLetra(int ordinal,string embarcacao ) {

		char letra;
		int p;
		//cout << AMARELO << nomeJogador;
		cout << endl <<" Digite a [ LETRA ] da " << ordinal <<" posicoes para " << embarcacao << endl;
		cout << endl;
		cin >> letra;

		// Deixa a letra maiuscula
		letra = toupper(letra);
		p = letra - 'A';
		do {

			if (limiteNumero(p)) // veriica se o valor informado esta dentro das dimensC5es do tabuleiro
			{
				entrada = true; cout<< AMARELO << endl <<" Entrada valida NO  limite do tabuleiro";
                    cout << BRANCO;
			} else {
				entrada =false; cout << VERMELHO <<endl << " Entrada Invalida fora do limite do tabuleiro ";
                    cout << BRANCO;
			}
			if( ! ( entrada ) )
			{
				cout << endl << "valor fora do limite do tabuleiro";
				LerIndiceLetra(ordinal,embarcacao );
			}

		} while( ! (entrada) );

		return p ;
	}
	// Fazendo a funC'C#o ler indide numero

	int LerIndiceNumero(bool &entrada, int ordinal, string embarcacao ) {
		int p;
		int numereDeErros =0;
		cout << endl <<" Digite o [ NUMERO] da " << ordinal <<" posicoes para " << embarcacao << endl;
		cin >> p;
		cout << endl;
		p--;
		cout  <<endl << " DENTRO  da Fc Ler indice numero " <<endl;
		do
		{
		    numereDeErros++;
		    cout << endl <<"numero de vezes que passou Do da fc ler numero inteiro " << numereDeErros;
		    if (limiteNumero(p)) // veriica se o valor informado esta dentro das dimensões do tabuleiro
                {
                    entrada = true; cout << endl << AMARELO << endl <<" Entrada valida NO  limite do tabuleiro" << endl;
                    cout << BRANCO;
                } else {
                    entrada =false; cout << VERMELHO <<endl << " Entrada Invalida fora do limite do tabuleiro ";
                    cout << BRANCO;
                }
                if( ! ( entrada ) )
                {
                    cout << endl << "valor fora do limite do tabuleiro"; 
                    LerIndiceNumero(entrada, ordinal, embarcacao );
                }
                cout << endl << " entrada " << entrada;
		} while( ! (entrada) );
		cout << endl ;
		cout << " fim fc  LerIndiceNumero OK";
		return p;
		
	}

			virtual bool validarPosicao(int p1, int p2, char m[15][15]) = 0;
		};

		class hidrohaviao : public Embarcacoes
		{
		public:
			int p3;
			int p4;

			bool validarPrimeiroNumero(int p1)
			{
			    cout << "validar 1° num esta recebendo " << p1;
				if (p1 == 0 || p1 == 14)
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
					if (tabuleiro[i][j] == HIDROAVIAO)
					    {
					        
						    cout << BRANCO << setw(LARGURA_COLUNA) << tabuleiro[i][j];
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
			bool entradaValida = false;


			limparTela();

			displayTabuleiro();

			// Le o nome do Jogador
			cout << BRANCO << endl;
			//cout << "Jogador 1 informe o seu nome: " << endl;
			//getline(cin, nomeJogador);
			cout << endl << " BAtalha.pvp()";

			for (int j = 1; j <= 2; j++)
			{
			    cout <<endl <<j <<"° " << H;
				for (int i = 1; i <= 3; i++)
				{

					do
					{
						
						//TODO fazer passagem de parametro por referencia para pegar o resultado da validação
						//hidrohaviao1.LerIndiceNumero(entradaValida, i,H);

						if (i == 1)
							{
							   hidrohaviao1.posicao1 = hidrohaviao1.LerIndiceNumero(entradaValida, i,H);
								if ( hidrohaviao1.validarPrimeiroNumero( hidrohaviao1.posicao1 )) // verifica C) possivel formar o desenho
								{
									 //hidrohaviao1.p3 = hidrohaviao1.LerIndiceNumero( entradaValida, i,H);
									 cout << endl <<" valor na fc hidrohaviao1.LerIndiceNumero(entradaValida, i,H) " << hidrohaviao1.p3;
									entradaValida = true;
									cout << endl << " primeiro numero  Valido ";
								}
								else
								{
									entradaValida = false;
									cout << endl << " primeiro numero  Invalido ";
								}
							} else {
							    hidrohaviao1.posicao1 = hidrohaviao1.LerIndiceNumero( entradaValida, i,H);
							   // if (entradaValida)
							}
							
							
							if (!(entradaValida))
							{
								cout << "Posicao Invalida" << endl;
							}
				

					} while ( ! ( entradaValida ) );


					// hidrohaviao1.LerIndiceLetra( i, H);


					tabuleiro1[ hidrohaviao1.LerIndiceLetra( i, H)  ][ hidrohaviao1.posicao1 ] = HIDROAVIAO;
					limparTela();
					imprimirTabuleiro(tabuleiro1);
				}//fim do HIDROAVIAO
				
                //TODO Implentar outras embarcações
                /*
				cout << endl;
				cout << "  Digite o [ Numero ] 1 para encoracado";
				cin encoracadop1;
				cout << endl <<" Digite a [ letra ] da " <<"1" << "  posicoes para Encoracado ";
				cout << endl;
				cin >> letra;

				cout << endl;
				cout << "  Digite o [ Numero ] 1 para encoracado";
				cin encoracadop2;
				cout << endl <<" Digite a [ letra ] da " <<"2" << "  posicoes para Encoracado ";
				cout << endl;
				cin >> letra;

				for(int i= 0; i <= 3){

				}
				cout << endl;
				cout << "  Digite o [ Numero ] 1 para porta Aviao";
				cin >> portaAviaop1;
				cout << endl <<" Digite a [ letra ] da " <<"1B0" << "  posicoes para porta Aviao ";
				cout << endl;
				cin >> letra;

				cout << endl;
				cout << " Digite a posiC'C#o 2 para porta Aviao";
				cin >> portaAviaop2;
				cout << endl <<" Digite a [ letra ] da " <<"2B0" << "  posicoes para porta Aviao ";
				cout << endl;
				cin >> letra;

				for(int i= 0; i <= 5){

				}
				

				/*cout <<"Entrou no if";
				 if(hidrohaviao1.validaEntrada(hidrohaviao1.posicao1, hidrohaviao1.posicao2, tabuleiro1)){
				    cout << "Posicao valida" << endl;

				    // Marcar a position on tabuleiro
				    tabuleiro1[hidrohaviao1.posicao2][hidrohaviao1.posicao1] = HIDROAVIAO;
				    cout << endl << "Tabuleiro com a posiC'C#o inserida" << endl;
				    limparTela();
				    imprimirTabuleiro(tabuleiro1);
				} else {
				    cout << "Posicao invalida" << endl;
				}*/
			}
			/*
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
				} while (hidrohaviao1.limiteNumero(hidrohaviao1.posicao1)); // Verifica se a primeira posiC'C#o C) valida

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
			*/
			cout << endl <<" acabou ";		}
		

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