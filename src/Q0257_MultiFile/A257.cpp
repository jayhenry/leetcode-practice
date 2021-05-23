#include "TreeNode.h"

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