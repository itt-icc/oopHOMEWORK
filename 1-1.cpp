//#include<iostream>
//#include<string.h>
//using namespace std;
//class Circle { 
//private:
//	double r_ = 0;
//	double pai_ = 3.1415926;
//public:
//	double getR()
//	{
//		return r_;
//	}
//	void setR(double r)
//	{
//		r_ = r;
//	}
//	double getArea()
//	{
//		return pai_ * r_ * r_;
//	}
//};
//class Box
//{
//private:
//	double x;
//	double y;
//	double z;
//public:
//	void get_value()
//	{
//		cin >> x >> y >> z;
//	}
//	void display()
//	{
//		cout << x * y * z << endl;
//	}
//};
//class Student
//{
//private:
//	int id;
//	string name;
//	char sex;
//public:
//	void display()
//	{
//		cout << "num:" << id << endl;
//		cout << "name:" << name << endl;
//		cout << "sex:" << sex << endl;
//		cout << endl;
//	}
//	Student(int id_, string name_, char sex_)
//	{
//		cout << "Constructor called." << endl;
//		id = id_;
//		name = name_;
//		sex = sex_;
//	}
//	~Student()
//	{
//		cout << "Destructor called." << endl;
//	}
//};
//
//enum CPU_rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
//class CPU
//{
//private:
//	CPU_rank Rank;
//	int frequency;
//	double voltage;
//public:
//	CPU(CPU_rank rank_=P1 ,int f=2,double v=100)
//	{
//		cout << "create a CPU!" << endl;
//		Rank = rank_;
//		frequency = f;
//		voltage = v;
//	}
//	CPU(const CPU & cpu)
//	{
//		cout << "copy create a CPU!" << endl;
//		Rank = cpu.Rank;
//		frequency = cpu.frequency;
//		voltage = cpu.voltage;
//	}
//	~CPU()
//	{
//		cout << "destruct a CPU!" << endl;
//	}
//	void showinfo()
//	{
//		cout << "rank:" << Rank << endl;
//		cout << "frequency:" << frequency << endl;
//		cout << "voltage:" << voltage << endl;
//
//	}
//};
//
////
//////int main()
//////{
//////	Box box2;
//////	box2.get_value();
//////	box2.display();
//////	return 0;
//////}
/////* 请在这里填写答案 */
//////int main()
//////{
//////	Student stud1(10010, "Wang_li", 'f');
//////	stud1.display();
//////	Student stud2(10011, "Zhang_fun", 'm');
//////	stud2.display();
//////	return 0;
//////}
////
//int main()
//{
//	CPU a(P6, 3, 300);
//
//	cout << "cpu a's parameter" << endl;
//	a.showinfo(); //显示性能参数
//
//	CPU b;
//	cout << "cpu b's parameter" << endl;
//	b.showinfo(); //显示性能参数
//
//	CPU c(a);
//	cout << "cpu c's parameter" << endl;
//	c.showinfo(); //显示性能参数
//}

//#include<iostream>
//#include<string>
//using namespace std;

//class A {
//private:
//	int a=0;
//	//const int b;
//public:
//	A(){ cout << "A::default constructer!\n"; };
//	A(int _a):a(_a) { cout << "A::constructer!\n"; };
//
//	void f1() { cout << "A::f1()"; };
//	static void f2() {
//		cout << "A::f2()"; };
//	~A() { cout << "A::default deconstructer!\n"; };
//
//};
//
//class B:public A
//{
//public:
//
//	int b=0;
//	A aa=10;
//public:
//	B()  { cout << "B::default constructer!\n"; };
//	~B() { cout << "B::default deconstructer!\n"; };
//
//};
//
////int x=0;
////
////int&  h()
////{
////	return  x;
////}
//
//void main()
//{
//	//A* a = new A[2];
//	//delete[] a;
//
//	//h() = 100;
//	//cout << x << endl;
//
//	//cout << sizeof(B) << endl;
//	//cout << sizeof(A) << endl;
//	//A a(10);
//	B b;
//
//}

//class A {
//public:
// void foo() {
//		cout << "A" << endl;
//	}
//};
//class B :public A{
//public:
// void foo() {
//		cout << "B" << endl;
//	}
//};
//int main()
//{
//	A* a ;
//	B b;
//	a = &b;
//	a->foo(); //结果为B
//	return 0;
//}

//class Shape {
//protected:
//	int width, height;
//public:
//	Shape(int a = 0, int b = 0)
//	{
//		width = a;
//		height = b;
//	}
//	int area()
//	{
//		cout << "Parent class area :" << endl;
//		return 0;
//	}
//	virtual ~Shape() { cout << "shape::decontor!\n"; };
//};
//class Rectangle : public Shape {
//public:
//	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
//	virtual int area()
//	{
//		cout << "Rectangle class area :" << endl;
//		return (width * height);
//	}
//	 ~Rectangle() { cout << "Rec::decontor!\n"; };
//};
//class Triangle : public Shape {
//public:
//	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
//	virtual int area()
//	{
//		cout << "Triangle class area :" << endl;
//		return (width * height / 2);
//	}
//	 ~Triangle() { cout << "Tri::decontor!\n"; };
//};
//
//void foo(int a, int b)
//{
//	cout << 1 << endl;
//}
//
//void foo(double a, double b)
//{
//	cout << 2 << endl;
//}
//
//int main()
//{
//	Shape* shape=new Rectangle(10, 7);
//	shape->area();
//	delete shape;
//
//	foo(1, 2.0);
//	return 0;
//}

//#include <iostream>
//#include <exception>
//using namespace std;
//
//struct MyException : public exception
//{
//    const char* what() const throw ()
//    {
//        return "C++ Exception";
//    }
//};
//
//class ex :public exception
//{
//
//};
//
//int main()
//{
//    try
//    {
//        throw MyException();
//    }
//
//    catch (ex& e)
//    {
//        //其他的错误
//        cout << 1 << endl;
//    }
//
//    catch (...)//可以捕捉所有类型的异常情况
//    {
//        std::cout << "MyException caught" << std::endl;
//        //std::cout << e.what() << std::endl;
//    }
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class A
{
private:
	int i;
public:
	//A() { cout << "ctor!\n"; };
	A() :i(0) {};
	void set(int i) { this->i = i; };
	int get() { return i; };
	~A() { cout << get(); };
};

class C
{
private:
	int i;
	int* arr;
public:
	friend ostream& operator<<( ostream& out, const C& c);
	friend istream& operator>>( istream& in ,  C& c);

	C&/*要改变自己*/ operator=(const C& that)
	{
		if (this == &that)
			return *this;
		this->i = that.i;
		return *this;
	}

	C &/*要改变自己*/ operator++()//重载++i
	{
		this->i++;
		return *this;/*返回自己*/
	}

	C operator++(int)//重载i++
	{
		C old(*this);
		++(*this);/*改变了自己*/
		return old;/*返回老的*/
	}

	int& operator[](int i)/*要改变自己所以返回引用*/
	{
		return arr[i];
	}

};
ostream& operator<<(ostream& out, const C& c)
{
	cout << c.i << endl;//输出
	return out;
}
istream& operator>>(istream& in, C& c)
{
	cin >> c.i;//输入
	return in;
}


template<class T,int len>
class D
{
public:
	static vector<T*>/*类型*/ arr[len];
	void print();
};

template<class T, int len>
vector<T*>/*类型*/ D<T, len>::/*作用域*/ arr[len];

template<class T, int len>
void D<T, len>::/*函数也要加上作用域*/print()
{
	cout << "zmqsb" << endl;
}


void main()
{
	vector v;
	v[0] = 2.5;
}






//void main()
//{
//	//A* p = new A[2];
//	//delete[] p;
//
//	//C c;
//	//c++;
//
//	D<int, 100> d;
//	
//	d.print();
//
//}