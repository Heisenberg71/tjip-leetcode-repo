class Solution {
private:
vector < vector<int> > grid = vector< vector<int> > (9, vector<int>(9, 0));

bool isValid(int r, int c, int val){
    for(int i = 0; i < 9; i++){
        if(grid[i][c] == val || grid[r][i] == val) return false;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + 3*(r/3)][j + 3*(c/3)] == val) return false;
        }
    }
    return true;
}

bool find_best_move(int& r, int& c){
    int min_collision = 100;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j]) continue;
            int collision = 0;
            for(int val = 1; val <= 9; val++)
                collision += isValid(i, j, val);
            if(collision < min_collision){
                min_collision = collision;
                r = i, c = j;
            }
        }
    }
    if(min_collision == 100) return false;
    return true;
}

bool backtrack(){
    int r, c;
    if(!find_best_move(r, c)) return true;
    for(int val = 1; val <= 9; val++){
        if(!isValid(r, c, val)) continue;
        cout << "uyt" << endl;
        grid[r][c] = val;
        if(backtrack()) return true;
    }
    grid[r][c] = 0;
    return false; 
}

public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    grid[i][j] = board[i][j] - '0';
                }
            }
        }

        backtrack();

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                board[i][j] = grid[i][j] + '0';
    }
};
