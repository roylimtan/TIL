#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//���(const) : ������ �ʴ� ��, ���� �ѹ� �����س����� �ٲ� �� ������.
	//����� ����� ���տ� ���� �����صξ�� �Ѵ�.
	const int	iAttack = 0x00000001;	//1
	const int	iArmor = 0x00000002;	//10
	const int	iHP = 0x00000004;		//100
	const int	iMP = 0x00000008;		//1000
	const int	iCritical = 0x00000010;	//10000

	// 1 | 100 = 101 | 10000 = 10101
	//-> �� ��Ʈ�� ���ϴ� ����� �߰��ϱ� ���ؼ��� or���
	int iBuf = iAttack | iHP | iCritical;

	//������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
	//�Ʒ��� Ǯ� ����  iBuf = iBuf ^ iHP;
	//^��� ����ϸ� ����ġ ����� ���� �� �ִ�.
	//10101 ^ 00100 = 10001 =>HP�� �������.
	iBuf ^= iHP; //HP��

	//10001 ^ 00100 = 10101
	iBuf ^= iHP; //HPŴ

	//10101 & 1 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;
	//10101 & 10 = 00000
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	//10101 & 10000 = 10000 = 16                                                                
	cout << "Critical : " << (iBuf & iCritical) << endl;


	/*
	����Ʈ ������ : <<, >> ���� ���� �����Ͽ� ������ ������ �ȴ�.
	�� ������ ���� ������ ������ ������ �ϰ� �ȴ�.
	20 << 2 = 80
	20 << 3 = 160
	20 << 4 = 320
	20�� 2������ ��ȯ�Ѵ�.
	10100 -> 2ĭ���� -> 1010000
	10100 -> 3ĭ���� -> 10100000
	10100 -> 4ĭ���� -> 101000000

	20 >> 2 = 5
	20 >> 3 = 2
	20 >> 4 = 1
	10100 -> 2ĭ ������ -> 101
	10100 -> 3ĭ ������ -> 10
	10100 -> 4ĭ ������ -> 1
	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	//iNumber�� 187�� �� �ִ�. �� ���� <-�� �������� 16��Ʈ �̵���Ű��
	//���� 16��Ʈ�� ���� ���� �ȴ�.
	iNumber <<= 16;

	//���� 16��Ʈ�� ä���.
	iNumber |= iLow;

	//High ���� ����Ѵ�.
	cout << "High :" << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	//���� ������ : ++, --�� �ִ�. 1����, 1�����̴�.
	iNumber = 10;

	//��ġ (���� ���ѳ��� ������ ó��)
	++iNumber;

	//��ġ (��� �� �Ŀ� ����)
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl;

	/*
	�б⹮���� ũ�� 2���� ������ �ִ�. if��, switch���� �����Ѵ�.
	if�� : ���ä��� üũ���ִ� ����̴�.
	���� : if(���ǽ�) {}(�ڵ��)
	if���� ���ǽ��� tue�� �� ��� �ڵ�� ���� �ڵ尡 ���۵ȴ�.
	false�� ��쿡�� ���۵��� �ʴ´�.
	*/
	if (true)
	{
		cout << "if�� ������ true�Դϴ�." << endl;
	}

	//������ �ִ��� Ȯ���Ѵ�.
	if ((iBuf & iAttack) !=0)
	{
		cout << "Attack������ �ֽ��ϴ�." << endl;
	}

	//if�� �Ʒ��� ���� �ڵ尡 1���� ��� {}(�ڵ��)�� ������ �� �ִ�.
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iHP) != 0)
		cout << "HP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iMP) != 0)
		cout << "MP ������ �ֽ��ϴ�." << endl;
	if ((iBuf & iCritical) != 0)
		cout << "Critical ������ �ֽ��ϴ�." << endl;

	/*
	else : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� ������ false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ���۵ȴ�.

	else if : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� �Ʒ� �;� �ϰ� else���ٴ� ���� �־�� �Ѵ�.
	else if�� �ڽ��� ���� �ִ� ���ǽ��� false�� ��� ���� else if�� ���ǽ��� üũ�Ѵ�.
	else if�� ��� ����� �����ϴ�.
	*/
	if (false)
		cout << "if�� ������ tue�Դϴ�" << endl;

	else
		cout << "if�� ������ false�Դϴ�." << endl;

	cout << "���ڸ� �Է��ϼ��� :";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20������ �����Դϴ�." << endl;
	else if (20 < iNumber && 30 >= iNumber)
		cout << "21~30������ �����Դϴ�." << endl;
	else if (31 < iNumber && 40 >= iNumber)
		cout << "31~40������ �����Դϴ�." << endl;
	else
		cout << "�� ���� �����Դϴ�." << endl;


	//���� �߻�
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;

	cout << (rand() % 101 + 100) << endl;
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
	cin >> iUpgrade;

	//��ȭ ȭ���� ���Ѵ�.	
	float fPercent = rand() % 10000 / 100.f;

	//��ȭ Ȯ�� : ���׷��̵尡 0~3 : 100%���� 4~6 : 40% 7~9 : 10%
	//10~13 : 1%  14~15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;
	else if (iUpgrade > 3 && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (iUpgrade > 6 && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (iUpgrade > 9 && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (iUpgrade > 13 && iUpgrade <= 15) 
	{
		if (fPercent < 0.01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}


	return 0;
}