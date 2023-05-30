#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while(no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "------------" << endl;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------" << endl;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

// Enfileirar
void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
	   f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}


// Desenfileirar
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

int main(int argc, char** argv)
{
	int sel = 1;
	Fila *senhasGeradas;
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	senhasGeradas = init();
	
	while(sel != 0){
		
		cout << "0. Sair" << endl;
		cout << "1. Gerar senha" << endl;
		cout << "2. Realizar atendimento" << endl;
		cout << "Senhas aguardando atendimento: " << count(senhasGeradas) << endl;
		cin >> sel;
		
		system("cls");
		
		switch(sel)
		{
	   	case 0:
	   		if(!isEmpty(senhasGeradas)){
				   sel = 3;
				   cout << "Nao foi possivel sair, pois ainda existem senhas na fila" << endl;
				   break;
			   }
  	        cout << "Senhas atendidas: " << count(senhasAtendidas) << endl;
	  		cout << "Saindo..." << endl;
	  		break;
		case 1:
			if(isEmpty(senhasGeradas)){
				enqueue(senhasGeradas, 1);
				cout << "Senha: 1" << endl;
				break;
			}
			enqueue(senhasGeradas, senhasGeradas->fim->dado + 1);
			cout << "Senha: " << senhasGeradas->fim->dado << endl;
		   	break;
		case 2:
			if(!isEmpty(senhasGeradas)){
				enqueue(senhasAtendidas, dequeue(senhasGeradas));
				cout << "Senha " << senhasAtendidas->fim->dado << " Atendida" << endl;
				break;
			}
			cout << "Nenhuma senha para ser atendida" << endl;
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