#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "klasa.h"
#include "klasa2.h"

using namespace std;
// szachy: K-Król G-Goniec W-Wie¿a H-Hetman S-Skoczek P-Pionek
HANDLE uchwyt;





gra::gra() {
	
	tab[0][0] = 'W'; tab[0][7] = 'W';
	tab[0][1] = 'S'; tab[0][6] = 'S';
	tab[0][2] = 'G'; tab[0][5] = 'G';
	tab[0][3] = 'H';
	tab[0][4] = 'K';
	for (int i = 0; i < 8; i++)
		tab[1][i] = 'P';

	for(int i=2; i<7 ; i++)
	for (int j = 0; j < 8 ; j++)		
 	tab[i][j] = ' ';

	tab[7][0] = 'W'; tab[7][7] = 'W';
	tab[7][1] = 'S'; tab[7][6] = 'S';
	tab[7][2] = 'G'; tab[7][5] = 'G';
	tab[7][3] = 'H';
	tab[7][4] = 'K';
	for (int i = 0; i < 8; i++)
		tab[6][i] = 'P';



	for (int i = 0; i < 8; i++) {
		kto[0][i] = 1;
		kto[1][i] = 1;
	}
    for (int i = 2; i < 6; i++)
	for(int j=0; j<8 ; j++)
				kto[i][j]= 0;
			
	for (int i =0 ; i < 8; i++) {
		kto[7][i] = 2;
		kto[6][i] = 2;
	}
	

	gracz = 1;



	/*
//do testów
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			tab[i][j] = ' ';
			kto[i][j] = 0;
		}
	

	tab[1][1] = 'P';
	tab[1][2] = 'P';
		tab[1][3] = 'P';
		tab[2][1] = 'P';
		tab[2][3] = 'P';
		tab[3][1] = 'P';
		tab[3][2] = 'P';
		tab[3][3] = 'P';
		
		kto[1][1] = 2;
		kto[1][2] = 2;
		kto[1][3] = 2;
		kto[2][1] = 2;
		kto[2][3] = 2;
		kto[3][1] = 2;
		kto[3][2] = 2;
		kto[3][3] = 2;
		

	tab[2][2] = 'G';
	kto[2][2] = 1;

	tab[6][6] = 'G';
	kto[6][6] = 1;*/
}

char gra::szach(int x, int y) {
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(uchwyt, 2);         //13 ró¿owy   2 zielony  7bia³y
	
	
		switch (kto[x][y]) {

		case 0: {
			return tab[x][y];
			break; }
			

		case 1: {
			SetConsoleTextAttribute(uchwyt, 2);
			return tab[x][y];
			
		}
		case 2: {
			SetConsoleTextAttribute(uchwyt, 13);                    //2 to ró¿owy   1 zielony
			return tab[x][y];
		
		}
		}
	
}

void gra::ruch(string x) {
	
	if (x != "nowa" && x != "koniec") {

		tab[gdziex][gdziey] = tab[wybranyx][wybranyy];
		tab[wybranyx][wybranyy] = ' ';
		kto[gdziex][gdziey] = kto[wybranyx][wybranyy];
		kto[wybranyx][wybranyy] = 0;
	}

}

void gra::identyfikacja(string x) {
	int X = x[1] - '0';
	int Y = x[4] - '0';
	switch (x[0]) {
	case 'A': {
		wybranyx = X - 1;
		wybranyy = 0;
		break;
	}
	case 'B': {
		wybranyx = X - 1;
		wybranyy = 1;
		break;
	}
	case 'C': {
		wybranyx = X - 1;
		wybranyy = 2;
		break;
	}
	case 'D': {
		wybranyx = X - 1;
		wybranyy = 3;
		break;
	}
	case 'E': {
		wybranyx = X - 1;
		wybranyy = 4;
		break;
	}
	case 'F': {
		wybranyx = X - 1;
		wybranyy = 5;
		break;
	}
	case 'G': {
		wybranyx = X - 1;
		wybranyy = 6;
		break;
	}
	case 'H': {
		wybranyx = X - 1;
		wybranyy = 7;
		break;
	}
	}

	switch (x[3]) {
	case 'A': {
		gdziex = Y - 1;
		gdziey = 0;
		break;
	}
	case 'B': {
		gdziex = Y - 1;
		gdziey = 1;
		break;
	}
	case 'C': {
		gdziex = Y - 1;
		gdziey = 2;
		break;
	}
	case 'D': {
		gdziex = Y - 1;
		gdziey = 3;
		break;
	}
	case 'E': {
		gdziex = Y - 1;
		gdziey = 4;
		break;
	}
	case 'F': {
		gdziex = Y - 1;
		gdziey = 5;
		break;
	}
	case 'G': {
		gdziex = Y - 1;
		gdziey = 6;
		break;
	}
	case 'H': {
		gdziex = Y - 1;
		gdziey = 7;
		break;
	}
	}

}

bool gra::poprawnosc(int x, string s) {

	if (s == "nowa")return 0;
	if (s == "koniec")return 0;
	
	

	if (spr_string(s))return 1;


	identyfikacja(s);

	if (kto[wybranyx][wybranyy] != x) {
		cout << "nie wybrales swojego szacha ";
		return 1;
	}
	if (kto[gdziex][gdziey] == x) {
		cout << "czemu bijesz swoich? ";
		return 1;
	}


	//teraz ruchy
	switch (tab[wybranyx][wybranyy]) {


	case 'P': {


		switch (x) {

		case 1: {
			if (wybranyx > gdziex) {
				cout << "niepoprawny ruch pionka ";
				return 1;
			}
			if (kto[gdziex][gdziey] == 0 && wybranyy == gdziey && gdziex == wybranyx + 1) {
				podmiana();  return 0;
			}
			if ((kto[gdziex][gdziey] == 2) && (wybranyy == gdziey - 1 || wybranyy == gdziey + 1)) {
				podmiana();  return 0;
			}
			cout << "niepoprawny ruch pionka ";
			return 1;

		}
		case 2: {
			if (wybranyx < gdziex) {
				cout << "niepoprawny ruch pionka ";
				return 1;
			}
			if (kto[gdziex][gdziey] == 0 && wybranyy == gdziey && gdziex == wybranyx - 1) {
				podmiana();  return 0;
			}
			if ((kto[gdziex][gdziey] == 1) && (wybranyy == gdziey - 1 || wybranyy == gdziey + 1)) {
				podmiana();  return 0;
			}
			cout << "niepoprawny ruch pionka ";
			return 1;
		}
		}


		cout << "niepoprawny ruch pionka ";
		return 1;
	}

	case 'W': {
		//w górê
		if (wybranyx > gdziex && wybranyy == gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if (wybranyx - i == gdziex) return 0;
				if (kto[wybranyx - i][wybranyy] != 0) {
					cout << "nieprawidlowy ruch wie¿y ";
					return 1;
				}

			}
			
		}

		//w dó³
		if (wybranyx < gdziex && wybranyy == gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if (wybranyx + i == gdziex) return 0;
				if (kto[wybranyx + i][wybranyy] != 0) {
					cout << "nieprawidlowy ruch wie¿y ";
					return 1;
				}

			}

		}

		//w prawo
		if (wybranyy < gdziey && wybranyx == gdziex) {
			int i = 0;
			while (wybranyy <= gdziey) {

				i++;
				if (wybranyy + i == gdziey) return 0;
				if (kto[wybranyx ][wybranyy+1] != 0) {
					cout << "nieprawidlowy ruch wie¿y ";
					return 1;
				}

			}

		}

		//w lewo
		if (wybranyy > gdziey && wybranyx == gdziex) {
			int i = 0;
			while (wybranyy >= gdziey) {

				i++;
				if (wybranyy - i == gdziey) return 0;
				if (kto[wybranyx][wybranyy - 1] != 0) {
					cout << "nieprawidlowy ruch wie¿y ";
					return 1;
				}

			}

		}

		cout << "nieprawidlowy ruch wie¿y ";
		return 1;
	
	}

	case 'G': {
		
		if (wybranyx > gdziex && wybranyy > gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if ((wybranyx - i == gdziex)&& (wybranyy - i == gdziey)) return 0;
				if (kto[wybranyx - i][wybranyy-i] != 0) {
					cout << "nieprawidlowy ruch goñca ";
					return 1;
				}

			}

		}


	
		if (wybranyx < gdziex && wybranyy < gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if ((wybranyx + i == gdziex) && (wybranyy + i == gdziey)) return 0;
				if (kto[wybranyx + i][wybranyy + i] != 0) {
					cout << "nieprawidlowy ruch goñca ";
					return 1;
				}

			}

		}
		

		//prawy górny róg
		if (wybranyx > gdziex && wybranyy < gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if ((wybranyx - i == gdziex) && (wybranyy + i == gdziey)) return 0;
				if (kto[wybranyx - i][wybranyy + i] != 0) {
					cout << "nieprawidlowy ruch goñca ";
					return 1;
				}

			}

		}


		
		if (wybranyx < gdziex && wybranyy > gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if ((wybranyx + i == gdziex) && (wybranyy - i == gdziey)) return 0;
				if (kto[wybranyx + i][wybranyy - i] != 0) {
					cout << "nieprawidlowy ruch goñca ";
					return 1;
				}

			}

		}

cout << "nieprawidlowy ruch goñca";
		return 1;
	}

	case 'H': {
		if (wybranyx > gdziex && wybranyy == gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if (wybranyx - i == gdziex) return 0;
				if (kto[wybranyx - i][wybranyy] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}

		//w dó³
		if (wybranyx < gdziex && wybranyy == gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if (wybranyx + i == gdziex) return 0;
				if (kto[wybranyx + i][wybranyy] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}

		//w prawo
		if (wybranyy < gdziey && wybranyx == gdziex) {
			int i = 0;
			while (wybranyy <= gdziey) {

				i++;
				if (wybranyy + i == gdziey) return 0;
				if (kto[wybranyx][wybranyy + 1] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}

		//w lewo
		if (wybranyy > gdziey && wybranyx == gdziex) {
			int i = 0;
			while (wybranyy >= gdziey) {

				i++;
				if (wybranyy - i == gdziey) return 0;
				if (kto[wybranyx][wybranyy - 1] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}
		

		if (wybranyx > gdziex && wybranyy > gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if ((wybranyx - i == gdziex) && (wybranyy - i == gdziey)) return 0;
				if (kto[wybranyx - i][wybranyy - i] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}



		if (wybranyx < gdziex && wybranyy < gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if ((wybranyx + i == gdziex) && (wybranyy + i == gdziey)) return 0;
				if (kto[wybranyx + i][wybranyy + i] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}


		//prawy górny róg
		if (wybranyx > gdziex && wybranyy < gdziey) {
			int i = 0;
			while (wybranyx >= gdziex) {

				i++;
				if ((wybranyx - i == gdziex) && (wybranyy + i == gdziey)) return 0;
				if (kto[wybranyx - i][wybranyy + i] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}



		if (wybranyx < gdziex && wybranyy > gdziey) {
			int i = 0;
			while (wybranyx <= gdziex) {

				i++;
				if ((wybranyx + i == gdziex) && (wybranyy - i == gdziey)) return 0;
				if (kto[wybranyx + i][wybranyy - i] != 0) {
					cout << "nieprawidlowy ruch hetmana ";
					return 1;
				}

			}

		}


	cout << "nieprawidlowy ruch hetmana ";
	return 1;

	}

	case'S': {
		//skok w gore
		if ((wybranyx == gdziex + 2) && ((wybranyy == gdziey + 1) || (wybranyy==gdziey - 1))) return 0;

//skok w dó³
		if ((wybranyx == gdziex - 2) && ((wybranyy == gdziey + 1) || (wybranyy == gdziey - 1))) return 0;

			//skok w prawo
		if ((wybranyy == gdziey - 2) && ((wybranyx == gdziex + 1) || (wybranyx == gdziex - 1))) return 0;

//skok w lewo
		if ((wybranyy == gdziey + 2) && ((wybranyx == gdziex + 1) || (wybranyx == gdziex - 1))) return 0;



		cout << "nieprawidlowy ruch skoczka ";
		return 1;
	}

	case 'K': {
		if ((wybranyx == gdziex + 1) && ((wybranyy == gdziey) || (wybranyy == gdziey))) return 0;
		if ((wybranyx == gdziex - 1) && ((wybranyy == gdziey) || (wybranyy == gdziey))) return 0;
		if ((wybranyy == gdziey + 1) && ((wybranyx == gdziex) || (wybranyx == gdziex))) return 0;
		if ((wybranyy == gdziey - 1) && ((wybranyx == gdziex) || (wybranyx == gdziex))) return 0;
		if ((wybranyx == gdziex + 1) && ((wybranyy == gdziey + 1) || (wybranyy == gdziey - 1))) return 0;
		if ((wybranyx == gdziex - 1) && ((wybranyy == gdziey + 1) || (wybranyy == gdziey - 1))) return 0;
		if ((wybranyy == gdziey + 1) && ((wybranyx == gdziex + 1) || (wybranyx == gdziex - 1))) return 0;
		if ((wybranyy == gdziey - 1) && ((wybranyx == gdziex + 1) || (wybranyx == gdziex - 1))) return 0;
						
		cout << "nieprawidlowy ruch króla ";
		return 1;
	}


}

}

int gra::kolej() {
	return gracz;
}

int gra::koniec(string s) {

	if (s == "nowa")return 0;

	if (s[0] != 'A'&& s[0] != 'B'&& s[0] != 'C'&& s[0] != 'D'&& s[0] != 'E'&& s[0] != 'F'&& s[0] != 'G'&& s[0] != 'H') {
		
		return 0;
	}

	if (s[1] != '1'&& s[1] != '2'&& s[1] != '3'&& s[1] != '4'&& s[1] != '5'&& s[1] != '6'&& s[1] != '7'&& s[1] != '8') {
		
		return 0;
	}

	if (s[3] != 'A'&& s[3] != 'B'&& s[3] != 'C'&& s[3] != 'D'&& s[3] != 'E'&& s[3] != 'F'&& s[3] != 'G'&& s[3] != 'H') {
		
		return 0;
	}
	if (s[4] != '1' && s[4] != '2' && s[4] != '3' && s[4] != '4' && s[4] != '5' && s[4] != '6' && s[4] != '7' && s[4] != '8') {
		
		return 0;
	}
	identyfikacja(s);
	if(tab[gdziex][gdziey]=='K')
	return 1;
	else return 0;
}

bool gra::spr_string(string s) {
	if (s == "nowa")return 0;

	if (s[0] != 'A'&& s[0] != 'B'&& s[0] != 'C'&& s[0] != 'D'&& s[0] != 'E'&& s[0] != 'F'&& s[0] != 'G'&& s[0] != 'H') {
		cout << "Ÿle podany ruch ";
		return 1;
	}

	if (s[1] != '1'&& s[1] != '2'&& s[1] != '3'&& s[1] != '4'&& s[1] != '5'&& s[1] != '6'&& s[1] != '7'&& s[1] != '8') {
		cout << "Ÿle podany ruch ";
		return 1;
	}

	if (s[3] != 'A'&& s[3] != 'B'&& s[3] != 'C'&& s[3] != 'D'&& s[3] != 'E'&& s[3] != 'F'&& s[3] != 'G'&& s[3] != 'H') {
		cout << "Ÿle podany ruch ";
		return 1;
	}
	if (s[4] != '1' && s[4] != '2' && s[4] != '3' && s[4] != '4' && s[4] != '5' && s[4] != '6' && s[4] != '7' && s[4] != '8') {
		cout << "Ÿle podany ruch ";
		return 1;
	}
	return 0;
}

void gra::podmiana() {
	char a;
	
		
		if (gdziex == 7 && kto[wybranyx][wybranyy]==1) {
			while (1) {
				cout << "wybierz szach W S G lub H: ";
				cin >> a;
				if (a == 'W' || a == 'S' || a == 'G' || a == 'H') {
					tab[wybranyx][wybranyy] = a;
					break;
					

				}
				cout << "Ÿle podany szach, podaj jeszcze raz: "; 
			}
		}


	else if (gdziex == 0 && kto[wybranyx][wybranyy] == 2) {
		while (1) {
			cout << "wybierz szach W S G lub H: ";
			cin >> a;
			if (a == 'W' || a == 'S' || a == 'G' || a == 'H') {
				tab[wybranyx][wybranyy] = a;
				break;

			}
			cout << "Ÿle podany szach, podaj jeszcze raz: "; continue;
		}
	}



}

gra::~gra() {
	
	/*for (int i = 0; i < 8; i++) {
		delete [] tab[i];
		delete [] kto[i];
	}
	delete[] tab;
	delete[] kto;*/
}

ostream & operator << (ostream&str, gra&z) {
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	str << "\n      A     B     C     D     E     F     G     H        ruch w formacie 'A2=B3'" ;
	for (int n = 0; n < 8; n++) {

		str << "  |\n   |-----|-----|-----|-----|-----|-----|-----|-----|         " << endl;
		str << n + 1;

		for (int m = 0; m < 8; m++) {

			str << "  |  "; 
			str << z.szach(n, m);
			SetConsoleTextAttribute(uchwyt, 7);

		}
	}

	str << "  |\n   |-----|-----|-----|-----|-----|-----|-----|-----|\n\n\n\n\n";
	return str;

}