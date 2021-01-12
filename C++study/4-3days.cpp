#include <iostream>
#include<time.h>

//concole input output 헤더파일이다.
//콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.
#include<conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	//가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 사용함
	//INT_MAX라는 값을 사용할 것이다.
	//INT_MAX는 이미 정의되어있는 값으로 int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	//별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarindex = 24;

	//마지막 공백을 제외하고 1~24 까지의 숫자만 섞어준다.
	//즉, 인덱스는 0~23번 인덱스 까지만 섞어준다.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp; 
	}
	
	while (true)
	{
		system("cls");
		for (int i = 0; i < 25; i += 5)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[j + i] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[j + i] << "\t";
			}
			cout << endl;
		}

		//tue로 주어서 먼저 모두 맞췄다 라고 가정해둔다.
		bool bWin = true;

		//퍼즐을 맞추었는지 체크한다,
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료";
		//_getch() 함수는 문자 1개를 입력받는 함수이다.
		//이 함수는 Enter를 치지 않더라도 문자를 누르는 수난 바로 그 문자를 반환하고 종료된다.
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		

		switch (cInput)
		{
		case'w':
		case'W':
			if (iStarindex > 4)
			{
				iNumber[iStarindex] = iNumber[iStarindex - 5];
				iNumber[iStarindex - 5] = INT_MAX;
				iStarindex -= 5;
				
			}
			break;
		case'a':
		case'A':
			if (iStarindex % 5 != 0)
			{
				iNumber[iStarindex] = iNumber[iStarindex - 1];
				iNumber[iStarindex - 1] = INT_MAX;
				iStarindex -= 1;
			}
			break;

		case's':
		case'S':
			if (iStarindex < 20)
			{
				iNumber[iStarindex] = iNumber[iStarindex + 5];
				iNumber[iStarindex + 5] = INT_MAX;
				iStarindex += 5;
			}
			break;
			 
		case'd':
		case'D':
			if (iStarindex % 5 != 4)
			{
				iNumber[iStarindex] = iNumber[iStarindex + 1];
				iNumber[iStarindex + 1] = INT_MAX;
				iStarindex += 1;
			}
			break;
		}
	}

	cout << "게임을 종료합니다." << endl;
	return 0;
}