#include <cstdio>
#define MAXSIZE 100 // 定义最大长度

struct SqList{
    int data[MAXSIZE]; // 存储空间的基址
    int length; // 当前长度
};

void Reverse(SqList &L, int from, int to){
    if(from < 0 || to > L.length || from > to){
        return;
    }
    while(from < to){
        int temp = L.data[from];
        L.data[from] = L.data[to];
        L.data[to] = temp;
        from++;
        to--;
    }
}

void Exchange(SqList &L, int n, int m){
    Reverse(L, 0, n-1); // 先将前 n 个元素翻转
    Reverse(L, n, m-1); // 再将后 m 个元素翻转
    Reverse(L, 0, m-1); // 最后将整个表翻转
    // 这样就实现了前 n 个元素和后 m 个元素的交换
}