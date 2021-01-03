#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int M = 100;
static int M2 = 0;

class Score
{
private:
		int score1;
		int score2;
        double sumsc;
		int a, b;
public: 
	Score()
	{
		score1 = 0;
		score2 = 0;
		sumsc = 0;
		a = 0, b = 0;
	}
	void set1(int x,int y)
	{ 
		a = x;
		b = y;
		cout << "请输入平时分数:" << endl;
		cin >> score1;
		cout << "请输入期末分数:" << endl;
		cin >> score2;
	}
	void add()
	{
		cin >> a;
		cout << "dd" << endl;
		cin >> b;
	}
	void show1()
	{
		sumsc = (score1 * a + score2 * b)*0.01; 
		cout << "平时分数:" << score1 <<endl;
		cout << "期末分数:" << score2 << endl;
		cout << "总分: " << sumsc << endl;
	}
};
class Subject
{
private:
	Score sc;
	char subject[20];
public:
	Subject()
	{
		for (int i = 0; i < 20; i++)
			subject[i] = 0;
	}
	void set2()
	{
		cout << "请输入科目名称:" << endl;
		cin >> subject;
	}
	void show2()
	{
		cout << subject;
	}
};
class Student
{
private:
	Score p1;
	char name[20];
	int num;
	int n;
public:
	Student()
	{

		for (int i = 0; i < 20; i++)
			name[i] = 0;
		num = 0;
	}
	void set3(int x,int y);
	void show3();
	int getNU1() { return num; }
	char* getNA1() { return name; }
};
void Student::set3(int x,int y) {            //学生类修改函数
	cout << "请输入学生姓名:";
	cin >> name;
	cout << "请输入该生学号:";
	cin >> num;
	cout << "请输入平时分数与考试分数." << endl;
	p1.set1(x,y);
}
void Student::show3() {            //学生类显示函数
	cout << "姓名:" << name <<  "\t学号:" << num << endl;
	p1.show1();
}
class Class {                    //班级类
private:
	Student stu;
	char name2[20];

public:
	Class() {
		for (int i = 0; i < 20; i++)
			name2[i] = 0;
		
	}
	int getNU() { return stu.getNU1(); }
	string getNA() { return stu.getNA1(); }
	void set4(int x,int y) {
		cout << "请输入该生所在班级名称:";
		cin >> name2;
		stu.set3(x,y);
	}
	void show4() {
		cout << "班级:" << name2;
		stu.show3();
	}
	friend void Search1(Class c1[], int count1);
	friend void Search2(Class c2[], int count2);
	friend void Update1(Class c3[], int count_d);
	friend void Delete(Class c4[], int* count_c);
	friend void Insert(Class c5[], int& count_a,int x,int y);
}b[100];

void Show(Class c7[])                 //显示记录函数
{
	int i = 0;
	for (i = 0; c7[i].getNU() != 0; i++)
		c7[i].show4();
}



void Insert(Class c5[], int& count_a,int x,int y)   //信息录入函数
{
	
	int i, in_number, n = 0;
	if (count_a == M)
	{
		cout << "空间已满!";
		return;
	}
	cout << "请输入学生的学号,检测是否已有数据：" << endl;
	do
	{
		do
		{
			cin >> in_number;
			for (i = 0; i < count_a; i++)
			{
				if (c5[i].getNU() == in_number)
					cout << "已有相同的学号,请重新输入!" << endl;
				break;
			}
		} while (c5[i].getNU() == in_number);
		if (in_number < 1)
			cout << "输入错误，请重新输入大于零的整数!" << endl;
	} while (in_number <= 0);
	i = count_a;
	c5[i].set4(x,y);
	count_a++;
	cout << endl << endl; n = n + 1;
	if (n != 0)
		cout << "学生成绩录入成功!" << endl;
}





void Search1(Class c1[], int count1)    //按学号查询信息函数
{
	int i, number, flag = 1, n = 0;
	cout << "请输入所要查询的学生的学号:" << endl;
	do
	{
		cin >> number;
		if (number <= 0)
			cout << "输入错误，请重新输入大于零的整数!" << endl;
	} while (number <= 0);
	for (i = 0; i < count1 && flag; i++)
		if (c1[i].getNU() == number)
		{
			c1[i].show4();
			flag = 0; n = n + 1;
		}
	if (n == 0)
		cout << "没有查询到该学生的资料!" << endl;
}


void Search2(Class c2[], int count2)  //按姓名查询信息函数
{
	int i, n = 0;
	char nam[20];
	cout << "请输入所要查询的学生的姓名:" << endl;
	cin >> nam;
	for (i = 0; i < count2; i++)
		if (c2[i].getNA() == nam)
		{
			c2[i].show4();
			n = n + 1;
		}
	if (n == 0)
		cout << "没有查询到该学生的资料!" << endl;
}

int main()
{ 
	int x, y;
	char a1;
	cout << "\t\t**************欢迎进入学生成绩管理系统**************" << endl << endl;
	cout << "请输入平时分数占比(例如：30%请输入30)" << endl;
	cin >> x;
	cout << "请输入期末分数占比(例如：70%请输入70)" << endl;
	cin >> y;
	do
	{
		cout << "请选择功能：" << endl;
		cout << "\t\t\ta.学生成绩查询" << endl;
		cout << "\t\t\tb.学生成绩录入" << endl;
		cout << "\t\t\tc.显示全部记录" << endl;
		cout << "\t\t\te.退出系统" << endl;
		int i = 0;
		
		for (i = 0; b[i].getNU() != 0; i++)
			;
		M2 = i;
		cin >> a1;
		switch (a1)
		{
		case 'a':
		{
			cout << "\t\t\t请继续选择:" << endl;
			cout << "\t\t\t\t1.按学号查询信息" << endl;
			cout << "\t\t\t\t2.按姓名查询信息" << endl;
			int x;
			cin >> x;
			switch (x)
			{
			case 1:Search1(b, M2); break;
			case 2:Search2(b, M2); break;
			default:cout << "选择错误，请重新选择!" << endl;
			}
		}
		break;
		case 'b':Insert(b, M2,x,y); break;
		case 'c':Show(b); break;
		default:cout << "选择错误，请重新选择!" << endl;
		}
	} while (a1 != 'e');
	return 0;
}

