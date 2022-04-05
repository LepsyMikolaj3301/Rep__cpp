#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <vector>
#include <windows.h>

#define clr system("CLS");
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

void wypisanie(char mapencja[10][10]) {    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << mapencja[i][j] << ' ';
        }
    cout << '\n';
    }
}
void manual_przycisk( char przycisk ) {
    for(int i = 0; i < 3; i++ ) {
        
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
    clr;
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
        for(int i = 0;i < licznik_krzakow;i++) {
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
        }
        // wypisanie mapy bo wychodzi na to że nie można argumentu funkcjii do kolejnej funkcjii wsadzić
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cout << mapa[i][j] << ' ';
            }
            cout << '\n';
        }
        //koncowe pytanie
        cout << "Czy jest GIT? (wpisz liczbe)" << "\n1. TAK\n" << "2. NIE\n";
        cin >> intus_wyboru;
        if(intus_wyboru == 1) {
            czy_git = true;
        }
    }
}
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
void ramka(string przycisk) {
    cout << ".";
    for(int i = 0; i < przycisk.length() + 2; i++ ) {
        cout << "-";
    }
    cout << "." << '\n';
    cout << "| " << przycisk << " |" << '\n';
    cout << ".";
    for(int i = 0; i < przycisk.length() + 2; i++ ) {
        cout << "-";
    }
    cout << "." << '\n';
}
// tworzenie mapy
                // 2 sposoby
                // 1. konstruktor
                // konstrukcja mapy poprzez przesuwanie tzw konstuktora, po naciśnięciu przycisku { coś } będzie można
                //  w switchu wybrać przeszkodę, gracza i metę w obecnym miejscu konstruktora
                // 2. koordynaty (prostszy)
                // gracz wpisuje w pętli koordynaty i rodzaj obiektu
// what to do:
// score
// jumpa *
int main() {
        // zmienne
        setlocale(LC_ALL, " ");
        srand(time(NULL));
        // mapa robocza
        char mapa[10][10], tymczas_mapa[10][10];
        //projekty uzytkownika
        char projekt1[10][10],projekt2[10][10],projekt3[10][10];
        // automatycznie stworzone mapy
        char AVTOMAT_project_easy[10][10], AVTOMAT_project_medium[10][10], AVTOMAT_project_hard[10][10];
        //inty
        int akt_poz_x_gracz = 1, akt_poz_y_gracz, akt_poz_x_mety = 8, akt_poz_y_mety;
        int ost_poz_x_gracz, ost_poz_y_gracz;
        
        int wybor_trybu, jaka_mapa, wybor_sposobu_tworzenia, wybor_stworzenia_projektu;
        int licznik_scian_tab = 0, licznik_przeszkod_tab = 0, licznik_met_tab = 0, m;
        int poziom_mapy, booster = 0;
        bool czas , czy_gra = true, chenc;
        char wybor, tymczas, wybor2;
        int czy_grac_dalej;
        string info_koniec, przycisk_manual[5] = {"w", "a", "s", "d", "SPACJA"};
        string opis_przycisku[4] = {"RUCH W GORE", "RUCH W LEWO", "RUCH W DOL", "RUCH W PRAWO"};
        
        //rozpoczęcie programu

        system("CLS");
        for(int i = 6; i > 0; i--) {
        system("CLS");
            for(int m = 6; m > i; m--) {
                cout << " " << '\n';
            }
            cout << "\n = = = = = = M O N K E - T H E  G A M E = = = = = = " << '\n';
        Sleep(500);
        }
    
        chenc = true, czas = true;
        cout << "CO CHCESZ ROBIC? \n (kliknij ENTER po wprowadzeniu opcjii)\n";
        cout << "1. zagraj w gre\n";
        cout << "2. Game Manual\n";
        cin >> wybor_trybu;
        system("CLS");
        if(wybor_trybu == 2) {
            cout << "Jak sie gra w MONKE'a? \n" << "Celem gracza, jest dostanie sie internetowej \"MALPY\" do METY (\"M\")\n";
            cout << "Nie dotykaj scian ( | ) , czy krzaczkow ( X ), bo ZGINIESZ\n";
            cout << "PORUSZANIE SIE: \n";
            for(int i = 0; i < 4; i++) {
                ramka(przycisk_manual[i]);
                cout << opis_przycisku[i] << '\n';    
            }

            cout << "\nCO TO BOOST?\n";
            ramka(przycisk_manual[4]);
            cout << "BOOST po naladowaniu (caly pasek w plusach ( + ) ) pozwala ci przeskoczyc przez krzaczki\nCzyli mozesz przejsc 2 pola a nie 1\n";
            cout << "Uruchom ponownie gre po przeczytaniu manuala\n";
            getch();
        }
        if(wybor_trybu == 3) {
            // for(int i = 0; i < 10; i++) {
            //      for(int j = 0; j < 10; j++) {
            //          mapa[i][j] = projekt1[i][j];
            //      }
            // }
            cout << "A widzisz, chuju, znalazles cos niestworzonego!" << '\n';
            getch();
            generowanie_pustej_mapy(projekt1);
            generowanie_pustej_mapy(projekt2);
            generowanie_pustej_mapy(projekt3);
            if(wybor_sposobu_tworzenia == 1) {
                
                cout << "Ktory projekt chcesz stworzyc?\n";
                cin >> wybor_stworzenia_projektu;
                switch (wybor_stworzenia_projektu)
                {
                case 1:
                    
                    break;
                
                case 2:
                    
                    break;
                case 3:

                    break;
                }
            }
        }
        if(wybor_trybu == 1) {
            system("CLS");
            cout << "\nJaki poziom wybierasz?\n 1. EASY\n 2. MEDIUM\n 3. HARD\n";
            cin >> poziom_mapy;
            if(poziom_mapy == 1) {
                generowanie_rand_ob(AVTOMAT_project_easy, poziom_mapy, akt_poz_y_gracz, akt_poz_x_gracz, akt_poz_y_mety, akt_poz_x_mety);
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        mapa[i][j] = AVTOMAT_project_easy[i][j];
                    }
                }
            }
            if(poziom_mapy == 2) {
                generowanie_rand_ob(AVTOMAT_project_medium, poziom_mapy, akt_poz_y_gracz, akt_poz_x_gracz, akt_poz_y_mety, akt_poz_x_mety);
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        mapa[i][j] = AVTOMAT_project_medium[i][j];
                    }
                }
            }
            if(poziom_mapy == 3) {
                generowanie_rand_ob(AVTOMAT_project_hard, poziom_mapy, akt_poz_y_gracz, akt_poz_x_gracz, akt_poz_y_mety, akt_poz_x_mety);
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        mapa[i][j] = AVTOMAT_project_hard[i][j];
                    }
                }
            }
                
        // blok sprawdzający gdzie mapa ma przeszkody itd
        //początek
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(mapa[i][j] == '.' || mapa[i][j] == '|' || mapa[i][j] == '-') {
                    licznik_scian_tab++;
                    }
                if(mapa[i][j] == 'X') {
                    licznik_przeszkod_tab++;
                }
                if(mapa[i][j] == 'M') {
                    licznik_met_tab++;
                }
            }
        }

        int **koordy_scian = new int * [licznik_scian_tab];
        for (int i = 0; i<licznik_scian_tab; i++)
	    	koordy_scian[i] = new int [2];
        int **koordy_przeszkod = new int * [licznik_przeszkod_tab];
        for (int i = 0; i<licznik_przeszkod_tab; i++)
	    	koordy_przeszkod[i] = new int [2];
        int **koordy_met = new int * [licznik_met_tab];
        for (int i = 0; i<licznik_met_tab; i++)
	    	koordy_met[i] = new int [2];

    /*  koordy_itd:
        [ 0 - i czyli koordy Y  ]
        [ 1 - j czyli koordy X  ]
    */
        int licznik_scian = 0, licznik_przeszkod = 0, licznik_met = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(mapa[i][j] == '.' || mapa[i][j] == '|' || mapa[i][j] == '-') {
                    koordy_scian[licznik_scian][0] = i;
                    koordy_scian[licznik_scian][1] = j;
                    licznik_scian++;
                }
                if(mapa[i][j] == 'X') {
                    koordy_przeszkod[licznik_przeszkod][0] = i;
                    koordy_przeszkod[licznik_przeszkod][1] = j;
                    licznik_przeszkod++;
                }
                if(mapa[i][j] == 'M') {
                    koordy_met[licznik_met][0] = i;
                    koordy_met[licznik_met][1] = j;
                    licznik_met++;
                }
                if(mapa[i][j] == '@') {
                    akt_poz_x_gracz = j;
                    akt_poz_y_gracz = i;
                }
            }
        }
    // KONIEC
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tymczas_mapa[i][j] = mapa[i][j];
        }
    }
    ost_poz_x_gracz = akt_poz_x_gracz;
    ost_poz_y_gracz = akt_poz_y_gracz;
    // zaczęcie gry!
    while(czy_gra == true) {
        // wartosci początkowe
        akt_poz_x_gracz = ost_poz_x_gracz;
        akt_poz_y_gracz = ost_poz_y_gracz;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                mapa[i][j] = tymczas_mapa[i][j];
            }
        }
        czas = true;
        chenc = true;
        booster = 0;
        info_koniec = "";
        //zaczęcie
        system("CLS");
        wypisanie(mapa);
        cout << "BOOST" << '\n' << "| - - - - - - - - - |" << '\n';

        while(czas == true) {
            
            wybor = getch();
            system("CLS");
            //poruszanie
            switch (wybor)
            {
                case 'd':
                // NA PRAWO
                    tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz][akt_poz_x_gracz + 1];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz + 1] = tymczas;
                    akt_poz_x_gracz++;
                    if (booster < 3) booster++;
                    break;
        
                case 'a':
                // NA LEWO
                    tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz][akt_poz_x_gracz - 1];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz - 1] = tymczas;
                    akt_poz_x_gracz--;
                    if (booster < 3) booster++;
                    break;
                case 'w':
                // W GÓRE
                    tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz - 1][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz - 1][akt_poz_x_gracz] = tymczas;
                    akt_poz_y_gracz--;
                    if (booster < 3) booster++;
                    break;
                case 's':
                // W DÓŁ
                    tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz + 1][akt_poz_x_gracz];
                    mapa[akt_poz_y_gracz + 1][akt_poz_x_gracz] = tymczas;
                    akt_poz_y_gracz++;
                    if (booster < 3) booster++;     
                    break;
                case ' ':
                    if(booster == 3) {
                    wypisanie(mapa);
                    cout << "BOOST MODE ACTIVATED\n";
                    wybor2 = getch();
                    switch (wybor2)
                    {
                        case 'd':
                        // NA PRAWO
                        tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz][akt_poz_x_gracz + 2];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz + 2] = tymczas;
                        akt_poz_x_gracz+= 2;  
                        break;
        
                    case 'a':
                    // NA LEWO
                        tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz][akt_poz_x_gracz - 2];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz - 2] = tymczas;
                        akt_poz_x_gracz-= 2;
                        break;
                    
                    case 'w':
                    // W GÓRE
                        tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz - 2][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz - 2][akt_poz_x_gracz] = tymczas;
                        akt_poz_y_gracz-= 2;
                        break;
                    
                    case 's':
                    // W DÓŁ
                        tymczas = mapa[akt_poz_y_gracz][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz][akt_poz_x_gracz] = mapa[akt_poz_y_gracz + 2][akt_poz_x_gracz];
                        mapa[akt_poz_y_gracz + 2][akt_poz_x_gracz] = tymczas;
                        akt_poz_y_gracz+= 2;     
                        break;

                    }
                    booster = 0;
                    system("CLS");
                    }
                break;
                }
        
        //sprawdzanie ze ścianami
            for(int i = 0; i < licznik_scian_tab; i++) {
                    if(akt_poz_x_gracz == koordy_scian[i][1] && akt_poz_y_gracz == koordy_scian[i][0]) {
                        info_koniec = "KONIEC GRY";
                        ramka(info_koniec);
                        info_koniec = "WASTED";
                        ramka(info_koniec);
                        czas = false;
                    }
                }
        //sprawdzanie ze krzaczkami
            for(int i = 0; i < licznik_przeszkod_tab; i++) {
                    if(akt_poz_x_gracz == koordy_przeszkod[i][1] && akt_poz_y_gracz == koordy_przeszkod[i][0]) {
                        info_koniec = "KONIEC GRY";
                        ramka(info_koniec);
                        info_koniec = "WASTED";
                        ramka(info_koniec);
                        czas = false;
                    }
                }
        //sprawdzanie z metą
            for(int i = 0; i < licznik_met_tab; i++) {
                    if(akt_poz_x_gracz == koordy_met[i][1] && akt_poz_y_gracz == koordy_met[i][0]) {
                        info_koniec = "KONIEC GRY";
                        ramka(info_koniec);
                        info_koniec = "YOU WON !";
                        ramka(info_koniec);
                        czas = false;
                    }
                }
        if(czas == false) {
            while(chenc == true) {
                Sleep(1000);
                cout << "\nCzy chcesz zagrac jeszcze raz?\n 1. TAK \n 2. NIE\n(wpisz liczbe i potwierdz ENTER'em)\n";
                cin >> czy_grac_dalej;
                    if(czy_grac_dalej == 2) {
                        clr;
                        czy_gra = false;
                        chenc = false;
                    } else if(czy_grac_dalej == 1) {
                        czy_gra = true;
                        chenc = false;
                        clr;
                    }
                }
            }
        if(czas == true) {
            wypisanie(mapa);
            cout << "BOOST" << '\n' << '|';
            for(int i = booster; i > 0; i--) {
                cout << " + + +";
            }
            for(int u = 3 - booster; u > 0; u--) {
                cout << " - - -";
            }        
            cout << " |" << '\n';
        }
        }
    }

    for (int i = 0; i<2; i++) {
		    delete [] koordy_scian[i];
        delete [] koordy_scian;
        for (int i = 0; i<2; i++)
	        	delete [] koordy_przeszkod[i];
        delete [] koordy_przeszkod;
        for (int i = 0; i<2; i++)
	    	delete [] koordy_met[i];
        delete [] koordy_met;
    }        

_getch();
    
//zabijanie pamięci
///KOOOOOOOONIEEEC
        
    
    }
}
//TYMCZASOWE
    /*
    for(int i = 0;i < licznik_scian_tab; i++) {
        for (int j = 0; j<2; j++)
            cout << koordy_scian[i][j] << ' ';
    cout << '\n';
    }
    cout << "- - - ";
    cout << '\n';
    for(int i = 0;i < licznik_przeszkod_tab; i++) {
        for (int j = 0; j<2; j++)
            cout << koordy_przeszkod[i][j] << ' ';
    cout << '\n';
    }
    cout << " - - - ";
    cout << '\n';
    for(int i = 0;i < licznik_met_tab; i++) {
        for (int j = 0; j<2; j++)
            cout << koordy_met[i][j] << ' ';
    cout << '\n';
    }
    */
