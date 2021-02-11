
#include <iostream>
#include<functional>

using namespace std;

/*
�Լ������� : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
�Լ������� ������ : ��ȯŸ�� (*�����͸�)(����Ÿ��); �� ���·� �����ȴ�.
*/

int Sum(int a, int b)
{
	return a + b;
}

int Outsum(int a, int b)
{
	cout << a - b << endl;
	return a - b;
}

float TestFunc(float a)
{
	cout << a << endl;
	return a;
}

void Output()
{
	cout << "Output Function" << endl;
}

class CHanzo
{
public:
	CHanzo()
	{
		m_iTest = 10;
	}

	~CHanzo()
	{

	}

public:
	int m_iTest;

public:
	void Output()
	{
		cout << "Hanzo" << endl;
		//this-> �� ������ �� �ִ�.
		cout << "Test : " << this->m_iTest << endl;
	}
};

typedef struct _tagPoint
{
	int x;
	int y;

	_tagPoint() :
		x(0),
		y(0)
	{

	}

	_tagPoint(int _x, int _y) :
		x(_x),
		y(_y)
	{

	}

	_tagPoint(const _tagPoint& pt)
	{
		//���� ���縦 �Ѵ�. �̷��� ���� ��� this�� �ڱ��ڽ��� �������̰� *�� �ٿ��� �ڱ��ڽ��� �������Ͽ� ��� �����͸� �����ϰ� �Ѵ�.
		*this = pt;
	}

	_tagPoint operator +(const _tagPoint& pt)
	{
		_tagPoint result;
		result.x = x + pt.x;
		result.y = y + pt.y;

		return result;
	}


}POINT, * PPOINT;

int main()
{
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = Outsum;

	Outsum(10, 20);

	//pFunc = Output;
	void(*pFunc1)() = Output;

	pFunc1();

	CHanzo hanzo1, hanzo2;
	hanzo1.m_iTest = 300;
	hanzo2.m_iTest = 200;

	//this ������ : Ŭ���� �ȿ��� this�� ����Ұ�� ��ü�� �޸��ּҰ� �ȴ�. �� �ڱ��ڽ��� �������̴�.
	//����Լ��� ȣ���Ҷ� this�� ȣ���ڷ� �����Ѵ�.

	hanzo1.Output();
	hanzo2.Output();

	void (CHanzo:: * pFunc2)() = &CHanzo::Output;

	//(*pFunc2)();

	//hanzo1.(*pFunc2)();
	(hanzo1.*pFunc2)();


	/*
	function ����� �Լ������͸� ����, ��� ������ �ʰ� ���� �ּҸ� �����ؼ� ȣ������ �� �ֵ��� ������ִ� ����̴�.
	������ : function<��ȯŸ��(����Ÿ��)> ������; �� ���·� �����Ѵ�.
	*/
	function<void()> func;
	function<void()> func1;

	//bind�� �̿��ؼ� �Լ��� �����ش�.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo1);

	cout << "==================Functional==================" << endl;
	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;

	//�Լ��� ���ڰ� ���� ��� placeholders�� �̿��ؼ� ������ ������ ������ �� �ִ�.
	func3 = bind(Outsum, placeholders::_1, placeholders::_2);

	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);

	func4(3.14f);

	cout << "===================POINT===================" << endl;

	POINT pt1(10, 20), pt2(30, 40), pt3;

	//POINT ����ü�� +�����ڰ� operator�� ������ �Ǿ��ִ�. 
	//�׷��� +������ �����ϰ� �ǰ� pt1�� + ������ �Լ��� ȣ�����ִ� �����̴�. pt2�� ���ڷ� �Ѱ��ش�.
	pt3 = pt1 + pt2;

	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;

	return 0;
}