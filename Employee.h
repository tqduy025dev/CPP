#include<iostream>
#include<string>

using namespace std;

class Employee{
	private:
	string code;
	string surName;
	string name;
	int yearOfBirth;
	
	public:
	Employee(){
	}
	Employee(string code, string surName, string name, int yearOfBirth){
		this->code = code;
		this->surName = surName;
		this->name = name;
		this->yearOfBirth = yearOfBirth;
	}
		friend istream &operator>>(istream &in,Employee &a);
		friend ostream &operator<<(ostream &out, Employee &a);
		string getCode();
};

string Employee::getCode(){
	return code;
}

istream &operator>>(istream &in,Employee &a){
			cout<<"MNV: ";
			in>>a.code;
			cout<<"Ho: ";
			in>>a.surName;
			cout<<"Ten: ";
			in>>a.name;
			cout<<"Nam sinh: ";
			in>>a.yearOfBirth;
		}
		
ostream &operator<<(ostream &out, Employee &a){
			out<<"Ma Nhan Vien: "<<a.code<<" -Ho: "<<a.surName<<"  -Ten: "<<a.name<<"  -Nam sinh: "<<a.yearOfBirth<<endl;
}
