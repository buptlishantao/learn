/*
copyright@buptlishantao
weibo: http://weibo.com/u/2158052054
100题3,求数组最大子数组和
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[]={1,-2,3,10,-4,7,2,-5};
	int length = sizeof(a)/sizeof(a[0]);
	int sum=0;
	int temp_sum =0;
	
	for (int i = 0; i < length; ++i)
	{
		temp_sum += a[i];
		if(temp_sum<0)
		{
			sum = 0;
			temp_sum = 0;
		}
		if(temp_sum>sum) sum = temp_sum;

	}
	cout<<sum<<endl;
	return 0;
}