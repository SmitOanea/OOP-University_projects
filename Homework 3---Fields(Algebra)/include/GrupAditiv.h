#include "iostream"
#include "Multime.h"
///#include "ElementGrupAditiv.h"
#ifndef GRUPADITIV_H
#define GRUPADITIV_H

using namespace std;

template<class T>
class GrupAditiv : virtual public Multime<T>
{
protected:
    bool comutativ;
    T tabla_adunarii[103][103];
public:
    ///constructors
    GrupAditiv();

    ///member functions
    /**int Aduna(ElementGrupAditiv &a,ElementGrupAditiv &b)
    {
        return tabla_adunarii[a.pozitie_in_multime][b.pozitie_in_multime];
    }*/
    T Aduna(T &a,T &b)
    {
        int poza=-1, pozb=-10,i;
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
        if(poza+pozb==-11)
            cout<<"Valori gresite!\n";
        return tabla_adunarii[poza][pozb];
    }

    ///geters
    bool get_comutativ()
    {
        return comutativ;
    }
    /*int get_element(int poz)
    {
        return elemente[poz];
    }*/
    /**int get_element(int poz)
    {
        return elemente[poz];
    }**/
    ///seters
    void set_adunare(int i,int j,int rez)
    {
        tabla_adunarii[i][j] = rez;
        tabla_adunarii[j][i] = rez;
    }

};

#endif // GRUPADITIV_H
