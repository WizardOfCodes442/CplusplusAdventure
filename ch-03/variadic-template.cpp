//Variadiac Template 
//A template can be defined to accept an arbitray number of arguments types 
//such a template is called a variadic template 
//for example 

#include <iostream>
template<typename T, typename ... Tail>
void f(T head, Tail ... tail)
{
    g(head);   //do something to head
    f(tail...); //try again with tail 
}

void f() {}  //do nothing 

//The key to implement a varidic template is to note
//that when you pass a list of arguments to it 
//you can seperate the first argument from the rest 
//here , we do something to the first argument (the head)
//and hen rcursively call f() with the rest of the arguments
//(the tail). 
//we can call this f() like this: 

int main()
{
    std::cout << "first";
    f(1,2.2, "hello");
    std::cout << "\nsecond:";
    f(0.2, 'c', "yuck!", 0,1,2);
    std::cout<<"\n";
}

//This would call f(1, 2.2, "hello"), which will call f(2.2, "hello")
//which will call f("hello")
//which will call f()

//The strenght of variadics is that they can accept any 
//arguments you care to give them.
//The weakness is that the type checking of the interface is a 
//possibly template elaborate program 

//