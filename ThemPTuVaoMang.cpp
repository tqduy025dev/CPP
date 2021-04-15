#include<stdio.h>
#include<conio.h>
#include<math.h>
void nhapmang(int a[], int n){
	for(int i=0;i<n;i++){ // nhap 8 ptu thi mang no chay tu a0 -> a7
		printf("phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
}
void xuatmang(int a[], int n){
	int dem = 0;
	for(int i=0;i<n;i++){
		dem++;
		if(dem == 10){
			printf("%d\t",a[i]);
			printf("\n");
			dem = 0;
		}else{
			printf("%d\t",a[i]);
		}
		
	}	
}

//phan tu lon nhat, phan tu nho nhat
void PhanTuLonNhat(int a[], int n){
	int max=a[0];
	for(int i=1;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	printf("\nPhan tu lon nhat: %d",max);
}
void PhanTuNhoNhat(int a[], int n){
	int min=a[0];
	for(int i=1;i<n;i++){
		if(min>a[i]){
			min=a[i];
		}
	}
	printf("\nPhan tu nho nhat: %d",min);
}
//vi tri phan tu duong nho nhat
void ViTri(int a[], int n){
	int min, dem=1;
	for(int i=0;i<n;i++){
		if(min>a[i]){
			min=a[i];
			dem=i+1;
		}
	}
	printf("\nPhan tu duong nho nhat xuat hien tai vi tri %d trong mang",dem);	

}
// tinh tong mang
float TinhTong(int a[], int n){
	int S=0;
	for(int i=0;i<n;i++){
		S=S+a[i];
	}
	return S;
}
// tinh trung binh cong 
float TBC(int a[], int n){
	int tbc=0, dem=0;
	float kq;
	for(int i=0;i<n;i++){
		tbc=tbc+a[i];
		dem++;
	}
	kq=((float)tbc/dem);
	return kq;
}
//tinh trung binh nhan
float TBN(int a[], int n){
	int dem=0, S=1;
	float kq;
	for(int i=0;i<n;i++){
		S=S*a[i];
		dem++;
	}
	kq= pow(S,(float)1/dem);
	return kq;
}




// sap xep mang theo thu tu tang dan
void SapXep1(int a[], int n){
	int t;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				t = a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
// sap xep mang theo thu tu giam dan
void SapXep2(int a[], int n){
	int t;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
// xuat day dao nguoc cua day ban dau
void DaoNguoc(int a[], int n){
	for(int i = n-1; i >= 0; i--){		
		printf("%d\t",a[i]);
	}
}
//Them ptu vao vi tri bat ki
void ThemPhanTu(int a[], int &n){
	n++;
	int x,k;
	printf("\nNhap x: ");
	scanf("%d",&x);
	printf("\nNhap vi tri can them: ");
	scanf("%d",&k);
	for(int i=n-1;i>k-1;i--){
		a[i]=a[i-1];
	}
	a[k-1]=x;
}
void XoaPhanTu(int a[], int &n){
	int k;
	printf("\nNhap vi tri can xoa : ");
	scanf("%d",&k);
    for(int i=k-1;i<n-1;i++){   
    	a[i]=a[i+1];			
	}						
	n--;

}
/*
for(int i=n-1;i>k+1;i--)
        a[i]=a[i-1];    
     
    a[k+1]=x;

	  1 2 3//4 5 6 7 8
	nhap x = 20 tai vi tri thu 3
	thi a[0] -> a[2] la giu nguyen gia tri
	vi tri thu 4 tro ve sau thi se gan lai gia tri
	VD : 10 20 30/40 50 60 70 80
		a0 a1 a2 a3 a4 a5 a6 a7
		-----------------------
		 10 20 50  30/40 50 60 70 80
		 a0 a1 a2 a3 a4 a5 a6 a7 a8
		 
		 a8 moi them, luc dau chua co
		 
		 a[8] = a[7]; a[8]= 80
		 a[7] = a[6]; a[7]= 70
		 ...
		 a[3] = a[2]; a[3]= 30
		a[2] == x;
*/




int main(){
	int a[1000];
	int n;
	
	printf("Nhap n: ");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("Mang ban dau:\n");
	xuatmang(a,n);
	
//	printf("\nMang dao nguoc: \n");
//	DaoNguoc(a,n);
	
	printf("\nMang sap xep theo thu tu giam dam:\n");
	SapXep2(a,n);
	xuatmang(a,n);
	
//	ThemPhanTu(a,n);
//	xuatmang(a,n);
	
//	XoaPhanTu(a,n);
//	xuatmang(a,n);
	
//	printf("\nMang sap xep theo thu tu tang dan:\n");
//	SapXep1(a,n);
//	xuatmang(a,n);
	

	
//	ThemPhanTu(a,n);
//	xuatmang(a,n);
//	
//	XoaPhanTu(a,n);
//	xuatmang(a,n);
	
	getch();
}
