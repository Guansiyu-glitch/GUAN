#include "seqQueue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//初始化队列
seqQueue init_SeqQueue()
{
	struct dynamicArray* arr = init_DynamicArray(MAX);
	return arr;
}
//入队
void push_SeqQueue(seqQueue queue, void* data)
{if (queue = NULL)
{
	return;
}
if (data == NULL)
{
	return;
}
struct dynamicArray* myQueue = queue;
if (myQueue->m_size >= MAX)
{
	return;
}
insert_dynamicArray(myQueue, myQueue->m_size, data);
}
//出队
void pop_SeqQueue(seqQueue queue)
{
	if(queue==NULL)
	{
		return;
	}
	struct dynamicArray* myQueue = queue;
	if(myQueue->m_size<=0)
	{
		return;

	}
	removeByPos_DynamicArray(myQueue, 0);
}
//返回对头元素
void* front_SeqQueue(seqQue queue)
{
	if (queue==NULL)
	{
		return NULL;
	}
	struct dynamicArray* myQueue = queue;
	return myQueue->pAddr[0];

}
//返回队尾元素
void* back_SeqQueue(seqQueue queue)
{
	if (queue == NULL;
	{return; }
	struct dynamicArray* myQueue = queue;
		return myQueue->pAddr[myQueue->m_size - 1];

}
//返回队伍大小
int size_SeqQueue(seqQueue queue)
{
	if (queue==NULL)
	{return -1;
	}
	struct dynamicArray* myQueue = queue;
	return myQueue->m_size;
}
//销毁
void destory_SeqQueue(seqQueue queue)
{if (queue==NULL)
{
	return;
}
destory_DynamicArray(queue);
}
struct Person {
	char name[64];
	int age;
};
void test02()
{
	seqQueue queue = init_SeqQueue();
	struct Person p1 = { "管爱国",10 };
	struct Person p2 = { "张规划",10 };
	struct Person p3 = { "王开发",10 };
	struct Person p4 = { "周富强",10 };
	struct Person p5 = { "李民主",10 };

	//入队
	push_SeqQueue(queue, &p1);
	push_SeqQueue(queue, &p2);
	push_SeqQueue(queue, &p3);
	push_SeqQueue(queue, &p4);
	push_SeqQueue(queue, &p5);
	while(size_SeqQueue(queue)>0
	{//获取队头元素
		struct Person* pFront = front_SeqQueue(queue);
			printf("队头元素——--姓名： %s  年龄: d\n" pFront->name, pFront->age);
		//获取队尾
		struct Person* pBack = back_SeqQueue(queue);
		printf("队尾-----姓名：  %s 年龄：d\n", pBack->name, pFront->age);
		//出队
		pop_SeqQueue(queue);
		{
			printf("队伍大小： %\n", size_SeqQueue(queue））;

			//销毁
			destory_SeqQueue(queue);

		}
	

		int main()
		{
			test02()
				system("pause");
			return EXIT_SUCCESS;
		}
