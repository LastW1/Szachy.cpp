#include <iostream>
#include <string>
#include "klasa.h"
#include "klasa2.h"
#include <fstream>

using namespace std;





void zapis::zapisz(gra&obiekt, int p) {
	ofstream plik("save.txt");
	if (plik.good() == true) {



		for (int i = 0; i < 8; i++)
			for (int j = 0; j<8; j++) {
				if (obiekt.tab[i][j] == ' ')
					plik << 'I';
				else plik << obiekt.tab[i][j];


			}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j<8; j++) {

				plik << obiekt.kto[i][j];


			}
		plik << p;
		obiekt.gracz = p;
		plik.close();
	}
	else cout << "plik nie mo¿e siê otworzyc" << endl;


	}


void zapis::wczytaj(gra&obiekt) {
	char x;
	ifstream plik("save.txt");
	if (plik.good() == true) {





		for (int i = 0; i < 8; i++)
			for (int j = 0; j<8; j++) {

				plik >> x;
				if (x == 'I')
					x = ' ';
				obiekt.tab[i][j] = x;

			}

		for (int i = 0; i < 8; i++)
			for (int j = 0; j<8; j++) {

				plik >> x;
				obiekt.kto[i][j] = x - '0';

			}

		plik >> x;

		obiekt.gracz = x - '0';



		plik.close();
	}
	else cout << "plik nie mo¿e siê otworzyc" << endl;
}

	
