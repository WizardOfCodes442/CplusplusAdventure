//By defining  constructors, copy operations,m move operations, and a destructor 
// a programmer can provide complete control of the lifetime of a contained resource 
// such as elements of container
// a move constructor allows an object to move simply and cheaply from 
//one scope to another 

//consider a standard library thread representing a concurrent activity 
//and a Vector of a million doubles 
//we can't r formalk and we don't want to copy the later 

std::vector<thread> my_threads;

Vector init(init n)
{
    thread t {heartbeat};        //run heartbeat concurrently (on its own thread)
    my_threads.push_back(move(t)); // move t into my_threads

    Vector vec(n);
    for (int i = 0; i < vec.size(); ++) vec[i] =777;
    return vec;
}

auto v = init();  //start the heartbeat and initialize v 

//this makes resource handles, such as Vector and thread, an alternative to using pointers
//the standard library such as unique_ptr are themselves resource handles 