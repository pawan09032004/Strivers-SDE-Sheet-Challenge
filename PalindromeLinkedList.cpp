#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int> *head) {
    LinkedListNode<int>*  curr=head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* next=NULL;
    while (curr != NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=head;
    while (fast->next != NULL && fast->next->next!=NULL) {
        slow= slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    LinkedListNode<int>* curr=head;
    while (slow != NULL) {
      if (slow->data != curr->data) {
          return false;
      }
      slow=slow->next;
      curr=curr->next;
    }
    return true;
   
}
