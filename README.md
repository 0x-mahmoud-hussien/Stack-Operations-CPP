# 💻 C++ Stack Data Structure & Algorithms
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**Author:** [Mahmoud Hussein](https://github.com/0x-mahmoud-hussien)  
📧 **Email:** mahmoud.abdelmaqsoud.hussien@gmail.com  
---

## 🧠 Overview  
This is a comprehensive C++ project that implements the **Stack** data structure using the STL `std::stack`. It goes beyond basic operations to demonstrate the stack's power in solving a wide range of classic computer science problems. The project features an interactive, menu-driven command-line interface to test over 35 different stack-related functions and algorithms, including expression evaluation, advanced sorting, and specialized stack implementations.

A key highlight of this project is the inclusion of `MinStack` and `MaxStack` classes, which efficiently track the minimum and maximum element in O(1) time.

---

## ✨ Key Features

### Fundamental Stack Operations
- **Push, Pop, Peek:** Standard LIFO (Last-In, First-Out) operations.
- **Utility:** `isEmpty`, `size`, `search`, `display`, and `copy`.

### Classic Computer Science Algorithms
- **Balanced Parentheses:** Checks if an expression with `()`, `{}`, `[]` is balanced.
- **Infix to Postfix Conversion:** Converts arithmetic expressions from infix to postfix notation using the Shunting-yard algorithm.
- **Postfix Evaluation:** Calculates the result of a postfix expression.
- **Next Greater Element:** An optimal O(n) solution to find the next greater element for each element in an array.
- **Palindrome Checker:** Uses a stack to determine if a string is a palindrome.

### Efficient MinStack & MaxStack
- Includes specialized `MinStack` and `MaxStack` classes.
- These structures allow fetching the current minimum or maximum element in the stack in constant **O(1)** time complexity.

### Advanced Stack Manipulations
- **`sortStack()`:** Sorts a stack using only stack operations (no other data structures).
- **`reverse()`:** Reverses the stack elements.
- **`removeDuplicates()`:** Removes duplicate values while maintaining the relative order of the first occurrences.
- **`pushBottom()`:** Inserts an element at the bottom of the stack.

### Interactive Testing Environment
- A robust, menu-driven interface that allows for interactive testing of all 35+ implemented methods.
- Includes interactive sub-menus for testing `MinStack` and `MaxStack` functionalities.

---

## 🛠️ Technologies Used
- **C++**
- **Standard Template Library (STL):**
  - `std::stack`
  - `std::vector`
  - `std::string`
- **Object-Oriented Programming (OOP)** principles.

---

## 🏁 How to Run

1.  **Clone the repository or download the source code.**
2.  **Compile the file** using a C++ compiler (e.g., g++):
    ```bash
    g++ Stack.cpp -o stack
    ```
    *(Note: Replace `main.cpp` with the name of your C++ file if it's different.)*

3.  **Run the executable:**
    ```bash
    ./stack
    ```

---

## 📜 License
This project is licensed under the MIT License.

---

## 🖥️ Example Output

```
====== Stack Operations Program (35 Methods) ======

========== STACK OPERATIONS MENU (35 Methods) ==========
--- Basic (1-10) ---
1. Push
2. Pop
...
--- Intermediate (11-20) ---
11. Check Balanced Parentheses
...
--- Advanced (19-22) ---
19. Check Palindrome
20. Next Greater Element
21. Test Min Stack
22. Test Max Stack
...
0. Exit
========================================================
Enter choice:
```