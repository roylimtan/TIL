#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	//숫자 야구게임

	int Strike = 0 , Ball = 0;

	int iNumber[9] = {};
	//1~9까지 숫자 설정
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}
	
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{	
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	
	//cout << "* * *" << endl;
	cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;


	int iInput[3];
	int Gamecount = 1;
	while (true)
	{
		cout << Gamecount << " 회" << endl;
		cout << "1~9중 3개의 숫자를 입력하세요(0 : 종료)" << endl;
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			cout << "종료합니다." << endl;
			break;
		}
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 ||
			iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입려하였습니다." << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입려하였습니다." << endl; 
			continue;
		}
			
		Strike = Ball = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++Strike;
					else
						++Ball;

					break;
				}
			}
		}

		if (Strike == 3)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		else if (Strike == 0 && Ball == 0)
		{
			cout << "3 OUT" << endl;
			
		}

		else
		{
			cout << Strike << "strike, " << Ball << "ball" << endl;
		
		}
		++Gamecount;



	}

	return 0;
}