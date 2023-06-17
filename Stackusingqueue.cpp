#include <bits/stdc++.h> 
class Stack {
	
queue < int > q;
   public:
   
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        q.empty();
    }

    void push(int element) {
         int s = q.size();
      q.push(element);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }

    int pop() {
        int n = q.front();
            if(q.empty()){
        return -1;
    } 

    q.pop();
    return n;
    }

    int top() {
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
};
