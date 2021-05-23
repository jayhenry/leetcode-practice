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
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if (m == 0) {
            if (n == 0) return true;
            if (all_of(p.begin(), p.end(), [](char i) {return i=='*';})) return true;
            return false;
        }

        if (n == 0) {
            return false;
        }

        vector<vector<bool>> M(m, vector<bool>(n, false));
        
        // initial M[0][:]
        bool real_match = false;
        for(int j=0; j<n; j++) {
            if (real_match && p[j] != '*') break;
            if (p[j] == '*') {
                M[0][j] = true;
            }
            else if (p[j] == '?' || p[j] == s[0]) {
                M[0][j] = true;
                real_match = true;
            }
            else {
                break;
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(p[j] == s[i] || p[j] == '*' || p[j] == '?') {
                    if (p[j] == '*' && M[i-1][j]) {
                        M[i][j] = true;
                    }
                    else if (p[j] == '*' && j>0 && M[i][j-1]) {
                        M[i][j] = true;
                    }
                    else if (j > 0 && M[i-1][j-1] == true) {
                        M[i][j] = true;
                    }
                }
            }
        }

        return M[m-1][n-1];
    }
};


int main() {
    vector<pair<string, string>> snps = {
        {"a", "a*"},
        {"aa", "a"},
        {"aa", "*"},
        {"cb", "?a"},
        {"adceb", "*a*b"},
        {"acdcb", "a*c?b"},
        {"", "*****"},
        {"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaabab", "a*******b"},
        {"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"},
        {"abcabczzzde", "*abc???de*"}
    };

    Solution sol;

    for(auto snp: snps) {
        auto s = snp.first;
        auto p = snp.second;
        auto r = sol.isMatch(s, p);
        cout << s << " " << p << " " << r << endl;
    }

    return 0;
}