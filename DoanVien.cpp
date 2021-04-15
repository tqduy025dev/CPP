#include<iostream>
#include<string>
using namespace std;


class DoanVien{
	private:
		int maDV;
		string hoten;
		int tuoi;
		string gioitinh;
	public:
		DoanVien(){
		};
		
			void NhapDV(){
			cout<<"Nhap ma doan vien: ";
			cin>>maDV;
			cout<<"Nhap ho ten: ";
			cin.ignore();
			getline(cin, hoten);
			cout<<"Nhap tuoi: ";
			cin>>tuoi;
			cout<<"Nhap gioi tinh: ";
			cin.ignore();
			getline(cin, gioitinh);
		}
	
		void XuatDV(){
			cout<<"Ma doan vien: "<<maDV<<endl;
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Gioi tinh: "<<gioitinh<<endl;
		}
};


class Node{
	private:
		DoanVien data;
		Node *next;
	public:
   		friend class Stack;
};

class Stack{
	private:
		Node *top;
	public:
		DoanVien getTop();
		Node *create_node(DoanVien dv);
		void push(Node *p);
		bool isEmpty();
		void pop();
		void print_stack();
};

DoanVien Stack::getTop(){
	return top->data;
}

bool Stack::isEmpty(){
		if(this->top == NULL)
			return true;
		return false;
}

void Stack::print_stack(){
		while(isEmpty() == false){
			getTop().XuatDV();
			pop();
		}
}

Node *Stack::create_node(DoanVien dv){
	Node *p = new Node();
	p->data = dv;
	p->next = NULL;
	return p;
}


void Stack::push(Node *p){
	if(isEmpty()==true){
		this->top = p;  
	}
	p->next = top;
	top = p;

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
	Stack st;

	DoanVien a1;
	DoanVien a2;
	DoanVien a3;
	
	a1.NhapDV();
	cout<<endl;
	a2.NhapDV();
	cout<<endl;
	a3.NhapDV();
	cout<<endl;
	
	
	Node *p1 = new Node;
	Node *p2 = new Node;
	Node *p3 = new Node;
	
	p1 = st.create_node(a1);
	p2 = st.create_node(a2);
	p3 = st.create_node(a3);
	
	st.push(p1);
	st.push(p2);
	st.push(p3);

	
	st.print_stack(); 
	
	
	
	
	return 0;
}
