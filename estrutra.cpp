  #include <iostream>
  #include <iomanip> // Inclua para usar setw
  #include <cstdlib>  // Para a fun��o atoi
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

  // Cosntantes para as cores
  #define AMARELO "\x1b[33m"
  #define RESET "\x1b[0m"
  #define PRETO "\x1b[30m"
  #define VERDE "\x1b[32m"
  #define FBRANCO "\x1b[47m"
  #define VERMELHO "\x1b[91m"
  #define VERDEC "\x1b[92m"
  #define AZUL "\x1b[94m"
  #define AZULC "\x1b[96m"
  #define FCINZA "\x1b[100m"

  const int TAMANHO_TABULEIRO = 15;
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  int tabuleiro1[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
  int tabuleiro2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

  void limparTela() {
      #ifdef _WIN32
          system("cls");
      #else
          cout << "\033[2J\033[H";
      #endif
  }
  // fun��o que ir� preencher a tela com o caracter que representa �gua
  /*void inicializarTabuleiro(char tabuleiro[15][15]){
      for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
          for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
              tabuleiro[i][j] = 'O';
          }
      }
  }*/
  void inicializarTabuleiro(int tabuleiro[15][15]){
      for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
          for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
              tabuleiro[i][j] = 0;
          }
      }
  }

  class Embarcacoes {
  public:
      int posicao1;
      int posicao2;

      void entraEmbarcacoes() {
          cout << "Digite a primeira posicao: ";
          cin >> posicao1;
          cout << endl;

          cout << "Digite a segunda posicao: ";
          cin >> posicao2;
          cout << endl;
      }

      virtual bool validarPosicao(int p1, int p2, int m[15][15]) = 0;
  };
//TODO Inicializar a matriz jogador1
  class hidrohaviao : public Embarcacoes {
  public:
      int p3;
      int p4;

      bool validarPosicao(int p1, int p2, int m[15][15]) override {
          if (p1 >= 0 && p1 <= 14 && p2 >= 0 && p2 <= 14 && m[p1][p2] == 0) {
              // Verificar posi��o espec�fica do hidroavi�o
              return true;
          }
          return false;
      }
  };

  class encoracado : public Embarcacoes {
  public:
      int p3;
      int p4;

      bool validarPosicao(int p1, int p2, int m[15][15]) override {
          if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
              // Verificar posi��o espec�fica do encoura�ado
              return true;
          }
          return false;
      }
  };

  class portaAviao : public Embarcacoes {
  public:
      int p3;
      int p4;

      bool validarPosicao(int p1, int p2, int m[15][15]) override {
          if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
              // Verificar posi��o espec�fica do porta-avi�es
              return true;
          }
          return false;
      }
  };

  class cruzador : public Embarcacoes {
  public:
      int p3;
      int p4;

      bool validarPosicao(int p1, int p2, int m[15][15]) override {
          if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
              // Verificar posi��o espec�fica do cruzador
              return true;
          }
          return false;
      }
  };

  class submarino : public Embarcacoes {
  public:
      int p3;
      int p4;

      bool validarPosicao(int p1, int p2, int m[15][15]) override {
          if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
              // Verificar posi��o espec�fica do submarino
              return true;
          }
          return false;
      }
  };

  void imprimirTabuleiro() {
      char vetorLetras[TAMANHO_TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
      const int LARGURA_COLUNA = 3; // Largura de cada coluna, ajuste conforme necess�rio

      // Imprimir os n�meros na parte superior
      cout << "   "; // Espa�o inicial para alinhar n�meros
      for (int i = 1; i < TAMANHO_TABULEIRO + 1; i++) {
          cout << AMARELO  << setw(LARGURA_COLUNA) << i; // Imprime o n�mero da coluna com largura fixa
      }
      cout << endl;
      cout << endl; // Pula uma linha depois de escrever os numeros

      // Imprimir o tabuleiro com letras na vertical
      for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
          cout << AMARELO << setw(2) << vetorLetras[i] << " "; // Imprime a letra da linha com espa�amento fixo

          for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
              cout << AZULC << setw(LARGURA_COLUNA) << tabuleiro[i][j]; // Imprime o conte�do do tabuleiro com largura fixa
          }
          cout << endl;
      }
  }

  void displayTabuleiro (){
      limparTela();
      inicializarTabuleiro(tabuleiro);
      imprimirTabuleiro();
  }

  void BatalhaPvp(){
      string nomeJogador =  "";
      char letra ;
      int posicaoNumero;
      limparTela();
      displayTabuleiro();
      cout << endl;
      cout << "Jogador 1 informe o seu nome: " << endl;
      getline(cin, nomeJogador);
      cout << endl;
      cout << nomeJogador+" Digite o numero da 1� posicoes para HidroAviao ";
      cout << endl;
      hidrohaviao hidrohaviao1;
      cin >> hidrohaviao1.posicao1;
      cout << nomeJogador+" Digite a letra da 1� posicoes para HidroAviao ";
      cout << endl;
      cin >> letra;
      letra = toupper(letra);
      posicaoNumero = letra - 'A';
      posicaoNumero++;
      cout << posicaoNumero;
      //posicaNumero = atoi(letra);
     // hidrohaviao1.posicao2 = atoi(letra);
      //hidrohaviao.valiadarPosicao(hidrohaviao1.posicao1, hidrohaviao1.posicao);
      if(hidrohaviao1.validarPosicao(hidrohaviao1.posicao1, hidrohaviao1.posicao2, tabuleiro1)){
          cout << "Posicao valida" << endl;
          // Marcar a posi��o no tabuleiro
          tabuleiro[hidrohaviao1.posicao1][hidrohaviao1.posicao2] = 'H';
      } else {
          cout << "Posicao invalida" << endl;
      }
  }

  void menuBatalhaNaval(){
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
      switch(resp)
      {
          case 1: cout <<"Tu escolheu P x P" << endl;
             BatalhaPvp();
              break;
          case 2: cout <<"Tu escolheu P x CPU" << endl;
              break;
          case 3: cout <<"Tu escolheu CPU x P" << endl;
              break;
      }
  }

  void Programa2(){
      limparTela();
      int resp = 0;
      cout << "Bem-vindo ao Programa2, mundo que ainda n�o � mundo" << endl;
      cout << "Digite 0 para sair " << endl;
      cin >> resp;
      cin.ignore(80, '\n');
  }

  void Programa3(){
      limparTela();
      int resp = 0;
      cout << "Bem-vindo ao Programa3, mundo que ainda n�o � mundo" << endl;
      cout << "Digite 0 para sair " << endl;
      cin >> resp;
      cin.ignore(80, '\n');
  }

  void Programa4(){
      limparTela();
      int resp = 0;
      cout << "Bem-vindo ao Programa4, mundo que ainda n�o � mundo" << endl;
      cout << "Digite 0 para sair " << endl;
      cin >> resp;
      cin.ignore(80, '\n');
  }

  void MatrizesVetores(){
      limparTela();
      int resp = 0;
      cout << "Estrutura de Dados Matrizes e Vetores" << endl;
      cout <<endl;
      cout << "[1] Batalha Naval " <<endl;
      cout << "[2] Programa 2" <<endl;
      cout << "[3] Programa 3" <<endl;
      cout << "[4] Programa 4" <<endl;
      cout << "[0] Digite  para sair " << endl;
      cout << "Entre com a op��o desejada" <<endl;
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
      limparTela();
      int resp = 0;
      cout << "Estrutura de Dados" << endl;
      cout <<endl;
      cout << "[1] Matrizes e Vetores " <<endl;
      cout << "[2] Programa 2" <<endl;
      cout << "[3] Programa 3" <<endl;
      cout << "[4] Programa 4" <<endl;
      cout << "[0] Digite para sair " << endl;
      cout << "Entre com a op��o desejada" <<endl;
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
      setlocale(LC_ALL, "Portuguese");
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
