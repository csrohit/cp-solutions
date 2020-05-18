from collections import deque
class BinaryTree:
    def __init__(self):
        self.root = None

    def create(self, indexes):
        q = deque()
        if self.root is None:
            self.root = Node(1,1)

        q.append(self.root)
        for left, right in indexes:
            if left == -1 and right == -1:
                q.popleft()
            else:
                current = q.popleft()
                if left != -1:
                    current.left = Node(left, current.level + 1)
                    q.append(current.left)
                if right != -1:
                    current.right = Node(right, current.level + 1)
                    q.append(current.right)

class Node:
    def __init__(self, data, level):
        self.data = data
        self.left = None
        self.right = None
        self.level = level


def swap_nodes(root, query):
    q = deque()
    q.append(root)
    while q:
        current = q.popleft()
        if current.level % query == 0:
            current.left, current.right = current.right, current.left
        if current.left is not None:
            q.append(current.left)
        if current.right is not None:
            q.append(current.right)

def inorder(root):
    stack = []
    current = root
    op = []
    while True:
        if current is not None:
            stack.append(current)
            current = current.left
        elif stack:
            node = stack.pop()
            op.append(node.data)
            current = node.right
        else:
            break
    print(*op, sep=" ")

if __name__ == '__main__':
    n = int(input())
    indexes = []
    for i in range(n):
        indexes.append(list(map(int, input().split())))
    queries_count = int(input())
    queries = []
    for i in range(queries_count):
        queries.append(int(input()))
    t = BinaryTree()
    t.create(indexes)
    for query in queries:
        swap_nodes(t.root, query)
        inorder(t.root)