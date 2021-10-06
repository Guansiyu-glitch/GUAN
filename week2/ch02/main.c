
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct BinaryNode
{
	char ch;//数据域
	struct BinaryNode* lChild;//左孩子结点
	struct BinaryNode* rChild;//右孩子结点
};
//利用递归特性，求二叉树叶子数目
void calculateLeafNum(struct BinaryNode* root, int* num)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*num)++;
	}
	calculateLeafNum(root->lChild, num);
	calculateLeafNum(root->rChild, num);
}
//求树的高度
int getTreeHeight(struct BinaryNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	//求左子树高度
	int lHeight = getTreeHeight(root->lChild);
	int rHeight = getTreeHeight(root->rChild);
	//取左右子树最大值加一
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
	return height;


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
	int num = 0;
	calculateLeafNum(&nodeA, &num);
	printf("叶子数量为：%d\n", num);

	int height = getTreeHeight(&nodeA);
		printf("树的高度为：%d\n", height);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}


