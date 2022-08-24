//problem link - https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
bool detectLoop(Node* head)
    {
        // your code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;
            }
        }
        
        return false;
    }