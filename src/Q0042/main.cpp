#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // find right max index
        vector<int> RI(n, -1);
        RI[n-2] = n-1;
        for(int i=n-3; i>=0;i--) {
            auto pre_idx = RI[i+1];
            if (height[pre_idx] >= height[i+1]) {
                RI[i] = pre_idx;
            }
            else {
                RI[i] = i+1;
            }
        }

        // find [left_index, right_index) tuples
        vector<pair<int, int>> lrs;
        int start = -1;
        int end = -1;
        int cur = 0;
        start = cur;
        while(cur <= n-2) {
            int ri = RI[start];
            if (height[ri] <= height[start]) {
                end = cur = ri;
                lrs.push_back({start, end});
                start = cur;
            }
            else {
                while(true) {
                    cur++;
                    if (height[cur] > height[ri]) {
                        end = cur;
                        break;
                    }
                }
                lrs.push_back({start, end});
                start = end;
            }
        }
        
        // sum drops between [left, right) pairs
        int total;
        for(auto lr: lrs) {
            auto left = lr.first;
            auto right = lr.second;
            int cur_h = height[left];
            if (height[right] > cur_h) {
                cur_h = height[right];
            }
            for(int i=left; i<right; i++) {
                if (cur_h > height[i]) {
                    total += cur_h - height[i];
                }
            }
        }
        return total;
    }
};


int main() {
    vector<vector<int>> heights = {
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {4,2,0,3,2,5},
    };

    Solution sol;

    for(auto height: heights) {
        auto r = sol.trap(height);
        cout << "result: " << r << endl;
    }

    return 0;
}