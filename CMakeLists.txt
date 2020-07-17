cmake_minimum_required (VERSION 2.8.11)
project (PrimeCompression)
set(CMAKE_CXX_FLAGS "-O3")
add_executable (primecompression main.cpp fast_integer_exponentiation.cpp)