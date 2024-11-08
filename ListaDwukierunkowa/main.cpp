
#include <iostream>
#include "ListaDwukierunkowa.h"

using namespace std;
int main()
{

   
  
    ListaDwukierunkowa a;
    cout << "Lista po dodaniu napoczatek 5 i dodaniu 6 7 9 na koniec:";
    cout << endl;
    a.Dodawanie_napoczatek(5);
    a.Dodawanie_nakoniec(6);
    a.Dodawanie_nakoniec(7);
    a.Dodawanie_nakoniec(9);
    a.Wyswietlanie_od_poczatku();
    cout << endl;

    cout << "wyswietl nastepny:";
    cout << endl;
    a.wyswietl_nastepny();
    cout << endl;


    cout << "wyswietl poprzedni:";
    cout << endl;
    a.wyswietl_poprzedni();
    cout << endl;



    cout << "Wyswietlanie od konca:";
    cout << endl;
    a.Wyswietlanie_od_konca();
    a.Dodawanie_na_index(5,0);
    cout << "Lista po dodaniu indexu 5 :";
    cout  << endl;
    a.Wyswietlanie_od_poczatku();
    cout << "Usuwanie z poczatku:";
    cout << endl;
    a.usuwanie_z_poczatku();
    a.Wyswietlanie_od_poczatku();
    cout << "Usuwanie z konca:";
    cout << endl;
    a.usuwanie_z_konca();
    a.Wyswietlanie_od_poczatku();
    cout << "Usuwanie z indexu:";
    cout << endl;
    a.usuwanie_z_indexu(1);
    a.Wyswietlanie_od_poczatku();


    cout << "Czyszczenie listy:";
    cout << endl;
    a.czyszczenie_listy();
    a.Wyswietlanie_od_poczatku();





    //a.czyszczenie_listy();

 
}

