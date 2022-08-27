//https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
class Solution
{
    public:
    Node* reverse(Node *head){
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
    
    Node* addOneUtil(Node* head){
        
        int carry=1;
        Node* curr=head;
        
        Node* temp=NULL;
        while(curr){
            int sum=curr->data+carry;
            curr->data=sum%10;
            carry=sum/10;
            
            temp=curr;
            curr=curr->next;
            
        }
        
        if(carry){
            temp->next=new Node(carry);
        }
        
        return head;
        
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        
        head=addOneUtil(head);
        
        return reverse(head);
        
    }
};