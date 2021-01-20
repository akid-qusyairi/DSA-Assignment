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

    TreeNode* searchDown(TreeNode* start, string target);

    void insertsibling(string item);
    void insertsibling(TreeNode*& t, string item);

    void insertchild(string item);
    void insertchild(TreeNode*& t, string item);

    TreeNode* getTop();
    bool isEmpty();
    void traverseTree();
    void traverseTree(TreeNode* root);
};

