#ifndef  CODEBASE_H
#define CODEBASE_H

extern int sp;

void swap(int* a, int* b);//交换两个整数的值的函数[用指针是因为局部变量交换数值无法改变原有的数值]

int trash_search(int arr[], int n, int num);//一个没有什么用的垃圾搜索函数.

void bubble_sort(int arr[], int n );//经典的冒泡排序算法.(从小到大的的顺序)

void select_sort(int arr[], int n);//选择排序

void insert_sort(int arr[], int n);//插入排序算法.

void quick_sort(int arr[],int n);//快速排序算法.

void heap_sort(int arr[], int n);//堆排序算法.(这个排序比冒泡排序要快)

int my_strlen(char* s);
//两个都是求字符串长度的函数.(具体区别我忘记了)
int my_strlen1(char* s);

void shellSort(int arr[], int n);//希尔排序算法.

void printArray(int arr[], int n); //打印数组的函数.

void swap(char* arr[], int i,int j);//字符串数组的两个元素的函数.

const char *month_name(int n);//根据数字返回月份名称的函数.

void reverse_array(int arr[], int n);//反转数组的函数.

long factorial_recursive(int n);//递归实现阶乘的函数.

int is_prime(int n);//判断一个数是否是素数的函数.

void randarr(int arr[], int n);//生成随机数组的函数.

int factors_sum(int n);//计算一个数的因子和的函数.

int* createintarray(int n);//创建一个整数数组的函数.

int isleapyear(int year);//判断是否是闰年的函数.

typedef struct bigtime {
	int year;
	int month;
	int day;
}date;

date getNextDay(int year, int month, int day);/*计算某年某月某日是该年的第几天的函数.
输入格式是 year-month-day 例如2023-08-15
*/

int* re_duplicate_array(int arr[], int n, int* new_size);//数组去重函数.

void heapify(int arr[], int n, int i);//堆排序的辅助函数.(用于保证堆是最大堆)



#endif

