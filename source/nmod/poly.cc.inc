#include "poly.h"
namespace nmod{

template<ulong N> 
inline void Poly<N>::copy(ulong *dst, const ulong *src, size_t len)
{
    memcpy(dst, src, len * sizeof(ulong));
}

template<ulong N>  
inline size_t Poly<N>::alig(size_t size)
{
    return size + 16 - (size % 16);
}

template<ulong N>  
inline size_t Poly<N>::size()
{
    return _size;
}

template<ulong N>  
inline size_t Poly<N>::size() const
{
    return _size;
}

template<ulong N> 
void Poly<N>::init(size_t size)
{
    size = alig(size);
    _val = new ulong[size];
    _msize = size;
}

template<ulong N> 
void Poly<N>::clear()
{
    if(_val){ delete[] _val; }
    _val = nullptr;
    _size = 0;
    _msize = 0;
}

template<ulong N>  
inline ulong * Poly<N>::data()
{
    return _val;
}

template<ulong N> 
void Poly<N>::set(size_t pos, ulong val)
{
    if(pos >= _msize){
        size_t msize = alig(pos);
        ulong * pt = new ulong[msize];
        for(size_t i = 0u; i < _msize; i++){ pt[i] = _val[i]; }
        for(size_t i = _msize; i < msize; i++){ pt[0] = 0ul; }
        _msize = msize;
        if(_val){ delete[] _val; }
        _val = pt;
    }
    _size = (pos + 1) > _size ? pos + 1 : _size;
    _val[pos] = Nmod<N>::init(val);
}

template<ulong N> 
void Poly<N>::print()
{
    std::cout << N << " " << _size << " ";
    for(size_t i = 0u; i != _size; i++){ std::cout << " " << _val[i]; }
}

template<ulong N> 
Poly<N>::Poly(size_t len)
{
    init(len);
    for(size_t i = 0u; i != _msize; i++){ _val[i] = 0ul; }
}

template<ulong N> 
inline unsigned long &Poly<N>::operator[](size_t pos)
{
    return _val[pos];
}

template<ulong N> 
inline unsigned long Poly<N>::operator[](size_t pos) const
{
    return _val[pos];
}


template<ulong N> 
unsigned long Poly<N>::operator()(long x)
{
    if(!_size) return 0;
    if(_size == 1) return _val[0];
    ulong mlt = 1ul;
    ulong ret = _val[0];
    for(size_t i = 1; i != _size; i++){
        mlt = Nmod<N>::mul(mlt, x);
        ret = Nmod<N>::add(ret, Nmod<N>::mul(_val[i], mlt));
    }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::mul(const Poly<N> &p, ulong l)
{
    Poly<N> ret(p.size());
    ret._size = p.size();
    for(size_t i = 0u; i != p.size(); i++){ ret[i] = Nmod<N>::mul(p[i], l); }
    for(size_t i = p.size(); i < ret.size(); i++) {ret[i] = 0ul; }
    for(long i = p.size()-1; i != -1; i--){ if(ret[i]){ break; } else { ret._size--; } }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::mul(const Poly<N> &first, const Poly<N> &second)
{
    Poly<N> ret(first.size() + second.size() - 1);
    ret._size = first.size() + second.size() - 1;
    for(size_t i = 0; i < ret.size(); i++) { ret[i] = 0ul; }
    for(size_t i = 0u; i != first.size(); i++){ 
        for(size_t j = 0u; j != second.size(); j++) { 
            ret[i+j] = Nmod<N>::add(ret[i+j], Nmod<N>::mul(first[i], second[j])); 
        }
    }
    for(long i = ret.size()-1; i != -1; i--){ 
        if(ret[i]){ break; } else { ret._size--; } 
    }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::add(const Poly<N> &p, ulong l)
{
    Poly<N> ret(p.size());
    ret._size = p.size();
    for(size_t i = 0u; i != p.size(); i++){ ret[i] = Nmod<N>::add(p[i], l); }
    for(size_t i = p.size(); i < ret.size(); i++) {ret[i] = 0ul; }
    for(long i = p.size()-1; i != -1; i--){ if(ret[i]){ break; } else { ret._size--; } }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::add(const Poly<N> &first, const Poly<N> &second)
{
    size_t min, max;
    ulong * pt;
    if(first.size() > second.size()){
        min = second.size();
        max = first.size();
        pt = first.data();
    }
    else{
        max = second.size();
        min = first.size();
        pt = second.data();
    }
    Poly<N> ret(max);
    ret._size = max;    
    for(size_t i = 0u; i != min; i++) { ret[i] = Nmod<N>::add(first[i], second[i]); }
    for(size_t i = min; i != max; i++){ ret[i] = pt[i]; }
    for(long i = ret.size()-1; i != -1; i--){ 
        if(ret[i]){ break; } else { ret._size--; } 
    }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::sub(const Poly<N> &p, ulong l)
{
    Poly<N> ret(p.size());
    ret._size = p.size();
    for(size_t i = 0u; i != p.size(); i++){ ret[i] = Nmod<N>::sub(p[i], l); }
    for(size_t i = p.size(); i < ret.size(); i++) { ret[i] = 0ul; }
    for(long i = p.size()-1; i != -1; i--){ if(ret[i]){ break; } else { ret._size--; } }
    return ret;
}

template<ulong N> 
Poly<N> Poly<N>::sub(const Poly<N> &first, const Poly<N> &second)
{
    size_t min, max;
    ulong * pt;
    if(first.size() > second.size()){
        min = second.size();
        max = first.size();
        pt = first.data();
    }
    else{
        max = second.size();
        min = first.size();
        pt = second.data();
    }
    Poly<N> ret(max);
    ret._size = max;    
    for(size_t i = 0u; i != min; i++) { ret[i] = Nmod<N>::sub(first[i], second[i]); }
    if(pt == first.data()){
        for(size_t i = min; i != max; i++){ ret[i] = pt[i]; }
    }
    else{
        for(size_t i = min; i != max; i++){ ret[i] = Nmod<N>::sub(0, second[i]); }
    }
    for(long i = ret.size()-1; i != -1; i--){ 
        if(ret[i]){ break; } else { ret._size--; } 
    }
    return ret;
}

template<ulong N> 
inline size_t Poly<N>::msize()
{
    return _msize;
}

template<ulong N> 
Poly<N> &Poly<N>::operator=(const Poly<N> &other)
{
    if(this == &other) return *this;
    Poly<N> ret(other.size());
    for(size_t i = 0u; i != other.size(); i++){ ret[i] = other[i]; }
    for(size_t i = other.size(); i < ret.size(); i++) { ret[i] = 0ul; }
    return ret;
}

template<ulong N> 
Poly<N> &&Poly<N>::operator=(Poly<N> &&other)
{
    if(this == &other) return *this;
    this->_size =  other.size();
    this->_msize = other.msize();
    this->_val =   other.data();
    other._msize = 0;
    other._val = 0;
    other._size = 0;
    return *this;
}
template<ulong N> 
Poly<N>::Poly(Poly<N> & other)
{
    if(this == &other){ return; }
    init(other.size());
    for(size_t i = 0; i != other.size(); i++){ _val[i] = other[i]; }
    for(size_t i = other.size(); i < _msize; i++){ _val[i] = 0ul; }
}

template<ulong N> 
Poly<N>::Poly(Poly<N> && other)
{
    if(this == &other){ return; }
    this->_size =  other.size();
    this->_msize = other.msize();
    this->_val =   other.data();
    other._msize = 0;
    other._val = 0;
    other._size = 0;
}

template<ulong N> 
Poly<N> Poly<N>::shiftRight(const Poly<N> &p, size_t pos)
{
    Poly<N> ret(p.size() + pos);
    ret._size = p.size() + pos;
    for(size_t i = 0; i != pos; i++){ ret[i] = 0UL; }
    for(size_t i = pos; i != ret.size(); i++){ ret[i] = p[i-pos]; }
    for(size_t i = ret.size(); i != ret.msize(); i++){ ret[i] = 0UL; }
    return ret;    
}
template<ulong N> 
Poly<N> Poly<N>::shiftLeft(const Poly<N> &p, size_t pos)
{
    size_t n = pos >= p.size() ? 0 : p.size() - pos;
    Poly<N> ret(n);
    ret._size = n;
    for(size_t i = 0; i != ret.size(); i++){ ret[i] = p[i+pos]; }
    for(size_t i = ret.size(); i != ret.msize(); i++){ ret[i] = 0UL; }
    return ret;    
}

} // namespace nmod