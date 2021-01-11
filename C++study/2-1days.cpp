#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//상수(const) : 변하지 않는 수, 값을 한번 지정해놓으면 바꿀 수 업ㅄ다.
	//상수는 선언과 도잇에 값을 지정해두어야 한다.
	const int	iAttack = 0x00000001;	//1
	const int	iArmor = 0x00000002;	//10
	const int	iHP = 0x00000004;		//100
	const int	iMP = 0x00000008;		//1000
	const int	iCritical = 0x00000010;	//10000

	// 1 | 100 = 101 | 10000 = 10101
	//-> 각 비트에 원하는 기능을 추가하기 위해서는 or사용
	int iBuf = iAttack | iHP | iCritical;

	//연산자 축야형 : 연산자를 줄여서 사용할 수 있다.
	//아래를 풀어서 쓰면  iBuf = iBuf ^ iHP;
	//^기능 사용하면 스위치 기능을 만들 수 있다.
	//10101 ^ 00100 = 10001 =>HP만 사라졌다.
	iBuf ^= iHP; //HP끔

	//10001 ^ 00100 = 10101
	iBuf ^= iHP; //HP킴

	//10101 & 1 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;
	//10101 & 10 = 00000
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	//10101 & 10000 = 10000 = 16                                                                
	cout << "Critical : " << (iBuf & iCritical) << endl;


	/*
	쉬프트 연산자 : <<, >> 값대 값을 연산하여 값으로 나오게 된다.
	이 연산자 또한 이진수 단위의 연산을 하게 된다.
	20 << 2 = 80
	20 << 3 = 160
	20 << 4 = 320
	20을 2진수로 변환한다.
	10100 -> 2칸가라 -> 1010000
	10100 -> 3칸가라 -> 10100000
	10100 -> 4칸가라 -> 101000000

	20 >> 2 = 5
	20 >> 3 = 2
	20 >> 4 = 1
	10100 -> 2칸 지워라 -> 101
	10100 -> 3칸 지워라 -> 10
	10100 -> 4칸 지워라 -> 1
	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	//iNumber에 187이 들어가 있다. 이 값을 <-이 방향으로 16비트 이동시키면
	//상위 16비트에 값이 들어가게 된다.
	iNumber <<= 16;

	//하위 16비트를 채운다.
	iNumber |= iLow;

	//High 값을 출력한다.
	cout << "High :" << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	//증감 연산자 : ++, --가 있다. 1증가, 1감소이다.
	iNumber = 10;

	//전치 (증가 시켜놓고 다음거 처리)
	++iNumber;

	//후치 (출력 한 후에 증가)
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl;

	/*
	분기문에는 크게 2가지 종류가 있다. if문, switch문이 존재한다.
	if문 : 조ㅓㄴ을 체크해주는 기능이다.
	형태 : if(조건식) {}(코드블럭)
	if문은 조건식이 tue가 될 경우 코드블럭 안의 코드가 동작된다.
	false일 경우에는 동작되지 않는다.
	*/
	if (true)
	{
		cout << "if문 조건이 true입니다." << endl;
	}

	//버프가 있는지 확인한다.
	if ((iBuf & iAttack) !=0)
	{
		cout << "Attack버프ㅏ 있습니다." << endl;
	}

	//if문 아래에 들어ㅏㄹ 코드가 1줄일 경우 {}(코드블럭)을 생랴할 수 있다.
	if ((iBuf & iArmor) != 0)
		cout << "Armor 버프가 있습니다." << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP 버프가 있습니다." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP 버프가 있습니다." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical 버프가 있습니다." << endl;

	/*
	else : if문과 반드시 같이 사용이 되어야 한다.
	if문 조건이 false일 경우 else가 있다면 else 구문 안의 코드가 동작된다.

	else if : if문과 반드시 같이 사용이 되어야 한다.
	if문 아래 와야 하고 else보다는 위에 있어야 한다.
	else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
	else if는 몇개든 사용이 가능하다.
	*/
	if (false)
		cout << "if문 조건이 tue입니다" << endl;

	else
		cout << "if문 조건이 false입니다." << endl;

	cout << "숫자를 입력하세요 :";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20사이의 숫자입니다." << endl;
	else if (20 < iNumber && 30 >= iNumber)
		cout << "21~30사이의 숫자입니다." << endl;
	else if (31 < iNumber && 40 >= iNumber)
		cout << "31~40사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;


	//난수 발생
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	cout << (rand() % 101 + 100) << endl;
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "Upgrade 기본 수치를 입력하세요 : ";
	cin >> iUpgrade;

	//강화 화률을 구한다.	
	float fPercent = rand() % 10000 / 100.f;

	//강화 확률 : 업그레이드가 0~3 : 100%성공 4~6 : 40% 7~9 : 10%
	//10~13 : 1%  14~15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;
	else if (iUpgrade > 3 && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (iUpgrade > 6 && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (iUpgrade > 9 && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (iUpgrade > 13 && iUpgrade <= 15) 
	{
		if (fPercent < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}


	return 0;
}