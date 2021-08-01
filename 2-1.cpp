//////#include<iostream>
//////#include<string.h>
//////using namespace std;
//////
////////class A
////////{
////////private:
////////	int x;
////////public:
////////	A(int t = 0) :x(t) {     }//调用格式为“构造函数 : A(初始值),B(初始值),C(初始值)……”，如下，其中A、B、C分别是类的成员变量：
////////
////////	int operator+(const A& a1) 
////////	{ 
////////		return x + a1.x; 
////////	}
////////};
////////
////////class B
////////{
////////public:
////////	void add1(int x, int y) {
////////		cout <<"在B中="<< x + y << endl;
////////	}
////////};
////////class D :public B
////////{
////////public:
////////	void add(int x, int y,int z) {
////////		cout << "在D中=" << x + y +z << endl;
////////	}
////////};
//////
//////
//////class A {
//////public:
//////    A(int i) { x = i; }
//////    void dispa() {
//////        cout << x << ',';
//////    }
//////private:
//////    int x;
//////};
//////class B : public A {
//////public:
//////    B(int i) : A(i + 10) {
//////        x = i;
//////    }
//////    void dispb() {
//////        dispa();
//////        cout << x << endl;
//////    }
//////private:
//////    int x;
//////};
//////int main() {
//////    B b(2);
//////    b.dispb();
//////    return 0;
//////}
////#include <iostream>
////#include <iomanip>
////using namespace std;
////class TDVector {
////private:
////    double x;
////    double y;
////public:
////    TDVector() {
////        x = y = 0;
////    }
////    /**    你提交的代码将被嵌在这里（替换本行内容）  **/
////    /*带参构造函数*/
////    TDVector(double x_, double y_)
////    {
////        x = x_;
////        y = y_;
////    }
////    double getX() { return x; }
////    double getY() { return y; }
////    void setX(double x_) { x = x_; }
////    void setY(double y_) { y = y_; }
////    TDVector operator+(const TDVector& a)
////    {
////        TDVector c;
////        c.x =x+ a.x;
////        c.y =y+ a.y;
////        return c;
////    }
////
////};
////int main() {
////    TDVector a;
////    /*double x, y;*/
////    //cin >> x >> y;
////    TDVector b(1.1, 2.2);
////    //cin >> x >> y;
////    TDVector c;
////    c.setX(3.3);
////    c.setY(4.4);
////    TDVector d;
////    d = a + b + c;
////    cout << fixed << setprecision(2) << d.getX() << ' ' << d.getY();
////    return 0;
////}
//
//#include <iostream>
//using namespace std;
//class People {
//private:
//    string id;
//    string name;
//public:
//    People(string id, string name) {
//        this->id = id;
//        this->name = name;
//    }
//    string getId() {
//        return this->id;
//    }
//    string getName() {
//        return name;
//    }
//};
//class Student : public People {
//private:
//    string sid;
//    int score;
//public:
//    Student(string id, string name, string sid, int score)
//        
//        /** 你提交的代码将被嵌在这里（替换此行） **/
//        :People(id, name) {
//        this->sid = sid;
//        this->score = score;
//
//    }
//friend ostream& operator <<(ostream& o, Student& s);
//};
//ostream& operator <<(ostream& o, Student& s) {
//    o << "(Name:" << s.getName() << "; id:"
//        << s.getId() << "; sid:" << s.sid
//        << "; score:" << s.score << ")";
//    return o;
//}
//int main() {
//    Student zs("370202X", "Zhang San", "1052102", 96);
//    cout << zs << endl;
//    return 0;
//}

//#include<iostream>
//#include<string.h>
//using namespace std;
//
//
//
//class Car;//需要一个前置声明
//class Boat
//{
//private:
//	int n;
//public:
//	Boat(int t) { n = t; };
//	friend int getTotalWeight(const Boat& b, const Car& c);
//};
//class Car
//{
//private:
//	int m;
//public:
//	Car(int t) { m = t; };
//	friend int getTotalWeight(const Boat& b, const Car& c);
//};
//int getTotalWeight(const Boat& b, const Car& c)
//{
//	return c.m + b.n;
//}
//
//int main() 
//{   int n, m; 
//	cin >> n >> m; 
//	Boat boat(n); 
//	Car car(m); 
//	cout << "船和汽车共重" << getTotalWeight(boat, car) << "吨" << endl; 
//}

#include<iostream>
#include<string.h>

using namespace std;

class Publication
{
protected:
	string title;//名称
	float price;//原价
	int day;//租期
public:
	virtual void display() = 0;//打印价格清单
	Publication(string a, float b, int c)
	{
		title = a;
		price = b;
		day = c;
	}
};

class Book :public Publication
{
private:
	double old = 0;
public:
	Book(string a, float b, int c, double d) :Publication(a, b, c) { old = d; }
	virtual void display()
	{
		cout << title;
		printf_s(" %.1f", day * 1.2);
		if (day * 1.2 > 2 * price * old)
			printf_s(" %.1f R", 2 * price * old);
		cout << endl;

	}
};

class Tape :public Publication
{
private:
	int num = 0;
public:
	Tape(string a, float b, int c, int d) :Publication(a, b, c) { num = d; }
	virtual void display()
	{
		cout << title;
		double cnt = price / (1 + num / 3);
		printf_s(" %.1f", day * 1.2);
		if (day * 1.2 > 2*cnt)
			printf_s(" %.1f R", 2*cnt);
		cout << endl;
	}
};

int main1()
{
	Publication *pp[10];
	int type;
	int cnt = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> type;
		if (type == 1) {
			string a; float b; int c; double d;
			cin >> a >> b >> c >> d;
			pp[i] = new Book(a, b, c, d);
		}
		else if (type == 2)
		{
			string a; float b; int c; int d;
			cin >> a >> b >> c >> d;
			pp[i] = new Tape(a, b, c, d);
		}
		else {
			cnt = i;
			break;
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		pp[i]->display();
	}

	return 0;
}