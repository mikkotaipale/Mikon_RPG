#pragma once
#include <vector>
//dynaaminen taulukko, tietojen tallennusta varten.

template<typename T>
class dArr
{
private:
    unsigned cap;
    unsigned initCap;
    unsigned nrOfEl;
    T* *arr;

    void laajennus();
    void initialize(unsigned from);

public:
    dArr(unsigned size = 5);
    dArr(const dArr& obj);
    ~dArr();

    T& operator[] (const unsigned index);
    void operator = (const dArr& obj);

    unsigned maxCap();
    unsigned size();
    void push(const T element);
    void remove(const unsigned index, bool ordered = false);
};

template<typename T>
dArr<T>::dArr(unsigned size)
{
    this->initCap = size;
    this->cap = size;
    this->nrOfEl = 0;

    this->arr = new T*[this->cap];

    this->initialize(0);
}

template<typename T>
dArr<T>::dArr(const dArr& obj)
{
    this->initCap = obj.initCap;
    this->cap = obj.cap;
    this->nrOfEl = obj.nrOfEl;

    this->arr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; i++)
    {
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}

template<typename T>
dArr<T>::~dArr()
{
    for (size_t i = 0; i < this->nrOfEl; i++)
    {
        delete this->arr[i];
    }
    delete[] arr;
}

template<typename T>
T& dArr<T>::operator[] (const unsigned index)
{
    if (index < 0 || index >= this->nrOfEl)
        throw"Out of bound indexing operator.";

    return *this->arr[index];
}

template<typename T>
void dArr<T>::operator= (const dArr& obj)
{
    for (size_t i = 0; i < this->nrOfEl; i++)
    {
        delete this->arr[i];
    }
    delete[] arr;

    this->initCap = obj.initCap;
    this->cap = obj.cap;
    this->nrOfEl = obj.nrOfEl;

    this->arr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; i++)
    {
        this->arr[i] = new T(*obj.arr[i]);
    }

    this->initialize(0);
}

template<typename T>
void dArr<T>::laajennus()
{
    this->cap *= 2;

    T* *tempArr = new T*[this->cap];

    for (size_t i = 0; i < this->nrOfEl; i++)
    {
        tempArr[i] = this->arr[i];
    }

    delete[]arr;

    this->arr = tempArr;

    this->initialize(this->nrOfEl);
}

template<typename T>
void dArr<T>::initialize(unsigned from)
{
    for (size_t i = from; i < this->cap; i++)
    {
        this->arr[i] = nullptr;
    }
}

template<typename T>
unsigned dArr<T>::maxCap()
{
    return this->cap;

}

template<typename T>
unsigned dArr<T>::size()
{
    return this->nrOfEl;
}

template<typename T>
void dArr<T>::push(const T element)
{
    if (this->nrOfEl >= this->cap)
        this->laajennus();

    this->arr[this->nrOfEl++] = new T(element);


}

template<typename T>
void dArr<T>::remove(const unsigned index, bool ordered)
{
    if(index < 0 || index >= this->nrOfEl)
        throw "Out of bounds remove.";

    if(ordered)
    {
        delete this->arr[index];

        for (size_t i = 0; i < nrOfEl-1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }

        this->arr[--this->nrOfEl] = nullptr;

    }
    else
    {
        delete this->arr[index];

        this->arr[index] = this->arr[this->nrOfEl - 1];
        this->arr[--this->nrOfEl] = nullptr;
    }
}
