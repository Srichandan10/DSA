/*
 Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(left-1>0){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
            
        }
        ListNode* tail=curr;
        ListNode* con=prev;
       
        while(right>0){
            ListNode* third=curr->next;
            curr->next=prev;
            prev=curr;
            curr=third;
            right--;
            
        }
        
        tail->next=curr;
        if(con==NULL){
            head=prev;
        }
        else
            con->next=prev;
        return head;
        
    }
};