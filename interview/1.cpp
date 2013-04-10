#include <iostream>
using namespace std;
/*
给定一个整数数组a[0~n]，求数组a的子数组，使其元素和为最大。

在计算temp_sum时，可以考虑以下三种情况：

1，当temp_sum>0时，temp_sum = temp_sum + a[i]。

2，当temp_sum<=0，这时候应该舍弃之前的temp_sum,以a[i]重新作为temp_sum的起点

3，在求真正的最大值时，需要把temp_sum和sum进行比较，如果temp_sum较大，则更新 s,e,sum.
*/

int max_sub_array(int &s,int &e,int * a,int len)
{
    int i=0;
    int temp_sum,start,end;
    int sum = 0;
    sum = temp_sum = a[0];
    s = e = start = end = 0;
    for(i = 1;i< len;i++)
    {
        if(temp_sum>0)
        {
            temp_sum = temp_sum + a[i];
            end = i;
        }
        else
        {
            temp_sum = a[i];
            start = end = i;
        }
        if(sum<temp_sum)
        {
            sum = temp_sum;
            s = start;
            e = end;
        }
    }
    return sum;
}
int main()
{
    int a[]={-2,-3,-1,-4,-5,-6,-7,-8,-9,-10};
    int start,end;
    int len = sizeof(a)/sizeof(a[0]);
    int sum = max_sub_array(start,end,a,len);
    cout << sum << "  "<<start<< " "<<end<< endl;
}
