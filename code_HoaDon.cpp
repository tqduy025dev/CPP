#include<iostream>
using namespace std;
class MH{
	private:
        char tmh [30];
        int sl;
        float dg;
    public:
    	int getSL();
    	float getDG();
    	float tien();
        void nhap();
        void xuat();
};
class HD{
	private:
        char thd[30];
        char dsmh[30];
        int slmh;
        MH *mh;
    public:
        void nhap();
        void xuat();
        float tongt(float *t,int n);
};
int MH::getSL(){
	return sl;
}
float MH::getDG(){
	return dg;
}
void MH::nhap()
{
    cout <<"ten mat hang: "; 
	cin>>tmh;
    cout<<"so luong: "; 
	cin>>sl;
    cout<<"don gia: "; 
	cin>>dg;
}
void MH::xuat()
{
    cout<<"\tTen mat hang: "<<tmh<<endl;
    cout<<"\tSo luong: "<<sl<<endl;
    cout<<"\tDon gia: "<<dg<<endl;
    cout<<"-- Thanh tien: "<<tien()<<endl;
}
void HD::nhap(){
	cout<<"Nhap ten hoa don: ";
	cin>>thd;
	cout<<"Nhap danh muc hang: ";
	cin>>dsmh;
	cout<<"Nhap so luong hang: ";
	cin>>slmh;
	mh=new MH[slmh];
	for(int i=0;i<slmh;i++){
		(mh+i)->MH::nhap();
	}
}
void HD::xuat(){
	float *a, S=0;
	cout<<"Ten hoa don: "<<thd<<endl;
	cout<<"Danh muc hang: "<<dsmh<<endl;
	cout<<"So luong mat hang: "<<slmh<<endl;
	for(int i=0;i<slmh;i++){
		(mh+i)->MH::xuat();
		*a=(mh+i)->tien();
		S=S+tongt(a,slmh);
	}
	cout<<"--> Tong tien hoa don: "<<S<<endl;
}
float MH::tien(){
	return dg*sl;
}
float HD::tongt(float *t,int n){
	float S=0;
	for(int i=0;i<n;i++){
		S=S + *(t+i);
	}
	return S;
}
int main(){
	HD *hd;
	int n;
	cout<<"Nhap so luong hoa don: ";
	cin>>n;
	hd=new HD[n];
	for(int i=0;i<n;i++){
		cout<<"****Nhap thong tin hoa don thu "<<i<<endl;
		(hd+i)->nhap();
	}
	for(int i=0;i<n;i++){
		cout<<"****Xuat thong tin hoa don thu "<<i<<": "<<endl;
		(hd+i)->xuat();
	}
}
