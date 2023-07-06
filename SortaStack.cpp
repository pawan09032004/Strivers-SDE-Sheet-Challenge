#include <bits/stdc++.h> 
using namespace std;
void sortStack(stack<int> &st12)
{
	// Write your code here
	if(st12.empty())return;

	int topElement = st12.top();
	st12.pop();
	sortStack(st12);
	stack<int> st;
	while(!st12.empty() && st12.top() > topElement){
		st.push(st12.top());
		st12.pop();
	}
	st12.push(topElement);
	while(!st.empty()){
		st12.push(st.top());
		st.pop();
	}
}
