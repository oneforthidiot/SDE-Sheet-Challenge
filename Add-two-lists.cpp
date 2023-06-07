/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2){
    Node* ans=new Node(-1);
    Node* temp=ans;
    int rem=0;
    while(num1 and num2){
        int sum=num1->data+num2->data+rem;
        temp->data=sum%10;
        rem=sum/10;
        temp->next=new Node(-1);
        temp=temp->next;
        num1=num1->next;
        num2=num2->next;
    }
    while(num1){
        int sum=num1->data+rem;
        temp->data=sum%10;
        rem=sum/10;
        temp->next=new Node(-1);
        temp=temp->next;
        num1=num1->next;
    }
    while(num2){
        int sum=num2->data+rem;
        temp->data=sum%10;
        rem=sum/10;
        temp->next=new Node(-1);
        temp=temp->next;
        num2=num2->next;
    }
    if(rem){
        int sum=rem;
        temp->data=sum%10;
        rem=sum/10;
        // temp=temp->next;
        temp->next=new Node(-1);
    }
    Node* prev=NULL;
    Node* p1=ans;
    while(p1->next){
        prev=p1;
        p1=p1->next;
    }
    prev->next=NULL;
    return ans;
}
