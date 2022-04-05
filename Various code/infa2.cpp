#include <iostream>
#include <time.h>
using namespace std;

/*
{{X,X} {Y,Y}, ... , {64,64} }
*/



int main()
{
	int tabela[64][2], zmienna_x = 1, zmienna_y = 1;
	for(int i = 0;i < 64;i++ ) {
		if(zmienna_y == 9) {
			zmienna_x++;
			zmienna_y = 1;
		}
		for(int j = 0; j < 2; j++) {
			if(j == 0) {
				tabela[i][j] = zmienna_x;
			} else {
				tabela[i][j] = zmienna_y;
			}
		}
		zmienna_y++;
	}
	
	for(int i = 0;i < 64;i++ ) {
		for(int j = 0; j < 2; j++) {
			cout << tabela[i][j] << ' ';
		}
	cout << '\n';
	}	
}