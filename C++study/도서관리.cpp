/*
도서관리 프로그램 만들기
1. 책 등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여금액, 책번호, 대여여부가 필요하다.
책목록을 선택하면 책 정보를 출력해준다.
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

		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 출력하세요 : ";
		int iMENU;
		cin >> iMENU;

		if (cin.fail())
		{
			//에러버퍼를 비워준다.
			cin.clear();

			//입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.
			//첫번째에는 검색하고자 하는 버퍼 크기를 지정한다. 넉넉하게 1024바이트정도 지정
			//두번째는 착조가 하는 문자를 넣어준다. 그래서 입력버퍼 처음부터 \n이 있는 곳까지 찾아서
			//그 부분을 모두 지워줘서 다시 입력받을수 있도록 해준다.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMENU == MENU_EXIT)
			break;

		switch (iMENU)
		{
		case MENU_INSERT:
			system("cls");
			cout << "==========도서 등록==========" << endl;

			if (iBookCount >= Book_MAX)
				break;

			//getline은 엔터를 인식하므로 이를 무시하기위해 ignore 해준다.
			cin.ignore(1024, '\n');

			cout << "책 이름 : ";
			cin.getline(Bookarr[iBookCount].strName, NAME_SIZE);
			cout << "대여 여부 : ";
			cin.getline(Bookarr[iBookCount].strExist, EXIST_SIZE);
			cout << "대여 금액 : ";
			cin >> Bookarr[iBookCount].iMoney;

			Bookarr[iBookCount].iNumber = iBookNumber;

			++iBookCount;
			++iBookNumber;

			cout << "도서 추가 완료" << endl;

			break;

		case MENU_LENDING:
			system("cls");

			cout << "==========도서 대여==========" << endl;

			cin.ignore(1024, '\n');
			cout << "대여 할 도서의 이름을 입력하세요 : " << endl;
			cin.getline(strBookName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(Bookarr[i].strName, strBookName) == 0)
				{
					cout << strBookName << "가 대여 완료 되었습니다." << endl;

					
					cout << "대여 가능 여부를 수정해주세요. : " << endl;
					cin.getline(Bookarr[i].strExist, EXIST_SIZE);
				}

				else
				{
					cout << "원하시는 책을 찾지 못했습니다." << endl;
				}
			}

			break;

		case MENU_RETURN:
			system("cls");
			cout << "==========도서 반납==========" << endl;

			cin.ignore(1024, '\n');
			cout << "반납할 도서의 이름을 입력하세요 : " << endl;
			cin.getline(strBookName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(Bookarr[i].strName, strBookName) == 0)
				{
					cout << strBookName << " 가 반납 완료 되었습니다." << endl;

					cout << "대여가능 여부를 수정해주세요 : " << endl;
					cin.getline(Bookarr[i].strExist, EXIST_SIZE);
				}
			}

			break;

		case MENU_OUTPUT:
			system("cls");
			cout << "==========도서 목록==========" << endl;

			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "도서 이름 : " << Bookarr[i].strName << endl;
				cout << "도서 금액 : " << Bookarr[i].iMoney << endl;
				cout << "도서 번호 : " << Bookarr[i].iNumber << endl;
				cout << "대여 여부 : " << Bookarr[i].strExist << endl << endl;
				
			}
			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;		
		}
		system("pause");
	}
	return 0;
}