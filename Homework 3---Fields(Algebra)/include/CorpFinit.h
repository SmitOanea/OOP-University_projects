#include<iostream>
#include "GrupAditiv.h"
#include "GrupMultiplicativ.h"
#ifndef CORPFINIT_H
#define CORPFINIT_H

using namespace std;

template<class T>
class ElementCorpFinit
{
protected:
    T val;
public:
    ElementCorpFinit()
    {
        //val = 0;
    }
protected:
};

template<class T>
class CorpFinit: public GrupMultiplicativ <  T >,public GrupAditiv < T >
{
protected:
    bool PutereDeNumarPrim(int x);
    string NumeCorp;
    bool viz[103];
    int st[103];
    bool izomorf;
public:
    void CitireCorp();
    void AfisareTabla();
    bool Verificare(CorpFinit<T>&);
    bool IntrodusCorect();
    bool operator == (CorpFinit<T> &other);
    void Back(int top, CorpFinit<T> &other);
    //friend ElementCorpFinit;
    ///constructors
    CorpFinit();
    ///geters
    bool get_comutativ()
    {
        return GrupMultiplicativ<T>::get_comutativ();
    }
    string get_NumeCorp()
    {
        return NumeCorp;
    }

    ///seters
    void set_NumeCorp(string s)
    {
        NumeCorp = s;
    }
    //set_comutativ s-a mostenit de la GrupMultiplicativ
protected:

private:
};

#endif // CORP_H
