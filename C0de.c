#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Code tren Linux . Chay tren Window se bi loi . Thay ham __fpurge(stdin); thanh ham fflush(stdin);

void InputInfor();
void OutputInfor();
void EditInfor();
void DeleteMember();
void InsertMember();
void Menu();

typedef struct {
	
	char name[50];
	int ID;
	int age;
	int groupID;
} Member;

int main() {

	Member *arrMember;
	int sizeArr, i_mem;
	
	int choose;
	int check = 1;
	do {
		Menu();
		scanf("%d", &choose);
		switch( choose ) {	

			case 1 :
				do {
					printf("Nhap so thanh vien : \n");
					scanf( "%d", &sizeArr );
					if( sizeArr <= 0 ) { printf("Nhap lai gia tri !\n"); }
				} while ( sizeArr <= 0 );
	
				arrMember = ( Member * ) malloc( sizeArr * sizeof(Member) );
	
				InputInfor( arrMember, &sizeArr );
				break;
			case 2 :
				OutputInfor( arrMember, sizeArr );
				break;
			case 3 :
				printf("Nhap so luong thanh vien can them : \n");
				scanf("%d", &i_mem);
				InsertMember( arrMember, &sizeArr, i_mem );
				break;
			case 4 :
				printf("Ban can sua thong tin thanh vien nao ? \n");
				scanf("%d", &i_mem);
				EditInfor( arrMember, i_mem - 1 );
				break;
			case 5 :
				printf("ban muon xoa thanh vien thu may : \n");
				scanf("%d", &i_mem);
				DeleteMember( arrMember, &sizeArr, i_mem);
				sizeArr--;
				OutputInfor( arrMember, sizeArr );
				break;
			case 6 :
				free(arrMember);
				exit(0);

		}
		printf("Ban muon tiep tuc hay khong ? ( 1 or 0 ? )\n");
		scanf("%d", &check);
	} while( check == 1 );

	
	return 0;
}

void Menu() {

	printf("________________________________________\n");
	printf("\n");
	printf("[1] . Nhap thong tin cac thanh vien \n");
	printf("[2] . Hien thi thong tin thanh vien \n");
	printf("[3] . Them thanh vien \n");
	printf("[4] . Sua thong tin 1 thanh vien \n");
	printf("[5] . Xoa thanh vien \n");
	printf("[6] . Thoat chuong trinh \n");
	printf("________________________________________\n");
	printf("Lua chon chuc nang : ");

}

void OutputInfor( Member *arrMember, int sizeArr ) {

	system("clear");
	for( int counter = 0; counter < sizeArr; counter++ ){
		
		printf("Thanh vien thu %d\n", counter + 1 );
		printf("Name \t: %s \n", arrMember[counter].name );
		printf("ID \t: %d \n", arrMember[counter].ID );
		printf("Age \t : %d \n", arrMember[counter].age );
		printf("Group ID : %d \n", arrMember[counter].groupID );
		printf("\n");
		
	}
	
}

void InputInfor( Member *arrMember, int *sizeArr ) {

	
	system("clear");
	for( int counter = 0; counter < *sizeArr; counter++ ) {
		printf("Thanh vien thu %d \n", counter + 1 );	
		printf("Name \t :" );
		__fpurge(stdin);
		gets( &arrMember[counter].name );
		printf("ID \t :" );
		scanf("%d", &arrMember[counter].ID );
		printf("Age \t :" );
		scanf("%d", &arrMember[counter].age );
		printf("Group ID :" );
		scanf("%d", &arrMember[counter].groupID );
	}

}

void EditInfor( Member *arrMember, int i_mem ) {

	int choose;
	printf("Ban muon sua thong tin nao ? \n");
	printf("[1] . Ho ten \n");
	printf("[2] . ID\n");
	printf("[3] . Tuoi\n");
	printf("[4] . Group ID \n");					
	printf("Nhap lua chon cua ban \n");
	scanf("%d", &choose);
	system("clear");
	switch(choose) {
	
		case 1 : 
			printf("Nhap lai Ten \n");
			__fpurge(stdin);
			gets(&arrMember[i_mem].name);
			
			break;
		case 2 :
			printf("Nhap lai ID \n");
			scanf("%d", &arrMember[i_mem].ID);
			break;
		case 3 :
			printf("Nhap lai Tuoi\n");
			scanf("%d", &arrMember[i_mem].age);
			break;
		case 4 :
			printf("Nhap lai Nhom \n");
			scanf("%d", &arrMember[i_mem].groupID);
			break;

	}
}

void DeleteMember( Member *arrMember, int *sizeArr, int i_mem ) {

	i_mem--;
	while ( i_mem < *sizeArr - 1 ) {

		arrMember[i_mem] = arrMember[i_mem + 1];
		i_mem++;
	}
}

void InsertMember( Member *arrMember, int *sizeArr, int amountAdd ) {

	int counter = *sizeArr;
	*sizeArr += amountAdd;
	arrMember = (Member *) realloc( arrMember, amountAdd * sizeof(Member) );
	for( counter; counter < *sizeArr; counter ++ ) {
		printf("Thanh vien thu %d \n", counter + 1 );	
		printf("Name \t :" );
		__fpurge(stdin);
		gets( &arrMember[counter].name );
		printf("ID \t :" );
		scanf("%d", &arrMember[counter].ID );
		printf("Age \t :" );
		scanf("%d", &arrMember[counter].age );
		printf("Group ID :" );
		scanf("%d", &arrMember[counter].groupID );
	}

}





