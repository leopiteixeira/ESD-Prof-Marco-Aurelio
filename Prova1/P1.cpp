#include <iostream>
#include <locale.h>
#include <string>
#include<stdio.h>
#include<time.h>
#include <cstdlib>
using namespace std;

class Data
{
	private:
		int dia;
		int mes;
		int ano;
    public:
    
    	Data(int dia, int mes, int ano) {
			this->dia = dia;
            this->mes = mes;
			this->ano = ano;			
		}
    	Data() {
			this->dia = 0;
            this->mes = 0;
			this->ano = 0;			
		}
		void setDia(int dia) {
			this->dia = dia;
		}
		void setMes(int mes) {
			this->mes = mes;
		}
		void setAno(int ano) {
			this->ano = ano;
		}
		int getDia() {
			return this->dia;
		}
		int getMes() {
			return this->mes;
		}
		int getAno() {
			return this->ano;
		}
		string getData()
        {
            return to_string(this->dia) + "/" +
                   to_string(this->mes) + "/" +
           		   to_string(this->ano);	  
        }
        
        Data* dia_seguinte()
		{
			Data *d1;
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			d1 = new Data(this->dia, this->mes, this->ano);
			if (d1->ano%4==0)
			{
				diasNoMes[1]++;
			}
			d1->dia++;
			if(d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			return d1;
		}
		 	
};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		Data *dtnasc;
    public:
    	Contato(string nome, string email, string telefone, Data *dtnasc) {
			this->nome = nome;
            this->email = email;
			this->telefone = telefone;
			this->dtnasc = dtnasc;		
		}
    	Contato() {
			this->nome = "";
            this->email = "";
			this->telefone = "";
			this->dtnasc = new Data();			
		}
		void setNome(string nome) {
			this->nome = nome;
		}
		void setEmail(string email) {
			this->email = email;
		}
		void setTelefone(string telefone) {
			this->telefone = telefone;
		}
		void setData(int dia, int mes, int ano) {
			this->dtnasc = new Data(dia,mes,ano);
		}
		string getNome() {
			return this->nome;
		}
		string getEmail() {
			return this->email;
		}
		string getTelefone() {
			return this->telefone;
		}
		string getData()
        {
            return to_string(this->dtnasc->getDia()) + "/" +
                   to_string(this->dtnasc->getMes()) + "/" +
           		   to_string(this->dtnasc->getAno());	  
        }
        
        int idade(int anoAtual){
			return anoAtual - (this->dtnasc->getAno());
		}
        
		 	
};

int main(int argc, char** argv)
{
	string n, e, t;
	int dia, mes, ano, ind;
	ind = 0;
	double soma = 0;
	int maiores = 0;
	int maiorId = 0;
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int anoAtual = tm.tm_year + 1900;
    
    Data *d;
    
    Contato* contatos[10];
	
	for(int i = 1; i <= 10; i++){
		cout << "Digite o nome do contato " << i << ": ";
		cin >> n;
		cout << "Digite o email do contato " << i << ": ";
		cin >> e;
		cout << "Digite o telefone do contato " << i << ": ";
		cin >> t;
		cout <<"Dia do nascimento do contato " << i << ": ";
		cin >> dia;
		cout <<"Mes do nascimento do contato " << i << ": ";
		cin >> mes;
		cout <<"Ano do nascimento do contato " << i << ": ";
		cin >> ano;
		
		d = new Data(dia, mes, ano);
		
		contatos[i - 1] = new Contato(n, e, t, d);
		
		system("cls");
		
		cout << "Contato Criado!" << endl;
	}
	
	for(int i = 0; i < 10; i++){
		soma += contatos[i]->idade(anoAtual);
		
		if(contatos[i]->idade(anoAtual) >= 18){
			maiores++;
		}
		
		if(contatos[i]->idade(anoAtual) > maiorId){
			maiorId = contatos[i]->idade(anoAtual);
		}
	}
	
	cout << endl;
	cout << "Media das idades: " << soma/10 << endl;
	cout << endl;
	
	cout << "Nomes das pessoas com idade maior que a media: " << endl;
	
	for(int i = 0; i < 10; i++){
		if(contatos[i]->idade(anoAtual) > soma/10){
			cout << contatos[i]->getNome() << endl;
		}
	}
	
	cout << endl;	
	cout << "Quantidade de maiores de idade: " << maiores << endl;
	cout << endl;	
	
	cout << "Contato(s) com a maior idade de todos: " << endl;
	
	for(int i = 0; i < 10; i++){
		if(contatos[i]->idade(anoAtual) == maiorId){
			cout << "Nome: " << contatos[i]->getNome() << endl;
			cout << "Email: " << contatos[i]->getEmail() << endl;
			cout << "Telefone: " << contatos[i]->getTelefone() << endl;
			cout << endl;
		}
	}
	
	
	while(ind < 11){
		cout << "quer que exiba qual contato(11 para sair):";
		cin >> ind;
		
		cout << "Nome: " << contatos[ind - 1]->getNome() << endl;
		cout << "Email: " << contatos[ind - 1]->getEmail() << endl;
		cout << "Telefone: " << contatos[ind - 1]->getTelefone() << endl;
		cout << "Data de nascimento: " << contatos[ind - 1]->getData() << endl;
		cout << "Idade: " << contatos[ind - 1]->idade(anoAtual) << endl;
		
		system("PAUSE");
		system("cls");
		
	}
	
	
	
	return 0;
}