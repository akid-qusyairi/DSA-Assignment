#pragma once
#include <string>
#include <iostream>
#include "TreeNode.h"
using namespace std;


class Tree
{
private:

    TreeNode* rootNode;
public:
    Tree();

    TreeNode* search(string target);
    TreeNode* search(TreeNode* start, string target);

    TreeNode* searchSibling(TreeNode* start, string target);

    void insert(string item);
    void insert(TreeNode*& t, string item);

    TreeNode* deleteNode(TreeNode*& child);

    TreeNode* getTop();
    bool isEmpty();
    void traverseTree();
    void traverseTree(TreeNode* root);
    void traverseRight(TreeNode* root);
};

