/*
created by alex.
 */
#ifndef __tree__tree__
#define __tree__tree__

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Tree{

public:
    Tree();
    
    /*
     The search method receives the lastname of a family and returns a list of the members of the family and the amount
     of memebers in the with that last name*/
    void search(string lastName, TreeNode* start);
    
    /*the insert method is the first step in the insertion of a name, it pretty much just separates the lastname and first name of the inputed name*/
    TreeNode* insert(string name, TreeNode* start);
    
    /*The insert 2 method takes as a parameter the first and last name of the person, the initial node, and the parent of that initial node. If the lastname is found in the tree, the count field of that node is increased, and the firstname is added to the names field. If the lastnmae is not found, a new node is created with that lastname*/
    TreeNode* insert2(string firstName, string lastName, TreeNode* start, TreeNode* parent);
    
    /*remove is the prestep of the remove proces. It separates the lastname and the firstname*/
    void remove(string name, TreeNode* start);
    
    /*remove removes the inputed name. If the lastname is found and the count is 1, the node is removed. If the count is more than one, the first name is simply removed from the tree*/
    void remove2(string firstName, string lastName, TreeNode* start);
    
    /*simply returns treeSize*/
    int count();
    
    /*prints in order the family names. For each family name, the name of memebers is also printed.*/
    void print(TreeNode* start);
    
private:
    int treeSize; // gives the number of surviviors
};


#endif /* defined(__tree__tree__) */
