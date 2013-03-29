/*
copyright@buptlishantao
weibo: http://weibo.com/u/2158052054
100题1,把一个BST转换为双链表
*/
#include <iostream>
using namespace std;

typedef struct node
{
    int node_value;
    node* leftnode;
    node* rightnode;
}treenode;
void insert(treenode* &node,int value)
{
    if(NULL==node)
    {
        treenode* pnode = new treenode();
        pnode->node_value = value;
        pnode->leftnode = NULL;
        pnode->rightnode = NULL;
        node = pnode;

    }
    else if(value < node->node_value)
    {
        insert(node->leftnode,value);
    }
    else if(value >= node->node_value)
    {
        insert(node->rightnode,value);
    }
}
void printtree(treenode* node)
{
    if(NULL==node)
    {
        return;
    }
    if(NULL!=node->leftnode)
    {
        printtree(node->leftnode);
    }
    cout<<node->node_value<<endl;
    if(NULL!=node->rightnode)
    {
        printtree(node->rightnode);
    }
}

treenode* previousnode =NULL;
treenode* phead =NULL;

void todoublelist(treenode* node)
{
    node->leftnode = previousnode;
    if(previousnode==NULL)
    {
        phead = node;
    }
    else
    {
        previousnode->rightnode = node;
    }
    previousnode = node;
}
void convert(treenode* node)
{
    if(NULL==node)
    {
        return;
    }
    if(NULL!=node->leftnode)
    {
        convert(node->leftnode);
    }
    todoublelist(node);
    if(NULL!=node->rightnode)
    {
        convert(node->rightnode);
    }
}
int main()
{
    int a[]={3,2,10,1,4,7,8,9,6,14,234,23,63,223,66};
    int length = sizeof(a)/sizeof(a[0]);
    treenode* root = NULL;
    for(int i=0;i<length;i++)
    {
        insert(root,a[i]);
    }
    printtree(root);

    convert(root);

    while(phead!=NULL)
    {
        cout<<phead->node_value<<endl;
        phead = phead->rightnode;
    }
}


