//Most computing involves creating collectionof values and then 
//manipulating such collections 
//Reading characters into a string and printing out the string is a simple examplke 

//A class with the main purpose of holding objects is known as as a container 
//providing suitable containers for given task and supporting them with useful fundamental
//operations are important steps in construction of any program 

//Vector 
//The most useful standard-library  container vector.
//A vector is sequnce of elements of a given type. 
//The elements are stored contiguously in memory 
//The examples 
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>


using namespace std;
struct Entry {
    string name; 
    int number;
};
ostream& operator<<(ostream& os, const Entry& e) {
    return os<<"{\""<<e.name<<"\", "<<e.number <<"}";
};

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
//We can initialize a vector with a set of values of it's 
//element type 
vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Poper", 234567},
    {"Bertrand Arthur William Russell", 345678}

};

//Elements can be accessed through subscripting 
void print_book(const vector <Entry>& book)
{
    for (int i = 0; i!=book.size(); ++i) 
        cout<<book[i] <<'\n';
}

//the element of a vector constitute a range so we can use a range -for loop 
void print_book(const vector<Entry>& book )
{
    for (const auto&  x: book)
        cout << x << '\n';
}

//When we define a vector we give it an initial size (initial number of element)
vector <int> v1 = {1, 2,3};  // size is 4 
vector <string> v2; //size is 0
vector<Shape*> v3(23);  //size is 23 and initial value is null pointer
vector<double> v4 (32, 9.9); //size is 32 and initial element value 9.9


//The initial size can be changed 
//one of the most useful operator on vector is push back 
void input()
{
    for (Entry e; cin>>e;)
        phone_book.push_back(e);
}

//copying and moving of vectors are implemeted by constructors 
// and assignment operators, where copying is undesirable, pointers 
//references or move operators are to be considered 
//when a value is inserted into a container, the value is also copied 

//Range checking 
//The standard library vector does not gurantee range checking 
void silly (vector<Entry> & book)
{
    int i = book[ph.size()].number;  //book.size() is out of range 
    //..
}

//simple range checking adaptation of vectors 
template<typename T>
class Vec : public std::vector<T> {
public: 
    using vector<T>::vector; //use copnstructor from vector under the Vec

    T& operator[](int i)  //rsnge
    {
        return vector<T>::at(i); 
    }

    const T& operator[](int i) const   //range check const objects 
    { return vector<T>::at(i);}
};

//Vec inherits everything from vector except for the subscript operations 
//that redefines to do range checking. 

//The at() operations is a vector subscript operation that throws an exception 
//of type out_of_range if it's argument is out of vector's range 

//for vec, an out-of-range access will throw an exception that user can catch 
//void checked(Vec<Entry>& book)

void checked(Vec<Entry>& book)
{
    try {
        book[book.size()] = {"Joe", 999999};  //will throw an exception 
        //..
    }
    catch(out_of_range) {
        cout << "range error\n";
    }
}

//One way to minimize exception is to use a main()
//with try block as its body 

int main()
try {
    //your code 
}
catch(out_of_range) {
    cerr << "range error\n";
} 
catch (...) {
    cerr << "Unknown exception thrown"
}

//list 
//we use a list where we want to insert and ddelete elements 
//without moving other elements 
list<Entry> phone_book2 = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bernad Arthur William Russell", 345678}
};

//when we use linked list we do not access the elements through 
//subscripting as we do in vectors 
//Instead we might search the list looking for an element 
//of a given value 

int get_number(const string& s)
{
    for (const auto& x: phone_book2)
        if(x.name==s)
            return x.number; 
        return 0; //use 0 to represnt "number nout found "
}

//need to identify an element in a list 
//we may want to delete or insert a new  entry before it 
int get_number(const string& s) 
{
    for (auto p = phone_book2.begin(); p!= phone_book2.end(); ++p)
        if (p-> name==s)
            return p-> number;
    return 0;  //use 0 to represent number not found 

}

//Given an iterator p, *p is the element to which it refers, 
//++P advances p to refer to the next element 
//and when p refers to a class with a member m then 
//p-> m is equivalent to (*p).m

//Adding elements to a list and removing element from a list 
//is easy 

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
    phone_book2.insert(p, ee); //add ee before the element refered to by p
    phone_book2.erase(q);   //remove the element refered  to by q 

}

//unless you have a reason not to use a vector for collections 
//of elements then use a list
//vector() performs better in smaller size and for algorithms
//like count(), find(), sort(), binary_searcch();

//map 
//A map is known as an associative array .
//writing code to lookup name in list of(number, names ) is quite tedious 
//also a linear search is inefficient for all but a short list 
//standard library offers a search tree(red black treee) called map:
//std map is a container of pairs of values for lookup 
//we can use the same initializer as for vectors and list 
map<string , int> phone_book3 {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur Williams Russell", 345678}
};

//when indexed by a value of its first type(called the key)
//a map returns the corresponding value of the second type 
//(called the value or the mapped type). For example 
int get_number(const string& s)
{
    return phone_book3[s];
}

//if a key is not found in a map  subscript operation, 
//it is enetered into the map with a default value for it's value 
//If you want toj avoid using default insert, use find and insert()
//instead of []
//

//Unordered map 
//The cost of a mnap lookup is O(log(n))
//n is number of elements in map
//for better performance hashed lookups are prefered to direct 
//comparison of elems using an ordering function 
//using undored_map for phone cause it provides hashed lookup
unordered_map<string, int> phone_book4 {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur Williams Russell", 345678}
};

//as for a map,     we subscript an unordered map 
int get_number3(const string& s)
{
    return phone_book4[s];
}

//container overview 
//vector<T> A variable size vector 
//list<T> A doubly linked list 
//forward_list<T> A singly linked list 
//deque<T>  A double-ended queue
//set<T>    A set
//multiset<T>    A set with value repetition
//map<K, V>      An associative array
//multimap<K,V>   A map with key Repetition 
//unordered_map <K, V>  map with hashed lookup
//unordered_multimap<K, V> multimap with hash lookup
//unordered_set<T> A set using hashed lookup
//undored_multiset<T> A multiset using a hashed lookup 

//Algorithms 
//A data structure is not so useful on it's own
//To use we need operation for basic access 
//such as adding and remopving elements as is provided for vectors 
// and list 

//Furthermore we need extra operations like sorting, extracting
//printing, merging, searching for object amd more 
//The standard library provides also algorithms for containers 
//for example the following sort a vector and places the copy 
//of each unique vector elements in a list.

bool operator<(const Entry& x, const Entry& y)  //less than 
{
    return x.name < y.name; //order entries by their names 

}

void f (vector<Entry>& vec, list<Entry>& lst)
{
    sort(vec.begin(), vec.end());   //use < for order
    unique_copy(vec.begin(), vec.end(), lst.begin());  //don't copy adjacent equal elements

}
//the sort() sorts the sequence defined by the pair of iterators vec.begin()
//and vec.end(), for writing output we need to specify the first elemnt to be written 
//the element following that initial element will be overwritten 
//If we wanted to place the unique elements in a vector we could have written 

list<Entry> f(vector<Entry>& vec)
{
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res)); //append to res
    return res;
}

//If you find the pair-of-iterator style of code, 
//such as sort(vec.begin(), vec.end()), tedious you can define container versions of 
//the algorithm and write sort(vec)

//Use of Iterators 
//many algorithms return iterators, for example the standard algorithm
//find looks for a value in a sequence and returns an iterator to the 
//element found:

bool has_c(const string& s, char c)   //does s contain the character c ?
{
    auto p = find(s.begin(), s.end(), c);
    if(p!=s.end())
        return true;
    else
        return false;
};
//Like many standard-library search algorithms, find returns ends()
// to indicate "not found "
//An equivalent, shorter, definition of has_c() is:


bool has_c2(const string& s, char c ) //does s contain the character ?
{
    return find(s.begin(), s.end(), c)!=s.end();
}

//A more interesting excercise would be to find the location of all occurences of a character 
//in a string. 
//We can return the set of occurences as a vector of string iterators 
//Returning a vector is effecient because of vector provides move semantics
//Assuming we would like to modify the locations found, we pass a non const string 

vector<string::iterator> find_all(string& s, char c) //find all the occurences of c in s 
{
    vector<string::iterator> res;
    for (auto p = s.begin(); p!=s.end(); ++p)
        if (*p== c)
            res.push_back(p);
    return res;
}

//The typename is needed to inform the compiler that C's iterator is 
//supposed to be a type and not a value of some type , say integer 7,
//we can hide this implementation detail by introducing type alias
//for iterator :
template<typename T> 
using iterator<T> = typename T::iterator;

template<typename C, typename V>
vector<iterator<C>> find_all(C& c, V v)   //find all occurrences of v in c
{
    vector<iterator<C>> res;
    for (auto p = c.begin(); p!=c.end());
        if(*p == v)
            res.push_back(p);
    return res;
}

//we can now write 
void test()
{
    string m {"Mary had a little lamb"};
    for (auto p: find_all(m, 'a'))
        if(*p!='a')
            cerr << "String bug!\n";

    list<double> ld {1.1, 2.2, 3.3, 1.1};
    for (auto p: find_all(ld, 1.1))
        if(*p!=1.1)
            cerr << "list bug!\n";

    vector<string> vs {"red", "blue", "green", "green", "orange", "green"};
    for (auto p: find_all(vs, "green"))
        if(*p!="green")
            cerr << "Vector bug!\n";

    for (auto p : find_all(vs, "green"))
        *p = "vert";
}

//Iterator Types 
//Any particular iterator is an object of some type 
//There are however many different types of iterators 
//These iterator types can be different as the containers 
//and the specialized needs they serve 
//For example a vector iterator could be an ordinary pointer 
//because a pointer is quite a reasonable way of referring to 
//an element of vector:
//A vector iterator could an ordinary pointer(pointer 
//is a reasonable way of referring to an element of a vector):
//Alternatively, a vector iterator could be implemented as a pointer to the 
//vector plus an index :
//A list iterator is more complicated and could be a pointer to a link.

//common to all iterators is their semantics and the naming of their 
//operations 
//for example applying ++ to any iterator yields an iterator that refers 
//to the next element 
//* yields the element to which the iterator refers 


//Stream Iterators 
//notion of iterators applied to input and output 
//To make an os_stream itertor, we need to specify which stream will be 
//used and the type of objects written to it.
ostream_iterator<string> oo{cout};//write strings to cout 

//The effect of assigning to {*oo is to write strings to cout} For example:

int main()
{
    *oo ="Hello";  //meaning cout <<"Hello, "
    ++oo;
    *oo = "world!\n";  //meaning cout << "world!\n
}

//similarly an istream_iterator is something that allows us to treat an input stream as a readonly 
//container 
//Again we must specify the stream to be used and 
//the types of values expected 
istream_iterator<string> ii{cin};

//Input iterators are used in pairs representing a sequence
//so we must provide an istream_iteror to indicate the end of an input 
//This is the default istream_iterator:

int main() {
    string from, to;
    cin >> from >> to;  //get source and target files names 

    ifstream is {from};  //input stream for file "from"
    istream_iterator<string> ii {is}; //input iterator for stream
    istream_iterator<string> eos {}; //input sentinel

    ofstream os{to};  //output stream for file "to"
    ostream_iterator<string> oo{os, "\n"}; //output iterator for stream

    vector<string> b {ii, eos};  //b is a vector initialized from input files [ii:eos]
    sort(b.begin(), b.end(), oo);  //sort the buffer 

    unique_copy(b.begin(), b.end(), oo);  //copy the buffer to output , discarded replicated values
    return !is.eof() || !os;  //copy buffer to ouput
}

//An ifstream is an istream that can be attached to a file, and an ofstream is an 
//ostream that can be attached to a file. The ostream_iterator second argument is used to 
//delimit output values.

//we read string into vector and we sort them. and then we writeb
//them out, eliminating duplicates. 

//A more elegant solution is not to store duplicates atall 
//This can be done by keeping the strings in a set, which does 
//keep duplicates and keeps its element in order. 
//that way we could replace the two lines using a vector with one using a set and replace 
//unique_copy with the simpler copy()
set<string> b {ii, eos}; //coillect strings from input 
copy(b.begin(), b.end(), oo); //copy buffer to output

//we used the names ii, eos and oo only once so we  could further reduce the size of 
//the program

int main()

{
    string from, to;
    cin >> from, to;    //get source target file names 

    ifstream is {from };  //input stream for file names 
    ofstream os {to};    //output stream for file 

    set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}}; //read input
    copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});  //copy to output 
    return !is.eof() || !os;  //return error state 
}

//Predicates 
//algorithms have built -in action 
//for the problem we are solving 
//however we oftem want to make the action a parameter to the algorithm 

//A map allows us to access its elements as a sequence of (key, value)
//so we can search a map <string, int>> sequence for a pair <const, string>
//where the int is greater than 42:

void f(map<string, int>& m)
{
    auto p = find_if(*m.begin, m.end, Greater_than{42});
    //..
}
//Here, Greater_than is a function object holding the value to be compared
struct Greater_than {
    int val;
    Greater_than(int v) : val{v} {}
    bool operator()(const pair<string, int> &r ) {return r.second> val};
}
//Alternatively we could use a lambda expression
int cxx = count_if(m.begin(), m.end(), [(const pair<string, int>&)]);

