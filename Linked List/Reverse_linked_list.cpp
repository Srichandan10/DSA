//Author- CHANDAN SRIVASTAVA
//Problem link- https://www.geeksforgeeks.org/reverse-a-linked-list/

#include<bits/stdc++.h>
using namespace std;


class Node{
public:
	int data;
	Node* next;
	Node(int data):data(data),next(NULL){}
};

Node* reverseLinkedList(Node *head){

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

void printlinkedlist(Node* head){
	Node *curr=head;
	while(curr){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
}
int main() {
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlinkedlist(reverseLinkedList(head));

   return 0;
}
