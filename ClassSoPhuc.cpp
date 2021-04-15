#include<iostream>
#include<math.h>

using namespace std;
class sophuc
{
private:
    float t,a;
public:
    sophuc(float =0,float =0);
    ~sophuc(void);
    float dodai();
    sophuc operator+(const sophuc &);
    sophuc operator-(const sophuc &);
    sophuc operator*(const sophuc &);
    sophuc operator/(const sophuc &);
    bool operator<(sophuc &);
    bool operator<=(sophuc &);
    bool operator>(sophuc &);
    bool operator>=(sophuc&);
    bool operator==(sophuc&);
    bool operator!=(sophuc&);
    friend ostream &operator<<(ostream &out,const sophuc &a);
    friend istream &operator>>(istream &in,sophuc &a);
};



sophuc::sophuc(float b,float c)
{
    t=b;a=c;
}
float sophuc::dodai()
{
    return sqrt(t*t+a*a);
}

sophuc::~sophuc(void)
{
}
sophuc sophuc::operator+(const sophuc &x)
{
    sophuc c;
    c.t=x.t+this->t;
    c.a=x.a+this->a;
    return c;
}
ostream &operator<<(ostream &out,const sophuc &a)
{
    if(a.t==0 && a.a!=0) out<<a.a<<"i";
    else if(a.a==0 && a.t!=0) out<<a.t;
    else if(a.t==0 && a.a==0) out<<0;
    else out<<"("<<a.t<<((a.a>0)?" + ":" - ")<<abs(a.a)<<"i)";
    return out;
}
istream &operator>>(istream &in,sophuc &a)
{
    cout<<"Phan thuc = ";in>>a.t;
    cout<<"Phan ao = ";in>>a.a;
    return in;
}
sophuc sophuc::operator-(const sophuc&x)
{
    sophuc c;
    c.t=t-x.t;
    c.a=a-x.a;
    return c;
}
sophuc sophuc::operator*(const sophuc&x)
{
    sophuc c;
    c.t=t*x.t-a*x.a;
    c.a=t*x.a+a*x.t;
    return c;
}
sophuc sophuc::operator/(const sophuc&x)
{
    sophuc c;
    c.t=(t*x.t+a*x.a)/(x.t*x.t+x.a*x.a);
    c.a=(x.t*a-t*x.a)/(x.t*x.t+x.a*x.a);
    return c;
}
bool sophuc::operator<(sophuc&x)
{
    if(dodai()<x.dodai()) return true;return false;
}
bool sophuc::operator<=(sophuc&x)
{
    if(dodai()<=x.dodai()) return true;return false;
}
bool sophuc::operator>(sophuc&x)
{
    if(dodai()>x.dodai()) return true;return false;
}
bool sophuc::operator>=(sophuc&x)
{
    if(dodai()>=x.dodai()) return true;return false;
}
bool sophuc::operator==(sophuc&x)
{
    if(dodai()==x.dodai()) return true;return false;
}
bool sophuc::operator!=(sophuc&x)
{
    if(dodai()!=x.dodai()) return true;return false;
}


int main()
{
    sophuc a,b,c;
    cin>>a>>b;
    cout<<a<<" + "<<b<<" = "<<a+b<<endl;
    cout<<a<<" - "<<b<<" = "<<a-b<<endl;
    cout<<a<<" * "<<b<<" = "<<a*b<<endl;
    cout<<a<<" / "<<b<<" = "<<a/b<<endl<<endl;

	cout<<a+b;

    if(a>b) cout<<a<<" lon hon "<<b<<endl<<endl;
	
    if(a<b) cout<<a<<" nho hon "<<b<<endl<<endl;
	
    if(a==b) cout<<a<<" bang "<<b<<endl<<endl;
	
    system("pause");
    return 0;
}
