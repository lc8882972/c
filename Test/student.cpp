#include "stdafx.h"

void student::display(vector<student> & c)
{
	cout << "ѧ��" << setw(20) << "�ɼ�" << endl;

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
		cout << "ѧ�ţ�";
		cin >> s;
		if (s == "0") 
		{
			ofstream wst("stud.txt");
			if (!wst) 
			{
				cout << "�����ļ�ʧ�ܣ�" << endl;
				return;
			}

			for (int i = 0; i < c.size(); i++)
			{
				wst << c[i].number << " " << c[i].score << " ";
			}

			wst.close();
			cout << "д���ļ�" << c.size() << "��ѧ����Ϣ" << endl;
			return;
		}

		a.SetNum(s);
		cout << "�ɼ���";
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
		cout << "���ļ�ʧ��";
		return;
	}

	cout << "ѧ��" << setw(20) << "�ɼ�" << endl;

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