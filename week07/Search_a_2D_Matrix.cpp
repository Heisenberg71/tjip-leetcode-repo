// T.C: O(logR + logC) // Here, R = row size, C = colomn size
// M.C: O(1)
class Solution {
private:
    const static int INVALID = -1;
    int binarySearchOnRow(vector<vector<int>>& matrix, int target){
        int lo = 0, hi = matrix.size() - 1, nearestRow = INVALID;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid][0] <= target){
                nearestRow = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return nearestRow;
    }
    bool binarySearchOnColomn(vector<vector<int>>& matrix, int target, int currRow){
        if(currRow == INVALID) return false;
        int lo = 0, hi = matrix[0].size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[currRow][mid] == target) return true;
            else if(matrix[currRow][mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currRow = binarySearchOnRow(matrix, target);
        return binarySearchOnColomn(matrix, target, currRow);
    }
};
