#include<iostream>

using namespace std;

bool PutereDeNumarPrim(int x)
{
    int p;
    for(p=2;p*p<=x;++p)
    {
        while(x%p==0)//am gasit un divizor
            x/=p;
        return x==1;
    }
    //std::cout<<"ERROR in CorpFinit::PutereDeNumarPrim\n";
    return true;
}

