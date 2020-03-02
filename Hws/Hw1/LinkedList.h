template <class T>
class Node // Node class for the list
{
public:
    T element; // Storage for element
    Node * next; // Pointer to next member
    Node * previous; // Pointer to previous member
    
    // Empty constructor
    Node()
    {
        next = nullptr;
        previous = nullptr;
    }

    // Constructor with element only
    Node(T nelem)
    {
        element = nelem;
        next = nullptr;
        previous = nullptr;
    }
    
    // COnstructor with pointers only
    Node(Node* nNext, Node* nPrev)
    {
        next = nNext;
        previous = nPrev;
    }

    // Full Parametric constructor
    Node(T nelem, Node* nNext, Node* nPrev)
    {
        element = nelem;
        next = nNext;
        previous = nPrev;
    }

    // Sets element
    bool setElem(T nElem)
    {
        element = nElem;
        return true; 
    }

    // Sets next node
    bool setNext(Node* nNext)
    {
        next = nNext;
        return true;
    }

    // Sets Previous node
    bool setPrev(Node* nPrev)
    {
        previous = nPrev;
        return true;
    }
};


template <class T, template <class> class N>
class Dlist // Class for list
{
private:
    N<T>* begining; // Pointer to start of the list
    N<T>* end; // Pointer to end of the list
    int elements; // Number of elements in the list

public:
    
    // Empty Constructor
    Dlist()
    {
        begining = nullptr;
        end = nullptr;
        elements = 0;
    }

    // Parametric constructor with elements
    Dlist(T nElem)
    {
        begining = new N<T>;
        begining->setElem(nElem);
        begining->setNext(nullptr);
        begining->setPrev(nullptr);
        end = begining;
        elements = 1;
    }

    // Paramteric constructor with initial node 
    Dlist(N<T> &nNode)
    {
        begining = &nNode;
        end = begining;
        elements = 1;
    }

    // Destructor
    ~Dlist()
    {
        N<T> *intermediate;
        if(elements == 1)
        {
            delete begining;
        }
        else if(elements == 2)
        {
            delete begining;
            delete end;
        }
        else
        {
            while (begining != nullptr && end != nullptr)
            {
                intermediate = begining->next;
                delete begining;
                begining = intermediate;
            }
            
        }
        
    }

    // Returns the number of elements
    int getElems()
    {
        return elements;
    }

    // Returns the front element
    T Front()
    {
        return begining->element;
    }

    // Adds element to the front of the list
    bool pushFront(T nELem)
    {
        std::cout << "Pusing front: " << nELem << std::endl;
        N<T>* nNode = new N<T>;
        nNode->setNext(begining);
        nNode->setPrev(nullptr);
        nNode->setElem(nELem);
        begining->previous = nNode;
        begining= nNode;
        elements++;
        return true;
    }

    // Removes element from the front of the list
    void popFront(T& output)
    {
        if(elements == 0)
        {
            std::cout << "Empty" << std::endl;
            return;
        }
        N<T>* intermediate;
        T toReturn;
        intermediate = begining->next;
        toReturn = begining->element;
        elements --;
        delete begining;
        begining = intermediate;
        output = toReturn;
    }


    // Returns last element
    T Back()
    {
        return end->element;
    }

    // Adds element to the end of the list
    void pushBack(T Nelement)
    {
        std::cout << "Pushing back: " << Nelement << std::endl;
        N<T>* newNode = new N<T>;
        newNode->setNext(nullptr);
        if(elements == 0)
        {
            newNode->setPrev(nullptr);
            newNode->setNext(nullptr);
            begining = newNode;
            end = newNode;
            newNode->setElem(Nelement);
            return;
        }
        newNode->setPrev(end);
        newNode->setElem(Nelement);
        end->next = newNode;
        end = newNode;
        elements ++;
    }

    // Removes element from the end of the list
    void popBack(T& output)
    {
        if(elements == 0)
        {
            std::cout << "Empty" << std::endl;
            return;
        }
        N<T>* intermediate;
        T toReturn;
        intermediate = end->previous;
        toReturn = end->element;
        elements --;
        delete end;
        end = intermediate;
        output = toReturn;
    }

};
