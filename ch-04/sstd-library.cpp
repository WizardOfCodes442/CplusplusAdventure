//The facilities provided by standard library can be classified like this 

//Runtime language support (e.g for allocation and runtime type information  )

//The C standard library 

//Strrings and I/O streams (with support for international language 

//A framework of containers (such as vectors and maps )  and algorithm such as sort(), merge(), find()

//Support for numerical computation (such as standard mathematical functions, complex numbners, vectors with arithmetic 
// operatios and random number generators )

//Support for regular expression mmatching 

//Support for concurrent progreamming, including threads, and locks 

//Utilities to support template metaprogramming
//STL -style generic programming and general programming 

//Smart pointers for resource management (e.g unique_ptr, and shared_ptr) and an interface to garbage collectors 

//Special-purpose containers such as array, bitset and tuple

//The Standard library header and namespace makes 
//standard library facilities available, through include and using namespace 

//simple example
#include <string>   //make the standard string facilities available. 
#include <list> 
using namespace std;   // make std names availialbe 

string s {"C++ is a  general purpose programming language "};
list<string> slogans {"War is peace", "Freedom is slavery", "Ignorance is Strength"};

//The string type provides a variety of useful operations such as concatenation 

string compose (const string& name, const string& domain){
    return name 
}
auto addr = compose("dmr", "bell-labs.com");
