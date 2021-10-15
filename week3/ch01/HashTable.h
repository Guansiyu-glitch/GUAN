#pragma once
#define DEFAULT_SIZE 16
//哈希表元素定义
typedef struct _ListNode
{
	struct _ListNode* next;
	int key;
	void *data;
}ListNode;
typedef ListNode* List;
typedef ListNode* Element;
//哈希表结构定义
typedef struct _HashTable
{
	int TableSize;
	List *Thelists;
}HashTable;

//根据key计算索引，定位Hash 桶的位置
int Hash(int key, int TableSize)
{
	return (key % TableSize);

}
