/*
编程实现以下数据输入/输出。
(1）以左对齐方式输出整数，域宽为12；
(2）以八进制、十进制、十六进制输入/输出整数；
(3）实现浮点数的指数格式和定点格式的输入/输出，并指定精度；
(4）把字符串读入字符型数组变量中，从键盘输入，要求输入串的空格也全部读入，以回车符结束。
*/

#include<iostream>
#include<string>
using namespace std;

//(1)
void f1()
{
	long a = 234;
	double b = 2345.67890;
	char c[100];
	cout.fill('*');   //左对齐的方式
	cout.flags(ios_base::left);
	cout.width(12);
	cout << a << endl;
}

//(2)
void f2()
{
	cout.flags(ios::hex);// 设置缓冲区的方式。
	cout << 234 << '\t';
	cout.flags(ios::dec);
	cout << 234 << '\t';
	cout.flags(ios::oct);
	cout << 234 << endl;
}

//(3)
void f3()
{
	double b = 16541356.65135165;
	cout.flags(ios::scientific);
	cout << b << '\t';
	cout.flags(ios::fixed);
	cout << b << endl;
}

void f4()
{
	char c[100];
	cin.get(c,100);
	cout << c << endl;
}

int main()
{

	f1();
	f2();
	f3();
	f4();
	return 0;
}






#include<iostream>
#include <fstream>

using namespace std;

class dog
{
public:
	dog(int weight, long days) :itsWeight(weight),
		itsNumberDaysAlive(days) {}
	~dog() {}

	int GetWeight()const { return itsWeight; }
	void SetWeight(int weight) { itsWeight = weight; }

	long GetDaysAlive()const { return itsNumberDaysAlive; }
	void SetDaysAlive(long days) { itsNumberDaysAlive = days; }

private:
	int itsWeight;
	long itsNumberDaysAlive;
};

int main() // returns 1 on error
{
	char fileName[80];

	cout << "Please enter the file name: ";
	cin >> fileName;
	ofstream fout(fileName);
	// ofstream fout(fileName,ios::binary);
	if (!fout)
	{
		cout << "Unable to open " << fileName << " for writing./n";
		return(1);
	}

	dog Dog1(5, 10);
	fout.write((char*)&Dog1, sizeof Dog1);

	fout.close();

	ifstream fin(fileName);
	// ifstream fin(fileName,ios::binary);
	if (!fin)
	{
		cout << "Unable to open " << fileName << " for reading./n";
		return(1);
	}

	dog Dog2(2, 2);

	cout << "Dog2 weight: " << Dog2.GetWeight() << endl;
	cout << "Dog2 days: " << Dog2.GetDaysAlive() << endl;

	fin.read((char*)&Dog2, sizeof Dog2);

	cout << "Dog2 weight: " << Dog2.GetWeight() << endl;
	cout << "Dog2 days: " << Dog2.GetDaysAlive() << endl;
	fin.close();
	return 0;
}

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct student
{
	int num;
	char name[20];
	float score;
};
int main()
{
	student stud[5] =
	{ 1001,"Li",85,
	 1002,"Fun",97.5,
	 1003,"Wang",98,
	 1004,"Tan",76.5,
	 1005,"Ling",96 };
	fstream iofile("mystd.dat", ios::in | ios::out | ios::binary);
	//用fstream类定义输入输出二进制文件流对象iofile
	if (!iofile)
	{
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < 5; i++)	//像磁盘中输入5个学生的数据 
	{
		iofile.write((char*)&stud[i], sizeof(stud[i]));
	}
	student stud1[5];		//用来存放从磁盘文件读入的数据
	for (int i = 0; i < 5; i += 2)
	{
		iofile.seekg(i * sizeof(stud[i]), ios::beg);//定位于第0，2，4学生数据开头
		iofile.read((char*)&stud1[i], sizeof(stud1[0]));
		//先后读入3个学生的数据，存放在stud1[0], stud1[1],stud1[2]中
		cout << stud1[i].num << " " << stud1[i].name << " " << stud1[i].score << endl;
		//输出 stud1[0], stud1[1],stud1[2]各成员的值 
	}
	cout << endl;
	//修改第3个学生（从0开始）的数据 
	stud[2].num = 1012;
	strcpy_s(stud[2].name, "niubi");
	stud[2].score = 100;
	iofile.seekp(2 * sizeof(stud[0]), ios::beg);		//定位到第三个数据的开头 
	iofile.write((char*)&stud[2], sizeof(stud[2])); //更新第三个学生的数据
	iofile.seekg(0, ios::beg);			//从新定位于文件开头
	for (int i = 0; i < 5; i++)
	{
		iofile.read((char*)&stud[i], sizeof(stud[i]));//读入5个学生的数据
		cout << stud[i].num << " " << stud[i].name << " " << stud[i].score << endl;
	}
	iofile.close();
	return 0;
}
