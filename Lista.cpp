#include <iostream>

using namespace std; // Permite o uso de elementos do namespace std sem a necessidade de prefixo (como std::cout).

// Criando constantes para selecionar o SO
#if defined(_WIN32)
#define Plataforma 'w'
#elif defined(_WIN64)
#define Plataforma 'w'
#elif defined(__linux__)
#define Plataforma 'l'
#endif


// clear
void limparTela()
{
#ifdef _WIN32
	system("cls");
#else
	cout << "\033[2J\033[H";
#endif
}

class Node {
public:
	int data;
	Node* next;

	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() : head(nullptr) {}

	~LinkedList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Busca um elemento e retorna sua posiC'C#o ou -1 se nC#o encontrado
	int busca(int valor) {
		Node* current = head;
		int pos = 0;
		while (current) {
			if (current->data == valor) {
				return pos;
			}
			current = current->next;
			pos++;
		}
		return -1; // nC#o encontrado
	}

	// Insere um elemento no inC-cio
	void inserirInicio(int valor) {
		Node* newNode = new Node(valor);
		newNode->next = head;
		head = newNode;
	}

	// Insere um elemento no final
	void inserirFim(int valor) {
		Node* newNode = new Node(valor);
		if (!head) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = newNode;
	}

	// Remove um elemento por valor
	void removerPorValor(int valor) {
		if (!head) return;

		if (head->data == valor) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current = head;
		while (current->next && current->next->data != valor) {
			current = current->next;
		}

		if (current->next) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}

	// Remove um elemento por posiC'C#o
	void removerPorPosicao(int pos) {
		if (pos < 0 || !head) return;

		if (pos == 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current = head;
		for (int i = 0; current && i < pos - 1; i++) {
			current = current->next;
		}

		if (current && current->next) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}

	// Retorna o tamanho da lista
	int tamanho() {
		int count = 0;
		Node* current = head;
		while (current) {
			count++;
			current = current->next;
		}
		return count;
	}

	// Imprime os elementos da lista
	void imprimir() {
		Node* current = head;
		while (current) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	// Ordena a lista em ordem crescente (Bubble Sort)
	void ordenarCrescente() {
		if (!head) return;

		bool trocou;
		do {
			trocou = false;
			Node* current = head;
			while (current && current->next) {
				if (current->data > current->next->data) {
					std::swap(current->data, current->next->data);
					trocou = true;
				}
				current = current->next;
			}
		} while (trocou);
	}

	// Ordena a lista em ordem decrescente (Bubble Sort)
	void ordenarDecrescente() {
		if (!head) return;

		bool trocou;
		do {
			trocou = false;
			Node* current = head;
			while (current && current->next) {
				if (current->data < current->next->data) {
					std::swap(current->data, current->next->data);
					trocou = true;
				}
				current = current->next;
			}
		} while (trocou);
	}
};

int main() {
	LinkedList lista;
	int opcao, valor;

	do {
		std::cout << "Escolha uma operacao:\n";
		std::cout << "1. Insert in to the Begin\n";
		std::cout << "2. Inserir no final\n";
		std::cout << "3. Remover por valor\n";
		std::cout << "4. Remove by position\n";
		std::cout << "5. Buscar\n";
		std::cout << "6. Tamanho da lista\n";
		std::cout << "7. Imprimir lista\n";
		std::cout << "8. Ordenar crescente\n";
		std::cout << "9. Ordenar decrescente\n";
		std::cout << "0. Sair\n";
		std::cout << "Option: ";
		std::cin >> opcao;

		switch (opcao) {
		case 1:
			limparTela();
			std::cout << "Digite o valor para inserir no inicio: ";
			std::cin >> valor;
			lista.inserirInicio(valor);
			break;
		case 2:
			limparTela();
			std::cout << "Digite o valor para inserir no final: ";
			std::cin >> valor;
			lista.inserirFim(valor);
			break;
		case 3:
			limparTela();
			if(lista.tamanho() > 0 ) {
				std::cout << "Digite o valor para remover: ";
				std::cin >> valor;
				lista.removerPorValor(valor);
			} else
				cout << "Lista Vazia ";

			break;
		case 4:
			limparTela();
			if(lista.tamanho() > 0 ) {
				std::cout << "Digite a posiC'C#o para remover: ";
				std::cin >> valor;
				lista.removerPorPosicao(valor);
			} else
				cout << "Lista Vazia ";

			break;
		case 5:
			limparTela();
			if(lista.tamanho() > 0 ) {
				std::cout << "Digite o valor para buscar: ";
				std::cin >> valor;
				int pos;
				pos = lista.busca(valor);
				if (pos != -1) {
					limparTela();
					std::cout << "Valor encontrado on position: " << pos << std::endl;
				} else {
					limparTela();
					std::cout << "Value not founded." << std::endl;
				}

			}else
			    cout << "Lista Vazia ";


			break;
		case 6:
			std::cout << "Tamanho da lista: " << lista.tamanho() << std::endl;
			break;
		case 7:
		{
			limparTela();
			std::cout << "Lista: ";
			lista.imprimir();
			break;
		}
		case 8:
			lista.ordenarCrescente();
			std::cout << "Lista ordenada em ordem crescente." << std::endl;
			break;
		case 9:
			lista.ordenarDecrescente();
			std::cout << "Lista ordenada em ordem decrescente." << std::endl;
			break;
		case 0:
			std::cout << "Saindo..." << std::endl;
			break;
		default:
			std::cout << " ( Invalid Option ). Tente novamente." << std::endl;
		}
		std::cout << std::endl;
	} while (opcao != 0);

	return 0;
}
