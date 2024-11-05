#include <iostream>
#include "ListaDwukierunkowa.h"

void ListaDwukierunkowa::Dodawanie_napoczatek(int dane) {

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
