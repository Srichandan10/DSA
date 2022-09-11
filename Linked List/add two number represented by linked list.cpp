//https://leetcode.com/problems/add-two-numbers/
class Solution
{
    private:
    struct Node* reverse(Node *head){
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
    
    struct Node* addTwoListsUtil(struct Node* first, struct Node* second){
        
        int carry=0;
        struct Node* dummy= new Node(0);
        struct Node* temp=dummy;
        
        while(first || second ||carry!=0){
            int first_data=(first)?first->data:0;
            int second_data=(second)?second->data:0;
            int sum=carry+first_data+second_data;
            
            carry=sum/10;
            sum=sum%10;
            temp->next=new Node(sum);
            temp=temp->next;
            
            first=(first)?first->next:NULL;
            second=(second)?second->next:NULL;
            
        }
        
        return dummy->next;
        
        
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        struct Node* head=addTwoListsUtil(first,second);
        
        return reverse(head);
        
        
    }
};
