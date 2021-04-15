#include<iostream>
 using namespace std;
 
 class T{
 	int a;
 	
 	public: 
 	T(int a){
 		this->a = a;
	 }
	
	void Xuat(){
		cout<<&a;
	}
 };
 
 int main(){
 	
 	T *a = new T(4);
 	
 	T *b = a;
 	
 	
 	a->Xuat(); cout<<endl;
 	b->Xuat();

 	
 }
