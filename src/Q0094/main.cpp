#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> res;

    void inorder(TreeNode* n) {
        if (n==NULL) return;
        inorder(n->left);
        res.push_back(n->val);
        inorder(n->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};


void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}


int main() {
    TreeNode* root = new TreeNode{
        1, NULL, new TreeNode {
            2, new TreeNode {3, NULL, NULL}, NULL
        }
    };
    Solution s;
    printTree(root);
    cout << endl;
    auto res = s.inorderTraversal(root);
    for(auto r: res) cout << r << " ";
    cout << endl;
    return 0;
}