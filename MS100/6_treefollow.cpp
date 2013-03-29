#include <iostream>
#include <vector>

using namespace std;

int treefollow(vector<int> &p,int begin,int end)
{	
	int root = p[end];
	int i=begin;
	while(p[i]<root)
	{		
		i++;
	}
	for(int j=i;j<=end;++j)
	{
		if(p[j]<root) return 0;
	}	
	int left = 1;
	if(i-1>begin)
	{

		cout<<"left tree"<<endl;
		left = treefollow(p,begin,i-1);
	}		
	int right = 1;
	if(i<end-1)
	{
		cout<<"right tree"<<endl;
		right =treefollow(p,i,end-1);
	}
		
	return (left&&right); 
}
int main(int argc, char const *argv[])
{
	vector<int> array;
	int len;
        cin>>len;
        int j;
	while(cin>>j)
	{
		array.push_back(j);
	}
	cout<<treefollow(array,0,len-1);
	return 0;
}
