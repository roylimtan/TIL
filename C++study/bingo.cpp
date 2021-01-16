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

int main()
{
	int iInput;
	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		//AI���ڵ� �����ش�.
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
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
	//���� �ȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	//���þȵ� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		//���ڸ� 5 x 5 �� ����Ѵ�.
		cout << "========== Player ==========" << endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				
				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}
		cout << "Bingo Line : " << iBingo << endl << endl;

		//AI�������� ����Ѵ�.
		cout << "========== AI ==========" << endl;

		switch(iAIMode)
		{
		case AM_EASY:
			cout << "AIMODE : EASY" << endl;
			break;
		case AM_HARD:
			cout << "AIMODE : HARD" << endl;
			
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iAINumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		//AI���� �� ���� ����Ѵ�
		cout << "AIBingo Line : " << iAIBingo << endl;

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

		//�ߺ� �Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ��� �ϱ� ���� true�� �־���.
		bool bAcc = true;

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� �ִ� ���
			if (iInput == iNumber[i])
			{
				//���縦 ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				//bAcc ������ false�� ������ش�.
				bAcc = false;

				//���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ����������.
				break;
			}
		}
		//bAcc������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue���ش�.
		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iAINumber[i])
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		//AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI�� ��忡 ���� �޶�����.
		switch (iAIMode)
		{
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
				if (iAINumber[i] != INT_MAX)
				{
					//*�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					//���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� �������Ѽ� �� ���þȵ� ������ �����ش�.
					//�׷��� 0���� ī��Ư�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1���� �߰��Ѵ�.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			/*
			for���� ���������� �Ǹ� ���þȵ� ����� ��������� ���þȵ� ����� ������ ��������� �ȴ�.
			���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ���� �ε����� �����ϰ� �����ش�.
			*/
			iInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
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
					if (iAINumber[i * 5 + j] == INT_MAX)
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
					if (iAINumber[j * 5 + i] == INT_MAX)
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
				if (iAINumber[i] == INT_MAX)
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
				if (iAINumber[i] == INT_MAX)
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
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				//�������� ��� iLine�� 5~9������ ���̴�.
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 0; i < 21; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}

		//AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٱ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}



		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �Ѵ�.
		//�׷��Ƿ� iBingo ������ 0���� �Ź� �ʱ�ȭ �ϰ� ���κ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAIBingo = 0;

		//����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			//�� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				//���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				//AI�� ������ �����ش�.
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;

				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}
			// i for���� ���������� ���� ���� ���� ���� �� ������ ����� iStar1������ ���� �ȴ�.
			//iStar1�� ���� 5�̸� �� ���� ��� *�̤Ӷ�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAIStar1 == 5)
				++iAIBingo;
			if (iAIStar2 == 5)
				++iAIBingo;
		}

		//���� ��ܿ��� ������ �ϴ� �밢�� üũ
		int iStar3 = 0, iStar4 = 0;
		int iAIStar3 = 0, iAIStar4 = 0;

		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar3;

			if (iAINumber[i] == INT_MAX)
				++iAIStar3;
		}


		//������ ��ܿ��� ���� �ϴ� �밢�� üũ
		for (int i = 4; i < 21; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar4;

			if (iAINumber[i] == INT_MAX)
				++iAIStar4;
		}

		if (iStar3 == 5)
			++iBingo;

		if (iStar4 == 5)
			++iBingo;

		if (iAIStar3 == 5)
			++iAIBingo;

		if (iAIStar4 == 5)
			++iAIBingo;
	}

	return 0;
}