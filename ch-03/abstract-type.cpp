//an anstract type is a type that completely insulates a user from 
//implementation details. 
//interface is decopled from the representation

//we must allocate objects on the free store and access them through  references or pointer
//we define the interface of a class Container which will design as a more abstract vector 

class Container {
    public:
        virtual double& operator[] (int) =0;  //pure virtual function
        virtual int size() const = 0;  //const membere function 
        virtual Container() {}      //destructor 
}

//this class is a pure interface to specific containers defined later 
// a class derived from Container provides an implementation for the 
//Container interface 
// = 0 in syntax means function is pure virtual 
//i.e some class derived from containers must define the function 
// not possible to define an object that's just a container 
// a container can only serve as an  interface to a class that implements 
//its methods 
//container maybe used like this 

void use(Container& c )
{
    const int sz = c.size(); 
    for (int i=0; i!=sz; ++i) 
        cout << c[i] << '\n';

}

//A container that implements the functions required by the interface defined 
//by the abstract class Container could use the concrete class Vector;

class Vector_container: public Container {  //Vector_container implements Container
    Vector v;

    public:
        Vector_container(int s) {}   //Vector of s elements 
        ~Vector_container() {}

        double& operator[](int i) {return v[i]}
        int size() const {return v.size();}
}

//The above example demonstrates the concept of inheritance 
//and the members operator[]() and size() are said to override the 
//corresponding members in the base class container 


//for function like use(Container&) to use container in complete ignorance 
//of implementation details... some other functions have to make an object
//on which it can operate... for example 
void g()
{
    Vector_container vc {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    use(vc);
}

//Since use() doesn't know about Vector_container but only knows 
//the Container interface, it will work just as well for a different implementation 
//of a container for example 

class List_container: public Container {  //List_container implements Container
    std::list<double> ld:    //(standard-library)  list of doubles
    
    public:
        List_container() {}
        List_container(initializer_list<double> il): ld{ii} {}
        ~List_container() {}

        double& operator[] (int i);
        int size() const {return id.size();} 
};

double& List_container::operator[](int i) 
{
    for (auto& x : ld) {
        if (i== 0) return x;
        --i;
    }
    throw out_of_range("List_containers");
}

//a function can create a List_container and have use it;

void h() 
{
    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(lc);
}

//The point of the above example is that use(Container &) has no idea 
//if its argument is a Vector_container, a List_Container, It Know only 
//the interface defined by the Container 
//The flip side of this flexibiliy is objects must be manipulated through pointer or references 
