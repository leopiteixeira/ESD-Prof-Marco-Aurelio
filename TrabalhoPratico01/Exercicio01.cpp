#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

#define POL 40
#define FIL 15



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	int seletor;
	int x;
	int lugaresOcupados = 0;
	int bilheteria = 0;
	char **mapa;
	mapa = new char*[FIL];
	
	for(int i = 0; i < FIL; ++i){
		mapa[i] = new char[POL];
	}
	
	for(int l = 0; l < FIL; ++l){
		for(int c = 0; c < POL; ++c){
			mapa[l][c] = '.';
		}
	}
	
	do{		
		
		cout << "0.	Finalizar" << endl;
		cout << "1.	Reservar poltrona" << endl;
		cout << "2.	Mapa de ocupação" << endl;
		cout << "3.	Faturamento" << endl;
		cout << endl << "Digite sua ação: ";
		cin >> seletor;
		system("cls");
		
		switch(seletor)
		{
		case 0:
			cout << "Finalizando...";
			break;
		case 1:			
			int fileira;
			int poltrona;
			do{
				cout << "Digite a fileira da poltrona a ser reservada: ";
				cin >> fileira;
				if(fileira > FIL){
					cout << "Erro! Escolha um valor entre 1 e " << FIL << "!" << endl;
				}
			}while(fileira > FIL);
			
			do{
				cout << "Digite a poltrona a ser reservada: ";
				cin >> poltrona;
				if(poltrona > POL){
					cout << "Erro! Escolha um valor entre 1 e " << POL << "!"<< endl;
				}
			}while(poltrona > POL);
			
			if(mapa[fileira - 1][poltrona - 1] == '.'){
				mapa[fileira - 1][poltrona - 1] = '#';
				lugaresOcupados++;
				cout << "Poltrona reservada com sucesso" << endl;
			}else
			{
				cout << "Poltrona ocupada!" << endl;
			}
			break;
		case 2:
			cout << "     ";
			for(int i = 0; i < POL; ++i){
				cout << "| " << i + 1 << " ";
			}
			cout << endl;
			
			for(int l = 0; l < FIL; ++l){
				if(l + 1 < 10){
					cout << l + 1 << ".   |";
				}else{
					cout << l + 1 << ".  |";
				}
				
				for(int c = 0; c < POL; ++c){
					if(c < 9){
						cout << " " << mapa[l][c] << " |";
					}else{
						cout << " " << mapa[l][c] << "  |";
					}
					
				}
				cout << endl;
			}
			break;
		case 3:
			
			for(int l = 0; l < FIL; l++){
				for(int c = 0; c < POL; c++){
					if((l < FIL / 3) && (mapa[l][c] == '#')){
						bilheteria += 50;
					}else if((l < 2 * FIL / 3) && (mapa[l][c] == '#')){
						bilheteria += 30;
					}else if (mapa[l][c] == '#'){
						bilheteria += 15;
					}			
				}				
			}
			
			cout << "Qtde de lugares ocupados:          " << lugaresOcupados << endl;
			cout << "Valor da bilheteria:               R$ " << bilheteria << ",00" << endl;
			
			bilheteria = 0;
			break;
		default:
			cout << "Opção invalida, Selecione novamente!" << endl;
			break;
		}
		if(seletor == 0){
			break;
		}
		cout << "Digite 0 para voltar ao menu...";
		cin >> x;
		system("cls");
		
	}while(true);

	return 0;
}

