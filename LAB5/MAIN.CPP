#include<iostream>
using namespace std;


class Node
{
	public:
	int leftval;
	int rightval;
	int temp;
	Node *left;
	Node *middle;
	Node *right;
	int height;
};


Node* newNode(int dest,int key)
{
	Node* node = new Node();
	dest = key;
//	cout<<"value of newnode, leftval"<<node->leftval;
//	cout<<"\n value of right val "<<node->rightval;
	node->left = NULL;
	node->middle= NULL;
	node->right = NULL;
	
	return(node);
}
void swap(Node* node, int leftval, int key)
{
    node->rightval=node->leftval;
    node->leftval=key;
}

Node* insert(Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(node->leftval,key));

	if (key < node->leftval)
	    swap(node,node->leftval,key);
		
	else if (key > node->leftval)
		return(newNode(node->rightval,key));
	else 
		return node;


	return node;
}


void display(Node *root)
{
// 	if(root != NULL)
// 	{
// 		cout << root->leftval << " ";
// 		cout << root->rightval << " ";
		
// 		display(root->left);
// 		display(root->middle);
// 		display(root->right);
// 	}
}


int main()
{
	Node *root = NULL;
	root = insert(root, 1);
	root = insert(root, 2);
// 	root = insert(root, 3);
// 	root = insert(root, 4);
// 	root = insert(root, 5);
// 	root = insert(root, 6);
	
	
	cout << "displalying  tree is \n";
	//display(root);
	
	return 0;
}
