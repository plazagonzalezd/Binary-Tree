/*
 
 */

#ifndef __tree__TreeNode__
#define __tree__TreeNode__

#include <iostream>
#include <vector>
/*
 Every treenode has 5 fields, count, the number of member of the family; parent, a pointer to the parent node;
 names, a vector that stores the first names of survivors of a given lastname; left, a pointer to the left child;
 and right, a pointer to the right child.

*/

using namespace std;

struct TreeNode {

    TreeNode(int count, string firstName, string lastName, TreeNode* right, TreeNode* left, TreeNode* parent);

    int count; //keeps track of the number of memebers of the family
    TreeNode* parent;
    vector<string> names; // list of names
    string lastName;
    TreeNode* left;
    TreeNode* right;
};

#endif /* defined(__tree__TreeNode__) */
