#include <iostream>

//an array of an elements of type char can be declared like this 

char v[6];    //array of 6 characters 

//a pointer can be declared like this 
char* p;   //pointer to character 

//The size of array must be a constant expression 
// A pointer variable can hold the address of an object of the 
//appropriate type 
char* p = &v[3];   //points to v's fourth element
char x = *p;  ///*p is the object that p points to 

//In an expression, prefix  unary  * means "contents of " and prefix unary & 
//means "address of " We can represent the result of that initialized definition 
//graphically;

//consider copying ten elements from one array to another. 

void copy_fct()
{
    int v1[10] = {0, 1, 2 , 3, 4, 5, 6, 7, 8, 9};
    int v2[10];     //to become a copy of v1 

    for (auto i = 0; i!=10; i++)  //copy elements 
        v2[i] = v[i];
}


//range for statement 
void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v )    // for each x in v 
         std::cout << x << "\n";

    for (auto x : {10, 21, 32, 43, 54, 65})
        std::cout<<x<<"\n";
}