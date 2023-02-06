// T.C: O(NlogN), Here, N = number of intervals
// M.C: O(1)


class Solution {
private:
    static bool endAsc(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), endAsc);
        int minRemove = intervals.size(), lastTakenEnd = INT_MIN;
        for(int i = 0; i < intervals.size(); i++){
            if(lastTakenEnd <= intervals[i][0]){
                minRemove--;
                lastTakenEnd = intervals[i][1];
            }
        }
        return minRemove;
    }
};
