#include <windows.h>
#include <iostream>
#include <cstdlib>
#include"klasa.h"
#include "klasa2.h"
#include <locale> 
#include <conio.h>

using namespace std;


int main() {
	{
		setlocale(LC_ALL, "pl-PL");
		string a;
		int zasilacz = 1;
		int spr;
		int koniec=0;
		gra nowa;
		zapis::wczytaj(nowa);
		int win = 0;
		char znak;
		cout << "                                 witaj w grze" << endl;
		cout << "              aby wykonaæ ruch musisz podaæ go w formacie np: 'A2=A3'" << endl;
		cout << "                   aby zakoñczyæ grê wystarczy wpisaæ 'koniec'" << endl;
		cout << "                  do rozpoczêcia nowej gry s³u¿y komenda 'nowa'\n\n\n\n\n\n\n" << endl;
		cout << "                   aby rozpocz¹æ grê wciœnij dowolny przycisk: \n";
		znak = _getch();
	
	
		while (zasilacz) {

			if (nowa.kolej() == 1) {
				spr = 1;
				
				while (spr) {
					cout << nowa;
					cout << "ruch gracza zielonego : ";
					cin >> a;
					if (a == "koniec") {
						koniec = 1;
						break;
					}
					if (a == "nowa") {
						gra nowa2;
						nowa = nowa2;
					}                
					
					
					
					spr = nowa.poprawnosc(1, a);
					if (spr == 1) continue;
				
if (nowa.koniec(a)) win = 1;
				}
				nowa.ruch(a);
				if (koniec) break;
				if (win) {
					cout << "WYGRAL GRACZ ZIELONY" << endl;
					cout << "zacz¹æ now¹ grê?  tak=0 nie=1" << endl;
					cin >> win;
					if (win) break;
					gra nowa2; nowa = nowa2;
				}
				
				zapis::zapisz(nowa, 2);
			}

			spr = 1;
			
			while (spr) {
				cout << nowa;
				cout << "ruch gracza ró¿owego: ";
				cin >> a;
				if (a == "koniec") {
					koniec = 1;
					break;
				}
				if (a == "nowa") {
					gra nowa2;
					nowa = nowa2;

				}
			
				
				spr = nowa.poprawnosc(2, a);
			   if (spr == 1) continue;
			
				if (nowa.koniec(a)) win = 1;

			}
			nowa.ruch(a);
			if (koniec) break;
			if (win) { cout << "WYGRAL GRACZ RÓ¯OWY" << endl;
			cout << "zacz¹æ now¹ grê?  tak=0 nie=1" << endl; 
			cin>>win;
			if (win) break;
			 gra nowa2; nowa = nowa2;
			}
			zapis::zapisz(nowa, 1);

		

		}



		cout << "pa pa :(" << endl;
	}
	system("PAUSE");
	return 0;
}


