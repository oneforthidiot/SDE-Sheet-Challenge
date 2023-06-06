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
LinkedListNode<int> * rev(LinkedListNode<int> *head){
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int> *nxt=NULL;
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(!head or !head->next)return true;
    LinkedListNode<int> *p1=head;
    LinkedListNode<int> *p2=head;
    LinkedListNode<int> *prev=NULL;
    while(p2->next and p2->next->next){
        prev=p1;
        p1=p1->next;
        p2=p2->next->next;
    }
    p1->next=rev(p1->next);
    p1=p1->next;
    p2=head;
    while(p1){
        if(p1->data!=p2->data)return false;
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}
