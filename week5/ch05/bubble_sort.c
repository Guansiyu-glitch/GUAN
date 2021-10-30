//选择排序和冒泡排序的实现
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
//冒泡排序打印
void print(int arr[], int length, int swapped)
{
	for (int i = 0; i < length; i++)
	{
		printf("  %d", arr[i]);
	}
	printf("%s\n", swapped ? "swapped" : "not swapped");
}
//交换
void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;

}
//选择排序
void selection_sort(int arr[], int n)

{
	int i, j, min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;

		}
		swap(&arr[min], &arr[i]);
		print_arr(arr, n);

	}
}

//冒泡排序
void bubble_sort(int arr[], int length)
{
	//外层循环：逐趟扫描
	for (int i = length; i > 1; i--)
	{
		int swapped = 0;//是否发生交换标志
		//一趟扫描
		for (int j = 1; j < i; j++)
		{
			if (arr[j - 1] > arr[j])

			{
				swap(&arr[j - 1], &arr[j]);
				swapped = 1;

			}

		}
		print(arr, length, swapped);
		if (!swapped)break;

	}
}
int main(int argc, char const* argv[])
{
	int arr[] = { 9,5,2,11,12,4,3,1,7 };
	int n = 9;
	printf("%s\n", "原数据：");
	print_arr(arr, n);
	printf("%s\n", "选择排序法：");
	selection_sort(arr, n);
	print_arr(arr, n);
	printf("%s\n", "冒泡排序法：");
	bubble_sort(arr, n);
	print(arr, n,0);

	return 0;
}
