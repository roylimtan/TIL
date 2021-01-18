#include <iostream>

#define NAME_SIZE 32

using namespace std;

/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능이다.
사용자정의 변수 타입이다.
형태 : struct 구조체 명 {}; 의 형태로 구성된다.
배열과 구조체의 공통점
1. 데이터 집합이다.
2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다.
*/
struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	//구조체 전체를 0으로 초기화
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	//구조체 멤버에 접근할때는 . 을 이용하여 접근하게 된다.
	tStudent.iKor = 100;

	//문자열을 배열에 넣어줄때는 단순 대입으로는 불가능하다.
	//strcpy_s라는 함수를 이용해서 문자열을 복사해주어야한다.
	//이 함수는 오른족에 있는 문자열을 왼쪽으로 복사해준다.
	strcpy_s(tStudent.strName, "가나다라 ASDF");
	
	//strcat_s함수는 문자열을 붙여주는 기능이다.
	//오른쪽에 있는 문자열을 왼쪽에 붙여준다. strName에는 위에서 저장해둔 이름 뒤에 오른쪽
	//문자열을 붙여서 만들어준다.
	strcat_s(tStudent.strName, "문자열 붙이기");

	//strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고 다를경우 0이 아닌값을 반환한다.
	strcpy_s(tStudent.strName, "홍길동");

	cout << "비교할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "학생을 찾았습니다." << endl;
	}
	else
		cout << "찾는 학생이 없습니다." << endl;

	//한글은 2byte 띄어쓰기는 1byte 영어는 1byte
	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;
	cout << "이름 : " << tStudent.strName << endl;

	/*
	문자열의 끝은 항상0(NULL)로 끝나야 한다. 그런데 쓰레기값이 들어가있는 상태에서 
	tStudent.strNmae[0] = 'a'; 처럼 각 배열 요소에 값을 넣어주게 되면 그 값이 출력되고
	넣어주지 않은 부분은 쓰레기값으로 그대로 출력된다. 왜냐하면 출력할대
	문자열의 끝을 인식할 수 없기 때문이다. 0이 들어가야 하는데 쓰레기값이 들어가기 때문이다.
	*/

	return 0;
}