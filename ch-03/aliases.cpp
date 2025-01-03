//aliases 
//often useful to introduce a synonym for a type or a template 
//the standard header <cstddefd> contains a defintitin of the 
//alias size t , maybe 

using size_t = unsigned int;

//size_t is implementation-dependent
//having size_t allow programmer to write portable code
//it very common for parameterized type to provide an alais for types 
//related to their template arguments 
//
template<typename T>
class Vector {
public:
    using value_type = T;
    // ...
};

//every standard -library container provids value_type 
//as the name of its value type
//allows us o write code that will 
//work for every container 
//that follows this convention

template<typename C>
using Element_type = typename C::value_type;

template<template Container>
void algo(Container& c)
{
    Vector<Element_type<Container>> vec;  // keep results here 
    //...
}

//The aliasing can be used to define a new template by binding 
//some or all template arguments . for example:
template <typename Key, typename Value>
class Map {
    //...
};

template<typename Value>
using String_map = Map<string, Value>;

String_map<int> m;  //m is a Map<string, int>