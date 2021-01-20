#include <string>
using namespace std;

struct TreeNode {
    string item;
    struct TreeNode* leftChild;
    struct TreeNode* rightSibling;
};