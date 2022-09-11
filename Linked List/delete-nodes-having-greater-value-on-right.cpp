//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        head=reverse(head);
        
        Node* curr=head;
        Node* prev=NULL;
        int max_so_far=INT_MIN;
        while(curr){
            if(curr->data>=max_so_far){
                max_so_far=curr->data;
                prev=curr;
                curr=curr->next;
            }
            else{
                Node* temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete(temp);
            }
        }
        
        head=reverse(head);
        return head;
    }
    
};