//
//  main.cpp
//  tree
//
//  Created by Alexis Plaza González on 11/1/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//
# include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"
using namespace std;
enum EntryCode {INSERT, SEARCH, PRINT, SIZE, REMOVE};

int main(){
    
    
    
    int response;
    string name, lastName, firstName;
    TreeNode* root = NULL;
    Tree tree;
    root = tree.insert("alex plaza", root);
    ifstream myInputFile;
    myInputFile.open("names.txt");
    myInputFile >> firstName >> lastName;
    while (!myInputFile.eof()) {
        name = firstName + " " + lastName;
        tree.insert(name, root);
        myInputFile >> firstName >> lastName;

    }
    myInputFile.close();
    
    cout << "\n Enter \n 0: insert \n 1: search \n 2: print \n 3: count \n 4: remove \n";
    cin >> response;
    while(response >= INSERT && response <= REMOVE){
        switch(response) {
            case INSERT:
                cout << "Please insert name: ";
                cin >> firstName >> lastName;
                name = firstName + " " + lastName;
                tree.insert(name, root);
                break;
            case SEARCH:
                cout << "Enter last name: ";
                cin >> lastName;
                tree.search(lastName, root);
                break;
            case PRINT:
                tree.print(root);
                break;
            case SIZE:
                cout<< "\n The number of survivors is: " + to_string(tree.count()) + "\n";
                break;
            case REMOVE:
                cout<< "Please inseart the name of the deceased: ";
                cin>> firstName >> lastName;
                name = firstName + " " + lastName;
                tree.remove(name, root);
                break;
        }
        cout << "\n Enter \n 0: insert \n 1: search \n 2: print \n 3: count \n 4: remove \n";
        cin >> response;
    }
    cout << endl << endl;
    return 0;
}

