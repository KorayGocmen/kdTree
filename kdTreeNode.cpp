/* 
 * File:   kdTreeNode.cpp
 * Author: Koray Gocmen
 * 
 * Created on March 25, 2016, 1:30 PM
 */
 
#include "kdTreeNode.h" 
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class kdTreeNode;

kdTreeNode::kdTreeNode() {
    x = 0;
    y = 0;
    beenHere = false;
    left = NULL;
    right = NULL;
    parent = NULL;
}
 
kdTreeNode::kdTreeNode(float _x, float _y){
    x = _x;
    y = _y;
    beenHere = false;
    left = NULL;
    right = NULL;
    parent = NULL;   
}
 
kdTreeNode::kdTreeNode(const kdTreeNode& orig) {
    x = orig.x;
    y = orig.y;
    left = orig.left;
    right = orig.right;
    parent = orig.parent;
}
 
kdTreeNode::~kdTreeNode() {
     
    if(left != NULL)
        delete left;
    left = NULL;
     
    if(right != NULL)
        delete right;
    right = NULL;
     
}
 
kdTreeNode& kdTreeNode::operator =(const kdTreeNode& R){
    x = R.x;
    y = R.y;
    level = R.level;
    beenHere = R.beenHere;
}
 
float kdTreeNode::getX() const{
    return x;
}
 
float kdTreeNode::getY() const{
    return y;
}
 
bool kdTreeNode::getLevel() const{
    return level;
}
 
bool kdTreeNode::getBeenHere() const{
    return beenHere;
}
 
kdTreeNode* kdTreeNode::getLeft() const{
    return left;
}
 
kdTreeNode* kdTreeNode::getRight() const{
    return right;
}
 
kdTreeNode* kdTreeNode::getParent() const{
    return parent;
}
 
void kdTreeNode::setX(float _x){
    x = _x;
}
 
void kdTreeNode::setY(float _y){
    y = _y;
}
 
void kdTreeNode::setLevel(bool _lev){
    level = _lev;
}
 
void kdTreeNode::setBeenHere(bool _here){
    beenHere = _here;
}
 
void kdTreeNode::setRight(kdTreeNode* newRight){
    right = newRight;
}
 
void kdTreeNode::setLeft(kdTreeNode* newLeft){
    left = newLeft;
}
 
void kdTreeNode::setParent(kdTreeNode* newParent){
    parent = newParent;
}
 
void kdTreeNode::removeNode(kdTreeNode* entry, kdTreeNode* root){
     
    if(this->level){
        //x-level
        if(this->x > entry->x){
            //go left
            if(left != NULL){
                left->removeNode(entry, root);
            }
            return;
        }
        else if(this->x < entry->x){
            //go right
            if(right != NULL){
                right->removeNode(entry, root);
            }
            return;            
        }
        else{
            //this.x == entry.x
            if(this->y == entry->y){
                //found it. delete it and re-balance tree
                if(this->left == NULL && this->right == NULL){
                    //it is a leaf
                    if(this->parent->left->x == this->x && this->parent->left->y == this->y){
                        //we are on parent's left node
                        this->parent->setLeft(NULL);
                        delete this;
                    }
                    else{
                        //we are on parent's right node
                        this->parent->setRight(NULL);
                        delete this;
                    }
                }else{
                    //entry has a subtree
                    //disconnect subtree
                    if(this->parent == NULL){
                        //entry is the root itself
                        //new root is the right node
                        //root = root->findNewRoot(root);
                        //this->distributeSubtree(this, root);
                        //delete this;
                         
                    }else{
                        //entry is not the root
                        if(this->parent->left->x == this->x && this->parent->left->y == this->y){
                            //we are on parent's left node
                            this->parent->setLeft(NULL);
                        }
                        else{
                            //we are on parent's right node
                            this->parent->setRight(NULL); 
                        }
                    }                    
                    //subtree is disconnected
                    //call connect subtree
                    this->distributeSubtree(this, root);                    
                }
            }
            else{
                //go right
                if(right != NULL){
                    right->removeNode(entry, root);
                }
                return;
            }
        }
    }
     
    else if(!(this->level)){
        //y-level
        if(this->y > entry->y){
            //go left
            if(left != NULL){
                left->removeNode(entry, root);
            }
            return;
        }
        else if(this->y < entry->y){
            //go right
            if(right != NULL){
                right->removeNode(entry, root);
            }
            return;
        }
        else{
            //this.y == entry.y
            if(this->x == entry->x){
                //found it. delete it and re-balance tree
                if(this->left == NULL && this->right == NULL){
                    //it is a leaf
                    if(this->parent->left->x == this->x && this->parent->left->y == this->y){
                        //we are on parent's left node
                        this->parent->setLeft(NULL);
                        delete this;
                    }
                    else{
                        //we are on parent's right node
                        this->parent->setRight(NULL);
                        delete this;
                    }
                }else{
                    //entry has a subtree
                    //disconnect subtree
                    if(this->parent == NULL){
                        //entry is the root itself
                        //new root is the right node
                        //root = root->findNewRoot(root);
                        //this->distributeSubtree(this, root);
                        //delete this;
                    }else{
                        //entry is not the root
                        if(this->parent->left->x == this->x && this->parent->left->y == this->y){
                            //we are on parent's left node
                            this->parent->setLeft(NULL);
                        }
                        else{
                            //we are on parent's right node
                            this->parent->setRight(NULL); 
                        }
                    }                    
                    //subtree is disconnected
                    //call connect subtree
                    this->distributeSubtree(this, root);                    
                }
            }
            else{
                //go right
                if(right != NULL){
                    right->removeNode(entry, root);
                }
                return;                
            }
        }
    }
}
 
void kdTreeNode::insertNode(kdTreeNode* newNode, kdTreeNode* &root){
     
    if(this->level){ //this is a x-level
 
        if(this->x > newNode->x){
            //go left for level x
            if(left != NULL)
                left->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel())); //change the level of the children node
                newNode->setParent(this);
                this->setLeft(newNode);
                return;
            }
        }
        else if(this->x < newNode->x){
            //go right for level x;
            if(right != NULL)
                right->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel())); //change the level of the children node
                newNode->setParent(this);
                this->setRight(newNode);
                return;
            }
        }
        else{
            //this.x == newNode.x
            if(this->y == newNode->y){
                //node already exists
                return;
            }
            else{
                //this->x == newNode->x && this.y != newNode->y
                //go right for level x;
                if(right != NULL)
                    right->insertNode(newNode, root);
                else{
                    newNode->setLevel(!(this->getLevel())); //change the level of the children node
                    newNode->setParent(this);
                    this->setRight(newNode);
                    return;
                }
            }
        }            
    }//end of if (x-level)
     
    else if(!(this->level)){ //this is a y-level
         
        if(this->y > newNode->y){
            //go left for level y
            if(left != NULL)
                left->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel())); //change the level of the children node
                newNode->setParent(this);
                this->setLeft(newNode);
                return;
            }
             
        }
        else if(this->y < newNode->y){
            //go right for level y
            if(right != NULL)
                right->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel())); //change the level of the children node
                newNode->setParent(this);
                this->setRight(newNode);
                return;
            }
        }
        else{
            //this.y == newNode.y
            if(this->x == newNode->x){
                //node already exists
                return;
            }
            else{
                //this->y == newNode->y && this->x != newNode->y
                //go right for level y
                if(right != NULL)
                    right->insertNode(newNode, root);
                else{
                    newNode->setLevel(!(this->getLevel())); //change the level of the children node
                    newNode->setParent(this);
                    this->setRight(newNode);
                    return;
                }
            }
        }
    }
}
 
kdTreeNode* kdTreeNode::findClosestNode(kdTreeNode* entry){
     
    vector<kdTreeNode>path;
     
    //start from the root vector
    findPath(entry);
        
    //previous smallest point
    //initialized to null in the beginning
    kdTreeNode dummy;
    kdTreeNode *previousSmallest = &dummy;
     
    //current smallest node in path
    //called with the root
    kdTreeNode *smallestNode = closestNodeInPath(entry, this);
     
     
    while(!(previousSmallest->getX() == smallestNode->getX() && previousSmallest->getY() == smallestNode->getY())){ //visited before?
                 
        previousSmallest = smallestNode;
         
        //find the unvisited child of the smallest node
        bool checkedLeft = false;
        bool checkedRight = false;
         
        if(smallestNode->getLeft()!=NULL && smallestNode->left->beenHere){
            checkedLeft = true;
        }
        else if(smallestNode->getRight()!=NULL && smallestNode->right->beenHere){
            checkedRight = true;
        }
         
        this->clearFlags();
         
        //find the new path
        if(checkedLeft){
            //add the smallest to the new path
            smallestNode->setBeenHere(true);
            if(smallestNode->getRight() != NULL)
                (smallestNode->getRight())->findPath(entry);
        }
        else if(checkedRight){
            //add the smallest to the new path
            smallestNode->setBeenHere(true);
            if(smallestNode->getLeft() != NULL)
                (smallestNode->getLeft())->findPath(entry);
        }else{
            smallestNode->setBeenHere(true);
            smallestNode->findPath(entry);
        }
         
        //update the smallest node
        smallestNode = closestNodeInPath(entry, smallestNode);         
    }         
    return smallestNode;    
}
 
kdTreeNode* kdTreeNode::closestNodeInPath(kdTreeNode* entry, kdTreeNode* root){
   
    double distanceHolder = 100000000;
    kdTreeNode* nodeHolder;
     
    kdTreeNode* current = root;
     
    //if there is only one node in the tree,
    //if there are multiple nodes these lines will not make a difference
    nodeHolder = current;
     
    bool noAvailableNode = false;
     
    while(!noAvailableNode){
        //continue as long as we don't reach a leaf
        //change the flag
        double tempDistance = findDistanceBetweenTwoPoints(entry, current);
         
        if(tempDistance < distanceHolder){
            distanceHolder = tempDistance;
            nodeHolder = current;
        }
         
        bool nextNodeIsLeft = false;
        bool nextNodeIsRight = false;
         
        //find the next node to go
        if(current->left != NULL){
            if(current->left->beenHere == true){
                nextNodeIsLeft = true;
                noAvailableNode = false;
                current = current->left;
            }else{
                noAvailableNode = true;
            }
        }
        if(current->right != NULL && !nextNodeIsLeft){
            if(current->right->beenHere == true){
                nextNodeIsRight = true;
                noAvailableNode = false;
                current = current->right;
            }else{
                noAvailableNode = true;
            }
        }
        if(current->left == NULL && current->right == NULL && !nextNodeIsLeft && !nextNodeIsRight){
            //we are on the leaf
            noAvailableNode = true;
        }
    }
     
    return nodeHolder;
     
}
 
void kdTreeNode::findPath(kdTreeNode *entry){
     
    this->setBeenHere(true); 
     
    if(this->level){
        //x-level
        if(this->x > entry->getX()){
            //go left            
            if(left != NULL)
                left->findPath(entry);
        }
        else if(this->x < entry->getX()){
            //go right
            if(right != NULL)
                right->findPath(entry);
        }
        else{
            //this.x == entry.x
            if(this->y == entry->getY()){
                //the same point
                //we don't need to check the rest of the tree             
            }else{
                //different point but has the same x value
                //go right
                if(right != NULL)
                    right->findPath(entry);
            }
        }      
    }
     
    else{
        //y-level
        if(this->y > entry->getY()){
            //go left
            if(left != NULL)
                left->findPath(entry);
        }        
        else if(this->y < entry->getY()){
            //go right
            if(right != NULL)
                right->findPath(entry);
        }
        else{
            //this.y == entry.y
            if(this->x == entry->getX()){
                //the same point
                //we don't need to check the rest of the tree   
            }else{
                //different point but has the same y value
                //go right
                if(right != NULL)
                    right->findPath(entry);
                else{
                    //right empty
                }
            }
        }
    }//end of y-level   
} 
 
void kdTreeNode::printNodes(){
    
    if(left != NULL)
        left->printNodes();
    
    if(this->parent != NULL){
        cout<<"("<<this->x<<","<<this->y<<")==>level: "
                <<level<<"==>parent: ("<<this->getParent()->x
                <<","<<this->getParent()->y<<")"<<endl;
    }else{
        cout<<"("<<this->x<<","<<this->y<<")==>level: "
                <<level<<"==>parent: ROOT"<<endl;
    }
    
    if(right != NULL)
        right->printNodes();   
     
}
 
void kdTreeNode::clearFlags(){
     
    if(left != NULL)
        left->clearFlags();
     
    if(this->beenHere){
        this->setBeenHere(false);
    }
    if(right != NULL)
        right->clearFlags();
     
}
 
void kdTreeNode::distributeSubtree(kdTreeNode* entry, kdTreeNode* root){
     
    if(this == NULL)
        return;
     
    if(this->left != NULL)
        left->distributeSubtree(entry, root);
     
    if(this->right != NULL)
        right->distributeSubtree(entry, root);
     
    if(!(this->x == entry->x && this->y == entry->y)){
        this->setBeenHere(false);
        this->setLeft(NULL);
        this->setRight(NULL);
        this->setParent(NULL);
        root->insertNode(this, root);
    }
    else{
        this->setRight(NULL);
        this->setLeft(NULL);
        this->setParent(NULL);
        delete this;
    }
}

double kdTreeNode::findDistanceBetweenTwoPoints(kdTreeNode* node1, kdTreeNode* node2){
    
    float x1 = node1->getX();
    float y1 = node1->getY();
    float x2 = node2->getX();
    float y2 = node2->getY();
            
    double distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    
    return distance;
}
