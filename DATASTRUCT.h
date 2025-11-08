#define CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef STRANGE_H
#define STRANGE_H
//事实上这个STRANGE_H没有什么特殊含义,只是确保这个头文件只是被定义一次.


//栈节点结构 ,这里使用了链表来实现栈.
typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode;
		
//栈的结构体
typedef struct
{
    StackNode* top; //栈顶指针
    int size;  //栈当前的大小
	int capacity; //栈的最大容量(这个容量由使用者分配来)
}Stack;

//初始化栈的函数
void initializeStack(Stack* stack, int capacity);

//检查栈是否为空
bool isStackEmpty(Stack* stack);//如果是空的,就返回真值


//检查栈是否已满
bool isStackFull(Stack* stack);

//入栈操作
bool push(Stack* stack, int value);

//出栈操作
bool pop(Stack* stack, int* poppedValue);

//查看栈顶元素但是不弹出(但是给你使用的机会)
bool peekStack(Stack* stack, int* topvalue);

int getsize(Stack* stack); //获取栈的当前大小,但是不打印出来,也不需要输入指定变量.

//清空栈的函数,但是栈的大小限制仍然存在,如果需要更改容量,请使用initializeStack函数.
int clearStack(Stack* stack);

//打印栈的函数(用于调试)
void printStack(Stack* stack);







#endif 