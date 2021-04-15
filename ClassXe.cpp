//#include<iostream>
#include<string>
//#include<vector>
#include<stdio.h>

using namespace std;

class Xe{
	protected :
		string BienSo;
		float TrongLuong;
	public:
		Xe(){};
		~Xe(){};
		void Nhap();
		void Xuat();
		float getTrongLuong();				
};
float Xe::getTrongLuong(){
	return TrongLuong;
}

void Xe::Nhap(){
	cout<<"Nhap Bien So: ";
	fflush(stdin);
	getline(cin, BienSo);
	cout<<"Nhap Trong Luong: ";
	cin>>TrongLuong;
}

void Xe::Xuat(){
	cout<<"Bien so la: "<<BienSo<<endl;
	cout<<"Trong luong la: "<<TrongLuong<<endl;
}

//=====================================================================//
class XeCon : public Xe{
	private: 
		int slChoNgoi;
	public:
		XeCon(){};
		~XeCon(){};
		
		friend istream &operator >> (istream &in, XeCon &x);
		friend ostream &operator << (ostream &out, XeCon &x);
		
		void NhapDSXeCon(XeCon *xc, int n);
		void XuatDSXeCon(XeCon *xc, int n);
		int getChoNgoi();
};

void XeCon::NhapDSXeCon(XeCon *xc, int n){
	for(int i=0; i<n; i++){
		cin>>*(xc+i);
		cout<<endl;
	}
}

void XeCon::XuatDSXeCon(XeCon *xc, int n){
	for(int i=0; i<n; i++){
		if(xc[i].getTrongLuong() < 1 && xc[i].getChoNgoi() <= 5)
		cout<<*(xc+i);
		cout<<endl;
	}
}

int XeCon::getChoNgoi(){
	return slChoNgoi;
}

istream &operator >> (istream &in, XeCon &x){
	x.Nhap();
	cout<<"Nhap so luong cho ngoi: ";
	in >> x.slChoNgoi;
	return in;
}

ostream &operator << (ostream &out, XeCon &x){
	x.Xuat();
	out<<"So luong cho ngoi la: "<<x.getChoNgoi()<<endl;
	return out;
}


//================================================================================/
class XeTai : public Xe{
	private:
		float TaiTrong;
	public:
		XeTai(){};
		~XeTai(){};
		
		friend istream &operator >> (istream &in, XeTai &x);
		friend ostream &operator << (ostream &out,XeTai &x);
		void NhapDSXeTai(XeTai *xt, int m);
		void XuatDSXeTai(XeTai *xt, int m);
		float minTaiTrong(XeTai *xt, int m);
		float getTaiTrong();	
};

float XeTai::getTaiTrong(){
	return TaiTrong;
}

void XeTai::NhapDSXeTai(XeTai *xt, int m){
	for(int i=0; i<m; i++){
		cin>>xt[i]; // con tro thi dung *(xt+i) 
		cout<<endl;
	}
}

float XeTai::minTaiTrong(XeTai *xt, int m){
	vector<XeTai> t;
	float min;
	for(int i=0; i<m; i++){
		if(xt[i].getTrongLuong() > 5){
			t.push_back(xt[i]);
		}
	}
	min = t[0].getTaiTrong();
	for(int j=0; j<t.size(); j++){
		if(min > t[j].getTaiTrong()){
			min = t[j].getTaiTrong();
		}
	}
	return min;
}

void XeTai::XuatDSXeTai(XeTai *xt, int m){
	float temp = minTaiTrong(xt,m);
	for(int i=0; i<m; i++){
		if(xt[i].getTrongLuong() > 5 && xt[i].getTaiTrong() == temp)
		cout<<*(xt+i);
		cout<<endl;
	}
}

istream &operator >> (istream &in, XeTai &x){
	x.Nhap();
	cout<<"Nhap Tai Trong: ";
	in>>x.TaiTrong;
	return in;
}

ostream &operator << (ostream &out, XeTai &x){
	x.Xuat();
	out<<"Tai trong la: "<<x.getTaiTrong()<<endl;
	return out;
}





int main(){
	int m, n;
	cout<<"Nhap so luong xe con: ";
	cin>>n;
	XeCon *a = new XeCon[n];
	a->NhapDSXeCon(a, n);
	
	system("cls");
	cout<<"Nhap so luong xe tai: ";
	cin>>m;
	XeTai *b = new XeTai[m];
	b->NhapDSXeTai(b, m);
	
	
	cout<<"DS xe con co trong luong < 1 tan va co so cho ngoi <= 5  la: "<<endl;
	a->XuatDSXeCon(a, n);
	

	cout<<"DS xe tai co trong luong > 5 va co trong tai nho nhat la: "<<endl;
	b->XuatDSXeTai(b, m);
	
	return 0;
}
