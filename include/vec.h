#ifndef VEC_H
#define VEC_H

#include "nmod.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace nmod{

template<size_t N>
class Vec
{
public:
    Vec() { }
    ~Vec()
    {
       if(_ar) delete[] _ar;
    }
    
    void zero();
    void zero(size_t len);
    void set(ulong ar[], size_t len);
    static inline Vec init(size_t len);
    static void swap(Vec & first, Vec & second);
    void print();
    
protected:
    void setMod();
    Vec(ulong ar[], size_t len);
private:
    ulong * _ar = nullptr;
    size_t _len = 0;

};

}

#include "../source/nmod/vec.cc.inc"
#endif //VEC_H