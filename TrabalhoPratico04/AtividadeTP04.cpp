#include <iostream>
using namespace std;

class Funcionario
{
	private:
		int prontuario;
		string nome;
		double salario;
    public:
    	Funcionario(string nome, int prontuario, double salario) {
			this->nome = nome;
            this->prontuario = prontuario;
			this->salario = salario;	
		}
    	Funcionario() {
			this->nome = "";
            this->prontuario = 0;
			this->salario = 0.0;			
		}
		void setNome(string nome) {
			this->nome = nome;
		}
		void setProntuario(int prontuario) {
			this->prontuario = prontuario;
		}
		void setSalario(double salario) {
			this->salario = salario;
		}
		string getNome() {
			return this->nome;
		}
		int getProntuario() {
			return this->prontuario;
		}
		double getSalario() {
			return this->salario;
		}
        
		 	
};

struct Lista
{
	Funcionario *dado;
	struct Lista *prox;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, Funcionario *i)
{
	Lista* novo = new Lista();
	novo->dado = i;
	novo->prox = lista;
	return novo;
}

void print(Lista* lista)
{
	Lista* aux = lista;
	double soma = 0;
	
	while (aux != NULL)
	{
		cout << "Prontuario: " << aux->dado->getProntuario() << endl;
		cout << "Nome: " << aux->dado->getNome() << endl;
		cout << "Salario: " << aux->dado->getSalario() << endl;
		cout << "-----------------------------------------------------" << endl;
		soma += aux->dado->getSalario();
		aux = aux->prox;
	}
	cout << "Total dos salarios: " << soma << endl;
}

Lista* find(Lista* lista, int i)
{
	Lista* aux = lista;
	
	while (aux != NULL && aux->dado->getProntuario() != i)
	{
		aux = aux->prox;
	}
	return aux;
}

Lista* remove(Lista* lista, Funcionario *i)
{
	Lista* ant = NULL;
	Lista* aux = lista;
	
	while (aux != NULL && aux->dado != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		return lista;
	}
	if (ant == NULL)
	{
		lista = aux->prox;	
	}
	else
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

Funcionario* incluir(Lista *l1){
	string nome;
	int pront;
	double sal;
	
	cout << "Digite o prontuario do funcionario à inserir: ";
	cin >> pront;
	
	if(find(l1, pront) != NULL){
		cout << "Erro! prontuario ja existente, tente novamente!" << endl;
		return NULL;
	}
	else{
		cout << "Digite o nome do funcionario à inserir: ";
		cin >> nome;
	
		cout << "Digite o salario do funcionario à inserir: ";
		cin >> sal;
	
	
	
		Funcionario *f = new Funcionario(nome, pront, sal);
	
		return f;
	}

}

void pesquisar(Lista *l1){
	
}

void listar(Lista *l1){
	
}

int main(int argc, char** argv)
{
	Lista *l1;
	l1 = init();
	int sel = 1;
	Funcionario *func;
	int pron;
	Lista *proc;
	
	while(sel != 0){
		
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		cin >> sel;
		
		system("cls");
		
		switch(sel)
		{
	   	case 0:
	  		cout << "Saindo..." << endl;
	  		break;
		case 1:
			func = incluir(l1);
			if(func != NULL){
				l1 = insert(l1, func);
			}
		   	break;
		case 2:
			cout << "Digite o prontuario do funcionario que deseja excluir: ";
			cin >> pron;
		   	if(find(l1, pron) != NULL){
				   l1 = remove(l1, find(l1, pron)->dado);
				   cout << "Funcionario Removido!" << endl;
			}else{
				cout << "Funcionario nao existe!" << endl;
			}
		   	break;
		case 3:
			cout << "Digite o prontuario do funcionario: ";
			cin >> pron;
			proc = find(l1, pron);
		   	if(proc != NULL){
 	    		cout << "Funcionario Encontrado!" << endl;
				cout << "Prontuario: "<< proc->dado->getProntuario() << endl;
				cout << "Nome: "<< proc->dado->getNome() << endl;
				cout << "Salario: "<< proc->dado->getSalario() << endl;
			}else{
				cout << "funcionario nao encontrado!" << endl;
			}
		   	break;
		case 4:
		   	print(l1);
		   	break;
		default:
		   	cout << "Erro! valor invalido" << endl;
		   	break;
		}
		system("pause");
		system("cls");
	}
	
	
	
	return 0;
}