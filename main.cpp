#define _CRT_SECURE_NO_WARNINGS
//#include <SDL2/SDL.h>
#include <cstdlib>
#include"CODEBASE.h"
#include <stdio.h>
//int trash_search(int* arr, int i, int i1);
#include <stdio.h>
#include <math.h>
#define PRINTF_DATE(p)\
printf("%-4d\n%-4d\n%-4d\n",\
(p).year,(p).month,(p).day);

void bubble_sort(int arr[], int n)//æ≠µ‰µƒ√∞≈›≈≈–ÚÀ„∑®.
{
	for (int i = 0; i < n; i++)
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

int main() {
	int n;
	scanf("%d", &n);
	int* arr = ((int*)malloc(n * sizeof(int)));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bubble_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	

	return 0;

}


