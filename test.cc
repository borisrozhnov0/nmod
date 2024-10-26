#include <iostream>
#include <cstdlib>
#include <cstring>
#include "poly.h"

using namespace std;
int main()
{
    nmod::Poly<5> p;
    p.set(1,53);
    p.set(3,12);
    p.print(); cout << endl;
    auto c = nmod::Poly<5>::mul(p, p);
    auto b = nmod::Poly<5>::shiftLeft(p, 1);
    b.print(); cout << endl;
    c.print(); cout << endl;
    cout <<"\n" << b(323) << endl;
    return 0;
}