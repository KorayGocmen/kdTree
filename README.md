# kdTree in C++
---
A C++ implementation of kdTree in 2D space

### Available functions
---

1. After adding the header files to your main file, create a kdTree object:

    ` kdTree *mykdTree = new kdTree();`

2. You can insert the node after you create a node object:

    `kdTreeNode *node52 = new kdTreeNode(5,2);`

    `mykdTree->insert(node52);`

3. You can delete nodes using a pointer to the node object:

    `mykdTree->remove(node52);`

4. You can print the entire tree using:

    `mykdTree->print();`
    
5. You can find the closest node in the tree, to a given node:
    
    `kdtreeNode *closestNode;`
    `closestNode = mykdTree->findClosestPoint(node52);`

6. You can get the root node of the tree:

    `kdtreeNode *root;`
    
    `root = mykdTree->getRoot();`
---

### Developed by Koray Gocmen
