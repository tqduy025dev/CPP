#include <iostream>
#include <conio.h>
using namespace std;
class vector
{
   private:
     int n;
     float *v;
   public:
     vector();//ham thiet lap khong tham so
     vector(int size);//ham thiet lap mot tham so
     vector(int size,float * a);//ham thiet lap hai tham so
     void display();
     ~vector();//ham huy
};

vector::vector()
{
   cout<<" Su dung ham thiet lap khong tham so :"<<endl;
   cout<<" Tao mot doi tuong lop vecto co dia chi tai:"<<this<<endl;
   cout<<" Nhap vao so toa do :";
   cin>>n;
   v=new float[n];
   cout<<" Xin cap phat mot vung bo nho cho "<<n<<" so thuc "<<" tai dia chi la: "<<v<<endl;
   for(int i=0;i<n;i++)
    {
      cout<<" Toa do thu "<<(i+1)<<":";
      cin>>v[i];
    }
}
 vector::vector(int size)
{  cout<<" Su dung ham thiet lap mot tham so :"<<endl;
   cout<<" Tao mot doi tuong lop vecto co dia chi tai:"<<this<<endl;
   n=size;
   v=new float[n];
   cout<<" Xin cap phat mot vung bo nho cho "<<n<<"so thuc"<<" tai dia chi la:"<<v<<endl;
   for(int i=0;i<n;i++)
    {
      cout<<" Toa do thu "<<(i+1)<<":";
      cin>>v[i];
    }
}

vector::vector(int size,float * a)
{
   cout<<" Su dung ham thiet lap hai tham so :"<<endl;
   cout<<" Tao mot doi tuong lop vecto co dia chi tai:"<<this<<endl;
   n=size;
   v=new float[n];
   cout<<" Xin cap phat mot vung bo nho cho "<<n<<" so thuc"<<" tai dia chi la:"<<v<<endl;
   for(int i=0;i<n;i++)
      v[i]=a[i];
}
vector::~vector()
{
   cout<<" Giai phong "<<v<<" cua doi tuong co dia chi tai "<<this<<endl;
   delete v;
   getch();
}
void vector::display()
{
  cout<<" Hien thi doi tuong co dia chi tai:"<<this<<endl;
  for(int i=0;i<n;i++)
     cout<<"  " <<v[i]<<"  ";
     cout<<endl;
}
 int main()
{
     vector s;
     s.display();
     vector s1(5);
     s1.display();
     float a[5]={1,2,3,4,5};
     vector s2(5,a);
     s2.display();
     getch();
     return 0;
     
}
