#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return (p->qtde);
}

void freePilha(Pilha *p) {
	free(p);
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	float v;
	int podeDesempilhar = (! isEmpty(p));
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else {
		v = -1;
	}
	return v;
}

void print(Pilha *p) {
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "-----------------------" << endl;
	for(int i=p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "-----------------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaCrescente;
	pilhaCrescente = init();
	Pilha *pilhaPar;
	pilhaPar = init();
	Pilha *pilhaImpar;
	pilhaImpar = init();
	int valor;
	
	for(int i=0; i < 30; i++){
		if(isEmpty(pilhaCrescente)){
			cout << "Digite um numero maior que o digitado anteriormente: " << endl;
			cin >> valor;
			push(pilhaCrescente, valor);
		}else{
			do{
				cout << "Digite um numero maior que o digitado anteriormente: " << endl;
				cin >> valor;
			}while(valor <= pilhaCrescente->elementos[0]);
			push(pilhaCrescente, valor);	
		}
		
		if(valor % 2 == 0){
			push(pilhaPar, valor);
		}else{
			push(pilhaImpar, valor);
		}
		
		cout << "Valor salvo!" << endl;
		system("pause");
		system("cls");
	}
	
	print(pilhaCrescente);
	print(pilhaPar);
	print(pilhaImpar);
	
	
	return 0;
}