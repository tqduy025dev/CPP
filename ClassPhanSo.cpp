#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class PhanSo{
	private:
		int tu, mau;
		
	public:
		PhanSo rutGon();
		void SoSanhPS( PhanSo b);
		void nhapPhanSo();
		void xuatPhanSo(){
			cout<<tu<<"/"<<mau;
		}
		
		// nap chong toan tu nhap xuat
		friend istream &operator >>(istream &in,PhanSo &x){
			cout<<"\nNhap tu: ";
			in>>x.tu;
			cout<<"\nNhap mau: ";
			in>>x.mau;
			return in;
		}
		
			friend ostream &operator <<(ostream &out,const PhanSo &x){
			out<<x.tu<<"/////="<<x.mau;
			return out;
		}
		
	
		PhanSo operator +(PhanSo b);
		PhanSo operator -(PhanSo b);
		PhanSo operator *(PhanSo b);
		PhanSo operator /(PhanSo b);
		bool operator >(PhanSo b){
			if(this->tu > b.tu){
				return true;
			}else{
				return false;
			}
		}
};

void PhanSo::nhapPhanSo(){ 
			cout<<" \n Tu so: "; cin>>this->tu; // mac dinh cua mac dinh
		do{
			cout<<" Mau so: "; cin>>mau;
			if(mau==0){
				cout<<" Nhap sai, nhap lai:\n";
				}
		}while(mau==0);
}

void PhanSo::SoSanhPS(PhanSo b){
	int n,m;
	m = abs(this->tu) * abs(b.rutGon().mau);
	n = abs(this->mau) * abs(b.rutGon().tu);

		if(m>n){
			cout<<"\n Phan so "; xuatPhanSo(); cout<<" > "; b.xuatPhanSo();
		}
		if(m<n){
			cout<<"\n Phan so "; xuatPhanSo(); cout<<" < "; b.xuatPhanSo();
		}
		if(m==n){
			cout<<"\n Phan so "; xuatPhanSo(); cout<<" = "; b.xuatPhanSo();
		}
}


PhanSo PhanSo::rutGon(){
    int a,b;
    PhanSo ps;
    ps.tu=this->tu;
    ps.mau=this->mau;
//Hàm tìm UCLN
    a = abs(ps.tu);
    b = abs(ps.mau);
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    ps.tu=tu/a;
    ps.mau=mau/a;
    
    return ps; 
}

PhanSo PhanSo::operator +(PhanSo b){
			PhanSo kq; 
			kq.tu = tu * b.mau + mau * b.tu;
			kq.mau = mau * b.mau;
		return kq;
}

PhanSo PhanSo::operator -(PhanSo b){
			PhanSo kq;
			kq.tu = tu * b.mau - mau * b.tu;
			kq.mau = mau * b.mau;
		return kq;
}

PhanSo PhanSo::operator *(PhanSo b){
			PhanSo kq;
			kq.tu = tu * b.tu;
			kq.mau = mau * b.mau;
		return kq;
}



PhanSo PhanSo::operator /(PhanSo b){
			PhanSo kq;
			kq.tu = tu * b.mau;
			kq.mau = mau * b.tu;
		return kq;
}

int main(){
	PhanSo a, b, tong, hieu, tich, thuong;
	cout<<" Nhap phan so 1: "; 
	cin>>a;
	
	//a.nhapPhanSo();
	cout<<"\n Nhap phan so 2: ";
	cin>>b;
	
	// b.nhapPhanSo();
	cout<<a+b;
	tong = a + b; 
	hieu = a.operator -(b);
	tich = a.operator *(b);
	thuong = a.operator *(b);
	
//	a.SoSanhPS(b); 
	if(a>b){
		cout<<"asdfa";
	}
PhanSo kkk;
kkk = tong.rutGon();
	cout<<"\n Tong 2 Phan So la: "; cout<<kkk; //tong.rutGon().xuatPhanSo();
	cout<<"\n Hieu 2 Phan So la: "; hieu.rutGon().xuatPhanSo();
	cout<<"\n Tich 2 Phan So la: "; tich.rutGon().xuatPhanSo();
	cout<<"\n Thuong 2 Phan So la: "; thuong.rutGon().xuatPhanSo();
	
	
	return 0;
}
