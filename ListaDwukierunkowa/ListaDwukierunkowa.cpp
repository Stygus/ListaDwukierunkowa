#include <iostream>
#include "ListaDwukierunkowa.h"

/**
 * @brief Dodaje nowy element na poczatek listy.
 *
 * @param wartosc Wartosc do dodania na poczatek listy.
 */
void ListaDwukierunkowa::Dodawanie_napoczatek(int wartosc) {
    if (ilosc_elementow > 0) {
        Wezel* nowyWezel = new Wezel;
        poczatek->poprzedni_wezel = nowyWezel;
        poczatek->poprzedni_wezel->nastepny_wezel = poczatek;
        poczatek = nowyWezel;
        nowyWezel->wartosc = wartosc;
    }
    else {
        Wezel* nowyWezel = new Wezel;
        poczatek = nowyWezel;
        koniec = nowyWezel;
        nowyWezel->wartosc = wartosc;
    }
    if (wezel == nullptr) {
        wezel = poczatek;
    }
    ilosc_elementow++;
}

/**
 * @brief Dodaje nowy element na koniec listy.
 *
 * @param wartosc Wartosc do dodania na koniec listy.
 */
void ListaDwukierunkowa::Dodawanie_nakoniec(int wartosc) {
    if (ilosc_elementow > 0) {
        Wezel* nowyWezel = new Wezel;
        koniec->nastepny_wezel = nowyWezel;
        koniec->nastepny_wezel->poprzedni_wezel = koniec;
        koniec = nowyWezel;
        nowyWezel->wartosc = wartosc;
    }
    else {
        Wezel* nowyWezel = new Wezel;
        poczatek = nowyWezel;
        koniec = nowyWezel;
        nowyWezel->wartosc = wartosc;
    }
    if (wezel == nullptr) {
        wezel = poczatek;
    }
    ilosc_elementow++;
}

/**
 * @brief Wyswietla wszystkie elementy listy od poczatku.
 */
void ListaDwukierunkowa::Wyswietlanie_od_poczatku() {
    Wezel* wskaznik = poczatek;
    for (int i = 0; i < ilosc_elementow; i++) {
        std::cout << wskaznik->wartosc << std::endl;
        if (wskaznik->nastepny_wezel != nullptr) {
            wskaznik = wskaznik->nastepny_wezel;
        }
        else {
            return;
        }
    }
}

/**
 * @brief Wyswietla wszystkie elementy listy od konca.
 */
void ListaDwukierunkowa::Wyswietlanie_od_konca() {
    Wezel* wskaznik = koniec;
    for (int i = 0; i < ilosc_elementow; i++) {
        std::cout << wskaznik->wartosc << std::endl;
        wskaznik = wskaznik->poprzedni_wezel;
    }
}

/**
 * @brief Dodaje nowy element na okreslony indeks w liscie.
 *
 * @param wartosc Wartosc do dodania.
 * @param index Indeks, na ktory ma zostac dodany element.
 */
void ListaDwukierunkowa::Dodawanie_na_index(int wartosc, int index) {
    if (index > 0 && index < ilosc_elementow) {
        Wezel* nowyWezel = new Wezel;
        Wezel* wskaznik = poczatek;
        for (int i = 0; i < index - 1; i++) {
            wskaznik = wskaznik->nastepny_wezel;
        }
        nowyWezel->nastepny_wezel = wskaznik->nastepny_wezel;
        wskaznik->nastepny_wezel->poprzedni_wezel = nowyWezel;
        wskaznik->nastepny_wezel = nowyWezel;
        nowyWezel->poprzedni_wezel = wskaznik;
        nowyWezel->wartosc = wartosc;
        ilosc_elementow++;
    }
    else if (index == 0) {
        Dodawanie_napoczatek(wartosc);
    }
    else if (index == ilosc_elementow) {
        Dodawanie_nakoniec(wartosc);
    }
    else {
        std::cout << "Index poza lista";
    }
}

/**
 * @brief Usuwa pierwszy element z listy.
 */
void ListaDwukierunkowa::usuwanie_z_poczatku() {
    if (!poczatek) {
        std::cout << "brak elementow\n";
    }
    else {
        if (ilosc_elementow > 1) {
            Wezel* obecny = poczatek->nastepny_wezel;
            delete obecny->poprzedni_wezel;
            poczatek = obecny;
        }
        else if (ilosc_elementow == 1) {
            delete poczatek;
            koniec = nullptr;
            poczatek = nullptr;
        }
    }
    ilosc_elementow--;
}

/**
 * @brief Usuwa ostatni element z listy.
 */
void ListaDwukierunkowa::usuwanie_z_konca() {
    if (!koniec) {
        std::cout << "brak elementow\n";
    }
    else {
        if (ilosc_elementow > 1) {
            Wezel* obecny = koniec->poprzedni_wezel;
            delete obecny->nastepny_wezel;
            koniec = obecny;
        }
        else if (ilosc_elementow == 1) {
            delete koniec;
            koniec = nullptr;
            poczatek = nullptr;
        }
    }
    ilosc_elementow--;
}

/**
 * @brief Usuwa element z listy na danym indeksie.
 *
 * @param index Indeks elementu do usuniecia.
 */
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
    else if (index == 0) {
        usuwanie_z_poczatku();
    }
    else if (index == ilosc_elementow) {
        usuwanie_z_konca();
    }
    else {
        std::cout << "Index poza lista";
    }
    ilosc_elementow--;
}

/**
 * @brief Usuwa wszystkie elementy z listy.
 */
void ListaDwukierunkowa::czyszczenie_listy() {
    do {
        usuwanie_z_konca();
    } while (ilosc_elementow > 0);
}

/**
 * @brief Wyswietla nastepny element w liscie.
 */
void ListaDwukierunkowa::wyswietl_nastepny() {
    if (wezel->nastepny_wezel != nullptr && wezel != nullptr) {
        wezel = wezel->nastepny_wezel;
    }
    else {
        std::cout << "nie ma nastepnego elementu listy";
        return;
    }
    std::cout << wezel->wartosc;
}

/**
 * @brief Wyswietla poprzedni element w liscie.
 */
void ListaDwukierunkowa::wyswietl_poprzedni() {
    if (wezel->poprzedni_wezel != nullptr) {
        wezel = wezel->poprzedni_wezel;
    }
    else {
        std::cout << "Nie ma poprzedniego elementu listy";
        return;
    }
    std::cout << wezel->wartosc;
}
