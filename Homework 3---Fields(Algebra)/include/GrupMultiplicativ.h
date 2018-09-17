#include "iostream"
#include "Multime.h"
#ifndef GRUPMULTIPLICATIV_H
#define GRUPMULTIPLICATIV_H

using namespace std;

template<typename T>
class GrupMultiplicativ: virtual public Multime<T>
{
protected:
    bool comutativ;
    T tabla_inmultirii[103][103];
public:
    ///constructors
    GrupMultiplicativ();

    T Inmulteste(T &a,T &b)
    {
        int poza=-1, pozb=-1,i;
        for(i=1;i<=this->cardinal;++i)
            if(this->elemente[i]==a)
            {
                poza = i;
                break;
            }
        for(i=1;i<=this->cardinal;++i)
            if(this->elemente[i]==b)
            {
                pozb = i;
                break;
            }
        if(poza==-1 || pozb ==-1)
        {
            cout<<"Valori gresite!\n";
            return a;
        }
        return tabla_inmultirii[poza][pozb];
    }

    ///geters
    bool get_comutativ()
    {
        return comutativ;
    }

    ///seters
    void set_comutativ(bool val)
    {
        comutativ = val;
    }
protected:
};

#endif // GRUPMULTIPLICATIV_H
