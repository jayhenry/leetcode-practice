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
    void loop_ans_tree(vector<int>& nums, vector<int>& answer, int index) {
        if (index == nums.size()) {
            ans_.push_back(answer);
            return ;
        }

        for (auto n: nums) {
            bool used = false;
            for(int i=0; i<index; i++) {
                if (answer[i] == n) {
                    used = true;
                    break;
                }
            }
            if (used) continue;
            answer[index] = n;
            loop_ans_tree(nums, answer, index + 1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        loop_ans_tree(nums, answer, 0);
        return ans_;
    }
};


int main() {
    vector<int> nums = {2,3,7};
    Solution s;
    auto res = s.permute(nums);
    for(auto r: res) {
        for(auto x: r) cout << x << " ";
        cout << endl;
    }

    return 0;
}