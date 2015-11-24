#include <iostream>
#include <math.h>
#include <stdlib.h>

/*Odchylenie v1.0
 *Program służy do liczenia wartości średniej i odchylenia standardowego z liczb podanych jako parametry linii komend.
 *Autor: Aleksander Szpakiewicz-Szatan 24.11.2015*/

using namespace std;

int main(int argc, char *arg[]) 	//obsługa parametrów linii komend
{
	int ilosc=argc-1; 				//unikamy ciągłego pisania argc-1, odejmujemy 1, bo nazwa programu jest traktowana jako parametr z indeksem 0.
	if(ilosc==0) 					//jeśli nie podano żadnych parametrów
	{
		cout<<"Nie podano żadnych liczb do policzenia odchylenia standardowego :/"<<endl;	//poinformuj o tym użytkownika
		cout<<"Wywołanie programu: [nazwa programu] [liczby (oddzielone znakiem spacji) z których program powinien policzyć średnią i odchylenie standardowe]"<<endl;
		return 1;					//i zakończ program
	}
	double *dane=new double[ilosc]; //zarezerwuj pamięć dla liczb
	char *perr;						//zmienna do przechwycenia nieliczbowej części łańcuchów znaków
	
	for(int ii=0;ii<ilosc;ii++)		//odczytaj wszystkie liczby z parametrów linii komend (w formie łańcuchów znaków)
	{
		dane[ii]=strtod(arg[ii+1],&perr);	//odczytaj liczby zmiennoprzecinkowe z łańcuchów znaków
		if(*perr!='\0')				//jeśli któryś z parametów zawiera coś zamiast/oprócz liczby uprzedś użytkownika
			cout<<"UWAGA! Któraś z liczb może nie być prawidłową liczbą (pojawia się tekst i/lub użytkownik użył w liczbach wymiernych przecinka zamiast kropki)."<<endl;
									//UWAGA: jeśli któryś z parametrów nie będzie liczbą, to zostanie potraktowany jak liczba 0 zniekształcając wyniki
	}
	double sr=0;					//średnia wartość
	double D=0;						//odchylenie standardowe
	
	for(int ii=0;ii<ilosc;ii++) 	//dodaj do siebie wszystkie liczby podane na wejściu
		sr+=dane[ii];
	sr/=(ilosc); 					//podziel ich sumę przez ich ilość
	
	for(int ii=0;ii<ilosc;ii++)		//dla wszystkich liczb skorzystaj ze wzoru na kwadrat odchylenia standardowego: SUMA (liczba-wartość średnia)^2
		D+=(dane[ii]-sr)*(dane[ii]-sr)/(ilosc);
	D=sqrt(D);						//oblicz odchylenie standardowe
	
	cout<<"Średnia: "<<sr<<";"<<endl;
	cout<<"Odchylenie standardowe: "<<D<<endl;
	
	delete []dane; 					//zwolnij pamięć
	return 0;
}