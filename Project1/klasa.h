#include <iostream>
#include <string>

using namespace std;


class gra {
	
private:
	char tab[8][8];
	int kto[8][8];
	int gdziex;
	int gdziey;
	int wybranyx;
	int wybranyy;
	int gracz;
	
public:
	friend class zapis;
	gra();
	~gra();
	char szach(int x,int y);
	void ruch(string x);
	void identyfikacja(string x);
	bool poprawnosc(int x,string s);
	void podmiana();
	int kolej();
	int koniec(string s);
	bool spr_string(string s);
	
	friend ostream & operator << (ostream&str, gra&z);
	
};

