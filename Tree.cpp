//
//  tree.cpp
//  tree
//
//  Created by Alexis Plaza González on 11/1/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;


Tree::Tree(){
    treeSize = 0;
}

void Tree::search(string lastName, TreeNode* start)
{
	if(start == NULL) cout << "Person not found"; //if start reaches a null pointer, it means that the lastname wasn't found
    
    else if(start-> lastName < lastName) search(lastName, start-> right);//if the inputed lastname is "bigger" than the lastname on the startnode, go right"
    else if(start-> lastName > lastName) search(lastName, start->left);//if the inputed lastname is "smaller" than the lastname on the startnode, go left"
    else if (start-> lastName == lastName){ //if lastname is found.
    cout << "There are " + to_string(start-> count) + " with last name " + lastName; //prints the number of memberer.
    for(int i = 0; i < (start -> names).size(); i++){ //prints the actual members.
        cout << "\n" + (start-> names)[i] + " " + lastName + "\n";
       }
    }
}


TreeNode* Tree::insert(string name, TreeNode* start)
{
    size_t x = name.find_first_of(" "); //separates first name and lastname
    string firstName = name.substr(0,x);
    string lastName = name.substr(x+1, name.size() - firstName.size() - 1);
    TreeNode* parent = start;
    return insert2(firstName, lastName, start, parent);
}

TreeNode* Tree::insert2(string firstName, string lastName, TreeNode* start, TreeNode* parent)
{
        if(start == NULL){ //if null is reached, create a new node.
        treeSize++;
        start = new TreeNode {1, firstName, lastName, NULL, NULL, parent};
        return start;
    }
    else if(lastName < start-> lastName) {
        parent = start;
        start-> left = insert2(firstName, lastName, start->left, parent);
    }
    else if(lastName > start-> lastName) {
        parent = start;
        start-> right =insert2(firstName, lastName, start ->right, parent);
    }
    else if (lastName == start-> lastName){ //if lastname is found, add firstname to the tree, and increse treesize and count.
        treeSize++;
        (start-> count)++;
        (start-> names).push_back(firstName);
    }
    return start;
}

int Tree::count()
{
    return treeSize;
}

void Tree::print(TreeNode* start)
{
    if(start != NULL){ //if the tree isn't empty
        if(start-> left != NULL) print(start-> left);
        cout << "\n - Section[" + start-> lastName + "] \n";
        for(int i = 0; i < (start -> names).size(); i++){
            cout << "\n    -" + (start-> names)[i] + " " + start-> lastName + "\n";
        }
        if(start-> right != NULL) print(start-> right);
    }
    else cout<< "The tree is empty";
}

void Tree::remove(string name, TreeNode* start){
    size_t x = name.find_first_of(" "); //separates firstname and lastname
    string firstName = name.substr(0,x);
    string lastName = name.substr(x+1, name.size() - firstName.size() - 1);
    remove2(firstName, lastName, start);
}


void Tree::remove2(string firstName, string lastName, TreeNode* start){
    
    if(start == NULL) cout << "Name was not found";
    else if(lastName < start-> lastName) remove2(firstName, lastName,start-> left );
    else if(lastName > start-> lastName) remove2(firstName, lastName, start-> right);
    else if(lastName == start-> lastName){ //if lastname was found
        treeSize--;
        if (start -> left != NULL && start -> right != NULL) //if two kids
        {
            if(start-> count == 1) { // if only name in the node
                if(firstName != start-> names[0]){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                TreeNode* replacement = start-> right;
                while(replacement-> left != NULL){ //find the minimum to the right of the note we want to delete
                    replacement =  replacement->left;
                }
                start-> lastName = replacement-> lastName; //change the information from the min node to the note we want to delete
                start-> names = replacement-> names;
                start-> count = replacement-> count;
                if(replacement-> right != NULL) { //if the found min has a right child.
                    (replacement-> parent)-> left = replacement-> right;
                    delete replacement;
                    replacement = NULL;
                    return;
                }
                replacement-> count = 1;//this is to guarantee that the node will be deleted.
                remove2("",replacement-> lastName, replacement); //at this point "replacement" must be a leave and we want to deleted becasue the fields were already copied.
                return;
            }
             else { //if many names
                 if(find((start-> names).begin(), (start-> names).end(), firstName) == (start-> names).end()){ //if first name doesnt match
                     cout<< "Name was not found";
                     return;
                 }
                (start-> count)--;
                (start-> names).erase(find((start-> names).begin(), (start-> names).end(), firstName));
                return;
            }
        }
        
        
        else if(start-> left != NULL) //if one kid to the left
        {
            if(start-> count == 1){
                
                if(firstName != start-> names[0]){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                
                TreeNode* replacement = start-> left; //the node that will replace the deleted node.
                start-> lastName = replacement-> lastName;
                start-> names = replacement-> names;
                start-> count = replacement-> count;
                replacement-> count = 1;
                remove2("",replacement-> lastName, replacement);
                return;
            } else { //if many names
                if(find((start-> names).begin(), (start-> names).end(), firstName) == (start-> names).end()){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                (start-> count)--;
                (start-> names).erase(find((start-> names).begin(), (start-> names).end(), firstName));
                return;
            }
            
        }
        
        
        else if(start-> right != NULL) //if one to the right
        {
            if(start-> count == 1){
                
                if(firstName != start-> names[0]){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                
                TreeNode* replacement = start-> right; //the node that will replace the deleted node.
                start-> lastName = replacement-> lastName;
                start-> names = replacement-> names;
                start-> count = replacement-> count;
                replacement-> count = 1;
                remove2("",replacement-> lastName, replacement);
                return;
            } else { //if many names
                if(find((start-> names).begin(), (start-> names).end(), firstName) == (start-> names).end()){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                (start-> count)--;
                (start-> names).erase(find((start-> names).begin(), (start-> names).end(), firstName));
                return;
            }
        }
        else { //if leave
            if(start-> count == 1) {
                
                if(firstName != start-> names[0]){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }
                
                if(start-> parent -> left != NULL && start-> lastName == (start-> parent)-> left-> lastName){ // if leave is on the left
                    (start-> parent) -> left = NULL;

                } else {
                    (start-> parent) -> right = NULL;
                }
                delete start; // if one name
                start = NULL;
                return;
              
            }
             
            else{ // if multiple names
                
                if(find((start-> names).begin(), (start-> names).end(), firstName) == (start-> names).end()){ //if first name doesnt match
                    cout<< "Name was not found";
                    return;
                }

                (start-> count)--;
                (start-> names).erase(find((start-> names).begin(), (start-> names).end(), firstName));
                return;
            }
        }
    }
}
 




