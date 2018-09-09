#ifdef W1_1

#include <iostream>
using namespace std;
class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(
// 在此处补充你的代码
A &a, A &b
)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
	return 0;
}

#endif

#if W1_2

#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
int* &a, int* &b
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
	return 0;
}

#endif

#if W1_3

#include <iostream>
using namespace std;
// 在此处补充你的代码
int&
getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}

#endif

#if W1_4

#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
// 在此处补充你的代码
//{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}
0
};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}

#endif
