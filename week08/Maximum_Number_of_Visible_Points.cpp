class Solution {
private:
    double get_angle(double dy, double dx){
        double deg = atan2(dy, dx)*180.0/M_PI;
        if(deg < 0) deg += 360.0;
        return deg;
    }
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector <double> angles;
        int overlap = 0, max_visible_points = 0;
        for(auto &point: points){
            if(point == location) overlap++;
            else angles.push_back(get_angle(point[1] - location[1], point[0] - location[0]));
        }
        sort(angles.begin(), angles.end());

        int siz = angles.size();
        for(int L = 0, R = 0; L < siz; L++){
            while((R < siz && angles[R] - angles[L] <= angle) || (R >= siz && 360.0 + angles[R%siz] - angles[L] <= angle)) R++;
            max_visible_points = max(max_visible_points, R - L);
        }
        return max_visible_points + overlap;
    }
};
