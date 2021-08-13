/**
Create a const whose value is determined at runtime by
reading the time when the program starts (you�ll have
to use the <ctime> standard header). Later in the program,
try to read a second value of the time into your const
and see what happens.
**/

Both constansts will be initialized with the same value

#include <iostream>
#include <ctime>

using namespace std;

int main() {

   time_t timer;
   struct tm* timeinfo;

   time(&timer);
   timeinfo = localtime(&timer);

   const char* first_time = asctime(timeinfo);

   cout << first_time << endl;

   // Takes some CPU time
   for (int i = 0, j = 0; i < 10000000000; i++)
       j++;

   const char* second_time = asctime(timeinfo);

   cout << second_time << endl;

   return 0;
}

#include "iostream"
using namespace std;

int main()

{
   // Read two integers

   cout << "Enter two integers: ";

   int number1, number2;

   cin >> number1 >> number2;

   try
   {
       if (number2 == 0)
           throw number1;

       cout << number1 << " / " << number2 << " is "
           << (number1 / number2) << endl;

       cout << "C" << endl;
   }
   catch (int e)
   {
       cout << "A";
   }

   cout << "B" << endl;

   return 0;
}

#include <iostream>

class MyClass {
public:

	void func() {
		throw MyException("抛出了异常");//异常是抛出了一个类
	}

	/*异常类*/
	class MyException {
	public:
		MyException( char* msg) : data(msg) {}
		char* what()  { return data; }
	private:
		char* data;
	};


};

int main() {

	try {
		MyClass m;
		m.func();
	}
	catch (MyClass::MyException  ex) {
		std::cout << "捕捉到了异常: " << ex.what() << '\n';
	}

	return 0;
}

#include <iostream>
using namespace std;
class MyClass 
{
public:
   MyClass() {}
   MyClass(const MyClass& m) { cout << ">>>> 拷贝构造函数" << endl; }
};
void function1(MyClass m) {
   cout << "function1(MyClass) call." << endl;
}
MyClass function2() {
   cout << "function2() call. 返回静态局部对象" << endl;
   static MyClass m;//创建静态局部对象
   return m;
}
int main() {
   MyClass obj;
   function1(obj);
   obj = function2();

   MyClass obj1(obj);
   return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int a[3] = { 1,2,3 };
	int* p = a;

	(*a)++;
	(*p)++;

	cout << a[0] << endl;
	return 0;

}

/*
Create a class with its own operator new. This operator
should allocate ten objects, and on the eleventh object
"run out of memory" and throw an exception. Also add a
static member function that reclaims this memory. Now
create a main( ) with a try block and a catch clause
that calls the memory-restoration routine. Put these
inside a while loop, to demonstrate recovering from an
exception and continuing execution.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

class Item
{
private:int id = 0;

public:
	Item(int _id) :id(_id) { cout << "Creating Item[" << id << "]" << endl; };
	  
	~Item(){ cout << "Deleting Item[" << id << "]" << endl; }
};


template<typename T, int size=20>
class Storage
{
private: static vector<T*> storage;

public:
	void* operator new(size_t sz) {
		for (int i = 1; i <= size; i++) {
			if (i>=11)
				throw runtime_error("Not enough memory");
			storage.push_back(new T(i));
		}
	}

	static void cleanUp() {
		int size_ = storage.size();
		for (int i = 0; i < size_; i++) {
			T* temp = storage.back();
			storage.pop_back();
			delete temp;
		}
		assert(storage.size() == 0);
	}
};
//
///*
//1.静态成员变量不能再类中被初始化。
//
//2.静态成员函数不能调用类的非静态成员。就像静态成员变量一样，不属于类的对象，所以就没有this指针。
//
//3.静态数据成员不能受private控制符的作用。
//
//4.静态数据成员可以直接被类名调用。
//*/
//
////这句话什么意思
///*利用类模板的规则修改限定符，初始化静态成员变量*/
template<typename T, int size>
vector<T*> Storage<T, size>::storage;



int main() {
	while (true) {
		try {
			Storage<Item, 15>* m = new Storage<Item, 15>();
		}
		catch (runtime_error& exc) {
			cout << "Exception detected: " << exc.what() << '\n';
			break;
		}
	}
	Storage<Item, 15>::cleanUp();

	return 0;
}

#include <iostream>
using namespace std;
class MyClass
{
public:
   MyClass() {}
   MyClass(const MyClass& m) { cout << ">>>> 拷贝构造函数" << endl; }
};
void function1(MyClass m) {
   cout << "function1(MyClass) call." << endl;
}

MyClass function2() {
   cout << "function2() call. 返回静态局部对象" << endl;
   MyClass m;//创建静态局部对象
   cout << "内部地址：" << &m << endl;
   return m;
}

int main() {
   MyClass obj1;
   cout << "外部地址1：" << &obj1 << endl;
   //function1(obj);
   MyClass obj;
   obj=obj1;
   cout << "外部地址2：" << &obj << endl;

   //MyClass obj1(obj);
   return 0;
}


#include<iostream>
#include<string>

using namespace std;

class Group
{
public:
	virtual int add(int x, int y) = 0;
	virtual int sub(int x, int y) = 0;
};

class GrpoupA :public Group
{
	virtual int add(int x, int y)
	{
		return x + y;
	}
	virtual int sub(int x, int y)
	{
		return x - y;
	}
};

class GrpoupB :public Group
{
	virtual int add(int x, int y)
	{
		return x + y;
	}
	virtual int sub(int x, int y)
	{
		int k = 10;
		int i, j;
		int result = 0;
		int p = 1;
		do {
			i = x % k;
			j = y % k;
			if (i < j)i += 10;
			result += (i - j) * p;
			x = x / k;
			y = y / k;
			p *= 10;
		} while (x || y);
		return result;
	}
};


class GrpoupC :public Group
{
	virtual int add(int x, int y)
	{
		int k = 10;
		int i, j;
		int result = 0;
		int p = 1;
		do {
			i = x % k;
			j = y % k;
			//cout << i << "  " << j << endl;
			result += ((i + j)%10) * p;
			x = x / k;
			y = y / k;
			p *= 10;
		} while (x || y);
		return result;
	}

	virtual int sub(int x, int y)
	{
		int k = 10;
		int i, j;
		int result = 0;
		int p = 1;
		do {
			i = x % k;
			j = y % k;
			//cout << i << "  " << j << endl;
			if (i < j)i += 10;
			result += (i - j) * p;
			x = x / k;
			y = y / k;
			p *= 10;
		} while (x || y);
		return result;
	}
};

int * split(string &s)
{
	int flg = 0;
	int pos = s.find("+");
	if (pos == s.npos) {
		pos = s.find("-");
		flg = 1;
	}
	string num1;
	string num2;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i < pos)num1 += s[i];
		else if (i == pos);
		else num2 += s[i];
	}
	int number1 = stoi(num1);
	int number2 = stoi(num2);
	static int num[3];
	num[0] = number1;
	num[1] = number2;
	num[2] = flg;
	return num;
}



int main()
{
	int n = 0;
	cin >> n;
	int stu[100] = {0};
	for (int i = 1; i <=n ; ++i)
	{
		cin >> stu[i];
	}
	Group * G[100];
	int cnt = 0;
	for (;;)
	{
		int id;
		string s;
		cin >> id;
		if (id==0)break;
		cin >> s;
		int cls = stu[id];
		int * a= split(s);
		if(cls == 1)		G[cnt] = new GrpoupA();
		else if(cls==2)		G[cnt] = new GrpoupB();
		else				G[cnt] = new GrpoupC();
		int num1 =a[0];
		int num2 =a[1];
		if (a[2] != 0)
		{
			cout << G[cnt]->sub(num1,num2) << endl;
		}
		else
			cout << G[cnt]->add(num1, num2) << endl;
		cnt++;
	}
	return 0;
}

#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	string IdPerson = "";
	string Name = "";
	string Sex = "";
	string Birthday = "";
	Person() {};
	Person(string id, string name, string sex, string bir) :IdPerson(id), Name(name), Sex(sex), Birthday(bir) {};
	Person(const Person& p) {
		IdPerson = p.IdPerson;
		Name = p.Name;
		Sex = p.Sex;
		Birthday = p.Birthday;
		cout << "Copy Constructor called" << endl;
	}

};

int main()
{
	Person p1("3170100125", "张友超", "男", "1999-04-22");
	Person p2(p1);

	return 0;
}


#include<iostream>
#include<string>
#include <math.h>
#include<list>
using namespace std;

class Shape
{
public:
	virtual void getInfo() = 0;
};

class Circle :public Shape
{
public:
	double r = 0;
	Circle(double R) :r(R) {};
	virtual void getInfo()
	{
		cout << "圆形 , 半径为：" << r << endl;
		cout << "圆形的面积：" << 3.14 * r * r << endl;
	}
};

class Rectangle :public Shape
{
public:
	double x = 0;
	double y = 0;
	Rectangle(double X,double Y):x(X),y(Y) {};
	virtual void getInfo()
	{
		cout << "长方形，边长为" << x << ", " << y << endl;
		cout << "长方形的面积：" << x*y << endl;
	}
};

class Triangle :public Shape
{
public:
	double x = 0;
	double y = 0;
	double z = 0;
	Triangle(double X, double Y,double Z) :x(X), y(Y) ,z(Z){};
	virtual void getInfo()
	{
		double s = (x + y + z) / 2.0;
		double area = sqrt(s * (s - x) * (s - y) * (s - z));
		cout << "三角形，边长为" << x << ", " << y <<", "<<z<< endl;
		cout << "三角形的面积：" << area << endl;
	}
};

int main()
{
	void (Shape ::*ptfunc)()=&Shape::getInfo;
	list<Shape*> S;
	Shape* S1 = new Circle(10);
	Shape* S2 = new Rectangle(10,10);
	Shape* S3 = new Triangle(10,10,10);
	S.push_back(S1);
	S.push_back(S2);
	S.push_back(S3);
	cout << "virtural-------------------------" << endl;
	for (Shape* s : S)
	{
		s->getInfo();
		cout << endl;
	}
	cout << "func point-------------------------" << endl;
	for (Shape* s : S)
	{
		(s->*ptfunc)();
		cout << endl;
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

int over = 0;

class A
{
private:
	int i;
public:
	A(int j):i(j){};
	A() {};
private:
	void pr()
	{
		cout <<"A::pr()" << endl;
	}
};



class B:public A
{
public:
	B() {};
private:
	void pr()
	{
		cout << "B::pr()"  << endl;
	}
};

/*默认参数只能在声明中给出*/
void print(int i, int j = 9999);

int main()
{
	A a;
	B b;
	

	return 0;
}

void print(int i, int j)
{
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
}

#include<iostream>
using namespace std;
class nothing
{
public:
	nothing() { cout << "nothing" << endl; }
	nothing(const nothing& n1) { cout << "copy nothing" << endl; }
};
nothing co(nothing n){//形参拷贝构造。但是如果拷贝则不构造
	return  n;//返回对象拷贝构造
}
int main()
{
	nothing n1;
	nothing n2 = n1;
	n2 = n1;
	cout << "------------------------------\n";
	n2 = co(n1);
	return 0;
}

#include <string>
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;
class A
{
public:virtual ~A() {};
};
class B :public A{};
int main()
{
	A* ap;
	ap = new B;
	cout << typeid(*ap).name() << endl;

	return 0;
}

#include <iostream>
using namespace std;

class Distance
{
private:
   int feet;             // 0 到无穷
   int inches;           // 0 到 12
public:
   // 所需的构造函数
   Distance() {
       feet = 0;
       inches = 0;
   }
   Distance(int f, int i) {
       feet = f;
       inches = i;
   }
   friend ostream& operator<<(ostream& output,const Distance& D);
   friend istream& operator>>(istream& input, Distance& D);
};

istream& operator>>(istream& input, Distance& D){
   input >> D.feet >> D.inches;
   return input;
}

ostream& operator<<(ostream& output,const Distance& D){
   output << "F = " << D.feet << " I = " << D.inches ;
   return output;
}

int main()
{
   Distance D1(11, 10), D2(5, 11), D3;

   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << endl;
   cout << "Second Distance :" << D2 << endl;
   cout << "Third Distance :" << D3 << endl;
   return 0;
}


/*
必须创建的成员函数：可能发生危险的地方（有指针的时候）
default constructor  方便创建数组
copy  constructor    避免浅拷贝，指针出现问题
operate assignment=	 避免指针出问题（）
virtural deconstructor 避免子类的指针出现问题
*/



#include<iostream>
#include<string>
using namespace std;

class Fi;//第二种类型的声明

class Fee
{
public:
	int i = 1;
	Fee() { cout << "Fee()\n"; };
	
	//explicit Fee(int) { cout << "Fee(int)\n"; };

	Fee(const Fee& f) { cout << "Fee(Fee)\n"; };//复制构造函数

	/*可能的转换方式2：利用别的类来做构造函数*/
	explicit Fee(const Fi& f) { cout << "Fee(Fi)\n"; };//防止被用来做类型转换，只用来做构造函数使用
													   //这里隐藏一个隐式的转换，
													   //会和运算符转换造成冲突，所以应该加上 explicit
	
	
	Fee& operator=(const Fee& that) {//这里要注意，这里是为了防止 delete[] 删除原来的地址
		if (this != &that) {//不指向同一个东西才需要做赋值操作
			this->i = that.i;
			cout << "=()\n";
		}
		return *this;
	}

	virtual ~Fee() { cout << "~Fee()\n"; };
};

class Fi
{
public:
	Fi() { cout << "Fi()\n"; };

	/*转换方式1：转换运算符实现转换*/
	operator Fee() const
	{
		cout << "Fi->Fee()\n";
		Fee f;
		return f;
	}

	/*转换方式3：最好的方式toclass()*/
	Fee  toFee()
	{
		cout << "Fi  to  Fee()\n";
		Fee f;
		return f;
	}
};



void main()
{
	Fi fi;
	Fee fum;
	cout << "----------------" << endl;
	//fum = fi;//如果没有关键子explicit，这里会首先用利用构造函数 Fee(const Fi&)创建一个对象，然后调用operater = //
	//这样编译器就不能找到这里的类型错误
	fum = fi.toFee();
}


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

class Item
{
private:int id = 0;

public:
	Item(int _id) :id(_id) { cout << "Creating Item[" << id << "]" << endl; };
	  
	~Item(){ cout << "Deleting Item[" << id << "]" << endl; }
};


template<typename T, int size>
class Storage
{
private: static vector<T*> storage;
public:
	void* operator new(size_t sz);
	static void cleanUp();
};

/*
1.静态成员变量不能再类中被初始化。

2.静态成员函数不能调用类的非静态成员。就像静态成员变量一样，不属于类的对象，所以就没有this指针。

3.静态数据成员不能受private控制符的作用。

4.静态数据成员可以直接被类名调用。
*/

//这句话什么意思
/*利用类模板的规则修改限定符，初始化静态成员变量*/
template<typename T, int size>
vector<T*> Storage<T, size>::storage;//初始化

template<typename T, int size>
void* Storage<T, size>::operator new(size_t sz) {
	for (int i = 1; i <= size; i++) {
		if (i >= 11)
			throw runtime_error("Not enough memory");
		storage.push_back(new T(i));
	}
}

template<typename T, int size>
static void Storage<T, size>::cleanUp() {
	int size_ = storage.size();
	for (int i = 0; i < size_; i++) {
		T* temp = storage.back();
		storage.pop_back();
		delete temp;
	}
	assert(storage.size() == 0);
}


int main() {
	while (true) {
		try {
			Storage<Item, 15>* m = new Storage<Item, 15>();
		}
		catch (runtime_error& exc) {
			cout << "Exception detected: " << exc.what() << '\n';
			break;
		}
	}
	Storage<Item, 15>::cleanUp();

	return 0;
}

#include<iostream>
#include<string>
using namespace std;

namespace A {
	int m;
	namespace B {
		int m;
		int n;
		void F() {
			m = 3;
			n = 4;
		}
	}
	void F(){
		B::m += 7;
	m = 23;
	}
}
namespace B {
	int m;
}

void main() {
	int m;
	m = 8;
	A::m = 9;
	A::B::m = 15;
	B::m = 111;
	cout << m << endl;
	cout << B::m << endl;
	A::B::F();
	cout << B::m << endl;
	using namespace A;
	cout << A::B::m << endl;
	cout << m << endl;
	cout << A::m << endl;
}

#include<iostream>
#include<string>
using namespace std;

class A {
private:
	static int k;
	int m;
	int n;
public:
	A(int k = 111, int m = 222) {//这样的话可以不需要默认构造函数
		A::k = k;
		A::m = m;
	}
	static int GetK() {
		return k;//静态成员变量只能通过静态方法访问
	}

	static int SetK(int i) {
		k = i;
		return k;//静态成员变量只能通过静态方法访问
	}

	int GetM() {
		return m;
	}
};
int A::k;

int m2 = 200;

int* F(int i) {
	static int m = 100;
	int n = 100;

	cout << m++ << endl;
	cout << n++ << endl;

	m += i;
	n += i;
	return &m;
}

void main() {

	cout << "static in class\n";
	A a1, a2;
	cout << sizeof(a1) << endl;
	cout << a1.GetK() << endl;
	cout << a2.GetK() << endl;

	cout << a1.SetK(123123) << endl;
	cout << a2.GetK() << endl;
	cout << "static in function\n";

	int* ip = F(3);
	cout << *ip << endl;
}
// C++ program for implementing B+ Tree
// BP node

