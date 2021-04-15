#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void Menu();
int ChonMenu();
void XuLyMenu();

void Menu(){
	printf("1. Coffe\n");
	printf("2. Bac xiu\n");
	printf("3. Coffe sua\n");
	printf("4. Sua tuoi\n");
	printf("5. Nuoc chanh day\n");
	printf("6. Nuoc cam\n");
	printf("7. Tra dao\n");
	printf("8. Tra sua\n");
	printf("9. Sinh to dau\n");
	printf("10. Sinh to dua\n");
	printf("11. Sinh to bo\n");
	printf("12. yaua\n");
	printf("13. 7 up\n");
	printf("14. Sting\n");
	printf("15. CoCa\n");
}

int ChonMenu(int &n){	
	do{
		printf("\nMoi chon Menu\t");
		scanf("%d",&n);
			if(n<0 || n>15)
				printf("Nhap sai, nhap lai: ");
			else 
				return n;
	}while(n<0 || n>15);
	
	
}

void XuLyMenu(int &n){
	int chon = ChonMenu(n);
	switch (chon){
		case 1: 
			printf("Coffe");
			break;
		case 2:
			printf("Bac xiu");
			break;
		case 3:
			printf("Coffe sua");
			break;
		case 4:
			printf("Sua tuoi");
			break;
		case 5: 
			printf("Nuoc chanh day ");
			break;
		case 6: 
			printf("Nuoc cam");
			break;
		case 7:
			printf("Tra dao");
			break;
		case 8: 		
			printf("Sinh to bo");
			break;
		case 9: 		
			printf("Tra sua");
			break;
		case 10: 		
			printf("Sinh to dau");
			break;
		case 11: 
			printf("Sinh to dua");
			break;
		case 12: 		
			printf("yaua");
			break;
		case 13: 		
			printf("7 up");
			break;
		case 14: 		
			printf("Sting");
			break;
		case 15: 		
			printf("Coca");
			break;

	}
	
}

}




