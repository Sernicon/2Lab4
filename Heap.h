#pragma once
#include <iostream>
using namespace std;

    template<class T>
    class Heap
    {
    private:
        T *h;
        int HeapSize;
    public:
        Heap();
        Heap(int HeapSize);
        Heap(Heap& c);
        ~Heap();
        Heap& operator=(const Heap& c);
        void insert(T n);
        void del(int n);
        void heapify(int i);
        void clear();
        bool isContains(T n);
        bool isEmpty();
        void print();
    };
    template<class T>
    Heap<T>::Heap()
    {
        HeapSize = 0;
        h = new T[0];
    }
    template<class T>
    Heap<T>::Heap(int HeapSize)
    {
        this->HeapSize = HeapSize;
        h = new T[HeapSize];
        for (int i = 0; i < HeapSize; i++)
            h[i] = 0;
    }
    template<class T>
    Heap<T>::Heap(Heap& c)
    {
        HeapSize = c.HeapSize;
        h = new T[HeapSize];
        for (int i = 0; i < HeapSize; i++)
            h[i] = c.h[i];
    }
    template<class T>
    Heap<T>::~Heap()
    {
        if (HeapSize > 0)
        {
            delete[] h;
            cout << "Heap memory has been cleared\n" << endl;
        }
    }
    template<class T>
    Heap<T>& Heap<T>::operator=(const Heap &c)
    {
        delete[] h;
        HeapSize = c.HeapSize;
        h = new T[HeapSize];
        for(int i = 0; i < HeapSize; i++)
            h[i] = c.h[i];
        return *this;
    }
    template<class T>
    void Heap<T>::insert(T n)
    {
        T *ph;
        ph = new T[HeapSize];
        for (int i = 0; i < HeapSize; i++)
            ph[i] = h[i];
        delete[] h;
        HeapSize++;
        h = new T[HeapSize];
        for (int i = 1; i < HeapSize; i++)
            h[i] = ph[i-1];
        h[0] = n;
        heapify(0);
    }
    template<class T>
    void Heap<T>::del(int n)
    {
        T *ph;
        HeapSize--;
        ph = new T[HeapSize];
        h[n] = 0;
        heapify(n);
        for (int i = 0; i < HeapSize; i++)
            ph[i] = h[i];
        delete[] h;
        h = new T[HeapSize];
        for (int i = 0; i < HeapSize; i++)
            h[i] = ph[i];
        delete[] ph;
    }
    template<class T>
    void Heap<T>::heapify(int i) 
    {
        int left, right;
        int temp;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < HeapSize) {
            if (h[i] < h[left]) {
                temp = h[i];
                h[i] = h[left];
                h[left] = temp;
                heapify(left);
            }
        }
        if (right < HeapSize) {
            if (h[i] < h[right]) {
                temp = h[i];
                h[i] = h[right];
                h[right] = temp;
                heapify(right);
            }
        }
    }
    template<class T>
    void Heap<T>::clear()
    {
        HeapSize = 0;
        delete[] h;
    }
    template<class T>
    bool Heap<T>::isContains(T n)
    {
        for (int i = 0; i < HeapSize; i++)
            if (h[i] == n)
                return true;
        return false;
    }
    template<class T>
    bool Heap<T>::isEmpty()
    {
        if (HeapSize == 0)
            return true;
        return false;
    }
    template<class T>
    void Heap<T>::print()
    {
        if (HeapSize == 0)
        {
            cout << "Heap is empty\n" << endl;
        }
        else 
        {
            cout << "Heap elements:" << endl;
            for (int i = 0; i < HeapSize; i++)
                cout << " " << i+1 << ") " << h[i] << endl;
            cout << endl;
        }
    }

