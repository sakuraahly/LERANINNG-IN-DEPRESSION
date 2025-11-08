#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "DATASTRUCT.h"

void initializeStack(Stack* stack, int capacity)
{
	stack->top = NULL;
	stack->size = 0;
	stack->capacity = capacity;

}

bool isStackFull(Stack* stack)
{
	if (stack->capacity < 0)
		return false;
	return stack->size >= stack->capacity;
	//这里我们可以看出如果我们的capacity是负数的话,栈永远不会满.
}

// 检查栈是否为空
bool isStackEmpty(Stack* stack)//如果是空的,就返回真值
{
	return stack->size == 0;
}
//入栈操作
bool push(Stack* stack, int data)
{
	if (isStackFull(stack))
	{
		printf("OH NO,THE STACK IS FULL!THE DATA %d IS SENTBACK.",data);
		return false;
	}

	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (!newNode)//如果内存分配失败,那么newNode就是NULL,也就是说我们的!newNode就是真值
	{
		printf("Memory allocation failed!\n");
		return false;
	}

	newNode->data = data;//将数据存储在新节点中
	newNode->next = stack->top;//也就是说新节点的下一个节点指向当前栈顶
	stack->top = newNode; //更新栈顶指针为新节点
	stack->size++;//栈的大小加1

	return true;
}

bool pop(Stack* stack,int * poppedValue)//出栈操作
{
	if (isStackEmpty(stack))
	{
		printf("OH NO,THE STACK IS EMPTY!NO DATA CAN BE POPPED.\n");
		return false;
	}
	StackNode* temp = stack->top;//临时指针指向栈顶节点

	*poppedValue = temp->data; //获取栈顶节点的数据

	stack->top = stack->top->next; //更新栈顶指针为下一个节(就是先提取top等待处理,之后吧top修改为next)

	free(temp); //释放临时指针的内存(防止内存泄露)

	stack->size--;//栈的大小减1

	return true;

}

bool peekStack(Stack* stack,int* topvalue)//查看栈顶元素但是不弹出(但是给你使用的机会)
{
	if (isStackEmpty(stack))
	{
		printf("THE STACK IS EMPTY!NO DATA TO PEEK.\n");
		return false;
	}
	printf("THE TOP ELEMENT IS %d\n", stack->top->data);//top指针指向栈顶节点,所以我们可以通过top->data来访问栈顶元素的数据
	*topvalue = stack->top->data; //将栈顶元素的数据赋值给topvalue指针指向的变量
	return true;
	
}

int getsize(Stack* stack) {//获取栈的当前大小,但是不打印出来,也不需要输入指定变量.
	return stack->size;	
	}

int clearStack(Stack* stack)//清空栈的函数,但是栈的大小限制仍然存在,如果需要更改容量,请使用initializeStack函数.
{
	StackNode* current = stack->top;
	while (current!=NULL)
	{
		StackNode* temp = current;
		current = current->next;
		free(temp);
	}
	stack->top = NULL;
	stack->size = 0;
}

//打印栈的函数(用于调试)
void printStack(Stack* stack)
{
	
		if (isStackEmpty(stack)) {
			printf("Stack is empty!\n");
			return;
		}

		printf("Stack (top to bottom): ");
		StackNode* current = stack->top;
		while (current != NULL) {
			printf("%d", current->data);
			if (current->next != NULL) {
				printf(" -> ");
			}
			current = current->next;
		}
		printf("\n");
	}


