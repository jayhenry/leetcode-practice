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
    bool is_match_;

    void loop_ans_tree(string& s, string& p, int s_idx, int p_idx) {
        if (is_match_) {return; }
        if (s_idx > s.size()) {return;}

        if ((s_idx == s.size() && p_idx == p.size()) 
            // || (s_idx == s.size() && p_idx == p.size() - 1 && p[p_idx] == '*')
        ){
            is_match_ = true;
            return;
        }

        if (p_idx >= p.size()) { return; }
        auto pi = p[p_idx];
        if (pi == '*') {
            // case 1: * is empty
            loop_ans_tree(s, p, s_idx, p_idx+1);
            // case 2: * is not empty, equal to si
            loop_ans_tree(s, p, s_idx+1, p_idx);
            return;
        }

        if (s_idx >= s.size()) { return; }
        auto si = s[s_idx];
        if (pi != '?' && pi != '*') {
            if (pi != si) {
                return;
            }
            loop_ans_tree(s, p, s_idx+1, p_idx+1);
            return;
        }
        if (pi == '?') {
            loop_ans_tree(s, p, s_idx+1, p_idx+1);
            return;
        }
    }

    bool isMatch(string s, string p) {
        is_match_ = false;
        // if (s.empty() && p.empty()) {
        //     is_match_ = true;
        //     return is_match_;
        // }

        loop_ans_tree(s, p, 0, 0);
        return is_match_;
    }
};


int main() {
    vector<pair<string, string>> snps = {
        {"aa", "a"},
        {"aa", "*"},
        {"cb", "?a"},
        {"adceb", "*a*b"},
        {"acdcb", "a*c?b"},
        {"", "*****"},
        {"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"}
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