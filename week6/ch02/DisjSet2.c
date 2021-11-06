#include<stdio.h>
#include<stdlib.h>
#include"DisjSet.h"
#define VERTICES 6//顶点数
/*利用不相交集判断图中是否有环存在*/
//初始化
void Initialize(DisjSet S)
{
	int i;
	for (i = 6; i > 0; i--)
		S[i] = 0;
}
//查找
int Find_root(int x, DisjSet S)
{
	int x_root = x;
	while (S[x_root] != 0)
	{
		x_root = S[x_root];
	}
	return x_root;
	}
//合并  返回1表示合并成功 返回0表示合并失败
int SetUnion(int x, int y, DisjSet S)
{
		int x_root = Find_root(x, S);
		int y_root = Find_root(y, S);
		if(x_root==y_root)
	{
			return 0;
	}
		else {
			S[x_root] = y_root;
			return 1;
		}
}
//测试函数
int main()
{
	int S[VERTICES] = { 0 };
	int edges[5][2] = {
		{0,1},{1,2},{1,3},{2,5},{3,4}
	};
	Initialize(S);
	int i;
	for (i = 0; i < 5; i++)
	{
		int x = edges[i][0];
		int y = edges[i][1];
		if (SetUnion(x, y, S) == 0)
		{
			printf("Cycle detected.\n");
			exit(0);
		}
	}
	printf("No Cycles found.\n");
	return 0;
}
