#include <string>
using namespace std;

typedef string ItemType;

struct TreeNode {
    ItemType item;
    struct TreeNode* leftChild;
    struct TreeNode* rightSibling;
};