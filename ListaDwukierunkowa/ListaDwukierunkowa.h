#pragma once
using namespace std;

/**
 * @brief Struktura reprezentujaca wezel w liscie dwukierunkowej.
 */
struct Wezel {
    int wartosc; /**< Wartosc przechowywana w wezle. */
    Wezel* nastepny_wezel; /**< Wskaznik na nastepny wezel w liscie. */
    Wezel* poprzedni_wezel; /**< Wskaznik na poprzedni wezel w liscie. */

    /**
     * @brief Konstruktor domyslny inicjalizujacy wartosc oraz wskazniki.
     */
    Wezel() : wartosc(NULL), poprzedni_wezel(nullptr), nastepny_wezel(nullptr) {}

    /**
     * @brief Destruktor wezla.
     */
    ~Wezel() {}
};

/**
 * @brief Klasa reprezentujaca liste dwukierunkowa.
 */
class ListaDwukierunkowa {
private:
    Wezel* poczatek; /**< Wskaznik na poczatek listy. */
    Wezel* koniec; /**< Wskaznik na koniec listy. */
    int ilosc_elementow; /**< Liczba elementow w liscie. */

public:
    Wezel* wezel; /**< Wskaznik na biezacy wezel w liscie. */

    /**
     * @brief Konstruktor domyslny inicjalizujacy pusta liste.
     */
    ListaDwukierunkowa() : poczatek(nullptr), koniec(nullptr), ilosc_elementow(0), wezel(nullptr) {}

    /**
     * @brief Destruktor listy dwukierunkowej.
     */
    ~ListaDwukierunkowa() {}

    /**
     * @brief Dodaje nowy element na poczatek listy.
     *
     * @param wartosc Wartosc do dodania na poczatek listy.
     */
    void Dodawanie_napoczatek(int wartosc);

    /**
     * @brief Dodaje nowy element na koniec listy.
     *
     * @param wartosc Wartosc do dodania na koniec listy.
     */
    void Dodawanie_nakoniec(int wartosc);

    /**
     * @brief Wyswietla wszystkie elementy listy od poczatku.
     */
    void Wyswietlanie_od_poczatku();

    /**
     * @brief Wyswietla wszystkie elementy listy od konca.
     */
    void Wyswietlanie_od_konca();

    /**
     * @brief Dodaje nowy element na okreslony indeks w liscie.
     *
     * @param wartosc Wartosc do dodania.
     * @param index Indeks, na ktory ma zostac dodany element.
     */
    void Dodawanie_na_index(int wartosc, int index);

    /**
     * @brief Usuwa pierwszy element z listy.
     */
    void usuwanie_z_poczatku();

    /**
     * @brief Usuwa ostatni element z listy.
     */
    void usuwanie_z_konca();

    /**
     * @brief Usuwa element z listy na danym indeksie.
     *
     * @param index Indeks elementu do usuniecia.
     */
    void usuwanie_z_indexu(int index);

    /**
     * @brief Usuwa wszystkie elementy z listy.
     */
    void czyszczenie_listy();

    /**
     * @brief Wyswietla nastepny element w liscie.
     */
    void wyswietl_nastepny();

    /**
     * @brief Wyswietla poprzedni element w liscie.
     */
    void wyswietl_poprzedni();
};
