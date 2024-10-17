#include <iostream>
using namespace std;

#define MAX 10  // Definindo o tamanho máximo da fila

class Fila {
private:
    int frente;         // Índice do elemento da frente da fila
    int tras;           // Índice do elemento de trás da fila
    int fila[MAX];      // Array que armazena os elementos da fila

public:
    Fila() {
        frente = 0;     // Inicializa a frente da fila
        tras = -1;      // Inicializa o trás da fila como -1, indicando que está vazia
    }

    // Função para verificar se a fila está vazia
    bool estaVazia() {
        return frente > tras;
    }

    // Função para verificar se a fila está cheia
    bool estaCheia() {
        return tras == MAX - 1;
    }

    // Função para adicionar um elemento à fila (enqueue)
    void enqueue(int elemento) {
        if (estaCheia()) {
            cout << "Erro: Fila cheia!" << endl;
        } else {
            fila[++tras] = elemento;  // Incrementa o trás e adiciona o elemento
            cout << "Elemento " << elemento << " inserido na fila." << endl;
        }
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
    cout << "Estrutura de Dados Fila" << endl;
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
                if (f.estaCheia()) {
                    cout << "Erro: A fila está cheia. Não é possível inserir novos elementos." << endl;
                } else {
                    cout << "Digite o elemento a ser inserido: ";
                    cin >> elemento;
                    f.enqueue(elemento);
                }
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