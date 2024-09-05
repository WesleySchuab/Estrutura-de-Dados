        #include <iostream>
        #include <iomanip> // Inclua para usar setw
        #include <cstdlib>  // Para a fun  o atoi
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
      //const char NAVIO = 'X';
      const char HIDROAVIAO = 'H';
      const char PORTAAVIAO = 'P';
      //const char TIRO_AGUA = '~';
      //const char TIRO_NAVIO = '*';

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

        void limparTela() {
            #ifdef _WIN32
                system("cls");
            #else
                cout << "\033[2J\033[H";
            #endif
        }

        void inicializarTabuleiro(char tabuleiro[15][15]){
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                        tabuleiro[i][j] = AGUA;
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
          bool validaEntrada(int p1, int p2, char m[15][15]) {
              if (p1 >= 0 && p1 <= 14 && p2 >= 0 && p2 <= 14 && m[p1][p2] == AGUA) {            
                  return true;
              }
              return false;
          }
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
          return p --;
        }
          int LerIndiceNumero(int ordinal, string embarcacao ){
               int p;
               cout << endl <<" Digite o [ NUMERO] da " << ordinal <<" posicoes para " << embarcacao << endl;
                cin >> p;
                cout << endl;         
              return p - 1;
          }


            virtual bool validarPosicao(int p1, int p2, char m[15][15]) = 0;
        };

        class hidrohaviao : public Embarcacoes {
        public:
            int p3;
            int p4;

            bool validarPosicao(int p1, int p2, char m[15][15]) override {           
                if (p1 == 1 || p1 == 14) {
                    return false;
                }
                else {          
                    return true;
                }         

            }
        };

        class portaAviao : public Embarcacoes {
        public:
            int p3;
            int p4;
        
                 bool validarPosicao(int p1, int p2, char m[15][15]) override {           
                if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
                    // Verificar posi  o espec fica do porta-avi es
                    return true;
                }
                return false;
            }
        };

        class encoracado : public Embarcacoes {
        public:
            int p3;
            int p4;

                 bool validarPosicao(int p1, int p2, char m[15][15]) override {           
              // User insert 1 but it should be 0
                if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
                    // analise da posicao do encoracado
                    return true;
                }
                return false;
            }
        };

        

        class cruzador : public Embarcacoes {
        public:
            int p3;
            int p4;

                 bool validarPosicao(int p1, int p2, char m[15][15]) override {           
                if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
                    // Verificar posi  o espec fica do cruzador
                    return true;
                }
                return false;
            }
        };

        class submarino : public Embarcacoes {
        public:
            int p3;
            int p4;

                 bool validarPosicao(int p1, int p2, char m[15][15]) override {           
                if (p1 >= 0 && p1 < 15 && p2 >= 0 && p2 < 15 && m[p1][p2] == 0) {
                    // Verificar posi  o espec fica do submarino
                    return true;
                }
                return false;
            }
        }; 

      //TODO a impressão do tabuleiro tem que ser
        void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
            char vetorLetras[TAMANHO_TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
            const int LARGURA_COLUNA = 3; // Largura de cada coluna, ajuste conforme necess rio

            // Imprimir os n meros na parte superior
            cout << "   "; // Espa o inicial para alinhar n meros
            for (int i = 1; i < TAMANHO_TABULEIRO + 1; i++) {
                cout << AMARELO  << setw(LARGURA_COLUNA) << i; // Imprime o n mero da coluna com largura fixa
            }
            cout << endl;
            cout << endl; // Pula uma linha depois de escrever os numeros

            // Imprimir o tabuleiro com letras na vertical
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                cout << AMARELO << setw(2) << vetorLetras[i] << " "; // Imprime a letra da linha com espa amento fixo

                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                    if(tabuleiro[i][j] == HIDROAVIAO)
                        cout << BRANCO << setw(LARGURA_COLUNA) << tabuleiro[i][j]; 
                    else
                      cout << AZULC << setw(LARGURA_COLUNA) << tabuleiro[i][j]; 
                }
                cout << endl;
            }
        }

        void displayTabuleiro (){
            limparTela();
            inicializarTabuleiro(tabuleiro);
            imprimirTabuleiro(tabuleiro);
        }
        void addHidro( hidrohaviao hidrohaviao1, int qt,string h){
            for (int i = 1; i <= qt; i++){
                if( hidrohaviao1.validarPosicao(hidrohaviao1.LerIndiceLetra(i,h),hidrohaviao1.LerIndiceNumero(i,h),tabuleiro1))
                {
                     tabuleiro1[hidrohaviao1.LerIndiceLetra(i,h)][ hidrohaviao1.LerIndiceNumero(i,h)] = HIDROAVIAO;
                }
               
          }
             imprimirTabuleiro(tabuleiro1);
        }
        void adicionaPortaAviao( portaAviao embarcacao,  int qt,string h){
            for (int i = 1; i <= qt; i++){
                if( embarcacao.validarPosicao(embarcacao.LerIndiceLetra(i,h), embarcacao.LerIndiceNumero(i,h), tabuleiro1 )){
                    
                    tabuleiro1[embarcacao.LerIndiceLetra(i,h)][ embarcacao.LerIndiceNumero(i,h)] = PORTAAVIAO;
                }
                
              
          }
             imprimirTabuleiro(tabuleiro1);
        }
        //void adiciona 



        void BatalhaPvp(){
            inicializarTabuleiro(tabuleiro1);
            inicializarTabuleiro(tabuleiro2);
            string nomeJogador =  "";
            string h = "HidroAviao";
            string p = "PortaAviao";
            char letra ;
            hidrohaviao hidrohaviao1;
            portaAviao portaaviao;
        
            limparTela();

            displayTabuleiro();

            // Le o nome do Jogador
            cout << BRANCO << endl;
            cout << "Jogador 1 informe o seu nome: " << endl;
            getline(cin, nomeJogador);
            cout << AMARELO << nomeJogador;

            //addHidro(hidrohaviao1,3,h);
            adicionaPortaAviao( portaaviao, 3, p);
            imprimirTabuleiro(tabuleiro);
            
           
            /*

           for(int i = 0; i <= 3; i++){
               if (i==0){
                   do {
                       cout << endl <<" Digite o [ Numero ] da 1 posicoes para HidroAviao "<< endl;
                       cin >> hidrohaviao1.posicao1;
                       cout << endl;
                       cout << AMARELO << nomeJogador;                                
                    }
                    while  (hidrohaviao1.posicao1 == 1 || hidrohaviao1.posicao1 == 14) ; // Verifica se a primeira posição é valida 
                   hidrohaviao1.posicao2 = LerIndiceLetra();
               } else if(i==1){
                   do{
                       cout << endl <<" Digite o [ Numero ] da " << i <<" posicoes para HidroAviao "<< endl;
                         cin >> hidrohaviao1.p3;
                         cout << endl;
                   } while(hidrohaviao1.p3 == hidrohaviao1.posicao1 );
               }





               if(hidrohaviao1.validaEntrada(hidrohaviao1.posicao1, hidrohaviao1.posicao2, tabuleiro1)){
                 cout << "Posicao valida" << endl;

                 // Marcar a position on tabuleiro
                 tabuleiro1[hidrohaviao1.posicao2][hidrohaviao1.posicao1] = HIDROAVIAO;
                 cout << endl << "Tabuleiro com a posição inserida" << endl;



               } else {
                 cout << "Posicao invalida" << endl;
               }*/
      imprimirTabuleiro(tabuleiro1);




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
            cout << "Bem-vindo ao Programa2, mundo que ainda n o   mundo" << endl;
            cout << "Digite 0 para sair " << endl;
            cin >> resp;
            cin.ignore(80, '\n');
        }

        void Programa3(){
            limparTela();
            int resp = 0;
            cout << "Bem-vindo ao Programa3, mundo que ainda n o   mundo" << endl;
            cout << "Digite 0 para sair " << endl;
            cin >> resp;
            cin.ignore(80, '\n');
        }

        void Programa4(){
            limparTela();
            int resp = 0;
            cout << "Bem-vindo ao Programa4, mundo que ainda n o   mundo" << endl;
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
            cout << "Entre com a op  o desejada" <<endl;
            cin >> resp;
            cin.ignore(80, '\n');
            switch(resp)
            {
                case 1: BatalhaPvp();
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
            cout << "Entre com a op  o desejada" <<endl;
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