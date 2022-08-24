Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* next=NULL;
    Node* curr=head;
    if(!curr){
        return NULL;
    }
    while(curr->next){
        if(curr->data==curr->next->data){
            
            next=curr->next->next;
            free(curr->next);
            curr->next=next;
           
        }
        else{
            curr=curr->next;
        }
        
    }
    return head;
}