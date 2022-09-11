// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

class Solution{
    
  private:
    struct compare{
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
    };
   
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<Node*, vector<Node*>, compare> pq;
           
           for(int i=0;i<K;i++){
               if(arr[i]){
                    pq.push(arr[i]);
               }
              
           }
           if(pq.empty()){
               return NULL;
           }
           Node* dummy=new Node(0);
           Node* last=dummy;
           while(!pq.empty()){
               
               Node* curr=pq.top();
               pq.pop();
               
               last->next=curr;
               last=last->next;
               
               if(curr->next){
                   pq.push(curr->next);
               }
               
           }
           
           Node* head=dummy->next;
           delete(dummy);
           return head;
           
           
           
    }
};
