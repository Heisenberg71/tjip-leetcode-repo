// TC: O(N^2 logN) Here, N = total number of points
// MC: O(N)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        static const int BASE = 20004;

        if(points.size() < 3) return points.size();

        unordered_map <int, int> sameLine_freq;

        int max_pairs_in_line = 1;
        for(auto &a: points){
            for(auto &b: points){
                int up = a[0] - b[0];
                int down = a[1] - b[1];
                int g = abs(__gcd(up, down));
                
                if(g == 0) continue;
                if(up < 0 || (up == 0 && down < 0)) up = -up, down = -down;
                up /= g, down /= g;

                sameLine_freq[up*BASE + down]++;
                max_pairs_in_line = max(max_pairs_in_line, 1 + sameLine_freq[up*BASE + down]);
            }
            sameLine_freq.clear();
        }

        return max_pairs_in_line;
    }
};
