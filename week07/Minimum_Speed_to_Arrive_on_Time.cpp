// T.C: O(Nlog(MAX_SPEED)) Here, N = size of dist vector
// M.C: O(1)

class Solution {
public:
    static const int MAX_SPEED = INT_MAX/2;
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = MAX_SPEED, minSpeed = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            double passedTime = 0.0;
            for(int i = 0; i < dist.size(); i++){
                if(i + 1 == dist.size()) passedTime += 1.00 * dist[i] / mid;
                else passedTime += (dist[i] + mid - 1)/mid;
            }
            if(passedTime > hour) lo = mid + 1;
            else{
                minSpeed = mid;
                hi = mid - 1;
            }
        }
        return minSpeed;
    }
};
