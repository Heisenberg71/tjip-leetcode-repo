// TC: O(NlogN)
// MC: O(N)

class Solution {
public:
    static bool comp(vector <int> &a, vector <int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector < vector<int> > non_overlapped_intervals;
        for(int i = 0; i < intervals.size(); i++){
            int current_size = non_overlapped_intervals.size();
            if(non_overlapped_intervals.empty())
                non_overlapped_intervals.push_back(intervals[i]);
            else if(non_overlapped_intervals[current_size - 1][1] >= intervals[i][0]){
                non_overlapped_intervals[current_size - 1][1] = max(non_overlapped_intervals[current_size - 1][1] ,intervals[i][1]);
            }
            else non_overlapped_intervals.push_back(intervals[i]);
        }
        return non_overlapped_intervals;
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// TC: O(MAX)
// MC: O(MAX)

class Solution {
public:
    static bool comp(vector <int> &a, vector <int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector < vector<int> > non_overlapped_intervals;
        for(int i = 0; i < intervals.size(); i++){
            int current_size = non_overlapped_intervals.size();
            if(non_overlapped_intervals.empty())
                non_overlapped_intervals.push_back(intervals[i]);
            else if(non_overlapped_intervals[current_size - 1][1] >= intervals[i][0]){
                non_overlapped_intervals[current_size - 1][1] = max(non_overlapped_intervals[current_size - 1][1] ,intervals[i][1]);
            }
            else non_overlapped_intervals.push_back(intervals[i]);
        }
        return non_overlapped_intervals;
    }
};
