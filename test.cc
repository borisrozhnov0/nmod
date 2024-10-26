#include <iostream>
#include <cstdlib>
#include <cstring>
#include "poly.h"

using namespace std;
int main()
{
    nmod::Poly<5> p;
    p.set(1,1);
    p.set(3,2);
    p.print(); cout << endl;
    auto b = nmod::Poly<5>::shiftLeft(p, 1);
    b.print(); cout << endl;

    cout <<"\n" << b(3) << endl;
    return 0;
}