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
		cout << "������ƽʱ����:" << endl;
		cin >> score1;
		cout << "��������ĩ����:" << endl;
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
		cout << "ƽʱ����:" << score1 <<endl;
		cout << "��ĩ����:" << score2 << endl;
		cout << "�ܷ�: " << sumsc << endl;
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
		cout << "�������Ŀ����:" << endl;
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
void Student::set3(int x,int y) {            //ѧ�����޸ĺ���
	cout << "������ѧ������:";
	cin >> name;
	cout << "���������ѧ��:";
	cin >> num;
	cout << "������ƽʱ�����뿼�Է���." << endl;
	p1.set1(x,y);
}
void Student::show3() {            //ѧ������ʾ����
	cout << "����:" << name <<  "\tѧ��:" << num << endl;
	p1.show1();
}
class Class {                    //�༶��
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
		cout << "������������ڰ༶����:";
		cin >> name2;
		stu.set3(x,y);
	}
	void show4() {
		cout << "�༶:" << name2;
		stu.show3();
	}
	friend void Search1(Class c1[], int count1);
	friend void Search2(Class c2[], int count2);
	friend void Update1(Class c3[], int count_d);
	friend void Delete(Class c4[], int* count_c);
	friend void Insert(Class c5[], int& count_a,int x,int y);
}b[100];

void Show(Class c7[])                 //��ʾ��¼����
{
	int i = 0;
	for (i = 0; c7[i].getNU() != 0; i++)
		c7[i].show4();
}



void Insert(Class c5[], int& count_a,int x,int y)   //��Ϣ¼�뺯��
{
	
	int i, in_number, n = 0;
	if (count_a == M)
	{
		cout << "�ռ�����!";
		return;
	}
	cout << "������ѧ����ѧ��,����Ƿ��������ݣ�" << endl;
	do
	{
		do
		{
			cin >> in_number;
			for (i = 0; i < count_a; i++)
			{
				if (c5[i].getNU() == in_number)
					cout << "������ͬ��ѧ��,����������!" << endl;
				break;
			}
		} while (c5[i].getNU() == in_number);
		if (in_number < 1)
			cout << "���������������������������!" << endl;
	} while (in_number <= 0);
	i = count_a;
	c5[i].set4(x,y);
	count_a++;
	cout << endl << endl; n = n + 1;
	if (n != 0)
		cout << "ѧ���ɼ�¼��ɹ�!" << endl;
}





void Search1(Class c1[], int count1)    //��ѧ�Ų�ѯ��Ϣ����
{
	int i, number, flag = 1, n = 0;
	cout << "��������Ҫ��ѯ��ѧ����ѧ��:" << endl;
	do
	{
		cin >> number;
		if (number <= 0)
			cout << "���������������������������!" << endl;
	} while (number <= 0);
	for (i = 0; i < count1 && flag; i++)
		if (c1[i].getNU() == number)
		{
			c1[i].show4();
			flag = 0; n = n + 1;
		}
	if (n == 0)
		cout << "û�в�ѯ����ѧ��������!" << endl;
}


void Search2(Class c2[], int count2)  //��������ѯ��Ϣ����
{
	int i, n = 0;
	char nam[20];
	cout << "��������Ҫ��ѯ��ѧ��������:" << endl;
	cin >> nam;
	for (i = 0; i < count2; i++)
		if (c2[i].getNA() == nam)
		{
			c2[i].show4();
			n = n + 1;
		}
	if (n == 0)
		cout << "û�в�ѯ����ѧ��������!" << endl;
}

int main()
{ 
	int x, y;
	char a1;
	cout << "\t\t**************��ӭ����ѧ���ɼ�����ϵͳ**************" << endl << endl;
	cout << "������ƽʱ����ռ��(���磺30%������30)" << endl;
	cin >> x;
	cout << "��������ĩ����ռ��(���磺70%������70)" << endl;
	cin >> y;
	do
	{
		cout << "��ѡ���ܣ�" << endl;
		cout << "\t\t\ta.ѧ���ɼ���ѯ" << endl;
		cout << "\t\t\tb.ѧ���ɼ�¼��" << endl;
		cout << "\t\t\tc.��ʾȫ����¼" << endl;
		cout << "\t\t\te.�˳�ϵͳ" << endl;
		int i = 0;
		
		for (i = 0; b[i].getNU() != 0; i++)
			;
		M2 = i;
		cin >> a1;
		switch (a1)
		{
		case 'a':
		{
			cout << "\t\t\t�����ѡ��:" << endl;
			cout << "\t\t\t\t1.��ѧ�Ų�ѯ��Ϣ" << endl;
			cout << "\t\t\t\t2.��������ѯ��Ϣ" << endl;
			int x;
			cin >> x;
			switch (x)
			{
			case 1:Search1(b, M2); break;
			case 2:Search2(b, M2); break;
			default:cout << "ѡ�����������ѡ��!" << endl;
			}
		}
		break;
		case 'b':Insert(b, M2,x,y); break;
		case 'c':Show(b); break;
		default:cout << "ѡ�����������ѡ��!" << endl;
		}
	} while (a1 != 'e');
	return 0;
}

