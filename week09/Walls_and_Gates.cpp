// T.C: O(GRID_SIZE)
// M.C: O(1)


class Solution {
private:
    constexpr static int adjMat[] = {0, 1, 0, -1, 0};
    bool isValid(int row, int col, int mxRow, int mxCol, vector<vector<int>>& rooms){
        if(row < 0 || mxRow <= row || col < 0 || mxCol <= col || rooms[row][col] == -1) return false;
        return true;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int mxRow = rooms.size(), mxCol = rooms[0].size();
        queue < vector<int> > Q;
        for(int row = 0; row < rooms.size(); row++)
            for(int col = 0; col < rooms[row].size(); col++)
                if(rooms[row][col] == 0) Q.push({row, col});

        while(!Q.empty()){
            vector <int> u = Q.front(); Q.pop();
            for(int changeDir = 0; changeDir < 4; changeDir++){
                vector <int> v;
                v.push_back(u[0] + adjMat[changeDir]); v.push_back(u[1] + adjMat[changeDir + 1]);
                if(isValid(v[0], v[1], mxRow, mxCol, rooms) && rooms[ u[0] ][ u[1] ] + 1 < rooms[ v[0] ][ v[1] ]){
                    rooms[ v[0] ][ v[1] ] =  rooms[ u[0] ][ u[1] ] + 1;
                    Q.push({v[0], v[1]});
                }
            }
        }
    }
};
