#include <iostream>
#include <time.h>

using namespace std;

enum SRP
{
	SPR_S = 1,
	SPR_R,
	SPR_P,
	SPR_END
};

int main()
{
	/*
	반복문 : 트정 작업ㅂ을 반복해서 수행해주는 기능이다.
	종류 : for, while, do while 3종류가 존재한다.
	while(조건시) {} 의 형태로 구성된다.
	while문은 조건식을 체크해서 true일 경우 코드불럭 안의 코드가 동작되고
	다시 조건식을 체크한다. 조건식이 false가 되면 while문을 빠져나오게 된다.
	반복문 안에서 break를 만나게 되면 해당 반복문을 빠져나오게 된다.
	*/
	int iNumber;

	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}

	//화면을 깨끄히 지워준다.
	system("cls");

	

	//난수테이블 생성
	srand((unsigned int)time(0));

	int iPlayer, iAI;

	while (false)
	{
		cout << "1.가위" << endl;
		cout << "2.바위" << endl;
		cout << "3.보" << endl;
		cout << "4.종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SPR_S || iPlayer > SPR_END)
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			//일시정지
			system("pause");
			//반복문의 시작점으로 이동시켜주는 기능이다.
			continue;
		}
		else if (iPlayer == SPR_END)
			break;

		//봇이 선택을 한다.
		iAI = rand() % 3 + SPR_S;

		switch (iAI)
		{
		case SPR_S:
			cout << "AI : 가위" << endl;
			break;
		case SPR_R:
			cout << "AI : 바위" << endl;
			break;
		case SPR_P:
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;
		
		/*if (iWin == 0)
			cout << "비겼습니다." << endl;

		else if (iWin == 1 or iWin == -2)
			cout << "Player 승리" << endl;

		else
			cout << "AI 승리" << endl;

		//system("pause");*/

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "Player 승리" << endl;
			break;
		case 0:
			cout << "비김" << endl;
			break;
		default:
			cout << "AI승리" << endl;
			break;
		}

	}

	/*
	for문 : 반복문의 한 종류이다.
	형태 : for(초기값; 조건식; 증감값){}의 형태로 구성된다.
	조건식이 true이면 코드블럭의 코드가 동작된다.
	무한루프를 돌릴때는 for(;;){}을 해주면 무한으로 돌아가게 된다.
	for문에서 초기값은 처음 for문에 진입할때 딱 1번만 동작된다.
	그 후에 조건식을 체크하고 조건식이 true면 코드블럭ㄱ의 코드가 동작된 후에 증감값을 처리한다.
	그 후 다시 조건을 체크하고 ture면 동작되고 증감-> 족건 -> 증감 -> 조건의 순서로 처리가 된다가
	조건이 false이거나 break를 만나게 되면 for문을 빠져나가게 된다.
	*/
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	}

	//구구단 2단을 출력해보자.
	for (int i = 1; i < 10; ++i)\
	{
		cout << "2 x " << i << "=" << 2 * i << endl;
	}

	//1~100사이의 숫자중 짝수만 출력하는 for문을 작성해보자.
	for (int i = 2; i <= 100; i=i+2) //i += 2
	{
		cout << i << endl;
	}

	//3과 7의 공배수만 출력
	for (int i = 1; i <= 100; ++i)
	{
		if (i % 3 == 0 and i % 7 == 0)
		{
			cout << i << endl;
		}  
	}

	//중첩 for문 : for문 안에 또 다른 for문이 존재하는 형태이다.
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "i = " << i << "j = " << j << endl;
		}
	}
	system("cls");

	//구구단 2단부터 9단까지 출려하는 중첩 for문
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}

	/*
	2단 3단 4단
	5단 6단 7단
	8단 9단 10단
	*/
	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cout << i << "x" << j << "=" << i * j << "\t";
			cout << i + 1 << "x" << j << "=" << (i + 1) * j << "\t";
			cout << i + 2 << "x" << j << "=" << (i + 2) * j << endl;
			
		}
		cout << endl;
	}

	//별을 아래의 형태로 출력되게 한다.
	/*
	*
	**
	***
	*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*";
		}

		cout << endl;
	}
	

	//별을 아래의 형태로 출력
	/*
	*****
	****
	***
	**
	*
	*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 5; j > i ; --j)
		{
			cout << "*";
		}

		cout << endl;
	}

	//별을 아래의 형태로 출력하게 한다.
	/*
	   *
	  ***
	 *****
	*******
	*/
	//공백 : 3, 2, 1, 0 별: 1, 3, 5, 7
	for (int i = 0; i < 4; ++i)
	{
		//공백을 출력하기 위한 for문
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";

		}
		//별 출력
		for (int j = 0; j < i * 2 + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	system("cls");

	int iLine = 7;
	int iCount = 0;

	for (int i = 0; i < iLine; ++i)
	{
		iCount = i;

		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
		}

		for (int j = 0; j < 3 - iCount; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < iCount * 2 + 1; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}