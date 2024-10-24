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

/* reworked 
include<iostream>
#include<cstdlib>
using namespace std;

using ulong = unsigned long long;
using llong = long long;

template<size_t N>
class Vec
{
public: 
    Vec<N>()=default;
    
    Vec<N>(int len)
    { 
        this->zero(len);
    }
    
    Vec<N>(long * ar, int len)
    { 
        this->set(ar, len);
    }
    
    Vec<N>(Vec<N> & v)
    {
        this->set(v.data(), v.size());
    }
    
    Vec<N>(Vec<N> && v)
    {
        _ar = v._ar;
        _len = v._len;
        v._ar = nullptr;
        v._len = 0;
    }
    
    ~Vec<N>()
    {
        this->clear(); 
    }
    
    void set(long * ar, int len)
    {
        this->clear();
        this->init(len);
        for(int i = 0; i != len; i++){ _ar[i] = ar[i]; }
    }
    
    void zero(long * ar, int len)
    {
        this->clear();
        this->init(len);
        for(int i = 0; i != len; i++){ _ar[i] = 0; }
    }
    
    static void swap(Vec<N> & first, Vec<N> & second)
    {
        std::swap(first._len, second._len);
        std::swap(first._ar, second._ar);
    }
    
    static Vec<N> add(const Vec<N> & first, const Vec<N> & second)
    {
        Vec<N> ret;
        if(first.size() > second.size()){
            ret.init(first.size());
            for(int i = 0, n = second.size(); i != n; i++){ ret[i] = first[i] + second[i]; }
            for(int i = second.size(), n = first.size(); i != n; i++){ ret[i] = first[i]; }
        }
        else{
            ret.init(second.size());
            for(int i = 0, n = first.size(); i != n; i++){ ret[i] = first[i] + second[i]; }
            for(int i = first.size(), n = second.size(); i != n; i++ ){ ret[i] = second[i]; }
        }
        return ret;
    }
    
    static Vec<N> sub(const Vec<N> & first, const Vec<N> & second)
    {
        Vec<N> ret;
        if(first.size() > second.size()){
            ret.init(first.size());
            for(int i = 0, n = second.size(); i != n; i++){ ret[i] = first[i] - second[i]; }
            for(int i = second.size(), n = first.size(); i != n; i++){ ret[i] = first[i]; }
        }
        else{
            ret.init(second.size());
            for(int i = 0, n = first.size(); i != n; i++){ ret[i] = first[i] - second[i]; }
            for(int i = first.size(), n = second.size(); i != n; i++ ){ ret[i] = second[i]; }
        }
        return ret;
    }
    
    static Vec<N> mul(const Vec<N> & source, long l)
    {
        Vec<N> ret;
        ret.init(source.size());
        for(int i = 0, n = source.size(); i != n; i++){ ret[i] = source[i] * l;  }
        return ret;
    }
    
    inline long &operator[](size_t pos)
    { 
        return _ar[pos]; 
    }
    inline long operator[](size_t pos) const 
    { 
        return _ar[pos]; 
    }
    Vec<N> operator=(Vec<N> & v){ return Vec<N>(v); }
    Vec<N> operator=(Vec<N> && v){ return Vec<N>(v); }
    
    void print()
    {
        std::cout << "<length-" << _len << " integer vector mod " << N << ">\n";
        std::cout << "[";
        for(int i = 0; i != _len; i++){ cout << " " << _ar[i];}
        std::cout << " ]\n";
    }
    inline long * data() const { return _ar; }
    inline size_t size() const { return _len; }
protected:
    void init(int len)
    { 
        clear();
        _ar = new long[len]; 
        _len = len;
    }
    void clear() 
    { 
        if(_ar){ delete[] _ar; }
        _ar = nullptr; 
    }
private:
    long * _ar = nullptr;
    size_t _len = 0;        
};

*/