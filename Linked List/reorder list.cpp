// https://leetcode.com/problems/reorder-list/
class Solution {
private:
    ListNode* reverseLinkedList(ListNode *head){

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return ;
        }
        ListNode* slow=head; //for even length find the first middle 
        ListNode* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* h1=head;
        ListNode* h2=reverseLinkedList(slow->next);  
        slow->next=NULL;
        
        ListNode* temp=NULL;
        while(h1 && h2){
            temp=h1->next;
            h1->next=h2;
            h1=temp;
            
            temp=h2->next;
            h2->next=h1;
            h2=temp;
        }
        
        
    }
};