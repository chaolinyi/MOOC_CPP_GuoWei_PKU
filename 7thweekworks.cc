#ifdef W7_1

#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
// 在此处补充你的代码
T* s, T* e){
	T tmp;
	for (;s != e; s++)
	{
		tmp = tmp + *s;
	}
	return tmp;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}

#endif

#ifdef W7_2

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
void Print(string s);
void Inc(int &n);
template <class T, class Pred>
void MyForeach(T* s, T* e, Pred op){
	for (; s != e; s++){
		op(*s);
	}
	return;
}
void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++ n;
}
string array[100];
int a[100];
int main() {
	int m,n;
	while(cin >> m >> n) {
		for(int i = 0;i < m; ++i)
			cin >> array[i];
		for(int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(array,array+m,Print);		 
		cout << endl;
		MyForeach(a,a+n,Inc);		 
		for(int i = 0;i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}

#endif

#ifdef W7_3

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
bool LargerThan2(int n);
bool LongerThan3(string s);
template <class T, class Pred>
T* Filter(T* s, T* e, T* nA, Pred op){
	for (; s != e; s++){
		if (op(*s)){
			*nA = *s;
			nA++;
		}
	}
	return nA;
}

bool LargerThan2(int n)
{
	return n > 2;
}
bool LongerThan3(string s) 
{
	return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
	string * p = Filter(as1,as1+5,as2,LongerThan3);
	for(int i = 0;i < p - as2; ++i)
		cout << as2[i];
	cout << endl; 
	int * p2 = Filter(a1,a1+5,a2,LargerThan2);
	for(int i = 0;i < p2-a2; ++i)
		cout << a2[i] << ",";
	return 0;
}

#endif

#ifdef W7_4

#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
private:
	bool valid;
public:
	MyCin():valid(true){}
	operator bool(){
		return valid;
	}
	MyCin& operator >> (int& n){
		cin >> n;
		if (n == -1)
			valid = false;
		return *this;
	}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}

#endif

#ifdef W7_5

#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
public:
    istream *a;
    T *p;
    CMyistream_iterator<T>(istream&is){
        p=new T[5];
        a=&is;
        *a>>*p;
    }
    ostream& operator<<(ostream&os){
        os<<*p;
        return os;
    }
    friend T operator*(CMyistream_iterator<T> b){
        return *b.p;
    }
    friend CMyistream_iterator operator++(CMyistream_iterator<T> &b,int k){
        b.p++;
        *b.a>>*b.p;
        return b;
    }
};

int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //读入 n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //读入 n2
		 inputInt ++;
		 n3 = * inputInt; //读入 n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}

#endif

#ifdef W7_6

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass {
// 在此处补充你的代码
private:
	T* p;
	size_t size;
public:
	myclass(T *a, size_t _size){
        size = _size;
        p = new T[size];
        for (int i = 0; i < size; ++i) {
            *(p+i) = a[i];
        }
    }

	~myclass( ) {
		delete [] p;
	}
	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
int main() {
	char line[100];
	while( cin >> line ) {
		myclass<char> obj(line,strlen(line));
		obj.Show();
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
		{
			cin >> a[i];
		//	cout << a[i] << endl;
		}
		myclass<int> obj2(a,n);
		obj2.Show();
	}
	return 0;
}

#endif

#ifdef W7_7

#include <iostream>
using namespace std;

bool Greater2(int n1,int n2) 
{
	return n1 > n2;
}

bool Greater1(int n1,int n2) 
{
	return n1 < n2;
}

bool Greater3(double d1,double d2)
{
	return d1 < d2;
}

template <class T1,class T2>
void mysort(
// 在此处补充你的代码
T1*s, T1*e, T2(*h)(T1 a, T1 b)) {
    int gap = e - s;
    for(int i=0;i<gap-1;i++)
        for (int j = 0; j < gap -1- i; j++)
        {
            T1 swap;
            if (!(*h)(*(s+j),*(s+j+1)))
            {
                swap = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = swap;
            }
        }
}

#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    
	mysort(an,an+NUM,Greater1); //从小到大排序 
    
	for( int i = 0;i < NUM; i ++ )
       cout << an[i] << ",";
    
	mysort(an,an+NUM,Greater2); //从大到小排序 
    cout << endl;
    
	for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ","; 
    cout << endl;
    
	double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //将数组从下标1到下标4从小到大排序 
    
	for( int i = 0;i < 6; i ++ )
         cout << d[i] << ","; 

	return 0;
}

#endif