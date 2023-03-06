// T.C: O(GRID_SIZE*(2^STRING_SIZE) + log(GRID_SIZE))
// M.C: O(GRID_SIZE)

class Solution {
private:
    constexpr static int adj[] = {0, 1, 0, -1, 0};

    bool isMatched(char ch, int row, int col, vector<vector<char>>& board){
        int rowSize = board.size(), colSize = board[0].size();
        if(row < 0 || rowSize <= row || col < 0 || colSize <= col || ch != board[row][col]) return false;
        return true;
    }

    bool backtrack(int pos, int row, int col, vector<vector<char>>& board, string& word, map<pair<int, int>, bool>& visited){
        if(!isMatched(word[pos], row, col, board)) return false;
        if(pos + 1 == word.size()) return true;

        bool wordFound = false;
        for(int i = 0; i < 4; i++){
            int newRow = row + adj[i], newCol = col + adj[i + 1];
            if(visited[{newRow, newCol}]) continue;
            
            visited[{newRow, newCol}] = true;
            wordFound |= backtrack(pos + 1, newRow, newCol, board, word, visited);
            visited[{newRow, newCol}] = false;
        }
        return wordFound;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool wordFound = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                map<pair<int, int>, bool> visited;
                visited[{i, j}] = true;
                wordFound |= backtrack(0, i, j, board, word, visited);
            }
        }
        
        return wordFound;
    }
};
