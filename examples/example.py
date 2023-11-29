class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        if self.left is not None:
            self.left.parent = self
        self.right = right
        if self.right is not None:
            self.right.parent = self
        self.parent = None


def iterative_inorder(root):
    cur = root
    # Navigate to the leftmost node
    while cur and cur.left:
        cur = cur.left

    while cur:
        yield cur.data

        # If right child exists, visit this subtree
        if cur.right:
            cur = cur.right
            while cur.left:
                cur = cur.left
        else:
            # Traverse back up to the parent
            while cur.parent and cur == cur.parent.right:
                cur = cur.parent
            cur = cur.parent


# Example usage
if __name__ == "__main__":
    root = Node(1, Node(2, Node(4), Node(5)), Node(3))
    #     1
    #    / \
    #   2   3
    #  / \
    # 4   5

    for data in iterative_inorder(root):
        print(data, end=" ")
    print()
