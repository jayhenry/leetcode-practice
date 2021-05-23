#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;

        int len = s.length();
        vector<int> L(len, 0); // longest length of substring start at i
        L[len-1] = 0;
        for(int i=len-2; i>=0; i--) {
            if (s[i] == ')') {
                L[i] = 0;
                continue;
            }
            // s[i] == '('
            if (s[i+1] == ')') {
                if (i + 2 < len) {
                    L[i] = 2 + L[i+2];
                }
                else {
                    L[i] = 2;
                }
                continue;
            }
            //  and s[i+1] == '('
            int end = i + 1 + L[i+1];
            if (end >= len) {
                L[i] = 0;
            }
            else if (s[end] == ')') {
                if (end + 1 >= len) {
                    L[i] = 2 + L[i+1];
                }
                else {
                    L[i] = 2 + L[i+1] + L[end + 1];
                }
            }
            else {
                L[i] = 0;
            }
        }
        
        int longest = 0;
        // for(int i=0; i < len; i++) {
        for (auto l: L) {
            // int l = L[i];
            // cout << "i:" << i << ", l:" << l << endl;
            if (l > longest) longest = l;
        }

        return longest;
    }
};


int main() {
    // string in1 = "(()";
    //string in1 = ")()())";
    // string in1 = ")()())()()(";
    string in1 = "((()))())";
    Solution s;
    auto res = s.longestValidParentheses(in1);
    cout << "in: '" << in1 << "', res: " << res << endl;

    return 0;
}