/* 
 * File:   kdTree.h
 * Author: Koray Gocmen
 *
 * Created on March 25, 2016, 1:47 PM
 */
 
#ifndef KDTREE_H
#define KDTREE_H 
#include "kdTreeNode.h"
 
class kdTree {
public:
    kdTree();
    kdTree(const kdTree& orig);
    virtual ~kdTree();
 
    kdTreeNode* getRoot();
    kdTreeNode* findClosestPoint(kdTreeNode* entry);
    
    void print();
    void remove(kdTreeNode* entry);
    void insert(kdTreeNode* newEntry);
    
private:
     
    kdTreeNode *root;
 
};
 
#endif /* KDTREE_H */
