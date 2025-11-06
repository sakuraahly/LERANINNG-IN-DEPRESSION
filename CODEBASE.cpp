#include "CODEBASE.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
int sp = 666;

void swap(int* a, int* b)//交换两个整数的值的函数
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int trash_search(int arr[], int n,int num) //这个版本找目标大小的数字
{
	if (n <= 0) {
		return -1;
	}

	int temp0,temp1,temp2;


		int condition = (n % 2);

		if (condition == 0) {
			 temp1 = arr[(n / 2) - 1];//左中间数字
			if (num == temp1)
			{
				return((n / 2) - 1);
			}
			 temp2 = arr[n / 2];//右中间数字
			if (num ==temp2){
				return (n / 2);;
			}

		}
		else {
			 temp0 = arr[(n - 1) / 2];//可以直接从最中间的数字来

		}//区分被查找的数组究竟有奇数个还是偶数个元素.



		switch (condition) {
		case 0:
			for (int i = 0; i < temp1;i++)
			{
				if (arr[i] == num)
				{
					return i;
				}
			}
			break;
		case 1:
			for (int i =0; temp0 < i <= n;i++)
			{
				if (arr[i] == num)
				{
					return i;
				}
			}

		}

		printf("对不起没有你要找的数字\n");


		return -1;
	}

void bubble_sort(int arr[], int n)//经典的冒泡排序算法.
{
	for (int i = 0 ; i<n ; i++)
	{
		
	for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
							
void select_sort(int arr[],int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int min = arr[i];
			if (arr[j] < min)
			{
				min = arr[j];

				int temp = arr[i];
				arr[i] = min;
				arr[j] = temp;
			}
		}
	}
}

void insert_sort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		// 将arr[i]插入到已排序的子数组arr[0..i-1]中
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int my_strlen(char *s)
{
	int n;
	for (n =0; *s != '\0';s++)
	{
		n++;
	}
	return n;
}

int my_strlen1(char* s)
{
	char* p = s;

	while (*p != '\0')
	{
		p++;//事实上,只是恰好char用1个字节存储,所以指针加1就是加1个字节.
		//如果是int*类型的指针,p++就是加4个字节(假设int是4个字节存储).
		//指针的加法是根据指针所指向的数据类型来决定的.
	}
	return p - s;
}

void shellSort(int arr[], int n) {
	// 初始增量gap为数组长度的一半，逐步减半直到1
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// 对每个子序列进行插入排序
		for (int i = gap; i < n; i++) {
			int temp = arr[i];  // 当前待插入元素
			int j;
			// 将元素插入到对应子序列的正确位置
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];  // 移动元素
			}
			arr[j] = temp;  // 插入元素
		}
	}
}

void printArray(int arr[], int n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

void swap(char* arr[], int i, int j) {
	char* temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

const char *month_name(int n) //根据数字返回月份名称的函数.
{
	static const char  *name[] = {
		"Illegal month","January","February",
		"March","April","May","June","July",
		"August","September","October",
		"November","December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

void reverse_array(int arr[], int n) //反转数组的函数.
{
	int temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}

long factorial_recursive(int n) //递归实现阶乘的函数.
{
	if (n <= 1 && n>0)
		return 1;
	else if (n < 0)
		return -1;
	else
		return n * factorial_recursive(n - 1);
}

int is_prime(int n) //判断一个数是否是素数的函数.
{
	if (n <= 1) {
		return 0;
	}
	if (n==2) {
		return 1;
	}

	if (n % 2 == 0) {
		return 0;
	}

	for (int i = 3; i * i <= n; i+=2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void randarr(int arr[], int n) //生成随机数组的函数.
{
	srand((unsigned int)time(NULL));//用时间作为随机数种子.

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

int factors_sum(int num) {
	int sum = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int* createintarray(int n) //创建一个整数数组的函数.
{
	int* p;
	p = (int*)malloc(n * sizeof(int));
	if (p == NULL) {
		printf("内存分配失败!\n");
		exit(1);
	}
	return p;
}

void quick_sort(int arr[], int n) {
		if (n <= 1) {
		return; // 基线条件：数组长度为0或1时已经有序
	}
	int pivot = arr[n / 2]; // 选择基准元素
	int i = 0, j = n - 1;
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			// 交换元素
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	// 递归排序子数组
	if (j > 0) {
		quick_sort(arr, j + 1);
	}
	if (i < n) {
		quick_sort(arr + i, n - i);
	}
}

void heap_sort(int arr[], int n) {//堆排序算法.(这个排序比冒泡排序要快)
	// 构建最大堆(从最后一个非叶子节点开始向前遍历到堆)
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	// 一个个从堆中取出元素
	for (int i = n - 1; i > 0; i--) {
		// 将当前根节点（最大值）与最后一个元素交换
		swap(&arr[0], &arr[i]);
		// 重新堆化受影响的子树
		heapify(arr, i, 0);
	}
}

int isleapyear(int year) //判断是否是闰年的函数.
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

date getNextDay(int year, int month, int day) //将日期加1天后的日期输出.
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isleapyear(year)) {
		daysInMonth[1] = 29;
	}
	else {
		daysInMonth[1] = 28;
	}

	if (day < daysInMonth[month - 1]) {
		day++;
	}
	else {
		day = 1;
		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}

	printf("%d-%d-%d\n", year, month, day);

	date date1;
	date1.year = year;
	date1.month = month;
	date1.day = day;


	return (date1);//{year,month,day};
}

int* re_duplicate_array(int arr[], int n, int* new_size)//数组去重函数.
{
	if (arr == NULL || n <= 0) {
		*new_size = 0;
		return NULL;
	}

	// 创建哈希表，假设数字范围在0-100000

	int* hash((int*)calloc(100001, sizeof(int)));

	// 分配结果数组内存（最大可能大小为n）
	int* result = (int*)malloc(n * sizeof(int));
	if (result == NULL) {
		*new_size = 0;
		return NULL;
	}

	int count = 0;  // 记录去重后的元素个数

	// 遍历原数组进行去重
	for (int i = 0; i < n; i++) {
		int num = arr[i];

		// 检查数字是否在有效范围内
		if (num < 0 || num > 100000) {
			continue;  // 跳过超出范围的数字
		}

		// 如果该数字第一次出现
		if (hash[num] == 0) {
			hash[num] = 1;          // 标记为已出现
			result[count] = num;     // 添加到结果数组
			count++;                 // 计数增加
		}
	}

	// 如果实际元素个数小于分配的大小，可以重新分配内存以节省空间
	if (count < n) {
		int* temp = (int*)realloc(result, count * sizeof(int));
		if (temp != NULL) {
			result = temp;
		}
		// 如果realloc失败，仍然使用原来的result，只是会浪费一些空间
	}

	*new_size = count;  // 设置新数组的大小
	return result;      // 返回去重后的新数组
}

void heapify(int arr[], int n, int i) {//
	int largest = i; //初始化最大元素为根节点(目前是假设状态)
	int left = 2 * i + 1;//左子节点
	int right = 2 * i + 2;//右子节点

	//最大堆(也就是搜索二叉树,左子节点小于节点小于右子节点)
	if (left < n && arr[left]>arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
	largest = right;
}

	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);//递归堆化受影响的子树
	}
}

