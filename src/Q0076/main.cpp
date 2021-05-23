#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans_;

    void dfs_ans_tree(vector<int>& nums, int index, vector<int>& a) {
        if (index >= nums.size()) {
            ans_.push_back(a);
            return;
        }
        // not use 
        dfs_ans_tree(nums, index+1, a);

        // use
        a.push_back(nums[index]);
        dfs_ans_tree(nums, index+1, a);
        a.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        dfs_ans_tree(nums, 0, a);
        return ans_;
    }
};


int main() {
    vector<int> nums = {2,3,7};
    Solution s;
    auto res = s.subsets(nums);
    for(auto r: res) {
        for(auto x: r) cout << x << " ";
        cout << endl;
    }

    return 0;
}