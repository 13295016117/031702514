#include"pch.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile("D:\\zuoye\\1\\address.txt");
	if (!infile.is_open())
	{
		cout << "无法读取文件";
	}
	string s; int i; int j = 0; int k;
	while (infile >> s)
	{
		cout << "{" << endl;
		cout << "   {" << endl;
		cout << "      \"" << "姓名\"" << ": " << "\"";
		for (i = 2; s[i] != ','; i = i + 2)
		{
			cout << s.substr(i, 2);
			s[i] = 'a'; s[i + 1] = 'a';
		}
		k = i + 1;
		cout << "\"" << "," << endl;
		cout << "      \"" << "手机\"" << ": " << "\"";
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
					cout << s[j];
					s[j] = 'a';
				}
				break;
			}
		}
		cout << "\"" << "," << endl;
		cout << "      \"" << "地址\"" << ": [" << endl;
		cout << "          \"";
		for (i = 0, j = 0; s[i] != '\0'; i++)
		{
			if (s[i] == 'a')
			{
				continue;
			}
			s[j] = s[i];
			j += 1;
		}
		for (i = 3;i<j ; i= i=i+2 )
		{
			if (s[i] == '.'||s[i-1]=='.')
			{
				break;
			}
			cout << s.substr(i, 2);
			if (s.substr(i, 2) == "省")
			{
				cout << "\"," << endl;
				cout << "          \"";
			}
			if (s.substr(i, 2) == "区")
			{
				cout << "\"," << endl;
				cout << "          \"";
			}
			if (s.substr(i, 2) == "市")
			{
				cout << "\"," << endl;
				cout << "          \"";
			}
			if (s.substr(i, 2) == "县")
			{
				cout << "\"," << endl;
				cout << "          \"";
			}
			if (s.substr(i, 2) == "镇")
			{
				cout << "\"," << endl;
				cout << "          \"";
			}
		}
		cout << "\"" << endl;
		cout << "           ]" << endl;
		cout << "   }" << endl;
		cout << "}" << endl;
	}
	return 0;
}