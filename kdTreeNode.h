/* 
 * File:   kdTreeNode.h
 * Author: Koray Gocmen
 *
 * Created on March 25, 2016, 1:30 PM
 */
 
#ifndef KDTREENODE_H
#define KDTREENODE_H

using namespace std;
 
class kdTreeNode {
    
public:
     
    kdTreeNode();
    kdTreeNode(float _x, float _y);
    kdTreeNode(const kdTreeNode& orig);
    virtual ~kdTreeNode();
    kdTreeNode& operator=(const kdTreeNode &R);
     
    float getX() const;
    float getY() const;
    bool getLevel() const;
    bool getBeenHere() const;
    
    kdTreeNode* getLeft() const;
    kdTreeNode* getRight() const;
    kdTreeNode* getParent() const;
     
    void setX(float _x);
    void setY(float _y);
    void setLevel(bool _lev);
    void setBeenHere(bool _here);
     
    void setLeft(kdTreeNode* newLeft);
    void setRight(kdTreeNode* newRight);
    void setParent(kdTreeNode* newParent);
     
    void printNodes();
     
    void clearFlags();
    
    void findPath(kdTreeNode *entry);
     
    void removeNode(kdTreeNode* entry, kdTreeNode* root);
    
    void insertNode(kdTreeNode* newNode, kdTreeNode* &root);
     
    void distributeSubtree(kdTreeNode* entry, kdTreeNode* root);
     
    void distributeTreeWithNewRoot(kdTreeNode* root, bool rootWasSet);
    
    double findDistanceBetweenTwoPoints(kdTreeNode* node1, kdTreeNode* node2);
    
     
    kdTreeNode* findNewRoot(kdTreeNode* root);
    
    kdTreeNode* findClosestNode(kdTreeNode* entry);
     
    kdTreeNode* closestNodeInPath(kdTreeNode* entry, kdTreeNode* root);
    
private:
     
    float x;
    float y;
    bool level;
    bool beenHere;
         
    kdTreeNode* left;
    kdTreeNode* right;
    kdTreeNode* parent;
 
};
   
#endif /* KDTREENODE_H */
