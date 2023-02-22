class Solution {
private:
    bool isValid(int row, int col, int mxRow, int mxCol, vector<vector<int>>& rooms){
        if(row < 0 || mxRow <= row || col < 0 || mxCol <= col || rooms[row][col] == -1) return 0;
        return 1;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int mxRow = rooms.size(), mxCol = rooms[0].size();
        queue < vector<int> > Q;
        for(int row = 0; row < rooms.size(); row++)
            for(int col = 0; col < rooms[row].size(); col++)
                if(rooms[row][col] == 0) Q.push({row, col});
            
        vector <int> dirRow(4, 0), dirCol(4, 0);
        dirRow[0] = -1, dirCol[0] = 0; dirRow[1] = 1, dirCol[1] = 0;
        dirRow[2] = 0, dirCol[2] = 1; dirRow[3] = 0, dirCol[3] = -1;

        while(!Q.empty()){
            vector <int> u = Q.front(); Q.pop();
            for(int changeDir = 0; changeDir < 4; changeDir++){
                vector <int> v;
                v.push_back(u[0] + dirRow[ changeDir ]); v.push_back(u[1] + dirCol[ changeDir ]);
                if(isValid(v[0], v[1], mxRow, mxCol, rooms) && rooms[ u[0] ][ u[1] ] + 1 < rooms[ v[0] ][ v[1] ]){
                    rooms[ v[0] ][ v[1] ] =  rooms[ u[0] ][ u[1] ] + 1;
                    Q.push({v[0], v[1]});
                }
            }
        }
    }
};
