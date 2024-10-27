#ifndef NMOD_H
#define NMOD_H
#include <cstdlib>

namespace nmod
{
using ulong  = unsigned long;
using slong  = signed long;
using sllong = signed long long;

template<ulong N> 
class Nmod                                                                      //FIXME sllong value
{                                                                               //STYLE add desc. to nmod.cc
public:
    Nmod()=default;
    Nmod(slong val):_val(init(val)){ };
    ~Nmod()=default;

    Nmod &operator+=(Nmod other)
    {  
        _val = (ulong)(((sllong)this->_val + other._val) % N);
        return *this;
    }
    Nmod &operator-=(Nmod other)
    {  
        _val = (ulong)(((sllong)this->_val - (sllong)other._val) % (sllong)N 
             + (this->_val < other._val ? N : 0));
        return *this;
    }
    Nmod &operator*=(Nmod other)
    {  
        _val = (ulong)(((sllong)_val * other._val) % N);
        return *this;
    }
    Nmod &operator/=(Nmod other)
    {  
        _val = (ulong)(((sllong)_val * inv(other._val)) % N);
        return *this;
    }

    Nmod operator+(Nmod other)
    {  
        Nmod ret;
        ret._val = (ulong)(((sllong)this->_val + other._val) % N);
        return ret;
    }
    Nmod operator-(Nmod other)
    {  
        Nmod ret;
        ret._val = (ulong)(((sllong)this->_val - (sllong)other._val) % (sllong)N 
                 + (this->_val < other._val ? N : 0));
        return ret;
    }
    Nmod operator*(Nmod other)
    {  
        Nmod ret;
        ret._val = (ulong)(((sllong)this->_val * other._val) % N);
        return ret;
    }
    Nmod operator/(Nmod other)
    {  
        Nmod ret;
        ret._val = (ulong)(((sllong)this->_val * inv(other._val)) % N);
        return ret;
    }

    static inline ulong init(slong value);
    static inline ulong add(slong first, slong second);
    static inline ulong sub(slong first, slong second);
    static inline ulong mul(slong first, slong second);
    static inline ulong div(slong first, slong second);
    static inline ulong pow(slong value, ulong exp);
    static inline ulong inv(nmod::slong val);
    static inline bool  divides(slong first, slong res, slong second);
private:
    ulong _val;

    friend std::ostream &operator<<(std::ostream & os, Nmod n)
    { 
        return os<<n._val;
    }
};
} // namespace nmod
#include "../source/nmod/nmod.cc.inc"

#ifdef __HIP__
namespace gpunmod
{
using ulong  = unsigned long;
using slong  = signed long;
using sllong = signed long long;

template<size_t N>  //FIXME replace size_t to ulong
class Nmod
{
public:
    static inline __device__ ulong init(nmod::slong value);
    static inline __device__ ulong add(slong first, slong second);
    static inline __device__ ulong sub(slong first, slong second);
    static inline __device__ ulong mul(slong first, slong second);
    static inline __device__ ulong div(slong first, slong second);
    static inline __device__ ulong pow(slong value, ulong exp);
    static inline __device__ ulong inv(nmod::slong val);
    static inline bool __device__ divides(slong first, slong res, slong second);
};
} // namespace nmod
#include "../source/gpunmod/nmod.cu.inc"
#endif // __HIP__
#endif //NMOD_H
