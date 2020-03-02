#include <iostream>
#include <fstream>
#include <list>

int main()
{

    int input;
    std::list<int> A;
    std::list<int> B;
    //Loop to add into the lists
    do
    {
        std::cin >> input;
        A.push_back(input);
        B.push_front(input);

    } while (input > 0);

    // Loop to print list A
    std::list<int>::iterator iterate;
    for(iterate = A.begin(); iterate != A.end();)
    {
        std::cout << *iterate;
        if(iterate++ == A.end())
        {
            break;
        }
        std::cout<< ' ';
    }
    std::cout<<std::endl;

    // Loop to print B to file
    std::ofstream file_for_B; // Declaring an ifstream object
    file_for_B.open("listB.txt", std::ios_base::out); // Opeaning file in write mode
    for(iterate = A.begin(); iterate != A.end();)
    {
        file_for_B << *iterate;
        if(iterate++ == B.end())
        {
            break;
        }
        file_for_B<< ' ';
    }
    file_for_B << std::endl;
    std::cout << std::endl;

    // Putting first element into last
    int temp;
    temp = A.front();
    A.pop_front();
    A.push_back(temp);
    temp = B.front();
    B.pop_front();
    B.push_back(temp);
    
    std::list<int>::iterator Iterate2;
    // Loop to print
    for(iterate = A.begin(), Iterate2 = B.begin(); (iterate != A.end()) && (Iterate2 != B.end());)
    {
        std::cout << *iterate << ", " << *Iterate2;
        iterate++;
        Iterate2++;
        if(Iterate2 == B.end())
        {
            break;
        }
        std::cout<< ", ";
    }
    std::cout << std::endl;

    // Loop to merge B into A
    for(iterate = B.begin(); iterate != B.end();)
    {
        A.push_back(*iterate);
        if(iterate++ == B.end())
        {
            break;
        }
    }
    
    // Look to print merged A
    for(iterate = A.begin(); iterate != A.end(); iterate++)
    {
        std::cout << *iterate << ' ';
    }
    std::cout<<std::endl;
    return 0;
}
