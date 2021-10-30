//快速排序
#include<stdio.h>
#include<stdlib.h>
//打印数组
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d   ", arr[i]);
	}
	putchar('\n');
}
//交换
void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;

}
//h划分函数
int partition(int arr[], int low, int high)
{
	int i = low - 1;
	int j = high;
	int pivot = arr[high];//枢纽元素
	while (1)
	{
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		if (i < j)
			swap(&arr[i], &arr[j]);
		else
			break;
	}
	swap(& arr[i], & arr[high]);//把枢纽元素放到正确的位置上
	return i;

  }
//快速排序
void qsort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		qsort(arr, low, mid - 1);
		qsort(arr, mid + 1, high);

	}
}
//快速排序入口
void quick_sort(int arr[], int n)
{
	qsort(arr, 0, n - 1);

}
int main(int argc, char const* argv[])
{
	int arr[] = { 9,5,2,11,12,4,3,1,7 };
	int n = 9;
	print_arr(arr, n);
	quick_sort(arr, n);
	print_arr(arr, n);
	return 0;
}
