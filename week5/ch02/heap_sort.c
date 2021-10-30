#include<stdio.h>
#include<stdlib.h>
//打印数组
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d",    arr[i]   );
	}
	putchar('\n');
}
//交换
void swap(int *a,int*b)
{
	 
	int temp = *a;
	*a = *b;
	*b = temp;
}
//维护结点下标 
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if (lson < n && arr[largest] < arr[lson])
		largest = lson;
	if (rson < n && arr[largest] < arr[rson])
		largest = rson;
	if (largest != i)//说明左右儿子有比它大
	{
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);

	}

}
//堆排序
void heap_sort(int arr[], int n)
{
	int i;
	//建堆
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	//排序
	for (i = n - 1; i > 0; i--)
	{
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);

	}

}
int main(int argc, char const* argv[])
{
	int arr[] = { 2,3,8,1,4,9,10,7,16,14 };
	int n = 10;
	print_arr(arr, n);
	heap_sort(arr, n);
	print_arr(arr, n);
	return 0;
}
