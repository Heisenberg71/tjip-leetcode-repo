/// TC: O(N)
/// MC: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, Lmax = height[0], Rmax = height.back(), L = 0, R = height.size() - 1;
        while(L < R){
            if(height[L] < height[R]){
                Lmax = max(Lmax, height[L]);
                ans += (Lmax - height[L]);
                L++;
            }
            else{
                Rmax = max(Rmax, height[R]);
                ans += Rmax - height[R];
                R--;
            }
        }
        return ans;
    }
};
