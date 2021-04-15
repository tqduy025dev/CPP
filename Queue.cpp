#include <iostream>
#include<queue>
using namespace std;


int main() {
   queue <int> q_data;
    q_data.push(1); // them vao cuoi hang 
    q_data.push(2);
    q_data.push(3);
    q_data.push(4);
    
	cout<<"size: "<<q_data.size()<<endl; // tra ve so luong phan tu cua queue
    
    while(!q_data.empty()){	//Trong khi danh sach khong rong thi duyet va xuat ra queue
		cout<<q_data.front(); // lay phan tu dau
		q_data.pop();	//xoa phan tu dau
	}
	
	cout<<"\nPhan tu cuoi la: "<<q_data.back(); // lay phan tu cuoi
    

    
}
