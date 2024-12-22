// the first step to building a type is often to 
//organize the elements it needs into a datastructure
#include <iostream>

struct Vector {
    double* elem;   //pointer to elements 
    int sz;
};

//for the type to be useful it must contain some operations 
//the first help us to initialize the type 
void vector_init(Vector&v, int s)  //initialize a Vector 
{
    v.elem = new double[s];//allocate an array of s doubles 
    v.sz = s;
};

// A simple use of vector 

double read_and_sum(int s) 
//read s integers from cin and returb their sum; 
// s is assumed to be positive 
{
    Vector v;
    vector_init(v,s);   // allocate s elements for v 

    for (int i = 0; i!=s;++i)
        std::cin>>v.elem[i];     // read into elements 

    double sum = 0;
    for (int i =0; i !=s; ++i)
        sum+=v.elem[i];
    return sum;
    
}

//use (dot .) to acces struct members through a name and reference 
// -> to access struct members through a pointer

void f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz;   // access through name 
    int i2 = rv.sz;  //access through referenece 
}