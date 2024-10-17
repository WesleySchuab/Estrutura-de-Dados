#include <iostream>
using namespace std;

// Classe com todos os atributos e metodos
class Pilha {
private:
    int topo;           // Índice do topo da pilha
    int* pilha;         // Ponteiro para o vetor que armazena os elementos da pilha
    int capacidade;     // Capacidade atual da pilha

public:
    Pilha() {
        topo = -1;       // Inicializa o topo da pilha como -1, indicando que está vazia
        capacidade = 2;   // Capacidade inicial da pilha
        pilha = new int[capacidade];  // Aloca o vetor dinamicamente
    }

    ~Pilha() {
        delete[] pilha;  // Libera a memória alocada pelo vetor
    }

    // Função para verificar se a pilha está vazia
    bool estaVazia() {
        return topo == -1;
    }

    // Função para verificar se a pilha está cheia
    bool estaCheia() {
        return topo == capacidade - 1;
    }

    // Função para redimensionar a pilha quando necessário
    void redimensionar() {
        int novaCapacidade = capacidade * 2;  // Dobrar a capacidade atual
        int* novaPilha = new int[novaCapacidade];  // Aloca um novo vetor maior

        // Copia os elementos da pilha antiga para a nova pilha
        for (int i = 0; i <= topo; i++) {
            novaPilha[i] = pilha[i];
        }

        // Libera a memória da pilha antiga e atualiza o ponteiro
        delete[] pilha;
        pilha = novaPilha;
        capacidade = novaCapacidade;
    }

    // Função para adicionar um elemento à pilha (push)
    void push(int elemento) {
        if (estaCheia()) {
            cout << "Pilha cheia! Redimensionando..." << endl;
            redimensionar();  // Redimensiona a pilha se estiver cheia
        }
        pilha[++topo] = elemento;  // Incrementa o topo e adiciona o elemento
        cout << "Elemento " << elemento << " inserido na pilha." << endl;
    }

    // Função para remover o elemento do topo da pilha (pop)
    void pop() {
        if (estaVazia()) {
            cout << "Erro: Pilha vazia!" << endl;
        } else {
            cout << "Elemento " << pilha[topo--] << " removido da pilha." << endl;
        }
    }

    // Função para ver o elemento do topo da pilha
    void topoDaPilha() {
        if (estaVazia()) {
            cout << "Erro: Pilha vazia!" << endl;
        } else {
            cout << "Elemento do topo: " << pilha[topo] << endl;
        }
    }

    // Função para mostrar o elemento no início da pilha (fundo da pilha)
    void inicioDaPilha() {
        if (estaVazia()) {
            cout << "Erro: Pilha vazia!" << endl;
        } else {
            cout << "Elemento no início da pilha: " << pilha[0] << endl;
        }
    }

    // Função para imprimir todos os elementos da pilha
    void imprimirPilha() {
        if (estaVazia()) {
            cout << "A pilha está vazia!" << endl;
        } else {
            cout << "Elementos da pilha: ";
            for (int i = topo; i >= 0; i--) {
                cout << pilha[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Pilha p;
    int opcao, elemento;
    cout << "Estrutura de Dados Pilha Dinamica" << endl;
    cout << "Professor Avelino" << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir elemento \n";
        cout << "2. Remover elemento \n";
        cout << "3. Mostrar topo da pilha\n";
        cout << "4. Mostrar início da pilha (fundo)\n";  // Nova opção
        cout << "5. Mostrar elementos da pilha\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o elemento a ser inserido: ";
                cin >> elemento;
                p.push(elemento);
                break;
            
            case 2:
                p.pop();
                break;
            
            case 3:
                p.topoDaPilha();
                break;

            case 4:
                p.inicioDaPilha();  // Mostrar início (fundo) da pilha
                break;

            case 5:
                p.imprimirPilha();
                break;

            case 6:
                cout << "Saindo do programa..." << endl;
                break;
            
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 6);

    return 0;
}
