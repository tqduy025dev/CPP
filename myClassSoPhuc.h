#include<iostream>
#include<math.h>

using namespace std;

class SoPhuc{
	private:
		int thuc;
		int ao;
	public:
		SoPhuc();
		SoPhuc(int a, int b);
		SoPhuc(const int &a);
		float Modul();
		friend istream &operator>>(istream &in, SoPhuc &sp);
		friend ostream &operator<<(ostream &out, SoPhuc &sp);
		SoPhuc operator +(SoPhuc x);
		SoPhuc operator -(SoPhuc x);
		SoPhuc operator /(SoPhuc x);
		SoPhuc operator *(SoPhuc x);
		bool operator==(SoPhuc &x);
		bool operator<(SoPhuc &x);
		bool operator>(SoPhuc &x);
};



SoPhuc::SoPhuc(){
	this->thuc = 0;
	this->ao = 0;
}

SoPhuc::SoPhuc(int a, int b){
	this->thuc = a;
	this->ao = b;
}

SoPhuc::SoPhuc(const int &a){
	thuc = a;
	ao = a;
}


float SoPhuc::Modul(){
			return sqrt(pow(this->thuc,2)+pow(this->ao,2));
		}

SoPhuc SoPhuc::operator +(SoPhuc b){
	return SoPhuc(this->thuc+b.thuc, this->ao+b.ao);
}

SoPhuc SoPhuc::operator -(SoPhuc b){
	return SoPhuc(this->thuc-b.thuc, this->ao-b.ao);
}

SoPhuc SoPhuc::operator *(SoPhuc b){
	return SoPhuc((this->thuc*b.thuc) - (this->ao*b.ao),(this->thuc*b.ao+this->ao*b.thuc));
}

SoPhuc SoPhuc::operator /(SoPhuc b){
	SoPhuc z;
    z.thuc = (this->thuc*b.thuc+this->ao*b.ao)/(pow(this->thuc,2)+pow(this->ao,2));
    z.ao= (this->thuc*b.ao-this->ao*b.thuc)/(pow(this->thuc,2)+pow(this->ao,2));
    return z;
}

istream &operator>>(istream &in, SoPhuc &sp){
    cout << "Thuc: ";
    in >> sp.thuc;
    cout << "Ao: ";
    in >> sp.ao;
    return in;
}

ostream &operator<<(ostream &out, SoPhuc &sp){
	if(sp.thuc==0 && sp.ao!=0) out<<sp.ao<<"i";
    else if(sp.ao==0 && sp.thuc!=0) out<<sp.thuc;
    else if(sp.thuc==0 && sp.ao==0) out<<0;
    else out<<"("<<sp.thuc<<((sp.ao>0)?" + ":" - ")<<abs(sp.ao)<<"i)";
    return cout;
}

bool SoPhuc::operator==(SoPhuc &x){
	if(Modul() == x.Modul()){
		return true;
	}
	return false;
}
bool SoPhuc::operator<(SoPhuc &x){
	if(Modul() < x.Modul()){
		return true;
	}
	return false;
}
bool SoPhuc::operator>(SoPhuc &x){
	if(Modul() > x.Modul()){
		return true;
	}
	return false;
}











