# Binary Trees Project

## Description

This project involves the implementation of functions to create and manipulate binary trees and max heaps. The tasks include creating binary tree nodes, inserting values into a max binary heap, and printing the binary tree structure. The code is written in C and adheres to the Betty style guidelines.

## Requirements

- All code is compiled on Ubuntu 14.04 LTS using `gcc 4.8.4` with flags `-Wall -Werror -Wextra -pedantic`.
- Each file ends with a new line.
- All code uses the Betty style for formatting.
- No global variables are allowed.
- Maximum of 5 functions per file.
- Standard library usage is allowed.
- Prototypes of all functions are included in the header file `binary_trees.h`.
- Header files are include guarded.

## Data Structures

The project uses the following data structures for binary trees:

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
