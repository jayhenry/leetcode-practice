#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isLeft(char &c) {
        auto ret = (c=='(' || c=='{' || c=='[');
        // cout << c << " is Left? " <<  ret << endl;
        return ret;
    }
    bool isMatch(char &c1, char &c2) {
        if ((c1=='(' && c2==')') || (c1=='{' && c2=='}') || (c1=='[' && c2==']')) {
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> cstack;
        for(auto c: s) {
            if (isLeft(c)) {
                cstack.push(c);
            }
            else {
                if (cstack.empty()) {
                    return false;
                }
                else {
                    auto c1 = cstack.top();
                    cstack.pop();
                    if (!isMatch(c1, c)) {
                        return false;
                    }
                }
            }
        }
        if (cstack.empty()) {
        return true;
        }
        return false;
    }
};

int main() {
    vector<string> inputs {"()", "()[]{}", "(]", "([)]", "{[]}"};
    Solution s;
    for (auto input: inputs) {
        auto ret = s.isValid(input);
        cout << input << "is valid? " << ret << endl;
    }
    return 0;
}