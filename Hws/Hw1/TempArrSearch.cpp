#include <iostream>

class Complex
{
private:
    double real;      //Real part of the complex number
    double imaginary; // Imaginary Part of the complex number

public:
    // Empty constructor. Sets all to 0
    Complex()
    {
        real = 0;
        imaginary = 0;
    }
    // Parametric constructor (double, double)
    Complex(double a, double b)
    {
        real = a;
        imaginary = b;
    }
    // Destructor
    ~Complex(){}

    // Overloading "=="
    bool operator ==(const Complex&a)
    {
        if(this->real == a.real && this->imaginary == a.imaginary)
        {
            return true;
        }
        return false;
    }
    
    //Overloading "<<"
    friend std::ostream& operator <<(std::ostream& out, const Complex& Obj)
    {
        out<< Obj.real << " + " << Obj.imaginary << "i";
        return out;
    }
};


template <class T>
int array_search(T arr[], int a, T b)
{
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == b)
        {
            return i+1;
        }
    }
    return -1;
}

template <class T>
void printArr(T* arr, int size)
{
    for(int i =0; i < size; i++)
    {
        std::cout<< arr[i] << " ";
    }
    std::cout<< std::endl;
}

int main()
{
    int Arr1[] = {1, 2, 3, 4, 5, 6, 7};
    double Arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.9, 7,7};
    Complex a(4, 20);
    Complex b(6, 9);
    Complex c(9, 6);
    Complex Arr3[] = {a, b, c};
    std::cout << "Array1:" << std::endl;
    printArr(Arr1, 7);
    std::cout << "3 is in position: "<< array_search(Arr1, 7, 3) << std::endl;
    std::cout << "Array2:" << std::endl;
    printArr(Arr2, 7);
    std::cout<< "6.9 is in position: " << array_search(Arr2, 7, 6.9) << std::endl;
    std::cout << "Array3:" << std::endl;
    printArr(Arr3, 3);
    std::cout << c << " is in position: " << array_search(Arr3, 3, c) << std::endl;
    return 0;    
}