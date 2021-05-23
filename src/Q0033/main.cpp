#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = nums[0];
        bool is_large = target >= pivot;
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;

        while (end >= start) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (is_large) {
                if (nums[mid] >= pivot) {
                    if (nums[mid] > target) {
                        end = mid - 1;
                    }
                    else {
                        start = mid + 1;
                    }
                }
                else {
                    end = mid - 1;
                }
            }
            else {
                if (nums[mid] >= pivot) {
                    start = mid + 1;
                }
                else {
                    if (nums[mid] > target) {
                        end = mid - 1;
                    }
                    else {
                        start = mid + 1;
                    }
                }
            }
        }

        return -1;
    }
};


int main() {
    vector<int> in1 = {4,5,6,7,0,1,2};
    int target = 0;
    Solution s;
    auto res = s.search(in1, target);
    cout << "res: " << res << endl;

    return 0;
}