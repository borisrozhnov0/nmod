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

    void zero(size_t len);
    void set(ulong ar[], size_t len)
    {
        if(_ar){ delete[] _ar; }
        _ar = new ulong[len];
        _len = len;
        _ar = (ulong*)std::memcpy(_ar, ar, sizeof(ulong) * len);
        setMod();
    }

    void zero()
    {
        for(size_t i = 0;  i != _len; i++){
            _ar[i] = 0;
        }
    }
    static inline Vec init(size_t len)
    {
        return Vec(new ulong[len], len);
    }

    static void swap(Vec & first, Vec & second)
    {
        size_t tmp = first._len;
        ulong * pt = first._ar;
        first._len = second._len;
        first._ar  = second._ar;
        second._len = tmp;
        second._ar =  pt;
    }
    void print();
protected:
    void setMod()
    {
        for(size_t i = 0; i != _len; i++){ _ar[i] = nmod::Nmod<N>::init(_ar[i]); }
    }
    Vec(ulong ar[], size_t len):_ar(ar), _len(len){ }
private:
    ulong * _ar = nullptr;
    size_t _len = 0;

};

}

#include "../source/nmod/vec.cc.inc"
#endif //VEC_H