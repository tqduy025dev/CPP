#include<iostream>
using namespace std;


class Shape {
	public:
	virtual double getArea();
	virtual double getPerimeter();
	virtual void Input();
	void HienThi();
};


double Shape::getArea(){
	return 0;
}

double Shape::getPerimeter(){
	return 0;
}

void Shape::Input(){
}


void Shape::HienThi(){
	cout<<"Dien tich la: "<<getArea()<<endl;
}

//-----------------------------------------------------//
class Circle : public Shape{
	private:
		double bankinh;
	public:
		Circle();
		Circle(double a);
		void Input();
		double getArea(){
			return 3.14*bankinh*bankinh;
		}
		
		
};

Circle::Circle(){
}


Circle::Circle(double a){
	bankinh = a;
}

void Circle::Input(){

	cout<<"Nhap ban kinh hinh tron: ";
	bankinh;
}






int main(){
	
	Shape *a = new Circle[5];

	for(int i=0; i<5; i++)
	(a+i)->Input();
	
	
	
	
	
	
	
	system("pause");
	return 0;
	
}
