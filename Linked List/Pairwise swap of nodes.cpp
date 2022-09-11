//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    struct Node* curr=head->next;
    struct Node* prev=head;
    
    head=curr;
    Node* next=NULL;
    while(1){
        next=curr->next;
        curr->next=prev;
        
        if(next==NULL || next->next==NULL){
            prev->next=next;
            break;
        }
        prev->next=next->next;
        
        prev=next;
        curr=prev->next;
        
    }
    

    return head;
}