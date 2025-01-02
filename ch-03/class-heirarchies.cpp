//The container example is a very simple example of class hierarchy. 
//A class hierarchy is a set of classes oredered in a latice created 
//by derivation.
//used for representing concepts having hierarchical relationship 
// A smiley is kind of circle, which is a kind of shape 
//Huge heirarchies with hundreds of classes, that are both deep 
// and wide are common 

#include <memory>
class Shape {
public:
    virtual Point center() const = o;  // pure virtual 
    virtual void move(Point to ) = 0;

    virtual void draw()  const = 0;      //draw on current "Canvas"
    virtual void rotate(int angle) = 0;

    virtual ~Shape(){}     //destructor 
}

//Given this definition we can write general functions 
//manipulating vectors of pointers to shapes.

void rotate_all(vector<Shape*>& v, int angle)  //rotate v's elements by angle degrees
{
    for (auto p:v)
        p->rotate(angle);
}

//To define a particular shapr, we must say that it is a shape and specify it's 
//particular properties (including its virtual functions );

class Circle : public Shape {
public: 
    Circle(Point p, int rr);  //constructor

    Point center() const {return x;}
    void move (Point to ) {x=to;}

    void draw() const;
    void rotate(int){}    //nice simple algorithm 

private: 
    Point x;  //center
    int r;    // radius
};

//building further now using Circle as a Baseclass
class Smiley : public Circle { // use the circle as the base for a face 
public: 
    Smiley(Point p, int r): Circle{p, r} mouth{nullptr} {}
    
    ~Smiley()
    {
        delete mouth;
        for (auto p: eyes) delete p;
    }

    void move(Point to);

    void draw() const;
    void rotate(int);

    void add_eye(Shape* s ) {eyes.push_back(s);}
    void set_mouth(Shape* s);
    virtual wink(int i);   //wink eye number i 

    //..

private:
    vector<Shape*>  eyes;   // usually two eyes
    Shape*  mouth;
    
}

//The push_back()  member function adds its argument to the vector (here, eyes )
//increasing the vector's size by one 
//we can now define Smiley::draw() using calls to Smiley's base and member's draw

void Smiley::draw()
{
    Circle::draw();
    for (auto p: eyes)
        p->draw();
    mouth->draw();
}

//classes in class heirarchies are different from short 
//concrete  classes used as local variables in that they
// tend to be allocated on the free store using new 
//for example, consider a function that reads data 
//describing shapes from an input stream and 
//construct appropriate Shape object

enum class Kind {circle, triangle, smiley};

Shape* read_shape(istream& is)  //read description from input stream 
{
    // ..read shape header from is and find its Kind k
    switch {
        case Kind::circle:
            //read circle data {Point, int} into p and r 
            return new Circle{p, r};
        case Kind::triangle:
            //read triangle data {Point, Point, Point } into p1, p2, p3
            return new Triangle{p1, p2, p3};
        case Kind::smiley:
            //read smiley data {Point, int, Shape, Shape} into p, r, e1, e2, and m 
            Smiley* ps = new Smiley{p, r};
            ps-> add_eye(e1);
            ps-> add_eye(e2);
            ps->set_mouth(m);
            return ps;
    }
}

//A program may use the shape reader like this:
void user()
{
    std::vector<Shape*> v;
    while(cin)
        v.push_back(read_shape(cin));
    draw_all(v);  //call draw() for each element
    rotate_all(v, 45);   // call rotate(45) for each elements.
    for (auto p : v) delete p;  //remember to delete elements 
}

// A user might fail to delete the pointer 
//returned by read_shape
//The owner of the container of Shape pointers might not delete 
//objects pointed to.

//functions returning a pointer allocated on the 
//free store are dangerous. 

//One solution to both problems is to return a standard-library 
//unique_ptr rather than a naked pointer and store unique_ptrs in the container

unique_ptr<Shape> read_shape(istream& is)  //read shape description from input stream 
{
    //read shape header from is and find its Kind k 

    switch(k) {
    case Kind::circle:
        //read circle data{Point, int} into p and r
        return unique_ptr<Shape>{new Circle{p, r}};

    //.. 
    }
}

void user() 
{
    vector<unique_ptr<Shape>> v;
    while (cin)
        v.push_back(read_shape(cin));
    draw_all(v);      //call draw() for each element
    rotate_all(v,45);   //cal rotate(45) for each element
}  //all Shapes implicitly destroyed 