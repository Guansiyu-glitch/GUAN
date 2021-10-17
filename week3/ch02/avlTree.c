#include<stdio.h>
#include<stdlib.h>
typedef struct TressNode {
	int data;
	int height;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
int getHeight(TreeNode* node)
{
	return node ? node->height : 0;

}
//求最大值
int max(int a, int b) 
{
	return a > b ? a : b;
}
//调整函数(右右旋）
void rrRotation(TreeNode* node, TreeNode** root) {
	TreeNode* temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	//旋转后调整高度
	node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
	temp->height = max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
	*root = temp;

}
//左左旋
void llRotation(TreeNode* node, TreeNode** root) {
	TreeNode* temp = node->lchild;
	node->rchild = temp->rchild;
	temp->rchild = node;//父亲成为右孩子

	node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
	temp->height = max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
	*root = temp;
}


void avlInsert(TreeNode** T, int data) {
	if (*T == NULL) {
		*T = (TreeNode*)mallloc(sizeof(TreeNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else if (data < (*T)->data) {
		avlInsert(&(*T)->lchild, data);
		//拿到当前节点左右子树的高度
		int lHeight = getHeight((*T)->lchild);
		int rHeight = getHeight((*T)->rchild);
		//判断高度差
		if (lHeight - rHeight == 2) {
			if (data < (*T)->lchild->data) {
				//LL调整
				llRotation(*T, T);

			}
			else {
				//LR调整
				rrRotation((*T)->lchild, &(*T)->lchild);
				llRotation(*T, T);
			}
		}
      }
	else if (data > (*T)->data) {
		avlInsert(&(*T)->rchild, data);

		//拿到当前节点左右子树的高度
		int lHeight = getHeight((*T)->lchild);
		int rHeight = getHeight((*T)->rchild);
		//判断高度差
		if (rHeight - lHeight == 2) {
			if (data > (*T)->rchild->data) {
				//RR调整
				rrRotation(*T, T);
			
			else 
			{
				//RL调整
				llRotation((*T)->rchild, &(*T)->rchild);
				rrRotation(*T, T);
			}
		}
	}
	(*T)->height = max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
}
//前序遍历
void preOrde(TreeNode* T){
	if (T) {
		printf("%d", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
int main() {
	TreeNode* T = NULL;
	int nums[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		avlInsert(&T, nums[i]);

	}
	preOrder(T);
	printf("\n");
}
