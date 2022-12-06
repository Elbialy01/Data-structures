#include <iostream>
#define ListEntry int 
using namespace std;
typedef struct ListNode {
    ListEntry entry;
	struct ListNode* next;
}ListNode;
typedef struct List {
    ListNode* head;
    int size;
}List;
void createlist(List* pl) {
    pl->head = NULL;
    pl->size = 0;
}
int listempty(List* pl) {
    return (pl->head == NULL);
}
int listfull(List* pl) {
    return 0;
}
int listsize(List* pl) {
    return pl->size;
}
void destorylist(List* pl) {
    ListNode* p = pl->head;
    while (p) {
        pl->head = pl->head->next;
        free(p);
        p = pl->head;
    }
    pl->size = 0;
}
void traverselist(List* pl,void(*pf)(ListEntry)) {
    ListNode* p = pl->head;
    while (p) {
        (*pf)(p->entry);
        p = p->next;
    }
}
void insertlist(int pos, ListEntry e, List* pl) {
    ListNode* p,*q;
    int i;
    p = (ListNode*)malloc(sizeof(ListNode));
    p->entry = e;
    p->next = NULL;
    if (pos == 0) {
        p->next = pl->head;
        pl->head = p;
    }
    else {
        for (q = pl->head, i = 0;i < pos - 1;i++)
            q = q->next;
        p->next = q->next;
        q->next = p;
    }
    pl->size++;   
}
void deletelist(int pos, ListEntry* pe, List* pl) {
    ListNode* p,*q;
    int i;
    if (pos == 0) {
        p = pl->head->next;
        *pe = pl->head->entry;
        free(pl->head);
        pl->head = p;
    }
    else {
        for (q = pl->head, i = 0;i < pos - 1;i++)
            q = q->next;
        p = q->next->next;
        *pe = q->next->entry;
        free(q->next);
        q->next = p;    
    }
    pl->size--;
}
void traverselist(int pos, ListEntry* pe, List* pl) {
    ListNode* p;
    int i;
    for (p = pl->head, i = 0;i < pos -1;i++)
        p = p->next;
    *pe = p->next->entry; 
}
void replacelist(int pos, ListEntry e, List* pl) {
    int i;
    ListNode* p;
    for (p = pl->head, i = 0;i < pos;i++)
        p = p->next;
    p->entry = e;
}
void display(int e) {
    cout << e<<" ";
}


int main()
{
    List l;
    ListEntry e;
    createlist(&l);
    for (int i = 0;i < 9;i++) {
        if (!listfull(&l))
            cin >> e;
        else break;
        insertlist(i, e, &l);
    }
    insertlist(5, 20, &l);
    deletelist(6, &e, &l);
    cout << e << endl;
    replacelist(4,0, &l);
    traverselist(&l, &display);
    cout<<endl<<listsize(&l);
}
