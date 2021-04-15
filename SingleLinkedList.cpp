#include<iostream>
#include <iomanip>

using namespace std;


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

class node{
	private:
		int value;
		node *next;
	public:
		friend class list;
};

class list{
	private:
		node *start;
		node *last;
	public:
		node *create_node(int x);
		void insert_Begin();
		void insert_Pos();
		void insert_End();
		void delete_Begin();
		void delete_End();
		void delete_Pos();
		void search();
		void update();
		void sort();
		void showlist();
		friend void swap();
		list(){
			start = last = NULL;	
		}
};


node *list::create_node(int x){
	node *t = new node;
	t->value = x;
	t->next = NULL;
	
	return t;
}

void list::insert_Begin(){
	int x;
	cout<<"Nhap du lieu: ";
	cin>>x;
	
	node *t = create_node(x);
	
	if(start == last && last == NULL){
		start = last = t;
	}
	else{
		t->next = start;
		start = t;
	}
}

void list::insert_End(){
	int x;
	cout<<"Nhap du lieu: ";
	cin>>x;
	
	node *t = create_node(x);
	
	if(start == last && last == NULL){
		start = last = t;
	}
	else{
		last->next = t;
		last = t;
	}
}


void list::insert_Pos(){
	int x, pos, i = 0;
	cout<<"Nhap du lieu: ";
	cin>>x;
	node *t = create_node(x);
	
	cout<<"Nhap vi tri can chen:";
	cin>>pos;
	
	if(start == last && last == NULL){
		if(pos == 1){
			start = last = t;
		}else{
			cout<<"Ngoai pham vi"<<endl;
			return;
		}
	}else{
		for(node *p = start; p != NULL ; p = p->next){
			i++;
			if(pos==1){
				t->next = start;
				start = t;
				return;
			}
			if(i == pos-1){
				t->next = p->next;
				p->next = t;
				return;
			}
		}
		if(pos > i){
			cout<<"Ngoai pham vi"<<endl;
			return;
		}
	}
	
}


void list::delete_Begin(){
	node *t;
	t = start;
	start = start->next;
	return;
}


void list::delete_End(){
	node *t;
	for(node* p = start; p != NULL ; p = p->next){
		if(p->next == last){
			t = p->next;
			last = p;
			last->next = NULL;
			delete t;
			return;
		}
	}
}


void list::delete_Pos(){
	int pos, i = 0;
	
	cout<<"Nhap vi tri can xoa:";
	cin>>pos;
	
	if(start == last && last == NULL){
		cout<<"Danh sach rong khong the xoa!"<<endl;
	}else{
		for(node *p = start; p != NULL ; p = p->next){
			i++;
			if(pos == 1){
				start = p->next;
				delete p;
				return;
			}
			if(i == pos-1){
				node *t, *h;
				t = p->next;
				h = t->next;   // cach khac: p->next = t->next, khong can phai khai bao them *h
				p->next = h;
				delete t;
				return;
			}
			if(pos > i){
				cout<<"Ngoai pham vi"<<endl;
				return;
			}
		}
	}
}


void list::search(){
	int x, pos = 0;
	bool msg = false;
	cout<<"Nhap du lieu can tim: ";
	cin>>x;
	if(start == last && last == NULL){
		cout<<"Danh sach rong khong the tim!"<<endl;
	}
	
	for(node *p = start; p != NULL ; p = p->next){
		pos++;
		if(p->value == x){
			cout<<"Du lieu nay o vi tri thu "<<pos<<" trong danh sach";
			msg = true;
		}
	}
	
	if(!msg){
		cout<<"Khong tim thay trong danh sach"<<endl;
	}
}

void list::update(){
	int x, pos, i=0;
	cout<<"Nhap vi tri can sua: ";
	cin>>pos;
	cout<<"Nhap du lieu moi";
	cin>>x;
	
	if(start == last && last == NULL){
		cout<<"Danh sach rong khong the sua!"<<endl;
	}
	
	for(node *p = start; p != NULL ; p = p->next){
		i++; cout<<"--"<<i;
		if(pos == 1){
			start->value = x;
			cout<<"Done!";
			return;
		}
		if(i == pos){
			p->value = x;
			cout<<"Done!";
			return;
		}
	}
	if(pos>i){
		cout<<"Ngoai pham vi"<<endl;
	}
	
}

void list::sort(){
	for(node *p = start; p != last ; p = p->next){
		for(node *q = p->next; q != NULL ;q = q->next){
			if(p->value > q->value){
				swap(p->value, q->value);
			}
		}
	}
}

void list::showlist(){
	for(node *t = start; t != NULL ; t = t->next){
		cout<<t->value<<setw(5);
	}
}







int main(){
	list a;
	a.insert_End();
	a.insert_End();
	a.insert_End();
	a.insert_End();
	a.update();
//	a.search();
//	a.delete_Pos();
//	a.delete_End();
//	a.delete_Begin();
//	a.insert_Pos();
//	a.sort();
	a.showlist();
}



























