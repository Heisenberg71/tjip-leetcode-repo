// T.C: O(N) Here, N = size of the array
// M.C: O(N)


mt19937 rd(0);

class Solution {
public:
    vector <int> prefSumOfWeight;
    Solution(vector<int>& w) {
        prefSumOfWeight = w;
        for(int i = 1; i < prefSumOfWeight.size(); i++)
            prefSumOfWeight[i] += prefSumOfWeight[i - 1];
    }

    int binarySearch(int value){
        int lo = 0, hi = prefSumOfWeight.size() - 1, randomIdx;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(prefSumOfWeight[mid] >= value){
                randomIdx = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return randomIdx;
    }
    
    int pickIndex() {
        return binarySearch(rd()%prefSumOfWeight.back() + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
