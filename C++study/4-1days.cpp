#include <iostream>
#include <time.h>

using namespace std;

int main()
{

	/*
	do while ��: �ݺ����� �� �����̴�.
	���� : do {}while(���ǽ�); �� ���·� �����ȴ�.
	whiile���� ó�� ���Ժ��� ���ǽ��� üũ������ do while�� ó�� �ѹ��� ������ ������ �ǰ�
	�� �Ŀ� ���ǽ��� üũ�ؼ� true�̸� ��� �ݺ��ؼ� ���۵Ǵ� �ݺ����̴�.
	*/
	int iNumber = 0;

	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);
	system("cls");


	/*
	�迭 : �������� ������ �ѹ��� �������� �� �ִ� ����̴�.
	���� : ����Ÿ�� �迭��[����]; �� ���·� ������ �� �ִ�.
	�迭�� Ư¡ : �迭�� ���ҵ� �޸� ���� ������ �Ҵ�ȴ�.
	�迭�� �ε����� �̿��ؼ� ���ϴ� �κп� �����Ͽ� ���� ������ �� �ִ�.
	�ε����� 0���� ����-1�����̴�. ��, 10����� 0~9������ �� 10���� �ε����� ������ �ȴ�.
	*/

	//�迭 �Ӹ� �ƴ϶� �Ϲ� �����鵵 ������ �ϰ� ���� �ʱ�ȭ���� ���� ��� �����Ⱚ�� ���� �ȴ�.
	//int iArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	//0~4�������� 1, 2, 3, 4, 5�� ���� ���� �ǰ� �������� ��� 0���� �ʱ�ȭ �ȴ�.
	//int iArray[10] = { 1, 2, 3, 4, 5 };

	//����ִ� �߿�ȣ�� �������� ��� ��� �ε����� 0���� �ʱ�ȭ�Ѵ�.
	int iArray[10] = {};

	iArray[1] = 1234;

	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}
	//cout << iArray[5] << endl;

	/*
	�迭 ������ 2�� �����ϸ� ������ �迭�� �ȴ�. 3�� �����ϸ� 3���� �迭�� �ȴ�.
	2���� �迭�� ������ ���� �� * ���� �� ��ŭ ó���� �ȴ�. �Ʒ��� 10 * 10���� �迭�� �ȴ�.
	*/
	int iArray2[10][10] = { {1, 2, 3}, {4, 5, 6} };

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << iArray2[i][j] << "\t";

		}
		cout << endl;

	}
	system("cls");

	srand((unsigned int)time(0));

	//Lotto Porgram
	int iLotto[45] = {};

	for (int i = 0; i < 45; ++i)
	{
		iLotto[i] = i + 1;
	}

	//swap �˰���
	/*
	int iNum1 = 1, iNum2 = 2, iNum3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;
	*/

	//shuffle
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << "\t";
	}

	cout << "���ʽ� ��ȣ : " << iLotto[6] << endl;


	return 0;
}