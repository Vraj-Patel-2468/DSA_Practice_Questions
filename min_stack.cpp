#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> min_index;
    int point, size, *arr;  
    MinStack(){
        point=-1;
        size=30000;
        arr= new int[size];
    }
    void push(int val) {
        if(point==size-1) return;
        point++;
        arr[point]=val;
        if(min_index.empty()) min_index.push(point);
        else if(arr[min_index.top()]>arr[point]) min_index.push(point);    
    }
    void pop() {
        if(point==-1) return;
        arr[point]=0;
        while(min_index.top()>=point) {min_index.pop(); if(min_index.empty()) break;}
        point--; 
    }
    int top() {
        if(point>=size-1) return 0;
        else return arr[point];
    }
    int getMin() {
        return arr[min_index.top()];
    }
};

int main() {
	MinStack* ptr = new MinStack();
	ptr->push(-2);
	ptr->push(0);
	ptr->push(-3);
	cout<<(ptr->getMin());
	ptr->pop();
	cout<<" "<<(ptr->top());
	cout<<" "<<(ptr->getMin());
	return 0;  	
}
