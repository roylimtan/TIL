#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	//���� �߱�����

	int Strike = 0 , Ball = 0;

	int iNumber[9] = {};
	//1~9���� ���� ����
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
		cout << Gamecount << " ȸ" << endl;
		cout << "1~9�� 3���� ���ڸ� �Է��ϼ���(0 : ����)" << endl;
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		
		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
		{
			cout << "�����մϴ�." << endl;
			break;
		}
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 ||
			iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "�߸��� ���ڸ� �Է��Ͽ����ϴ�." << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
		{
			cout << "�ߺ��� ���ڸ� �Է��Ͽ����ϴ�." << endl; 
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
			cout << "���ڸ� ��� ������ϴ�." << endl;
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