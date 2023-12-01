#include<iostream>
#include <algorithm>
#include "Spisok.h"
#include "Ochered.h"
#include "Stack.h"

template<class T>
T reverse(T a)
{
    std::vector<int> d = a.data();
    T res;
    int N = d.size();
    for(int i = N-1; i >= 0; i--)
        res.push(d[i]);
    return res;
}

template<>
Spisok reverse<Spisok>(Spisok a)
{
    std::vector<int> d = a.data();
    Spisok res;
    int N = d.size();
    for(int i = 0; i < N; i++)
        res.push(d[i]);
    return res;
}

int main()
{
    Stack S{3, 4, 7};
    S.print();
    Stack S1 = reverse(S);
    S1.print();

    Ochered O{1, 2, 4, 9};
    O.print();
    Ochered O1 = reverse(O);
    O1.print();

    Spisok A{2, 4, 5};
    A.print();
    Spisok A1 = reverse(A);
    A1.print();
};
