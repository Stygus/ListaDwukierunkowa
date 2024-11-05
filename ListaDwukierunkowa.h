#pragma once
using namespace std;

struct Wezel
{
	int wartosc;
	Wezel* poprzedni_wezel;
	Wezel* nastepny_wezel;  // domyslnie pola i metody sa publiczne w structcie 
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

	void Dodawanie_napoczatek(int dane) {

		if (ilosc_elementow > 0)
		{
			Wezel* morski = new Wezel;
			poczatek->poprzedni_wezel = morski;
			poczatek->poprzedni_wezel->nastepny_wezel = poczatek;  // relacje miedzy wezlami
			poczatek = morski;    // ustawienie poczatku 
			morski->wartosc = dane;   //ustawienie danych


		}
		else
		{
			Wezel* morski = new Wezel;
			poczatek = morski;   // jedyny wenzel
			koniec = morski;
			morski->wartosc = dane;
		}

		ilosc_elementow++;
	}
	void Dodawanie_nakoniec(int dane) {

		if (ilosc_elementow > 0)
		{
			Wezel* morski = new Wezel;
			koniec->nastepny_wezel = morski;
			koniec->nastepny_wezel->poprzedni_wezel = koniec;  // relacje miedzy wezlami
			koniec = morski;    // ustawienie poczatku 
			morski->wartosc = dane;   //ustawienie danych


		}
		else
		{
			Wezel* morski = new Wezel;
			poczatek = morski;   // jedyny wenzel
			koniec = morski;
			morski->wartosc = dane;
		}

		ilosc_elementow++;
	}
	void Wyswietlanie_od_poczatku() {
		Wezel* wskaznik = new Wezel;
		wskaznik = poczatek;
		for (int i = 0; i < ilosc_elementow; i++)
		{
			cout << wskaznik->wartosc << endl;
			wskaznik = wskaznik->nastepny_wezel;
		}
	}

	void Wyswietlanie_od_konca() {
		Wezel* wskaznik = new Wezel;
		wskaznik = koniec;
		for (int i = 0; i < ilosc_elementow; i++)
		{
			cout << wskaznik->wartosc << endl;
			wskaznik = wskaznik->poprzedni_wezel;
		}
	}




};

