//https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

Node* firstNodeOfLoop(Node* head){
	if(head==NULL || head->next==NULL){
            return NULL
    }
        
    Node* slow=head;
    Node* fast=head;
        
    while(fast && fast->next){
        
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow){
            slow=head;
            while(fast!=slow){
            	slow=slow->next;
            	fast=fast->next;
            }
            return slow
            
        }
            
    }
    return NULL;


}