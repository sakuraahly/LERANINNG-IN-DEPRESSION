#include <stdio.h>
#include <stdlib.h>

//队列的实现
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int* queue = ((int*)calloc(20000, sizeof(int)));
//    int front = 0;
//    int  rear = 0;
//
//    for (int i = 0; i < n; i++) {
//        int os;
//        scanf("%d", &os);
//        if (os == 1) {
//            int num;
//            scanf("%d", &num);
//            queue[rear++] = num;
//        }
//        else if (os == 0) {
//            if (front == rear) {
//                printf("invalid\n");
//            }
//            else {
//                printf("%d\n", queue[front++]);
//            }
//        }
//    }
//    return 0;
//}