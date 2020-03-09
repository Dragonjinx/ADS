#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>
#include "Fiboimp.h"

//Prints the difference in seconds
void print_time(std::ostream& out, std::chrono::duration <double, std::ratio<1L, 1000L>> differnce)
{
    out <<  (differnce).count() << std::endl;
}

std::chrono::time_point<std::chrono::steady_clock> time_now()
{
    return std::chrono::steady_clock::now();
}


int main()
{
    using namespace std::chrono_literals;
    typedef std::chrono::duration <double, std::ratio<1L, 1000l>> mili;
    std::ofstream Output("N_and_time", std::ios::out);
    auto start = time_now();
    // sleep_for(10ms);
    auto end = time_now();
    mili difference =  end - start;
  
   
    Matrix A;
    int CheckN[15] = {1, 2, 3, 5, 7, 10, 15, 20, 27, 34, 41, 47, 61, 76, 91};
    std::chrono::duration <double, std::ratio <1L, 1000L>> Static_Duration = 10000ms;
    // std::cout << "Works here" << Fib_Bottom(10) << std::endl;
    // Begin execution loop
   
    Output << "Closed form computations: " << std::endl;
    for(int i = 0; i < 15; i++)
    {
        start = time_now();
        Fib_Closed(CheckN[i]);
        end = time_now();
        difference = end - start;
        print_time(std::cout, difference);
        if( (difference).count() > Static_Duration.count())
        {
            std::cout << CheckN[i] << "th computation in " << (difference).count() << " Miliseconds" << std::endl;
            break;
        }
        Output << CheckN[i] << "   " << (difference).count() << " miliseconds" << std::endl;
    }
    Output << std::endl;

    Output << "Matrix Method computations: " << std::endl;
    for(int i = 0; i < 15; i++)
    {
        start = time_now();
        Fib_Mat(CheckN[i], A);
        end = time_now();
        difference = end - start;
        print_time(std::cout, difference);
        if( (difference).count() > Static_Duration.count())
        {
            std::cout << CheckN[i] << "th computation in " << (difference).count() << " Miliseconds" << std::endl;
            break;
        }
        Output << CheckN[i] << "   " << (difference).count() << " miliseconds" << std::endl;
    }
    Output << std::endl;

    Output << "Bottom up computations: " << std::endl;
    for(int i = 0; i < 15; i++)
    {
        start = time_now();
        Fib_Closed(CheckN[i]);
        end = time_now();
        difference = end - start;
        print_time(std::cout, difference);
        if( (difference).count() > Static_Duration.count())
        {
            std::cout << CheckN[i] << "th computation in " << (difference).count() << " Miliseconds" << std::endl;
            break;
        }
        Output << CheckN[i] << "   " << (difference).count() << " miliseconds" << std::endl;
    }
    Output << std::endl;
    
    Output << "Naive computations: " << std::endl;
    for(int i = 0; i < 15; i++)
    {
        start = time_now();
        Fib_Naive(CheckN[i]);
        end = time_now();
        difference = end - start;
        print_time(std::cout, difference);
        if( (difference).count() > Static_Duration.count())
        {
            std::cout << CheckN[i] << "th computation in " << (difference).count() << " Miliseconds" << std::endl;
            break;
        }
        Output << CheckN[i] << "   " << (difference).count() << " miliseconds" << std::endl;
    }
    Output << std::endl;
    Output.close();
    return 0;
}

    /*
    start = time_now();
    std::cout << "10 th fib number = " << Fib_Bottom(90) << std::endl;
    end = time_now();
    difference =  end - start;
    std::cout << "Bottom up runtime: ";
    print_time(std::cout, difference);
    start = time_now();
    std::cout << "10 th fib number = " << Fib_Closed(90) << std::endl;
    end = time_now();
    difference =  end - start;
    std::cout << "Closed form runtime: ";
    print_time(std::cout, difference);

    start = time_now();
    std::cout << "10 th fib number = " << Fib_Mat(90, A) << std::endl;
    end = time_now();
    difference =  end - start;
    std::cout << "Matrix method runtime: ";
    print_time(std::cout, difference);
    */
