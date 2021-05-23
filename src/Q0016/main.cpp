#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <map>
#include <cstdlib>
using namespace std;


class Solution {
public:
    map<int, vector<pair<int, int>>> twosum2idxs;
    unordered_map<int, int> delta2idx;

    bool overlap(int idx, vector<pair<int,int>>& idxs) {
        for(auto ipair: idxs) {
            if (idx != ipair.first && idx != ipair.second) {
                return false;
            }
        }
        return true;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0, delta=2e9;
        int n = nums.size();
        for(int i=0; i<=n-2; i++) {
            for(int j=i+1; j<=n-1; j++) {
                auto sum = nums[i] + nums[j];
                twosum2idxs[sum].push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<=n-1;i++) {
            auto d = target - nums[i];
            delta2idx[d] = i;
        }
        int cur_d = 0;

        for(auto d2i: delta2idx) {
            auto d = d2i.first;
            auto idx = d2i.second;
            auto itlow = twosum2idxs.lower_bound(d);

            if (itlow!=twosum2idxs.end()) {
            auto up = itlow->first;
            auto up_idx = itlow->second;
            cur_d = up - d;
            if (cur_d < delta) {
                if (!overlap(idx, up_idx)) {
                    delta = cur_d;
                    res = target + delta;
                    if (cur_d == 0) {return res;}
                }
            }
            }

            if (itlow!=twosum2idxs.begin()) {
            itlow--;
            auto down = itlow->first;
            auto down_idx = itlow->second;
            cur_d = d - down;
            if (cur_d < delta) {
                if (!overlap(idx, down_idx)) {
                    delta = cur_d;
                    res = target - delta;
                    if (cur_d == 0) {return res;}
                }
            }
            }
            
            
        }

        return res;
    }
};


int main() {

    vector<int> nums{-1,2,1,-4};
    int target = 1;
    Solution s;
    auto res = s.threeSumClosest(nums, target);
    cout << "res " << res << endl;
    
    return 0;
}