#include <vector>
#include <iostream>

int main()
{
    std::string Input; // Storing user inpput line
    std::vector<std::string> Container; // Vector container for all input
    //Loop for user input:
    while(1)
    {
        getline(std::cin, Input);
        
        if(Input == "END") // "END" break condition
        {
            break;
        }
        Container.push_back(Input); // Adding user input to end of vector
    } 

    // Swapping 2nd and 5th elements if they exist.
    if(Container.size() >= 5)
    {
        std::string Cache;
        Cache = Container[1];
        Container[1] = Container[4];
        Container[4] = Cache;
    }

    //Replacing last element with "???"
    Container.pop_back();
    Container.push_back("???");

    std::vector<std::string>::iterator GoThrough = Container.begin(); // Declaration of vector iterator
    // Printing with commas
    while(1) 
    {
        std::cout << *GoThrough;
        GoThrough++;
        if(GoThrough == Container.end())
        {
            break;
        }
        std::cout<< ", ";
    }
    std::cout << std::endl;
    

    GoThrough = Container.begin();
    // Printing with semi-colons
    while(1) 
    {
        std::cout << *GoThrough;
        GoThrough++;
        if(GoThrough == Container.end())
        {
            break;
        }
        std::cout<< "; ";
    }
    std::cout << std::endl;
    
    GoThrough = Container.end();
    // Printing in reverse
    while(1) 
    {
        GoThrough--;
        std::cout << *GoThrough;
        if(GoThrough == Container.begin())
        {
            break;
        }
        std::cout<< " "; 
    }
    std::cout << std::endl;
    return 0;
}