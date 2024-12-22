//concrete classes behave just like built-in types 
//Complex number type and infinite precision integer are much like 
//built-in type int except they have their own semantics 

//concrete class types have its representation as part of definiotion 
//represntation is one or more pointers to more data stored else where 
//but it's present in each object of the concrete class 
//That allows implementation to be optimally efficient

//allows us to 
//place objects of concrete types on the statically allocated memory 
//refer to obhect directly (and not just through pointers or references)
//initialize objects immediately and completely 
//copy object

class complex {
    double re, im; //representation: two doubles 
public: 
     complex(double r, double i) : re{r}, im{i} {} //construct complex from two scalars 
     complex(double r) : re{r}, im{0} {}  //construct complex from one scalar 
     complex() : re{0}, im{0} {}   //default constructor 

     double real() const {return re;}
     void real(double d ) {re=d;}
     double imag() const {return im;}
     void imag(double d) {im = d;}

     //add o re and in and return result  
     complex& operator+=(complex z) {re+=z.re, im+z.im; return *this;}

     complex& operator-=(complex z ) { re-=z.re, im -=z.im; return *this;}

     complex& operator*=(complex z);  //defined out of class somewhere 
     complex& operator/=(complex z ); //defined out of class somewhere

     friend complex operator+(complex a, complex b) {return a+=b;}
     friend complex operator-(complex a, complex b) {return a-=b;}
     friend complex operator-(complex a) {return -a.re, -a.im;}
     friend complex operator/(complex a, complex b) {return a/=b;}
     friend complex operator*(complex a, complex b) {return a*=b}

     //The definition of == and != are straightforward 

     friend bool operator==(complex a, complex b) {return a.real()==b.real() && a.imag()=b.imag();}
     friend bool operator!=(complex a, complex b)  {return!(a==b);}

     void f (complex z)
     {
        complex a {2, 3};  //construct {2.3, 0.0}
        complex b {1/a};
        complex c {a+z * complex{1, 2.3}};
        //..
        if (c!= b)
            c =-(b/a)+2*b;
     };

};
