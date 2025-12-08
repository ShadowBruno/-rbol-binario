class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

def preOrder(node):
    if node is None:
        return
    print(node.value, end=" ")
    preOrder(node.left)
    preOrder(node.right)

def inOrder(node):
    if node is None:
        return
    inOrder(node.left)
    print(node.value, end=" ")
    inOrder(node.right)

def postOrder(node):
    if node is None:
        return
    postOrder(node.left)
    postOrder(node.right)
    print(node.value, end=" ")

def height(node):
    if node is None:
        return 0
    return node.height

def get_balance(node):
    if node is None:
        return 0
    return height(node.left) - height(node.right)

def right_rotate(z):
    y = z.left
    T3 = y.right

    y.right = z
    z.left = T3

    z.height = 1 + max(height(z.left), height(z.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y

def left_rotate(z):
    y = z.right
    T2 = y.left

    y.left = z
    z.right = T2

    z.height = 1 + max(height(z.left), height(z.right))
    y.height = 1 + max(height(y.left), height(y.right))

    return y

def insert(root, value):
    if root is None:
        return Node(value)

    if value < root.value:
        root.left = insert(root.left, value)
    elif value > root.value:
        root.right = insert(root.right, value)
    else:
        return root

    root.height = 1 + max(height(root.left), height(root.right))
    balance = get_balance(root)

    if balance > 1 and value < root.left.value:
        return right_rotate(root)

    if balance < -1 and value > root.right.value:
        return left_rotate(root)

    if balance > 1 and value > root.left.value:
        root.left = left_rotate(root.left)
        return right_rotate(root)

    if balance < -1 and value < root.right.value:
        root.right = right_rotate(root.right)
        return left_rotate(root)

    return root


root = Node('R')
root.left = Node('A')
root.right = Node('B')
root.left.left = Node('C')
root.left.right = Node('D')
root.right.left = Node('E')
root.right.right = Node('F')
root.right.right.left = Node('G')


print("ÁRBOL ORIGINAL\n")

print("Pre-order:")
preOrder(root)

print("\nIn-order:")
inOrder(root)

print("\nPost-order:")
postOrder(root)

print("\n\nINSERTANDO NODOS EN AVL, REBALANCE AUTOMÁTICO\n")

root = None
valores = [10, 20, 30, 40, 50, 25]

for v in valores:
    root = insert(root, v)
    print(f"Insertado: {v}")

print("\nAVL Pre-order:")
preOrder(root)

print("\nAVL In-order:")
inOrder(root)

print("\nAVL Post-order:")
postOrder(root)
