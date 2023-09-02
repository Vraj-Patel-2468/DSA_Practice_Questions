#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;//IN Queue pair[0]=w, pair[1]=v
        pair<int,int> temp; q.push(make_pair(0,0));
        vector<bool> vis(V, false); int sum=0;
        while(!q.empty()) {
            temp=q.top(); q.pop();
      		if(vis[temp.second]) continue;
            vis[temp.second]=true; sum+=temp.first;
            for(vector<int> it : adj[temp.second]) {
                if(!vis[it[0]])
                    q.push(make_pair(it[1], it[0]));
            }
        }
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }   
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }
    return 0;
}
