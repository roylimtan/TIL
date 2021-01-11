#include <iostream>

using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다.
enum 열거체 명 {} 의 형태로 구성된다.
열거체 명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
즉, 열거체 자체가 사용자정의 변수 타입이 될 수도 있다.
열거체는 숫자에 이름을 붙여주는 기능이다.
*/
enum NUM
{
	NUM_0 = 10, //아무것도 부여하지 않을 경우  
	NUM_1, //->11
	NUM_2 = 0x0010,
	NUM_3 //-> 17
};

#define NUM_4 4

int main()
{
	/*
	switch문 : 분기문의 한 종류이다. if문이 조건을 체크하는 분기문이라면
	switch문은 값이 뭔지를 체크하는 분기문이다.
	형태 : switch(변수) {} 의 형태로 구성된다.
	코드블럭 안에는 case break 구문이 들어가게 된다.
	case상수 : 의 형태로 처리가 되고 변수 값이 무엇인지에 따라서 case뒤에오는 상수를 비교하게 된다.
	*/
	int iNumber;
	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	switch (iNumber)
	{
	case 1: //iNumber값이 무엇인지에 딸나서 실행되는 case 구문이 결정된다.
		cout << "입력한 숫자는 1입니다." << endl;
		break; //break를 만나게 되면 switch문을 빠져나가게 된다.
	case 2:
		cout << "입력한 숫자는 2입니다." << endl;
		//여기처럼 break가 없을 경우 바로 아래에 있는 case구문도 강제로 실행되게 된다.
	case 3:
		cout << "입력한 숫자는 3입니다." << endl;
		break;

	case NUM_4:
		cout << "입력한 숫자는 4     입니다" << endl;
		break;

	default: //case 로 지정되어 있지 않은 숫자가 들어올 경우 실행된다.
		cout << "그 외의 숫자입니다." << endl;
		break;
	}
	//열거체 타입의 변수를 선언했다.
	//열거체 타입 변수는 무조건 4byte를 차지하게 된다.
	//열거체에 나열된 값들 안에서 선택해서 사용한다.
	NUM		eNUM;

	//sizeof(타입 or 변수)를 하게 되면 해당 타입 혹은 변수의 메모리 크기를 구해준다.
	cout << sizeof(NUM) << endl;
	//typeid(타입 or 변수).name()을 하게 되면 typeid 안에 들어간 타입 혹은 변수의 타입을 문자열로 반환해준다.
	cout << typeid(eNUM).name() << endl;


	return 0;
}