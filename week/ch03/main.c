
//#define_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
struct SStack
{
	void* data[MAX];
	int m_Size;

};
typedef void* seqStack;
seqStack init_SeqStack()
{
	struct SStack* stack = malloc(sizeof(struct SStack));
	if(stack==NULL)
	{
		return NULL;
	}
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
	myStack->data[myStack->m_Size] = data;
	myStack->m_Size++;

}
void pop_SeqStack(seqStack stack)
{
	if(stack==NULL)
	{
		return;
	}
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
	int isEmpty_SeqStack(seqStack stack)
	{
		if(stack==NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	if(myStack->m_Size <=0)
	{
		return 1;
	}
	return 0;
	}

void destroy_SeqStack(seqStack stack)
	{
		if(stack==NULL)
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
	void test01()
	{
		struct Person p1 = { "aaa",19 };
		struct Person p2 = { "bbb",20 };
		
		struct Person p3 = { "ccc",18 };
		struct Person p4 = { "ddd",21 };

		seqStack stack = init_SeqStack();

		push_SeqStack(stack, &p1);
		push_SeqStack(stack, &p2);
		push_SeqStack(stack, &p3);
		push_SeqStack(stack, &p4);
		
		while (isEmpty_SeqStack(stack) == 0)//如果栈不为空 进行访问栈顶元素 并且出栈
		{
			struct Person * pTop = top_SeqStack(stack);
			printf("栈顶元素 姓名：%s 年龄：%d\n", pTop->name, pTop->age);
			pop_SeqStack(stack);
		}
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
