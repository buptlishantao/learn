/*
copyright@buptlishantao
weibo: http://weibo.com/u/2158052054
100题5,查找k个最小元素的方法
用最大堆比较好
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int MAX_INT =~(1<<31);
	int a[]={3,2,1,5,4,23,1,0,5,6,4,4,44,5513,22,34,1,-1,343};
	int len = sizeof(a)/sizeof(a[0]);
	int minarray[4]={MAX_INT,MAX_INT,MAX_INT,MAX_INT};
	for (int i = 0; i < len; ++i)
	{
		int temp = a[i];
		for (int j = 0; j < 4; ++j)
		{
			if (temp<minarray[j])
			{
				int comtemp =minarray[j]; 
				minarray[j] = temp;		
				temp = comtemp;
			}			
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		cout<<minarray[i]<<endl;
	}
	return 0;
}


/*
*此种方法原理比较简单,即利用一个空间大小是k的multiset
*将原始数据的前k个依次插入multiset,然后从元素数据的第k+1个元素开始
*逐渐与multiset的第一个元素比较,(注意,multiset是用红黑树实现的,可以容纳
*多个相同的元素,当比较器是greater时,multiset第一个元素是最大的元素),如果比
*第一元素小,则删除mutiset第一个元素,将此元素插入
*/


/*
#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
using namespace std;

typedef multiset<int, greater<int> >  IntHeap;

///////////////////////////////////////////////////////////////////////
// find k least numbers in a vector
///////////////////////////////////////////////////////////////////////
void FindKLeastNumbers(
      const vector<int>& data,               // a vector of data
      IntHeap& leastNumbers,                 // k least numbers, output
      unsigned int k                              
)
{
      leastNumbers.clear();

      if(k == 0 || data.size() < k)
            return;

      vector<int>::const_iterator iter = data.begin();
      for(; iter != data.end(); ++ iter)
      {
            // if less than k numbers was inserted into leastNumbers
            if((leastNumbers.size()) < k)
                  leastNumbers.insert(*iter);

            // leastNumbers contains k numbers and it's full now
            else
            {
                  // first number in leastNumbers is the greatest one
                  IntHeap::iterator iterFirst = leastNumbers.begin();

                  // if is less than the previous greatest number 
                  if(*iter < *(leastNumbers.begin()))
                  {
                        // replace the previous greatest number
                        leastNumbers.erase(iterFirst);
                        leastNumbers.insert(*iter);
                  }
            }
      }
}

int main() {
	FindKMinElemFromVector<int>ff;
	srand(unsigned(time(0)));
	int N=20;
	int i=0;
	vector<int>v;
	int x;
	for(i=0;i<N;i++) {
		v.push_back(rand()%N);
	}
	cout<<"原始数据是:"<<endl;
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	ff.FindKLeastNumbers(v,3);
}


*/
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<assert.h>
// #include<time.h>

// #define LEN 500000
// #define K 100

// /*堆的性质*/
// #define LEFTSON(i) (2*(i)+1)
// #define RIGHTSON(i) (2*((i)+1))
// #define PARENT(i) (((i)-1)/2)

// void swap(int *a, int *b)
// {
//         assert(a != NULL && b != NULL);

//         if(a != b)
//         {
//                 *a = *a ^ *b;
//                 *b = *a ^ *b;
//                 *a = *a ^ *b;
//         }
// }

// int partition(int *a, int left, int right)
// {
//         int pivot = a[right];
//         int i = left;
//         int j = left - 1;

//         assert(a != NULL);

//         for(i = left; i < right; ++ i)
//         {
//                 if(a[i] < pivot)
//                 {
//                         ++ j;
//                         swap(&a[i],&a[j]);
//                 }
//         }
//         swap(&a[j + 1],&a[right]);
//         return (j + 1);
// }

// void quicksort(int *a, int left, int right)
// {
//         int i = 0;

//         assert(a != NULL);

//         if(left < right)
//         {
//                 i = partition(a,left,right);
//                 quicksort(a, left, i - 1);
//                 quicksort(a, i + 1, right);
//         }
// }

// int QuickSort(int *a, int size)
// {
//         assert(a != NULL);
//         quicksort(a,0,size-1);
// }

// void quickselect(int *a, int left, int right, int k)
// {
//         int i = 0;

//         assert(a != NULL && left <= k
//                 && left <= right && k <= right);

//         if(left < right)
//         {
//                 i = partition(a, left, right);
//                 if(i + 1 <= k)
//                         quickselect(a, i + 1 , right, k);
//                 else if(i > k)
//                         quickselect(a, left, i - 1, k);
//         }
// }

// void QuickSelect(int *a, int size, int k)
// {
//         assert(a != NULL);
//         quickselect(a, 0, size - 1, k);
// }

// /*最大堆*/
// void max_heapify(int *a, int left, int right)
// {
//         int tmp = 0;
//         int child = left;
//         int parent = left;

//         assert(a != NULL);

//         for(tmp = a[parent]; LEFTSON(parent) <= right;parent = child)
//         {
//                 child = LEFTSON(parent);

//                 if(child != right && a[child] < a[child + 1])
//                         child ++;

//                 if(tmp < a[child])
//                         a[parent] = a[child];
//                 else /*满足最大堆的特性，直接退出*/
//                         break;
//         }
//         a[parent] = tmp;
// }

// /*创建最大堆*/
// void build_maxheap(int *a, int size)
// {
//         int i = 0;
//         assert(a != NULL);

//         for(i = PARENT(size); i >= 0 ; -- i)
//                 max_heapify(a,i,size - 1);
// }

// /*最小堆的实现*/
// void min_heapify(int *a, int left, int right)
// {
//         int child = 0;
//         int tmp = 0;
//         int parent = left;

//         assert(a != NULL);

//         for(tmp = a[parent]; LEFTSON(parent) <= right; parent = child)
//         {
//                 child = LEFTSON(parent);

//                 if(child != parent && a[child] > a[child + 1])
//                         child ++;

//                 if(a[child] < tmp)
//                         a[parent] = a[child];
//                 else /*满足最小堆的特性，直接退出*/
//                         break;
//         }
//         a[parent] = tmp;
// }

// /*创建最小堆*/
// void build_minheap(int *a, int size)
// {
//         int i = PARENT(size);

//         assert(a != NULL);

//         for(; i >= 0; -- i)
//                 min_heapify(a, i, size - 1);
// }

// /*采用快速排序查找*/
// void find_Kmin_num_1(int *a , int size, int k)
// {
//         int i = 0;

//         assert(a != NULL);

//         QuickSort(a, size);

// #if 0
//         for(i = 0; i < k ; ++ i)
//                 printf("%d\t",a[i]);

//         printf("\n");
// #endif
// }

// /*采用快速选择实现*/
// void find_Kmin_num_2(int *a, int size, int k)
// {
//         int i = 0;

//         assert(a != NULL);

//         QuickSelect(a, size, k);

// #if 0
//         for(i = 0; i < k ; ++ i)
//                 printf("%d\t",a[i]);

//         printf("\n");
// #endif
// }

// /*采用最大堆实现*/
// void find_Kmin_num_3(int *a, int size, int k)
// {
//         int i = 0;

//         int *b = (int*)malloc(sizeof(int)*k);

//         assert(a != NULL && b != NULL);

//         for(i = 0; i < k; ++ i)
//                 b[i] = a[i];

//         build_maxheap(b,k);

//         for(; i < size; ++ i)
//         {
//                 if(a[i] < b[0])
//                 {
//                         b[0] = a[i];
// // build_maxheap(b , k);
//                         max_heapify(b,0,k - 1);
//                 }
//         }
// #if 0
//         for(i = 0; i < k ; ++ i)
//                 printf("%d\t",b[i]);

//         printf("\n");
// #endif
// }

// /*采用最小堆删除元素的方式实现*/
// void find_Kmin_num_4(int *a ,int size, int k)
// {
//         int i = 0;

//         assert(a != NULL);

//         build_minheap(a, size - 1);
//         for(i = 0; i < k; ++ i)
//         {
// // printf("%d\t",a[0]);

//                 /*删除a[0]，释放a[size - 1 - i]*/
//                 a[0] = a[size -1 - i];
//                 min_heapify(a, 0, size - 2 - i);
//         }
// // printf("\n");
// }

// int main()
// {
//         int a[LEN];
//         int b[LEN];
//         int c[LEN];
//         int d[LEN];

//         int i = 0,j = 0;

//         clock_t _start;
//         double times = 0;

//         srand((int)time(NULL));

//         for(i = 0; i < LEN; ++ i)
//         {
//                 a[i] = rand()%(LEN);
//                 b[i] = a[i];
//                 c[i] = a[i];
//                 d[i] = a[i];

// // printf("%d\t",a[i]);
//         }
// // printf("\n");

//         _start = clock();
//         find_Kmin_num_1(a,LEN,K);
//         times = (double)(clock() - _start)/CLOCKS_PER_SEC;
//         printf("快速排序的查找需要:%f\n",times);

//         _start = clock();
//         find_Kmin_num_2(b,LEN,K);
//         times = (double)(clock() - _start)/CLOCKS_PER_SEC;
//         printf("快速选择的查找需要:%f\n",times);

//         _start = clock();
//         find_Kmin_num_3(c,LEN,K);
//         times = (double)(clock() - _start)/CLOCKS_PER_SEC;
//         printf("最大堆的查找需要:%f\n",times);

//         _start = clock();
//         find_Kmin_num_4(d,LEN,K);
//         times = (double)(clock() - _start)/CLOCKS_PER_SEC;
//         printf("最小堆的查找需要:%f\n",times);

//         return 0;
// }


