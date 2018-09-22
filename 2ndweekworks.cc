#ifdef W2_1

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
public:
	Student():name(""),age(0),number(0),avg(0.0),y1(0),y2(0),y3(0),y4(0){}
	void input(){
		// Tom Hanks,18,7817,80,80,90,70
		char str[41];
		char tmpStr[7][21];
		cin.getline(str, 40);
		
		/* 字符串分割开始 */
		const char *sep = ",";
		char *p;
		p = strtok(str, sep);
		int i = 0;
		while(p){
			strcpy(tmpStr[i], p);
			//cout << "tmpStr[" << i << "] = " << tmpStr[i] << endl; 
			i++;
			p = strtok(NULL, sep);
		}
		/* 字符串分割结束 */
		
		strcpy(name, tmpStr[0]);
		age = stoi(tmpStr[1]);
		number = stoi(tmpStr[2]);
		y1 = stoi(tmpStr[3]);
		y2 = stoi(tmpStr[4]);
		y3 = stoi(tmpStr[5]);
		y4 = stoi(tmpStr[6]);
		//cout << name << ","<<age<<","<<number<<","<<y1<<","<<y2<<","<<y3<<","<<y4<<endl;
	}
	void calculate(){
		avg = (y1 + y2 + y3 + y4)/4.0;
	}
	void output(){
		// Tom Hanks,18,7817,80
		cout << name <<","<<age<<","<<number<<","<<avg << endl;
	}
private:
	char name[21];
	unsigned int age;
	unsigned int number;
	
	unsigned int y1;
	unsigned int y2;
	unsigned int y3;
	unsigned int y4;
	
	double avg;
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}

#endif

#ifdef W2_2

#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
	Sample(int val):v(val){}
	Sample(){v = 0;}
	Sample(const Sample& a){
		v = a.v + 2;
	}
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}

#endif

#ifdef W2_3

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
	Complex(const char str[]){
		/* 字符串分割开始 */
		char tmpStr[2][3];
		const char *sep = "+i";
		char *p;
		char tmp[100];
		strcpy(tmp, str);
		//cout << "str: " << str <<endl;
		//cout << "tmp: " << tmp <<endl;
		p = strtok(tmp, sep);
		int i_ = 0;
		while(p){
			strcpy(tmpStr[i_], p);
			//cout << "tmpStr[" << i << "] = " << tmpStr[i] << endl; 
			i_++;
			p = strtok(NULL, sep);
		}
		/* 字符串分割结束 */
		r = atof(tmpStr[0]);
		i = atof(tmpStr[1]);
		//cout << r << "+" << i << "i" << endl;
	}
	Complex():r(0.0),i(0.0){}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}

#endif


#ifdef W2_4

#include <iostream>
using namespace std;
class A {
	public:
		int i;
		A(int x) { i = x; }
// 在此处补充你的代码
		~A(){cout<<i<<endl;}
};
int main()
{
	A a(1);
	A * pa = new A(2);
	delete pa;
	return 0;
}

#endif