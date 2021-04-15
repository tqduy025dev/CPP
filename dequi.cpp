#include<iostream>

using namespace std;

int dequi(int n)
{
    if(n==0){
    	return 0;
	}else{
		return n%10 + dequi(n/10);
	}    
}

int  main(){
	int n = 12345;
	cout<<dequi(n);
}
