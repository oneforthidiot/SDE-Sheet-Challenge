#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* nw=new Node<int>(-1);
    Node<int>* temp=nw;
    Node<int>* p1=first;
    Node<int>* p2=second;
    while(p1 and p2){
        if(p1->data<p2->data){
            temp->next=p1;
            temp=p1;
            p1=p1->next;
        }
        else{
            temp->next=p2;
            temp=p2;
            p2=p2->next;
        }
    }
    while(p1){
        temp->next=p1;
        temp=p1;
        p1=p1->next;
    }
    while(p2){
        temp->next=p2;
        temp=p2;
        p2=p2->next;
    }
    return nw->next;
}
