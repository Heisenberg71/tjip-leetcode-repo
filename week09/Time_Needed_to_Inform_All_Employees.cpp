// T.C: O(N)  Here, N = number of nodes in tree
// M.C: O(N)

class Solution {
private:
    int DFS(int u, unordered_map <int, vector<int> >& edge, vector<int>& informTime){
        int timeToVisitSubtree = 0;
        for(auto& v: edge[u])
            timeToVisitSubtree = max(timeToVisitSubtree, informTime[u] + DFS(v, edge, informTime));
        return timeToVisitSubtree;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map <int, vector<int> > edge;
        for(int i = 0; i < manager.size(); i++)
            edge[ manager[i] ].push_back(i);

        return DFS(headID,  edge, informTime);
    }
};
