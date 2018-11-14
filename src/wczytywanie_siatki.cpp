#include <iostream>
#include <fstream>

using namespace std;

int main (void) {

int **mapa; //siatka, adresowanie (y, x)
const int mapa_wymiar_x = 20; //siatka rozmiar x
const int mapa_wymiar_y = 20; //siatka rozmiar y

string mapa_nazwa_pliku = "grid.txt";


//teraz deklarujemy dynamicznie tablice, do której wczytamy nasz plik
mapa = new int*[mapa_wymiar_y];
for (int y=0; y < mapa_wymiar_y; y++)
  mapa[y] = new int[mapa_wymiar_x];

cout<<"Wczytywanie danych z pliku "<< mapa_nazwa_pliku << endl;

std::ifstream plik(mapa_nazwa_pliku.c_str());
  
for (int y = mapa_wymiar_y-1; y>=0; y--) //od gory do dolu, pierwszy wiersz w pliku ma y=19   
{
  for (int x = 0; x < mapa_wymiar_x; x++) 
  {
  	plik >> mapa[y][x];
  }
}  
plik.close();

cout<<"\nWypisujemy na ekran\n\n";
for (int y = mapa_wymiar_y-1; y>=0; y--) //gorny wiersz ma y=19  
{
  for (int x = 0; x < mapa_wymiar_x; x++) 
  {
    cout << mapa[y][x]<< " ";
  }
  cout << "\n";
}   
   
//na koniec programu czyscimy pamiec po naszej tablicy
for(int y=0; y<mapa_wymiar_y; y++)
  delete[] mapa[y]; //usuwamy wiersze
delete[] mapa;//zwalniamy tablice wskaznikow do wierszy
mapa = 0;

cout<<"\n\nWpisz cokolwiek i enter, aby zakonczyc";
char ch_tmp;
cin >> ch_tmp;

return 0;
}
