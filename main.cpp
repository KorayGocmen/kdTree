#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string>

#include "kdTree.h"
#include "kdTreeNode.h"

using namespace std;

int main() {
    
    kdTree *mykdTree = new kdTree();
    
    kdTreeNode *node52 = new kdTreeNode(5,2);
    
    mykdTree->insert(node52);
    
    mykdTree->print();
    
    
    return 0;
}
