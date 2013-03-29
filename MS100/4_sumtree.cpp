/*
copyright@buptlishantao
weibo: http://weibo.com/u/2158052054
100题4,在二元树中找所有路径
待改进,最好不要设置全局变量，vector v改为以引用传递
*/
#include <iostream>
#include <vector>
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
std::vector<int> v;
void find(treenode* root,int sum,int dest)
{
    if(NULL==root)
    {
        cout<<"empty tree"<<endl;
        return;
    }
    sum += root->node_value;
    v.push_back(root->node_value);
    if(NULL!=root->leftnode)
    {
        find(root->leftnode,sum,dest);
    }   
    if (NULL!=root->rightnode)
    {
        find(root->rightnode,sum,dest);
    }
    if(dest==sum)
    {
        cout<<"I find a path"<<endl;
        for(std::vector<int>::iterator it=v.begin();it!=v.end();++it)
        {
            cout<<*it<<endl;
        }        
    }
    else
    {
        
        sum = sum - root->node_value;
    }
    v.pop_back(); 
}


int main()
{
    int a[]={10,5,4,7,12};
    int length = sizeof(a)/sizeof(a[0]);
    treenode* root = NULL;
    for(int i=0;i<length;i++)
    {
        insert(root,a[i]);
    }
    printtree(root);

    cout<<"haha"<<endl;

    find(root,0,22);

}


