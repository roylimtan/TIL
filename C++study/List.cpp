
#include "List.h"

void OutputStudent(const PSTUDENT pStudent)
{
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
}

void InitList(PLIST pList)
{
	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;
	//시작노드의 다음노드는 마지막 노드이다.
	pList->pBegin->pNext = pList->pEnd;
	//마지막노드의 이전 노드는 시작노드이다.
	pList->pEnd->pPrev = pList->pBegin;
	//마지막 노드의 다음 노드는 없으므로 NULL로 해준다.
	pList->pEnd->pNext = NULL;
	//시작노드의 이전 노드는 없으므로 NULL로 해준다.
	pList->pBegin->pPrev = NULL;
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList)
{
	system("cls");
	cout << "========================= 학생 추가 =========================" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번 : ";
	tStudent.iNumber = InputInt();

	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	//새로 추가되는 노드는 End노드의 이전노드와 End노드 사이에 추가해야 한다.
	//그래서 pEnd의 prev 노드를 구해놓는다.
	PNODE pPrev = pList->pEnd->pPrev;

	//pEnd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pPrev->pNext = pNode;

	//추가할 노드의 이전 노드로 End의 이전 노드를 지정한다.
	pNode->pPrev = pPrev;

	//새로 추가할 노드의 다음 노드를 pEnd에 연결한다.
	pNode->pNext = pList->pEnd;

	//pEnd노드의 이전 노드로 새로 추가할 노드를 지정한다.
	pList->pEnd->pPrev = pNode;

	++pList->iSize;
}

void Push_Front()
{
}

void Output(PLIST pList)
{
	int iMenu;

	while (true)
	{
		system("cls");
		cout << "========================= 학생 출력 =========================" << endl;
		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();

		if (iMenu > OT_NONE&& iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu)
	{
	case OT_OUTPUT:
		//추가되는 노드들은 begin 과 end 사이에 배치된다. 그러므로 begin의 다음 노드를 얻어온다.
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		//역방향으로 출력을 할때는 end의 이전 노드를 얻어오고 계속 이전노드로 진행한다. begin과 같아질 경우 반복을 종료한다.
		pNode = pList->pEnd->pPrev;

		while (pNode != pList->pBegin)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}

	cout << "학생수 : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "========================= 학생 탐색 =========================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "학생을 찾을 수 없습니다." << endl;
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "========================= 학생 삭제 =========================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << "학생을 삭제하였습니다." << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "삭제할 대상을 찾을 수 없습니다." << endl;
	system("pause");
}