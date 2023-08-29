# Binary Trees 

## What is a Binary Tree?

A **binary tree** is a hierarchical data structure consisting of nodes. Each node has, at most, two children: a left child and a right child. The node at the very top is known as the root. Nodes with no children are referred to as leaves. Binary trees are widely used in computer science due to their efficient representation and ease of traversal.

## Difference Between Binary Tree and Binary Search Tree

A **binary search tree (BST)**, a specialized version of a binary tree, adheres to a specific rule: for every node, all nodes in its left subtree contain values less than the node's value, and all nodes in its right subtree contain values greater than the node's value. This property enables binary search trees to facilitate rapid search, insertion, and deletion operations.

## Time Complexity Gain Compared to Linked Lists

Binary trees offer substantial improvements in terms of time complexity when compared to linked lists. In a balanced binary search tree, search operations boast a time complexity of O(log n). In contrast, searching within a linked list necessitates O(n) time complexity. This efficiency gain makes binary trees a preferred choice for various applications.

## Depth, Height, and Size of a Binary Tree

- **Depth**: The depth of a node is the length of the path from the root node to that specific node. The root node's depth is considered 0.

- **Height**: The height of a binary tree represents the maximum depth of any node within the tree. It is the longest path from the root to a leaf.

- **Size**: The size of a binary tree refers to the total number of nodes present in the tree.

## Tree Traversal Methods

Binary trees can be traversed in multiple ways:

- **Inorder Traversal**: Traverse the left subtree, visit the root node, and then traverse the right subtree.

- **Preorder Traversal**: Visit the root node, traverse the left subtree, and then traverse the right subtree.

- **Postorder Traversal**: Traverse the left subtree, traverse the right subtree, and then visit the root node.

## Complete, Full, Perfect, and Balanced Binary Trees

- **Complete Binary Tree**: In this tree, all levels are filled except possibly the last one. Nodes are filled from left to right.

- **Full Binary Tree**: All nodes in this type of tree have either 0 or 2 children.

- **Perfect Binary Tree**: Each internal node has exactly two children, and all leaf nodes are at the same level.

- **Balanced Binary Tree**: For every node, the height difference between the left and right subtrees is at most one.

