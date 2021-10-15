#include"Hash_Table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//初始化哈希表
HashTable* InitHash(int TableSize)
{
	int i = 0;
	HashTable* hTable=NULL;
	if (TableSize <= 0)
	{
		TableSize = DEFAULT_SIZE;
	}
	hTable = (HashTable*)malloc(sizeof(HashTable));
	if (NULL == hTable)

	{
		printf("HashTable malloc error.\n");
		return NULL;
	}
	hTable->TableSize = TableSize;
	//为Hash桶分配内存空间，其为一个指针数组
	hTable->Thelists = (List*)malloc(sizeof(List) * TableSize);
	if (NULL == hTable->Thelists)
	{

		printf("HashTable malloc error\n");
		free(hTable);
		return NULL;
	}
	//为Hash桶对应的指针数组初始化链表节点
	for (i = 0; i < TableSize; i++)
	{
		hTable->Thelists[i] = (ListNode*)malloc(sizeof(ListNode));
		if (NULL == hTable->Thelists[i])
		{
			printf("HashTable malloc error\n");
			free(hTable->Thelists);
			free(hTable);
			return NULL;
		}
		else
		{
			memset(hTable->Thelists[i], 0, sizeof(ListNode));
		}
	}
	return hTable;
}
//从哈希表中根据键值查找元素

Element Find(HashTable* HashTable, int key)
{
	int i = 0;
	List L = NULL;
	Element e = NULL;
	i = Hash(key, HashTable->TableSize);
	L = HashTable->Thelists[i];
	e = L->next;
	while (e != NULL && e->key != key)
		e = e->next;
	return e;
}

	//哈希表插入元素，元素为键值对
	void Insert(HashTable * HashTable, int key, void* value)
	{
		Element e = NULL, tmp = NULL;
		List L= NULL;
			e = Find(HashTable, key);
		if (NULL == e)
		{
			tmp = (Element)malloc(sizeof(ListNode));
			if (NULL == tmp)
			{
				printf("malloc error\n");
				return;
			}
			L=HashTable->Thelists[Hash(key, HashTable->TableSize)];//前插法
			tmp->data = value;
			tmp->key = key;
			tmp->next = L->next;
			L->next = tmp;
		}
		else
			printf("the key already exist\n");
	}

//哈希表删除元素
	void Delete(HashTable* HashTable, int key)
	{
		Element e = NULL, last = NULL;
		List L = NULL;
		int i = Hash(key, HashTable->TableSize);
		L = HashTable->Thelists[i];
		last = L;
		e = L->next;
		while (e != NULL && e->key != key)
		{
			last = e;
			e = e->next;
		}
		if (e) {//如果键值对存在
			last->next = e->next;
			free(e);
		}
	}
	//哈希表元素中提取数据
	void* Retrieve(Element e)
	{
		return e ? e->data : NULL;

	}
	//销毁哈希表
	void Destory(HashTable* HashTable)
	{
		int i = 0;
		List L = NULL;
		Element cur = NULL, next = NULL;
		for (i = 0; i < HashTable->TableSize; i++)
		{
			L = HashTable->Thelists[i];
			cur = L->next;
			while (cur->next != NULL)
			{
				next = cur->next;
				free(cur);
				cur = next;
			}
			free(L);
		}
		free(HashTable);
	}


	void main(void)
	{
		char* elems[] = { "小a","小b","小c" };
		int i = 0;
		HashTable* HashTable = NULL;
		HashTable = InitHash(31);
		Insert(HashTable, 1, elems[0]);
		Insert(HashTable, 2, elems[1]);
		Insert(HashTable, 3, elems[2]);
		Delete(HashTable, 1);
		for (i = 0; i < 4; i++)
		{
			Element e = Find(HashTable, i);
			if (e) {
				printf("%s\n", (const char*)Retrieve(e));
			}
			else {
				printf("Not found[key:%d]\n", i);

			}
		}
		system("pause");
	}
	
