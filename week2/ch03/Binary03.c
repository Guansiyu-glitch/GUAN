#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
//用到之前写的关于顺序栈的代码
struct SStack
{
	void* data[MAX];
	int m_Size;

};
typedef void* seqStack;
seqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	if (stack == NULL)
	{
		return NULL;
	}
	memset(stack->data, 0, sizeof(void*) * MAX);
	stack->m_Size = 0;
	return stack;
}
void push_SeqStack(seqStack stack, void* data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;

	}
	struct SStack* myStack = stack;
	if (myStack->m_Size == MAX)
	{
		return;
	}
	myStack->data[myStack->m_Size] = data;
	myStack->m_Size++;

}
void pop_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct SStack* myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return;
	}
	myStack->data[myStack->m_Size - 1] = NULL;


}
void* top_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct SStack* myStack = stack;
	if (myStack->m_Size == 0)
	{
		return NULL;

	}
	return myStack->data[myStack->m_Size - 1];

}
int size_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	return myStack->m_Size;
}
int isEmpty_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return 1;
	}
	return 0;
}

void destroy_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}
struct Person
{
	char name[64];
	int age;
};
//二叉树的非递归遍历
/*思路：
1.将根节点压入栈中
2.只要 栈size>0,执行循环
  2.1拿出栈顶元素
  2.2如果栈顶元素标志为真 直接输出 执行下一次循环
  2.3如果不为真 ，该flag标志为真
  2.4将 右子节点 和左子节点 和根入栈
  2.5执行下一次循环
*/
struct BinaryNode
{
	char ch;//数据域
	struct BinaryNode* lChild;//左孩子结点
	struct BinaryNode* rChild;//右孩子结点
	//标示
	int flag;
};
void  nonRecurion(struct BinaryNode* root)
{
	//初始化栈
	seqStack myStack = init_SeqStack();
	push_SeqStack(myStack, root);
	while (size_SeqStack(myStack) > 0)
	{
		//获取栈顶元素
		struct BinaryNode* topNode = top_SeqStack(myStack);
		//弹出栈顶
		pop_SeqStack(myStack);
		if(topNode->flag==1)
		{
			printf("%c", topNode->ch);
			continue;
		}
		//如果不是真，将flag改为真
		topNode->flag = 1;
		//将右子结点和左子节点和根入栈
		if (topNode->rChild != NULL)
		{
			push_SeqStack(myStack, topNode->rChild);
		}
		if (topNode->lChild != NULL)
		{
			push_SeqStack(myStack, topNode->lChild);

		}
		push_SeqStack(myStack, topNode);
	}
	 detroy_SeqStack(myStack);
	 myStack = NULL;
}
void test03()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL ,0};
	struct BinaryNode nodeB = { 'B',NULL,NULL ,0};
	struct BinaryNode nodeC = { 'C',NULL,NULL ,0};
	struct BinaryNode nodeD = { 'D',NULL,NULL ,0 };
	struct BinaryNode nodeE = { 'E',NULL,NULL ,0};
	struct BinaryNode nodeF = { 'F',NULL,NULL ,0 };
	struct BinaryNode nodeG = { 'G',NULL,NULL ,0};
	struct BinaryNode nodeH = { 'H',NULL,NULL ,0 };
	//建立结点关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;
	nonRecursion(&nodeA);
}
int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
