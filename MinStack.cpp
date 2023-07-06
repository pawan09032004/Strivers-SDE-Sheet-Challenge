#include <bits/stdc++.h> 
// Implement class for minStack.
using namespace std;
class minStack
{
	// Write your code here.
	stack<int> st;
	int mini = INT_MAX;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			if(st.empty()){
				st.push(val);
				mini = val;
			}
			else{
				if(val < mini){
					st.push(2*val-mini);
					mini = val;
				}
				else{
					st.push(val);
				}
				
			}		// Write your code here.
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty())return -1;

			int val = st.top();
			st.pop();
			if(val < mini){
				int v = mini;
				mini = 2*mini - val;
				return v;
			}
			return val;
			// Write your code here.
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty())return -1;
			int val = st.top();
			return val<mini?mini:val;
			
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{	if(st.empty())return -1;
			return mini;// Write your code here.
		}
};
