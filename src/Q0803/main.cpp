#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void printGrid(vector<vector<int>>& grid) {
        for(auto line: grid) {
            for(auto p: line) {
                cout << p << "\t";
            }
            cout << endl;
        }
    }

    void Union(int a, int b, unordered_map<int, int>& set, unordered_map<int, int>& height, unordered_map<int, int>& num) {
        a = Find(a, set);
        b = Find(b, set);
        if (a == b) return;

        if(height[a]==height[b]) {
            height[a] += 1;
            set[b] = a;
            num[a] += num[b];
        }
        else if (height[a]<height[b]) {
            set[a] = b;
            num[b] += num[a];
        }
        else {
            set[b] = a;
            num[a] += num[b];
        }
        return;
    }

    int Find(int a, unordered_map<int, int>& set) {
        int r = a;
        while (set[r] != r) {
            r = set[r];
        }
        int i = a;
        int j;
        while (i!=r) {
            j = set[i];
            set[i] = r;
            i = j;
        }
        return r;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();
        int L = hits.size();
        vector<int> ret(L,0);
        vector<vector<int>> pairs;
        vector<int> values;
        unordered_map<int, int> set;
        unordered_map<int, int> height;
        unordered_map<int, int> num;
        
        vector<int> realhit;
        for(auto hit: hits) {
            if (grid[hit[0]][hit[1]]) realhit.push_back(1);
            else realhit.push_back(0);

            grid[hit[0]][hit[1]] = 0;
        }

        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (grid[i][j] == 0) continue;
                
                int v = i*m + j;
                if (i==0) { values.push_back(v); }
                set[v] = v;
                height[v] = 1;
                num[v] = 1;
                if (i<n-1 && grid[i+1][j]!=0) {int v2=(i+1)*m + j; pairs.push_back({v, v2});}
                if (j<m-1 && grid[i][j+1]!=0) {int v2=i*m + j+1; pairs.push_back({v, v2});}
            }
        }

        for(auto pr: pairs) {
            Union(pr[0], pr[1], set, height, num);
        }

        int virtualv = -1;
        set[virtualv] = virtualv;
        height[virtualv] = 1;
        num[virtualv] = 1;
        for (auto v: values) {
            Union(virtualv, v, set, height, num);
        }
        // cout << "Initial virtualv node " << Find(virtualv, set) << endl;

        for(int l=L-1; l>=0; l--) {
            if (realhit[l] == 0) {
                continue;
            }
            int i=hits[l][0], j=hits[l][1];
            // cout << "Doing " << l << ", ij is " << i << "," << j << ". virtual node " << Find(virtualv, set) << endl;
            int drop_num = 0;
            int fixv = 0, hitv = 0;
            bool real_drop = false;
            hitv = i*m + j;
            grid[i][j] = 1;
            set[hitv] = hitv;
            height[hitv] = 1;
            num[hitv] = 1;
            vector<int> real_drop_vs;
            if (i==0) {
                real_drop_vs.push_back(hitv);
                real_drop = true;
            }

            int i2, j2, v2, fv2;
            for(int deltav=0; deltav<4; deltav++){
                i2 = i;
                if (deltav == 0) i2 = i+1;
                else if (deltav == 1) i2 = i-1;
                j2 = j;
                if (deltav == 2) j2 = j+1;
                else if (deltav == 3) j2 = j-1;

                if (i2<0 || i2>=n || j2<0 || j2>=m) continue;

                if (grid[i2][j2]) {
                    v2 = i2*m + j2;
                    fixv = Find(virtualv, set);
                    fv2 = Find(v2, set);
                    if (fv2 != fixv) {
                        if (fv2 != Find(hitv, set)) {
                            drop_num += num[fv2];
                            real_drop_vs.push_back(fv2);
                        }
                    }
                    else {
                        real_drop = true;
                    }
                    Union(fv2, hitv, set, height, num);
                    // cout << "In deltav " << deltav << " condition, fixv " << fixv << " fv2 " << fv2 << " drop_num " << drop_num << endl;
                }
            }
            // cout << "Done " << l << " real_drop " <<real_drop << " drop_num " <<drop_num <<endl;
            if (real_drop) {
                ret[l] = drop_num;
                for (int vv: real_drop_vs) {
                    Union(vv, virtualv, set, height, num);
                }
            }
        }

        return ret;
    }
};

int main() {
    // vector<vector<int>> grid {{1,0,0,0},{1,1,1,0}};
    // vector<vector<int>> hits {{1,0}};
    // [[1],[1],[1],[1],[1]]
    // [[3,0],[4,0],[1,0],[2,0],[0,0]]
    vector<vector<int>> grid {{1},{1},{1},{1},{1}};
    vector<vector<int>> hits {{3,0},{4,0},{1,0},{2,0},{0,0}};
    // vector<vector<int>> grid {{1,0,1},{1,1,1}};
    // vector<vector<int>> hits {{0,0},{0,2},{1,1}};
    // [[1,1,0,1,0],[1,1,0,1,1],[0,0,0,1,1],[0,0,0,1,0],[0,0,0,0,0],[0,0,0,0,0]]
    // [[5,1],[1,3]]
    // vector<vector<int>> grid {{1,1,0,1,0},{1,1,0,1,1},{0,0,0,1,1},{0,0,0,1,0},{0,0,0,0,0},{0,0,0,0,0}};
    // vector<vector<int>> hits {{5,1},{1,3}};
    Solution s;
    auto drops = s.hitBricks(grid, hits);
    for (auto d: drops) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}