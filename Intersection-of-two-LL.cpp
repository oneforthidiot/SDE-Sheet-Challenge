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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* p1=firstHead;
    Node* p2=secondHead;
    int sz1=0,sz2=0;
    while(p1){
        p1=p1->next;
        sz1++;
    }
    while(p2){
        p2=p2->next;
        sz2++;
    }
    p1=firstHead;
    p2=secondHead;
    if(sz2>sz1){
        int diff=(sz2-sz1);
        while(diff--){
            if(!p2)return NULL;
            p2=p2->next;
        }
    }
    else{
        int diff=(sz1-sz2);
        while(diff--){
            if(!p1)return NULL;
            p1=p1->next;
        }
    }
    if(p1 and p1==p2)return p1; 
    bool flag=false;
    while(p1 and p2){
        p1=p1->next;
        p2=p2->next;
        if(p1==p2){
            return p1;
        }
    }
    return NULL;
}
