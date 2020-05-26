#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* insertStart(node *header,int d)
{
	node *newnode=new node();
	newnode->data=d;
	newnode->next=header;
	header=newnode;

	return header;
}

node* insertAfter(node *h,int d,int k)
{
	node *temp;
	temp=h;
	while(temp->data!=k)
	{
		temp=temp->next;
	}
	node *newnode=new node();
	newnode->data=d;
	newnode->next=temp->next;
	temp->next=newnode;
	
	return h;
}

node* insertEnd(node *header,int d)
{
	node *temp;
	temp=header;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node *newnode=new node();
	newnode->data=d;
	newnode->next=NULL;
	temp->next=newnode;
	
	return header;
}

void printList(node *header)
{
	while(header!=NULL)
	{
		cout<<header->data<<" ";
		header=header->next;
	}
}

int main()
{
	node *h=NULL;

	h=insertStart(h,30);
	h=insertStart(h,20);
	h=insertStart(h,10);

	h=insertAfter(h,25,20);

	h=insertEnd(h,40);

	printList(h);

	return 0;
}