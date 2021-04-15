#include<iostream>
#include<math.h>
using namespace std;


int main(){
	int h;
	cout<<"Nhap h: ";
	cin>>h;
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<2*h; j++){
			cout<<"*"<<endl;
		}
	}
	
	
	
	return 0;
}
