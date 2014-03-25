#include <iostream>
#include <string>
#include "tablica.h"


using namespace std;
/*!
 *\brief
 * funkcja main() zawierajaca menu uzytkownika. Przy wywolaniu prosi
 * o wybor odpowiedniej opcji, w wyniku ktorej wykonuje operacje na obiekcie
 * tablicy dynamicznej. Uzywa funkcji zawartych w pliku tablica.h 
 */
int main(){ 
cout << endl; 
Tablica Tab;
 
int opcja=0;

cout << "#############################################" << endl;
cout << "              MENU UZYTKOWNIKA           " << endl;
cout << " 1 - wczytaj tabele z pliku txt          " << endl;
cout << " 2 - wczytaj tabele wzorcowa z pliku txt " << endl;
cout << " 3 - wyswietl tabele z danymi            " << endl;
cout << " 4 - wyswietl tabele wzorcowa z danymi   " << endl;
cout << " 5 - wyzeruj tablice                     " << endl;
cout << " 6 - wymnoz tabele danych                " << endl;
cout << " 7 - zamien miejscami dwa elementy tablicy" << endl;
cout << " 8 - odwroc kolejnosc elementow tablicy  " << endl;
cout << " 9 - dodaj element do tablicy            " << endl;
cout << "10 - dodaj elementy do tablicy           " << endl;
cout << "11 - Wykonaj wielokrotny algorytm mnozenia tablicy" << endl;
cout << "12 - Wyswietl menu uzytkownika           " << endl;
cout << "13 - Porownaj tablice danych z tablica wzorcowa" << endl;
cout << "14 - Zakoncz dzialanie programu          " << endl;
cout << "#############################################" << endl;
do{
cout << endl;
cout << "Twoj wybor: ";
cin >> opcja;

	switch(opcja){
		case 1: Tab.Wczytaj_Argumenty_Z_Pliku(); break;
		case 2: Tab.Wczytaj_Argumenty_Spr_Z_Pliku(); break;
    		case 3: Tab.Pokaz_Dane(); break;
		case 4: Tab.Pokaz_Dane_Wzor(); break;
		case 5: Tab.Wyzeruj_Tablice(); break;
		case 6: Tab.Wymnoz_Tablice_Liczb(); break;
		case 7: Tab.Zamien_Miejscami(); break;
		case 8: Tab.Odwroc_Kolejnosc(); break;
		case 9: {
			int nowy_elem;
			cout << "Podaj element do dodania: ";
			cin >> nowy_elem;
			Tab.Dodaj_Element(nowy_elem);} break;
		case 10: Tab.Dodaj_Elementy(); break;
		case 11: Tab.Wykonaj_Algorytm(); break;
		case 12: Tab.Wyswietl_Menu(); break;
		case 13: Tab.Porownaj_Wartosci_Tablic(); break;
		case 14: break;
		default: cerr << "Nierozpoznana opcja! Wpisz ponownie : "; break;
		}
}while(opcja != 14);

/*
Tab.Wczytaj_Argumenty_Z_Pliku();
Tab.Pokaz_Dane();
Tab.Wczytaj_Argumenty_Spr_Z_Pliku();
Tab.Pokaz_Dane_Wzor();
Tab.Wymnoz_Tablice_Liczb();
Tab.Porownaj_Wartosci_Tablic();
	
cout << "czas pracy programu: " << Tab.czas_pracy << "ms" << endl;
cout << "##################" << endl;
*/
return 0;
}

