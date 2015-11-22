//
//  TreeNode.cpp
//  tree
//
//  Created by Alexis Plaza González on 11/7/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include "TreeNode.h"

TreeNode::TreeNode(int count, string firstName, string lastName, TreeNode* left, TreeNode* right, TreeNode* parent) : count{count}, lastName{lastName}, left{left}, right{right}, parent{parent} {
    
    names.push_back(firstName);//inputs the firstname pass in the parameter into the vector names.
}