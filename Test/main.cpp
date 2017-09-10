// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include <iostream> 
#include <algorithm>
#include <functional>
#include <fstream>
#include "student.h" 
using namespace std;

//一、一维数组
//静态 int array[100]; 　　定义了数组array，并未对数组进行初始化
//静态 int array[100] = { 1，2 }；　　定义并初始化了数组array
//动态 int* array = new int[100];  delete[]array;　　分配了长度为100的数组array 
//动态 int* array = new int[100](1，2); 　delete[]array;　为长度为100的数组array初始化前两个元素
int main()
{
	string s = "";

	string s1[] = { "1","2" };
	//string* s2 = new string[5];
	cout << "11";
	char a;
	
	cin >> a;
	cout << a;

	int arr[] = { 1,2,3,4,5 };

	reverse(arr, arr + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i];
	}
	cin >> a;

	ofstream of;
	char ch[15], * p = "abcdefg";
	of.open("my.txt");
	of << p;
	of << "Goodbye!";
	of.close();

	ifstream * iftream =new ifstream();
	iftream ->open("my.txt",ios_base::in);
	iftream->close();
	delete iftream;

	vector<int> ivec(10,1);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		*iter = 2; //使用 * 访问迭代器所指向的元素
	}
	return 0;
}

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

struct  list
{
	double salary;
	char name[20];
	friend ostream &operator <<(ostream &os, list&ob);
	friend istream &operator >>(istream &is, list&ob);
};

ostream &operator <<(ostream &os, list&ob) 
{
	os << ob.name << ' ';
	os << ob.salary << ' ';
	return os;
}
 istream &operator >>(istream &is, list&ob) 
{
	 is >> ob.name;
	 is >> ob.salary;
	 return is;
}

