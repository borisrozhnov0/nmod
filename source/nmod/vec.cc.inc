#include "vec.h"

namespace nmod
{
    template<size_t N> inline void Vec<N>::zero(size_t len)
    {
        if(len > _len){ len = _len; }
        for(size_t i = 0, n = len + 1; i != n; i++){ _ar[i] = 0; }
    }
    
    template<size_t N> inline void nmod::Vec<N>::print()
    {

        std::cout << "<length-" << std::to_string(_len) 
                  << " integer vector mod " << std::to_string(N) << ">\n[";
        for(size_t i = 0UL, n = _len; i!= n; i++) { 
            std::cout << " ";
            std::cout << std::to_string(_ar[i]); 
        }
        std::cout << " ]\n";
    }
}