#include<iostream>
#include<cstdlib>
#include "Employee.h"

using namespace std;



class node {
	private:
	    Employee info;
		node *n;
	    node *p;
    public:
    	friend class listNode;
};

int count = 0; // dem so phan tu trong list
class listNode {
	private:
		node *start, *last;
    public:
      node *create_node(Employee nv);
      void insert_begin();
      void insert_end();
      void insert_pos();
      void delete_pos();
      void search();
      void update();
      void display();
      void reverse();
      listNode() {
         start = NULL;
         last = NULL;
      }
};


node* listNode::create_node(Employee nv) {
   count++;
   node *t;
   t = new node;
   t->info = nv;
   t->n = NULL;
   t->p = NULL;
   return t;
}
void listNode::insert_begin() {
   Employee nv;
   cout<<endl<<"Nhap thong tin nhan vien : "<<endl;
   cin>>nv;
   node *t;
   t = create_node(nv);
   
   if (start == last && start == NULL) {
      cout<<"Phan tu duoc chen vao danh sach trong"<<endl;
      start = last = t;
      start->n = last->n = NULL;
      start->p = last->p = NULL;
   } else {
      t->n = start;
      start->p = t;
      start = t;
      start->p = last;
      last->n = start;
      cout<<"Da chen xong!"<<endl;
   }
}

void listNode::insert_end() {
   Employee nv;
   cout<<endl<<"Nhap thong tin nhan vien: "<<endl;
   cin>>nv;
   node *t;
   t = create_node(nv);
   if (start == last && start == NULL) {
      cout<<"Phan tu duoc chen vao danh sach trong"<<endl;
      start = last = t;
      start->n= last->n = NULL;
      start->p = last->p= NULL;
   } else {
      last->n= t;
      t->p= last;
      last = t;
      start->p = last;
      last->n= start;
   }
}
void listNode::insert_pos() {
	Employee nv;
    int pos, i;
   cout<<endl<<"Nhap thong tin nhan vien: "<<endl;
   cin>>nv;
   cout<<endl<<"Nhap vao vi tri can chen: ";
   cin>>pos;
    node *t, *s, *ptr;
   t = create_node(nv);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->n = last->n = NULL;
         start->p = last->p = NULL;
      } else {
         cout<<"Vi tri ngoai pham vi"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Vi tri ngoai pham vi"<<endl;
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            cout<<"Da chen xong!"<<endl;
            break;
         }
      }
   }
}
void listNode::delete_pos() {
   int pos, i;
   node *ptr, *s;
   if (start == last && start == NULL) {
      cout<<"Danh sach trong, khong the xoa"<<endl;
      return;
   }
   cout<<endl<<"Nhap vao vi tri can xoa: ";
   cin>>pos;
   if (count < pos) {
      cout<<"Vi tri ngoai pham vi"<<endl;
      return;
   }
   s = start;
   if(pos == 1) {
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
      cout<<"Da xoa xong!"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
   cout<<"Da xoa xong!"<<endl;
}

void listNode::update() {
	Employee nv;
   int i, pos;
   if (start == last && start == NULL) {
      cout<<"Danh sach trong, khong the cap nhat"<<endl;
      return;
   }
   cout<<endl<<"Nhap vao vi tri can cap nhat: ";
   cin>>pos;
   cout<<"Nhap thong tin moi: "<<endl;
   cin>>nv;
   node *s;
   if (count < pos) {
      cout<<"Vi tri ngoai pham vi"<<endl;
      return;
   }
   s = start;
   if (pos == 1) {
      s->info = nv;
      cout<<"Da cap nhat!"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->n;
   }
   s->info = nv;
   cout<<"Da cap nhat!"<<endl;
}

void listNode::search() {
	string nv;
   int pos = 0, i;
   bool flag = false;
   node *s;
   if (start == last && start == NULL) {
      cout<<"Danh sach trong khong the tim"<<endl;
      return;
   }
   cout<<endl<<"Nhap MNV can tim: ";
   cin>>nv;
   s = start;
   for (i = 0;i < count;i++) {
      pos++;
      if (s->info.getCode() == nv ){
         cout<<"Nhan vien "<<s->info<<"nay dc tim thay o vi tri thu: "<<pos<<endl;
         flag = true;
      }
      s = s->n;
   }
   if (!flag)
      cout<<"Khong tim thay trong danh sach"<<endl;
}

void listNode::display() {
   int i;
   node *s;
   if (start == last && start == NULL) {
      cout<<"Danh sach trong, khong the hien thi"<<endl;
      return;
   }
   s = start;
   for (i = 0;i < count-1;i++) {
      cout<<s->info;
      s = s->n;
   }
   cout<<s->info<<endl;
}
void listNode::reverse() {
   if (start == last && start == NULL) {
      cout<<"Danh sach trong, khong the dao"<<endl;
      return;
   }
   node *p1, *p2;
   p1 = start;
   p2 = p1->n;
   p1->n = NULL;
   p1->p= p2;
   while (p2 != start) {
      p2->p = p2->n;
      p2->n = p1;
      p1 = p2;
      p2 = p2->p;
   }
   last = start;
   start = p1;
   cout<<"Dao nguoc xong!"<<endl;
}




