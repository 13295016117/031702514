#include"pch.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile("input.txt"); 
	ofstream outfile("031702514.txt");
	if (!infile.is_open())
	{
		outfile << "无法读取文件";
	}
	string s; int i; int j = 0; int k; string re; string l; string y; string x; string d; string f;
	while (infile >> s)
	{

		re = { "{{[''姓名'':''" };
		for (i = 2; s[i] != ','; i = i + 2)
		{
			re += s.substr(i, 2);
			s[i] = 'a'; s[i + 1] = 'a';
		}
		k = i + 1;
		y = { "'',''手机''：''" };
		re += y;
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] >= 48 && s[i] <= 57)
			{
				j = j + 1;
			}
			else
			{
				j = 0;
			}
			if (j == 11)
			{
				for (j = i - 10; j <= i; j++)
				{
					re += s[j];
					s[j] = 'a';
				}
				break;
			}
		}
		x = { "'',''地址'':[''" };
		re += x;
		for (i = 0, j = 0; s[i] != '\0'; i++)
		{
			if (s[i] == 'a')
			{
				continue;
			}
			s[j] = s[i];
			j += 1;
		}
		for (i = 3; i < j; i = i + 2)
		{
			if (s[i] == '.' || s[i - 1] == '.')
			{
				break;
			}
			re += s.substr(i, 2);
			if (s.substr(i, 2) == "省")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "区"&&s.substr(i - 2, 2) == "政")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "北"&&s.substr(i + 2, 2) == "京")
			{
				f = { "京'',''" };
				i += 2;
				re += f;
			}
			if (s.substr(i, 2) == "重"&&s.substr(i + 2, 2) == "庆")
			{
				f = { "庆'',''" };
				i += 2;
				re += f;
			}
			if (s.substr(i, 2) == "上"&&s.substr(i + 2, 2) == "海")
			{
				f = { "海'',''" };
				i += 2;
				re += f;
			}
			if (s.substr(i, 2) == "天"&&s.substr(i + 2, 2) == "津")
			{
				f = { "津'',''" };
				i += 2;
				re += f;
			}
			if (s.substr(i, 2) == "市"&&s.substr(i+2, 2)!="区")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "县"||s.substr(i, 2) == "区")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "镇"||s.substr(i, 2) == "乡"||s.substr(i, 2) == "道")
			{
				l = { "'',''" };
				re += l;
			}
		}
		if (re[re.size() - 1] == '.')
		{
			re = re.substr(0, re.length()-1);
		}
		d = { "'']}}" };
		re += d;
		cout << re << endl;
		outfile << re;

	}
	outfile.close();
	return 0;
}