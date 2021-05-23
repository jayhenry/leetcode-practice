#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i<0 || j <0 || i>=n || j>=m) return;
        if (grid[i][j]==0 || grid[i][j]==2) return;
        grid[i][j] = 2;
        bfs(i-1, j, n, m, grid);
        bfs(i+1, j, n, m, grid);
        bfs(i, j-1, n, m, grid);
        bfs(i, j+1, n, m, grid);
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
            grid[hit[0]][hit[1]] = 0;

            // iterate over first line
            int i=0, j=0;
            for(j=0; j<m; j++) {
                if (grid[i][j]==0) continue;
                // iterate over connected points
                bfs(i, j, n, m, grid);
            }

            // cout << "hit:" << hit[0] << "," << hit[1] << endl;
            // printGrid(grid);

            // count current all numbers
            int drop_num = 0;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(grid[i][j]==2) {
                        grid[i][j] = 1;
                    }
                    else if(grid[i][j]==1) {
                        drop_num+=1; 
                        grid[i][j]=0;
                    }
                }
            }
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