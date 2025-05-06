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

// 2025.5.7
// 试编写带头结点的单链表L中删除一个最小值节点的高效算法（最小值节点唯一）
// 第一步，找最小值
// 第二步，删掉最小值
// 使用 p 指针遍历，使用 q 指针标记遍历到的节点中的最小值。
// 具体表现为，将 p 当前位置的值与 q 的值进行比较，若 p 的值小于 q 的值，则将 q 指向 p。
// 直到 p 遍历完链表，q 指向的就是最小值节点。
// 使用 pre 指针来记录 q 的前一个节点，方便删除操作。


void DeleteMinNode(LinkList &L){
    if(L->next == NULL){
        return; // 链表为空
    }
    LNode *p = L->next; // p 指向第一个节点
    LNode *pre = L; // pre 指向 q 的前一个节点
    LNode *minpre = pre;
    LNode *q = p; // q 指向最小值节点
    while(p != NULL){
        if(p->data < q->data){
            q = p;
            minpre = pre;
        }
        p = p->next;
        minpre = minpre->next;
    }
    pre->next = q->next;
    free(p);
}
