#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

//�Լ��� ����� ���� �κ��� ���� �� �ִ�.
void SetNumber(int* pArray)
{
	for (int i = 0; i < 25; ++i)
	{
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray)
{
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;
	}
}

AI_MODE SelectAIMode()
{
	int iAIMode;

	//AI ���̵��� �����Ѵ�.
	while (true)
	{
		system("cls");
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "AI ��带 �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}

	return (AI_MODE)iAIMode;
}

void OutputNumber(int* pArray, int iBingo)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";

			else
				cout << pArray[i * 5 + j] << "\t";
		}

		cout << endl;
	}
	cout << "Bingo Line : " << iBingo << endl << endl;
}

bool ChangeNumber(int* pArray, int iInput)
{
	//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ����� ã�Ƴ���.
	for (int i = 0; i < 25; ++i)
	{
		//���� ���ڰ� �ִ� ���
		if (iInput == pArray[i])
		{
			//���縦 ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
			//bAcc ������ false�� ������ش�.
		

			//���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
			pArray[i] = INT_MAX;

			//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ����������.
			return false;
		}
	}

	//������� ���ԵǸ� return false�� ���� �ȵȰ��̹Ƿ� ���� ���ڰ� ���ٴ� ���̴�. ��, �ߺ��� ���ڸ� �Է��߱� ������  true�� �����Ѵ�.
	return true;
}

int SelsctAINumber(int* pArray, AI_MODE eMode)
{
	//���� �ȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	//���þȵ� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	//AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI�� ��忡 ���� �޶�����.
	switch (eMode)
	{
		int iNoneSelectCount;
		/*
		AI EASY���� ���� AI�� ���ڸ����� ���� �ٲ��� ���� ���� ����� ���� �� ���� �� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
		*/
	case AM_EASY:
		//���� �ȵ� ���� ����� ������ش�.
		//���� �ȵ� ���� ������ ����� ���� �� ī�������ش�.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� *�� �ƴ� ���
			if (pArray[i] != INT_MAX)
			{
				//*�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
				//���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� �������Ѽ� �� ���þȵ� ������ �����ش�.
				//�׷��� 0���� ī��Ư�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1���� �߰��Ѵ�.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		/*
		for���� ���������� �Ǹ� ���þȵ� ����� ��������� ���þȵ� ����� ������ ��������� �ȴ�.
		���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ���� �ε����� �����ϰ� �����ش�.
		*/
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:

		/*
		�ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ���� ã�Ƽ�
		�� �ٿ� �ִ� ������ �ϳ��� *�� ����� �ش�.
		*/
		int iLine;
		int iStarCount = 0;
		int iSaveCount = 0;

		//���� ���� ���� �� ���� *�� ���� ������ ã�Ƴ���.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			/*
			���� 5�� �̸��̾�� ���� ���� �ƴϰ� ������ ���� ���� ������ ������ Ŀ�� ���� ���� ���� �����̹Ƿ�
			������ ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
			*/
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = i;
				iSaveCount = iStarCount;
			}
		}

		//���� ������ ���� ���� ���� ������ �̹� ���ߴ�.
		//�� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				//���� ������ 5~9�� �ǹ̸� �ο��ߴ�.
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		//���ʿ��� ������ �밢�� üũ
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		//�����ʿ��� ���� �밢�� üũ
		iStarCount = 0;
		for (int i = 0; i < 25; i += 4)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		//��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��Ȥ�� ����Ǿ���.
		//�� �ٿ� �ִ� ���� �ƴ� ������ �ϳ��� �����ϰ� �Ѵ�.
		//�������� ���
		if (iLine <= LN_H5)
		{
			//�������� ��� iLine�� 0~4 ������ ���̴�.
			for (int i = 0; i < 5; ++i)
			{
				//���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}

		else if (iLine <= LN_V5)
		{
			//�������� ��� iLine�� 5~9������ ���̴�.
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return pArray[i * 5 + (iLine - 5)];
				}
			}
		}

		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}

		else if (iLine == LN_RT)
		{
			for (int i = 0; i < 21; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		break;
	}

	return -1;
}

int BingoCountingH(int* pArray)
{
	//���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		//�� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			//���� �� ������ �����ش�.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}
		// j for���� ���������� ���� ���� ���� ���� �� ������ ����� iStar1������ ���� �ȴ�.
		//iStar1�� ���� 5�̸� �� ���� ��� *�̤Ӷ�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}

int BingoCountingV(int* pArray)
{
	//t���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		//�� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			//���� �� ������ �����ش�.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}
		// j for���� ���������� ���� ���� ���� ���� �� ������ ����� iStar1������ ���� �ȴ�.
		//iStar1�� ���� 5�̸� �� ���� ��� *�̤Ӷ�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}

int BingoCountingLTD(int* pArray)
{
	//���� ��ܿ��� ������ �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 25; i += 6)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}

int BingoCountingRTD(int* pArray)
{
	//������ ��ܿ��� ���� �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;

	for (int i = 4; i < 21; i += 4)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}

int BingoCounting(int* pArray)
{
	int iBingo = 0;

	//������ üũ
	iBingo += BingoCountingH(pArray);

	//������ üũ
	iBingo += BingoCountingV(pArray);

	//���� ��� �밢�� üũ
	iBingo += BingoCountingLTD(pArray);

	//������ ��� �밢�� üũ
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}

int main()
{
	srand((unsigned int)time(0));
	int iInput;
	int iNumber[25] = {};
	int iAINumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAINumber);

	Shuffle(iNumber);
	Shuffle(iAINumber);
	

	int iBingo = 0, iAIBingo = 0;

	//AI���̵��� �����Ѵ�.
	AI_MODE eAIMode = SelectAIMode();


	while (true)
	{
		system("cls");

		//���ڸ� 5 x 5 �� ����Ѵ�.
		cout << "========== Player ==========" << endl;
		OutputNumber(iNumber, iBingo);

		//AI�������� ����Ѵ�.
		cout << "========== AI ==========" << endl;

		switch (eAIMode)
		{
		case AM_EASY:
			cout << "AIMODE : EASY" << endl;
			break;
		case AM_HARD:
			cout << "AIMODE : HARD" << endl;

			break;
		}

		OutputNumber(iAINumber, iAIBingo);


		//�ټ��� 5 �̻��� ��� �����Ѵ�.
		if (iBingo >= 5)
		{
			cout << "Player �¸�" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		//�ߺ� �Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ�� �ϱ� ���� true�� �־���.
		bool bAcc = ChangeNumber(iNumber, iInput);


		//bAcc������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue���ش�.
		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		ChangeNumber(iAINumber, iInput);

		//AI�� ���ڸ� �����Ѵ�. AI��忡 ���缭 ���õǵ��� �Լ��� �����Ǿ� �ִ�.
		iInput = SelsctAINumber(iAINumber, eAIMode);



		//AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٱ��ش�.
		ChangeNumber(iNumber, iInput);

		ChangeNumber(iAINumber, iInput);

		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �Ѵ�.
		//�׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ �ϰ� ���κ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);



		
	}
	return 0;
}