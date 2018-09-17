#include "GrupAditiv.h"
#include "GrupMultiplicativ.h"
#include "CorpFinit.h"
#include<iostream>
#include<vector>

using namespace std;

bool AmIntrodusCorpuri = false, PrimaData = true;
bool AmR = false, AmQ = false;
vector<CorpFinit<char> >ListaCorpuriFinite;


class CorpNumereReale
{
private:
    static CorpNumereReale* instance;
protected:
public:
    CorpNumereReale()
    {
    }
    double Aduna(double a, double b)
    {
        return a+b;
    }
    double Inmulteste(double a, double b)
    {
        return a*b;
    }
    static CorpNumereReale* getinstance();
};

CorpNumereReale* CorpNumereReale::instance = 0;

CorpNumereReale* CorpNumereReale::getinstance()
{
    if (instance == 0)
    {
        instance = new CorpNumereReale();
    }

    return instance;
}

class CorpNumereRationale
{
private:
    static CorpNumereRationale* instance;
protected:
public:
    CorpNumereRationale()
    {
    }
    double Aduna(double a, double b)
    {
        return a+b;
    }
    double Inmulteste(double a, double b)
    {
        return a*b;
    }
    static CorpNumereRationale* getinstance();
};

CorpNumereRationale* CorpNumereRationale::instance = 0;

CorpNumereRationale* CorpNumereRationale::getinstance()
{
    if (instance == 0)
    {
        instance = new CorpNumereRationale();
    }

    return instance;
}


void Meniu()
{
    if(!PrimaData)
        cout<<"\n\n\n";
    if(AmIntrodusCorpuri)
    {
        cout<<"Pana acum ati introdus corpurile: ";
        unsigned int ui;
        for(ui=0;ui+1<ListaCorpuriFinite.size();++ui)
            cout<<ListaCorpuriFinite[ui].get_NumeCorp()<<", ";
        if(ui<ListaCorpuriFinite.size())
            cout<<ListaCorpuriFinite[ui].get_NumeCorp()<<" ";
        ///de facut cele infinite
        if(AmQ)
            cout<<"Q ";
        if(AmR)
            cout<<"R ";

        cout<<"\n";

    }
    cout<<"Puteti alege una dinre urmatoarele optiuni:\n\n";

    cout<<"1. Introduceti un corp nou.\n";
    cout<<"2. Efectuati operatii peste un corp deja introdus. ";
    if(!AmIntrodusCorpuri)
        cout<<"(momentan indisponibil)";
    cout<<"\n";

    cout<<"3. Verificati daca doua corpuri sunt izomorfe.\n";

    cout<<"4. Iesire\n";

    cout<<"Optiunea dumneavoastra:";
}

int main()
{
    CorpNumereReale *R = CorpNumereReale::getinstance();
    CorpNumereRationale *Q = CorpNumereRationale::getinstance();
    CorpNumereReale *R2 = CorpNumereReale::getinstance();
    int option;
    unsigned int ui;
    cout<<"Bine ati venit!\n\n";
    while(1)
    {
        Meniu();
        cin>>option;
        cout<<"\n";
        if(option==1)
        {
            int alegere;
            cout<<"Ce fel de corp vreti sa introduceti?\n";
            cout<<"1.Finit\n";
            cout<<"2.Infinit\n";
            cout<<"Optiunea dumneavoastra: ";
            cin>>alegere;
            if(alegere==1)///FINIT
            {
                string nm;
                bool citok=true;

                cout<<"Introduceti numele corpului: ";
                cin>>nm;
                for(ui=0;ui<ListaCorpuriFinite.size() && citok;++ui)
                    if(ListaCorpuriFinite[ui].get_NumeCorp() == nm)
                        citok = false;
                while(citok==false)
                {
                    cout<<"Aveti deja acest nume! Scrieti alt nume: ";
                    cin>>nm;
                }
                CorpFinit<char> K;
                K.set_NumeCorp(nm);
                K.CitireCorp();
                if(K.IntrodusCorect())
                    ListaCorpuriFinite.push_back(K);
                else
                    cout<<"Corp introdus gresit!\n";
            }
            if(alegere==2)///INFINIT
            {
                string nm;
                cout<<"Scrieti numele corpului dorit. (R,Q)\n";
                cin>>nm;
                if(nm=="R")
                    AmR = true;
                if(nm=="Q")
                    AmQ = true;
            }
            AmIntrodusCorpuri = true;
        }
        if(option==2)
        {
            string nm;

            cout<<"Peste ce corp vreti sa efectuati operatiile?\n";
            cin>>nm;
            cout<<"Introduceti o operatie (exp: x + y, 2 * 3, etc.)\n";
            bool finit = true;
            if(nm=="R" || nm=="Q")
                finit = false;

            if(nm=="Q")
            {
                float e1,e2;
                char op;
                cin>>e1>>op>>e2;
                if(op=='+')
                    cout<<e1<<" + "<<e2<<" = "<<Q->Aduna(e1,e2)<<"\n";
                if(op=='*')
                    cout<<e1<<" * "<<e2<<" = "<<Q->Inmulteste(e1,e2)<<"\n";

            }
            if(nm=="R")
            {
                double e1,e2;
                char op;
                cin>>e1>>op>>e2;
                if(op=='+')
                    cout<<e1<<" + "<<e2<<" = "<<R->Aduna(e1,e2)<<"\n";
                if(op=='*')
                    cout<<e1<<" * "<<e2<<" = "<<R->Inmulteste(e1,e2)<<"\n";
            }
            if(finit)
            {
                CorpFinit<char>K;
                for(ui=0;ui<ListaCorpuriFinite.size();++ui)
                    if(ListaCorpuriFinite[ui].get_NumeCorp() == nm)
                    {
                        K = ListaCorpuriFinite[ui];

                        ///cout<<"Cardinalul este: "<<K.get_cardinal()<<"\n";
                        ///K.AfisareTabla();
                        ui = ListaCorpuriFinite.size()+1;
                        char e1,e2,op;
                        cin>>e1>>op>>e2;
                        if(op=='+')
                            cout<<e1<<" + "<<e2<<" = "<<K.Aduna(e1,e2)<<"\n";
                        if(op=='*')
                            cout<<e1<<" * "<<e2<<" = "<<K.Inmulteste(e1,e2)<<"\n";
                    }
            }

        }
        if(option==3)
        {
            string nm1,nm2;
            cout<<"Corp 1: "; cin>>nm1;
            cout<<"Corp 2: "; cin>>nm2;

            CorpFinit<char> K1,K2;
            for(ui=0;ui<ListaCorpuriFinite.size();++ui)
                if(ListaCorpuriFinite[ui].get_NumeCorp() == nm1)
                {
                    K1 = ListaCorpuriFinite[ui];
                    break;
                }
            for(ui=0;ui<ListaCorpuriFinite.size();++ui)
                if(ListaCorpuriFinite[ui].get_NumeCorp() == nm2)
                {
                    K2 = ListaCorpuriFinite[ui];
                    break;
                }
            if(K1==K2)
                cout<<"Da, sunt izomorfe.\n";
            else
                cout<<"Nu,. nu sunt izomorfe.\n";

        }
        if(option==4)///iesire
            return 0;
        PrimaData = false;
    }
    ///Finit k;
    ///k.get_element(3);
    return 0;
}
