#include <iostream>
#include <string>
#include <vector>
using namespace std;

void duyetToi(string a, vector<int> &vt){
int t = 100;
for(int i=0; i<a.length(); i++){
		if(a[i]=='e' || a[i]=='u' || a[i]=='o' || a[i]=='a' || a[i]=='i'){
			t = i;
		}
		if(t == 100){
			vt.push_back(t);
		}else{
			vt.push_back(i-t);
		}
	}
}

void duyetLui(string a, vector<int> &vt){
int t = 100;
	for(int i=a.length()-1; i>=0; i--){
		if(a[i]=='e' || a[i]=='u' || a[i]=='o' || a[i]=='a' || a[i]=='i'){
			t = i;
		}
		if(t != 100){
			vt[i] = min(t-i,vt[i]);
		}
	}
}
int main(){

	string a = "binh phuoc";
	vector<int> vt;
	vector<int>::iterator iter;
	
//	for(int i=0; i<a.length(); i++){
//		if(a[i]=='e' || a[i]=='u' || a[i]=='o' || a[i]=='a' || a[i]=='i'){
//			t = i;
//		}
//		if(t == 100){
//			vt.push_back(t);
//		}else{
//			vt.push_back(i-t);
//		}
//	}
//	
//	t = 100;
//	for(int i=a.length()-1; i>=0; i--){
//		if(a[i]=='e' || a[i]=='u' || a[i]=='o' || a[i]=='a' || a[i]=='i'){
//			t = i;
//		}
//		if(t != 100){
//			vt[i] = min(t-i,vt[i]);
//		}
//	}


	duyetToi(a,vt);
	duyetLui(a,vt);

	for(iter = vt.begin(); iter < vt.end(); iter++){
		cout<<*iter<<" ";
	}
	
	
	
}


