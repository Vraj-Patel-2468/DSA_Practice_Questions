#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size(), ans, area[size]; vector<int> pre_index(size, 0), post_index(size, 0); stack<int> temp;
        for(int i=size-1; i>=0; i--) {
        	if(temp.empty()){temp.push(i); post_index[i]=size+1;}
        	else {
        		while(heights[temp.top()]>=heights[i]){ temp.pop(); if(temp.empty()) break;}
        		if(temp.empty()){post_index[i]=size+1; temp.push(i);}
        		else {post_index[i]=temp.top(); temp.push(i);}
        	}
        }
        while(!temp.empty()) temp.pop();
        for(int i=0; i<size; i++) {
        	if(temp.empty()){temp.push(i); pre_index[i]=-1;}
        	else {
        		while(heights[temp.top()]>=heights[i]){ temp.pop(); if(temp.empty()) break;}
        		if(temp.empty()){pre_index[i]=-1; temp.push(i);}
        		else {pre_index[i]=temp.top(); temp.push(i);}
        	}
        }
        for(int i=0; i<size; i++) {
              if(pre_index[i]==post_index[i]) area[i]=heights[i];
              else if(pre_index[i]==-1 && post_index[i]==size+1)  area[i]=size*heights[i];
              else if(pre_index[i]==-1 && post_index[i]!=size+1)  area[i]=(post_index[i])*(heights[i]);
              else if(pre_index[i]!=-1 && post_index[i]==size+1)  area[i]=(size-pre_index[i]-1)*(heights[i]);
              else area[i]=(post_index[i]-pre_index[i]-1)*heights[i];
              if(i==0) ans=area[i];
              else {if(ans<area[i]) ans=area[i];}
        }
        return ans;   
    }
};

int main(){
	vector<int> height={2,1,5,6,2,3};
	Solution* obj=new Solution();
	int ans= obj->largestRectangleArea(height);
	cout<<"Ans = "<<ans<<endl;
	return 0;
}
