#include <iostream>
using namespace std;

typedef struct node
{
	node* left;
	node* right;
	int value;
}node;


void insert(node* &root,int value)
{
    if(NULL==root)
    {
        node* p = new node();
        p->value = value;
        p->left = NULL;
        p->right = NULL;
        root = p;

    }
    else if(value < root->value)
    {
        insert(root->left,value);
    }
    else if(value >= root->value)
    {
        insert(root->right,value);
    }
}
void printtree(node* root)
{
    if(NULL==root)
    {
        return;
    }
    if(NULL!=root->left)
    {
        printtree(root->left);
    }
    cout<<root->value<<endl;
    if(NULL!=root->right)
    {
        printtree(root->right);
    }
}


int mirror(node* &root)
{
	if(NULL==root)
		return 0;
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirror(root->left);
	mirror(root->right);
}

int mirrorloop(node* &root)
{
	if (NULL==root)
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	int a[]={8,6,5,7,9,10,11};
    int length = sizeof(a)/sizeof(a[0]);
    node* root = NULL;
    for(int i=0;i<length;i++)
    {
        insert(root,a[i]);
    }
    printtree(root);
    mirror(root);
    printtree(root);

	return 0;
}
