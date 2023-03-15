#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	int** baralho;
	baralho = new int*[104];
	int indice = 0;
	int* temp = new int[3];
	srand(time(0));
	
	for(int i = 0; i < 104; i++){
		baralho[i] = new int[3];
	}
	
	for(int b = 1; b < 3; b++){
		for(int n = 1; n < 5; n++){
			for(int c = 1; c < 14; c++){
				baralho[indice][0] = n;
				baralho[indice][1] = c;
				baralho[indice][2] = b;
				indice++;
			}
		}
	}
	
	
	for(int i = 0; i < 104; i++){
		
		int valorrand = rand() % (103+1 - 0) + 0;
		temp = baralho[valorrand];
		baralho[valorrand] = baralho[i];
		baralho[i] = temp;
		
	}
	

	
	cout << "Jogador 1" << endl;
	
	for(int i = 0; i < 11; i++){
		for(int l = 0; l < 3; l++){
			cout << baralho[i][l];
			cout << " ";
		}
		cout << endl << endl;
	}
	
	cout << "Jogador 2" << endl;
	
	for(int i = 11; i < 22; i++){
		for(int l = 0; l < 3; l++){
			cout << baralho[i][l];
			cout << " ";
		}
		cout << endl << endl;
	}
	
	cout << "Jogador 3" << endl;
	
	for(int i = 22; i < 33; i++){
		for(int l = 0; l < 3; l++){
			cout << baralho[i][l];
			cout << " ";
		}
		cout << endl << endl;
	}
	
	cout << "Jogador 4" << endl;
	
	for(int i = 33; i < 44; i++){
		for(int l = 0; l < 3; l++){
			cout << baralho[i][l];
			cout << " ";
		}
		cout << endl << endl;
	}
	
	
	return 0;
}