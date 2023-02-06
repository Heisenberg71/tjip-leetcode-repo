// T.C: O(NlogN) Here, N = number of given sticks
// M.C: O(N)

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> min_heap(sticks.begin(), sticks.end());

        int minCost = 0;
        while(min_heap.size() > 1){
            int newStickLen = min_heap.top();
            minCost += min_heap.top(); min_heap.pop();
            newStickLen += min_heap.top();
            minCost += min_heap.top(); min_heap.pop();
            min_heap.push(newStickLen);
        }

        return minCost;
    }
};
