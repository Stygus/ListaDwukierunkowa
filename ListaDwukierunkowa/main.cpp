
#include <iostream>
#include "ListaDwukierunkowa.h"

using namespace std;
int main()
{

   
  
    ListaDwukierunkowa a;
    a.Dodawanie_napoczatek(5);
    a.Dodawanie_nakoniec(6);
    a.Dodawanie_nakoniec(7);
    a.Dodawanie_nakoniec(9);
    a.Wyswietlanie_od_poczatku();
    cout << endl;
    a.Dodawanie_na_index(5,0);
  //  a.Wyswietlanie_od_poczatku();
  //  /*a.usuwanie_z_poczatku();*/
  // /* a.usuwanie_z_indexu(3);*/
  ///*  cout << endl;
  //  a.czyszczenie_listy();
  //  a.Wyswietlanie_od_poczatku();
  // */
    a.wyswietl_nastepny();

}

