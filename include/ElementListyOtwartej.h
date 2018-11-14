#ifndef ELEMENTLISTYOTWARTEJ_H
#define ELEMENTLISTYOTWARTEJ_H
#include<iostream>
#include <cmath>
#include "ElementListyOtwartej.h"

class ElementListyOtwartej
{
    public:
        ElementListyOtwartej(int x,int y,int g,int rodzic_x,int rodzic_y,int cel_x,int cel_y);
        void Wypisz();
        int x;
        int y;
        int g;
        int rodzic_x;
        int rodzic_y;
        double h;
        int cel_x;
        int cel_y;
        double f;
        bool czyJestemCelem()
        {
            if(this->x == this->cel_x && this->y==cel_y)
                return true;
            return false;
        }
};

#endif // ELEMENTLISTYOTWARTEJ_H

