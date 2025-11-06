//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <math.h>
//
//#define MAX_STACK_SIZE 100
//#define MAX_EXPRESSION_LENGTH 200
//
//// 堆栈结构定义
//typedef struct {
//    double data[MAX_STACK_SIZE];
//    int top;
//} Stack;
//
//// 堆栈操作函数
//void initStack(Stack* s) {
//    s->top = -1;
//}
//
//int isEmpty(Stack* s) {
//    return s->top == -1;
//}
//
//int isFull(Stack* s) {
//    return s->top == MAX_STACK_SIZE - 1;
//}
//
//void push(Stack* s, double value) {
//    if (isFull(s)) {
//        printf("错误：堆栈已满\n");
//        return;
//    }
//    s->data[++(s->top)] = value;
//}
//
//double pop(Stack* s) {
//    if (isEmpty(s)) {
//        printf("错误：堆栈为空\n");
//        return 0;
//    }
//    return s->data[(s->top)--];
//}
//
//double peek(Stack* s) {
//    if (isEmpty(s)) {
//        return 0;
//    }
//    return s->data[s->top];
//}
//
//// 检查字符是否为运算符
//int isOperator(char c) {
//    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
//}
//
//// 执行运算
//double performOperation(double a, double b, char operator) {
//    switch (operator) {
//    case '+': return a + b;
//    case '-': return a - b;
//    case '*': return a * b;
//    case '/':
//        if (b == 0) {
//            printf("错误：除数不能为零\n");
//            return 0;
//        }
//        return a / b;
//    case '^': return pow(a, b);
//    default:
//        printf("错误：未知运算符 %c\n", operator);
//        return 0;
//    }
//}
//
//// 解析逆波兰表达式并计算
//double evaluateRPN(char* expression) {
//    Stack stack;
//    initStack(&stack);
//
//    char* token = strtok(expression, " ");
//
//    while (token != NULL) {
//        // 如果是数字，压入堆栈
//        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
//            double num = atof(token);
//            push(&stack, num);
//        }
//        // 如果是运算符
//        else if (isOperator(token[0])) {
//            // 检查堆栈中是否有足够的操作数
//            if (stack.top < 1) {
//                printf("错误：表达式不合法\n");
//                return 0;
//            }
//
//            double b = pop(&stack);  // 第二个操作数
//            double a = pop(&stack);  // 第一个操作数
//            double result = performOperation(a, b, token[0]);
//            push(&stack, result);
//        }
//        else {
//            printf("错误：无法识别的符号 '%s'\n", token);
//            return 0;
//        }
//
//        token = strtok(NULL, " ");
//    }
//
//    // 最终结果应该在堆栈顶部
//    if (stack.top != 0) {
//        printf("错误：表达式不完整\n");
//        return 0;
//    }
//
//    return pop(&stack);
//}
//
//// 中缀转后缀表达式的辅助函数
//int getPrecedence(char op) {
//    switch (op) {
//    case '+': case '-': return 1;
//    case '*': case '/': return 2;
//    case '^': return 3;
//    default: return 0;
//    }
//}
//
//// 中缀表达式转后缀表达式（逆波兰表达式）
//void infixToPostfix(char* infix, char* postfix) {
//    Stack opStack;  // 运算符堆栈
//    initStack(&opStack);
//
//    char output[MAX_EXPRESSION_LENGTH] = "";
//    int outputIndex = 0;
//
//    for (int i = 0; infix[i] != '\0'; i++) {
//        char c = infix[i];
//
//        // 跳过空格
//        if (c == ' ') continue;
//
//        // 如果是数字，直接输出
//        if (isdigit(c) || c == '.') {
//            while (isdigit(infix[i]) || infix[i] == '.' ||
//                (infix[i] == '-' && i == 0) ||
//                (infix[i] == '-' && infix[i - 1] == '(')) {
//                output[outputIndex++] = infix[i++];
//            }
//            output[outputIndex++] = ' ';
//            i--;  // 回退一个字符
//        }
//        // 如果是左括号，压入堆栈
//        else if (c == '(') {
//            push(&opStack, c);
//        }
//        // 如果是右括号，弹出直到左括号
//        else if (c == ')') {
//            while (!isEmpty(&opStack) && peek(&opStack) != '(') {
//                output[outputIndex++] = (char)pop(&opStack);
//                output[outputIndex++] = ' ';
//            }
//            pop(&opStack);  // 弹出左括号
//        }
//        // 如果是运算符
//        else if (isOperator(c)) {
//            while (!isEmpty(&opStack) &&
//                getPrecedence((char)peek(&opStack)) >= getPrecedence(c) &&
//                (char)peek(&opStack) != '(') {
//                output[outputIndex++] = (char)pop(&opStack);
//                output[outputIndex++] = ' ';
//            }
//            push(&opStack, c);
//        }
//    }
//
//    // 弹出堆栈中剩余的运算符
//    while (!isEmpty(&opStack)) {
//        output[outputIndex++] = (char)pop(&opStack);
//        output[outputIndex++] = ' ';
//    }
//
//    output[outputIndex] = '\0';
//    strcpy(postfix, output);
//}
//
//// 测试函数
//int main() {
//    int choice;
//    char expression[MAX_EXPRESSION_LENGTH];
//    char postfix[MAX_EXPRESSION_LENGTH];
//
//    printf("=== 逆波兰表达式计算器 ===\n");
//
//    while (1) {
//        printf("\n请选择模式：\n");
//        printf("1. 直接输入逆波兰表达式\n");
//        printf("2. 输入中缀表达式（自动转换）\n");
//        printf("3. 退出\n");
//        printf("请选择: ");
//        scanf("%d", &choice);
//        getchar();  // 消耗换行符
//
//        switch (choice) {
//        case 1: {
//            printf("请输入逆波兰表达式（用空格分隔，如：5 1 2 + 4 * + 3 -）: ");
//            fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
//            expression[strcspn(expression, "\n")] = 0;  // 移除换行符
//
//            char temp[MAX_EXPRESSION_LENGTH];
//            strcpy(temp, expression);
//            double result = evaluateRPN(temp);
//            printf("表达式: %s\n", expression);
//            printf("结果: %.2f\n", result);
//            break;
//        }
//
//        case 2: {
//            printf("请输入中缀表达式（如：(5+((1+2)*4)-3)）: ");
//            fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
//            expression[strcspn(expression, "\n")] = 0;
//
//            infixToPostfix(expression, postfix);
//            printf("后缀表达式: %s\n", postfix);
//
//            char temp[MAX_EXPRESSION_LENGTH];
//            strcpy(temp, postfix);
//            double result = evaluateRPN(temp);
//            printf("结果: %.2f\n", result);
//            break;
//        }
//
//        case 3:
//            printf("再见！\n");
//            return 0;
//
//        default:
//            printf("无效选择！\n");
//        }
//    }
//
//    return 0;
//}