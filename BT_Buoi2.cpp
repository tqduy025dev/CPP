#include<iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};
typedef struct node NODE;
typedef NODE* tree;


void createTree(tree &t){
	t = NULL;
}

void addNode(tree &t, int x){
	if(t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if(t->data > x){
			addNode(t->left,x);
		}else if(t->data < x){
			addNode(t->right,x);
		}
	}
}

void leftNodeRight(tree &t){
	if(t !=  NULL){
		leftNodeRight(t->left);
		cout<<t->data<<"  ";
		leftNodeRight(t->right);
	}
}

void nodeLeftRight(tree &t){
	if(t !=  NULL){
		cout<<t->data<<"  ";
		nodeLeftRight(t->left);
		nodeLeftRight(t->right);
	}
}

void leftRightNode(tree &t){
	if(t !=  NULL){
		leftRightNode(t->left);
		leftRightNode(t->right);
		cout<<t->data<<"  ";
	}
}

bool searchKey(tree t, int key){
	if(t != NULL){
		if(t->data == key){
			return true;
		}
		if(t->data > key) return searchKey(t->left,key);
		if(t->data < key) return searchKey(t->right,key);
	}
	return false;
}

void deleteTree(tree &t){
	if(t == NULL) return;
	deleteTree(t->left);
	deleteTree(t->right);
	free(t);
}

void MENU(tree &t){
	int n, x, choose, key;
	do{
		cout<<"\n\n\t\t\t============MENU============="<<endl;
		cout<<"\t\t\t1. Nhap du lieu cho cay"<<endl;
		cout<<"\t\t\t2. Duyet NLR"<<endl;
		cout<<"\t\t\t3. Duyet LNR"<<endl;
		cout<<"\t\t\t4. Duyet LRN"<<endl;
		cout<<"\t\t\t5. Tim phan tu trong cay"<<endl;
		cout<<"\t\t\t0. Thoat"<<endl<<endl;
		cout<<"\t\t\t============MENU============="<<endl;
		cout<<"\t\t\tNhap lua chon ";
		cin>>choose;
		switch(choose){
			case 1:
				cout<<"\t\t\tNhap so luong phan tu cua cay n= ";
				cin>>n;
				cout<<endl;
				for(int i = 1; i <= n; i++){
					cout<<"\t\t\tNhap gia tri ";
					cin>>x;
					addNode(t,x);
				}
				break;
			case 2:
				system("cls");
				cout<<"\t\t\tPhan tu trong cay la: ";nodeLeftRight(t);
				break;
			case 3:
				system("cls");
				cout<<"\t\t\tPhan tu trong cay la: ";leftNodeRight(t);
				break;
			case 4:
				system("cls");
				cout<<"\t\t\tPhan tu trong cay la: ";leftRightNode(t);
				break;
			case 5:
				cout<<"\t\t\tNhap du lieu can tim x = ";
				cin>>key;
				system("cls");
				if(searchKey(t,key)){
					cout<<"\t\t\tDu lieu da co trong cay";
				}else{
					cout<<"\t\t\tDu lieu khong co trong cay";
				}
				break;
		}
	}while(choose != 0);
}

int main(){
	tree t;
	createTree(t);
	
	MENU(t);
	
	deleteTree(t);
	return 0;
}
