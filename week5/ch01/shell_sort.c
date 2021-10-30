//以下代码用希尔排序实现从小到大排序
#include<stdio.h>
#include<stdlib.h>
//打印数组
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", arr[i] );
	}
	putchar('\n');
}
//希尔排序
void shell_sort(int arr[], int n)
{
	int i, j, inc, key;
	//初始增量：n/2每一堂之后除以2
	for (inc = n / 2; inc > 0; inc /= 2)
	{
		//每一趟采用插入排序
		for (i = inc; i < n; i++)
		{
			key = arr[i];
			for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
				arr[j] = arr[j - inc];
			arr[j] = key;
		}
		print_arr(arr, n);
	}
}
int main(int argc, char const* argv[])
{
	int arr[] = { 15 , 5 ,2 , 7 , 12 , 6 , 1 ,4 , 3 , 9 , 8 , 10};
	int n = 12;
	print_arr(arr, n);
	shell_sort(arr, n);
	print_arr(arr, n);
	return 0;
}
