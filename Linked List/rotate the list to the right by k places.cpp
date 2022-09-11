class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int len=1;
        ListNode* last=head;
        
        while(last->next){
            last=last->next;
            len++;
        }
        
        k=k%len;
        if(k==0){
            return head;
        }
        ListNode* nh=head;
        ListNode* tail=NULL;
        for(int i=1;i<len-k+1;i++){
            tail=nh;
            nh=nh->next;
        }
        
        last->next=head;
        tail->next=NULL;
        return nh;
    }
};