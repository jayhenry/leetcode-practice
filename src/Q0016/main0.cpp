#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <cstdlib>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0, delta=2147483647;
        int i,j,k;
        int n = nums.size();
        for(i=0; i<=n-3; i++) {
            for(j=i+1; j<=n-2; j++) {
                for(k=j+1; k<=n-1; k++) {
                    auto sum = nums[i] + nums[j] + nums[k];
                    auto d = abs(sum - target);
                    if (d == 0) return sum;
                    if (d < delta) {
                        res = sum;
                        delta = d;
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