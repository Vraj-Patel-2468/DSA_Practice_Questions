#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> curr=cells; int size=cells.size();
        for(int i=0; i<n; i++) {
            curr=cells;
            for(int j=0; j<size; j++) {
                if(j==0) cells[j]=(curr[j]==curr[j+1]);
                else if(j==size-1) cells[j]=(curr[j]==curr[j-1]);
                else cells[j]=(curr[j-1]==curr[j+1]);
            }
        }
        return cells;
    }
};

int main() {
    vector<int> cells={0,1,0,1,1,0,0,1}; int n=7;
    Solution* obj=new Solution();
    vector<int> ans= obj->prisonAfterNDays(cells, n);
    for(int i=0; i<cells.size(); i++) cout<<"Ans = "<<ans[i]<<' '<<endl;   
    return 0;
}