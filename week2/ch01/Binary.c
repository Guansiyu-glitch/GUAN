//二叉树的递归遍历
//#define_CRT_SECURE_NO_WARNINGS;
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct BinaryNode
{
	char ch;//数据域
	struct BinaryNode* lChild;//左孩子结点
	struct BinaryNode* rChild;//右孩子结点
};
//递归遍历函数
void recursion(struct BinaryNode* root)
{
	if(root==NULL)
	{
		return;

	}
	//先序遍历DLR
	/*printf("%c", root->ch);
	recursion(root->lChild);
	recursion(root->rChild);*/
	//中序遍历LDR
	recursion(root->lChild);
	recursion(root->rChild);
	//后序遍历LRD
	recursion(root->lChild);
	recursion(root->rChild);
	printf("%c", root->ch);

}
void test01()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL };
	struct BinaryNode nodeB = { 'B',NULL,NULL };
	struct BinaryNode nodeC = { 'C',NULL,NULL };
	struct BinaryNode nodeD = { 'D',NULL,NULL };
	struct BinaryNode nodeE = { 'E',NULL,NULL };
	struct BinaryNode nodeF = { 'F',NULL,NULL };
	struct BinaryNode nodeG = { 'G',NULL,NULL };
	struct BinaryNode nodeH = { 'H',NULL,NULL };
	//建立结点关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;
	recursion(&nodeA);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
