#include <cmath>
#include <cassert>
#include <stack>
#include "util.h"

struct TreeNode {
    int val; // value of the node
    TreeNode* left; // left child node
    TreeNode* right; // right child node
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // constructor
};

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> preorder;
    std::stack<TreeNode*> stack;

    if (root == nullptr)
        return preorder;

    stack.push(root);

    while(!stack.empty()) {
        TreeNode* curr = stack.top();
        stack.pop();
        preorder.push_back(curr->val);

        if (curr->right != nullptr)
            stack.push(curr->right);

        if (curr->left != nullptr)
            stack.push(curr->left);
    }

    return preorder;
}

int main() {
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    auto res = preorderTraversal(root);

    std::cout << "Result array: " << util::arrToStr(res) << "\n";

    assert(util::arraysEqual(res, {1, 2, 3, 4, 5}));
}