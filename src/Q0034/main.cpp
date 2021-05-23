#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int start, int end, bool find_first) {
        int mid = 0;
        int first = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                if (find_first) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
                first = mid;
            }
        }
        return first;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;

        if (end < 0 || nums[0] > target || nums[end] < target) {
            return {-1, -1};
        }

        int first = -1, last = -1;

        // find first
        first = binarySearch(nums, target, start, end, true);

        if (first == -1) {
            return {-1, -1};
        }
        // find last
        start = first;
        end = nums.size() - 1;
        last = binarySearch(nums, target, start, end, false);
        return {first, last};
    }
};


int main() {
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    Solution s;
    auto res = s.searchRange(nums, target);
    for (auto r: res) {
        cout << r << endl;
    }

    return 0;
}