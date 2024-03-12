/*
*****Sprawozdanie SPD Laboratorium*****
Michal Dos 
nr indeksu: 263498

Termin oddania: 13.03.2024r.

Cwiczenie 1

Wyniki dzialania programu dla:
    data1 - 14950
    data2 - 20198
    data3 - 34509
    data4 - 35155

suma calkowita 105532

Sugerowana ocena 3.5

*/



#include <iostream>
#include <fstream>


/**
 * @brief Struktura proces, przechowuje informacje o zadaniach:
            nr: Numer zadania.
            r: Czas przgotowania zadania.
            p: Czas trwania zadania.
            q: Czas wygaszania zadania.
 * 
 */
struct proces{
	int nr;
	int r;
	int p;
	int q;
};

/**
 * @brief Oblicza czas zakończenia wszystkich zadań.Dla każdego zadania:
            Oblicza czas zakończenia zadania (max) jako maksimum z czasu przyjścia zadania i sumy czasu trwania zadania.
            Oblicza całkowity czas zakończenia (c) jako maksimum z poprzedniego czasu zakończenia i czasu oczekiwania zadania.
 * 
 * @param tab 
 * @param rozmiar Iteruje po tablicy zadanego rozmiaru.
 * @return int Zwraca całkowity czas zakończenia.
 */
int suma(proces tab[], int rozmiar){
	int max=0;
	int c=0;
	for(int i=0; i<rozmiar; i++){
		max = std::max(max, tab[i].r) + tab[i].p;
		c = std::max(c,max + tab[i].q);
	}
	return c;
}

/**
 * @brief Wyświetla kolejność zadań.
 * 
 * @param tab 
 * @param rozmiar 
 */
void wyswietl(proces tab[], int rozmiar){
	std::cout << "->Kolejnosc zadan:" << std::endl;
	for(int i=0; i<rozmiar; i++){
		std::cout << tab[i].nr << ", ";
	}
	std::cout << std::endl;

}

/**
 * @brief Zamienia dwa elementy w tablicy zadanego indeksu.
 * 
 * @param tab 
 * @param a 
 * @param b 
 */
void zamien(proces tab[], int a, int b){

	proces temp;

	temp.nr = tab[a].nr;
	temp.r = tab[a].r;
	temp.q = tab[a].q;
	temp.p = tab[a].p;

	tab[a].nr = tab[b].nr;
	tab[a].r = tab[b].r;
	tab[a].p = tab[b].p;
	tab[a].q = tab[b].q;

	tab[b].nr = temp.nr;
	tab[b].r = temp.r;
	tab[b].p = temp.p;
	tab[b].q = temp.q;
}

/**
 * @brief Wykonuje algorytm szeregowania zadań.
        Iteruje po zadanej liczbie iteracji (10 razy w tym przypadku).
        Przegląda wszystkie pary zadań i zamienia je, jeśli to poprawia całkowity czas zakończenia.
        Aktualizuje całkowity czas zakończenia.
 * 
 * @param tab 
 * @param rozmiar 
 */
void szeregowanie(proces tab[], int rozmiar){

	int length = suma(tab, rozmiar);
	int l;

	
		for(int j = 0; j < rozmiar; j++){
			for(int k = 0; k < rozmiar; k++){
				zamien(tab, j, k);
				l = suma(tab, rozmiar);
				if(l > length){
					zamien(tab, j, k);
				}
				else{
					length = l;
				}
			}
		
	}
}

int main(){
	int suma_calkowita=0;
	char znak;
	std::string s;
	std::string part[4] = {"data.1","data.2","data.3","data.4"};
	int n=0;
	int tab[4];
	proces tablica[100];
	std::ifstream input("data.txt");
	for(int i=0; i<4; i++){
		std::cout << "Paczka danych: " << i + 1 << std::endl;
		while(s!=part[i]){
			input >> s;
		}
		input >> n;
		for(int i=0; i<n; i++){
			tablica[i].nr = i + 1;
			input >> tablica[i].r;
			input >> tablica[i].p;
			input >> tablica[i].q;
		}
		szeregowanie(tablica, n);
		tab[i] = suma(tablica, n);
		wyswietl(tablica, n);
		std::cout << "Suma " << tab[i] << std::endl;
		std::cout << "------------------------" << std::endl;
	}
	for(int i=0; i<4;i++){
		suma_calkowita += tab[i];
	}
	std::cout << "Suma calkowita: " << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << suma_calkowita << std::endl;
		std::cout << "------------------------" << std::endl;
}
