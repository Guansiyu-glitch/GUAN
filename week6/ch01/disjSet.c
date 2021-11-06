
#include <cstdlib>
#include <iostream>
#define NumSets 5000
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void initialize(DisjSet S);
void SetUnion(DisjSet S, SetType root1, SetType root2);
SetType Find(ElementType X, DisjSet S);

/*按高度求并，初始化为高度1用复数表示*/
void initialize(DisjSet S)
{
	int i;
	for (i = 0; i < NumSets; i++)
		S[i] = -1;
}


void SetUnion(DisjSet S, SetType root1, SetType root2)
{
	if (S[root1] < S[root2])
		S[root2] = root1;
	else
	{
		if (S[root1] == S[root2])
			S[root2] --;
		S[root1] = root2;
	}
}


/*路径压缩*/
SetType Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}
int main()
{
	DisjSet One;
	initialize(One);
	int i;
	SetType root1, root2;
	for (i = 10; i < 1000; i++)
	{
		root1 = Find(2 * i + 1, One);
		root2 = Find(3 * i + 1, One);
		SetUnion(One, root1, root2);
	}
	for (i = 0; i < 1000; i++)
		printf("%d : %d\n ", i, Find(i, One));
}
