#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "search.h"
#include "config.h"

int main(int argc, char** argv){
    Config conf("config.json");
    Search s(&conf);
    return 0;
}