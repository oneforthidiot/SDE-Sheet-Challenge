/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* head1, Node* head2){
	if(!head1)return head2;
	if(!head2)return head1;
	Node* p1=new Node(0);
	Node* temp=p1;
	Node* res=temp;
	while(head1 and head2){
		if(head1->data<head2->data){
			temp->child=head1;
			temp=temp->child;
			head1=head1->child;
		}
		else{
			temp->child=head2;
			temp=temp->child;
			head2=head2->child;
		}
	}
	if(head1){
		temp->child=head1;
	}
	if(head2){
		temp->child=head2;
	}
	return res->child;
}
Node* flattenLinkedList(Node* head) {
	if(!head or !head->next)return head;
	Node* temp=head;
	Node* temp2=flattenLinkedList(head->next);
	head->next=NULL;
	return merge(temp,temp2);
}
