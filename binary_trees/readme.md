# binary trees representaion

it is hieraical data structure

        3    -- parent
       / \
      9   20 -- children
     / \  / \
    15  7 18 25

two properties of binary tree

1. in binary tree each node have atmost 2 children
2. a binary tree can be empty, meaning it contains no nodes.(the root node is NULL)

key terminlogy:

1. Node
   a node in binary tree contains three parts

   1. data
   2. left child
   3. right child

   if left child or right child is null we can say there is no childs

2. root
   node which is at top is called root

3. parent
   node is considered as parent of its left and right children.

4. child
   any node can have 0 , 1 or 2 children called as child

5. leaf node or terminal nodes
   node which is having no children is called leaf node

6. internal node
   node which is having at least one child is called internal node

7. sub tree
   a tree fromed by a node and its desendents
   desendents means all the nodes which are below a node

8. height of tree
   height of tree is maximum number of edges from root to leaf node
   in simple terms
   the length of longest path from root to leaf node

9. depth of node
   depth of node is number of edges from root to that node
   in simple terms
   the length of path from root to that node

10. ancestor
    a ancesstor of a node is any node which is on path from root to that node except node itself

Types of Binary tree

1. full binary tree
   each node in binary tree have either 0 or 2 children

2. a complete binary tree
   all level, except last level, are completely filled and last level is filled from left to right

   example
   1
   / \
    2 3
   /
   4 5

3. a perfect binary tree
   all internal nodes have two children and all leaf nodes are at same level

   example
   1
   / \
    2 3
   / \ / \
   4 5 6 7

4. a balanced binary tree
   height of left and right subtree of every node differ by at most 1
   10 => (height diff = |2 - 1 | = 1)
   / \
    (heigh diff = |2 - 0| = 0) 5 20 => (height diff = |2 - 2 | = 0)
   /
   1 => (height diff = |0 - 0| = 0)
   here each diff is less than 2 so we can say this is a balanced binary tree

5. degenrate binary tree
   a binary tree where each node is having only one child is called degenrate binary tree

   example
   1
   /
   2
   \
    3

6. skewed binary tree
   it is also a degenrate binary tree
   it is a binary tree where all nodes are either left child or right child

   if all node are left child then it is called left skewed binary tree
   if all node are right child then it is called right skewed binary tree

tree traversals:
what is traversal
traversal means visiting all nodes of tree at least once

### importance of tree traversals

1.data retrieval or searching
2.tree modification or tree transformations
3.expression evaluation

broadly there are 2 types of traversal

1. Depth first search (DFS)
2. Breadth first search (BFS)

3. Depth first search (DFS)
   there are 3 types of DFS

   1. pre order traversal (root -> left -> right)
   2. in order traversal (left -> root -> right)
   3. post order traversal (left -> right -> root)

4. Breadth first search (BFS)
   it is level order traversal
   we started from root and visited all nodes level by level
