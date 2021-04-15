#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iostream>



long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;
 
    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}


int main(){
	char n, x;
	int a, b;
	float result;
	
	int y = -32;
	char m = y;
	std::cout<<m;
	
	do{
			
			printf("Nhap so a = "); scanf("%d", &a);
			printf("Nhap so b = "); scanf("%d", &b);
			fflush(stdin);
			printf("Nhap phep toan: "); scanf("%c", &n);
	
	switch (n){
		case '+':
			result = a + b;
			printf("DEC: %f\n",result);
			printf("BIN: %d",decimalToBinary(result));
			break;
		case '-':
			result = a - b;
			printf("DEC: %f\n",result);
			printf("BIN: %d",decimalToBinary(result));
			break;
		case '*':
			result = a * b;
			printf("DEC: %f\n",result);
			printf("BIN: %d",decimalToBinary(result));
			break;
		case '/':
			result = a / b;
			printf("DEC: %f\n",result);
			printf("BIN: %d",decimalToBinary(result));
		}
			fflush(stdin);
			printf("\n\nNhan phim bat ki de tiep tuc");
			printf("\nESC de thoat \n\n");
			x = getch();
	}while(x != 27);
	
	
	return 0;
}
