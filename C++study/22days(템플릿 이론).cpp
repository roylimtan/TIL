
#include <iostream>

using namespace std;

/*
奴巴鹸 : 陳督析 舘域拭辞 展脊聖 井舛憎澗 奄管戚陥.
展脊戚 陥丞馬惟 郊介 呪 赤陥.
template<typename 据馬澗 戚硯>税 莫殿稽 紫遂 亜管馬陥.
template <class 据馬澗 戚硯>税 莫殿稽 紫遂 亜管馬陥.

森)
template <typename T>
void Output()
{
	cout << typeid(T).name() << endl;
}

是坦軍 敗呪研 幻級壱 板窒獣
Output<int>();
Output<float>();

戚係惟 背爽檎 int, float生稽 展脊戚 舛背遭陥. 雌伐拭 魚虞 隔嬢爽澗 展脊生稽 展脊戚 亜痕旋生稽 郊餓澗 依戚陥.

亜痕展脊精 食君鯵研 走舛背匝呪赤陥.
template<typename T, typename T1>
void Output()
{
}

是坦軍 食君鯵 走舛亀 亜管廃 依戚陥.
*/

template <typename T>
void OutputType()
{
	cout << "==== OutputType ====" << endl;
	cout << typeid(T).name() << endl;
}

template <typename T>
void OutputData(T data)
{
	cout << "==== OutputData ====" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

typedef struct _tagStudent
{

}STUDENT, *PSTUDENT;

class CCar
{
public:
	CCar()
	{

	}

	~CCar()
	{

	}
};

enum Test
{

};

class CTemplate
{
public:
	CTemplate()
	{

	}

	~CTemplate()
	{

	}

public:
	template <class T, class T1>
	void Output(T a, T1 b)
	{
		cout << a << endl;
		cout << b << endl;
	}
};

template <typename T>
class CTemplate1
{
public:
	CTemplate1()
	{
		cout << "Template1 class Type : " << typeid(T).name() << endl;

	}

	~CTemplate1()
	{

	}

private:
	T m_Data;

public:
	void Output()
	{
		cout << typeid(T).name() << endl;
	}
};

int main()
{
	OutputType<int>();
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<Test>();

	OutputData(10);
	OutputData(3.1);
	OutputData(381.324);
	OutputData('a');
	OutputData("せせせせせせ");

	CTemplate tem;

	tem.Output(10, 3.14);

	CTemplate1<int> tem1;

	tem1.Output();

	CTemplate1<CTemplate> tem2;

	return 0;
}