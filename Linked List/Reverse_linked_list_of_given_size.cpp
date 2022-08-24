struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head){
            return NULL;
        }
        
        int count=k;
        node* curr=head;
        node* prev=NULL;
        node* next=NULL;
        while(curr && count--){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        if(curr){
            head->next=reverse(curr,k);
        }
        return prev;
    }