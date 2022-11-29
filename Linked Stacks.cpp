#include <iostream>
#define MAXSTACK 10
#define StackEntry int 
using namespace std;
typedef struct Stacknode {
    StackEntry entry;
    struct Stacknode *next;
}Stacknode;
typedef struct Stack {
    Stacknode* head;
    int size;
}Stack;
void createstack(Stack* ps) {
    ps->head = NULL;
    ps->size = 0;
}
int stackfull(Stack* ps) {
    return 0;
}
int push(StackEntry e, Stack* ps) {
    Stacknode* pe = (Stacknode*)malloc(sizeof(Stacknode));
    if (pe) {
        pe->entry = e;
        pe->next = ps->head;
        ps->head = pe;
        ps->size++;
        return 1;
    }
    else return 0;
}
int stackempty(Stack* ps) {
    return ps->size == 0;
}
void pop(StackEntry* pe, Stack* ps) {
    Stacknode* pn = ps->head;
    ps->head = pn->next;
    *pe = pn->entry;
    free(pn);
    ps->size--;
}
int stacksize(Stack* ps) {
    return ps->size;
}
void stacktop(StackEntry* pe, Stack* ps) {
    *pe = ps->head->entry;
}
void traversestack(Stack* ps, void(*pf)(StackEntry)) {
    Stacknode* pn = ps->head;
    while (pn) {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
void clearstack(Stack* ps) {
    Stacknode* pn, * pm;
    pn = ps->head;
    pm = ps->head;
    while (pm)
    {
        pn = pn->next;
        free(pm);
        pm = pn;
    }
    ps->size = 0;
    ps->head = NULL;
}
void display(StackEntry e) {
    cout << e << " ";
}



int main()
{
    Stack s;
    StackEntry e;
    createstack(&s);
    for (int i = 0;i < 10;i++) {
        if (!stackfull(&s))
            cin >> e;
        else break;
        push(e, &s);
    }
    cout << stacksize(&s)<<endl;
    if(!stackempty(&s))
        stacktop(&e, &s);
   cout << e <<endl;
    for (int i = 0;i < 5;i++) {
        if (!stackempty(&s))
            pop(&e, &s);
        else break;
        cout << e<<" ";
    }
    cout << endl<<stacksize(&s)<<endl;
    traversestack(&s, &display);
    cout << endl;
    clearstack(&s);
    cout << stacksize(&s);
       
}

