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

    void find(int target, vector<int>& candidates, int cur_index, vector<int>& cur_arr) {
        if (target < 0 || cur_index >= candidates.size()) return;

        if (target == 0) {
            ans_.push_back(cur_arr);
            return;
        }

        // not use cur_index
        find(target, candidates, cur_index+1, cur_arr);

        // use cur_index
        auto x = candidates[cur_index];
        target -= x;
        if (target >= 0) {
            cur_arr.push_back(x);
            find(target, candidates, cur_index, cur_arr);
            cur_arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        find(target, candidates, 0, arr);
        return ans_;
    }
};


int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution s;
    auto res = s.combinationSum(candidates, target);
    for(auto r: res) {
        for(auto x: r) cout << x << " ";
        cout << endl;
    }
    cout << "hello " << endl;

    return 0;
}