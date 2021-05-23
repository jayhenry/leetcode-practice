#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        auto len = A.size();
        if (len < 3) {return 0;}

        for (int i=len-1; i>=2; i--) {
            if (A[i] < A[i-1] +A[i-2]) {
                return A[i] + A[i-1] + A[i-2];
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> inputs {{2,1,2}, {1,2,1}, {3,2,3,4}, {3,6,2,3}};
    Solution s;
    for (auto input: inputs) {
        auto ret = s.largestPerimeter(input);
        for (auto i: input) { cout << i << " " ;}
        cout << ", largest perimeter is : " << ret << endl;
    }
    return 0;
}