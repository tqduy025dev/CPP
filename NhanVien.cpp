#include<iostream>
#include<string>
#include<stack>
#include<conio.h>


using namespace std;


class NhanVien{
	private:
		long long int MNV;
		string HoTen;
		int NamSinh;
		string PhongBan;
		double Luong;
	public:
		NhanVien();
		NhanVien(int MNV, string HoTen, int NamSinh, string PhongBan, double Luong);
		~NhanVien();
		double getLuong();
		int getNamSinh();
		string getHoTen();
		friend istream &operator >> (istream &in, NhanVien &nv);
		friend ostream &operator << (ostream &out, NhanVien &nv);
		bool operator > (NhanVien nv);
		bool operator < (NhanVien nv);
		bool operator == (NhanVien nv);
					
};


NhanVien::NhanVien(){
	this->MNV =0;
	this->HoTen ="";
	this->NamSinh = 0;
	this->PhongBan ="";
	this->Luong = 0;
}

NhanVien::NhanVien(int MNV, string HoTen, int NamSinh, string PhongBan, double Luong){
	this->MNV = MNV;
	this->HoTen = HoTen;
	this->NamSinh = NamSinh;
	this->PhongBan = PhongBan;
	this->Luong = Luong;
}

NhanVien::~NhanVien(){}

double NhanVien::getLuong(){
	return this->Luong;
}

int NhanVien::getNamSinh(){
	return this->NamSinh;
}

string NhanVien::getHoTen(){
	return this->HoTen;
}

istream &operator >> (istream &in, NhanVien &nv){
	cout<<"\t\tNhap ma nhan vien: ";
	in>>nv.MNV;
	cout<<"\t\tNhap ho ten: ";
	cin.ignore();
	getline(in,nv.HoTen);
	cout<<"\t\tNhap nam sinh: ";
	in>>nv.NamSinh;
	cout<<"\t\tNhap phong ban: ";
	cin.ignore();
	getline(in, nv.PhongBan);
	cout<<"\t\tNhap luong: ";
	in>>nv.Luong;
	cout<<endl;
	return in;
}

ostream &operator << (ostream &out, NhanVien &nv){
	out<<"\t\tMa nhan vien \t\t: "<<"UTC"<<nv.MNV<<endl;
	out<<"\t\tHo ten nhan vien \t: "<<nv.HoTen<<endl;
	out<<"\t\tNam sinh \t\t: "<<nv.NamSinh<<endl;
	out<<"\t\tPhong ban \t\t: "<<nv.PhongBan<<endl;
	out<<"\t\tLuong \t\t\t: "<<nv.Luong<<endl<<endl;
	return out;
}

bool NhanVien::operator < (NhanVien nv){
	if(this->Luong < nv.Luong)
	return 1;
	return 0;
}
bool NhanVien::operator > (NhanVien nv){
	if(this->Luong > nv.Luong)
	return 1;
	return 0;
}
bool NhanVien::operator == (NhanVien nv){
	if(this->Luong == nv.Luong)
	return 1;
	return 0;
}

void swap(NhanVien *a, NhanVien *b){
	NhanVien t;
	t = *a;
	*a = *b;
	*b = t;
}


void NhapListNV(NhanVien *nv, int n){
	for(int i = 0; i<n ;i++){
		cout<<"\t\tNhan vien : "<<i+1<<endl;
		cin>>*(nv+i);
	}
}

void XuatListNV(NhanVien *nv, int n){
	for(int i = 0; i<n ;i++){
		cout<<"\t\tSTT:"<<i+1<<endl;
		cout<<*(nv+i);
	}
}
void sortLuong(NhanVien *nv,int n){
	for(int i = 0; i<n ;i++){
		for(int j=i+1; j<n ;j++){
			if((nv+i)->getLuong()<(nv+j)->getLuong())
			swap((nv+i),(nv+j));
		}
	}
	cout<<"\t\t***************\tDanh Sach Nhan Vien Co Luong Giam Dan\t*************************"<<endl;
	XuatListNV(nv,n);
}

void sortNamSinh(NhanVien *nv,int n){
	for(int i = 0; i<n ;i++){
		for(int j=i+1; j<n ;j++){
			if((nv+i)->getNamSinh()>(nv+j)->getNamSinh())
			swap((nv+i),(nv+j));
		}
	}
	cout<<"\t\t***************\tDanh Sach Nhan Vien Co Nam Sinh Tang Dan\t******************"<<endl;
	XuatListNV(nv,n);
}

string catTen(NhanVien *nv){
	string str = nv->getHoTen();
	string temp;
	stack <string> t;
	str.append(" ");
	for(int i = 0; i<str.length(); i++){
		for(int j=i+1; j<str.length(); j++){
			if(str[j] == ' '){
				temp = str.substr(i,j-i);
				i = j+1;
				t.push(temp);
			}
		}
	}
	return t.top();
}

void sortTen(NhanVien *nv,int n){
	for(int i = 0; i<n ;i++){
		for(int j=i+1; j<n ;j++){
			if( catTen(nv+i) > catTen(nv+j)){
				swap((nv+i),(nv+j));
			}
		}
	}
	cout<<"\t\t***************\tDanh Sach Nhan Vien Sap Xep Theo Ten\t*************************"<<endl;
	XuatListNV(nv,n);
}


void ThongKeLuong(NhanVien *nv, int n){
	int sl=0;
	for(int i = 0; i<n ;i++){
		double t = (nv+i)->getLuong();
		if(t>=10000000){
			sl++;
		}
	}
	cout<<"\t\t***************\tSo luong nhan vien luong >= 10 trieu la: "<<sl<<"\t******************"<<endl;
}




int main(){
	NhanVien *nv;
	int n;
	int choose;
	do{
		system("color F4");
		cout<<"\t\t------------------------------QUAN LY NHAN VIEN-----------------------------------"<<endl;
		cout<<"\t\t||\t\t\t\t\t\t\t\t\t\t||"<<endl;
		cout<<"\t\t||1. Nhap danh sach nhan vien \t\t\t\t\t\t\t||"<<endl;
		cout<<"\t\t||2. Xem danh sach nhan vien da duoc sap xep theo ten \t\t\t\t||"<<endl;
		cout<<"\t\t||3. Xem danh sach nhan vien co luong giam dan \t\t\t\t\t||"<<endl;
		cout<<"\t\t||4. Xem danh sach nhan vien co luong lon hon 10 trieu \t\t\t\t||"<<endl;
		cout<<"\t\t||5. Xem danh sach nhan vien co nam sinh tang dan \t\t\t\t||"<<endl;
		cout<<"\t\t||6. Thoat khoi chuong trinh \t\t\t\t\t\t\t||"<<endl;
		cout<<"\t\t||\t\t\t\t\t\t\t\t\t\t||"<<endl;
		cout<<"\t\t------------------------------QUAN LY NHAN VIEN-----------------------------------"<<endl;
		cout<<"\t\tNhap lua chon: ";
		cin>>choose;
		switch(choose){
			case 1: 
				cout<<"\t\tNhap so luong nhan vien: ";
				cin>>n;
				nv = new NhanVien[n];
				NhapListNV(nv, n);
				break;
			case 2:
				system("cls");
				sortTen(nv,n);
				break;
			case 3:
				system("cls");
				sortLuong(nv,n);
				break;
			case 4:
				system("cls");
				ThongKeLuong(nv,n);
				break;
			case 5:
				system("cls");
				sortNamSinh(nv,n);
				break;
			case 6:
				exit(0);
		}
		
	}while(1);
	
	
	
}
