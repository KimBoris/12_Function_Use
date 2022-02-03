#include <stdio.h>
#include <stdlib.h>
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

int* TestFunc(void)
{//함수가 반환하면 소멸할 자동변수의 주소를 반환한다.
	int nData = 10;
	return &nData;
}

int main(int argc, char* argv[])
{
	int* pnResult = NULL;
	pnResult = TestFunc();

	//포인터가 가리키는 대상 메모리는 유효하지 않은 메모리이다.

	printf("%d\n", *pnResult);
	return 0;
}

//이 코드의 가장 큰 문제점 . 함수 내부에 선언된 자동변수의 주소를 반환하는 것
//자동변수는 스택영역을 사용하며 스택은 스코프가 닫히면 그 내부에서 선언된 것들이 사실상 사라진다고 봐야한다.
//곧 사라질 자동변수의 주소를 반화하고 있는데 이 예제를 빌드하면 경고메세지가 뜬다.
//warning C4172 : 지역변수 또는 임시 변수의 주소를 반환하고 있습니다.

//이러한 잘못에도 불구하고 사라진 대상 메모리에 간접 지정 연산으로 접근해도 별 다른 문제가 없어 보인다는 점.
//이와 같은 현상이 벌어진 이유 = 스택메모리가 정말로 사라지거나 해제되는 것이 아니라 가용범위가 줄어든것(지정해제)에 불과하기 때문이다.