#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size(); vector<int> ans(size, 0);
        stack<int> index;
        for(int i=size-1; i>=0; i--) {
            if(index.empty()) {index.push(i); ans[i]=i;}
            else {
                while(temperatures[i]>=temperatures[index.top()]) {index.pop(); if(index.empty()) break;}
                if(index.empty()) {ans[i]=i; index.push(i);} else ans[i]=index.top();
                index.push(i);        
            }
        }
        for(int i=0; i<size; i++) ans[i]=ans[i]-i;
        return ans;
    }
};
int main() {
    Solution* obj=new Solution();
    vector<int> Temp={73,74,75,71,69,72,76,73};
    for(int i : obj->dailyTemperatures(Temp)) cout<<i<<' ';
    return 0;
}
