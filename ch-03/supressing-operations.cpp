//Using  the default vopy or move for a class 
//is typical a disater 
//So the best thing is to delete the the default copy and move 
//operations, that is , to eliminate the default defintions 
//of those  two operations 

class Shape {
public:
    Shape(const Shape&) = delete;    //no copy operations 
    Shape& operator=(const Shape&) = delete;

    Shape(Shape&& )  = delete;       // no move 
    Shape& operator=(Shape&&) = delete;

    ~Shape();

    //..
};

//now an attempt to copy a Shape will be   caught by the compiler
//if you need to copy an object in a class hierarchy, write some kind of clone function 

//The =delete mechanism is general that is, it can be used to suppress any operation

