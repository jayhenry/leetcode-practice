#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> combine(string digits, unordered_map<char, vector<string>>& d2s) {
        auto sz = digits.size();
        if (sz == 0) return {};

        auto subres = combine(digits.substr(1, sz-1), d2s);
        vector<string> res;
        auto curc = digits[0];
        auto letters = d2s[curc];
        for(auto l: letters) {
            for(auto sr: subres) {
                res.push_back(l+sr);
            }
            if (subres.empty()) {
                res.push_back(l);
            }
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> d2s;
        d2s['2'] = {"a", "b", "c"};
        d2s['3'] = {"d", "e", "f"};
        d2s['4'] = {"g", "h", "i"};
        d2s['5'] = {"j", "k", "l"};
        d2s['6'] = {"m", "n", "o"};
        d2s['7'] = {"p", "q", "r", "s"};
        d2s['8'] = {"t", "u", "v"};
        d2s['9'] = {"w", "x", "y", "z"};

        auto res = combine(digits, d2s);

        // res
        // for p in digits:
         // for y in pool:
          // for x in res:
           // new_res.append(x+[y])
         // res = new_res


        return res;
    }
};


int main() {
    string input = "23";
    Solution s;
    auto res = s.letterCombinations(input);
    for(auto r: res) {
        cout << r << endl;
    }
    return 0;
}