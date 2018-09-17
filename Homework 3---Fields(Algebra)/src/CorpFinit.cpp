#include "iostream"
#include "CorpFinit.h"

template<class T>
CorpFinit<T>::CorpFinit()
{
    int i;
    for(i=1;i<=102;++i)
        viz[i] = false;
}

template<typename T>
void CorpFinit<T>::CitireCorp()
{
    cout<<"cardinalul multimii: ";
    int dim; cin>>dim;
    while(dim<2 || !PutereDeNumarPrim(dim))
    {
        cout<<"Valoare gresita! Cardinalul trebuie sa fie o putere de numar prim!";
        cin>>dim;
    }
    this->set_cardinal(dim);
    cout<<"Introduceti pe rand elementele corpului: ";
    int i,j;
    for(i=1;i<=this->cardinal;++i)
        cin>>this->elemente[i];
    T x;
    cout<<"Introduceti tabla adunarii:\n";
    for(i=1;i<= (this->cardinal);++i)
        for(j=1;j<=i;++j)
        {
            cout<<this->elemente[i]<<" + "<<this->elemente[j]<<" = ";
            cin>>x;
            this->tabla_adunarii[i][j] = this->tabla_adunarii[j][i] = x;
        }

    cout<<"Introduceti tabla inmultirii:\n";
    for(i=1;i<=this->cardinal;++i)
        for(j=1;j<=this->cardinal;++j)
        {
            cout<<this->elemente[i]<<" * "<<this->elemente[j]<<" = ";
            cin>>this->tabla_inmultirii[i][j];
        }
}

template<class T>
bool CorpFinit<T>::Verificare(CorpFinit<T> &other)
{
    int i,j;
    /**cout<<"tablele:\n";
    for(i=1;i<=this->cardinal;++i)
    {
        for(j=1;j<=this->cardinal;++j)
            cout<<this->tabla_adunarii[i][j]<<" ";
        cout<<"\n";
    }

    for(i=1;i<=other.cardinal;++i)
    {
        for(j=1;j<=other.cardinal;++j)
            cout<<other.tabla_adunarii[i][j]<<" ";
        cout<<"\n";
    }*/

    //for(i=1;i<=this->cardinal;++i)
        //coresp[st[i]] = i;

    /*cout<<"Permutarea:\n";
    for(i=1;i<=this->cardinal;++i)
        cout<<st[i]<<" ";
    cout<<"\n";*/
    ///matricea adunarii
    for(i=1;i<=this->cardinal;++i)
    {
        for(j=1;j<=this->cardinal;++j)
        {
            if(this->pozitia_in_multime(this->tabla_adunarii[i][j]) !=
               other.pozitia_in_multime(other.tabla_adunarii[st[i]][st[j]] ) )
            {

                return false;
            }
        }
    }


    ///matricea inmultirii
    for(i=1;i<=this->cardinal;++i)
    {
        for(j=1;j<=this->cardinal;++j)
        {
            if(this->pozitia_in_multime(this->tabla_inmultirii[i][j]) !=
               other.pozitia_in_multime(other.tabla_inmultirii[st[i]][st[j]] ) )
            {

                return false;
            }
        }
    }

    return true;
}

template<class T>
void CorpFinit<T>::Back(int top,CorpFinit<T> &other)
{
    if(top==this->cardinal+1)
    {
        if(Verificare(other))
            izomorf = true;
    }
    else
    {
        int i;
        for(i=1;i<=this->cardinal;++i)
            if(!viz[i])
            {
                st[top] = i;
                viz[i] = true;
                Back(top+1,other);
                viz[i] = false;
            }
    }
}

template<class T>
bool CorpFinit<T>::operator == (CorpFinit<T> &other)
{
    if(other.cardinal!=(this->cardinal))
        return false;
    izomorf = false;
    Back(1,other);
    return izomorf;
}

template<typename T>
void CorpFinit<T>::AfisareTabla()
{
    int i,j;
    cout<<"Afisare tabla adunarii:\n";
    for(i=1;i<= (this->cardinal);++i)
        for(j=1;j<=this->cardinal;++j)
        {
            cout<<this->elemente[i]<<" + "<<this->elemente[j]<<" = ";
            cout<<this->tabla_adunarii[i][j]<<"\n";
        }

    cout<<"Afisare tabla inmultirii:\n";
    for(i=1;i<=this->cardinal;++i)
        for(j=1;j<=this->cardinal;++j)
        {
            cout<<this->elemente[i]<<" * "<<this->elemente[j]<<" = ";
            cout<<this->tabla_inmultirii[i][j]<<"\n";
        }
}

template<typename T>
bool CorpFinit<T>::PutereDeNumarPrim(int x)
{
    int p;
    if(x==2 || x==3)
        return true;
    for(p=2;p*p<=x;++p)
    {
        while(x%p==0)//am gasit un divizor
            x/=p;
        return x==1;
    }
    cout<<"ERROR in CorpFinit::PutereDeNumarPrim\n";
    return true;
}

template<typename T>
bool CorpFinit<T>::IntrodusCorect()
{
    ///distributivitate
    //int i,j,k;
    /*for(i=1;i<=this->cardinal;++i)
        for(j=1;j<=this->cardinal;++j)
            for(k=1;k<=this->cardinal;++k)
            {
                if(this->Inmulteste(this->get_element(i)    ,    this->Aduna(this->get_element(j),this->get_element(k)) )
                   != this->Inmulteste(this->Aduna(this->get_element(i),this->get_element(j))  ,  this->get_element(k)  ))
                    return false;
            }*/
    return true;
}


template class CorpFinit<int>;
template class CorpFinit<char>;
