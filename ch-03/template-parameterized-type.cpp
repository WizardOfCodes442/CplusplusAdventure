//A template is a class or a function that we parameterize with a set of types or values.
//we use templates to represent concepts that are best understood as something very general b
//from which we can generate specific types and functions.

//we can generalize our vector of doubles type to  
//a vector of anything type by making it a template 
//
#include <list>
#include <string>
#include <iostream>
template<typename T>
class Vector {
private:
    T* elem; //elem points to an array of sz elem of type T
    int sz;

public:
    Vector(int s);  // constructor : establish invariant, acquire resources 
    ~Vector() {delete[] elem;}  //destructor: release resources 

    //... copy and move operations 
    T& operator[]( int i);
    const T& operator[] (int i) const;
    int size() const {return sz;}

};

//The template<typename T>  prefix makes T a parameter of 
//the declaration it prefixes. It is 
//The member function might be defined similarly:
template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0) throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
const T& Vector<T>::operator[] (int i) const;
{
    if (i<0  || size()<= i)
        throw out_of_range{"Vector::operator[]"}
    return elem[i];
}

//given these definitions we can define Vectors like this 
Vector<char> vc(200);  //vector of 200 characters 
Vector<string> vs(17); //vector of 17 strings
Vector<list<int>> vli(45);   //vector of 45 lists of integer

//we can vector like this 
void write(const Vector<string>& vs)  //Vector of some strings 
{
    for (int i = 0; i!=vs.size(); ++i)
        std::cout<< vs[i] << '\n';
}
//to support the range for loop for our vector 
//we must define suitable end and begin functions:

template<typename T>
T* begin(Vector<T>& x)
{
    return &x[0];  //pointer to first element 
}

template <typename T>
T* end(Vector<T>& x)
{
    return x.begin() + x.size(); //pointer to one past last element
}

//Given those, we can write 
void f2(const Vector<string>& vs)  //Vector of sopme strings
{
    for (auto& s : vs)
        std::cout << s << "\n"; 
}

//Similarly we can define lists, vectors , maps (i.e associative arrays )
//Templates are compile time mechanism.

