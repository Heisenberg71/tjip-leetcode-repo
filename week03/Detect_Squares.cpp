class DetectSquares {
public:
    vector< vector <int> > points;
    map <vector<int>, int> common_point_freq;
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        if(!common_point_freq.count(point))points.push_back(point);
        common_point_freq[point]++;
    }
/*
    (x1, y2)-------------- Q(x2, y2)
    |
    |
    |
    |
    |
    |
    (x1, y1)--------------- (x2, y1)
*/
    
    int count(vector<int> point) {
        int x2 = point[0];
        int y2 = point[1];
        int squareCount = 0;
        for(auto &each_point: points){
            int x1 = each_point[0];
            int y1 = each_point[1];

            if(x1 == x2 || y1 == y2 || abs(x1 - x2) != abs(y1 - y2)) continue;
            if(common_point_freq.count({x1, y1}) && common_point_freq.count({x1, y2}) && common_point_freq.count({x2, y1}))
                squareCount += common_point_freq[{x1, y1}] * common_point_freq[{x1, y2}] * common_point_freq[{x2, y1}];
        }

        return squareCount;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
