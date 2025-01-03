//One particular useful kind of template is the function object 
//(sometimes called a functor), which is used to define objects 
//that can be called like functions. For example

#include <iostream>
#include <memory>
#include <vector>
template<typename T>
class Less_than {
    const T val;  //value to compare against

public: 
    Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const {return x < val;}  //call operator 
};

//The function called operator() implements the function call "call" or "application" 
//operator().
//we can define named variables of type Less_than
//for some argument type:
Less_than<int> lti{42};  //lti(i) will compare i to 42 using  < (i<42)
Less_than<string> lts{"Backus"};  //lts will compare s to "Backus" 
//using  < ( s < "Backus")

//we call such an object
//such as we call a function 
void fct(int n,const string & s) {
    bool b1 = lti(n);
    bool b2 = lts(s);
    //..
} 

//such functions are widely used as argument to algorithms \
//For example, we can count the occurence of value s
//for which a predicate returns true 

template<typename C, typename P>
int count (const C& c, P pred)
{
    int cnt = 0;
    for(const auto& x : c) 
        if (pred(x))
            ++cnt;
        return cnt;
}

//A predicate is something we can invoke 
// to return true or false for example 

void f (const Vector<int>& vec, const list<string>& lst , int x, const string& s) 
{
    std::cout <<"number of values less than " << x
              << ":" << count(vec, Less_than<int>{x})
              << '\n';
    std::cout << "number of values less than " << s
              << ":" << count(lst, Less_than<string>{s})
              << '\n';

    
}

//The beauty of function object is they carry the value 
//to be compared against with them. we don't have to write 
// a seperate function for each value and each type and we don't 
//have to introduce nasty global variables to hold values 

//function objects used to specify the meaning of key 
// operations of a general algorithm such Less_than for 
//count() are often referred to as policy objects.
//there is a notation for implicitly generating 
//function objects:

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    std::cout << "number of values less than" << x 
              << ":" << count(vec, [&](int a) {return a <s; })
              << '\n';
    std::cout << "number of values less than " << s 
              << ":" << count(lst, [&](const string& a ) {return a < s;})
              << '\n';

}

//The notation [&](int a) {return a < x }; is called lambda expression 
//It generates a function object exactly like Less_than<int>{x}.
//[&] capture all local names used by reference 
//[] capture nothing 
//[=x] capture generated object copy of x 
//[&x] capture  only x by reference 
//[=] capture all local names used by values 

//for non trivial actions (say more than a simple expression )
//I prefer to name the operation so as to more clearly state 
//its purpose and make it available for use in several place in a program 

//when in annoyance of having to write many functions 
// to perform operations on elements of vectors of pointers 
// and unique pointers .
//Function objects (in particular lamdas ) can help by allowing 
// us to seperate the transversal of the container 
//from the specification of what is to be done with each elements 

template<class C, class Oper> 
void for_all(C& c, Oper op)  //assume that C is a container o0f pointers 
{
    for (auto& x: c)
        op(*x);  //pass op() a reference to each element pointed to        
}

//Now we can write a version of user() from without 
//writing a set of __all functions:
void user()
{
    std::vector<std::unique_ptr<Shape>>  v;
    while(std::cin) 
        v.push_back(read_shape(std::cin));
    for_all(v, [](Shape& s){s.draw();});       //draw_all()
    for_all(v, [](Shape& s){s.rotate(45);});  // rotate_all(45)

}

//I pass a reference to Shape  to a lambda so that the 
//the lambda doesn't care exactly how the objects are stored 
// in a container
//In particular , those for_all() calls would still work 
//if I changed v to a vector<Shape *>
