class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> temp;
        for(int i = 0, j = 0; i < m || j < n; ){
            if(i == m && j < n){
                temp.push_back(nums2[j]);
                j++;
            }
            else if(i < m && j == n){
                temp.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                 temp.push_back(nums2[j]);
                 j++;
            }
        }
        nums1 = temp;
    }
};
