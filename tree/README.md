
---
![tree-centers-examples](https://github.com/user-attachments/assets/8b0621d6-0f5e-4b56-9d2a-361782d91d4a)

---

# Introduction

A tree is a data structure that simulates a hierarchical tree structure with a set of connected nodes. Each node contains a value and pointers to its children. Trees are widely used to represent hierarchical data, such as organizational structures, file systems, and more.

---

# Key Characteristics

- **Root**: The topmost node in a tree.
- **Edge**: The connection between two nodes.
- **Leaf**: A node with no children.
- **Child**: A node directly connected to another node when moving away from the Root.
- **Parent**: The converse notion of a child.
- **Sibling**: Nodes that share the same parent.
- **Subtree**: A tree formed by a node and its descendants.
- **Depth**: The length of the path from the root to a node.
- **Height**: The length of the path from a node to the deepest leaf.

---

# Types of trees

There are various types of trees used in computer science, each serving different purposes:

- **Binary Tree**: A tree where each node has at most two children.
- **Binary Search Tree (BST)**: A binary tree where the left child contains only nodes with values less than the parent node, and the right child contains only nodes with values greater than the parent node.
- **AVL Tree**: A self-balancing binary search tree.
- **Red-Black Tree**: Another self-balancing binary search tree.
- **B-Tree**: A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.
- **Trie**: A tree-like data structure that stores a dynamic set of strings, often used for searching words in a dictionary.
- **N-ary Tree**: A tree in which a node can have at most N children.

---

# Binary search tree

![1_ziYvZzrttFYMXkkV9u66jw](https://github.com/user-attachments/assets/ac61f36f-d003-4058-b966-6a0e22607ece)


A Binary Search Tree (BST) is a type of binary tree that maintains the following properties:

- The left subtree of a node contains only nodes with values less than the node's value.
- The right subtree of a node contains only nodes with values greater than the node's value.
- Both the left and right subtrees must also be binary search trees.

This property makes BSTs efficient for searching, insertion, and deletion operations, all of which can be performed in O(log n) time on average.

---

- ### Implementation

    - Define the Node Class

    ```python
    class Node:
        def __init__(self, key):
            self.left = None
            self.right = None
            self.val = key
    ```

    -  Insert a Node

    ```python
    def insert(root, key):
        if root is None:
            return Node(key)
        else:
            if root.val < key:
                root.right = insert(root.right, key)
            else:
                root.left = insert(root.left, key)
        return root
    ```

    - Search for a Node

    ```python
    def search(root, key):
        if root is None or root.val == key:
            return root
        if root.val < key:
            return search(root.right, key)
        return search(root.left, key)
    ```

    - Delete a Node

    ```python
    def deleteNode(root, key):
        if root is None:
            return root
        if key < root.val:
            root.left = deleteNode(root.left, key)
        elif key > root.val:
            root.right = deleteNode(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            temp = minValueNode(root.right)
            root.val = temp.val
            root.right = deleteNode(root.right, temp.val)
        return root

    def minValueNode(node):
        current = node
        while(current.left is not None):
            current = current.left
        return current
    ```

---

- ### Where to use BST

    - #### Use Cases:
        - **Search Operations**: Efficiently search for an element in O(log n) time.
        - **Sorting Data**: Can be used to maintain a dynamically sorted list of elements.
        - **Dynamic Set Operations**: Insert, delete, and search for elements dynamically.
    - #### When to Use:
        - When the data needs to be stored in a sorted manner.
        - When there is a need for frequent insertion and deletion of elements.
        - When searching for elements efficiently is a priority.
    
    ---

- ### Real-World Examples of BST

    - **Database Indexing**: BSTs are used in database systems to index data for quick retrieval.
    - **File Systems**: Many file systems use tree structures to manage directories and files.
    - **Network Routing Algorithms**: Routing algorithms use tree structures to determine the optimal path.
    - **Compiler Design**: BSTs are used to manage symbol tables.

---
