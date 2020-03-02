#include <iostream>
#include <map>
#include <fstream>

int main()
{
    std::map<std::string, std::string> Container; // Storage for all Data from file 
    std::ifstream file; // File Object
    std::string Input; // Storing user input
    file.open("data.txt", std::ios::in); // Opeaninbg the input file
    std::string Name;
    std::string Birthday;
    // Loop to store file input into container
    while (!file.eof())
    {
        getline(file, Name);
        // std::cout << "Adding " << Name << std::endl; // Debugging
        getline(file, Birthday);
        Container[Name] = Birthday;
    }
    
    while(Input != "EXIT")
    {
        getline(std::cin, Input);
        if(Container.count(Input))
        {
            std::cout << Container[Input] <<std::endl;
        }
        else
        {
            std::cout <<"Name not found" <<std::endl;
        }      
    }    

    return 0;
}