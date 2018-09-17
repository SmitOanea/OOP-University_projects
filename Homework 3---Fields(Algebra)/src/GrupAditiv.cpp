#include "GrupAditiv.h"

template<class T>
class ElementGrupAditiv
{
    ///friend class GrupAditiv;
protected:
    T val;
    int pozitie_in_multime;
public:
    ElementGrupAditiv()
    {
        pozitie_in_multime = 0;
    }
};


template<typename T>
GrupAditiv<T>::GrupAditiv() : comutativ(true)
{
    //ctor
}

template class GrupAditiv<int>;
template class GrupAditiv<char>;
