#include<iostream>
using namespace std;
#include "Tree.h"

//======================================//
//      Done By: Chua Jing Yi, Jax      //
//         StudentID: S10196708         //
//======================================//


//Constructor
Tree::Tree(){ rootNode = NULL; }    

//Helper function to call search
TreeNode* Tree::search(string target)
{
    return search(rootNode, target);
}

//Searches the tree at start node for the string target, if found, returns the node.
TreeNode* Tree::search(TreeNode* start, string target) {
    if (start == NULL)
        return NULL;
    if (start->item == target) 
        return start;
    if (search(start->leftChild, target) != NULL)
        return search(start->leftChild, target);
    if (search(start->rightSibling, target) != NULL)
        return search(start->rightSibling,target);
    return NULL;
}

//Searches the right siblings of the tree for the target, returns node if found.
TreeNode* Tree::searchSibling(TreeNode* start, string target) {
    if (start == NULL)
        return NULL;
    if (start->item == target)
        return start;
    if (search(start->rightSibling, target) != NULL)
        return search(start->rightSibling, target);
    return NULL;
}

//Helper function  to insert
void Tree::insert(string item)
{
    insert(rootNode, item);
}

//insert item at the node that is inputted recursively
void Tree::insert(TreeNode*& t, string item)
{
    if (t == NULL)
    {
        TreeNode* newNode = new TreeNode;
        newNode->item = item;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        t = newNode;
    }
    else {
        insert(t->rightSibling, item);
    }
}

//delete the node and its children recursively
TreeNode* Tree::deleteNode(TreeNode*& child)
{
    TreeNode* newNode = NULL;
    if (child != NULL) {
        while (child->leftChild != NULL) {
            child->leftChild = deleteNode(child->leftChild);
        }
        newNode = child->rightSibling;
        free(child);
    }
    return newNode;
}

//returns the rootNode
TreeNode* Tree::getTop() { return rootNode; }

//Check if rootNode is empty
bool Tree::isEmpty() { return rootNode == NULL; }

//Helper function to call traversetree()
void Tree::traverseTree() {
    traverseTree(rootNode);
}

//Prints out the tree by parent node and then children nodes
void Tree::traverseTree(TreeNode* root)
{
    if (root == NULL)
        return;
    while (root != NULL)
    {
        if (root->leftChild != NULL) {
            cout << "Origin: " << root->item << endl;
            cout << "Destinations: ";
            traverseRight(root->leftChild);
            cout << endl << "----------------------------------------------" << endl;
            traverseTree(root->leftChild);
        }
        root = root->rightSibling;
    }
}

void Tree::traverseRight(TreeNode* root) {
    if (root == NULL)
        return;
    else{
        cout << root->item << "; ";
        traverseRight(root->rightSibling);
    }
}
