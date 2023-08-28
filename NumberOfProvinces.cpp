#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> grid, int sv, vector<bool> &vis, int size){
        vis[sv]=true;
        for(int i=0; i<size; i++) {
            if(grid[sv][i] && i!=sv) {
                if(!vis[i]) dfs(grid, i, vis, size);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int count=0, size=grid.size(); vector<bool> vis(size, false);
        for(int i=0; i<size; i++) {
            if(vis[i]) continue;
            for(int j=0; j<size; j++) {
                if(grid[i][j] && !vis[j]) {
                    dfs(grid, i, vis, size);
                    count++; break;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution* obj=new Solution();
    vector<vector<int>> vec={{1,1,0},{1,1,0},{0,0,1}};
    int ans=obj->findCircleNum(vec);
    cout<<ans<<endl;
    return 0;
}