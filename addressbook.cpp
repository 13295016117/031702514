#include"pch.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char **argv)
{
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	if (!infile.is_open())
	{
		outfile << "无法读取文件";
	}
	string s; int i; int j = 0; int k; string re; string l; string y; string x; string d;
	while (infile >> s)
	{

		re = { "{{[''姓名'':''" };
		for (i = 2; s[i] != ','; i = i + 2)
		{
			re += s.substr(i, 2);
			s[i] = 'a'; s[i + 1] = 'a';
		}
		k = i + 1;
		y = { "'',''手机''：" };
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
		for (i = 3; i < j; i = i = i + 2)
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
			if (s.substr(i, 2) == "区")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "市")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "县")
			{
				l = { "'',''" };
				re += l;
			}
			if (s.substr(i, 2) == "镇")
			{
				l = { "'',''" };
				re += l;
			}
		}
		d = { "'']}}" };
		re += d;
		cout << re<<endl;
		outfile << re;
	}
	outfile.close();
	return 0;
}
