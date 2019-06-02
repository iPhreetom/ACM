#include<bits/stdc++.h>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
#define State int

typedef struct {
	ElemType * elem;
	int length;
	int listsize;
}SqList;

State InitList_Sq(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) exit(false);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return true;
}

State ListInsert_Sq(SqList &L,int i,ElemType e) {
	if (i < 1 || i > L.length	 + 1) return 0;
	if (L.length >= L.listsize) {
		ElemType * newbase = (ElemType*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) return 0;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int* q = &(L.elem[i-1]);
	for (int* p = &(L.elem[L.length-1]);p>=q;--p) {
		*(p+1) = *p;
	}
	*q = e;
	++L.length;
	return true;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	SqList lis;
	InitList_Sq(lis);
	ListInsert_Sq(lis,0,1);
	
	return 0;
}
