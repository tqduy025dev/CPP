#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;



class Point{
	private: 
	int hoanhdo;
	int tungdo;
	
	public:
	Point();
	Point(int x,int y);
	~Point() { };
	int getHoanhDo(){
		return hoanhdo;
	}
	int getTungDo(){
		return tungdo;
	}
	void setHoanhDo(int x){
		hoanhdo = x;
	}
	void setTungDo(int y){
		tungdo = y;
	}
	friend istream &operator>>(istream &in, Point &x); // overload ham nhap
	friend ostream &operator<<(ostream &out, Point &x);// overload ham xuat
	friend float range(Point a, Point b);						 // khoang cach
	friend bool checkTriangle(Point a, Point b, Point c);// kiem tra 3 diem co tao thanh tam giac hay ko
	friend void isoscelesTriangle(Point a, Point b, Point c);	//kiem tra tam giac can
	friend void perimeter_acreage();							 // chu vi _ dien tich					 
};


//overload toan tu >>
istream &operator>>(istream &in, Point &x){
	cout<<"Hoanh Do: ";
	in>>x.hoanhdo;
	cout<<"Tung Do: ";
	in>>x.tungdo;
	return in;
}
//overload toan tu <<
ostream &operator<<(ostream &out, Point &x){
	out<<"("<<x.getHoanhDo()<<","<<x.getTungDo()<<")";
	return out;
}

Point::Point(){
	this->hoanhdo = 0;
	this->tungdo = 0;
}
Point::Point(int tungdo, int hoanhdo){
	this->hoanhdo = hoanhdo;
	this->tungdo = tungdo;
}


//ham tinh khoang cach
float range(Point a, Point b){
	float t = pow(a.getHoanhDo()-b.getHoanhDo(),2) + pow(a.getTungDo()-b.getTungDo(),2);
	return sqrt(t);
}

//Ham kiem tra co phai la tam giac hay khong
//	Dieu kien : tong 2 canh phai lon hon canh con lai	
bool checkTriangle(Point a, Point b, Point c){
	float x,y,z;
 	 	x = sqrt(pow(a.getHoanhDo()-b.getHoanhDo(),2) + pow(a.getTungDo()-b.getTungDo(),2));
 		y = sqrt(pow(a.getHoanhDo()-c.getHoanhDo(),2) + pow(a.getTungDo()-c.getTungDo(),2));
 		z = sqrt(pow(b.getHoanhDo()-c.getHoanhDo(),2) + pow(b.getTungDo()-c.getTungDo(),2));
 	if((x+y>z) && (x+z>y) && (y+z>x))
 		return true;
	else
		return false;
	
 }
 
// ham kiem tra tam giac can hay khong
void isoscelesTriangle(Point a, Point b, Point c){
 	float x,y,z;
 	 	x = sqrt(pow(a.getHoanhDo()-b.getHoanhDo(),2) + pow(a.getTungDo()-b.getTungDo(),2));
 		y = sqrt(pow(a.getHoanhDo()-c.getHoanhDo(),2) + pow(a.getTungDo()-c.getTungDo(),2));
 		z = sqrt(pow(b.getHoanhDo()-c.getHoanhDo(),2) + pow(b.getTungDo()-c.getTungDo(),2));
 		if(checkTriangle(a,b,c)){
 			if(x!=y&& x!=z && y!=z)
 			cout<<"La tam giac binh thuong \n\n";
 			if(x==y)	
			 cout<<"La tam giac can tai A \n\n";
			if(x==z)
			 cout<<"La tam giac can tai B \n\n";
			if(y==z)
			 cout<<"La tam giac can tai C \n\n";
		 }
		else cout<<"Khong phai la tam giac!";
 }
 
//ham tinh chu vi dien tich tam giac
void perimeter_acreage(Point a, Point b, Point c){
	float x,y,z,cv,dt;
 	 	x = sqrt(pow(a.getHoanhDo()-b.getHoanhDo(),2) + pow(a.getTungDo()-b.getTungDo(),2));
 		y = sqrt(pow(a.getHoanhDo()-c.getHoanhDo(),2) + pow(a.getTungDo()-c.getTungDo(),2));
 		z = sqrt(pow(b.getHoanhDo()-c.getHoanhDo(),2) + pow(b.getTungDo()-c.getTungDo(),2));
 		cv = x+y+z;
 		dt = (float)1/2*sqrt(pow(y,2)-pow(1/2*z,2))*z;
 		
 	if(checkTriangle(a,b,c)){
 		cout<<"Chu vi tam giac la: "<<cv<<endl;
 		cout<<"Dien tich tam giac la: "<<setprecision(5)<<dt;
	 }
}


int main(){
	Point a,b,c;
	cout<<"Nhap tao do diem A"<<endl;
	cin>>a;
	cout<<"Nhap tao do diem B"<<endl;
	cin>>b;
	cout<<"Nhap tao do diem C"<<endl;
	cin>>c;
	cout<<"\nKhoang cach AB = "<<range(a,b)<<"\nKhoang cach AC = "<<range(a,c)<<"\nKhoang cach BC = "<<range(b,c)<<endl;
	
	isoscelesTriangle(a,b,c);
	perimeter_acreage(a,b,c);

	
	return 0;
}


