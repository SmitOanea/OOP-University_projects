#include<iostream>
#include<fstream>

using namespace std;

///********************************************************************************************************************************************************************************************
///*******************************************Incep clasa Vector*******************************************************************************************************************************
///********************************************************************************************************************************************************************************************


template <typename Tip>
class Vector
{
private:
    int dim;
    Tip *a;
public:

    ///constructori
    Vector()
    {
        dim = 0;
        a = new Tip;
    }
    Vector(const int &sizze)
    {
        dim = sizze;
        a = new Tip[sizze];
        for(int i=0; i<sizze; ++i)
            a[i] = 0;
    }
    Vector(const Vector<Tip> &other)
    {
        dim = other.dim;
        a = new Tip[dim];
        for(int i=0; i<dim; ++i)
            a[i] = other.a[i];
    }


    ///functii
    void free()
    {
        if(dim>0)
        {
            delete a;
            //dim = 0;
        }
    }
    void set_sizze(int sizze)
    {
        dim = sizze;
    }
    void read(std::istream &in)
    {
        int n;
        in>>n;
        set_sizze(n);
        in>>*this;
    }
    void print(std::ostream &out)
    {
        out<<dim<<"\n";
        out<<*this;
    }


    ///operatori
    Tip& operator [](int pos)
    {
        return a[pos];
    }
    Vector<Tip>& operator =(Vector<Tip> &other)
    {
        free();
        dim = other.dim;
        a = new Tip[dim];

        for(int i=0; i<dim; ++i)
            a[i] = other[i];

        return *this;
    }
    bool operator ==(Vector &other)
    {
        if(dim!=other.dim)
            return false;
        int i;
        for(i=0; i<dim; ++i)
            if(a[i]!=other.a[i])
                return false;
        return true;
    }
    bool operator !=(Vector &other)
    {
        return !(*this==other);
    }


    template <typename Tip2>
    friend istream &operator >>(istream &in,Vector<Tip2> &other);
    template <typename Tip2>
    friend ostream &operator <<(ostream &out,Vector<Tip2> &other);



    ///getere
    int lenght()
    {
        return dim;
    }
    Tip* Geta()
    {
        return a;
    }
};

template <typename Tip>
std::istream &operator >>(std::istream &in, Vector<Tip>& other)
{
    other.free();
    other.a = new Tip[other.dim];
    for (int i = 0; i < other.lenght(); ++i)
        in >> other.a[i];
    return in;
}

template <typename Tip>
std::ostream &operator <<(std::ostream &out, Vector<Tip> &other)
{
    for (int i = 0; i < other.lenght(); ++i)
        out << other.a[i]<<" ";
    out<<"\n";
    return out;
}



///********************************************************************************************************************************************************************************************
///*******************************************Incep clasa MatriceOarecare**********************************************************************************************************************
///********************************************************************************************************************************************************************************************

template < typename Tip >
class Matrice
{
protected:
    int lin;
    Vector <Tip> *v;
    void free()
    {
        if (lin > 0)
            delete[] v;
    }

public:
    ///constructori
    Matrice(): lin(0)
    {
        v = new Vector <Tip>;
    }
    Matrice(const int nrlin, const int nrcol) : lin(nrlin)
    {
        v = new Vector<Tip>[nrlin];
        for (int i = 0; i < nrlin; ++i)
            v[i] = Vector<Tip>(sizze);
    }
    Matrice(const Matrice& other)
    {
        lin = other.lin;
        v = new Vector<Tip>[lin];

        for (int i = 0; i < lin; ++i)
        {
            v[i] = other.v[i];
        }
    }



    ///operatori
    Vector<Tip>& operator[] (int pos)
    {
        return v[pos];
    }
    Matrice<Tip>& operator =(const Matrice<Tip> &other)
    {
        free();
        lin = other.lin;
        v = new Vector<Tip>[lin];
        for (int i = 0; i < lin; ++i)
        {
            v[i] = other.v[i];
        }
        return *this;
    }
    bool operator ==(const Matrice<Tip>& other)
    {
        if (lin != other.lin)
            return false;
        for(int i = 0; i < lin; ++i)
            if(!(v[i] == other.v[i]))
                return false;
        return true;
    }
    bool operator!= (const Matrice<Tip>& other)
    {
        if (lin != other.lin)
            return true;
        for(int i = 0; i < lin; ++i)
            if(!(v[i] == other.v[i]))
                return true;
        return false;
    }
    Matrice<Tip> operator +(Matrice<Tip> &other)
    {
        Matrice ans;
        if (sizze() != other.sizze())
        {
            std::cerr << "Eroare! La adunare, matricile trebuie sa aiba aceleasi dimensiuni!\n";
            return ans;
        }

        if (sizze() == 0 && other.sizze() == 0)
            return ans;

        if (v[0].sizze() != other.v[0].sizze())
        {
            std::cerr << "Eroare! La adunare, matricile trebuie sa aiba aceleasi dimensiuni!\n";
            return ans;
        }

        ans.resizze(sizze(), v[0].sizze());

        for (int i = 0; i < lin; ++i)
            for (int j = 0; j < v[i].sizze(); ++j)
                ans[i][j] = v[i][j] + other.v[i][j];

        return ans;
    }

    int sizze()
    {
        return lin;
    }

    void resizze(int new_sizze_vec,int new_sizze_arr)
    {
        Vector<Tip> *new_vec = new Vector<Tip>[new_sizze_vec];

        if (new_sizze_vec < lin)
        {
            lin = new_sizze_vec;
        }

        for (int i = 0; i < lin; i++)
        {
            new_vec[i] = v[i];
        }

        for (int i = 0; i < new_sizze_vec; ++i)
            new_vec[i].resizze(new_sizze_arr);

        free();
        lin = new_sizze_vec;
        v = new_vec;
    }

    void resizze(int new_sizze_vec)
    {
        Vector<Tip> *new_vec = new Vector<Tip>[new_sizze_vec];

        if (new_sizze_vec < lin)
        {
            lin = new_sizze_vec;
        }

        for (int i = 0; i < lin; i++)
        {
            new_vec[i] = v[i];
        }

        free();
        lin = new_sizze_vec;
        v = new_vec;
    }

    void push_back_v(const Vector<Tip>& elem)
    {
        resizze(lin + 1);
        v[lin - 1] = elem;
    }

    ~Matrice()
    {
        free();
    }

    template <typename Tip2>
    friend istream &operator >>(istream &in,Matrice<Tip2> &other);
    template <typename Tip2>
    friend ostream &operator <<(ostream &out,Matrice<Tip2> &other);
};

template <typename Tip>
std::istream &operator >>(std::istream &in, Matrice<Tip>& other)
{
    int nrCol;
    other.free();

    in >> other.lin >> nrCol;
    other.v = new Vector<Tip>[other.lin];

    for (int i = 0; i < other.sizze(); ++i)
    {
        other.v[i].set_sizze(nrCol);
        in >> other.v[i];
    }

    return in;
}

template <typename Tip>
std::ostream &operator <<(std::ostream &out, Matrice<Tip> &other)
{
    out << "Matricea are dimensiunile " << other.sizze() << " x " << (other.sizze() == 0 ? 0 : other[0].lenght()) << "\n";

    if (other.sizze() == 0)
        return out;

    out << "Elementele matricei sunt:\n";
    for (int i = 0; i < other.sizze(); ++i)
    {
        out << other[i];
    }
    return out;
}


///********************************************************************************************************************************************************************************************
///*******************************************Incep clasa MatricePatratica*********************************************************************************************************************
///********************************************************************************************************************************************************************************************
/**template<typename Tip>
class MatricePatratica : public Matrice<Tip>
{
private:

public:
    MatriceOarecare()
    {
        this->lin = 0;
        this->col = 0;
        this->v = new Vector< Tip >;
    }
    MatriceOarecare(int n,int m)
    {
        this->lin = n;
        this->col = m;
        this->v = new Vector< Tip > [this->linlin];
        for(int i=0;i<lin;++i)
        {
             (this->v)[i] = new Vector<Tip>[col];
        }
    }


    ///operatori
    Tip& get_element(int i,int j)
    {
        return (this->v[i])[j];
    }




    ///setere
    void set_elem(int i,int j,int x)
    {
        (this->v[i])[j] = x;
    }
    void set_lin(int n)
    {
        lin = n;
    }
    void set_col(int m)
    {
        col = m;
    }

    ///getere
    int getlin()
    {
        return lin;
    }
    int getcol()
    {
        return col;
    }
}*/



int main()
{
    Matrice<int>M;

    ifstream fin("date.in");
    ofstream fout("date.out");
    cin>>M;
    cout<<M;
    return 0;
}

