#ifdef W3_1

#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int
// 在此处补充你的代码
	&v){val = v;}
	A():val(123){}
	A& GetObj(){ return *this;}
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}

#endif

#ifdef W3_2

#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big  // 封闭类
{
public:
	int v;
	Base b;  // 成员对象
// 在此处补充你的代码
	Big(int val):v(val),b(val){}
	Big(Big& big):v(big.v),b(big.b.k){}
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}

#endif


#ifdef W3_3

#include <iostream>
using namespace std;
// 在此处补充你的代码

class Animal
{
	public:
		static int number;
		Animal(){
			number++;
		}
		virtual ~Animal()//如果不加virtual,删除c2的时候就不能调用Cat的析构函数了 
		{
			number--;
		}
};
class Dog:public Animal
{
	public:
		static int number;
		Dog()
		{
			number++;
		}
		~Dog()
		{
			number--;
		}
};
class Cat:public Animal
{
	public:
		static int number;
		Cat()
		{
			number++;
		}
		~Cat()
		{
			number--;
		}
};
int Animal::number=0,Dog::number=0,Cat::number=0;

void print() {
	cout << Animal::number << " animals in the zoo, " 
	<< Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}

#endif


#ifdef W3_4

#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
// 在此处补充你的代码
    const A* getPointer() const
    {
        return this;
    }
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}

#endif


#ifdef W3_5

#include <iostream>
#include <string>




#endif