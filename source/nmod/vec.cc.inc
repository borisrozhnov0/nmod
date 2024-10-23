#include "vec.h"

namespace nmod
{
    template<size_t N> inline void Vec<N>::zero(size_t len)
    {
        if(len > _len){ len = _len; }
        for(size_t i = 0, n = len + 1; i != n; i++){ _ar[i] = 0; }
    }

    template<size_t N> inline void Vec<N>::zero()
    {
        for(size_t i = 0;  i != _len; i++){ _ar[i] = 0; }
    }

    template<size_t N> void Vec<N>::print()
    {

        std::cout << "<length-" << std::to_string(_len) 
                  << " integer vector mod " << std::to_string(N) << ">\n[";
        for(size_t i = 0UL, n = _len; i!= n; i++) { 
            std::cout << " ";
            std::cout << std::to_string(_ar[i]); 
        }
        std::cout << " ]\n";
    }

    template<size_t N> inline void Vec<N>::set(ulong *ar, size_t len)
    {
        if(_ar){ delete[] _ar; }
        _ar = new ulong[len];
        _len = len;
        _ar = (ulong*)std::memcpy(_ar, ar, sizeof(ulong) * len);
        setMod();
    }

    template<size_t N> inline void Vec<N>::swap(Vec<N> &first, Vec<N> &second)
    {
        size_t tmp = first._len;
        ulong * pt = first._ar;
        first._len = second._len;
        first._ar  = second._ar;
        second._len = tmp;
        second._ar =  pt;
    }

    template<size_t N> inline Vec<N> Vec<N>::init(size_t len)
    {
        return Vec(new ulong[len], len);
    }

    template<size_t N> inline void nmod::Vec<N>::setMod()
    {
        for(size_t i = 0; i != _len; i++){ _ar[i] = nmod::Nmod<N>::init(_ar[i]); }
    }

    template<size_t N> inline nmod::Vec<N>::Vec(nmod::ulong *ar, size_t len):_ar(ar), _len(len)
    {

    }
}