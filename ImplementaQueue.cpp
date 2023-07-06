#include <bits/stdc++.h> 
using namespace std;
class Queue {
    int *arr;
    int start;
    int end;
    int currSize;
    int maxSize;

public:
    Queue() {
        // Implement the Constructor
        arr = new int[5000];
        start=end = -1;
        maxSize = 5000;
        currSize =0;
    }
    Queue(int maxSize){
        arr = new int[maxSize];
        start= end = -1;
        currSize = 0;
        maxSize = maxSize;
    }

    /*----------------- Public Functions of Queue -----------------*/
    bool isFull(){
        return currSize==maxSize;
    }
    bool isEmpty() {
        return(currSize==0);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isFull()){
            return;
        }
        end = (end+1) % maxSize;
        arr[end]= data;
        currSize++;
        if(start==-1)start=end;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        int data = arr[start];
        start = (start+1)%maxSize;
        
        currSize--;
        return data;
    }

    int front() {
        if(isEmpty()){
            return -1;
        }
        int data = arr[start];
        return data;        // Implement the front() function
    }


};
