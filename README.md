# Morris (InOrder) Traversal Alternative

## [Morris Traversal](https://www.educative.io/answers/what-is-morris-traversal) is a way to traverse the tree without using stack and recursion.

# Table of Contents

1. [Problem](#problem)
2. [Solution](#solution)
3. [Complexity](#complexity)
4. [Examples](#examples)
    - [Python](#python)
    - [C++](#c)
5. [Contributing](#contributing)
6. [License](#license)
7. [Author](#author)

### Problem:

Given a binary tree, traverse the tree in inorder fashion using constant space and linear time without recursion.

### Solution:

*We need to use the parent pointer to traverse the tree.*

1. Get the the leftmost node of the root of the tree.
2. Yield the node.
3. Check if the node has a right child.
4. If it has a right child, find the leftmost node of the right child.
5. If it doesn't have a right child
    1. Go up the tree until you find a node that is not right child of its parent.
    2. Go to the parent of that node.
6. Repeat from step 2 until the node is None.

### Complexity:

- Time Complexity: O(n)
- Space Complexity: O(1)

### Examples:

*You can see full working code for all examples (and more) [here](./examples).*

#### Python

```python
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
```

#### C++

```cpp
void iterativeInorder(Node* root) {
    Node* cur = root;

    // Find the leftmost node
    while (cur && cur->left) {
        cur = cur->left;
    }

    while (cur) {
        std::cout << cur->data << " "; // Output the data

        // Traverse the right subtree
        if (cur->right) {
            cur = cur->right;
            while (cur->left) {
                cur = cur->left;
            }
        } else {
            // Move up the tree
            while (cur->parent && cur == cur->parent->right) {
                cur = cur->parent;
            }
            cur = cur->parent;
        }
    }
}
```

# Contributing

Contributions are welcome! If you find a bug or want to contribute, feel free to create an issue or open a pull request!

I would personally thank anybody who can open a pull request to add more examples in other languages!

# License

This project is licensed under the MIT License. See [LICENSE](./LICENSE) for more details.

# Author

The algorithm was created and published by [1mpossible-code](https://github.com/1mpossible-code/).