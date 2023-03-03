// T.C: O(GRID_SIZE)
// M.C: O(1)

class Solution {
private:
    bool isNewShip(int row, int col, vector<vector<char>>& board){
        if(board[row][col] != 'X') return false;
        if(0 < row && board[row - 1][col] == 'X') return false;
        if(0 < col && board[row][col - 1] == 'X') return false;
        return true;
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int shipCnt = 0;
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(isNewShip(row, col, board)) shipCnt++;
            }
        }
        return shipCnt;
    }
};
