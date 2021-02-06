
#include<iostream>
using namespace std;
#include "Tree.h"


Tree::Tree(){ rootNode = NULL; }    

TreeNode* Tree::search(string target)
{
    return search(rootNode, target);
}

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

TreeNode* Tree::searchSibling(TreeNode* start, string target) {
    if (start == NULL)
        return NULL;
    if (start->item == target)
        return start;
    if (search(start->rightSibling, target) != NULL)
        return search(start->rightSibling, target);
    return NULL;
}


void Tree::insert(string item)
{
    insert(rootNode, item);
}

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

TreeNode* Tree::getTop() { return rootNode; }
bool Tree::isEmpty() { return rootNode == NULL; }

void Tree::traverseTree() {
    traverseTree(rootNode);
}

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
