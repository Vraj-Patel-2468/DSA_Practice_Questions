#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, bool vis[], bool pathVis[]) {
        vis[node]=true; pathVis[node]=true;
        for(int temp : adj[node]) {
            if(!vis[temp]) {
                if(dfs(temp, adj, vis, pathVis))
                    return true;
            } 
            else if(pathVis[temp])
                return true;  
        }
        pathVis[node]=false; return false;
    }
    bool cycleDetect(int numCourses, vector<vector<int>>& adj) {
        bool vis[numCourses]={false}, pathVis[numCourses]={false};
        for(int i=0; i<numCourses; i++) {
            if(!vis[i])
                if(dfs(i, adj, vis, pathVis))
                    return true;
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (vector<int> temp : prerequisites)
            adj[temp[1]].push_back(temp[0]);
        bool hasCycle=cycleDetect(numCourses, adj);
        return !hasCycle;
    }
};

int main() {
    Solution* solution=new Solution;
    int umCourses = 2; vector<vector<int>> prerequisites = {{1, 0}};
    bool result = solution->canFinish(umCourses, prerequisites);
    cout<<result<<endl;
    return 0;
}
