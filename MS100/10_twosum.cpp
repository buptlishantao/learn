#include <iostream>
using namespace std;

int find(int a[],int length,int &m,int &n,int destination)
{
	m = 0;
	n = length-1;
	while(m < n)
	{
		if(a[m]+a[n]==destination)
			return 1;
		else if(a[m]+a[n]<destination)
			m++;
		else
			n--;
	}
	return 0;
}


int main()
{
	int m = 0;
	int n = 0;
	int a[] ={1,3,4,6,7,8,11,22};
	int length = sizeof(a)/sizeof(a[0]);
	int result = find(a,length,m,n,15);
	if (result)
	{
		cout<<"find "<<m<<"		"<<n;
	}
	else
		cout<<"not find";
}