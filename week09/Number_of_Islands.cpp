// T.C: O(N) Here, N = size of grid
// M.C: O(D) Here, D = max depth of recursion stack memory

class Solution {
private:
    constexpr static int adjMat[] = {0, 1, 0, -1, 0};
    bool isValid(int row, int col, vector<vector<char>>& grid){
        if(row < 0 || grid.size() <= row || col < 0 || grid[row].size() <= col || grid[row][col] != '1') return false;
        return true;
    }
    void DFS(int u_row, int u_col, vector<vector<char>>& grid){
        grid[u_row][u_col] = '0';
        for(int i = 0; i < 4; i++){
            int v_row = u_row + adjMat[i], v_col = u_col + adjMat[i + 1];
            if(isValid(v_row, v_col, grid)) DFS(v_row, v_col, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    DFS(i, j, grid);
                    islandCnt++;
                }
            }
        }

        return islandCnt;
    }
};
