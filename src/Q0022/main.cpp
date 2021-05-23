#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <memory>
using namespace std;

class Solution {
public:
    vector<string> res;
    void generate(string prefix, int ln, int rn){
        if(ln == 0 && rn == 0) {
            res.push_back(prefix);
            return;
        }

        if(ln > 0) {
            generate(prefix + "(", ln - 1, rn + 1);
        }
        if(rn > 0) {
            generate(prefix + ")", ln , rn -1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string init = "";
        generate(init, n, 0);
        return res;
    }
};


int main() {
    Solution s;
    auto res = s.generateParenthesis(3);
    for(auto r: res) {
        cout << r << endl;
    }
    return 0;
}