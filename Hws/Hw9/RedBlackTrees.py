class TreeNode:
    def __init__(self, value= None, color = 'Black', parent= None, left= None, right= None):
        self.Value = value
        self.Parent = parent
        self.Left = left
        self.Right = right
        self.Color = color

def compare(Node1, Node2):
    #print('Comparing N1', Node1.Value, 'and N2', Node2.Value)
    if Node1 == None or Node2 == None:
        return True
    elif Node1.Value == Node2.Value:
        return True
    else:
        return False

def RB_Transplant(Tree, Node1, Node2):
    if compare(Node1.Parent, Tree.Sentinel):
        Tree.rootNode = Node2

    elif compare(Node1, Node1.Parent.Left):
        Node1.Parent.Left = Node2
    else:
        Node1.Parent.Right = Node2
    Node2.Parent = Node1.Parent
    
def Maximum_From_Node(Tree, Node):
    Pointer = Node
    while not compare(Pointer.Right, Tree.Sentinel):
        Pointer = Pointer.Right
    return Pointer

def Minimum_From_Node(Tree, Node):
    Pointer = Node
    while not compare(Pointer.Left, Tree.Sentinel):
        Pointer = Pointer.Left
    return Pointer


def Left_Rotate(Tree, Node):
    print('Begin Left Rotate')
    to_switch = Node
    pointer = to_switch.Right
    to_switch.Right = pointer.Left
    if not compare(pointer.Left, Tree.Sentinel):
        pointer.Left.Parent = to_switch
    pointer.Parent = to_switch
    if compare(to_switch.Parent, Tree.Sentinel):
        Tree.rootNode = pointer
    elif compare(to_switch, to_switch.Parent.Left):
        to_switch.Parent.Left = pointer
    else:
        to_switch.Parent.Right = pointer
    pointer.Left = to_switch
    to_switch.Parent = pointer
    print('End Left Rotate')


def Right_Rotate(Tree, Node):
    print('Begin right rotate')
    to_switch = Node
    pointer = to_switch.Left
    to_switch.Left = pointer.Right
    if not compare(pointer.Right, Tree.Sentinel):
        pointer.Right.Parent = to_switch
    pointer.Parent = to_switch
    if compare(to_switch.Parent, Tree.Sentinel):
        Tree.rootNode = pointer
    elif compare(to_switch, to_switch.Parent.Right):
        to_switch.Parent.Right = pointer
    else:
        to_switch.Parent.Left = pointer
    pointer.Right = to_switch
    to_switch.Parent = pointer
    print('End Right Rotate')

def Color_Fixer(Tree, Node):
    print('Beginning Color Fix')
    to_fix = Node
    while to_fix.Parent.Color == 'Red':
        #case 1
        if compare(to_fix.Parent, to_fix.Parent.Parent.Left):
            pointer = to_fix.Parent.Parent.Right
            if pointer.Color == 'Red':
                to_fix.Parent.Color = 'Black'
                pointer.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
                to_fix = to_fix.Parent.Parent
            
            else:
                if compare(to_fix, to_fix.Parent.Right):
                    #Case 2:
                    to_fix = to_fix.Parent
                    Left_Rotate(Tree, to_fix)
                #Case 3:
                to_fix.Parent.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
                Right_Rotate(Tree, to_fix.Parent.Parent)
        #Case 1 Symmettric
        else:
            pointer = to_fix.Parent.Parent.Left
            if pointer.Color == 'Red':
                to_fix.Parent.Color = 'Black'
                pointer.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
                to_fix = to_fix.Parent.Parent
            
            else:
                if compare(to_fix, to_fix.Parent.Left):
                    #Case 2 Symmettric:
                    to_fix = to_fix.Parent
                    Right_Rotate(Tree, to_fix)
                #Case 3 Symmettric:
                to_fix.Parent.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
                Left_Rotate(Tree, to_fix.Parent.Parent)
    Tree.rootNode.Color = 'Black'
    print('End Color Fix')

def Delete_Fixer(Tree, Node):
    to_fix = Node
    while not compare(to_fix, Tree.rootNode) and to_fix.Color == 'Black':
        if compare (to_fix, to_fix.Parent.Left):
            pointer = to_fix.Parent.Right
            if pointer.Color == 'Red':
                pointer.Color = 'Black'
                to_fix.Parent.Color = 'Red'
                Left_Rotate(Tree, to_fix.Parent)
                pointer = to_fix.Parent.Right
            
            if  (pointer.Left.Color == 'Black') and (pointer.Right.Color == 'Black'):
                pointer.Color = 'Red'
                to_fix = to_fix.Parent

            else:
                if pointer.Right.Color == 'Black':
                    #case 3
                    pointer.Left.Color = 'Black'
                    pointer.Color = 'Red'
                    Right_Rotate(Tree, pointer)
                    pointer = to_fix.Parent.Right

                #case 4
                pointer.Color = to_fix.Parent.Color
                to_fix.Parent.Color = 'Black'
                pointer.Right.Color = 'Black'
                Left_Rotate(Tree, to_fix.Parent)
                to_fix = Tree.rootNode

        else:
            pointer = to_fix.Parent.Left
            if pointer.Color == 'Red':
                pointer.Color = 'Black'
                to_fix.Parent.Color = 'Red'
                Right_Rotate(Tree, to_fix.Parent)
                pointer = to_fix.Parent.Left
            
            if  (pointer.Right.Color == 'Black') and (pointer.Left.Color == 'Black'):
                pointer.Color = 'Red'
                to_fix = to_fix.Parent
            else:
                if pointer.Left.Color == 'Black':
                    #case 3
                    pointer.Right.Color = 'Black'
                    pointer.Color = 'Red'
                    Left_Rotate(Tree, pointer)
                    pointer = to_fix.Parent.Left

                #case 4
                pointer.Color = to_fix.Parent.Color
                to_fix.Parent.Color = 'Black'
                pointer.Left.Color = 'Black'
                Right_Rotate(Tree, to_fix.Parent)
                to_fix = Tree.rootNode
    to_fix.Color = 'Black'


class RedBlackTree:
    def __init__(self, root):
        self.rootNode = TreeNode(root, 'Black')
        self.Sentinel = TreeNode('Sentinel', 'Black')
        self.rootNode.Parent = self.Sentinel
        self.rootNode.Right = self.Sentinel
        self.rootNode.Left = self.Sentinel

    def insert(self, value):
        print('Begenning insert')
        Pointer = None
        Pointer2 = self.rootNode
        #loopcounter = 0
        while not compare(Pointer2, self.Sentinel):
        #    print('Loop Number', loopcounter)
        #    print('Pointer value', Pointer2.Value)
            Pointer = Pointer2
            if value < Pointer2.Value:
        #        print("Going left")
                Pointer2 = Pointer2.Left
            else:
        #        print("Going Right")
                Pointer2 = Pointer2.Right
        #    loopcounter += 1
        #    print('Going to', Pointer2.Value)

        insert = TreeNode(value, 'Red')
        insert.Parent = Pointer
        insert.Left = self.Sentinel
        insert.Right = self.Sentinel
        if Pointer == None:
            self.rootNode = insert
        elif insert.Value < Pointer.Value:
            Pointer.Left = insert
        else:
            Pointer.Right = insert
        Color_Fixer(self, insert)
        print('End Insert')

    def Minimum(self):
        return Minimum_From_Node(self, self.rootNode)

    def Maximum(self):
        return Maximum_From_Node(self, self.rootNode)
    
    def successor(self, Node):
        if not compare(Node.Right, self.Sentinel):
            return Minimum_From_Node(self, Node.Right)
        
        else:
            pointer = Node.Parent
            while not compare(pointer, self.Sentinel) and compare(Node, pointer.Right):
                Node = pointer
                pointer = pointer.Parent
            
            return pointer

    def predecessor(self, Node):
        if not compare(Node.Left, self.Sentinel):
            return Maximum_From_Node(self, Node.Left)
        
        else:
            pointer = Node.Parent
            while not compare(pointer, self.Sentinel) and compare(Node, pointer.Left):
                Node = pointer
                pointer = pointer.Parent
            
            return pointer


    def Search(self, to_search):
        Pointer = None
        Pointer2 = self.rootNode
        #loopcounter = 0
        while not compare(Pointer2, self.Sentinel):
        #    print('Loop Number', loopcounter)
        #    print('Pointer value', Pointer2.Value)
            Pointer = Pointer2
            if to_search == Pointer2.Value:
                return Pointer
            elif to_search < Pointer2.Value:
        #        print("Going left")
                Pointer2 = Pointer2.Left
            else:
        #        print("Going Right")
                Pointer2 = Pointer2.Right
        #    loopcounter += 1
        return self.Sentinel
        
    def Delete_Node(self, Node):
        pointer = Node
        og_color_pointer = pointer.Color
        if compare(Node.Left, self.Sentinel):
            pointer2 = Node.Right
            RB_Transplant(self, Node, Node.Right)
        
        elif compare(Node.Right, self.Sentinel):
            pointer2 = Node.Left 
            RB_Transplant(self, Node, Node.Left)
        
        else:
            pointer = Minimum_From_Node(self, Node.Right)
            og_color_pointer = pointer.Color
            pointer2 = pointer.Right
            if compare(pointer.Parent,  Node):
                pointer2.Parent = pointer
            
            else:
                RB_Transplant(self, pointer, pointer.Right)
                pointer.Right = Node.Right
                pointer.Right.Parent = pointer
            
            RB_Transplant(self, Node, pointer)
            pointer.Left = Node.Left
            pointer.Left.Parent = pointer
            pointer.Color = Node.Color
        
        if og_color_pointer == 'Black':
            Delete_Fixer(self, Node)


tree = RedBlackTree(5)

print(tree.rootNode.Value)
print(tree.Sentinel.Value)
print(tree.Maximum().Value, tree.Minimum().Value)
tree.insert(4)
tree.insert(9)
tree.insert(10)
tree.insert(11)
tree.insert(3)
tree.insert(2)
tree.insert(13)
tree.insert(12)
tree.insert(16)
tree.insert(20)
tree.insert(21)
tree.insert(7)
print(tree.Search(5).Right.Left.Value)

print(tree.rootNode.Value)
print(tree.Maximum().Value, tree.Minimum().Value)
tree.Delete_Node(tree.Search(21))
print(tree.Search(20).Value)
print(tree.Maximum().Value, tree.Minimum().Value)

# The Delete function apparently delets the entire subtree because I can't find 20 anumore.
# The code was completely based off of the psudocode provided in the slides so I guess
# this is the expected outcome
# Crosschecked with this code that I found online which is suspiciously similar to the psudocode:
# https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/red-black-trees/red_black_tree.py#L71