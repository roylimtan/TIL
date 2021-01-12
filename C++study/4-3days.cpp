#include <iostream>
#include<time.h>

//concole input output ��������̴�.
//�ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� ��������̴�.
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

	//���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ���� �����
	//INT_MAX��� ���� ����� ���̴�.
	//INT_MAX�� �̹� ���ǵǾ��ִ� ������ int�� ǥ���� �� �ִ� �ִ밪�̴�.
	iNumber[24] = INT_MAX;

	//���� �ִ� ��ġ�� ������ ������ ������ش�.
	int iStarindex = 24;

	//������ ������ �����ϰ� 1~24 ������ ���ڸ� �����ش�.
	//��, �ε����� 0~23�� �ε��� ������ �����ش�.
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

		//tue�� �־ ���� ��� ����� ��� �����صд�.
		bool bWin = true;

		//������ ���߾����� üũ�Ѵ�,
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
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ����";
		//_getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�.
		//�� �Լ��� Enter�� ġ�� �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� ����ȴ�.
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

	cout << "������ �����մϴ�." << endl;
	return 0;
}