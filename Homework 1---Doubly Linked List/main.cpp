#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

/******************************************************************************************/

class ListaDubluInlantuita;

class Nod
{
    public:
        Nod();
        Nod(double);
        Nod(const Nod&);
        ~Nod();
        Nod &operator =(Nod aux);
        bool operator ==(const Nod &aux) const;
        bool operator !=(const Nod &aux) const;
        bool operator <(const Nod &aux) const;


        friend class ListaDubluInlantuita;

        friend ifstream &operator >>(ifstream &in,Nod &nod);
        friend ofstream &operator <<(ofstream &out,const Nod &nod);

        friend ifstream &operator>> (ifstream &,ListaDubluInlantuita&);
        friend ofstream &operator<< (ofstream &,const ListaDubluInlantuita &L);


        ///void
    private:
        double info;
        Nod *next,*prev;
};


class ListaDubluInlantuita
{
    private:
        Nod *p;
        int sz;
    public:
        ListaDubluInlantuita();
        ListaDubluInlantuita(const ListaDubluInlantuita &other);
        int size() const;
        void sterge(int poz);
        void insert(int poz,Nod x);
        double &operator[](int poz);
        ListaDubluInlantuita operator =(const ListaDubluInlantuita aux);
        ListaDubluInlantuita operator -(const ListaDubluInlantuita &A);
        ListaDubluInlantuita operator +(const ListaDubluInlantuita &A);
        //void &operator(int poz);
        friend ifstream &operator >> (ifstream &in,ListaDubluInlantuita &L);
        friend ofstream &operator << (ofstream &out,const ListaDubluInlantuita &L);
};




/**
**********************************************************************************************************************************************
**********************************************************************************************************************************************
*************************************************Urmeaza functiile clasei Nod*****************************************************************
**********************************************************************************************************************************************
**********************************************************************************************************************************************
*/
Nod::Nod()
{
    info = 0;
    next = NULL;
    prev = NULL;
}

Nod::Nod(double p)
{
    info = p;
    next = NULL;
    prev = NULL;
}

Nod::Nod(const Nod& other)
{
    this->info=other.info;
}

Nod::~Nod()
{

}

ifstream &operator >> (ifstream &in,Nod &nod)
{
    in>>nod.info;
    return in;
}


ofstream & operator << (ofstream &out,const Nod &nod)
{
    out<<nod.info<<" ";
    return out;
}

Nod& Nod::operator=(Nod aux)
{
    this->info=aux.info;
    return *this;
}

bool Nod::operator==(const Nod &aux) const
{
    return this->info==aux.info;
}

bool Nod::operator!=(const Nod &aux) const
{
    return this->info != aux.info;
}

bool Nod::operator<(const Nod &aux) const
{
    return this->info < aux.info;
}
/**
**********************************************************************************************************************************************
**********************************************************************************************************************************************
*************************************************Urmeaza functiile clasei ListaDubluInlantuita************************************************
**********************************************************************************************************************************************
**********************************************************************************************************************************************
*/

ListaDubluInlantuita::ListaDubluInlantuita()
{
    p = NULL;
    //p->next = p->prev = NULL;
    sz=0;
}

ListaDubluInlantuita::ListaDubluInlantuita(const ListaDubluInlantuita &other)
{
        p->next = NULL;
        p->prev = NULL;
        p = NULL;
        sz = 0;

        if (other.size() == 0)
        {
            return;
        }

        Nod *ptr = other.p;

        while (ptr != NULL)
        {
            insert(sz,ptr -> info);
            ptr = ptr -> next;
        }
}

double &ListaDubluInlantuita::operator[](int poz)
{
    int i=0;
    Nod *ptr = new Nod();
    i=0;
    ptr = p;
    while(i<poz)
    {
        ptr = ptr->next;
        i++;
    }
    return ptr->info;
}



ListaDubluInlantuita ListaDubluInlantuita::operator =(const ListaDubluInlantuita aux)
{

    while(p!=NULL)
    {
        sterge(0);
    }
    //cout<<sz<<"    asta e marimea\n";

    Nod *ptr;
    p = NULL;
    ptr = aux.p;
    while(ptr!=NULL)
    {
        insert(size(),*ptr);
        ptr=ptr->next;
    }
    sz=aux.sz;
    //return *this;

}

ListaDubluInlantuita ListaDubluInlantuita::operator+(const ListaDubluInlantuita &L)
{
    ListaDubluInlantuita *aux=this;
    Nod *ptr;
    ptr = p;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = L.p;
    L.p->prev = ptr;
    aux->sz = L.sz+sz;

    return *aux;
}


ListaDubluInlantuita ListaDubluInlantuita::operator-(const ListaDubluInlantuita &A)
{
    /**
            123 - 124 = 3
    */
    Nod *ptrA,*ptrInit;
    ptrA = A.p;
    ptrInit = p;
    while(p->info == ptrA->info)
    {
        p = p->next;
        ptrA = ptrA->next;
        if(ptrA==NULL)
        {
            //cout<<""
            break;
        }
        if(p==NULL)
        {
            //cout<<"aici\n";
            break;
        }
    }
    ///cout<<"GATAAA?\n";
    //cout<<"\t\tI="<<i<<"\n";
    //cout<<p->info<<"    astaa\n";
    ListaDubluInlantuita rez;
    rez.p = NULL;
    while(p!=NULL)
    {

        rez.insert(rez.size(),*p);
        p = p->next;
    }



    p = ptrInit;
    return rez;
}

int ListaDubluInlantuita::size() const
{
    return sz;
}

void ListaDubluInlantuita::insert(int poz,Nod x)
{
    if(poz<0 || poz>sz)
        return;
    sz++;///aici maresc size-ul

    int i;
    i=0;
    Nod *ptr,*new_node;
    if(poz==0)
    {
        new_node = new Nod(x);
        if(p==NULL)
        {
            p = new_node;
            return;
        }
        new_node->prev = NULL;
        new_node->next = p;
        p->prev = new_node;


        p = new_node;
        return;
    }

    if(poz < sz-1)///noul size
    {
        i=0;
        ptr = p;
        while(i<poz-1)
        {
            ptr = ptr->next;
            i++;
        }
        new_node = new Nod(x);

        new_node->next = ptr->next;
        new_node->prev = ptr;

        ptr->next = new_node;
        new_node->next->prev = new_node;

        return;
    }
    ///poz==size-1
    i=0;
    ptr = p;
    while(i < poz-1)
    {
        ptr = ptr->next;
        i++;
    }
    new_node = new Nod(x);

    new_node->next = NULL;
    new_node->prev = ptr;

    ptr->next = new_node;
}

void ListaDubluInlantuita::sterge(int poz)
{
    if(poz<0 || poz>sz-1)
        return;
    sz--;///aici scad sz-ul
    int i;
    Nod *ptr;
    if(poz==0)
    {
        if(sz==0)
        {
            delete p;
            p = NULL;
            return;
        }
        p = p->next;
        delete p->prev;
        p->prev = NULL;
        return;
    }

    if(poz < sz)///noul size
    {
        i=0;
        ptr = p;
        while(i<poz-1)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete p;
        return;
    }
    ///poz==size
    i=0;
    ptr = p;
    while(i < poz-1)
    {
        ptr = ptr->next;
        i++;
    }
    delete ptr->next;
    ptr->next = NULL;
}

ifstream & operator >> (ifstream &in,ListaDubluInlantuita &L)
{
    int n;
    in>>n;
    Nod nod;
    for(int i=0;i<n;i++)
    {
        in>>nod;
        L.insert(i,nod);
    }
    return in;
}

ofstream & operator << (ofstream &out,const ListaDubluInlantuita &L)
{
    ///trebuie sa fac alta afisare, fara stergere. pentru ca acum e const
    ///gata, am facut fara stergere
    Nod *ptr=L.p;
    while(ptr!=NULL)
    {
        out<<ptr->info<<" ";
        ptr = ptr->next;
    }

    out<<"\n";
    return out;
}


int main()
{
    ListaDubluInlantuita L1,L2,L3;
    fin>>L1;
    fin>>L2;
    L3=L1 + L2;
    fout<<L3;

    fin.close();
    fout.close();
    return 0;
}
