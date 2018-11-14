#include <iostream>
#include <vector>
#include <cstdlib>
#include "ElementListyOtwartej.h"
#include "Macierz.h"
#include <algorithm>
using namespace std;

void astar();
int main()
{
    astar();
    system("pause");
}

void astar()
{
    int x_start = 19;
    int y_start = 0;
    int goal_x = 0;
    int goal_y = 19;
    vector < ElementListyOtwartej > listaOtwarta;
    vector <ElementListyOtwartej> listaZamknieta;
    vector <ElementListyOtwartej> dostepniSasiedzi;

    int gc=1,x=0,y=0;
    double fc=-1.0;

    Macierz mac = Macierz("grid.txt");//utworzenie macierzy przez konstrukor
    mac.setGoal(goal_x, goal_y);//ustawienei celu do macierzy
    mac.Wypisz();
    //dodajemy punkt startowy do listy zamknietej

        listaZamknieta.push_back(ElementListyOtwartej(x_start,y_start,0 ,-1,-1,goal_x,goal_y));


    dostepniSasiedzi = mac.DostepniSasiedzi(listaZamknieta[0].x,listaZamknieta[0].y,gc, listaZamknieta);
    listaOtwarta=dostepniSasiedzi;

    while(listaOtwarta.size()>0)
    {
        //wybieranie elementu listy otwartej o minimanlnym f
        double min_f=listaOtwarta[0].f;
        int indexAkutalnegoELementuListyOtwartej = 0 ;

        //wybranie pola o minimalnym f
        ElementListyOtwartej ElementOMinimalnymF=listaOtwarta[0];//przypisanie do aktualnego elementu o najmniejszym f pierwszego lementu z listy otwartej
        for(int i = 0 ; i < listaOtwarta.size(); i++)
        {
            if(min_f>=listaOtwarta[i].f)
            {
                indexAkutalnegoELementuListyOtwartej = i;
                min_f=listaOtwarta[i].f;
                ElementOMinimalnymF=listaOtwarta[i];//pole o minimalnym f przypiane do elementu sc
            }
        }

        listaOtwarta.erase(listaOtwarta.begin()+indexAkutalnegoELementuListyOtwartej);//usuniêcie z listy otwartej wybranego elemetu
        listaZamknieta.push_back(ElementOMinimalnymF);//dodanie tego elemntu do listy zamknietej

        if(ElementOMinimalnymF.czyJestemCelem())//sprawdzenie czy wybrany punkt jest celem
        {
            cout<<"\ncel osiagniety"<<endl;
            break;
        }

        gc=ElementOMinimalnymF.g+1;//zwiekszenie kosztu o jeden
        dostepniSasiedzi = mac.DostepniSasiedzi(ElementOMinimalnymF.x,ElementOMinimalnymF.y,gc, listaZamknieta);

        //dodanie sasiadow elementu o najmniejszym f do listy otwartej
        for(int i = 0 ; i < dostepniSasiedzi.size(); i++)
        {
            bool czyDodane = false;
            for(int j = 0 ; j< listaOtwarta.size();j++)
            {
                if(listaOtwarta[j]==dostepniSasiedzi[i])//sprawdzenie czy dany element istnieje juz w lisicie otwartej
                   {
                        czyDodane=true;
                        if(listaOtwarta[j].f> dostepniSasiedzi[i].f)//jezeli istnieje to prownanie wartosci f jezeli jest mniejsza to zamiana rodzicow
                        {
                            //listaOtwarta[j].set_rodzicow(dostepniSasiedzi[i].get_rodzic_x(),dostepniSasiedzi[i].get_rodzic_y());
                            listaOtwarta[j].rodzic_x=dostepniSasiedzi[i].rodzic_x;
                            listaOtwarta[j].rodzic_y=dostepniSasiedzi[i].rodzic_y;
                            listaOtwarta[j].f=dostepniSasiedzi[i].f;
                            listaOtwarta[j].g=dostepniSasiedzi[i].g;

                        }
                   }
            }
            if(!czyDodane)//jezeli nie nie ma w liscie zamnknietej to dodanie
            listaOtwarta.push_back(dostepniSasiedzi[i]);
        }
    }

    //cout<<"\ndlugosc sciezki: "<<gc-1<<endl;
    vector<ElementListyOtwartej> listaDrogi;
    mac.reconstruct_path(listaZamknieta, listaZamknieta[listaZamknieta.size()-1],listaDrogi);
}

