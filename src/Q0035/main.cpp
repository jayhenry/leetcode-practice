#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        for(idx=0; idx<nums.size(); idx++) {
            if (target <= nums[idx]) {
                return idx;
            }
        }
        return idx;
    }
};

int main() {
    vector<pair<vector<int>, int>> inputs {
        {{1,3,5,6}, 5},
        {{1,3,5,6}, 2},
        {{1,3,5,6}, 7},
        {{1,3,5,6}, 0}
    };

    Solution s;

    for (auto each: inputs) {
        auto res = s.searchInsert(each.first, each.second);
        for (auto c: each.first) {
            cout << c << ",";
        }
        cout << "insert " << each.second << " at " << res << endl;
    }

    return 0;
}

