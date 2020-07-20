#pragma once;
#include "fast_integer_exponentiation.h"

template <class T>
class Field;

template <class T>
class Element<T>{
    
    
    Element operator + (Element const B) { 
         return value+mod(B,; 
    }

    T value;
    Field* _field;
}

template <class T>
typename E Element<T>;
