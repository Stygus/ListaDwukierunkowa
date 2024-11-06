#pragma once
using namespace std;

struct Wezel
{
	int wartosc;
	Wezel* nastepny_wezel;
	Wezel* poprzedni_wezel;  // domyslnie pola i metody sa publiczne w structcie 
	Wezel() : wartosc(NULL), poprzedni_wezel(nullptr), nastepny_wezel(nullptr) {}; 
	~Wezel() {};
};


class ListaDwukierunkowa
{
private:
	Wezel* poczatek;
	Wezel* koniec;   // domyslnie w clasie sa private
	int ilosc_elementow;
public:
	ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc_elementow(0) {  }
	~ListaDwukierunkowa() {};

	void Dodawanie_napoczatek(int wartosc);
	void Dodawanie_nakoniec(int wartosc);
	void Wyswietlanie_od_poczatku();
	void Wyswietlanie_od_konca();
	void Dodawanie_na_index(int wartosc, int index);
	void usuwanie_z_poczatku();
	void usuwanie_z_konca();
	///*void usuwanie_z_indexu();*/
	//void poruszanie_po_liscie();

};






