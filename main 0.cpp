#include<iostream>

using namespace std;

struct SalesRec {
	char pID[10]; // 10 bite
	int dYear, dMonth, dData; // 3*4 bite
	char deliverAddr[40];// 40 bite

};
struct TimeRec {
	int hours;
	int minutes;
	int seconds;
};



double GetArraySum(double arr[], int n);
void printsum(double sum);
double variance(double arr[], int n);
void SwapValues(int x, int y);
void PrSalesRec(SalesRec Srec);


void AddTime(TimeRec& t1, const TimeRec& t2);
void AddTime(TimeRec& t1, int minutes); //�⺻���� ���������� ���� ��������


int main()
{
	/*
	double a[50], b[100];
	double sum = 0;

	sum = GetArraySum(a, 50);

	printsum(sum);

	sum = GetArraySum(b, 100);

	printsum(sum);
	*/
	/*
	int a, b = { 0 };
	cout << "�ΰ��� ���� �Է��ϼ��� :";
	cin >> a >> b;
	SwapValues(a, b);
	cout << "a =" << a << "b =" << b << endl;

	SalesRec stRec;
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 6;
	stRec.dData = 6;
	strcpy_s(stRec.deliverAddr, "��⵵ �����");
	PrSalesRec(stRec);
	*/

	/*
	1. void func(inta,int b);
	// int func(inta,int b);
	2. void func(inta,int b,int c = 100);

	func(a,b);// 1���� 2���� ��� �����ؾ� ���� ��ȣ�Ͽ� �����߻�

	a. void func(int a);
	b. void func (float a );

	func(10);
	func(10.0f);
	func(10.0);// doouble���� ��� a�� ȣ���ؾ��ϴ��� b�� ȣ���ؾ� �ϴ��� ��ȣ�Ͽ� �����߻� 


	*/


	TimeRec time1 = { 2, 20 };
	TimeRec time2 = { 1, 55 };
	int minutes = 210;

	cout << time1.hours << "�ð�" << time1.minutes << "�� +" << time1.seconds << "�� +";
	cout << time2.hours << "�ð�" << time2.minutes << "�� +" << time2.seconds << "�� =";
	AddTime(time1, time2);
	cout << time1.hours << "�ð�" << time1.minutes << "��" << time1.seconds << "�� " << endl;

	cout << time1.hours << "�ð�" << time1.minutes << "�� +" << time1.seconds << "�� +";
	cout << time2.hours << "�ð�" << time2.minutes << "�� +" << time2.seconds << "�� =";
	AddTime(time1, time2 );
	cout << time1.hours << "�ð�" << time1.minutes << "��" << time2.seconds << "�� " << endl;


		
}


//�迭�� �� �迭 ��ȣ�� ���� �־��ְ� ���� ���Ѱ��� ��ȯ
double GetArraySum(double arr[], int n) // double arr[], int n <-- �Ű�����
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		sum += arr[i];
	}

	return sum;
}

void printsum(double sum)
{
	cout << "sum = " << sum << endl;
}

//�л� ���ϱ�
double variance(double arr[], int n)
{
	double sum = 0, sqSum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		sqSum += arr[i] * arr[i];
	}
	double result = sqSum / n - sum / (n * n);
	return result;
}

//�ΰ��� ���� ���� �ٲٱ�
void SwapValues(int x, int y) // int x ,int y �� �ؿ� ���� �����ؼ� �ְԵǰ� int& x, int& y (&)�������� ���� ��ɾ�
							  // const �� ���� �����ϴ� ��ɾ�
{
	int temp = x;
	x = y;
	y = temp;
}


void PrSalesRec(SalesRec Srec)
{
	cout << "ǰ���ڵ�" << Srec.pID << endl;
	cout << "�������" << Srec.dYear << "��" << endl;
	cout << Srec.dMonth << "��" << Srec.dData << "��" << endl;
	cout << "����ּ�" << Srec.deliverAddr << endl;
}
//�ð� t1�� t2�� ���Ѵ�
void AddTime(TimeRec& t1, const TimeRec& t2)
{
	t1.seconds += t2.seconds;
	t1.minutes += t2.minutes + (t1.seconds / 60);
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.seconds %= 60;
	t1.minutes %= 60;
     
}
//�ð� t1�� minutes ���� ���Ѵ�
void AddTime(TimeRec& t1, int minutes)
{
	t1.minutes += minutes;
	t1.hours += (t1.minutes / 60);
	t1.minutes %= 60;
}