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
    bool is_exist_;
    unordered_set<int> visited_;
    vector<pair<int, int>> directs_;

    void dfs_ans_tree(vector<vector<char>>& board, string& word, int word_index, int x, int y) {
        if (is_exist_ || word_index >= word.size() - 1) {
            is_exist_ = true;
            return;
        }

        if (word.size() <= 0) {
            is_exist_ = true;
            return;
        }

        int h = board.size();
        if (h <= 0) {
            return;
        }
        int w = board[0].size();
        if (w <= 0) {
            return;
        }

        for(auto d : directs_) {
            int x1 = x + d.first;
            int y1 = y + d.second;
            int flat_idx = y1 * w + x1;
            if (x1 < 0 || x1 >= w || y1 < 0 || y1 >= h || visited_.find(flat_idx) != visited_.end()) {
                continue;
            }
            if (board[y1][x1] != word[word_index + 1]) {
                continue;
            }
            visited_.insert(flat_idx);
            dfs_ans_tree(board, word, word_index + 1, x1, y1);
            visited_.erase(flat_idx);
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        is_exist_ = false;
        visited_.clear();
        directs_.push_back({-1,0});
        directs_.push_back({0,-1});
        directs_.push_back({1,0});
        directs_.push_back({0,1});

        for(int y=0; y<board.size(); y++) {
            for(int x=0; x<board[0].size(); x++) {
                if (board[y][x] == word[0]) {
                    int flat_idx = y * board[0].size() + x;
                    visited_.insert(flat_idx);
                    dfs_ans_tree(board, word, 0, x, y);
                    visited_.erase(flat_idx);
                }
                if (is_exist_) break;
            }
            if (is_exist_) break;
        }
        return is_exist_;
    }
};


int main() {
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    vector<string> word_vec = {
        "ABCCED",
        "SEE",
        "ABCB"
    };
    Solution s;

    for(auto word: word_vec) {
        auto res = s.exist(board, word);
        cout << "word: " << word << ", exists? " << res << endl;
    }

    return 0;
}