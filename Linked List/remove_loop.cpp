//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* slow=head;
        Node* fast=head;
            
        while(fast && fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow){
                break;
                
            }
                
        }
        if(fast==slow){
            slow=head;
            if(fast==slow){ //fast==slow ==head;
                while(fast->next!=slow){
                    fast=fast->next;
                }
                    
            }
            else{
                    
                while(fast->next!=slow->next){
                    fast=fast->next;
                    slow=slow->next;
                        
                }
            
            }
            fast->next=NULL;
        }
    }


