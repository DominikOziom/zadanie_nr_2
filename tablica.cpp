/*!
 * \file
 * \brief Definicje funkcji klasy Tablica
 *
 * Zawiera definicje funkcji wczytywania danych z pliku,
 * wyswietlania tabel z danymi, zerowania tabel, wymnazania tabeli razy 2,
 * zamiany kolejnosci 2 elementow w tabeli, odwracania tabeli, dodawania elementu
 * oraz elementow do tabeli, wykonania wielokrotnie mnozenia tablicy oraz
 * wyswietlania menu uzytkownika.
 */
#include "tablica.h"
using namespace std;


void Tablica::Wczytaj_Argumenty_Z_Pliku(){

	rozmiar=0;
	int index=0;
	string nazwa;
	cout <<"Podaj nazwe pliku zrodlowego txt : " << endl;
	cin >> nazwa;	
	fstream plik1;
   	plik1.open( nazwa.c_str());   //otwarcie pliku zrodlowego
   if ( !plik1.is_open() ) {
    cerr << "Blad otwarcia pliku" << endl;
    }
	else{
		plik1 >> rozmiar;
	if(rozmiar>0){
		tab_liczb=new int[rozmiar];
		while(!plik1.eof()){
			plik1 >> tab_liczb[index++];
		}}}}


void Tablica::Wczytaj_Argumenty_Spr_Z_Pliku(){

	rozmiar_wzor=0;
	int index=0;
	string nazwa;
	cout <<"Podaj nazwe pliku wzorcowego txt : " << endl;
	cin >> nazwa;	
	fstream plik1;
   	plik1.open( nazwa.c_str());   //otwarcie pliku zrodlowego
   if ( !plik1.is_open() ) {
    cerr << "Blad otwarcia pliku" << endl;
    }
	else{
		plik1 >> rozmiar_wzor;
	if(rozmiar_wzor>0){
		tab_liczb_wzor=new int[rozmiar_wzor];
		while(!plik1.eof()){
			plik1 >> tab_liczb_wzor[index++];
		}}}}

void Tablica::Wczytaj_Dane_Wzor(string nazwa1){
	rozmiar_wzor = 0;
	int index;
	fstream plik1;
   	plik1.open( nazwa1.c_str());   //otwarcie pliku zrodlowego
  	if ( !plik1.is_open() ) {
 	cerr << "Blad otwarcia pliku" << endl;
    	}
	else{
    	plik1 >> rozmiar_wzor;
    	if (rozmiar_wzor > 0){
    		tab_liczb_wzor = new int[rozmiar_wzor];
    		while (!plik1.eof())
    			plik1 >> tab_liczb_wzor[index++];
    	}
    }
}


void Tablica::Wyzeruj_Tablice(){
	delete [] tab_liczb;
	delete [] tab_liczb_wzor;
	rozmiar = 0;
	rozmiar_wzor =0;
	cout << " Tablice wyzerowane" << endl;
}

void Tablica::Pokaz_Dane(){
	cout << "Wartosci tabeli:" << endl;
	for( int i  = 0 ; i < rozmiar; i++)
		cout << tab_liczb[i] << endl;
}

void Tablica::Pokaz_Dane_Wzor(){
	cout << "Wartosci tabeli wzorcowej:" << endl;
	for( int i  = 0 ; i < rozmiar_wzor; i++)
		cout << tab_liczb_wzor[i] << endl;
}

void Tablica::Wymnoz_Tablice_Liczb(){
	gettimeofday(&start, NULL);
	for( int i  = 0 ; i < rozmiar; i++)
		tab_liczb[i]=tab_liczb[i]*2;
	gettimeofday(&stop, NULL);

czas_pracy = (stop.tv_sec - start.tv_sec)*1000.0;
czas_pracy += (stop.tv_usec - start.tv_usec) / 1000.0;
}


void Tablica::Porownaj_Wartosci_Tablic(){
if (rozmiar==rozmiar_wzor){
		for (int i=0;i<rozmiar;i++)
		{
			if ((tab_liczb[i]!=tab_liczb_wzor[i]) && (rozmiar==rozmiar_wzor)) 
				cerr << "wartosci tablic nie sa zgodne" << endl;
				break;
			}
		cout << "sprawdzanie zakonczone sukcesem, nie wykryto bledow" << endl;
		}	
	else{
		cerr << "Rozmiary tablic sa rozne!" << endl;
	}
}



void Tablica::Zamien_Miejscami(){
int save, i, j;

	cout << "podaj 1 indeks ( nie wiekszny niz " << rozmiar-1 << " ): ";
	cin >> i;
	cout << "podaj 2 indeks ( nie wiekszny niz " << rozmiar-1 << " ): ";
	cin >> j;

if((j>0)&&(i>0)){
		save = tab_liczb[i];
		tab_liczb[i]=tab_liczb[j];
		tab_liczb[j]=save;
		cout << "Zamieniono liczby miejscami" << endl;
	}
	else cerr << "Podano zle indeksy!" << endl;
}



void Tablica::Odwroc_Kolejnosc(){

tab_liczb_wzor = new int[rozmiar];
	for (int i=0;i<rozmiar;i++){
		tab_liczb_wzor[i] = tab_liczb[(rozmiar-1)-i];
	}
	for (int i=0;i<rozmiar;i++){
		tab_liczb[i]=tab_liczb_wzor[i];
	}
	delete [] tab_liczb_wzor;
	rozmiar_wzor=0;	
cout << "Odwrocono kolejnosc liczb w tablicy" << endl;
}


void Tablica::Dodaj_Element(int e){

	tab_liczb_wzor = new int[rozmiar];
	for (int i=0;i<rozmiar;i++){
		tab_liczb_wzor[i] = tab_liczb[i];
	}
	++rozmiar;
	rozmiar_wzor = rozmiar;
	delete [] tab_liczb;
	tab_liczb = new int[rozmiar];
	for (int i=0;i<(rozmiar-1);++i){
		tab_liczb[i]=tab_liczb_wzor[i];
	}
	tab_liczb[rozmiar-1] = e;
	delete [] tab_liczb_wzor;
	rozmiar_wzor = 0;
	cout << "Dodano nowy element do tablicy" << endl;
}


void Tablica::Stworz_Plik_Do_Dodania_Elementow(){

	ofstream plik("tablica_testowa.txt");
	cout << endl;
	cout<<"Ile liczb chcesz wpisac? : ";
	cin>>rozmiar_tab_wczytywanej;
	if (rozmiar_tab_wczytywanej>0)
	{
		cout<<"\n Wypelnianie wpliku..." << endl;
		plik << rozmiar_tab_wczytywanej << endl;
		for (int i=1;i<(rozmiar_tab_wczytywanej+1);i++){
			plik << i << endl;
		}
	}
}

void Tablica::Dodaj_Elementy(){

	Stworz_Plik_Do_Dodania_Elementow();
	Wczytaj_Dane_Wzor("tablica_testowa.txt");
	int *tab_nowa=0;
	tab_nowa = new int[rozmiar];
	for (int i=0;i<rozmiar;i++){
		tab_nowa[i] = tab_liczb[i];
	}
	delete [] tab_liczb;
	rozmiar=rozmiar+rozmiar_tab_wczytywanej;
	tab_liczb = new int[rozmiar];
	int j = 0;
	for (int i=0;i<(rozmiar);i++){
		if(i<(rozmiar-rozmiar_tab_wczytywanej))
			tab_liczb[i]=tab_nowa[i];
		else {
			tab_liczb[i]=tab_liczb_wzor[j];
			j++;
		}
	}	
	delete [] tab_nowa;
	rozmiar_tab_wczytywanej = 0;
        cout << "Dodano nowe elementy do tablicy" << endl;
}


bool operator == (Tablica &tab1, Tablica &tab2){

	if ((tab1.rozmiar>0) && (tab1.rozmiar == tab2.rozmiar)){
		for (int i=0;i<tab1.rozmiar;i++){
			if (tab1.tab_liczb[i] != tab2.tab_liczb[i]){
				return false;				
			}
			}
}
	return true;
}

void Tablica::Wykonaj_Algorytm(){
	timeval begin, end;

	Wczytaj_Argumenty_Z_Pliku();
	cout << endl;
	cout<<"Ile razy wykonac algorytm? : ";
	cin>>ilosc_powtorzen;
	gettimeofday(&begin, NULL);
	for (int i = 0; i < ilosc_powtorzen;i++)
	{
		Wymnoz_Tablice_Liczb();
	}

	gettimeofday(&end, NULL);

	czas_pracy = (end.tv_sec - begin.tv_sec)*1000.0;
	czas_pracy += (end.tv_usec - begin.tv_usec) / 1000.0;

	cout << "Czas calkowity wykonania algorytmu ( "<< ilosc_powtorzen << " razy ) to:" << endl
		<< czas_pracy << "ms. " << " dla tabeli o " << rozmiar << " elementach " <<endl;

	
	fstream plik1;
   	plik1.open("csv.txt");   //otwarcie pliku zrodlowego
   if ( !plik1.is_open() ) {
    cerr << "Blad otwarcia pliku do zapisu wynikow koncowych" << endl;
    }
	else{
		plik1 << rozmiar <<"  "<< ilosc_powtorzen <<"  "<< czas_pracy << endl;
}
}

void Tablica::Wyswietl_Menu(){
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
}
