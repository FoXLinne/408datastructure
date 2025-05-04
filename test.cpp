void Delete_x(LinkList &L, ElemType x){
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;

    while(L->next != NULL){
        if(p.data == x){
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
        else{
            pre = pre->next;
            p = p->next;
        }
    }
}

bool Merge(SqList A, SqList B, SqList &C){
    if(C.length < A.length + B.length){
        return false;
    }

    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.data[i] > B.data[j]){
            C.data[k] = B.data[j];
            j++;
            k++;
        }
        else{
            C.data[k] = A.data[i];
            i++;
            k++;
        }
    }
    while(i < A.length){
        C.data[k++] = A.data[i++];
    }
    while(j < B.length){
        C.data[k++] = B.data[j++]
    }
    C.length = k;
    return true;
}