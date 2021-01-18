/*
�������� ���α׷� �����
1. å ���
2. å �뿩
3. å �ݳ�
4. å ���
5. ����

å ����ü�� �̸�, �뿩�ݾ�, å��ȣ, �뿩���ΰ� �ʿ��ϴ�.
å����� �����ϸ� å ������ ������ش�.
*/

#include <iostream>

#define NAME_SIZE 32
#define Book_MAX 10
#define EXIST_SIZE 32

using namespace std;

struct _tagBook
{
	char strName[NAME_SIZE];
	char strExist[EXIST_SIZE];
	int iMoney;
	int iNumber;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_LENDING,
	MENU_RETURN,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagBook Bookarr[Book_MAX] = {};
	int iBookCount = 0;
	int iBookNumber = 1;

	char strBookName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");

		cout << "1. å ���" << endl;
		cout << "2. å �뿩" << endl;
		cout << "3. å �ݳ�" << endl;
		cout << "4. å ���" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� ����ϼ��� : ";
		int iMENU;
		cin >> iMENU;

		if (cin.fail())
		{
			//�������۸� ����ش�.
			cin.clear();

			//�Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n�� �����ش�.
			//ù��°���� �˻��ϰ��� �ϴ� ���� ũ�⸦ �����Ѵ�. �˳��ϰ� 1024����Ʈ���� ����
			//�ι�°�� ������ �ϴ� ���ڸ� �־��ش�. �׷��� �Է¹��� ó������ \n�� �ִ� ������ ã�Ƽ�
			//�� �κ��� ��� �����༭ �ٽ� �Է¹����� �ֵ��� ���ش�.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMENU == MENU_EXIT)
			break;

		switch (iMENU)
		{
		case MENU_INSERT:
			system("cls");
			cout << "==========���� ���==========" << endl;

			if (iBookCount >= Book_MAX)
				break;

			//getline�� ���͸� �ν��ϹǷ� �̸� �����ϱ����� ignore ���ش�.
			cin.ignore(1024, '\n');

			cout << "å �̸� : ";
			cin.getline(Bookarr[iBookCount].strName, NAME_SIZE);
			cout << "�뿩 ���� : ";
			cin.getline(Bookarr[iBookCount].strExist, EXIST_SIZE);
			cout << "�뿩 �ݾ� : ";
			cin >> Bookarr[iBookCount].iMoney;

			Bookarr[iBookCount].iNumber = iBookNumber;

			++iBookCount;
			++iBookNumber;

			cout << "���� �߰� �Ϸ�" << endl;

			break;

		case MENU_LENDING:
			system("cls");

			cout << "==========���� �뿩==========" << endl;

			cin.ignore(1024, '\n');
			cout << "�뿩 �� ������ �̸��� �Է��ϼ��� : " << endl;
			cin.getline(strBookName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(Bookarr[i].strName, strBookName) == 0)
				{
					cout << strBookName << "�� �뿩 �Ϸ� �Ǿ����ϴ�." << endl;

					
					cout << "�뿩 ���� ���θ� �������ּ���. : " << endl;
					cin.getline(Bookarr[i].strExist, EXIST_SIZE);
				}

				else
				{
					cout << "���Ͻô� å�� ã�� ���߽��ϴ�." << endl;
				}
			}

			break;

		case MENU_RETURN:
			system("cls");
			cout << "==========���� �ݳ�==========" << endl;

			cin.ignore(1024, '\n');
			cout << "�ݳ��� ������ �̸��� �Է��ϼ��� : " << endl;
			cin.getline(strBookName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(Bookarr[i].strName, strBookName) == 0)
				{
					cout << strBookName << " �� �ݳ� �Ϸ� �Ǿ����ϴ�." << endl;

					cout << "�뿩���� ���θ� �������ּ��� : " << endl;
					cin.getline(Bookarr[i].strExist, EXIST_SIZE);
				}
			}

			break;

		case MENU_OUTPUT:
			system("cls");
			cout << "==========���� ���==========" << endl;

			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "���� �̸� : " << Bookarr[i].strName << endl;
				cout << "���� �ݾ� : " << Bookarr[i].iMoney << endl;
				cout << "���� ��ȣ : " << Bookarr[i].iNumber << endl;
				cout << "�뿩 ���� : " << Bookarr[i].strExist << endl << endl;
				
			}
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;		
		}
		system("pause");
	}
	return 0;
}