#include<iostream>
#include<String>
#include <stdlib.h>
using namespace std;


class Node{
	private:
		string data;
		Node *next;
	public:
   		friend class Stack;
};

class Stack{
	private:
		Node *top;
	public:
		string getTop();
		Node *create_node(string str);
		bool isEmpty();
		void push(Node *p);
		void pop(string &x); //xoa va luu lai du lieu	
		void pop();
		void print_stack();
};

//Lay du lieu data cua top
string Stack::getTop(){
	return top->data;
}

void Stack::print_stack(){
		while(isEmpty() == false){
			cout<<getTop();
			pop();
		}
}

Node *Stack::create_node(string x){
	Node *p = new Node();
	p->data = x;
	p->next = NULL;
	return p;
}


bool Stack::isEmpty(){
		if(this->top == NULL)
			return true;
		return false;
}

void Stack::push(Node *p){
	if(isEmpty()==true){
		this->top = p;  // cap nhat dau stack la node p
	}
	p->next = top;
	top = p;

}

void Stack::pop(string &x){
	if(isEmpty()==true){
		cout<<"Stack rong ! khong the pop";
	}
	else{
		Node *p = top;
		top = top->next;
		x = p->data;
		delete p;
	}

}
void Stack::pop(){
	if(isEmpty()==true){
		cout<<"Stack rong ! khong the pop";
	}
	else{
		Node *p = top;
		top = top->next;
		delete p;
	}

}


 


int main(){
		Stack a; 
		string str = "(21 + ((25 * (7 * (2 - 8))) - ((15/4)+3) + (40 * (2 + (5 - (3 * 8))))))";
		string p1,p2,p3;
		int kq;
		
		for(int i = 0; i < str.length(); i++)
	{
		Node *p = new Node;
		if(str[i] == '(')
		{
			continue; 
		}
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			char *Temp = new char;
			Temp[0] = str[i];
			Temp[1] = '\0';
			string x = Temp;
		
			p = a.create_node(x);
			a.push(p);
		}

		string Temp;
		int Start;
		int End;

		if(str[i] >= '0' && str[i] <= '9')
		{
			Start = i;

			for(int j = i + 1; j < str.length(); j++)
			{
				if(str[j] < '0' || str[j] > '9')
				{
					End = j;
					i = j;
					break;
				}
			}
			End - 1;
			Temp = str.substr(Start, End - Start);
			
			p = a.create_node(Temp);
			a.push(p);
		}

		if(str[i] == ')')
		{
			a.pop(p1);
			a.pop(p2);
			a.pop(p3);

			int Num3, Num1;
			Num3 = atoi(p3.c_str());
			Num1 = atoi(p1.c_str());

			if(p2 == "+")
			{
				kq = Num3 + Num1;
			}
			else if(p2 == "-")
			{
				kq = Num3 - Num1;
			}
			else if(p2 == "*")
			{
				kq = Num3 * Num1;
			}
			else if(p2 == "/")
			{
				kq = Num3 / Num1;
			}
			else if(p2 == "%")
			{
				kq = Num3 % Num1;
			}


			char chr[20];
			itoa(kq, chr, 10);
			Node *q = a.create_node((string)chr);
			a.push(q);
		}
			
	}
	cout << "(21 + ((25 * (7 * (2 - 8))) - ((15/4)+3) + (40 * (2 + (5 - (3 * 8))))))"<<"\n= "<<kq;

	return 0;
}
