#include <cmath>
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

//Begin Fib Functions

long long int Fib_Naive(int n)
{
    if(n < 2)
    {
        return n;
    }
    else
    {
        return (Fib_Naive(n -1) + Fib_Naive(n-2));
    }
}   

long long int Fib_Bottom(int n)
{
    if(n < 2)
    {
        return n;
    }
    long long int Array[n + 1];
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