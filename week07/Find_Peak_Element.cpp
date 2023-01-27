// T.C: O(logN) Here, N = size of the array
// M.C: O(1)

// ................................................. 1st implementation ............................................

class Solution {
private:
    const static int INVALID = -1;
    int binarySearch(vector<int>& nums)
    {
        int lo = 1, hi = nums.size()  - 1, peak = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid - 1] > nums[mid]){
                peak = mid - 1;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return peak;
    }
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums);
    }
};



// ................................... 2nd Implementation .........................................

class Solution {
private:
    const static int INVALID = -1;
    int binarySearch(vector<int>& nums)
    {
        int lo = 0, hi = nums.size()  - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if((mid - 1 < 0 || nums[mid - 1] < nums[mid]) && (mid + 1 >= nums.size() || nums[mid] > nums[mid + 1])) return mid;
            else if(mid >  0 && nums[mid - 1] > nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return INVALID;
    }
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums);
    }
};
