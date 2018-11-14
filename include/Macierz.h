#ifndef MACIERZ_H
#define MACIERZ_H
#include <iostream>
#include <vector>
#include "ElementListyOtwartej.h"
#include <windows.h>
using namespace std;
class Macierz
{
    public:
        Macierz(std::string nazwaPliku);
        void setWiersze(int wartosc)
        {
            this->wiersze = wartosc;
        }
        int getWiersze()
        {
            return this->wiersze;
        }
        void setKolumny(int wartosc)
        {
            this->kolumny=wartosc;
        }
        int getKolumny()
        {
            return this->kolumny;
        }
        int getWartoscPola(int x, int y)
        {
            return this->wartosci[x][y];
        }
        void setGoal(int x, int y)
        {
            this->goal_x = x;
            this->goal_y = y;
        }
        bool czyDostepne(int x, int y)
        {
            if(x>=this->wiersze || y>=this->kolumny || x<0 || y<0 || this->wartosci[x][y]==5)
                return false;
            return true;
        }
        bool czyJestWLiscie( int x, int y,vector <ElementListyOtwartej> lista)
        {
            for(int i = 0 ; i < lista.size();i++)
            {
                if(lista[i].x==x && lista[i].y==y)
                    return true;
            }
            return false;
        }
        vector <ElementListyOtwartej> DostepniSasiedzi(int x, int y, int gc , vector <ElementListyOtwartej> listaZamknieta )
        {
            vector <ElementListyOtwartej> dostepniSasiedzi;
            if(czyDostepne(x,y-1)&& !czyJestWLiscie(x,y-1,listaZamknieta))
                dostepniSasiedzi.push_back(ElementListyOtwartej(x,y-1,gc,x,y,goal_x,goal_y));
            if(czyDostepne(x-1,y) && !czyJestWLiscie(x-1,y,listaZamknieta))
                dostepniSasiedzi.push_back(ElementListyOtwartej(x-1,y,gc,x,y,goal_x,goal_y));
            if(czyDostepne(x,y+1) && !czyJestWLiscie(x,y+1,listaZamknieta))
                dostepniSasiedzi.push_back(ElementListyOtwartej(x,y+1,gc,x,y,goal_x,goal_y));
            if(czyDostepne(x+1,y)&& !czyJestWLiscie(x+1,y,listaZamknieta))
                dostepniSasiedzi.push_back(ElementListyOtwartej(x+1,y,gc,x,y,goal_x,goal_y));

                return dostepniSasiedzi;
        }
        void Wypisz()
        {
            if(this->wartosci==0&&this->kolumny==0)
            {
                cout<<"Nie wczytano pliku"<<endl;
            }else{
                cout<<"aktualne wartosci macierzy:"<<endl;
                for(int i = 0; i < getWiersze() ;i++)
                {
                    for(int j = 0; j<getKolumny();j++)
                    {
                        cout<<this->wartosci[i][j]<<" ";
                    }
                    cout<<'\n';
                }
            }
          }
        void wypiszZdroaga(vector <ElementListyOtwartej> listaZamknieta)
        {

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            for(int i = 0 ; i < getWiersze(); i++)
            {
                for(int j = 0 ; j <  getKolumny(); j++)
                {
                     if(czyJestWLiscie(i,j,listaZamknieta))
                     {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                         cout<<3<<" ";
                     }else
                     {
                         SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                        cout<<wartosci[i][j]<<" ";
                     }
                }
                 cout<<endl;
            }
        }

        void reconstruct_path(vector<ElementListyOtwartej> &listaZamknieta, ElementListyOtwartej aktualnyElement, vector<ElementListyOtwartej> &listaDrogi)
        {
            ElementListyOtwartej elementDoWywolania = listaZamknieta[0];
            listaDrogi.push_back(aktualnyElement);
            if(aktualnyElement.rodzic_x == -1 && aktualnyElement.rodzic_y == -1)
            {
                listaDrogi.push_back(aktualnyElement);
                wypiszZdroaga(listaDrogi);
            }else
            {
                for(int i = 0 ; i < listaZamknieta.size(); i++)
                {
                    if(aktualnyElement.rodzic_x == listaZamknieta[i].x && aktualnyElement.rodzic_y == listaZamknieta[i].y)
                    {
                        elementDoWywolania = listaZamknieta[i];
                        break;
                    }
                }
                reconstruct_path(listaZamknieta,elementDoWywolania,listaDrogi);
            }
        }
    protected:
    private:
        int** wartosci;
        int wiersze;
        int kolumny;
        int goal_x;
        int goal_y;
};

#endif // MACIERZ_H
