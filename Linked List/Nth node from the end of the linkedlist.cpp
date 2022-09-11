//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* first=head;
       Node* second=head;
       
       // move first to the n-th node from beginning.
       for(int i=1;i<n;i++){
           
           first=first->next;
           if(first==NULL){
               return -1;
           }
       }
       // move first and second by one node until
        // first reaches end of the list.
       while(first && first->next){
           first=first->next;
           second=second->next;
       }
       
       return second->data;
}