/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    Node* p1=head;
    Node* p2=head;
    int t=K;
    while(t--){
        if(!p1)return head;
        p1=p1->next;
    }
    if(!p1)return head->next;
    Node* prev=NULL;
    while(p1 and p2){
        p1=p1->next;
        prev=p2;
        p2=p2->next;
    }
    if(p2==NULL)return head;
    // cout<<p2->data<<endl;
    prev->next=p2->next;
    return head;
}
