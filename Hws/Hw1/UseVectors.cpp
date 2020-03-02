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

    std::vector<std::string>::iterator GoThrough; // Declaration of vector iterator
    for(GoThrough = Container.begin(); GoThrough != Container.end(); GoThrough++) // For loop moving iterator from begenning of a vector to the end.
    {
        std::cout << *GoThrough << " ";
    }
    std::cout << std::endl;
    return 0;
}