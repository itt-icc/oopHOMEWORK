/*
���ʵ��������������/�����
(1��������뷽ʽ������������Ϊ12��
(2���԰˽��ơ�ʮ���ơ�ʮ����������/���������
(3��ʵ�ָ�������ָ����ʽ�Ͷ����ʽ������/�������ָ�����ȣ�
(4�����ַ��������ַ�����������У��Ӽ������룬Ҫ�����봮�Ŀո�Ҳȫ�����룬�Իس���������
*/

//#include<iostream>
//#include<string>
//using namespace std;
//
////(1)
//void f1()
//{
//	long a = 234;
//	double b = 2345.67890;
//	char c[100];
//	cout.fill('*');   //�����ķ�ʽ
//	cout.flags(ios_base::left);
//	cout.width(12);
//	cout << a << endl;
//}
//
////(2)
//void f2()
//{
//	cout.flags(ios::hex);// ���û������ķ�ʽ��
//	cout << 234 << '\t';
//	cout.flags(ios::dec);
//	cout << 234 << '\t';
//	cout.flags(ios::oct);
//	cout << 234 << endl;
//}
//
////(3)
//void f3()
//{
//	double b = 16541356.65135165;
//	cout.flags(ios::scientific);
//	cout << b << '\t';
//	cout.flags(ios::fixed);
//	cout << b << endl;
//}
//
//void f4()
//{
//	char c[100];
//	cin.get(c,100);
//	cout << c << endl;
//}
//
//int main()
//{
//
//	f1();
//	f2();
//	f3();
//	f4();
//	return 0;
//}






//#include<iostream>
//#include <fstream>
//
//using namespace std;
//
//class dog
//{
//public:
//	dog(int weight, long days) :itsWeight(weight),
//		itsNumberDaysAlive(days) {}
//	~dog() {}
//
//	int GetWeight()const { return itsWeight; }
//	void SetWeight(int weight) { itsWeight = weight; }
//
//	long GetDaysAlive()const { return itsNumberDaysAlive; }
//	void SetDaysAlive(long days) { itsNumberDaysAlive = days; }
//
//private:
//	int itsWeight;
//	long itsNumberDaysAlive;
//};
//
//int main() // returns 1 on error
//{
//	char fileName[80];
//
//	cout << "Please enter the file name: ";
//	cin >> fileName;
//	ofstream fout(fileName);
//	// ofstream fout(fileName,ios::binary);
//	if (!fout)
//	{
//		cout << "Unable to open " << fileName << " for writing./n";
//		return(1);
//	}
//
//	dog Dog1(5, 10);
//	fout.write((char*)&Dog1, sizeof Dog1);
//
//	fout.close();
//
//	ifstream fin(fileName);
//	// ifstream fin(fileName,ios::binary);
//	if (!fin)
//	{
//		cout << "Unable to open " << fileName << " for reading./n";
//		return(1);
//	}
//
//	dog Dog2(2, 2);
//
//	cout << "Dog2 weight: " << Dog2.GetWeight() << endl;
//	cout << "Dog2 days: " << Dog2.GetDaysAlive() << endl;
//
//	fin.read((char*)&Dog2, sizeof Dog2);
//
//	cout << "Dog2 weight: " << Dog2.GetWeight() << endl;
//	cout << "Dog2 days: " << Dog2.GetDaysAlive() << endl;
//	fin.close();
//	return 0;
//}

//#include<fstream>
//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//using namespace std;
//struct student
//{
//	int num;
//	char name[20];
//	float score;
//};
//int main()
//{
//	student stud[5] =
//	{ 1001,"Li",85,
//	 1002,"Fun",97.5,
//	 1003,"Wang",98,
//	 1004,"Tan",76.5,
//	 1005,"Ling",96 };
//	fstream iofile("mystd.dat", ios::in | ios::out | ios::binary);
//	//��fstream�ඨ����������������ļ�������iofile
//	if (!iofile)
//	{
//		cerr << "open error!" << endl;
//		abort();
//	}
//	for (int i = 0; i < 5; i++)	//�����������5��ѧ�������� 
//	{
//		iofile.write((char*)&stud[i], sizeof(stud[i]));
//	}
//	student stud1[5];		//������ŴӴ����ļ����������
//	for (int i = 0; i < 5; i += 2)
//	{
//		iofile.seekg(i * sizeof(stud[i]), ios::beg);//��λ�ڵ�0��2��4ѧ�����ݿ�ͷ
//		iofile.read((char*)&stud1[i], sizeof(stud1[0]));
//		//�Ⱥ����3��ѧ�������ݣ������stud1[0], stud1[1],stud1[2]��
//		cout << stud1[i].num << " " << stud1[i].name << " " << stud1[i].score << endl;
//		//��� stud1[0], stud1[1],stud1[2]����Ա��ֵ 
//	}
//	cout << endl;
//	//�޸ĵ�3��ѧ������0��ʼ�������� 
//	stud[2].num = 1012;
//	strcpy_s(stud[2].name, "niubi");
//	stud[2].score = 100;
//	iofile.seekp(2 * sizeof(stud[0]), ios::beg);		//��λ�����������ݵĿ�ͷ 
//	iofile.write((char*)&stud[2], sizeof(stud[2])); //���µ�����ѧ��������
//	iofile.seekg(0, ios::beg);			//���¶�λ���ļ���ͷ
//	for (int i = 0; i < 5; i++)
//	{
//		iofile.read((char*)&stud[i], sizeof(stud[i]));//����5��ѧ��������
//		cout << stud[i].num << " " << stud[i].name << " " << stud[i].score << endl;
//	}
//	iofile.close();
//	return 0;
//}