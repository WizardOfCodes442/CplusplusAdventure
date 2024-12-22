//To achieve resolution i.e to select the right function to call at runtime
//when a function is using derived types of abstract types 
// or interface as an argument; The usual implementation is for compilers 
//to convert the name of a virtual function into an index table of pointers
//to function. That table is usually called the virtual function table or simply the vtbl.
//Each class with a virtual function has its own vtbl identifying its virtual functions 
//The functions in the vtbl allow the object tpo be used correctly even when the size of the 
//object and the layout of its data are unknown to the caller. 
//The implemtation of the caller needs only to know the location of the pointer to the 
//vtbl in a Container and the index is used for each Virtual function 