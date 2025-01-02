//by default objects can be copied.
//This is true for both user-defined and built-in objects
//The default meaning of copy is memberwise copy

void test(complex z1)
{
    complex z2{z1};  //copy initialization
    complex z3, 
    z3 = z2;
    //..             
}

//Copying Containers 
//when a class is a resource handle, that is 
//responsible for objects accessed through a 
//pointer... memberwise copy is not good option here 
// will violate the resource handle-invariants

//for example, the default copy would leave a copy 
//of a vector refering to thesame element as the original 

void bad_copy(Vector v1)
{
    Vector v2 = v1;  //copy v1's representation into v2 
    v1[0] = 2;       //v2[0] is now also 2!
    v2[1] = 3;      //v1[1] is now also 3
}

//Copying of an object of a class is defined by two members :
//a copy construtor and a copy assignment

class Vector {
private:
    double* elem;   //elem points to an array of sz doubles 
    int sz;

public:
    Vector(int s);           //constructor: establish invariant, acquire resources
    ~Vector() {delete[] elem;}  

    Vector (const Vector& a ); // copy constructor
    Vector& operator=(const Vector& a); //copy assignment

    Vector(const Vector&& a);  // move constructor
    Vector& operator=(Vector&& a);  //move assignment
    
    double& operator[] (int i);
    const double& operator[] (int i ) const;

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;

};

//A suitable definition of a copy constructor for 
//Vector allocates the space for the required number 
//of elements and then copies the elements into it,
//so that after a copy each Vector has its own copy 
//of the elements:

Vector::Vector(const Vector& a) //copy constructor 
    :elem{new double[sz]}, //allocate space for elements 
    sz{a.sz}

{
    for (int i =0; i!= sz; ++i)   //copy elements
        elem[i] = a.elem[i];
}
//we need a copy assignment in addition to the 
//copy constructor: 

Vector& Vector::operator=(const Vector& a)  //copy assignment
{
    double* p = new double[a.sz];
    for(int i = 0; i!=a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;  //delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}

//Moving Containers 
//We can control copying by defining a copy constructor and a 
//a copy assignment. 
//but copying can be costly for large containers 
//consider 
Vector operator+(const Vector& a, const Vector& b)
{
    if (a.size() != b.size())
        throw Vector_size_mismatch{};

    Vector res(a.size());
    for (int i=0; i!=a.size(); ++i)
        res[i] =a[i]+b[i];
    return res;
}

//Returning from a + involves copying the result out of \
//the local variable res and into some place where the 
//caller can access it.
//We might use this + like this

void f (const Vector& x, const Vector& y, const Vector& z)
{
    Vector r;
    //...
    r = x+y+z;
    //...
}

//That would be copying a vector at least twice 
//one for each of the + operator 
//If a vector is large, say 10,000 doubles, that could be 
//embarassing.
//we didn't really  copy, we just wanted the result 
//of a function.
//we wanted to move a Vector rather than to copy it.
//Fortunately we can state that intent with 
//move constructor
//move assignments 
//the compiler will choose the move constructor 
//to implementthe transfer of the return value out 
//of the function.
//This means that r = x+y+z will no copying of vectors
//Instead vectors are just moved. 
Vector::Vector(Vector&& a)
    :elem{a.elem},    //"grab the elements" from a
    sz{a.sz}

{
    a.elem =nullptr;   //now a has no elements 
    a.sz = 0;
}

//The && means "rvalue reference" and is a reference to which we can bind an rvalue
//rvalue means a value you can't assign to, such as an integer returned by a function call 
//and an rvalue reference is a reference no one can assign to.
//The res local variable in operator+() for Vector is an example


//A move constructor does not take const argument: after all 
//a move constructor is supposed to remove the value from its argument
//A move assignment is defined similarly 

//A move operation is applied when an rvalue reference is used as an initiliazer or 
//as the right hand side of an  assignment 

//After a moive, a moved-from object should be in the state thatn allows a destructorto be run 
//Where the programmer knows that a value will not be used again, 
// but the compiler can't be expected to be smart enough to figure that out. 
//the programmer can be specific. 
Vector f()
{
    Vector x(1000);
    Vector y(1000);
    Vector z(1000);
    //...
    z = x;  // we get a copy
    y = std::move(x);  //we get a move 
    //..
    return z;
    
}