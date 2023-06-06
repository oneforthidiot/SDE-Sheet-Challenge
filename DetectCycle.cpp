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

bool detectCycle(Node *head){
	Node* p1=head;
    Node* p2=head;
    while(p2 and p2->next){
        p1=p1->next;
        p2=p2->next->next;
        if(p1==p2)return true;
    }
    return false;
}
