#include<iostream>
#include<string>
using namespace std;
//lop Xe
class Xe
{
protected:
	string BienSo;
	float TrongLuong;
public:
	Xe();
	~Xe();
	friend istream &operator >>(istream &, Xe &);
	friend ostream &operator <<(ostream &, Xe);
	void Input();
};

Xe::Xe()
{
}

Xe::~Xe()
{
}
istream &operator >>(istream &is, Xe &x)
{
	fflush(stdin);
	cout << "Nhap Bien So Xe : ";
	getline(is, x.BienSo);
	cout <<"\nNhap Trong Luong Xe : ";
	is >> x.TrongLuong;
	getchar();
	return is;
}
ostream &operator <<(ostream &os, Xe x)
{
	os << "Bien So Xe : " << x.BienSo;
	os << "Trong Luong Xe : " << x.TrongLuong;
	return os;
}


void Xe::Input(){
	cin.clear();	
	cout << "Nhap Bien So Xe : ";
	getline(cin, this->BienSo);
	cout <<"\nNhap Trong Luong Xe : ";
	cin >> this->TrongLuong;
}







//lop XeCon ke thua lop Xe
class XeCon :public Xe
{
public:
	XeCon();
	~XeCon();
	friend istream &operator >>(istream &, XeCon &);
	friend ostream &operator <<(ostream &, XeCon );
	int Get_ChoNgoi();
	void Set_ChoNgoi(int);
	float Get_TrongLuong();
	void Set_TrongLuong(float);
private:
	int ChoNgoi;
};

XeCon::XeCon()
{
}

XeCon::~XeCon()
{
}
istream &operator >>(istream &is, XeCon &x)
{
	x.Input();
	cout << "\n Nhap So Cho Ngoi : ";
	is >> x.ChoNgoi;
	getchar();
	return is;
	
//	Xe *a = static_cast<Xe*>(&x);
//	is >> *a;
//	cout << "\n Nhap So Cho Ngoi : ";
//	is >> x.ChoNgoi;
//	getchar();
//	return is;
}
ostream &operator <<(ostream &os, XeCon x)
{
	Xe a = static_cast<Xe>(x);
	os << a;
	os << "\n So Cho Ngoi : " << x.ChoNgoi;
	return os;
}
int XeCon::Get_ChoNgoi()
{
	return ChoNgoi;
}
void XeCon::Set_ChoNgoi(int x)
{
	ChoNgoi = x;
}
float XeCon::Get_TrongLuong()
{
	return TrongLuong;
}
void XeCon::Set_TrongLuong(float x)
{
	TrongLuong = x;
}
//lop Xe tai ke thua lop Xe
class XeTai : public Xe
{
public:
	XeTai();
	~XeTai();
	friend istream &operator >>(istream &, XeTai &);
	friend ostream &operator <<(ostream &, XeTai);
	float Get_TrongLuong();
	void Set_TrongLuong(float);
	float Get_TaiTrong();
	void Set_TaiTrong(float);
private:
	float TaiTrong;
};

XeTai::XeTai()
{
}

XeTai::~XeTai()
{
}
istream &operator >>(istream &is, XeTai &x)
{
	Xe *a = static_cast<Xe*>(&x);
	is >> *a;
	cout << "\n Nhap Tai Trong : ";
	is >> x.TaiTrong;
	getchar();
	return is;
}
ostream &operator <<(ostream &os, XeTai x)
{
	Xe a = static_cast<Xe>(x);
	os << a;
	os << "\n Tai Trong : " << x.TaiTrong;
	return os;
}
float XeTai::Get_TrongLuong()
{
	return TrongLuong;
}
void XeTai::Set_TrongLuong(float x)
{
	TrongLuong = x;
}
float XeTai::Get_TaiTrong()
{
	return TaiTrong;
}
void XeTai::Set_TaiTrong(float x)
{
	TaiTrong = x;
}

int main()
{
	int n,m;
	cout << "\n Nhap So Luong Xe Con : ";
	cin >> n;
	XeCon *a = new XeCon[n];
	getchar();
	for (size_t i = 0; i < n; i++)
	{
		cout << "\n Nhap Xe Con Thu " << i + 1;
		cin >> a[i];
	}
	cout << "\n Nhap So Luong Xe Tai : ";
	cin >> m;
	XeTai *b = new XeTai[m];
	getchar();
	for (size_t i = 0; i < m; i++)
	{
		cout << "\n Nhap Xe Tai Thu " << i + 1;
		cin >> b[i];
	}
	/*cout << "\n======================XUAT MANG XE CON======================";
	for (size_t i = 0; i < n; i++)
	{
		cout << "\n\n\t Thong Tin Xe Con Thu " << i + 1;
		cout << a[i];
	}*/
	cout << "\n==========XUAT MANG XE CON CO TRONG LUONG DUOI 1 TAN VA KO QUA 5 CHO NGOI=============";
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].Get_ChoNgoi() <= 5 && a[i].Get_TrongLuong() < 1)
		{
			cout << "\n Xe Con Thu " << i + 1;
			cout << a[i];
		}
	}
	
	cout<< "=======XUAT MANG XE TAI TRONG LUONG LON HON 5 TAN VA TRONG TAI IT NHAT==========";
	for (size_t i = 0; i < m; i++)
	{
		float min = b[0].Get_TaiTrong();
		for (size_t j = 0; j < m; i++){
			if(b[j].Get_TaiTrong() < min){
				min = b[j].Get_TaiTrong();
			}
		}
		if (b[i].Get_TrongLuong() > 5 )
		{
			cout << "\n Xe Con Thu " << i + 1;
			cout << b[i];
		}
	}
	
	
	
	
	
	/*
	cout << "\n======================XUAT MANG XE TAI======================";
	for (size_t i = 0; i < m; i++)
	{
		cout << "\n\n\t Thong Tin Xe Con Thu " << i + 1;
		cout << b[i];
	}
	*/
	cout << "\n";
	system("pause");
	return 0;
}
