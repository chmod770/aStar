#include<iostream>
#include <cmath>
#include "ElementListyOtwartej.h"

ElementListyOtwartej::ElementListyOtwartej(int x,int y,int g,int rodzic_x,int rodzic_y,int cel_x,int cel_y)
{
    this->x=x;
    this->y=y;
    this->g=g;
    this->rodzic_x=rodzic_x;
    this->rodzic_y=rodzic_y;
    this->h=sqrt(((x-cel_x)*(x-cel_x)+(y-cel_y)*(y-cel_y)));
    this->cel_x=cel_x;
    this->cel_y=cel_y;
    this->f = this->g + this->h;
}

void ElementListyOtwartej::Wypisz(void)
{
    std::cout<<"\npole:x:"<<x<<", y:"<<y<<"\ng:"<<g<<"\nrodzic_x:"<<rodzic_x<<"\nrodzic_y:"<<rodzic_y<<"\nh:"<<h<<"\nf: "<<f<<'\n';
}

