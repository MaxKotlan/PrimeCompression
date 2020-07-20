#pragma once
#include "fast_integer_exponentiation.h"
#include <iostream>

template <class T>
class Field;

template <class T>
class Element{
    public:

    Element(T value, T modulo=0) : _value(value), _p(modulo) {};
    
    Element operator - (Element const B) { 
         return mod(_value-mod(B._value, _p), _p); 
    }

    Element operator + (Element const B) { 
         return mod(_value+mod(B._value, _p), _p); 
    }

    Element operator * (Element const B) { 
         return mod(_value*mod(B._value, _p), _p); 
    }

    Element operator % (Element const B) { 
         return mod(_value, B._value); 
    }

    Element operator ^ (Element const B) { 
         return mod(_value, B); 
    }

     Element operator-() {
          _value = _p-_value;
          return *this;
     }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Element<U> e);

    private:
    
    T _value;
    T _p;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Element<T> e)
{
    os << e._value;
    return os;
}

template <class T>
Element<T> power(Element<T> A, Element<T> B){
     return power(A, B);
}