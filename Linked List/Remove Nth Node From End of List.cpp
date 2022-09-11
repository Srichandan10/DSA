//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* first=head;
        ListNode* second=head;
        
        while(n--){
            first=first->next;
        }
        
        if(first==NULL){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        
        while(first->next!=NULL){
            first=first->next;
            second=second->next;
        }
        ListNode* temp=second->next;
        second->next=second->next->next;
        delete(temp);
        
        return head;
        
        
    }
};