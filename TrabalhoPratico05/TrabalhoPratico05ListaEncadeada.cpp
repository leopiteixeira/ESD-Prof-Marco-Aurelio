#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha();
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i = 0;
	No *no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

void print(Pilha *p) {
	No *no = p->topo;
	cout << "--------------" << endl;
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "--------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
    cout << "--------------" << endl;
}

void push(Pilha *p, float v) {
	No *no = new No();
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (!isEmpty(p));
	if (podeDesempilhar) {
		No *no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		free(no);
	}
	else {
		ret = -1;
	}
	return ret;
}

void freePilha(Pilha *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}
	free(p);
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
			}while(valor <= pilhaCrescente->topo->dado);
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