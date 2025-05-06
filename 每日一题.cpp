// 2010统考真题
// 将 n 个整数存放在一维数组 R 中，设计一个在时间和空间方面都尽可能高效的算法，将 R 中保存的序列循环左移 p （0 < p < n）位。即将 R 中的数据由 (X0, X1, X2, ..., Xn-1) 变换为 (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。
// 1) 给出算法的基本设计思想
// 2) 用 C 语言实现算法，并给出完整的程序代码
// 3) 说明算法的时间复杂度和空间复杂度

// 先 Reverse 前 p 个元素，再 Reverse 后 n - p 个元素，最后 Reverse 整个数组。

#include <cstdio>

void Reverse(SqList &L, int to, int from){
    while(to < from){
        int temp = L[to];
        L[to] = L[from];
        L[from] = temp;
        to++;
        from--;
    }
}

void Exchange(SqList &L, int p, int n){
    Reverse(L, 0, p-1);
    Reverse(L, p, n-1);
    Reverse(L, 0, n-1);
}