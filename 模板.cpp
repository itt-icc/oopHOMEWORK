#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */

template <class T>
void sort(T* a, int size)
{
   for (int i = 0; i < size; i++)
       cin >> a[i];

   /*选择排序*/
   for (int i = 0; i < size-1; ++i)
   {
       int index = i;
       /*找到最小值对应下标*/
       for (int j = i + 1; j < size; j++)
       {
           if (a[index] > a[j])
           {
               index = j;
           }
       }
       T temp = a[index];
       a[index] = a[i];
       a[i] = temp;
   }
}



template <class T>
void display(T* a, int size) {
   for (int i = 0; i < size - 1; i++) cout << a[i] << ' ';
   cout << a[size - 1] << endl;
}
int main() {
   const int SIZE = 10;
   int a[SIZE];
   char b[SIZE];
   double c[SIZE];
   string d[SIZE];
   int ty, size;
   cin >> ty;
   while (ty > 0) {
       cin >> size;
       switch (ty) {
       case 1:sort(a, size); display(a, size); break;
       case 2:sort(b, size); display(b, size); break;
       case 3:sort(c, size); display(c, size); break;
       case 4:sort(d, size); display(d, size); break;
       }
       cin >> ty;
   }
   return 0;
}



/**
Templatize the fibonacci( ) function on the type of value that it produces
(so it can produce long, float, etc. instead of just int).
**/


#include <iostream>
using namespace std;
template <class T>
T fibonacci(T n) {
   const int size = 50;
   static T f[size];
   f[0] = f[1] = 1;

   int i;
   for (i = 0; i < size; i++)
       if (f[i] == 0) break;
   while (i <= n) {
       f[i] = f[i - 1] + f[i - 2];
       i++;
   }
   return f[n];
}


int main()
{
   cout << fibonacci(30) << endl;
   return 0;
}

#include<iostream>
using namespace std;
//类模板
template<class T>
class vector
{
public:
	void sort(T a[], int n)
	{
		T temp;
		bool exchange;
		for (int i = 1; i < n; i++)
		{
			exchange = false;
			for (int j = n - 1; j >= i; j--)
				if (a[j] < a[j - 1])
				{
					temp = a[j]; a[j] = a[j - 1]; a[j - 1] = temp;
					exchange = true;
				}
			if (!exchange)
				return;
		}
	}
	T sum(T a[], int n)
	{
		T sum = a[0];
		for (int i = 1; i < n; i++)
			sum += a[i];
		return sum;
	}
	int search(T e, T a[], int n)
	{
		for (int i = 0; i < n; i++)
			if (a[i] == e)
				return i;
		return -1;
	}
};

void main()
{
	int data[5] = { 5,3,1,2,4 };
	vector<int> obj;
	cout << "数组和为：" << obj.sum(data, 5) << endl;
	cout << "数字4在数组中的位置是：" << obj.search(4, data, 5) << endl;
	cout << "排序前数组各元素为：" << endl;
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
	obj.sort(data,5);
	cout << "排序后数组各元素为：" << endl;
	for (int i = 0; i < 5; i++)
		cout << data[i] << " ";
	cout << endl;
}
