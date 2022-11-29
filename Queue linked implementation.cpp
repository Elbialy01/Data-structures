#include <iostream>
#define MAXQUEUE 10
#define QueueEntry char
using namespace std;
typedef struct Queuenode {
    QueueEntry entry;
    struct Queuenode* next;
  
}Queuenode;
typedef struct Queue {
    Queuenode* front;
    Queuenode* rear;
    int size;
}Queue;
void createqueue(Queue* pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
int append(QueueEntry e, Queue* pq) {
    Queuenode* pn = (Queuenode*)malloc(sizeof(Queuenode));
    if (pn) {
        pn->entry = e;
        pn->next = NULL;
        if (!pq->rear) {
            pq->front = pn;
            pq->rear = pn;
        }
        else {
            pq->rear->next = pn;
            pq->rear = pn;
        }
        pq->size++;
        return 1;
    }
    else return 0;
}
void serve(QueueEntry* pe, Queue* pq) {
    Queuenode* pn=pq->front;
    pq->front = pq->front->next;
    *pe = pn->entry;
    free(pn);
    if (!pq->front) {
        pq->rear = NULL;
    }
    pq->size--;
}
int queuesize(Queue* pq) {
    return pq->size;
}
int queuefull(Queue* pq) {
    return 0;
}
int queueempty(Queue* pq) {
    return (pq->front == NULL);
}
void clearqueue(Queue* pq) {
    while (pq->front) {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}
void traversequeue(Queue* pq,void(*pf)(QueueEntry)) {
    Queuenode* pn = pq->front;
    while (pn) {
        (*pf)(pn->entry);
        pn = pn->next;
    }

}
void display(char e) {
    cout << e << " ";
}

int main()
{
    Queue q;
    QueueEntry e;
    createqueue(&q);
    for (int i = 0;i < 10;i++) {
        cin >> e;
        if (!queuefull(&q))
            append(e, &q);
        else break;
    }
    cout << queuesize(&q)<<endl;
    for (int i = 0;i < 5;i++) {
        if (!queueempty(&q))
            serve(&e, &q);
        else break;
        cout << e << " ";
    }
    cout << endl << queuesize(&q)<<endl;
    traversequeue(&q, &display);
}

