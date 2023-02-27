// T.C: O(ROW*log(COL) + COL*log(ROW))
// M.C: O(1)

class Solution {
private:
    bool checkAllRowofCol(int col, vector<vector<char>>& image){
        int H = image.size(), W = image[0].size();
        for(int row = 0; row < H; row++){
            if(image[row][col] == '1') return true;
        }
        return false;
    }
    bool checkAllColofRow(int row, vector<vector<char>>& image){
        int H = image.size(), W = image[0].size();
        for(int col = 0; col < W; col++){
            if(image[row][col] == '1') return true;
        }
        return false;
    }
    int leftORrightmostCol(int col, vector<vector<char>>& image, int isLeft){
        int lo = col + 1, hi = image[0].size() - 1, border = col;
        if(isLeft) lo = 0, hi = col - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(checkAllRowofCol(mid, image)){
                border = mid;
                if(isLeft) hi = mid - 1;
                else lo = mid + 1;
            }
            else{
                if(isLeft) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return border;
    }
    int upORdownmostRow(int row, vector<vector<char>>& image, int isUp){
        int lo = row + 1, hi = image.size() - 1, border = row;
        if(isUp) lo = 0, hi = row - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(checkAllColofRow(mid, image)){
                border = mid;
                if(isUp) hi = mid - 1;
                else lo = mid + 1;
            }
            else{
                if(isUp) lo = mid + 1;
                else  hi = mid - 1;
            }
        }
        return border;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = leftORrightmostCol(y, image, true);
        int right = leftORrightmostCol(y, image, false);
        int up = upORdownmostRow(x, image, true);
        int down = upORdownmostRow(x, image, false);
        return (right - left + 1)*(down - up + 1);
    }
};
