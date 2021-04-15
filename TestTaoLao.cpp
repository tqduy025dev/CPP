#include<math.h>
#include<stdio.h>
#include<iostream>


struct Diem{
	int x;
	int y;
};


int foo(int n){
	if(n<0)
		return 0;
	if(n==1)
		return 1;
	
	return foo(n-1) +5;
}






void Nhap(Diem a[], int n){
	for(int i=0 ; i<n; i++){
		printf("Nhap x= ");
		scanf("%d",&a[i].x);
		printf("Nhap y= ");
		scanf("%d",&a[i].y);	
	}
		
}


void Xuat(Diem a[], int n){
	for(int i=0 ; i<n; i++){
		printf("Tao do diem thu %d: (%d, %d)\n",(i+1), a[i].x, a[i].y);
	}
}

float KhoangCach(Diem a[], int n){
	float kc = 0;
	for(int i=0 ; i<n-1; i++){ 
		kc = kc + sqrt(pow(a[i].x-a[i+1].y, 2) + pow(a[i].x-a[i+1].y, 2));
	}
	return kc;
}

int main(){
	int n = 3;
//	Diem *a = new Diem[n];
//	
//	Nhap(a, n);
//	Xuat(a, n);
//	
//
//	printf("Khoang cach la: %f",KhoangCach(a,n));


	std::cout<<foo(8);
		
	return 0;
}
