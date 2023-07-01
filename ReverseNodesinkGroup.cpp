#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *reverse(Node *head,int n,int b[],int i) {
  while (b[i] == 0 && i<n) {
	  i++;
  }
    if(!head || !head->next || i == n)
	return head;


        Node* curr=head;
	Node* prev=NULL;
	Node* next;
	int cnt=b[i];
        while (curr != NULL && cnt > 0) {
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			cnt--;
        }
		head->next=reverse(curr,n,b,i+1);
		return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
        if (head == NULL) {
			return NULL;
        }
        return reverse(head,n,b,0);
}
