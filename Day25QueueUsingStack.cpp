
#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1, s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    // Implement the enqueue() function.
    }

    int deQueue() {
        if(s1.empty())return -1;
        int ele = s1.top();
        s1.pop();
        return ele;
        // Implement the dequeue() function.
    }

    int peek() {
        return s1.empty()?-1:s1.top();
        // Implement the peek() function here.
    }

    bool isEmpty() {
        
        return s1.empty();
        // Implement the isEmpty() function here.
    }
};
