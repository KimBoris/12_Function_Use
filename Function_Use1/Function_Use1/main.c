#include <stdio.h>
#include <stdlib.h>
//
//
////Call By Value - �Ű������� ���� ���� �ִ°�
//int Add(int a, int b)
//{
//	return a + b;
//}
////Call By Reference - �Ű������� �ּҰ� ���� ��
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

//�迭 ���μ��� '������' �Ű������� �޴´٤�.
//�����Ϳ��� ����� ���� ������ �����Ƿ� int�Ű������� �� �ʿ��ϴ�
//���� �Է¹޾ƾ� �� ������ ������ �޶����� �� �Լ� �ڵ�� ������ �ʴ´�.
//void InitList(int* pList, int nSize)
//{
//	int i = 0;
//	for (i = 0; i < nSize; ++i)
//	{
//		printf("������ �Է��ϼ��� : ");
//		scanf_s("%d", &pList[i]);
//	}
//}
//
////��Ұ� int������ �迭�̶�� ����� ������ ������� ������ �� �ִ�!
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
//	//�ڷᱸ���� ���������� �����߱� ������ 
//	//�ٸ� �Լ������� ���� ������ �� ����.
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
//	//�޸� �����Ҵ�
//	pszName = calloc(32, sizeof(char));
//	printf("�̸��� �Է��ϼ��� : ");
//
//	//���� �Ҵ��� �޸𸮿� ����ڰ� �Է��� ���ڿ��� �����Ѵ�.
//	gets_s(pszName, sizeof(char) * 32);
//	//���� �Ҵ��� �޸��� �ּҸ� ȣ���� �Լ��� ��ȯ�Ѵ�.
//	return pszName;
//}
////��ȯ���ĵ� �������ε� 
////1. �ݸ��Լ����� �޸𸮸� �����Ҵ��ϰ�
////2. �ݷ��ʿ��� �����ϴ� ��Ư�� ����̴�.
//
//int main(int argc, char* argv[])
//{
//	char* pszName = NULL;
//
//	//�̸��� ����� �����Ҵ�� �޸��� �ּҸ� ��ȯ
//	pszName = GetName();
//	printf("����� �̸��� %s�Դϴ�.\n", pszName);
//
//	//ȣ���� �Լ��� �����ؾ��Ѵ�
//	free(pszName);
//	return 0; 
//	//�޸𸮸� �Ҵ��ϰ� �����ϴ°��� �׶��׋� �ٸ� �� �ִ�.
//}









//
////Swap�Լ�
////�Ű������� �ּҸ� �޴´�.
//void Swap(int* pLeft, int* pRight)
//{
//	//�ּҰ� ����Ű�� ����� �޸� ���� ��ȯ�Ѵ�.
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




//�ʼ� �ǽ�����
//���ڿ��� �����ϴ� �Լ� �����
//�޸��� �ּ� �� ���� �Ű������� �޾� ���ڿ��� ����(deep copy)�ϴ� �Լ���
//MyStrcpy()�Լ��� �ۼ��Ѵ�. main()�Լ��� �ڵ�� �������� ������ ���� ��, ���������� �۵��� �� �ֵ��� �����Ѵ�.
//��������� MyStrcpy()�Լ��� strcpy()Ȥ�� strcpy_s�� ����.
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
////���������̰� �ڵ������̱⶧���� �������� ����� �������.
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
//	//2. �и� ���������ε� ���� 10���� ���´� 
//	//�������� ����� ������°��̶�� ������ why?
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



//����� �޸𸮸� ��ȯ�ϴ� ���� ���� â���� ���̴�.
//badfuncion01.c

int* TestFunc(void)
{//�Լ��� ��ȯ�ϸ� �Ҹ��� �ڵ������� �ּҸ� ��ȯ�Ѵ�.
	int nData = 10;
	return &nData;
}

int main(int argc, char* argv[])
{
	int* pnResult = NULL;
	pnResult = TestFunc();

	//�����Ͱ� ����Ű�� ��� �޸𸮴� ��ȿ���� ���� �޸��̴�.

	printf("%d\n", *pnResult);
	return 0;
}

//�� �ڵ��� ���� ū ������ . �Լ� ���ο� ����� �ڵ������� �ּҸ� ��ȯ�ϴ� ��
//�ڵ������� ���ÿ����� ����ϸ� ������ �������� ������ �� ���ο��� ����� �͵��� ��ǻ� ������ٰ� �����Ѵ�.
//�� ����� �ڵ������� �ּҸ� ��ȭ�ϰ� �ִµ� �� ������ �����ϸ� ���޼����� ���.
//warning C4172 : �������� �Ǵ� �ӽ� ������ �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�.

//�̷��� �߸����� �ұ��ϰ� ����� ��� �޸𸮿� ���� ���� �������� �����ص� �� �ٸ� ������ ���� ���δٴ� ��.
//�̿� ���� ������ ������ ���� = ���ø޸𸮰� ������ ������ų� �����Ǵ� ���� �ƴ϶� ��������� �پ���(��������)�� �Ұ��ϱ� �����̴�.