Flight Ticket Management System Using AVL Tree

1. Introduction

The Flight Ticket Management System is a DSA project developed using C++. It uses an AVL Tree to store and manage flight ticket IDs. It demonstrates LR and RL rotations to maintain a balanced tree.

2. Objectives

- To understand AVL Tree operations.
- To demonstrate LR and RL rotations.
- To organize ticket IDs in sorted order.
- To understand self-balancing Binary Search Trees.

3. Features

- Add flight ticket IDs.
- Display ticket IDs in sorted order.
- Demonstrate LR rotation.
- Demonstrate RL rotation.
- Simple menu-driven interface.

4. Technologies Used

- Programming Language: C++
- IDE: Dev-C++
- Data Structure: AVL Tree


5. AVL Tree Rotations

LR Rotation

LR rotation occurs when a node is inserted into the right subtree of the left child.

Before:
30, 10, 20

After:

    20
   /  \
  10   30

RL Rotation

RL rotation occurs when a node is inserted into the left subtree of the right child.

Before:
10, 30, 20

After:

    20
   /  \
  10   30

6. How to Run

1. Open the source code in Dev-C++.
2. Compile and run the program.
3. Select an option from the menu.
4. Enter ticket IDs or select LR/RL rotation demonstrations.

7. Conclusion

This project demonstrates how an AVL Tree maintains balance through rotations. 
It helps understand insertion and balanced tree operations using C++.
