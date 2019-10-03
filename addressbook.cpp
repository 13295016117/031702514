#include"pch.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Exception//异常类
{
public:
	Exception(const string& msg, int id)
	{
		_msg = msg;
		_id = id;
	}

	const char* What() const
	{
		return _msg.c_str();
	}

protected:
	string _msg;
	int    _id;
};

template<size_t N = 10>
class Array
{
public:
	int& operator[](size_t pos)
	{
		if (pos >= N)
		{
			Exception e("下标不合法", 1); //出了这个作用域，抛出的异常对象就销毁了，这时会生成一个匿名对象先接受这个对象，并传到外层栈帧。
			throw e;
		}
		return a[pos];
	}
protected:
	int a[N];
};

int f()
{
	try
	{
		Array<> a;
		a[11];
	}
	catch (exception& e)
	{
		cout << e.what() << endl; //类型不匹配，找离抛出异常位置最近且类型匹配的那个。
	}

	return 0;
}
void Test1()
{
	try
	{
		char* p = new char[0x7fffffff];  //抛出异常
	}
	catch (exception e)
	{
		cout << e.what() << endl;   //捕获异常，然后程序结束
	}
}
int main(int argc, char **argv)
{
	try
	{
		f();
	}
	catch (Exception& e)
	{
		cout << e.What() << endl;
	}

	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
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