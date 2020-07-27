cmake_minimum_required (VERSION 2.8.11)
project (PrimeCompression)
set(CMAKE_CXX_FLAGS "-O3")

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 

    add_executable (primecompression main.cpp config.cpp fieldsearch.cpp field.cpp actions/print.cpp actions/match.cpp actions/first_occur.cpp actions/distance.cpp)# actions/match.cpp actions/first_occur.cpp actions/distance.cpp)
    target_link_libraries(primecompression gmp pthread)
    #add_executable (primecompression-tests "test/element/add.cpp")
    #target_link_libraries(primecompression-tests Boost)

endif()