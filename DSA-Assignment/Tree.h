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

    TreeNode* search(ItemType target);
    TreeNode* search(TreeNode* start, ItemType target);

    TreeNode* searchDown(TreeNode* start, ItemType target);

    void insertsibling(ItemType item);
    void insertsibling(TreeNode*& t, ItemType item);

    void insertchild(ItemType item);
    void insertchild(TreeNode*& t, ItemType item);

    TreeNode* getTop();
    bool isEmpty();
    void traverseTree();
    void traverseTree(TreeNode* root);
};

