#include "nmod.h"

namespace nmod
{
    template<ulong N> inline ulong Nmod<N>::init(slong value)
    {
        ulong ret = (ulong)(value % (sllong)N  + (value < 0 ? N : 0));
        return ret;
    }

    template<ulong N> inline ulong Nmod<N>::add(slong first, slong second)
    {
        sllong val = first + second;
        ulong ret = (ulong)(val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<ulong N> inline ulong Nmod<N>::sub(slong first, slong second)
    {
        sllong val = first - second;
        ulong ret = (ulong)(val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<ulong N> inline ulong Nmod<N>::mul(slong first, slong second)
    {
        sllong val = first * second;
        ulong ret = (ulong)( val % (sllong)N  + (val < 0 ? N : 0));
        return ret;
    }

    template<ulong N> inline ulong Nmod<N>::div(slong first, slong second)
    {
        ulong ret = Nmod<N>::mul(first, Nmod<N>::inv(second));
        return ret;
    }

    template<ulong N> inline ulong Nmod<N>::pow(slong value, ulong exp)
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

    template<ulong N> inline ulong Nmod<N>::inv(nmod::slong val)
    {
        ulong ret = Nmod<N>::pow(val, N-2);
        return ret;
    }

    template<ulong N> inline bool Nmod<N>::divides(slong first, slong res, slong second)
    {
        return Nmod<N>::mul(first, second) == Nmod<N>::init(res);
    }
}
