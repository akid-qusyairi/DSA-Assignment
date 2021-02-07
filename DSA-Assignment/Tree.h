#pragma once
#include <string>
#include <iostream>
#include "TreeNode.h"
using namespace std;
//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//

class Tree
{
private:

    TreeNode* rootNode;
public:
    Tree();
    
    //Searches the tree for the string target
    TreeNode* search(string target);
    TreeNode* search(TreeNode* start, string target);

    //Only searches the right side of the tree for the string target
    TreeNode* searchSibling(TreeNode* start, string target);

    //Insertion of string item to a node as a child or sibling
    void insert(string item);
    void insert(TreeNode*& t, string item);

    //Deletes the node and any child attached to it
    TreeNode* deleteNode(TreeNode*& child);

    //Gets the rootNode and returns it
    TreeNode* getTop();
    
    //Check if the tree is empty
    bool isEmpty();

    //Prints the tree
    void traverseTree();
    void traverseTree(TreeNode* root);

    //Prints the right side of the tree
    void traverseRight(TreeNode* root);
};

