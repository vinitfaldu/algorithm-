#include<iostream>
using namespace std;
struct node
{
	int key;
	node *left,*right;
};
node* newnode(int k)
{
	node* n=(struct node *)malloc(sizeof(struct node));
	n->key=k;
	n->left=n->right=NULL;
	return n;
}
void inorder(node* n)
{
	while(n!=NULL)
	{
		inorder(n->left);
		cout<<(n->key)<<" ";
		inorder(n->right);
	}
}
node* insert(node* n,int key)
{
	if(n==NULL)
		return newnode(key);

	if(key < n->key)
		n->left=insert(n->left,key);
	else if(key > n->key)
		n->right=insert(n->right,key);

	return n;

}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,80);
	//insert(root,90);

	inorder(root);

	return 0;
}