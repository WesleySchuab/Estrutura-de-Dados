#include <iostream>
using namespace std;

#define MAX 10  // Definindo o tamanho máximo da pilha

// Classe com todos os atributos e metodos
class Pilha {
private:
    int topo;           // Índice do topo da pilha
    int pilha[MAX];     // Array que armazena os elementos da pilha

public:
    Pilha() {
        topo = -1;       // Inicializa o topo da pilha como -1, indicando que está vazia
    }

    // Função para verificar se a pilha está vazia
    bool estaVazia() {
        return topo == -1;
    }

    // Função para verificar se a pilha está cheia
    bool estaCheia() {
        return topo == MAX - 1;
    }

    // Função para adicionar um elemento à pilha (push)
    void push(int elemento) {
        if (estaCheia()) {
            cout << "Erro: Pilha cheia!" << endl;
        } else {
            pilha[++topo] = elemento;  // Incrementa o topo e adiciona o elemento
            cout << "Elemento " << elemento << " inserido na pilha." << endl;
        }
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

    // Função para imprimir todos os elementos da pilha
    void imprimirPilha() {
        if (estaVazia()) {
            cout << "A pilha está vazia!" << endl;
        } else {
            cout << "Elementos da pilha: ";
            for (int i = topo; i >= 0; i--) {
                cout << endl << pilha[i] ;
            }
            cout << endl;
        }
    }
};

int main() {
    Pilha p;
    int opcao, elemento;
    cout << "Estrutura de Dados Pilha" << endl;
    cout << "Professor Avelino" << endl;


    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir elemento (push)\n";
        cout << "2. Remover elemento (pop)\n";
        cout << "3. Mostrar topo da pilha\n";
        cout << "4. Mostrar elementos da pilha\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (p.estaCheia()) {
                    cout << "Erro: A pilha está cheia. Não é possível inserir novos elementos." << endl;
                } else {
                    cout << "Digite o elemento a ser inserido: ";
                    cin >> elemento;
                    p.push(elemento);
                }
                break;
            
            case 2:
                p.pop();
                break;
            
            case 3:
                p.topoDaPilha();
                break;

            case 4:
                p.imprimirPilha();
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
