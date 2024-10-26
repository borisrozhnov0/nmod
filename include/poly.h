#ifndef POLY_H
#define POLY_H

#include "nmod.h"

namespace nmod{
template<ulong N>
class Poly
{
using ulong = unsigned long;
public:
    Poly() = default;
    Poly(size_t len);
    Poly(Poly<N> & other);
    Poly(Poly<N> && other);
    void set(size_t pos, ulong val);
    void print();
    inline void clear();
    inline ulong* data();
    inline size_t size();
    inline size_t size() const;
    inline size_t msize();

    Poly<N>      &operator=(const Poly<N> & other);
    Poly<N>     &&operator=(Poly<N> && other); 
    inline ulong &operator[](size_t pos);
    inline ulong  operator[](size_t pos) const;
    ulong         operator()(long x);
    
    static Poly<N> mul(const Poly<N> & p, ulong l);
    static Poly<N> mul(const Poly<N> & first, const Poly<N> & second);
    static Poly<N> add(const Poly<N> & p, ulong l);
    static Poly<N> add(const Poly<N> & first, const  Poly<N> & second);
    static Poly<N> sub(const Poly<N> & p, ulong l);
    static Poly<N> sub(const Poly<N> & first, const  Poly<N> & second);
    static Poly<N> shiftRight(const Poly<N> & p, size_t pos);
    static Poly<N> shiftLeft (const Poly<N> & p, size_t pos);

protected:
    inline void init(size_t size);
    inline void copy(ulong * dst, const ulong * src, size_t len);
    inline size_t alig(size_t size);
private:
    size_t _size  = 0,
           _msize = 0;
    ulong * _val = nullptr;
};

} // namespace nmod

#include "../source/nmod/poly.cc.inc"
#endif //POLY_H