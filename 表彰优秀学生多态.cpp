#include<iostream>
#include <string>
using namespace std;


/* 请在这里填写答案 */
class Student
{
public:
   string ID;
   string name;
   int s1;
   int s2;
public:
   static double Rewardline;//静态变量，只初始化一次，所有的类都可以访问
   virtual void display() {}
   Student(string _ID, string _name, int _s1, int _s2)
   {
       ID = _ID;
       name = _name;
       s1 = _s1;
       s2 = _s2;
   }
};
double Student::Rewardline = 0;//初始化静态变量

/*普通生*/
class GroupA :public Student
{
public:
   virtual void display() 
   {
       if ((s1 + s2) >= Rewardline)
       {
           cout << ID + " " + name << endl;
       }
   };
   GroupA(string _ID, string _name, int _s1, int _s2) :Student(_ID, _name, _s1, _s2) 
   {
       if ((s1 + s2) > Rewardline)//奖励线
           Rewardline = s1 + s2;//更新
   }
};

/*运动特长生*/
class GroupB :public Student
{
private:
   char s3;
public:
   GroupB(string _ID, string _name, int _s1, int _s2, char _s3) :Student(_ID, _name, _s1, _s2) 
   {
       s3 = _s3; 
       if ((s1 + s2) > Rewardline)//奖励线
           Rewardline = s1 + s2;//更新
   }
   virtual void display() 
   {
       if (((s1 + s2) >= 0.7 * Rewardline && s3 == 'A')||(s1+s2)>=Rewardline)
       {
           cout << ID + " " + name << endl;
       }
   };
};
/*学科特长生*/
class GroupC :public Student
{
private:
   int s3;
   int s4;
   int s5;
public:
   GroupC(string _ID, string _name, int _s1, int _s2, int _s3, int _s4, int _s5) :Student(_ID, _name, _s1, _s2) 
   { s3 = _s3; s4 = _s4; s5 = _s5;}
   virtual void display() 
   {
       if (((s1 + s2 + s3 + s4 + s5) / 5 )>= (Rewardline /2 * 0.9))
       {
           cout << ID + " " + name << endl;
       }
   };

};



int main()
{
   const int Size = 50;
   string num, name;
   int i, ty, s1, s2, s3, s4, s5;
   char gs;
   Student* pS[Size];
   int count = 0;
   for (i = 0; i < Size; i++) {
       cin >> ty;
       if (ty == 0) break;
       cin >> num >> name >> s1 >> s2;
       switch (ty) {
       case 1:pS[count++] = new GroupA(num, name, s1, s2); break;
       case 2:cin >> gs; pS[count++] = new GroupB(num, name, s1, s2, gs); break;
       case 3:cin >> s3 >> s4 >> s5; pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5); break;
       }
   }
   for (i = 0; i < count; i++) {
       pS[i]->display();
       delete pS[i];
   }
   return 0;
}

