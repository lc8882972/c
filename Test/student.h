#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
class student
{
	private:
		string number;
		double score;

	public:
		void SetNum(string s) { number = s; }
		void SetScore(double d) { score = d; }
		string GetNum() { return number; }
		double GetScore() { return score; }
		void set(vector<student> &);
		void display(vector<student> &);
		void read(vector<student> &);
};


