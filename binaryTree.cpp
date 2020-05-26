#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
bool isBST(node* root,node* l,node* r)
{
	if(root==NULL)
		return true;

	if(l!=NULL && root->data <= l->data)
		return false;

	if(r!=NULL && root->data >= r->data)
		return false;

	return isBST(root->left,l,root) && isBST(root->right,root,r);
}
node* newnode(int data)
{
	node *n=new node();
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
int main()
{
	node *root=newnode(3);
	root->left=newnode(2);
	root->right=newnode(5);
	root->left->left=newnode(1);
	//root->left->right=newnode(2);

	if(isBST(root,NULL,NULL))
		cout<<" Is BST "<<endl;
	else 
		cout<<" Not a BST "<<endl;

	return 0;

}