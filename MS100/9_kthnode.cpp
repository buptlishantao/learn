#include <iostream>
using namespace std;
typedef struct node
{
	int value;
	node* next;
}node;
node* initial(int a[],int lenght)
{
	node* head =NULL;
	node* current =NULL;
	for (int i = 0; i < lenght; ++i)
	{
		node *p =new node();
		p->value = a[i];		
		p->next = NULL;
		if(0==i)
		{
			head  = p;	
		}
		else
		{
			current->next =p;
		}
		current = p;
	}
	return head;
}
node* findlastk(node* head,int k)
{
	if (NULL==head)
		return NULL;
	node* previous = head;
	node* behind  = head;

	for(int i =0;i < k; i++)
	{
		previous = previous->next;
	}
	while(previous!=NULL)
	{
		previous = previous->next;
		behind = behind->next;
	}

	return behind;
}
int main()
{
	int a[]={1,2,3,4,5,6};
	node* head=initial(a,6);

	node* p =findlastk(head,3);
	cout<< p->value;


}