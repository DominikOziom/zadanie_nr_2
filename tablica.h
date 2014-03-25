#ifndef TABLICA_H
#define TABLICA_H
/*!
 * \file
 * \brief Definicja klasy Tablica.
 *
 *  Plik zawiera deklaracje tablicy argumentow typu int
 *  oraz zapowiedzi funkcji wczytywania danych z pliku,
 *  wyswietlania tabel z danymi, zerowania tabel, wymnazania tabeli razy 2,
 *  zamiany kolejnosci 2 elementow w tabeli, odwracania tabeli, dodawania elementu
 *  oraz elementow do tabeli, wykonania wielokrotnie mnozenia tablicy oraz
 *  wyswietlania menu uzytkownika.
 */

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <sys/time.h>

/*! 
 * \brief Modeluje pojecie klasy Tablica.
 *
 * Klasa modelujaca pojecie tablicy argumentow
 * typu int.
 */
using namespace std;

class Tablica {
public:
  int rozmiar;   /*! zmienna typu int zawierajaca informacje o ilosci elementow w tablicy danych */
  int rozmiar_wzor; /*! zmienna typu int zawierajaca informacje o ilosci elementow w tablicy wzorcowej */
  int rozmiar_tab_wczytywanej;/*! zmienna typu int zawierajaca informacje o ilosci elementow w tablicy dodawanej do glownej tablicy danych*/
  int ilosc_powtorzen;/*! zmienna typu int okreslajaca ilosc powtorzen algorytmu mnozenia tablicy danych */
  int *tab_liczb;/*! parametr deklarujacy tablicę elementow typu int */
  int *tab_liczb_wzor;/*! parametr deklarujacy tablicę wzorcowa elementow typu int */ 
  timeval start, stop;/*! zmienne typu timeval uzyte przy liczeniu czasu pracy algorytmu mnozenia*/
  double czas_pracy;/*! zmienna typu double zawierajaca informacje o czasie pracy algorytmu mnozenia*/

/*!
* \brief konstruktor tablicy dynamicznej
*/
Tablica(){ rozmiar = 0, rozmiar_wzor = 0, rozmiar_tab_wczytywanej = 0, tab_liczb=0, tab_liczb_wzor = 0, czas_pracy = 0; }

/*!
* \brief destruktor tablicy dynamicznej
*/
~Tablica(){ delete [] tab_liczb;
	if (rozmiar_wzor != 0)
  		{
  			delete [] tab_liczb_wzor;
  		}
	 } 

/*!
 *\brief  Wczytywanie liczb z pliku tekstowego
 * 
 * Funkcja wczytuje liczby z pliku tekstowego i zapisuje wczytane wartosci do klasy Tablica.
 * Plik musi zawierac liczbe argumentow, ktore posiada tablica oraz te argumenty zapisane w kolumnie.
 */ 
void Wczytaj_Argumenty_Z_Pliku();

/*!
 *\brief  Wczytywanie liczb z wzorcowego pliku tekstowego
 * 
 * Funkcja wczytuje liczby z wzorcowego pliku tekstowego i zapisuje wczytane wartosci do klasy Tablica.
 * Plik musi zawierac liczbe argumentow, ktore posiada tablica oraz te argumenty zapisane w kolumnie.
 */ 
void Wczytaj_Argumenty_Spr_Z_Pliku();

/*!
 *\brief  Wczytywanie liczb z pliku tekstowego
 * 
 * Funkcja wczytuje liczby z pliku tekstowego. Uzywana jest w trakcie dodawania wiekszej ilosci elementow
 * do tablicy danych
 *\param[in] nazwa1  - zmienna typu string zawierajaca nazwe pliku z ktorego odbywa sie odczyt informacji
 */
void Wczytaj_Dane_Wzor(string nazwa1);

/*!
 *\brief  Zerowanie tablic obiektu Tablica
 * 
 * Funkcja zeruje tablice obiektu Tablica oraz zmienne typu int okreslajace ich wielkosc
 */ 
void Wyzeruj_Tablice();

/*!
 *\brief  wyswietlanie tablicy danych
 * 
 * Funkcja drukuje na stdout wszystkie elementy tablicy danych
 */ 
void Pokaz_Dane();

/*!
 *\brief  wyswietlanie wzorcowej tablicy danych 
 * 
 * Funkcja drukuje na stdout wszystkie elementy wzorcowej tablicy danych
 */ 
void Pokaz_Dane_Wzor();

/*!
 *\brief  Wymnozenie wartosci tablicy razy dwa
 * 
 * Funkcja wczytuje kolejne wartosci tablicy, przemnaza je przez dwa i zapisuje otrzymane wartosci
 * spowrotem w danym obiekcie
 */
void Wymnoz_Tablice_Liczb();

/*!
 *\brief  Porownanie wartosci dwoch tablic
 * 
 * Funkcja wczytuje kolejne wartosci dwoch tablic i porownuje ich wartosci
 * \return Zwraca odpowiednie komunikaty jesli tablice sa takie same lub rozne.
 */
void Porownaj_Wartosci_Tablic();

/*!
 *\brief  Zamienia miejscami dwa elementy tablicy
 * 
 * Funkcja pyta uzytkownika o indeksy dwoch elementow, ktore maja byc zamienione i nastepnie wykonuje te zamiane.
 *
 */
void Zamien_Miejscami();

/*!
 *\brief  Zmiana kolejnosci elementow w tablicy
 * 
 * Funkcja odwraca kolejnosc elementow zapisanych w danej tablicy
 */
void Odwroc_Kolejnosc();

/*!
 *\brief  Dodaje element do tablicy
 * 
 * Funkcja dodaje kolejny element do danej tablicy
  *\param[in] e  - zmienna typu int ,ktora zostanie dodana na koncu tablicy danych
 */
void Dodaj_Element(int e);

/*!
 *\brief  Tworzy nowy plik z danymi
 * 
 * Funkcja tworzy nowy plik tekstowy o nazwie tlica_testowa.txt i zapisuje w niej okreslona ilosc
 * liczb w kolumnie
 */
void Stworz_Plik_Do_Dodania_Elementow();

/*!
 *\brief  Dodaje elementy do tablicy
 * 
 * Funkcja dodaje kilka elementow do danej tablicy, pyta uzytkownika o ilosc elementow, ktore chce dodac
 * nastepnie tworzy w pliku pomocniczym ablice z odpowiednia iloscia elementow i wczytuje je do tablicy
 * danych obiektu Tablica.
 */
void Dodaj_Elementy();

/*!
 *\brief  Porownanie dwoch tablic
 * 
 * Funkcja przeciaza operator == aby umozliwic latwe porownanie dwoch tablic danych,
 * w pierwszej kolejnosci sprawdza zgodnosc rozmiarow tablic, a potem kolejne ich elementy.
  *\param[in] tab1, tab2  - wskazniki na obiekt Tablica zawierajace porownywane miedzy soba tablice danych
 */
friend bool operator == (Tablica &tab1, Tablica &tab2);

/*!
 *\brief  Wykonanie algorytmu wielokrotnego mnozenia tablicy danych
 * 
 * Funkcja pyta o plik zrodlowy z zapisana w nim tablica danych, wczytuje go, pyta o ilosc
 * powtorzen operacji mnozenia, wykonuje dana operacje oraz zlicza czas jej wykonania.
 * Na koncu wyswietla wyniki operacji na stdout, a takze zapisuje je w pliku tekstowym csv.txt
 * podajac kolejno ilosc elementow tablicy, ilosc powtorzen, czas pracy.
 */
void Wykonaj_Algorytm();

/*!
* \brief Wyswietla menu uzytkownika
*/
void Wyswietl_Menu();
};


#endif
