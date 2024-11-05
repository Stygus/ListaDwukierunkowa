
#include <iostream>
#include "ListaDwukierunkowa.h"
#include "ListaDwukierunkowa.cpp"

using namespace std;
int main()
{

   
  
    ListaDwukierunkowa a;
    a.Dodawanie_napoczatek(5);
    a.Dodawanie_nakoniec(6);
    a.Dodawanie_nakoniec(7);
    a.Dodawanie_napoczatek(9);
    a.Wyswietlanie_od_poczatku();
    cout << endl;
    a.Wyswietlanie_od_konca();


}
