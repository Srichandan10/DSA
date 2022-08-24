//https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

Node* moveToFront(Node* head){

	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* last=head;
	Node* secLast=NULL;

	while(last->next){
		secLast=last;
		last=last->next;
	}

	secLast->next=NULL;
	
	last->next=head;

	return last; //last will be new head


}