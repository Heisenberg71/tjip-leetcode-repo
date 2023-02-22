// T.C: O(V + E) Here, V = number of nodes in the graph
// M.C: O(V + E) Here, E = number of edge int the graph

class Solution {
private:
    const static int NOT_PROCESSED = 0;
    const static int PROCESSING = 1;
    const static int FINISHED_PROCESSE = 2;
    
    bool dfs(int u, vector <int> adjMat[], vector <int> &vis)
    {
        if(vis[u] == PROCESSING) return true;
        if(vis[u] == FINISHED_PROCESSE) return false;
        vis[u] = PROCESSING;
        bool findCycle = false;
        for(auto v: adjMat[u]){
            findCycle |= dfs(v, adjMat, vis);
        }
        vis[u] = FINISHED_PROCESSE;
        return findCycle;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adjMat[ numCourses ];
        vector <int> vis(numCourses, 0);
        for(auto u: prerequisites){
            adjMat[ u[0] ].push_back(u[1]);
        }

        bool findCycle = false;
        for(int u = 0; u < numCourses; u++)
            if(vis[u] == NOT_PROCESSED) findCycle |= dfs(u, adjMat, vis);

        return !findCycle;
    }
};
