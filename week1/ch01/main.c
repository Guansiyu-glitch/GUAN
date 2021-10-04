
//#define_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
//栈的结构体
struct SStack
{
	void* data[MAX];//数组
	int m_Size;//栈的元素个数

};
typedef void* seqStack;
//初始化栈
seqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	if(stack==NULL)
	{
		return NULL;
	}
	//清空数组中的每个元素
	memset(stack->data, 0, sizeof(void*) * MAX);
	stack->m_Size = 0;
	return stack;
}
void push_SeqStack(seqStack stack, void* data)
{
	if(stack==NULL)
	{
		return;
	}
	if(data==NULL)
	{
		return;

	}
	struct SStack* myStack = stack;
	if(myStack->m_Size==MAX)
	{
		return;
	}
	myStack->data[myStack->m_Size] = data;//入栈 尾插
	myStack->m_Size++;//更新栈的大小

}
//出栈
void pop_SeqStack(seqStack stack)
{
	if(stack==NULL)
	{
		return;
	}
	//如果是在空栈，不执行出栈
	struct SStack* myStack = stack;
	if(myStack->m_Size <=0)
	{
		return;
	}
	myStack->data[myStack->m_Size  - 1] = NULL;


}
void* top_SeqStack(seqStack stack)
{
	if(stack==NULL)
	{
		return NULL;
	}
	struct SStack* myStack = stack;
	if(myStack->m_Size ==0)
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
//判断栈是否为空
	int isEmpty_SeqStack(seqStack stack)
	{
		if(stack==NULL)
	{
		return -1;//真
	}
	struct SStack* myStack = stack;
	if(myStack->m_Size <=0)
	{
		return 1;//真
	}
	return 0;//返回假， 代表不是空栈
	}

//销毁栈
void destroy_SeqStack(seqStack stack)
	{
		if(stack==NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
	}
//测试

	struct Person
	{
		char name[64];
		int age;
	};
	void test01()
	{
		//准备出数据
		struct Person p1 = { "aaa",19 };
		struct Person p2 = { "bbb",20 };
		
		struct Person p3 = { "ccc",18 };
		struct Person p4 = { "ddd",21 };
                //初始化栈
		seqStack stack = init_SeqStack();
                //入栈
		push_SeqStack(stack, &p1);
		push_SeqStack(stack, &p2);
		push_SeqStack(stack, &p3);
		push_SeqStack(stack, &p4);
		
		while (isEmpty_SeqStack(stack) == 0)//如果栈不为空 进行访问栈顶元素 并且出栈
		{
			struct Person * pTop = top_SeqStack(stack);//栈顶元素
			printf("栈顶元素 姓名：%s 年龄：%d\n", pTop->name, pTop->age);
			pop_SeqStack(stack);//出栈
		}
		//栈的大小
		int size = size_SeqStack(stack);
		printf("栈大小：%d\n", size);


		destroy_SeqStack(stack);//销毁
	}

	int main()
	{
		test01();
		system("pause");
		return EXIT_SUCCESS;


	}
