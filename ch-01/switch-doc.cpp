#include <iostream>


bool accept2()
{
    std::cout << "Do you want to proceed(y or no)?\n";    //write a question

    char answer = 0;
    std::cin >> answer;

    switch(answer) {
        case 'y':
            return true;
        case 'n': 
            return false;
        default:
            std::cout <<"I'll  take that as a no.\n";
            return false; 

    }
}

bool accept3() 
{
    int tries = 1;
    while(tries < 4) {
        std::cout<<"Do you want to proceed(y or no)?\n";   //write a question 
        char answer = 0;
        std::cin >> answer;               //read answer

        switch(answer) {
            case 'y':
                return true;
            case 'n':
                return false;

            default:
                std::cout << "Sorry, I don't understand that. \n";
                ++tries; 
        }
    }
    std::cout << "I'll that for a no.\n";
    return false;
}