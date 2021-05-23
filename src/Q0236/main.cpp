#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l=NULL, TreeNode* r=NULL) : val(x), left(l), right(r) {}
};


class Solution {
public:
    unordered_map<int, bool> has_p;
    unordered_map<int, bool> has_q;

    void setHasPQ(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return;
        bool c_has_p=false, c_has_q=false;

        if (root->left != NULL) {
            setHasPQ(root->left, p, q);
            auto l = root->left->val;
            c_has_p = c_has_p || has_p[l];
            c_has_q = c_has_q || has_q[l];
        }
        if (root->right != NULL) {
            setHasPQ(root->right, p, q);
            auto l = root->right->val;
            c_has_p = c_has_p || has_p[l];
            c_has_q = c_has_q || has_q[l];
        }
        auto c = root->val;
        if (c == p->val) {c_has_p = true;}
        if (c == q->val) {c_has_q = true;}
        has_p[c] = c_has_p;
        has_q[c] = c_has_q;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        setHasPQ(root, p, q);
        TreeNode* res = root;
        while(1) {
            if (res->left && has_q[res->left->val] && has_p[res->left->val]) {
                res = res->left;
            } 
            else if (res->right && has_q[res->right->val] && has_p[res->right->val]) {
                res = res->right;
            }
            else {
                break;
            }
        }
        return res;
    }
};


int main() {

    auto root = new TreeNode {
        3,
        new TreeNode{
            5,
            new TreeNode{6},
            new TreeNode {
                2,
                new TreeNode {7},
                new TreeNode {4}
            }
        },
        new TreeNode{
            1,
            new TreeNode{0},
            new TreeNode{8}
        }
    };
    TreeNode* p = root->left;
    // TreeNode* q = root->right;
    TreeNode* q2 = p->right->right;
    Solution s;
    // auto res = s.lowestCommonAncestor(root, p, q);
    auto res2 = s.lowestCommonAncestor(root, p, q2);

    // cout << "result " << res->val << endl;
    cout << "result2 " << res2->val << endl;
    
    return 0;
}