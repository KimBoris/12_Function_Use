#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//
////Call By Value - 매개변수에 값을 집어 넣는것
//int Add(int a, int b)
//{
//	return a + b;
//}
////Call By Reference - 매개변수가 주소가 들어가는 것
//int Add2(int* a, int* b)
//{
//	return *a + *b;
//}
//
//int main(int argc, char* argv[])
//{
//	int x = 3, y = 4;
//	printf("%d\n", Add(3, 4));
//	printf("%d\n", Add2(&x, &y));
//	return 0;
//}



//codedevgood01.c

//배열 실인수는 '포인터' 매개변수로 받는다ㅏ.
//포인터에는 요소의 개수 정보가 없으므로 int매개변수가 더 필요하다
//만일 입력받아야 할 정수의 개수가 달라져도 이 함수 코드는 변하지 않는다.
//void InitList(int* pList, int nSize)
//{
//	int i = 0;
//	for (i = 0; i < nSize; ++i)
//	{
//		printf("정수를 입력하세요 : ");
//		scanf_s("%d", &pList[i]);
//	}
//}
//
////요소가 int형식인 배열이라면 요소의 개수와 상관없이 정렬할 수 있다!
//void SortList(int* pList, int nSize)
//{
//	int i = 0, j = 0, nTmp = 0;
//	for (i = 0; i < nSize - 1; ++i)
//	{
//		for (j = i + 1; j < nSize; j++)
//		{
//			if (pList[j] < pList[i])
//			{
//				nTmp = pList[j];
//				pList[j] = pList[i];
//				pList[i] = nTmp;
//			}
//		}
//	}
//}
//
//void PrintList(int* pList, int nSize)
//{
//	int i = 0;
//	for (i = 0; i < nSize; ++i)
//	{
//		printf("%d\t", pList[i]);
//		putchar('\n');
//	}
//}
//int main(void)
//{
//	//자료구조를 지역변수로 선언했기 때문에 
//	//다른 함수에서는 직접 접근할 수 없다.
//	int aList[5] = { 0 };
//
//	InitList(aList, 5);
//	SortList(aList, 5);
//	PrintList(aList, 5);
//
//	return 0;
//}


//
//char* GetName(void)
//{
//	char* pszName = NULL;
//
//	//메모리 동적할당
//	pszName = calloc(32, sizeof(char));
//	printf("이름을 입력하세요 : ");
//
//	//동적 할당한 메모리에 사용자가 입력한 문자열을 저장한다.
//	gets_s(pszName, sizeof(char) * 32);
//	//동적 할당한 메모리의 주소를 호출자 함수에 반환한다.
//	return pszName;
//}
////반환형식도 포인터인데 
////1. 콜리함수에서 메모리를 동적할당하고
////2. 콜러쪽에서 해제하는 독특한 방식이다.
//
//int main(int argc, char* argv[])
//{
//	char* pszName = NULL;
//
//	//이름이 저장된 동적할당된 메모리의 주소를 반환
//	pszName = GetName();
//	printf("당신의 이름은 %s입니다.\n", pszName);
//
//	//호출자 함수가 해제해야한다
//	free(pszName);
//	return 0; 
//	//메모리를 할당하고 해제하는것이 그때그떄 다를 수 있다.
//}









//
////Swap함수
////매개변수로 주소를 받는다.
//void Swap(int* pLeft, int* pRight)
//{
//	//주소가 가리키는 대상의 메모리 값을 교환한다.
//	int nTmp = *pLeft;
//	*pLeft = *pRight;
//	*pRight = nTmp;
//}
//
//
//
//
////<<<<<EX>>>>>>
//void TestFunc(int* pnParam)//pnParam = 0x00EFF9E4  b8 fa ef 00
//{
//	*pnParam = 10;
//}
//int main(void)
//{
//
//	int a = 10; 
//	int b = 20;
//	Swap(&a, &b);
//	 
//	printf("%d, %d\n", a, b );
//
//	int nData = 0;//0x00EFFAB8
//	TestFunc(&nData);
//
//	printf("%d\n", nData);
//	return 0;
//}




//필수 실습문제
//문자열을 복사하는 함수 만들기
//메모리의 주소 두 개를 매개변수로 받아 문자열을 복사(deep copy)하는 함수인
//MyStrcpy()함수를 작성한다. main()함수의 코드와 실행결과가 다음과 같을 때, 정상적으로 작동할 수 있도록 구현한다.
//기능적으로 MyStrcpy()함수는 strcpy()혹은 strcpy_s와 같다.
//
//char* Mystrcpy(char* a, const char* b)
//{
//	char* origin;
//	for (origin = a; *a = *b; a++, b++);
//	return origin;
//}
//
//char* MyStrcpy2(char* destination, const char* source)
//{
//	while (*source != '\0')
//	{
//		*destination = *source;
//		source++;
//		destination++;
//	}
//	*destination = '\0';
//
//	return destination;
//}
//
//
//
////지역변수이고 자동변수이기때문에 스코프를 벗어나면 사라진다.
//int* TestFunc(void)
//{
//	int nData = 10;
//	return &nData;
//}
//
//
//
//int main(int argc, char* argv[])
//{
//	//2. 분명 지역변수인데 값이 10으로 나온다 
//	//스코프를 벗어나면 사라지는것이라고 했지만 why?
//
//	printf("%d\n", *TestFunc());
//	
//	/*1.
//	char szBufferSrc[12] = { "TestString" };
//	char szBufferDst[12] = { 0 };
//
//	puts(szBufferSrc);
//	MyStrcpy2(szBufferDst, szBufferSrc);
//	puts(szBufferDst);
//
//*/
//	return 0;
//}



//사라질 메모리를 반환하는 것은 완전 창피한 일이다.
//badfuncion01.c

//int* TestFunc(void)
//{//함수가 반환하면 소멸할 자동변수의 주소를 반환한다.
//	int nData = 10;
//	return &nData;
//}
//
//int main(int argc, char* argv[])
//{
//	int* pnResult = NULL;
//	pnResult = TestFunc();
//
//	//포인터가 가리키는 대상 메모리는 유효하지 않은 메모리이다.
//
//	printf("%d\n", *pnResult);
//	return 0;
//}

//이 코드의 가장 큰 문제점 . 함수 내부에 선언된 자동변수의 주소를 반환하는 것
//자동변수는 스택영역을 사용하며 스택은 스코프가 닫히면 그 내부에서 선언된 것들이 사실상 사라진다고 봐야한다.
//곧 사라질 자동변수의 주소를 반화하고 있는데 이 예제를 빌드하면 경고메세지가 뜬다.
//warning C4172 : 지역변수 또는 임시 변수의 주소를 반환하고 있습니다.

//이러한 잘못에도 불구하고 사라진 대상 메모리에 간접 지정 연산으로 접근해도 별 다른 문제가 없어 보인다는 점.
//이와 같은 현상이 벌어진 이유 = 스택메모리가 정말로 사라지거나 해제되는 것이 아니라 가용범위가 줄어든것(지정해제)에 불과하기 때문이다.





//<<<<스택 프레임 그리는 방법>>>>>
//- 스택과 메모리는 반대로 그린다.
//스택의 왼쪽 - 함수의 이름, 스코프의 시작지점
//       오른쪽 - 식별자 이름
//
// ex) 메모리 주소가 늘어났다 = 스택이 줄어듬
//	   메모리 주소가 줄어듬 = 스택이 늘어남

//1. 스택은 위로 주소는 아래로
//2. 스택은 아래서부터 쌓는다.
//3. 선언한 변수 순서대로 스택에 그려서 표시한다.
//데이터를 넣는다 = push
//데이터는 끄집어낸다 = pop

//NULL로 초기화한 경우 그냥 NULL이라고 쓰고 선을 그어 표시하지 않는다.
//NULL포인터는 아무것도 가르키지 않음을 의미하기 때문에

//*[배열 인덱스는 아래로 증가하게 그린다]

//stackframe03.c
//int main(int argc, char* argv[])
//{
//	int aList[3] = { 10, 20 , 30 };
//	int* pnData = aList;
//	*(pnData + 1) = 100;
//	return 0;
//}
/*
위 식을 그림으로 표현하면


[aLIst] *pnData	  |	주소
[ 1 0 ]	aList[0]  |
[ 2 0 ]	[1]		  |
[ 3 0 ]	[2]		  |
------------------|
				  |stack
				  */
//스택은 감소
//주소는 증가하니까 


//*[동적 할당된 메모리는 따로 표시한다]

//stackframe04.c

//int main(int argc, char* argv[])
//{
//	int nData = 10;
//	char* pszBuffer = NULL;
//
//	pszBuffer = (char*)malloc(12);
//	strcpy(pszBuffer, "Hello");
//	free(pszBuffer);
//	return 0;
//}



//******진짜 중요******
//[매개변수는 오른쪽부터 스택에 그리며 새 스코프는 기존 스택위에 그린다.]
//- 매개 변수도 스택에 그려야 하는데 반드시 오른쪽 매개변수부터 먼저 Push하는 것으로 그린다.
//함수 호출 규칙(call convension)마다 다를 수 있다.

//stackframe05.c

//int Add(int a, int b)
//{
//	int nResult = 0;
//	nResult = a + b;
//	return nResult;
//}
//
//int main(int argc, char* argv[])
//{
//	int nResult = 0;
//	nResult = Add(3, 4);
//	return 0;
//}


//Add함수 스코프에 nResult = a+b가 실행되기 전.
/*
				|			|주소
				|			|
				|	[0]		|nResult
----------------|	[3]		|a
ADD()			|	[4]		|b
----------------|-----------|
main()			|  [ 0 ]	| nResult
----------------------------|
							|
							stack
				*/

//함수가 함수를 호출해 함수 몸체에 대한 스코프가 형성되면
//스택에 가로선을 길게 그어 표시한다.

//중요한 것은 7번 행에 의해 피 호출자 함수가 반환하면 return nResult;
//함수의 몸체에 해당하는 스코프를 모두 닫아야 한다.
//즉 Add()함수 호출 전과 같은 상태로 되돌린다.
//그리고 피 호출자 함수가 호출자에 반환하는 값도 별도로 표시한다. 

//식별자 검색순서는 위에서 아래로
//ex

int main(void)
{
	int nInput = 0;
	scanf_s("%d", &nInput);

	if (nInput > 10)
	{
		int nInput = 20;
		printf("%d\n", nInput);
		if (nInput < 20)
		{
			int nInput = 30;
			printf("%d\n", nInput);
		}
	}
	printf("%d\n", nInput);
	return 0;
}

//위식은 스택에 
//[30]
//[20]
//[10] 으로 쌓이지만 스코프가 닫히면 30, 20 은 삭제되고
//372식의 값은 10으로 출력된다. 
//식별자 순서는 위에서 아래로

//정적변수는 스택에 그리지 않는다.
//따라서, 따로 빼서 그려라
