#DISCLAIMER! I am using previous insted of next because next in a stack does not make sense


class StackNode:
    def __init__(self, data = None, prevNode = None):
        self.Data = data
        self.Prev = prevNode 

class Stack:
    def __init__(self, size = -1):
        self.Size = size
        self.Top = None
        if self.Size != -1:
            self.Current_Size = 0
    
    def push(self, data):
        
        if (self.Size == -1):
            new = StackNode(data)
            new.Prev = self.Top
            self.Top = new
       
        elif self.Size != -1 and self.Current_Size < self.Size:
            new = StackNode(data)
            new.Prev = self.Top
            self.Top = new
            self.Current_Size += 1

        else:
            print("Overflow")
        return

    def pop(self):
        if self.Top == None:
            print("Underflow")
        
        else:
            temporary = self.Top.Data
            self.Top = self.Top.Prev
            if self.Size != -1:
                self.Current_Size -= 1
            
            return temporary

    def isEmpty(self):
        if self.Top == None:
            return True

        else:
            return False

    def isFull(self):
        if self.Current_Size == self.Size:
            return True
        
        else:
            return False

class Queue:
    def __init__(self, size):
        self.Input_Stack = Stack(size)
        self.Output_Stack = Stack(size)
    
    def push(self, data):
        if self.Input_Stack.isFull():
            print("Queue is full")
        
        elif not (self.Output_Stack.isEmpty()):
            if self.Input_Stack.Current_Size + self.Output_Stack.Current_Size ==  self.Input_Stack.Size:
                print("Queue is full")

            else:
                self.Input_Stack.push(data)        

        else:
            self.Input_Stack.push(data)
            if self.Input_Stack.isFull():
                for i in range(self.Input_Stack.Size):
                    self.Output_Stack.push(self.Input_Stack.pop())

    def pop(self):
        if self.Output_Stack.isEmpty() and self.Input_Stack.isEmpty():
            print("Queue is empty")

        elif self.Output_Stack.isEmpty():
            for i in range(self.Input_Stack.Current_Size):
                self.Output_Stack.push(self.Input_Stack.pop())

            temp = self.Output_Stack.pop()
            print('Popping', temp)
            return temp

        else:
            temp = self.Output_Stack.pop()
            print('Popping', temp)
            return temp



# I assume that a tree structure has already been given to me.
# I do not feel like expecting em to implement all tree  methods 
# and then another additional function for 4 points in realistic

class TreeNode:
    def __init__(self):
        self.Value = None
        self.Parent = None
        self.Left = None
        self.Right = None

class Tree:

    def __init__(self):
        self.Root = TreeNode()

    def minimum(self): #This is a one time use minimum function
        pointer = self.Root
        while pointer.Left != None:
            pointer = pointer.Left

        #Insert function to delete leaf. I am not implementing this
        temp = pointer.Value
        return temp
    
    
def Listifier(A):
    list = Stack()
    list.push(A.minimum())






a = Queue(5)

a.push(3)
a.push(4)
a.push(5)
a.pop()
a.push(6)
a.push(7)
a.push(8)
a.push(9)

for i in range(a.Input_Stack.Size):
    a.pop()
