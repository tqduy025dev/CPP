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
        cout << "Hàng d?i d?y rùi má oi, không enqueue du?c n?a dâu!" << endl;
        return;
    }
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (isEmpty()) {
        cout << "U?y, hàng d?i r?ng má oi, có gì dâu mà dequeue!" << endl;
        return;
    }
    queue[front] = 0;
    front++;
}

int peek() {
    return queue[front];
}

int main() {
    // g?i các thao tác v?i queue ? dây
    return 0;
}
