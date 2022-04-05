#include <iostream>
#include <time.h>
#include <vector>
#include<windows.h>
using namespace std;

                    //  {{ '.','-','-','-','-','-','-','-','-','.'},
                    //   { '|','@','*','*','*','*','*','*','*','|'},
                    //   { '|','*','*','*','*','*','*','X','*','|'},
                    //   { '|','*','*','*','X','*','*','*','*','|'},
                    //   { '|','*','*','*','*','*','*','*','*','|'},
                    //   { '|','*','*','*','X','*','*','*','*','|'},
                    //   { '|','*','*','*','*','*','*','X','*','|'},
                    //   { '|','*','*','*','*','*','*','*','*','|'},
                    //   { '|','*','*','*','*','*','*','*','M','|'},
                    //   { '.','-','-','-','-','-','-','-','-','.'} }



void generowanie_pustej_mapy(char nowa_mapa[10][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if((i == 0 || i == 9) && (j > 0 && j < 9)) nowa_mapa[i][j] = '-';
                else if((i == 0 || i == 9) && (j == 0 || j == 9)) nowa_mapa[i][j] = '.';
                else if((i > 0 && i < 9) && (j == 0 || j == 9)) nowa_mapa[i][j] = '|';
            else nowa_mapa[i][j] = '*';
        }
    }
}
void generowanie_rand_ob(char mapa[10][10], int poziom_mapy,int &poz_y_gracza, int poz_x_gracza,int &poz_y_mety, int poz_x_mety) {
    srand(time(NULL));
    //wartosci początkowe i zmienne
    // normalnie majstersztyk tyy...
    int areszt_1, areszt_2;
    int koord_wstk[64][2];
    const int cst_odlicznik = 63;
    int odlicznik, zmienna_x, zmienna_y, losownik, intus_wyboru;
    bool czy_git = false;
    // zrobienie lvla
    int licznik_krzakow;
    if(poziom_mapy == 1) licznik_krzakow = 15;
    else if(poziom_mapy == 2) licznik_krzakow = 25;
    else licznik_krzakow = 35;
    /*
    tablica 2 wymiarowa, z wartosciami 
    y - x
    pyr pyr pyr...
    y - x przy 64 komórce
    */
    // po zmiennych
    while(czy_git == false) {
        //ustawienie od nowa wartości
        system("CLS");
        odlicznik = cst_odlicznik;
        zmienna_x = 1;
        zmienna_y = 1;
        //stworzenie czystej mapy
        for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    if((i == 0 || i == 9) && (j > 0 && j < 9)) mapa[i][j] = '-';
                        else if((i == 0 || i == 9) && (j == 0 || j == 9)) mapa[i][j] = '.';
                        else if((i > 0 && i < 9) && (j == 0 || j == 9)) mapa[i][j] = '|';
                    else mapa[i][j] = '*';
                }
            }
        // wylosowanie pozycjii gracza
        poz_y_gracza = rand()%6 + 2;
        mapa[poz_y_gracza][poz_x_gracza] = '@';
        //wylosowanie pozycjii mety
        poz_y_mety = rand()%6 + 2;
        mapa[poz_y_mety][poz_x_mety] = 'M';
        for(int i = 0;i < 64;i++ ) {
	    	if(zmienna_y == 9) {
	    		zmienna_x++;
	    		zmienna_y = 1;
	    	}
	    	for(int j = 0; j < 2; j++) {
		    	if(j == 0) {
		    		koord_wstk[i][j] = zmienna_x;
		    	} else {
		    		koord_wstk[i][j] = zmienna_y;
		    	}
		    }
		    zmienna_y++;
	    }
        // wyrzucanie wartości gracza i mety
        for(int i = 0;i < odlicznik;i++ ) {
            //kod wyrzucający pozycje gracza i jego przestrzeń osobistą
            if(koord_wstk[i][0] == poz_y_gracza && koord_wstk[i][1] == poz_x_gracza) {
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;

                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
            //przestrzeń osobista
            if((koord_wstk[i][0] == poz_y_gracza - 1 && koord_wstk[i][1] == poz_x_gracza)||(koord_wstk[i][0] == poz_y_gracza + 1 && koord_wstk[i][1] == poz_x_gracza)) {
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;

                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
            if(koord_wstk[i][0] == poz_y_gracza && koord_wstk[i][1] == poz_x_gracza + 1) {
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;

                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
            // pozycje mety i jej przestrzeń osobista
            if(koord_wstk[i][0] == poz_y_mety && koord_wstk[i][1] == poz_x_mety) {           
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;
            
                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
            //przestrzeń osobista
            if(koord_wstk[i][0] == poz_y_mety + 1 && koord_wstk[i][1] == poz_x_mety || koord_wstk[i][0] == poz_y_mety - 1 && koord_wstk[i][1] == poz_x_mety) {           
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;
            
                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
            if(koord_wstk[i][0] == poz_y_mety && koord_wstk[i][1] == poz_x_mety + 1) {           
                areszt_1 = koord_wstk[i][0];
                koord_wstk[i][0] = koord_wstk[odlicznik][0];
                koord_wstk[odlicznik][0] = areszt_1;
            
                areszt_2 = koord_wstk[i][1];
                koord_wstk[i][1] = koord_wstk[odlicznik][1];
                koord_wstk[odlicznik][1] = areszt_2;
                odlicznik--;
            }
        }
        // przy odliczniku teraz będzie wiadomo gdzie wywalić kolejną liczbe
        //losowanie krzaków
        for(int i = 0;i < odlicznik;i++) {
            // losowanie indeksu
            losownik = rand()%odlicznik;
            mapa[koord_wstk[losownik][0]][koord_wstk[losownik][1]] = 'X';

            areszt_1 = koord_wstk[losownik][0];
            koord_wstk[losownik][0] = koord_wstk[odlicznik][0];
            koord_wstk[odlicznik][0] = areszt_1;

            areszt_2 = koord_wstk[losownik][1];
            koord_wstk[losownik][1] = koord_wstk[odlicznik][1];
            koord_wstk[odlicznik][1] = areszt_2;
            odlicznik--;
            if(odlicznik == odlicznik - licznik_krzakow) break;
        }
        // wypisanie mapy bo wychodzi na to że nie można argumentu funkcjii do kolejnej funkcjii wsadzić
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cout << mapa[i][j] << ' ';
            }
            cout << '\n';
        }
        //koncowe pytanie
        cout << "Czy jest GIT? " << "\n1. TAK\n" << "2. NIE\n";
        cin >> intus_wyboru;
        if(intus_wyboru == 1) {
            czy_git = true;
        }
    }
}
void wypisanie(char mapencja[10][10]) {    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << mapencja[i][j] << ' ';
        }
    cout << '\n';
    }
}
void problem_13_krzakow(char mapa[10][10],int poziom_mapy) {
    srand(time(NULL));
    int poz_x_gracz = 1;
    int poz_x_met = 9;
    int ilosc_krzakow;
    // @ będzie w randomowym miejscu (wartosc x gracza jest zawsze taka sama = to jest int poz_x_gracz)
    int poz_y_gracza = rand()%8 + 1;
    mapa[poz_y_gracza][1] = '@';
    // Meta będzie losowana
    vector<int>poz_met;
    int rand_ilosc_met = rand()%2 + 1;
    int wybranie_wart_los_y_met;
    bool pytanie = true, pytanie2 = true;
    for(int i = 0; i < rand_ilosc_met; i++) {
        while(pytanie == true) {
            wybranie_wart_los_y_met = rand()%8 + 1;
            for(int j:poz_met) {
                if(wybranie_wart_los_y_met != j) {
                    mapa[wybranie_wart_los_y_met][9] = 'M';
                    poz_met.push_back(wybranie_wart_los_y_met);
                    pytanie == false;
                }
            }
        }
    }
    
    // krzaczki będą generowane randomowo
    int wybranie_los_wart_x_krzak, wybranie_los_wart_y_krzak;
    vector<int> poz_x_krzak;
    vector<int> poz_y_krzak;
    
    /* 
        łatwy lvl = 15 krzaczków
        średni lvl = 25 krzaczków
        ciężki lvl = 35 krzaczków
    */
    if(poziom_mapy == 1) {
        ilosc_krzakow = 15;
    } else if (poziom_mapy == 2)
    {
        ilosc_krzakow = 25;
    } else if(poziom_mapy == 3) {
        ilosc_krzakow = 35;
    }
    
    pytanie = true;
    if(poziom_mapy == 1) {
        for(int i = 0; i < ilosc_krzakow; i++) {
            while(pytanie2 == true) {
                bool czy_wszystko = true;
                bool czy_wart_x = false;
                bool czy_wart_y = false;
                wybranie_los_wart_x_krzak = rand()%8 + 1;
                wybranie_los_wart_y_krzak = rand()%8 + 1;
                    // sprawdzanie wartości z metami
                for(int j : poz_met) {
                    if(wybranie_los_wart_y_krzak == j) {
                        czy_wszystko = false;
                        break;
                    }
                    if(wybranie_los_wart_y_krzak == j + 1)
                        czy_wszystko = false;
                    if(wybranie_los_wart_y_krzak == j - 1)
                        czy_wszystko = false;
                    if(wybranie_los_wart_x_krzak == poz_x_met - 1 && wybranie_los_wart_y_krzak == j) 
                        czy_wszystko = false;
                }
                //sprawdzanie wartości z innymi krzakami
                for(int k:poz_x_krzak) {
                    if (wybranie_los_wart_x_krzak == k) {
                        czy_wart_x = true;
                        break;
                    }
                }
                for(int k:poz_y_krzak) {
                    if(wybranie_los_wart_y_krzak == k) {
                        czy_wart_y = true;
                        break;
                    }
                }
                if(czy_wart_x == true && czy_wart_y == true) {
                    czy_wszystko = false;
                }
                //sprawdzanie wartości z graczem
                if(wybranie_los_wart_x_krzak == poz_x_gracz && wybranie_los_wart_y_krzak == poz_y_gracza){
                    czy_wszystko == false;
                }
                if(wybranie_los_wart_x_krzak == poz_x_gracz + 1) {
                    czy_wszystko == false;
                }
                if(czy_wszystko == true) {
                    mapa[wybranie_los_wart_y_krzak][wybranie_los_wart_x_krzak] = 'X';
                    poz_x_krzak.push_back(wybranie_los_wart_x_krzak);
                    poz_y_krzak.push_back(wybranie_los_wart_y_krzak);
                }
            }
        }
    }
}
int main() {
    char mapa[10][10];
    int poziom_mapy = 2, poz_x_gracza = 1, poz_x_mety = 8, poz_y_gracza, poz_y_mety; 

    
    // printf("To jest poziom %d , a to jest m %s", poziom_mapy, m);
    // for(int i = 6; i > 0; i--) {
    //     system("CLS");
    //         for(int m = 6; m > i; m--) {
    //             cout << " " << '\n';
    //         }
    //         cout << "\n = = = = = = M O N K E - T H E  G A M E = = = = = = " << '\n';
    //     Sleep(500);
    // }
}