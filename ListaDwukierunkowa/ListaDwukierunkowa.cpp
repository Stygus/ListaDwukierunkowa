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

void ListaDwukierunkowa::Wyswietlanie_od_poczatku() {
	Wezel* wskaznik = new Wezel;
	wskaznik = poczatek;
	for (int i = 0; i < ilosc_elementow ; i++)
	{
		cout << wskaznik->wartosc << endl;
		if (wskaznik->nastepny_wezel != nullptr) {
			wskaznik = wskaznik->nastepny_wezel;

		}
		else
		{
			return;
		}
	}
}


void ListaDwukierunkowa::Wyswietlanie_od_konca() {
	Wezel* wskaznik = new Wezel;
	wskaznik = koniec;
	for (int i = 0; i < ilosc_elementow; i++)
	{
		cout << wskaznik->wartosc << endl;
		wskaznik = wskaznik->poprzedni_wezel;
	}
}



void ListaDwukierunkowa::Dodawanie_na_index(int wartosc, int index) {
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
		
	}
	else if (index == 0) Dodawanie_napoczatek(wartosc);
	else if (index == ilosc_elementow) Dodawanie_nakoniec(wartosc);
	else cout << "Index poza listą";
}



void ListaDwukierunkowa::usuwanie_z_poczatku() {
	if (!poczatek) {
		cout << "brak elementow\n";
	}
	else
	{
		if (ilosc_elementow > 1) {
		Wezel* obecny = poczatek->nastepny_wezel;
		delete obecny->poprzedni_wezel;
			poczatek = obecny;
		}
		else if (ilosc_elementow == 1)
		{
			delete poczatek;
			koniec = nullptr;
			poczatek = nullptr;
		}
	}
	ilosc_elementow--;
}



void ListaDwukierunkowa::usuwanie_z_konca() {
	if (!koniec) {
		cout << "brak elementow\n";
	}
	else
	{
		if (ilosc_elementow > 1)
		{
			Wezel* obecny = koniec->poprzedni_wezel;
			delete obecny->nastepny_wezel;
			koniec = obecny;
		}
		else if (ilosc_elementow == 1)
		{
			delete koniec;
			koniec = nullptr;
			poczatek = nullptr;
		}
	}
	ilosc_elementow--;
}

void ListaDwukierunkowa::usuwanie_z_indexu(int index) {
	if (index > 0 && index < ilosc_elementow - 1) {
		Wezel* wskaznik = poczatek;
		for (int i = 0; i < index; i++) {
			wskaznik = wskaznik->nastepny_wezel;
		}
		Wezel* dodatkowy = wskaznik->poprzedni_wezel;
		dodatkowy->nastepny_wezel = wskaznik->nastepny_wezel;
		wskaznik->nastepny_wezel->poprzedni_wezel = dodatkowy;
		delete wskaznik;
	}
	else if (index == 0) usuwanie_z_poczatku();
	else if (index == ilosc_elementow) usuwanie_z_konca();
	else cout << "Index poza listą";
}




//void ListaDwukierunkowa::poruszanie_po_liscie() {
//	int index = 0;
//	int komenda = 0;
//	string error = "";
//	Wezel* wybrany = new Wezel;
//	if (poczatek != nullptr) wybrany = poczatek;
//	do {
//
//		/*wyswietlanie:*/
//		cout << "1 - poprzedni element\n2 - nastepny element\n3 - dodaj na poczatek\n4 - dodaj na koniec\n5 - dodaj na konkretne miejsce\n6 - usun z poczatku\n7 - usun z konca\n8 - usun z konkretnego indexu\n9 - wyswietl liste od poczatku\n10 - wyswietl liste od konca\n0 - wyjdz\n\n\n\n"; \
//			if (komenda != 9 && komenda != 10)
//			{
//				cout << "\n\nwartosc: ";
//				if (wybrany->poprzedni_wezel != nullptr) { cout << wybrany->poprzedni_wezel->wartosc; }
//				if (wybrany != nullptr) { cout << " -> "; if (ilosc_elementow == 0) cout << "null"; else cout << wybrany->wartosc; cout << " <- "; }
//				if (wybrany->nastepny_wezel != nullptr) { cout << wybrany->nastepny_wezel->wartosc; }
//				cout << "\nindex: " << index << "\n\n\n" << error << "\n\n";
//			}
//			else if (komenda == 9) {
//				Wyswietlanie_od_poczatku();
//			}
//			else if (komenda == 10) {
//				Wyswietlanie_od_konca();
//			}


		/*	*/

	/*	error = "";
		cin >> komenda;
		int a = 0, ind = 0;
		switch (komenda)
		{
		case 1:
			if (wybrany->poprzedni != nullptr) {
				wybrany = wybrany->poprzedni;
				index--;
			}
			break;
		case 2:
			if (wybrany->nastepny != nullptr) {
				wybrany = wybrany->nastepny;
				index++;
			}
			break;
		case 3:
			cout << "Podaj wartosc: ";
			cin >> a;
			if (ilosc == 0) wybrany = dodaj_na_poczatek(a);
			else { dodaj_na_poczatek(a); index++; }
			break;
		case 4:
			cout << "Podaj wartosc: ";
			cin >> a;
			if (ilosc == 0) wybrany = dodaj_na_koniec(a);
			else { dodaj_na_koniec(a); }
			break;
		case 5:
			cout << "Podaj wartosc: ";
			cin >> a;
			cout << "Podaj index: ";
			cin >> ind;
			if (ind >= 0 && ind <= ilosc) {
				wybrany = dodaj_na_index(a, ind);
				index = ind;
			}
			else error = "Index poza lista";

			break;
		case 6:
			if (wybrany == poczatek) { wybrany = poczatek->nastepny; index++; };
			usun_z_poczatku();
			index--;
			break;
		case 7:
			if (wybrany == koniec) { wybrany = koniec->poprzedni; index--; }
			usun_z_konca();
			break;
		case 8:
			if (wybrany == poczatek) {
				if (wybrany == poczatek) { wybrany = poczatek->nastepny; index++; };
				usun_z_poczatku();
				index--;
			}
			else if (wybrany == koniec) {
				if (wybrany == koniec) { wybrany = koniec->poprzedni; index--; }
				usun_z_konca();
			}
			else { wybrany = wybrany->poprzedni; usun_z_indexu(index); index--; }
			break;
		}
		system("cls");
	} while (komenda != 0);
}*/
