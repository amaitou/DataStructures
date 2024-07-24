
# Introduction to Stacks

A stack is a fundamental data structure in computer science that follows a particular order for inserting and deleting elements. This order is known as Last In, First Out (LIFO), meaning that the last element added to the stack will be the first one to be removed. The analogy often used to explain stacks is a stack of plates: you can only take the top plate off the stack and can only add a new plate on top.

---

### Basic Operations

- Push: Add an element to the top of the stack.
- Pop: Remove the element from the top of the stack.
- Peek (or Top): View the top element without removing it.
- isEmpty: Check if the stack is empty.
- isFull: Check if the stack is full (mainly used in fixed-size stack implementations).

---

### Stack Implementation

Stacks can be implemented using arrays or linked lists. Each method has its advantages and disadvantages:

- **Array-based implementation**: This is straightforward and efficient in terms of time complexity (O(1) for push and pop operations). However, it requires a predefined size, leading to potential space inefficiencies.

- **Array-based implementation**: This is straightforward and efficient in terms of time complexity (O(1) for push and pop operations). However, it requires a predefined size, leading to potential space inefficiencies.

---

# How and When to Use Stacks

### When to Use Stacks

Stacks are used in a variety of scenarios where LIFO order is required. Some common use cases include:

- Function Call Management: In many programming languages, the call stack is used to manage function calls and returns.

- Expression Evaluation: Stacks are used to evaluate arithmetic expressions, especially those in postfix or prefix notation.

- Undo Mechanism in Text Editors: Most text editors use stacks to implement the undo feature. Each change is pushed onto the stack, and popping from the stack reverts to the previous state.

- Parenthesis Matching: Stacks are used in algorithms that check for balanced parentheses in expressions.

- Depth-First Search (DFS): DFS in graph algorithms uses a stack to keep track of the vertices to be explored.

---

### How to Use Stacks

Consider a problem where we need to check if a given string of parentheses is balanced. Here's how a stack can be used:

```python
def is_balanced(expression):
    stack = Stack()
    for char in expression:
        if char in "({[":
            stack.push(char)
        elif char in ")}]":
            if stack.is_empty():
                return False
            top = stack.pop()
            if not matches(top, char):
                return False
    return stack.is_empty()

def matches(opening, closing):
    opens = "({["
    closes = ")}]"
    return opens.index(opening) == closes.index(closing)

print(is_balanced("({[()]})"))
print(is_balanced("({[([)])}))"))
```

