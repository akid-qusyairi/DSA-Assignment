
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
    if (start->leftChild != NULL)
        return searchDown(start->leftChild, target);
    if (start->rightSibling != NULL)
        return search(start->rightSibling,target);
}

TreeNode* Tree::searchDown(TreeNode* start, string target) {
    if (start->item == target) {
        return start;
    }
    if (start->item != target) {
        if (start->rightSibling != NULL) {
            return search(start->rightSibling, target);
        }
    }
}

void Tree::insertsibling(string item)
{
    insertsibling(rootNode, item);
}

void Tree::insertsibling(TreeNode*& t, string item)
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
        TreeNode* tmp = t;
        while (tmp->rightSibling != NULL) {
            tmp = tmp->rightSibling;
        }
        TreeNode* newNode = new TreeNode;
        newNode->item = item;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        tmp->rightSibling = newNode;
    }
}

void Tree::insertchild(string item)
{
    insertchild(rootNode, item);
}

void Tree::insertchild(TreeNode*& t, string item)
{
    if (t == NULL)
    {
        TreeNode* newNode = new TreeNode;
        newNode->item = item;
        newNode->leftChild = NULL;
        newNode->rightSibling = NULL;
        t = newNode;
    }
    else
        insertsibling(t->rightSibling, item); 	// insert in right subtree
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
        cout << root->item <<"; ";
        if (root->leftChild != NULL) {
            cout << endl << "-----------" << endl;
            cout <<"Flights from: " <<root->item ;
            cout << endl << "Flights to: ";
            traverseTree(root->leftChild);
            cout << endl <<"-----------"<< endl;
        }
        root = root->rightSibling;
    }
}
