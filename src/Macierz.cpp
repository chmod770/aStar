#include <string>
#include <fstream>
#include<iostream>
#include "Macierz.h"
using namespace std;

Macierz::Macierz(string nazwaPliku)
{
    ifstream plik;
    string a;
    int liczba;
    this->wiersze=0;
    this->kolumny=0;
    //sprawdzanie ile wierszy i kolumn potrzeba
    plik.open( nazwaPliku.c_str() );
    if( !plik.good() )
    {
        cout<<"Nie mozna otworzyc pliku"<<endl;
         return;
    }

    //obliczanie iloúci wierrszy i kolumn
    this->wiersze=1;
    while( true ){
        getline(plik, a);
        if( plik.good() ){
            this->wiersze++;
        }else
             break;
        this->kolumny = (a.length()+1)/2;
    }

    //generowanie tablicy do przechowywania macierzy
    this->wartosci = new int*[wiersze];
    for(int i = 0 ; i < kolumny;i++){
        this->wartosci[i]= new int[wiersze];
    }

    //przenoszenia wskaünika pliki na poczπtek
    plik.clear();
    plik.seekg(0, ios::beg);


    //uzupe≥aniae tablicy do przechowywania macierzy
    for(int i = 0 ; i< wiersze;i++)
    {
        for(int j = 0 ; j < kolumny;j++)
        {
            plik>>liczba;
            this->wartosci[i][j]=liczba;
            kolumny = (a.length()+1)/2;
        }
    }

    this->wiersze=wiersze;
    this->kolumny=kolumny;
}

