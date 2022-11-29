#include <iostream>
#define MAXSTACK 10
#define StackEntry int 
using namespace std;
typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
}Stack;
void createstack(Stack* ps) {
    ps->top = 0;
}
void push(StackEntry e, Stack* ps) {
    ps->entry[ps->top++] = e;
}
int stackfull(Stack* ps) {
    if (ps->top == MAXSTACK)
        return 1;
    else
        return 0;
}
void pop(StackEntry* pe, Stack* ps) {
    *pe = ps->entry[--ps->top];
}
int stackempty(Stack* ps) {
    if (ps->top == 0)
        return 1;
    else
        return 0;
}
void stacktop(StackEntry* pe, Stack* ps) {
    *pe = ps->entry[ps->top - 1];
}
int stacksize(Stack* ps) {
    return ps->top;
}
void clearstack(Stack* ps) {
    ps->top = 0;
}
void traversestack(Stack* ps, void (*pf)(StackEntry)) {
    for (int i = ps->top - 1;i >= 0;i--)
        (*pf)(ps->entry[i]);
}
void display(StackEntry e) {
    cout << e<<" ";
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

