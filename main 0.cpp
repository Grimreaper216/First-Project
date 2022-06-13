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
void AddTime(TimeRec& t1, int minutes); //기본값은 마지막것을 빼면 오류터짐


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
	cout << "두개의 수를 입력하세요 :";
	cin >> a >> b;
	SwapValues(a, b);
	cout << "a =" << a << "b =" << b << endl;

	SalesRec stRec;
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 6;
	stRec.dData = 6;
	strcpy_s(stRec.deliverAddr, "경기도 광명시");
	PrSalesRec(stRec);
	*/

	/*
	1. void func(inta,int b);
	// int func(inta,int b);
	2. void func(inta,int b,int c = 100);

	func(a,b);// 1번과 2번중 어디를 선택해야 할지 모호하여 에러발생

	a. void func(int a);
	b. void func (float a );

	func(10);
	func(10.0f);
	func(10.0);// doouble형이 없어서 a를 호출해야하는지 b를 호출해야 하는지 모호하여 에러발생 


	*/


	TimeRec time1 = { 2, 20 };
	TimeRec time2 = { 1, 55 };
	int minutes = 210;

	cout << time1.hours << "시간" << time1.minutes << "분 +" << time1.seconds << "초 +";
	cout << time2.hours << "시간" << time2.minutes << "분 +" << time2.seconds << "초 =";
	AddTime(time1, time2);
	cout << time1.hours << "시간" << time1.minutes << "분" << time1.seconds << "초 " << endl;

	cout << time1.hours << "시간" << time1.minutes << "분 +" << time1.seconds << "초 +";
	cout << time2.hours << "시간" << time2.minutes << "분 +" << time2.seconds << "초 =";
	AddTime(time1, time2 );
	cout << time1.hours << "시간" << time1.minutes << "분" << time2.seconds << "초 " << endl;


		
}


//배열에 각 배열 번호에 값을 넣어주고 전부 합한값을 반환
double GetArraySum(double arr[], int n) // double arr[], int n <-- 매개변수
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

//분산 구하기
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

//두개의 수를 서로 바꾸기
void SwapValues(int x, int y) // int x ,int y 는 밑에 값을 복사해서 넣게되고 int& x, int& y (&)같은경우는 참조 명령어
							  // const 는 값을 고정하는 명령어
{
	int temp = x;
	x = y;
	y = temp;
}


void PrSalesRec(SalesRec Srec)
{
	cout << "품목코드" << Srec.pID << endl;
	cout << "배달일자" << Srec.dYear << "년" << endl;
	cout << Srec.dMonth << "월" << Srec.dData << "일" << endl;
	cout << "배달주소" << Srec.deliverAddr << endl;
}
//시간 t1에 t2를 더한다
void AddTime(TimeRec& t1, const TimeRec& t2)
{
	t1.seconds += t2.seconds;
	t1.minutes += t2.minutes + (t1.seconds / 60);
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.seconds %= 60;
	t1.minutes %= 60;
     
}
//시간 t1에 minutes 분을 더한다
void AddTime(TimeRec& t1, int minutes)
{
	t1.minutes += minutes;
	t1.hours += (t1.minutes / 60);
	t1.minutes %= 60;
}