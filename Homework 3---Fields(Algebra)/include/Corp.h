#include "GrupAditiv.h"
#include "GrupMultiplicativ.h"
#ifndef CORP_H
#define CORP_H


class Corp: public GrupAditiv, public GrupMultiplicativ
{
public:
    ///constructors
    Corp();
    ///geters
    bool get_comutativ()
    {
        return GrupMultiplicativ::get_comutativ();
    }

    ///seters
    //set_comutativ s-a mostenit de la GrupMultiplicativ
protected:

private:
};

#endif // CORP_H
