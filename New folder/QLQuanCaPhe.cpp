#include<stdio.h>
#include<string.h>
#include<conio.h>



struct SanPham{
	int maSP;
	int soBan;
	char tenSP[100];
	float giaSP;
	int soluongSP;
};

void NhapSP(SanPham &sp){
	printf("Ma san pham :");
	scanf("%d",&sp.maSP);
	
	printf("So ban:");
	scanf("%d",&sp.soBan);
	
	printf("Ten san pham :");
	fflush(stdin);
	scanf("%s",&sp.tenSP);
	
	printf("Gia san pham :");
	scanf("%f",&sp.giaSP);
	
	printf("So luong :");
	scanf("%d",&sp.soluongSP);
}

void XuatSP(SanPham sp){
	printf("\n-Ma san pham : %d", sp.maSP);
	
	printf("\nSo ban: %d", sp.soBan);
	
	printf("\nTen san pham : %s", sp.tenSP);
	
	printf("\nGia san pham : %f", sp.giaSP);
	
	printf("\nSo luong : %d\n", sp.soluongSP);
}


struct Node{
	SanPham sp;
	Node* next;
};


struct DanhSach
{
	Node* head;
	Node* tail;
};

Node* TaoNode(SanPham init_sp)
{
	Node* node = new Node;
	node->sp = init_sp;
	node->next = NULL;   
	
	return node;
}


void TaoDanhSach (DanhSach &ds){
	ds.head = ds.tail = NULL;
}


void ThemNodeVaoDS(DanhSach &ds)
{
	SanPham sp;
	printf("Nhap thong tin san pham\n");
	NhapSP(sp);
   
   Node *node = TaoNode(sp);
	
	if (ds.head == NULL)
	{
		ds.head = node;
		ds.tail = node;
	}
	else
	{
		ds.tail->next = node;
		ds.tail = node;
	}
}



void TimKiem(DanhSach &ds){
	int x, pos = 0;
	bool msg = false;
	printf("Nhap du lieu can tim: ");
	scanf("%d",&x);
	if(ds.head == ds.tail && ds.tail == NULL){
		printf("Danh sach rong khong the tim!");
	}
	
	for(Node *p = ds.head; p != NULL ; p = p->next){
		pos++;
		if(p->sp.maSP == x){
			printf("Du lieu nay o vi tri thu %d trong danh sach",pos);
			msg = true;
		}
	}
	
	if(!msg){
		printf("Khong tim thay trong danh sach");
	}
}



void XoaNode(DanhSach &ds)
{
	int x, i = 0; // i dem phan tu trong node
	printf("Nhap vi tri muon xoa  "); //xoa theo vi tri, Muon xoa theo món thì dieu kien khac ~~ suy nghi thu xem
	scanf("%d", &x);
	
	if(ds.head == ds.tail && ds.tail == NULL){
		printf("Danh sach rong khong the xoa!");
	}else{
		for(Node *p = ds.head; p != NULL ; p = p->next ){
			i++;
			if(x == 1){
				ds.head = p->next;
				delete p;
				return;
			}
			if(i == x-1){
				Node *t, *h;
				t = p->next;
				h = t->next;   // cach khac: p->next = t->next, khong can phai khai bao them *h
				p->next = h;
				delete t;
				return;
			}
			if(x > i){
				printf("Ngoai pham vi\n");
				return;
			}
		}
	}
	
}

void XuatDanhSach(DanhSach &ds){
	for(Node *t = ds.head; t != NULL ; t = t->next){
		XuatSP(t->sp);
	}
}








int main(){
	
	DanhSach s1;
	
	TaoDanhSach(s1);
	
	ThemNodeVaoDS(s1);
	ThemNodeVaoDS(s1);
	
//	XoaNode(s1); 
	TimKiem(s1);

	XuatDanhSach(s1);
	
		

	
	
	getch();
	return 0;
	
}
