#include "nmod.h"

namespace nmod
{
    template<size_t N> inline ulong nmod::Nmod<N>::init(slong value)
    {
        ulong ret = (ulong)(value % (sllong)N  + (value < 0 ? N : 0));
        return ret;
    }

    template<size_t N> inline ulong add(slong first, slong second)
    {
        sllong val = first + second;
        ulong ret = (ulong)(val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<size_t N> inline ulong sub(slong first, slong second)
    {
        sllong val = first - second;
        ulong ret = (ulong)(val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<size_t N> inline ulong mul(slong first, slong second)
    {
        sllong val = first * second;
        ulong ret = (ulong)( val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<size_t N> inline ulong div(slong first, slong second)
    {
        ulong ret = Nmod<N>::mul(first, Nmod<N>::inv(second));
        return ret;
    }

    template<size_t N> inline ulong pow(slong value, ulong exp)
    {
        ulong val = Nmod<N>::init(value),
            ret = 1UL;
        while(exp){
            if(exp & 1){ ret = Nmod<N>::mul(ret, val); }
            val = Nmod<N>::mul(val, val);
            exp >>= 1;
        }
        return ret;
    }

    template<size_t N> inline ulong inv(nmod::slong val) noexcept(true)
    {
        ulong ret = Nmod<N>::pow(val, N-2);
        return ret;
    }

    template<size_t N> inline bool divides(slong first, slong res, slong second)
    {
        return Nmod<N>::mul(first, second) == Nmod<N>::init(res);
    }
}
