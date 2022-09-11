//https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-LinkedList/problem/delete-without-head-pointer
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       /*while(del->next->next){
           del->data=del->next->data;
           del=del->next;
       }
       del->data=del->next->data;
       del->next=NULL;*/
       Node* temp=del->next;
       del->data=del->next->data;
       del->next=del->next->next;
       free(temp);
    }

};