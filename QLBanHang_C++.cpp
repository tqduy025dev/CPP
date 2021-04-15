#include<iostream>
#include<string>
using namespace std;


class MatHang{
	private: 
		string tenMH;
		int soLuong;
		double donGia;
	public:
		MatHang();
		~MatHang();
		MatHang(string tenMH, int soLuong, double donGia);
		double Tien();
		void NhapMH();
		void XuatMH();
		
		friend istream &operator>>(istream &in, MatHang &mh){
			cout<<"Nhap ten mat hang: ";
			cin.ignore();
			getline(in,mh.tenMH);
			cout<<"Nhap so luong: ";
			in>>mh.soLuong;
			cout<<"Nhap don gia: ";
			in>>mh.donGia;
			return  in;
		}
		friend ostream &operator<<(ostream &out, MatHang &mh){
			cout<<"Ten mat hang: "<<mh.tenMH<<endl;
			cout<<"So luong: "<<mh.soLuong<<endl;
			cout<<"Don gia: "<<mh.donGia<<endl;
			cout<<"==>Thanh tien: "<<mh.Tien()<<endl;
		}
};

MatHang::MatHang(){};
MatHang::~MatHang(){};

MatHang::MatHang(string tenMH, int soLuong, double donGia){
	this->tenMH = tenMH;
	this->soLuong = soLuong;
	this->donGia = donGia;
}

double MatHang::Tien(){
	return (soLuong * donGia);
}

void MatHang::NhapMH(){
	
	cout<<"Nhap ten mat hang: ";
	cin.ignore();
	getline(cin, tenMH);
	cout<<"Nhap so luong: ";
	cin>>soLuong;
	cout<<"Nhap don gia: ";
	cin>>donGia;
}

void MatHang::XuatMH(){
	cout<<"Ten mat hang: "<<tenMH<<endl;
	cout<<"So luong: "<<soLuong<<endl;
	cout<<"Don gia: "<<donGia<<endl;
}




//**********************************************//
class HoaDon{
	private:
		string tenHD;
		int soluongMH;
		MatHang *dsmh;
	public :
		HoaDon();
		HoaDon(string tenHD, int soluongMH, MatHang *dsmh);
		~HoaDon();
		void NhapHD();
		void XuatHD();
		double TongTien();
		void timkiemHD( int n);
	
};

HoaDon::HoaDon(){}

HoaDon::~HoaDon(){}

HoaDon::HoaDon(string tenHD, int soluongMH, MatHang *dsmh){
	this->tenHD = tenHD;
	this->dsmh = dsmh;
	this->soluongMH = soluongMH;
}

void HoaDon::NhapHD(){
	cout<<"Nhap ten hoa don: ";
	cin.ignore();
	getline(cin, tenHD);
	cout<<"Nhap so luong mat hang ";
	cin>>soluongMH;
	cout<<"\n";
	dsmh = new MatHang[soluongMH];
	for(int i=0; i<soluongMH; i++){
		cout<<"===>Nhap thong tin mat hang thu: "<<i+1<<endl;
		cin>>*(dsmh+i);
	}
	cout<<"\n";
}

void HoaDon::XuatHD(){
	cout<<"Ten hoa don: "<<tenHD<<endl;
	cout<<"So luong cac mat hang: "<<soluongMH<<endl<<endl;
	for(int i=0 ; i<soluongMH; i++){
		cout<<*(dsmh+i);
	}
	cout<<"TONG TIEN HOA DON: "<<TongTien()<<endl;
}

void HoaDon::timkiemHD( int n){
	string x;
	cout<<"Nhap ten hoa don can tim: ";
	cin.ignore();
	getline(cin, x);
	for(int i=0; i<n; i++){
		if(x == this->tenHD){
			XuatHD();
			return;
		}
		else{
			cout<<"Khong tim thay ten hoa don";
		}
	}
	
}

double HoaDon::TongTien(){
	double sum = 0;
	for(int i = 0; i< soluongMH; i++){
		sum = sum + (dsmh+i)->Tien();
	}
	return sum;
}

int main(){	
	HoaDon *hd;
	int n, choose;
	cout<<"Nhap so luong hoa don: ";
	cin>>n;
	hd = new HoaDon[n];
	
	for(int i=0; i<n; i++){
		cout<<">>----->>Nhap thong tin hoa don thu "<<i+1<<"<<------<<"<<endl;
		(hd+i)->NhapHD();
	}
		
	for(int i=0; i<n; i++){
		cout<<"\n========Thong tin hoa don thu "<<i+1<<"========="<<endl;
		(hd+i)->XuatHD();
	}
	
	cout<<"\n-------------Nhan phim 1 de tim kiem hoa don-------------\n";
	cin>>choose;
	if(choose == 0){
		system("cls");
		hd->timkiemHD(n);
	}
	system("pause");
	return 0;
}
