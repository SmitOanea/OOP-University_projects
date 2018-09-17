#ifndef MULTIME_H
#define MULTIME_H

template<class T>
class Multime
{
protected:
    int cardinal;
    T elemente[103];//dinamic. template
public:
    void CitireMultime(int lim_cardinal);
    int pozitia_in_multime(T elem);
    ///constructors
    Multime();

    ///geters
    int get_cardinal();
    T get_element(int poz)
    {
        return elemente[poz];
    }

    ///seters
    void set_cardinal(int val);
    void set_element(int i,T val)
    {
        elemente[i] = val;
    }

protected:
};

#endif // MULTIME_H
