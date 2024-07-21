#include<bits/stdc++.h>
using namespace std;

void init_code(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int func(vector<long long> &DP, int number) {

   // Check if previously solved the subproblem.
   if(DP[number] != -1)
      return DP[number];

   // Covering all the base cases.
   if(number == 0 || number == 1) 
      return DP[number] = 1;

   // Covering the transition.
   long long ways = 0;
   for(int i=1; i<=6; i++) {
      if(number>i) {
         ways += func(DP, number-i);
      }
      if(number==i) {
         ways += 1;
      }
   }

   return DP[number] = ways % 1000000007;
}

int main() {
   init_code();
   int number;
   cin >> number;
   vector<long long> DP(number+1, -1);
   int ways = func(DP, number);
   cout << ways;
   return 0;
}
