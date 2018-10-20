#ifdef W6_1

#include <iostream>
using namespace std;
class B { 
	private: 
		int nBVal; 
	public: 
		void Print() 
		{ cout << "nBVal="<< nBVal << endl; } 
		void Fun() 
		{cout << "B::Fun" << endl; } 
		B ( int n ) { nBVal = n;} 
};
class D : public B{
private:
    int nDVal;
public:
    D(int n):B(3 * n){
        nDVal = n;
    }
    void Fun(){
        cout << "D::Fun" << endl; } 
    void Print(){
        B::Print();
        cout << "nDVal=" << nDVal << endl; } 
};
int main() { 
	B * pb; D * pd; 
	D d(4); d.Fun(); 
	pb = new B(2); pd = new D(8); 
	pb -> Fun(); pd->Fun(); 
	pb->Print (); pd->Print (); 
	pb = & d; pb->Fun(); 
	pb->Print(); 
	return 0;
}

#endif

#ifdef W6_2

#include <iostream> 
using namespace std;
class A { 
	private: 
		int nVal; 
	public: 
		void Fun() 
		{ cout << "A::Fun" << endl; }; 
		void Do() 
		{ cout << "A::Do" << endl; } 
}; 
class B:public A { 
	public: 
		virtual void Do() 
		{ cout << "B::Do" << endl;} 
}; 
class C:public B { 
	public: 
		void Do( ) 
		{ cout <<"C::Do"<<endl; } 
		void Fun() 
		{ cout << "C::Fun" << endl; } 
}; 
void Call(
// 在此处补充你的代码
B& p
) { 
	p.Fun(); p.Do(); 
} 
int main() { 
	C c; 
	Call( c); 
	return 0;
}

#endif

#ifdef W6_3

#include <iostream> 
using namespace std;
class A 
{ 
public:
	A() { }
// 在此处补充你的代码
	virtual ~A(){ cout << "destructor A" << endl;}
}; 
class B:public A { 
	public: 
	~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
	A * pa; 
	pa = new B; 
	delete pa; 
	return 0;
}

#endif

#ifdef W6_4

#include <iostream>
using namespace std;
class A {
	private:
	int nVal;
	public:
	void Fun()
	{ cout << "A::Fun" << endl; };
	virtual void Do()
	{ cout << "A::Do" << endl; }
};
class B:public A {
	public:
	virtual void Do()
	{ cout << "B::Do" << endl;}
};
class C:public B {
	public:
	void Do( )
	{ cout <<"C::Do"<<endl; }
	void Fun()
	{ cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
A* p
) {
	p->Fun(); p->Do();
}
int main() {
	Call( new A());
	Call( new C());
	return 0;
}

#endif