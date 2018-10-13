#ifdef W5_1

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class MyString
{
public:
    MyString() { sValue = ""; };
    MyString(const char *s) { 
        int n = strlen(s);
        sValue = new char[n + 1];
        int i;
        for (i = 0; i < n; i++)
            sValue[i] = s[i];
        sValue[i] = '\0';
    };
    MyString(const string &s) { 
        sValue = new char[strlen(s.c_str()) + 1];
        strcpy(sValue, s.c_str()); 
    };

    MyString operator()(int i, int j) {
        MyString res;
        res.sValue = new char[j];
        int start=i;
        int idx = 0;
        for (idx=0; idx < j; idx++)
            res.sValue[idx] = sValue[start++];
        res.sValue[idx] = '\0';
        return res;
    }
    char& operator[](int i) { return sValue[i]; }
    friend ostream& operator<<(ostream &os,const MyString &s)
    {
        if (s.sValue == NULL)
            return os;
        else
        {
            os <<s.sValue;
            return os;
        }
    }
    friend MyString operator+(const char*str, const MyString &rhs)
    {
        MyString res(str);
        res = res + rhs;
        return res;
    }
    MyString operator+(const MyString &rhs)
    {
        MyString res;
        int n = strlen(sValue) + strlen(rhs.sValue);
        res.sValue = new char[n];
        strcpy(res.sValue, sValue);
        strcat(res.sValue, rhs.sValue);
        return res;
    }
    MyString operator+(const char *rhs)
    {
        MyString res;
        MyString r(rhs);
        res = *this + r;
        return res;
    }
    MyString& operator+=(const char *rhs) {
        MyString res;
        MyString r(rhs);
        res = *this + r;
        *this = res;
        return *this;
    }
    bool operator < (const MyString & rhs) {
        int flag=strcmp(sValue, rhs.sValue);
        if (flag == -1)
            return true;
        else
        {
            return false;
        }
    }
    bool operator > (const MyString & rhs) {
        int flag = strcmp(sValue, rhs.sValue);
        if (flag == 1)
            return true;
        else
        {
            return false;
        }
    }
    bool operator ==(const MyString & rhs) {
        int flag = strcmp(sValue, rhs.sValue);
        if (flag == 0)
            return true;
        else
        {
            return false;
        }
    }
private:
    char* sValue;
};


int compareString(const void * e1, const void * e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1>*s2)
        return 1;
}

int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = { "big","me","about","take" };
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3; s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1; s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), compareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5, 10) << endl;
    system("pause");
    return 0;
}

#endif

#ifdef W5_4

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

#ifdef TEST

#include <iostream>
using namespace std;

class A{
	public:
		A(){cout << "A()" << endl;}
		~A(){cout << "~A()" << endl;}
		void func(int a){
			cout << a << endl;
		}
		void f(){
			cout << "hello" << endl;
		}
	private:
		int hello;
};
class B : public A{
	public:
		B(){cout << "B()" << endl;}
		~B(){cout << "~B()" << endl;}
		void func(int a)
		{
			A::func(a);
			cout << a * 2 << endl;
		}
	private:
		int hello;
};

int main (){
	B b;
	//b.func(2);
	return 0;
}

#endif