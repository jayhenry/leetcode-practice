#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
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
};


int main() {
    TreeNode r {
        1,
        new TreeNode{2, NULL, 
            new TreeNode{5, NULL, NULL}
        },
        new TreeNode{3, NULL, NULL}
    };

    cout << r.val << endl;
    cout << r.left->val << endl;
    cout << r.left->right->val << endl;
    cout << r.right->val << endl;

    Solution s;
    auto result = s.binaryTreePaths(&r);
    cout << "Result is:" << endl;
    for(auto res: result) {
       cout << res << endl;
    }

    return 0;
}