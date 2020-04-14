class TreeNode:
    def __init__(self, value= None, color = 'Black', parent= None, left= None, right= None):
        self.Value = value
        self.Parent = parent
        self.Left = left
        self.Right = right
        self.Color = color

def compare(Node1, Node2):
    if Node1 == None or Node2 == None:
        return True
    elif Node1.Value == Node2.Value:
        return True
    else:
        return False


def Left_Rotate(Tree, Node):
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

def Right_Rotate(Tree, Node):
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

def Color_Fixer(Tree, Node):
    to_fix = Node
    while to_fix.Parent.Color == 'Red':
        #case 1
        if compare(to_fix.Parent, to_fix.Parent.Parent.Left):
            pointer = to_fix.Parent.Parent.Right
            if pointer.Color == 'Red':
                to_fix.Parent.Color = 'Black'
                pointer.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
            
            elif compare(to_fix, to_fix.Parent.Right):
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
            
            elif compare(to_fix, to_fix.Parent.Left):
                #Case 2 Symmettric:
                to_fix = to_fix.Parent
                Right_Rotate(Tree, to_fix)
                #Case 3 Symmettric:
                to_fix.Parent.Color = 'Black'
                to_fix.Parent.Parent.Color = 'Red'
                Left_Rotate(Tree, to_fix.Parent.Parent)
    Tree.rootNode.Color = 'Black'

def Delete_Fixer(Tree, Node):
    to_fix = Node
    while not compare(to_fix, Tree.rootNode) and to_fix.color == 'Black':
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

            elif pointer.Right.Color == 'Black':
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
            elif pointer.Left.Color == 'Black':
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
        Pointer = None
        Pointer2 = self.rootNode
        #loopcounter = 0
        while not compare(Pointer2, self.Sentinel):
            #print('Loop Number', loopcounter)
            #print('Pointer value', Pointer2.Value)
            Pointer = Pointer2
            if value < Pointer2.Value:
                Pointer2 = Pointer2.Left
            else:
                Pointer2 = Pointer2.Right
            #loopcounter += 1

        insert = TreeNode(value)
        insert.Parent = Pointer
        insert.Left = self.Sentinel
        insert.Right = self.Sentinel
        if Pointer == None:
            self.rootNode = insert
        elif insert.Value < Pointer.Value:
            Pointer.Left = insert
        else:
            Pointer.Right = insert
        insert.Color = 'Red'
        Color_Fixer(self, insert)

    def Maximum(self):
        Pointer = None
        Pointer2 = self.rootNode
        while not compare(Pointer2, self.Sentinel):
            Pointer = Pointer2
            Pointer2 = Pointer2.Right
        return Pointer.Value

    def Minimum(self):
        Pointer = None
        Pointer2 = self.rootNode
        while not compare(Pointer2, self.Sentinel):
            Pointer = Pointer2
            Pointer2 = Pointer2.Left
        return Pointer.Value


"""
    def Delete_Node(self, Node):
        to_delete = self.Node
        pointer = self.Node
        og_color_pointer = pointer.Color
        if compare(to_delete.Left, self.Sentinel):
            pointer2 = to_delete.Right

"""


tree = RedBlackTree(5)
a = TreeNode(3, 'Red')
b = TreeNode(7, 'Red')

tree.rootNode.Left = a
tree.rootNode.Right = b
a.Parent = tree.rootNode
b.Parent = tree.rootNode
a.Left = tree.Sentinel 
a.Right = tree.Sentinel
b.left = tree.Sentinel
b.right = tree.Sentinel

print(tree.rootNode.Value)
print(tree.Sentinel.Value)
print(tree.rootNode.Left.Value)
print(tree.rootNode.Right.Value)
print(tree.Maximum(), tree.Minimum())
tree.insert(9)
tree.insert(1)
print(tree.Maximum(), tree.Minimum())
