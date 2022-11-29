#include <iostream>
#define MAXQUEUE 10
#define QueueEntry char
using namespace std;
typedef struct Queue {
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;
void createqueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void append(QueueEntry e, Queue* pq) {
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
int queuefull(Queue* pq) {
    return pq->size == MAXQUEUE;
}
void serve(QueueEntry* pe, Queue* pq) {
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
int queueempty(Queue* pq) {
    return pq->size == 0;
}
int queuesize(Queue* pq) {
    return pq->size;
}
void clearqueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void traversequeue(Queue* pq, void(*pf)(QueueEntry)) {
    for (int i = pq->front,s=0;s<pq->size;s++) {
        (*pf)(pq->entry[i]);
        i = (i + 1) % MAXQUEUE;

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

