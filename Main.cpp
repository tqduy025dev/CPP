#include<iostream>
#include"LinkedList.h"



int main() {
   int c;
   listNode ls;
   while (1) //perform switch operation 
   {
      cout<<"1.Chen vao vi tri bat dau"<<endl;
      cout<<"2.Chen vao vi tri cuoi"<<endl;
      cout<<"3.Chen vao vi tri bat ki"<<endl;
      cout<<"4.Xoa vi tri bat ki"<<endl;
      cout<<"5.Cap nhat thong tin nodee"<<endl;
      cout<<"6.Hien thi danh sach"<<endl;
      cout<<"7.Tim kiem nhan vien"<<endl;
      cout<<"8.Dao nguoc danh sach"<<endl;
      cout<<"9.Thoat"<<endl;
      cout<<"Vui long chon : ";
      cin>>c;
      switch(c) {
         case 1:
            ls.insert_begin();
         break;
         case 2:
            ls.insert_end();
         break;
         case 3:
            ls.insert_pos();
         break;
         case 4:
            ls.delete_pos();
         break;
         case 5:
            ls.update();
         break;
         case 6:
            ls.display();
         break;
         case 7:
            ls.search();
         break;
         case 8:
            ls.reverse();
         break;
         case 9:
            exit(1);
         default:
            cout<<"Nhap sai, nhap lai"<<endl;
      }
   }
   return 0;
}

