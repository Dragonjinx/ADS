template <class T>
class Stack
{
private:
    T *array; // Container for stack
    int elems; // Number of elements present in the stack
    int size; // Size of the stack

public:
    // Empty constructor
    Stack() 
    {
        array = new T[10];
        elems = 0;
        size = 10;
    }
    // Parametric constructor Stack(int)
    Stack(int sizze)
    {
        size = sizze;
        elems = 0;
        array = new T[size];
    }
    // Copy constructor
    Stack(const Stack &a)
    {
        if (a.size > size)
        {
            T *newArr = new T[a.size];
            for (int i = 0; i < a.size; i++)
            {
                newArr[i] = a.array[i];
            }
            delete[] array;
            array = newArr;
            size = a.size;
        }
        else
        {
            for (int i = 0; i < a.elems; i++)
            {
                array[i] = a.array[i];
            }
        }
        elems = a.elems;
    }

    // Destructor;
    ~Stack()
    {
        if(array != nullptr)
        {
            delete[] array;
        }
    }

    void extend()
    {
        T* newArr = new T(size * 2);
        for(int i= 0; i < elems; i++)
        {
            newArr[i] = array[i];
        }
        delete[] array;
        array = newArr;
    }

    // Adds elements to the end of the stack. Can expand the stack
    bool push(T element)
    {
        std::cout << "Pushing " << element << std::endl;
        if (elems == size)
        {
            this->extend();
        }
        elems++;
        array[elems - 1] = element;
        return true;
    }

    // Removes one element off the end of the stack
    bool pop(T &out)
    {
        if (elems == 0)
        {
            std::cout << "Empty" << std::endl;
            return false;
        }

        else
        {
            out = array[elems-1];
            elems--;
            T* newArr = new T(size);
            for(int i =0; i < elems; i++)
            {
                newArr[i] = array[i];
            }
            delete[] array;
            array = newArr;
        }
        return true;
    }

    // Returns the last element of the stack
    T back(void)
    {
        return array[elems];
    }
    // Returns the number of elements of the stack
    int getNumEntries()
    {
        return elems;
    }
    // Returns the stack size
    void printstack()
    {
        for(int i = 0; i < elems; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};