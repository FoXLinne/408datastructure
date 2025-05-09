#include <cstdio>
#include <cstring>
#include <math.h>
#include <stdlib.h>


constexpr int MAXSIZE = 100;

struct stack{
    int data[MAXSIZE];
    int top;
};

void Push(stack &S, int x){
    S.top++;
    S.data[S.top] = x;
}

int Pop(stack &S, int &x){
    if (S.top == -1) {
        return 0;
    }
    x = S.data[S.top];
    S.top--;
    return 1;
}

int main(){
    stack S;
    S.top = -1;

    int n;
    char action[10];
    int k;

do {
    if (scanf("%s", action) == 1 && strcmp(action, "exit") == 0) {
        exit(-1);
    }
    if (scanf("%d", &n) != 1) {
        while (getchar() != '\n'); // 清空输入缓冲区
        n = -1;
        printf("Invaild number of operations, try again\n");// 设置为无效值以继续循环
    }
} while (n < 1 || n > 100);

    for(int i = 0; i < n; i++){
        scanf("%s", action);
        if(strcmp(action, "push") == 0){
            scanf("%d", &k);
            Push(S, k);
        }
        else if(strcmp(action, "pop") == 0){
            if (int x; Pop(S, x)){
                printf("%d\n", x);
            }
            else {
                printf("-1\n");
            }
        }
        else if (strcmp(action, "exit") == 0) {
            exit(-1);
        }
        else {
            printf("Invalid command\n");
            i--;
        }
    }
    return 0;
}