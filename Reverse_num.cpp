#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
        int temp=x, num2=0;
        if(temp>=0){
            while(x>0){
                num2=(num2*10)+(x%10);
                x/=10;
            }
        } else {
            x*=(-1);
            while(x>0){
                num2=(num2*10)+(x%10);
                x/=10;
            }
            num2*=(-1);
        }
        return num2;
    }
};

int main() {
    int x=120;
    Solution* obj=new Solution();
    int y=obj->reverse(x);
    cout<<y<<endl;
    x=-120;
    y=obj->reverse(x);
    cout<<y<<endl;
    return 0;
}