/*
copyright@buptlishantao
weibo: http://weibo.com/u/2158052054
具有输出当前最小值功能的 栈
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct minnode
{
	int minvalue;
	int value;
}minnode;

class Minstack
{
public:
	Minstack(int _maxsize=100)
	{
		p = new minnode[_maxsize];
		top = -1;
		maxsize =_maxsize;
	}
	~Minstack()
	{
		delete []p;
	}
	int pop()
	{
		if (top==-1)
		{
			cout<<"haha"<<endl;
			return 0;
		}
		top--;
		return 1;
	}
	int gettop()
	{
		return  p[top].value;
	}
	int push(int i)
	{
		if(top==maxsize)
		{
			cout<<"full"<<endl;
			return 0;
		}
		if(top ==-1)
		{
			++top;
			p[top].minvalue = i;
			p[top].value = i;
		}
		else
		{
			if(i < p[top].minvalue) p[top+1].minvalue = i;
			else  p[top+1].minvalue = p[top].minvalue;
			p[top+1].value = i;
			top++; 	
		}
		
	}
	int min()
	{

		return p[top].minvalue;
	}

private:
	minnode* p;
	int top;
	int maxsize;	
};
int main()
{
	Minstack stack;	
	int a[] ={3,2,5,6,8,12,3,4,1,56,7};

	int length = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < length; ++i)
	{
		stack.push(a[i]);
	}

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	cout<<stack.min();
}