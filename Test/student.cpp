#include "stdafx.h"

void student::display(vector<student> & c)
{
	cout << "学号" << setw(20) << "成绩" << endl;

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i].GetNum() << setw(12) << c[i].GetScore() << endl;
	}
}

void::student::set(vector<student> & c) 
{
	student a;
	string s;
	double b;
	while (true)
	{
		cout << "学号：";
		cin >> s;
		if (s == "0") 
		{
			ofstream wst("stud.txt");
			if (!wst) 
			{
				cout << "创建文件失败！" << endl;
				return;
			}

			for (int i = 0; i < c.size(); i++)
			{
				wst << c[i].number << " " << c[i].score << " ";
			}

			wst.close();
			cout << "写入文件" << c.size() << "个学生信息" << endl;
			return;
		}

		a.SetNum(s);
		cout << "成绩：";
		cin >> b;
		a.SetScore(b);
		c.push_back(a);
	}
}

void student::read() 
{
	string number;
	double score;

	ifstream rst("stud.txt");

	if (!rst) 
	{
		cout << "打开文件失败";
		return;
	}

	cout << "学号" << setw(20) << "成绩" << endl;

	while (true)
	{
		rst >> number >> score;
		if (rst.eof()) 
		{
			rst.close();
			return;
		}

		cout << number << setw(12) << score << endl;
	}
}