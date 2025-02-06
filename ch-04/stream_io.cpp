#include <iostream>
#include <string>
using namespace std;
//The standard library provides formatted character input and output through the iostream library
//The input operations are typed and extensible to handle user-defined types 
//other forms of user interactions such as graphical I/O are handled through libraries 
//that are not part of the ISO standard 

//Output 
//The I/O stream libarry defines output for every built-in type 
//It's easy to define output of a user defined type. 
//The operator << ("put to ") is used as an output operator on objects 
//of type ostream; cout is the standard output stream and cerr is the standard stream 
// for reporting errors 
//By default, values written to cout are converted to na sequence of characters. 
//For example to output the decimal number 10, we can write :

void f() 
{
    cout << 10;
}

//Equivalently 
void g()
{
    int i {10};
    cout << i;
}

//Output of different types can be combined in the obvious way:

void h (int i)
{
    cout << "the value of i is ";
    cout << i;
    cout << '\n';

}
//Equivalently 
void h2 (int i ) 
{
    cout << "the value of i is"<< i << '\n';
}

//Note that character is output as character rather than as numerical value.
void k() {
    int b = 'b';    // note: char implicitly converted to int  
    char c = 'c';
    cout << 'a' << b << c;
}


//Input 
//The standard library offers istreams for input . Like ostreams, istreams deal with 
//character string representation of built -in types and can easily be extended to cope with 
//user defined types 
//>> used for input 
// cin is the standard input stream 

void f() 
{
    int i; 
    cin >> i;  //read an integer into i 

    double d;
    cin >> d; //read a double-precision floating-point number into d
}

//Often we want to read a sequence of charcters.
//A convenient way of doing that is to read into a string 

void hello() {
    cout << "Please enter your name\n";
    string str;
    cin >>str;
    cout << "Hello, " << str << "!\n"; 
}

//You can read a whole line (including the terminating newline character )
//using the getline() function for example 

void hello_line()
{
    cout << "Please enter your name \n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
}

//IO of User-Defined Types 
struct Entry {
    string name; 
    int number;
};

//we can define a simple output operator to write entry 
// using a {"name", number} format similar to the one 
// we use for initialization of the code 
ostream& operator<<(ostream& os, const Entry& e) {
    return os<<"{\""<<e.name<<"\", "<<e.number <<"}";
};

// A user-defined output oerator takes its output stream (by reference ) as its 
//first argument and returns it as its result. 

//The corresponding input operator is more complicated because it has check for 
// correct formatting and check for errors:

istream& operator>>(istream& is, Entry& e) //read 
{
    char c, c2;
    if (is >> c && c  == '{' && is>>c2 && c2=='"') { //start with a {"
        string name;        // the default value of a string is the empty string. ""
        while (is.get(c) && c!='"')  //anything before a " is part of the name 
            name+=c;

        if (is>>c && c==',') {
            int number = 0;
            if (is >> number >> c && c =='}') {
                e = {name, number}; //asign to the entry
                return is;
            }
        }
    }
    is.setf(ios_base::failbit);  //register the failure in the stream
    return is;
}