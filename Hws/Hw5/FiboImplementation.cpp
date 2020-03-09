#include <iostream>
#include <chrono>
#include <cmath>
/*
Algorithm for fibonachi
n = 1
n _2 = 1
n_3 = 1 + n_2
n = n_2
n_2 = n_3
*/
/* Format fot chrono:
auto start = std::chrono::stedy_clock::now();
code
auto end = std::chrono::stedy_clocl::end();
suto diff = end -start;
Printing:
cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
*/

class Matrix
{
public:
    long long int Array[2][2];
    Matrix(){Array[0][0] = 1, Array[0][1] =1, Array[1][0] =1, Array[1][1] = 0;}
    void operator=(Matrix A);
};

void Matrix::operator=(Matrix A)
{
    Array[0][0] = A.Array[0][0];
    Array[0][1] = A.Array[0][1];
    Array[1][0] = A.Array[1][0];
    Array[1][1] = A.Array[1][1];
}

Matrix operator*(Matrix A, Matrix B)
{
    Matrix M;
    M.Array[0][0] = (A.Array[0][0] * B.Array[0][0]) + (A.Array[0][1] * B.Array[1][0]);
    M.Array[0][1] = (A.Array[0][0] * B.Array[0][1]) + (A.Array[0][1] * B.Array[1][1]);
    M.Array[1][0] = (A.Array[1][0] * B.Array[0][0]) + (A.Array[1][1] * B.Array[1][0]);
    M.Array[1][1] = (A.Array[1][0] * B.Array[0][1]) + (A.Array[1][1] * B.Array[1][1]);
    return M;
}

Matrix Unlimited_Power(Matrix A, int n)
{
    if(n == 2)
    {
        return A * A;
    }
    else if (n > 2 && (n%2 == 0))
    {
        return (Unlimited_Power(A, n/2) * Unlimited_Power(A, n/2));
    }
    else if (n > 2 && (n%2 != 0))
    {
        return (A * Unlimited_Power(A, n/2) * Unlimited_Power(A, n/2));
    }
    else
    {
        return A;
    }
    
}


//Prints the difference in seconds
void print_time(std::ostream& out, std::chrono::duration <double, std::ratio<1L, 1000L>> differnce)
{
    out <<  (differnce).count() << std::endl;
}

std::chrono::time_point<std::chrono::steady_clock> time_now()
{
    return std::chrono::steady_clock::now();
}

//Begin Fib Dunctions

long long int Fib_Native(int n)
{
    if(n < 2)
    {
        return n;
    }
    else
    {
        return (Fib_Native(n -1) + Fib_Native(n-2));
    }
}   

long long int Fib_Bottom(int n)
{
    if(n < 2)
    {
        return n;
    }
    long long int* Array = new long long int(n + 1);
    Array[0] = 0, Array[1] = 1, Array[2] = 1;
    for(int i = 3; i < n + 1; i++)
    {
        Array[i] = Array[i-1] + Array[i-2];
    }
    return Array[n];
}

long long int Fib_Closed(int n)
{
    long long int value = round(pow(((1 + sqrt(5)) / 2), n) / sqrt(5));
    return value;
}

long long int Fib_Mat(int n, Matrix A)
{
    Matrix M = Unlimited_Power(A, n-1);
    return M.Array[0][0];
}

int main()
{
    using namespace std::chrono_literals;
    auto start = time_now();
    auto end = time_now();
    auto difference =  end - start;
    print_time(std::cout, difference);
    Matrix A;
    // A = A * A * A * A; 
    // std::cout << "10 th fib number = " << Fib_Native(20) << std::endl;
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
    return 0;
}

