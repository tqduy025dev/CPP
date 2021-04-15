#include<iostream>
#include <vector>

using namespace std;

class DoanVien{
	private:
		int maDV;
		string hoten;
		int tuoi;
		string gioitinh;
	public:
		DoanVien(){
		};
		
			void NhapDV(){
			cout<<"Nhap ma doan vien: ";
			cin>>maDV;
			cout<<"Nhap ho ten: ";
			cin.ignore();
			getline(cin, hoten);
			cout<<"Nhap tuoi: ";
			cin>>tuoi;
			cout<<"Nhap gioi tinh: ";
			cin.ignore();
			getline(cin, gioitinh);
		}
	
		void XuatDV(){
			cout<<"Ma doan vien: "<<maDV<<endl;
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Gioi tinh: "<<gioitinh<<endl;
		}
};




int main(){
	vector <DoanVien> array;
	vector <DoanVien>::iterator iter; //  con tro itertor 

	DoanVien a1;
	DoanVien a2;
	DoanVien a3;
	a1.NhapDV();
	a2.NhapDV();
	a3.NhapDV();
	
	cout<<endl;
 // them vao phan tu cuoi
	array.push_back(a1);
	array.push_back(a2);
	array.push_back(a3);

	
	

	cout<<"danh sach doan vien : "<<array.size()<<endl;
	for(int i = 0; i < array.size(); i++) // duyet tung phan tu thong qua iterator
	{
		array[i].XuatDV();
		cout<<endl;
	}

	return 0;
}

	
