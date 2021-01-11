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
	�ݺ��� : Ʈ�� �۾����� �ݺ��ؼ� �������ִ� ����̴�.
	���� : for, while, do while 3������ �����Ѵ�.
	while(���ǽ�) {} �� ���·� �����ȴ�.
	while���� ���ǽ��� üũ�ؼ� true�� ��� �ڵ�ҷ� ���� �ڵ尡 ���۵ǰ�
	�ٽ� ���ǽ��� üũ�Ѵ�. ���ǽ��� false�� �Ǹ� while���� ���������� �ȴ�.
	�ݺ��� �ȿ��� break�� ������ �Ǹ� �ش� �ݺ����� ���������� �ȴ�.
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

	//ȭ���� ������ �����ش�.
	system("cls");

	

	//�������̺� ����
	srand((unsigned int)time(0));

	int iPlayer, iAI;

	while (false)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "3.��" << endl;
		cout << "4.����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < SPR_S || iPlayer > SPR_END)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			//�Ͻ�����
			system("pause");
			//�ݺ����� ���������� �̵������ִ� ����̴�.
			continue;
		}
		else if (iPlayer == SPR_END)
			break;

		//���� ������ �Ѵ�.
		iAI = rand() % 3 + SPR_S;

		switch (iAI)
		{
		case SPR_S:
			cout << "AI : ����" << endl;
			break;
		case SPR_R:
			cout << "AI : ����" << endl;
			break;
		case SPR_P:
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAI;
		
		/*if (iWin == 0)
			cout << "�����ϴ�." << endl;

		else if (iWin == 1 or iWin == -2)
			cout << "Player �¸�" << endl;

		else
			cout << "AI �¸�" << endl;

		//system("pause");*/

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "Player �¸�" << endl;
			break;
		case 0:
			cout << "���" << endl;
			break;
		default:
			cout << "AI�¸�" << endl;
			break;
		}

	}

	/*
	for�� : �ݺ����� �� �����̴�.
	���� : for(�ʱⰪ; ���ǽ�; ������){}�� ���·� �����ȴ�.
	���ǽ��� true�̸� �ڵ���� �ڵ尡 ���۵ȴ�.
	���ѷ����� �������� for(;;){}�� ���ָ� �������� ���ư��� �ȴ�.
	for������ �ʱⰪ�� ó�� for���� �����Ҷ� �� 1���� ���۵ȴ�.
	�� �Ŀ� ���ǽ��� üũ�ϰ� ���ǽ��� true�� �ڵ������ �ڵ尡 ���۵� �Ŀ� �������� ó���Ѵ�.
	�� �� �ٽ� ������ üũ�ϰ� ture�� ���۵ǰ� ����-> ���� -> ���� -> ������ ������ ó���� �ȴٰ�
	������ false�̰ų� break�� ������ �Ǹ� for���� ���������� �ȴ�.
	*/
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	}

	//������ 2���� ����غ���.
	for (int i = 1; i < 10; ++i)\
	{
		cout << "2 x " << i << "=" << 2 * i << endl;
	}

	//1~100������ ������ ¦���� ����ϴ� for���� �ۼ��غ���.
	for (int i = 2; i <= 100; i=i+2) //i += 2
	{
		cout << i << endl;
	}

	//3�� 7�� ������� ���
	for (int i = 1; i <= 100; ++i)
	{
		if (i % 3 == 0 and i % 7 == 0)
		{
			cout << i << endl;
		}  
	}

	//��ø for�� : for�� �ȿ� �� �ٸ� for���� �����ϴ� �����̴�.
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "i = " << i << "j = " << j << endl;
		}
	}
	system("cls");

	//������ 2�ܺ��� 9�ܱ��� ����ϴ� ��ø for��
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}

	/*
	2�� 3�� 4��
	5�� 6�� 7��
	8�� 9�� 10��
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

	//���� �Ʒ��� ���·� ��µǰ� �Ѵ�.
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
	

	//���� �Ʒ��� ���·� ���
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

	//���� �Ʒ��� ���·� ����ϰ� �Ѵ�.
	/*
	   *
	  ***
	 *****
	*******
	*/
	//���� : 3, 2, 1, 0 ��: 1, 3, 5, 7
	for (int i = 0; i < 4; ++i)
	{
		//������ ����ϱ� ���� for��
		for (int j = 0; j < 3 - i; ++j)
		{
			cout << " ";

		}
		//�� ���
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