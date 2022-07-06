// Problem Link - https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?topList=striver-sde-sheet-problems&leftPanelTab=1

#define ll int
class Queue {
    ll arr[5000];
    ll rear;
    ll fron;
    ll count;
public:
    Queue() {
        rear = -1;
        fron = -1;
        count = 0;
    }

    bool isEmpty() {
        return fron==-1 or fron>rear;
    }

    void enqueue(int data) {
        if(fron==-1)
            fron = 0;
        rear = rear + 1;
        arr[rear] = data;
        count++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        ll val = arr[fron];
        arr[fron] = -1;
        fron = fron + 1;
        count--;
        return val;
    }

    int front() {
        if(isEmpty())
            return -1;
        return arr[fron];
    }
};