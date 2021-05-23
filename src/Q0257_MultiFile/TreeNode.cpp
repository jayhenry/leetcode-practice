#include "TreeNode.h"

vector<string> Solution::binaryTreePaths(TreeNode* root) {
    if (root == NULL) {
        return {};
    }
    if ((root->left == NULL) && (root->right == NULL)) {
        return {to_string(root->val)};
    }
    vector<string> result;
    vector<TreeNode*> chids {root->left, root->right};
    for (auto c: chids) {
        if (c == NULL) continue;

        auto tmp = binaryTreePaths(c);
        for (auto t: tmp) {
            stringstream ss;
            result.push_back(to_string(root->val) + "->" + t);
        }
    }
    return result;
};