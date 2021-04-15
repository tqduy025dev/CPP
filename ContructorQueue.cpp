#include <iostream>

using namespace std;

int size = 10;
int front = 0;
int rear = -1;
int queue[10];

bool isEmpty() {
    return (front < 0 || front > rear) ? true : false;
}

bool isFull() {
    return rear == size - 1 ? true : false;
}

void enqueue(int item) {
    if (isFull()) {
        cout << "H�ng d?i d?y r�i m� oi, kh�ng enqueue du?c n?a d�u!" << endl;
        return;
    }
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (isEmpty()) {
        cout << "U?y, h�ng d?i r?ng m� oi, c� g� d�u m� dequeue!" << endl;
        return;
    }
    queue[front] = 0;
    front++;
}

int peek() {
    return queue[front];
}

int main() {
    // g?i c�c thao t�c v?i queue ? d�y
    return 0;
}
