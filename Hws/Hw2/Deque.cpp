#include <iostream>
#include <deque>

// Fuction to print deque A with elements seperated by char C
void printqueue(std::deque<float> &A, char c)
{
    std::deque<float>::iterator iter;
    for (iter = A.begin(); iter != A.end();)
    {
        std::cout << *iter;
        iter++;
        if ( iter == A.end())
        {
            break;
        }
        else if (c != ' ')
        {
            std::cout << c << ' ';
        }
        else
        {
            std::cout << c;
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<float> A;
    float input;
    do
    {
        std::cin >> input;
        if (input > 0)
        {
            A.push_back(input);
        }
        else if (input < 0)
        {
            A.push_front(input);
        }

    } while (input != 0);

    printqueue(A, ' ');
    std::cout << std::endl;

    std::deque<float>::iterator index_for_Zero; // Stores the index to add 0 to
    std::deque<float>::iterator iter;
    for (iter = A.begin(); iter != A.end();)
    {
        index_for_Zero = iter;
        if (*(iter++) > 0)
        {
            break;
        }
    }
    A.insert(index_for_Zero, 0);

    printqueue(A, ';');
    return 0;
}