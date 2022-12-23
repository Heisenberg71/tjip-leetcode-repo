class Solution {
public:
    static const int BASE = 40005;
    static const int MAX_RECTANGLE_AREA = 1600000005;
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map <int, bool> point_freq;
        for(auto x: points){
            point_freq[ x[0]*BASE + x[1] ] = 1;
        }
/*
        (x2, y1) --------- A(x1, y1)
        |
        |
        |
        |
        B(x2, y2) --------- (x1, y2)
*/

        int minRectangle = MAX_RECTANGLE_AREA;
        for(auto &a: points){
            int x1 = a[0], y1 = a[1];
            for(auto &b: points){
                int x2 = b[0], y2 = b[1];
                if(x1 == x2 || y1 == y2) continue;
                if(!point_freq.count(x2*BASE + y1) || !point_freq.count(x1*BASE + y2)) continue;
                minRectangle = min(minRectangle, abs(x1 - x2)*abs(y1 - y2));
            }
        }

        if(minRectangle == MAX_RECTANGLE_AREA)
            minRectangle = 0;
        return minRectangle;
    }
};
