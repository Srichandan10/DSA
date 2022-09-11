//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node* curr=head;
        Node* temp=NULL;
        // insert additional node after
        // every node of original list
        while(curr){
            temp=curr->next;
            curr->next=new Node(curr->data);
            curr->next->next=temp;
            curr=temp;
            
        }
        
        // adjust the random pointers of the
        // newly added nodes
        curr=head;
        while(curr){
            curr->next->arb=curr->arb?curr->arb->next:curr->arb;
            curr=curr->next->next;
        }
        
        // now separate the original list and copied list
        Node* original=head, *clone=head->next;
        
        Node* clone_head=clone;
        while(original && clone){
            original->next=(original->next)?original->next->next:original->next;
            clone->next=(clone->next)?clone->next->next:clone->next;
            original=original->next;
            clone=clone->next;
        }
        
        return clone_head;
    }

};