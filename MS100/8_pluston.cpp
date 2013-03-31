#include <iostream>
using namespace std;

class sumplus
{
public:
	sumplus()
	{
		n++;
		sum = sum + n ;
	}
	static int get_n()
	{
		return sum;
	}
private:	
	static int n;
	static int sum;
};

int sumplus::n = 0 ;
int sumplus::sum = 0;
int main()
{
	sumplus* p = new sumplus[100];
	
	cout<<sumplus::get_n()<<endl;
	
	delete []p;
}