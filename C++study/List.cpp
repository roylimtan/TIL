
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

void Sort(PLIST pList)
{
	system("cls");
	cout << "========================= 학생 정렬 =========================" << endl;
	cout << "1. 학번 기준" << endl;
	cout << "2. 평균 기준" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput <= ST_NONE || iInput > ST_AVG)
	{
		cout << "잘못 입력하였습니다." << endl;
		system("pause");
		return;
	}

	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;

	//First는 End의 이전 노드와 같아지게 되면 더이상 비교할 노드가 없으므로 종료한다.
	while (pFirst != pList->pEnd->pPrev)
	{
		 //Second는 무조건 First 노드 다음 노드부터 검사를 시작한다.
		pSecond = pFirst->pNext;

		//Second는 End 이전 까지 반복해야 하므로 End가 아닐동안만 반복한다.
		while (pSecond != pList->pEnd)
		{
			bool bSwap = false;

			switch (iInput)
			{
			case ST_NUMBER:
				if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
					bSwap = true;
				break;
			case ST_AVG:
				if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
					bSwap = true;
				break;
			}

			//bool변수 bSwap이 true일 경우 두 노드를 바꿔야 한다는 것이다.
			if (bSwap)
			{
				//First 노드의 이전과 다음노드를 저장한다.
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				//Second 노드의 이전과 다음노드를 저장한다.
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;	

				// 위에서 두 노드가 서로 바꼈으므로 연결되어있던 pNext와 pPrev도 바꿔주어야 한다.
				//그래서 pFirstPrev 노드의 다음노드로 바뀐 pFirst를 지정하고 바뀐 pFirst의 이전 노드로 pFirstPrev노드를 지정해준다.
				//다음 노드들도 마찬가지로 교체해주어야 한다.
				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;


				//바꾸려는 두 노드가 붙어있지 않은 경우
				if (pSecond != pFirstNext)
				{
					pFirstNext->pPrev = pSecond;
					pSecond->pNext = pFirstNext;

					pSecondPrev->pNext = pFirst;
					pFirst->pPrev = pSecondPrev;
				}
				
				//노드가 붙어있다면
				else
				{
					pSecond->pNext = pFirst;
					pFirst->pPrev = pSecond;
				}

				pSecondNext->pPrev = pFirst;
				pFirst->pNext = pSecondNext;

				//두 노드를 바꿔준다.
				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;
			}
			pSecond= pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}
	cout << "정렬이 완료되었습니다." << endl;
	system("pause");
}