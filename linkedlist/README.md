---
![Singlelinkedlist](https://github.com/user-attachments/assets/604a55db-e939-489c-a0e5-271e103b2c08)
---

# Introduction to LinkedList

A linked list is a linear data structure where elements are stored in nodes, with each node containing a reference (or link) to the next node in the sequence. This allows for efficient insertion and deletion of elements as it does not require shifting elements like in an array.

---

### Different Types of Linked Lists

- **Singly Linked List**

    Each node points to the next node in the sequence.

    ![singly-linkedlist](https://github.com/user-attachments/assets/49785f90-fe02-4be9-892d-fa2aca196f53)


- **Doubly Linked List**

    Each node points to both the next and the previous nodes.

    ![DLL1](https://github.com/user-attachments/assets/63b9a7bb-c254-4aed-bc24-913c5cc76a79)


---

### Difference Between Singly and Doubly Linked Lists

- **Singly Linked List** -> Simpler to implement, uses less memory as each node only has one pointer.
- **Doubly Linked List** -> More complex due to additional pointer, but allows for easier traversal both forwards and backward.

---

### Implementation

- Singly Linked List

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        new_node.prev = last

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

# Usage
dll = DoublyLinkedList()
dll.append(1)
dll.append(2)
dll.append(3)
dll.display()
```

- Doubly Linked List

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        new_node.prev = last

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

# Usage
dll = DoublyLinkedList()
dll.append(1)
dll.append(2)
dll.append(3)
dll.display()
```

---

# When to Use Each

**Singly linked** lists are ideal when memory efficiency is crucial and the primary operations involve sequential access from the head to the end of the list. They are simpler to implement and use less memory than **doubly linked lists** since each node only needs to store a reference to the next node. Common use cases include implementing stacks and queues, where elements are added or removed from one end of the list. On the other hand, **doubly linked lists** are more suitable when bidirectional traversal is required, as each node maintains references to both the next and previous nodes. This facilitates operations such as reverse iteration and easy removal of nodes from any position in the list. However, **doubly linked lists** consume more memory due to the additional pointer in each node. They are typically used in scenarios like navigation systems (e.g., browser history), implementing complex data structures like deques, or when frequent insertions and deletions from both ends of the list are necessary.

# The purpose of each

- Singly Linked List:

    - Implementation of Stacks: Singly linked lists are often used to implement stacks where elements are added and removed from one end.
    - Hash Table Chaining: Used in collision resolution strategies where each bucket is a linked list.

- Doubly Linked List:

    - Web Browser History: Allows easy navigation forward and backward.
    - Music Playlists: Enables navigating to the next and previous songs efficiently.
    - Undo/Redo Functionality: Supports going back and forth in a sequence of actions.
