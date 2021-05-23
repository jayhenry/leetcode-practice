#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<int>>& grid, bool& drop, vector<int>& ps) {
        if (i<0 || j <0 || i>=n || j>=m) return;
        if (grid[i][j]==0 || grid[i][j]==2) return;
        grid[i][j] = 2;
        ps.push_back(i*m+j);
        if (i==0 && drop) {drop=false;}
        bfs(i-1, j, n, m, grid, drop, ps);
        bfs(i+1, j, n, m, grid, drop, ps);
        bfs(i, j-1, n, m, grid, drop, ps);
        bfs(i, j+1, n, m, grid, drop, ps);
    }

    void afterBfs(vector<vector<int>>& grid, int& drop_num, vector<int>& ps, int m, bool drop) {
        int pad=0;
        if (drop) {
                drop_num+=ps.size();
                pad=0;
            }
            else {pad=1;}
            for(auto p: ps) {
                int x = p % m;
                int y = p / m;
                grid[y][x] = pad;
            }
    }

    void printGrid(vector<vector<int>>& grid) {
        for(auto line: grid) {
            for(auto p: line) {
                cout << p << "\t";
            }
            cout << endl;
        }
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> ret;
        auto n = grid.size();
        auto m = grid[0].size();
        // auto status = grid;
        for(auto hit: hits) {
            // remove hit
            auto p = grid[hit[0]][hit[1]];
            if (p == 0) {
                ret.push_back(0);
                continue;
            }
            int i=hit[0], j=hit[1];
            grid[i][j] = 0;

            // iterate over surrounding points
            int drop_num = 0;
            bool drop = true;
            vector<int> ps;
            bfs(i-1, j, n, m, grid, drop, ps);
            afterBfs(grid, drop_num, ps, m, drop);

            drop = true;
            ps.clear();
            bfs(i+1, j, n, m, grid, drop, ps);
            afterBfs(grid, drop_num, ps, m, drop);

            drop = true;
            ps.clear();
            bfs(i, j-1, n, m, grid, drop, ps);
            afterBfs(grid, drop_num, ps, m, drop);

            drop = true;
            ps.clear();
            bfs(i, j+1, n, m, grid, drop, ps);
            afterBfs(grid, drop_num, ps, m, drop);

            // cout << "hit:" << hit[0] << "," << hit[1] << endl;
            // printGrid(grid);

            // cout << "After modify, drop " << drop_num << endl;
            // printGrid(grid);
            ret.push_back(drop_num);
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> grid {{1,0,0,0},{1,1,1,0}};
    vector<vector<int>> hits {{1,0}};
    Solution s;
    auto drops = s.hitBricks(grid, hits);
    for (auto d: drops) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}