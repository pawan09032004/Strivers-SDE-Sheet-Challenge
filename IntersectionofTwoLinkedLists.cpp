/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
     Node* tail = firstHead;
    while(tail->next){
        tail = tail->next;
    }

    //creating a loop
    tail->next = firstHead;

    //detecting and finding the intersection
    Node *fast = secondHead, *slow = secondHead;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) {
            slow = secondHead;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            //undoing the loop
            tail->next = NULL;
            return slow;
        };
    }
    tail->next = NULL;
    return NULL;
}
