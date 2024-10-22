#include <iostream>
#include "nmod.h"
#include "vec.h"

using namespace std;

int main()
{

    unsigned long ar[] = {2123, 3123, 21123, 1123, 1123, 1235, 1232};
    size_t len = 7;
    auto v =  nmod::Vec<13>();
    v.set(ar, len);
    v.print();
    return 0;
}