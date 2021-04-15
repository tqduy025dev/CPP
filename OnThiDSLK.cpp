#include<iostream>
#include<vector>
#include<math.h>


using namespace std;


class PhanSo{
	private:
		int tu;
		int mau;
	public:
		PhanSo(int = 0, int =1){}
		
		friend istream &operator >> (istream &in, PhanSo &x);
		friend ostream &operator<<(ostream &out,const PhanSo &x);
		PhanSo operator +(PhanSo &a);
		void rutgonPS();
		void Xuat(){
			cout<<this->tu<<"/"<<this->mau;
		}
};

PhanSo PhanSo::operator +(PhanSo &a){
	PhanSo kq; 
			kq.tu = this->tu * a.mau + this->mau * a.tu;
			kq.mau = this->mau * a.mau;
		return kq;
}

istream &operator >> (istream &in, PhanSo &x){
	cout<<"Nhap tu: ";
	in>>x.tu;
	cout<<"Nhap mau: ";
	in>>x.mau;
	return in;
}

ostream &operator <<(ostream &out,const PhanSo &x){
			out<<x.tu<<"/"<<x.mau;
			return out;
		}



void PhanSo::rutgonPS(){
	int a,b;
    PhanSo ps;
    ps.tu=this->tu;
    ps.mau=this->mau;
//Hàm tìm UCLN
    a = abs(tu);
    b = abs(mau);
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    tu=this->tu/a;
    mau=this->mau/a;
    
} 


int main(){
	
	PhanSo a;
	PhanSo b;
	cin>>a;
	cout<<a<<"ssssss"<<endl;
	cin>>b;
	
	cout<<(a+b);


	return 0;
}
