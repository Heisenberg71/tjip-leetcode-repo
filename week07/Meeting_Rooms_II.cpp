class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> timeline;
        for(int i = 0; i < intervals.size(); i++){
            timeline[ intervals[i][0] ]++;
            timeline[ intervals[i][1] ]--;
        }
        int prefixSum = 0, minRoom = 0;
        for(auto& currTime: timeline){
            prefixSum += currTime.second;
            minRoom = max(minRoom, prefixSum);
        }
        return minRoom;
    }
};
