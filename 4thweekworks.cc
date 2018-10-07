#ifdef W4_1

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    MyString(const MyString&s) {
        p = new char[strlen(s.p) + 1];
        strcpy(p, s.p);
    }
    void Copy(const char*s) {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    friend ostream & operator << (ostream &output, const MyString &s) {
        output << s.p;
        return output;
    }
    MyString& operator=(const char*s) {
        delete[]p;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
        return *this;
    }
    void operator=(MyString& a) {
        strcpy(p,a.p);
    }
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}

#endif

#ifdef W4_2

#include <iostream> 
using namespace std;
class MyInt 
{ 
	int nVal; 
	public: 
	MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
	MyInt& operator -(int a){
        nVal-=a;
        return *this;
    }
    operator int () {
    return nVal;
    }
}; 
int Inc(int n) {
	return n + 1;
}
int main () { 
	int n;
	while(cin >>n) {
		MyInt objInt(n); 
		objInt-2-1-3; 
		cout << Inc(objInt);
		cout <<","; 
		objInt-2-1; 
		cout << Inc(objInt) << endl;
	}
	return 0;
}

#endif

#ifdef W4_3

#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
	friend istream & operator >>(istream & i,Point & p){
            i>>p.x>>p.y;
            return i;
        }
        friend ostream & operator <<(ostream & o,Point & p){
            o<<p.x<<","<<p.y;
            return o;
        }
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}

#endif

#ifdef W4_4

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
int** ptr;int _x, _y;

public:
	Array2() :ptr(NULL),_x(0),_y(0) {}
	Array2(int x, int y){
		_x = x; 
		_y = y;
		ptr = new int*[x];
		for (int i = 0; i < x; i++){
			ptr[i] = new int[y];
			}
		}
		int* operator[](int n){
			return ptr[n];
		}
		int operator()(int x, int y){
			return ptr[x][y];
		}
		Array2& operator=(const Array2& a){
			if (ptr != NULL){
				for (int i = 0; i < _x; i++){
					delete[]ptr[i];
				}
			delete[]ptr;
		}
		ptr = new int*[a._x];
		for (int i = 0; i < a._x; i++){
			ptr[i] = new int[a._y];
			memcpy(ptr[i], a.ptr[i], sizeof(int)*a._y);
		}
		_x = a._x;_y = a._y;
		return *this;
	}
	~Array2(){
		for (int i = 0; i < _x; i++)
			delete[]ptr[i];delete []ptr;
	}

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

#endif


#ifdef W4_5

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
    char maxNum[210];
    int len;
public:
    CHugeInt(char * s){
        strcpy(maxNum,s);
        int i=0,j=strlen(s)-1;
        while(i<j)
        {
            swap(maxNum[i],maxNum[j]);
            i++;
            j--;
        }
        //cout<<"init:"<<maxNum<<endl;
        len=strlen(s);
        //cout<<"Init success"<<endl;
    }
    CHugeInt(){
        len=0;
    } 
    CHugeInt(int n){
        int i=0;
        if(n==0)
        {
            maxNum[i++]='0';
        }else{
            while(n)
            {
                maxNum[i++]=n%10+'0';
                n=n/10;
            }    
        }
        maxNum[i]='\0';
        len=i;
        //cout<<maxNum<<endl;
    }
    CHugeInt  operator+(CHugeInt & a)
    {
            //cout<<"hrer"<<endl;
            int i=0,j=0;
            int t,sum=0;
            CHugeInt temps;
            strcpy(temps.maxNum,maxNum);
            temps.len=len;
            //cout<<"before:"<<temps.maxNum<<endl;
            //maxNum=new char[strlen(a.maxNum)+1];
            //cout<<a.len<<","<<len<<endl;
            int flag=0;
            while(j<a.len&&i<temps.len)
            {
                t=a.maxNum[j]-'0';
                int te=temps.maxNum[i]-'0';
                sum=t+te;
                //cout<<t<<"+"<<te<<":"<<sum<<endl;
                if(sum>=10)
                {
                    temps.maxNum[i]=sum%10+'0';
                    //cout<<temps.maxNum[i]<<endl;
                    temps.maxNum[i+1]=sum/10+temps.maxNum[i+1];
                    if(i+1>=temps.len)
                    {
                        temps.maxNum[i+1]+='0'; 
                    }
                    flag=1;
                }else{
                    //cout<<"sum:"<<sum<<endl;
                    flag=0;
                    temps.maxNum[i]=sum+'0';
                }
                //cout<<temps.maxNum[i]<<endl;
                i++,j++;
                sum=0;
            }
            while(j<a.len)
            {
                if(flag==1)
                {
                    temps.maxNum[i+1]=a.maxNum[j];
                    i++,j++;    
                }else{
                    temps.maxNum[i]=a.maxNum[j];
                    i++,j++;
                }
            }
            if(i>=len)
            {
                if(flag==1){
                    temps.maxNum[i+1]='\0';
                    temps.len=i+1;
                }
                else{
                    temps.maxNum[i]='\0';
                    temps.len=i;
                }        
            }
        return temps;
    }
    /*operator char *()
    {
        return maxNum;
    }*/
    CHugeInt & operator +=(int n)
    {
        CHugeInt temps(n);
        *this=this->operator+(temps);
        //cout<<this->maxNum<<endl;
        return *this;
    }
    friend ostream & operator<<(ostream & os,const CHugeInt & s)
    {
            int i=0,j=s.len-1;
            //cout<<"len:"<<s.len<<endl;
            //cout<<"输出:"<<s.maxNum<<endl;
            for(;j>=i;j--)
                os<<s.maxNum[j];
            return os;
    }
    friend CHugeInt  operator+(int n,CHugeInt  s)
    {
        CHugeInt temps(n);
        s=s+temps;
        return s;
    }
    friend CHugeInt  operator+(CHugeInt  s,int n)
    {
        CHugeInt temps(n);
        s=s+temps;
        return s;
    }
    CHugeInt &  operator++()
    {
        (*this)+=1;
        //cout<<"前置自增后："<<this->maxNum<<endl;
        return *(this);
    }
    CHugeInt   operator++(int n)
    {
        CHugeInt temps;
        strcpy(temps.maxNum,maxNum);
        temps.len=len;
        this->operator +=(1);
        //cout<<temps.maxNum<<endl;
        //cout<<"len:"<<temps.len<<endl;
        return temps;
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}

#endif