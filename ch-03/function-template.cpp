//template are used to parameterized both types and algorithm 
//in standard library. 
//for example we can write a function that claculates 
//the sum of the element values of any container like this

#include <list>
#include <vector>
template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x: c)
    v+= x;
    return v;
}

//The value yemplate argument and the function argument v are there to allow 
//to specify the type and initial value of the accumulator (the variable 
// in which to acummulate the sum

void user(Vector<int>& vi, std::list<double>& ld, std::vector<complex<double>>& vc)
{
    int x = sum(vi, 0);    //the sum of a vector of ints(add ints)
    double d = sum(vi, 0, 0);   //the sum of a vector of intd (add doudles)
    double dd = sum(ld, 0, 0);  // the sum of a list of doubles 
    auto  z = sum(vc, complex<double>{});  //the sum of a vector of complex<double>
                                        //the initial value is {0, 0, 0, 0 }
}

//This sum is a simplified version of standard library 
//accumulates 