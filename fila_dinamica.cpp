#include <iostream>
using namespace std;

// Classe com todos os atributos e metodos
class Fila {
private:
    int frente;          // Índice do primeiro elemento da fila
    int tras;            // Índice do último elemento da fila
    int* fila;           // Ponteiro para o vetor que armazena os elementos da fila
    int capacidade;      // Capacidade atual da fila

public:
    Fila() {
        frente = 0;      // Inicializa a frente da fila
        tras = -1;       // Inicializa o tras da fila como -1, indicando que está vazia
        capacidade = 2;   // Capacidade inicial da fila
        fila = new int[capacidade];  // Aloca o vetor dinamicamente
    }

    ~Fila() {
        delete[] fila;   // Libera a memória alocada pelo vetor
    }

    // Função para verificar se a fila está vazia
    bool estaVazia() {
        return frente > tras;
    }

    // Função para verificar se a fila está cheia
    bool estaCheia() {
        return tras == capacidade - 1;
    }

    // Função para redimensionar a fila quando necessário
    void redimensionar() {
        int novaCapacidade = capacidade * 2;  // Dobrar a capacidade atual
        int* novaFila = new int[novaCapacidade];  // Aloca um novo vetor maior

        // Copia os elementos da fila antiga para a nova fila
        for (int i = frente; i <= tras; i++) {
            novaFila[i - frente] = fila[i];  // Reorganiza os índices
        }

        // Atualiza os índices
        tras = tras - frente;
        frente = 0;

        // Libera a memória da fila antiga e atualiza o ponteiro
        delete[] fila;
        fila = novaFila;
        capacidade = novaCapacidade;
    }

    // Função para adicionar um elemento à fila (enqueue)
    void enqueue(int elemento) {
        if (estaCheia()) {
            cout << "Fila cheia! Redimensionando..." << endl;
            redimensionar();  // Redimensiona a fila se estiver cheia
        }
        fila[++tras] = elemento;  // Incrementa o tras e adiciona o elemento
        cout << "Elemento " << elemento << " inserido na fila." << endl;
    }

    // Função para remover o elemento da frente da fila (dequeue)
    void dequeue() {
        if (estaVazia()) {
            cout << "Erro: Fila vazia!" << endl;
        } else {
            cout << "Elemento " << fila[frente++] << " removido da fila." << endl;
        }
    }

    // Função para ver o elemento da frente da fila
    void frenteDaFila() {
        if (estaVazia()) {
            cout << "Erro: Fila vazia!" << endl;
        } else {
            cout << "Elemento da frente: " << fila[frente] << endl;
        }
    }

    // Função para imprimir todos os elementos da fila
    void imprimirFila() {
        if (estaVazia()) {
            cout << "A fila está vazia!" << endl;
        } else {
            cout << "Elementos da fila: ";
            for (int i = frente; i <= tras; i++) {
                cout << fila[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Fila f;
    int opcao, elemento;

    cout << "Estrutura de Dados Fila dinamica" << endl;
    cout << "Professor Avelino" << endl;


    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir elemento \n";
        cout << "2. Remover elemento \n";
        cout << "3. Mostrar frente da fila\n";
        cout << "4. Mostrar elementos da fila\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o elemento a ser inserido: ";
                cin >> elemento;
                f.enqueue(elemento);
                break;
            
            case 2:
                f.dequeue();
                break;
            
            case 3:
                f.frenteDaFila();
                break;

            case 4:
                f.imprimirFila();
                break;

            case 5:
                cout << "Saindo do programa..." << endl;
                break;
            
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 5);

    return 0;
}
