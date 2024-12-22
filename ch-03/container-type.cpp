//A container is a type holding a collection of objects 
//So we call a  vector a container because it's the type of objects 
//that are containers 
//desctructur gor deallocating memory used by constructors asfter it's done 

class Vector {
    private: 
        double* elem;   //elem points to an array of sz doubles 
        int sz;

    public: 
        Vector(int s): elem{new double[s]}, sz{s}  //constructor acquire resources 
        {
            for (int i =0; i!=s; ++i) elem[i] = 0;   //initialiaze elements 
        }

        ~Vector() {delete[] elem;}    //destructor: releases resources 

        double& operatror[](int i);
        int size() const;


}

//The user simply use Vector like they would use any other variable 
//and they have no idea how the constructor and destructor get their work done 
//and example usage is presented below 

void fct(int n)
{
    Vector v(n);
    // ... use vector v ...
    {
        Vector v2(2*n);
        // .. use v and v2 ..

    }  //v2 is destroyed here 

    // .. use v ..
}   // v is destroyed here 

namespace init-container {
    // A container exists to hold elemnts, so obviously we need 
    //convenient ways of getting elemts into a container 
    //We can handle that by creating a vector with an appropriate 
    //number of elements and then asigning to them, but typically other ways are more elegant
    //Initializer-list constructor : Initialize with a list of elements.
    //push_back(): Add a new elements at the ( at the back of ) the sequence 
    class Vector {
        public: 
            Vector(std::initializer_list<double>);  //initializes with a list 
            //...
            void push_back(double);      // addelement at end increasing the size by one 
            //..
    }

    //the push_back() is useful for input of arbitrary numbers of elements 
    Vector read(istream& is )
    {
        Vector v ;
        for (double d; is>>d;)   /// read floating point values into d
            v.push_back(d);      //ad d to v 
    }

    //The std::initializer_list used to define the initializer-list constructor is a standard-library 
    //type known to the compilere: when we use a {} list, such as {1, 2, 3, 4},
    //the compiler will create an object of type initializer_list to give the program. so we can write 

    Vector v1 = {
        1, 2, 3, 4, 5
    }   //v1 has 5 elements 

    Vector v2 = {1.233, 3.45, 6.7, 8};  //v2 has 4 elements 

    //Vector's initializer-list constructor might be define like 
    Vector::Vector(std::initializer_list<double> lst)  //initialize with a list 
        :elem{new double[lst.size()]}, sz{lst.size()}

    {
        copy(lst.begin(), ist.end(), elem);    //copy from list into elem 
    }
}