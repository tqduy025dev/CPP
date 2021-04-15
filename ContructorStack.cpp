#include <iostream>

using namespace std;

int size = 10;
int top = -1;
int stack[10];

//kiem tra rong
bool isEmpty() {	
    return top == -1 ? true : false;		
}

//kiem tra day
bool isFull() {
    return top == size-1 ? true : false;
}

//chen du lieu o dinh stack
void push(int a) {
    if (!isFull()) {
    	top++;
    	stack[top] = a;
    }else 
    	cout<<"Ngan xep da day, khong the chen!"<<endl;
}

//xoa du lieu o dinh stack
void pop() {
    if (!isEmpty()) {
   		stack[top] = 0;
		top--;
    }else 
    cout<<"Ngan xep rong, khong the xoa!"<<endl;
}

//lay du lieu o dinh ma khong xoa
int peek() {
    return stack[top];
}

int main() {
	
	push(1);
	push(5);
	push(3);
	push(9);
	push(7);
	push(6);
	push(10);
	push(2);
	push(4);
	push(8);
	if(isEmpty())
		cout<<"stack rong!"<<endl;
	if(isFull())
		cout<<"stack da day"<<endl;
	
		//lay du lieu trong stack
	for(top; top>=0 ;top--){
	cout<<peek()<<" ";
	}
	
    return 0;
}
