#include <string>
using namespace std;

string compose(const string& name, const string& domain ) {
    return name + "@" + domain;
}

auto addr = compose("dmr", "bells-lab.com");

//simnple concatenation 
void m2 (string& s1, string& s2) 
{
    s1 += s2;
}

//A string is mutable and also allows subscripting operations 
string name = "Niels Stroustrup";

void m3()
{
    string s = name.substr(6,10);   //s = "Stroustrup"
    name.replace(0,5,  "nicholas");  // name becomes "nicholas Strousup"
    name[0] = toupper(name[0]); //name becomes "Nicholas "
}

//The substr operation returns a string that is a copy of the substring indicated 
//by it's arguments 
//The first argument is an index into the string (a position)
//and the second is the length of the desired substring. 

//The replace() operation replaces a substring with a value 

//Strings can be compared against eachother and string literals 
string incantation;

void respond(const string& answer) 
{
    if (answer == incantation) {
        //perform magic. 
    }
    else if  (answer  == "yes") {
        //..
    }
    //..
}

//The string library is described 