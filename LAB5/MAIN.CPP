#include<iostream>
using namespace std;


class Node
{
	public:
    int size;
	int key[3];
	Node *first;
	Node *second;
	Node *third;
	Node *fourth;

};

Node* create(Node* node,i)
void swap(Node* node, int key, int value)
{
    node->key[1]=node->key[0];
    node->key[0]=value;
}

Node* insert(Node* node, int value)
{

	if (node == NULL)
    {
        Node* node = new Node();
        node->key[0]=value;
        node->first = NULL;
        node->second= NULL;
        node->third = NULL;
        return node;
    }


	if (value < node->key[0])//case 1
	    swap(node,node->key[0],value);

	else if (value > node->key[0])// case 2
		{
        node->key[1]=value;
        node->first = NULL;
        node->second= NULL;
        node->third = NULL;
        return node;
    }
	else
		return node;


	return node;
}


void display(Node *root)
{
 	if(root != NULL)
 	{
		for(int i=0;i<3;i++)
        {
            cout <<root->key[i] << " ";
        }



 		display(root->first);
 		display(root->second);
 		display(root->third);
  	}
}


int main()
{
	Node *root = NULL;
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);



	cout << "displalying  tree is \n";
	display(root);

	return 0;
}
