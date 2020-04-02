class TreeNode:
    def __init__(self, value= None, color = 'Black', parent= None, left= None, right= None):
        self.Value = value
        self.Parent = parent
        self.Left = left
        self.Right = right
        self.Color = color


class RedBlackTree:
    def __init__(self, root):
        self.rootNode = TreeNode(root, 'Black')
    
    def Left_Rotate(Node):

    def Right_Rotate(Node):

    def Color_Fixer(self,Node):
        



    def insert(self, value):
        Pointer = None;
        Pointer2 = self.rootNode
        while Pointer2 != None:
            Pointer = Pointer2
            if value < Pointer2.Value:
                Pointer2 = Pointer2.Left
            else:
                Pointer2 = Pointer2.Right
        insert = TreeNode(value)
        insert.Parent = Pointer
        if Pointer == None:
            self.rootNode = insert
        elif insert.Value < Pointer.Value:
            Pointer.Left = insert
        else:
            Pointer.Right = insert
        insert.Color = 'Red'
        self.Color_Fixer(insert)




    def delete
