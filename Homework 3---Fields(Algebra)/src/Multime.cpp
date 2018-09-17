#include <iostream>
#include "Multime.h"

template<typename T>
Multime<T>::Multime()
{
    cardinal=0;
}

template<typename T>
void Multime<T>::CitireMultime(int lim_cardinal)
{
    int dim;
    std::cout<<"Introduceti cardinalul multimii: ";
    std::cin>>dim;
    while(dim<lim_cardinal)
    {
        std::cout<<"Valoare gresita! Cardinalul trebuie sa fie cel putin "<<lim_cardinal<<"!\n";
        std::cin>>dim;
    }
    set_cardinal(dim);

    std::cout<<"Acum introduceti, pe rand elementele multimii: ";
    int i;
    for(i=1;i<=cardinal;++i)
    {
        std::cin>>elemente[i];
    }
}


template <class T>
void Multime<T>::set_cardinal(int val)
{
    cardinal = val;
}

template <class T>
int Multime<T>::get_cardinal()
{
    return cardinal;
}

template <class T>
int Multime<T>::pozitia_in_multime(T elem)
{
    int i;
    for(i=1;i<=cardinal;++i)
        if(elemente[i]==elem)
            return i;
    std::cout<<"Elementul "<< elem<<" nu exista in multime!\n";
    return 0;

}

template class Multime<int>;
template class Multime<char>;
