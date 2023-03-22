// T.C: O(ROW*COL)
// M.C: O(ROW*COL)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> paths;
        paths.resize(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) paths[i][j] = 1;
                else paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};
