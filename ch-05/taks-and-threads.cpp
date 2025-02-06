//computation that can potentially be executed with other computation is called a task
//A thread is a system representation of a task in a program.
//A task to be executed concurrently with other task is launched 
//constructing a std::thread(<thread>) with the task as its argument 
//A task is a function or a function object
#include <thread>
#include <iostream>
using namespace std;
void f();  // function

struct F {           //function object 
    void operator()();  //F's call operator 
};

void user()
{
    thread t1 {f};  // f() executes in seperate thread
    thread t2 {F()};  //F()() executes in seperate thread
    //join() means to wait for thread to terminate 
    t1.join();  //wait for t1
    t2.join();  //wait for t2
}

//thread of a program share single address space 
//programming concurrent tasks can be tricky consider
//possible implementations of the tasks f (a function) and F (a funtion object)

void f() {cout << "Hello";}

struct F {
    void operator()() {cout << "Parallel World!\n";}
};
//this implementation can poroduce odd output 
