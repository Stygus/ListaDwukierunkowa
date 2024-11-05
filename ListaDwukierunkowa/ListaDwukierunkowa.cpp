#include <iostream>
#include "ListaDwukierunkowa.h"

void ListaDwukierunkowa::Dodawanie_napoczatek(int wartosc) {

	if (ilosc_elementow > 0)
	{
		Wezel* nowyWezel = new Wezel;
		poczatek->poprzedni_wezel = nowyWezel;
		poczatek->poprzedni_wezel->nastepny_wezel = poczatek;  // relacje miedzy wezlami
		poczatek = nowyWezel;    // ustawienie poczatku 
		nowyWezel->wartosc = wartosc;   //ustawienie danych


	}
	else
	{
		Wezel* nowyWezel = new Wezel;
		poczatek = nowyWezel;   // jedyny wenzel
		koniec = nowyWezel;
		nowyWezel->wartosc = wartosc;
	}

	ilosc_elementow++;
}
/// <summary>
/// /////
/// </summary>
/// <param name="wartosc"></param>
void ListaDwukierunkowa::Dodawanie_nakoniec(int wartosc) {

	if (ilosc_elementow > 0)
	{
		Wezel* nowyWezel = new Wezel;
		koniec->nastepny_wezel = nowyWezel;
		koniec->nastepny_wezel->poprzedni_wezel = koniec;  // relacje miedzy wezlami
		koniec = nowyWezel;    // ustawienie poczatku 
		nowyWezel->wartosc = wartosc;   //ustawienie danych


	}
	else
	{
		Wezel* nowyWezel = new Wezel;
		poczatek = nowyWezel;   // jedyny wenzel
		koniec = nowyWezel;
		nowyWezel->wartosc = wartosc;
	}

	ilosc_elementow++;
}
/// <summary>
/// ////////
/// </summary>
void ListaDwukierunkowa::Wyswietlanie_od_poczatku() {
	Wezel* wskaznik = new Wezel;
	wskaznik = poczatek;
	for (int i = 0; i < ilosc_elementow; i++)
	{
		cout << wskaznik->wartosc << endl;
		wskaznik = wskaznik->nastepny_wezel;
	}
}
/// <summary>
/// ///////////
/// </summary>

void ListaDwukierunkowa::Wyswietlanie_od_konca() {
	Wezel* wskaznik = new Wezel;
	wskaznik = koniec;
	for (int i = 0; i < ilosc_elementow; i++)
	{
		cout << wskaznik->wartosc << endl;
		wskaznik = wskaznik->poprzedni_wezel;
	}
}

/// <summary>
/// ///
/// </summary>
/// <param name="wartosc"></param>
/// <param name="index"></param>
/// <returns></returns>

Wezel* ListaDwukierunkowa::Dodawanie_na_index(int wartosc, int index) {
	if (index > 0 && index < ilosc_elementow) {
		Wezel* nowyWezel = new Wezel;
		Wezel* wskaznik = poczatek;
		for (int i = 0; i < index - 1; i++)
		{
			wskaznik = wskaznik->nastepny_wezel;
		}
		nowyWezel->nastepny_wezel = wskaznik->nastepny_wezel;
		wskaznik->nastepny_wezel->poprzedni_wezel = nowyWezel;
		wskaznik->nastepny_wezel = nowyWezel;
		nowyWezel->poprzedni_wezel = wskaznik;
		nowyWezel->wartosc = wartosc;
		ilosc_elementow++;
		return nowyWezel;
	}
	else if (index == 0) Dodawanie_napoczatek(wartosc);
	else if (index == ilosc_elementow) Dodawanie_nakoniec(wartosc);
	else cout << "Index poza listą";
}

/// <summary>
/// /////////
/// </summary>

void ListaDwukierunkowa::usuwanie_z_poczatku() {
	if (!poczatek) {
		cout << "brak elementow\n";
	}
	else
	{
		Wezel* obecny = poczatek;
		poczatek = poczatek->nastepny_wezel;
		poczatek->poprzedni_wezel = nullptr;
		delete obecny;
	}
	ilosc_elementow;
}


void ListaDwukierunkowa::usuwanie_z_konca() {
	if (!koniec) {
		cout << "brak elementow\n";
	}
	else
	{
		Wezel* obecny = koniec;
		koniec = koniec->poprzedni_wezel;
		koniec->nastepny_wezel = nullptr;
		delete obecny;
	}
	ilosc_elementow;
}



