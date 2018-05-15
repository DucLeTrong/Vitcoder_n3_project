#include<bits/stdc++.h>
#include<conio.h>

typedef struct Node{
	
	int memberID;
	int groupID;
	int age;
	char name[30];
	
} node;


void addMember(int *n, node memberList[]){
	
	printf("Nhap thong tin thanh vien!");
	printf("\n\nMuon thoat nhap ID < 0 \n\n");
	while(1){
	printf("Them thanh vien thu %d:\n", ++(*n));
 	printf("ID thanh vien: ");
	scanf("%d", &memberList[*n].memberID);
	if (memberList[*n].memberID < 0){
		(*n)--;
		break;
		} 
	printf("Ten thanh vien: "); 
	fflush(stdin);
	gets(memberList[*n].name);
	printf("Tuoi : ");
	scanf("%d",&memberList[*n].age);
	printf("Group ID: ");
	scanf("%d",&memberList[*n].groupID);	
	}

}

int findMember(int n, node memberList[], int idFind) {
	for(int i = 1; i <= n; i++ ){
		if (memberList[i].memberID == idFind){
			return i;
		}
	}
	return -1;
}

void editMember(int n, node memberList[]){
	
	int idEdit;
	int k = findMember(n, memberList, idEdit);
	
	printf("Nhap ID thanh vien can sua: ");
	scanf("%d", &idEdit);
	
	printf("Cap nhap lai thong tin thanh vien: \n ");
	
	printf("ID thanh vien: ");
	scanf("%d", &memberList[k].memberID);
	
	printf("Ten thanh vien: "); 
	fflush(stdin);
	gets(memberList[k].name);
	
	printf("Tuoi: ");
	scanf("%d",&memberList[k].age);
	
	printf("Group ID: ");
	scanf("%d",&memberList[k].groupID);

}

void deleteMember(int &n, node memberList[]){
 
	int idDelete;
	printf("Nhap ID thanh vien can xoa: ");
	scanf("%d",&idDelete);
	int k = findMember(n, memberList, idDelete);
	for(int i = k; i < n; i++){
		memberList[i] = memberList[i+1];
	}
	n--;
	
} 

void printInfoMember(node member){
	
		printf("\nID thanh vien:        %d   ", member.memberID);
		printf("\nTen thanh vien:       %s   ", member.name);
		printf("\nTuoi:                 %d  ", member.age);
		printf("\nGroup ID:             %d   ", member.groupID);
		printf("\n-------------------------------------------");
		
}

void printMemberList(int n, node memberList[]){
	
	for(int i = 1; i <= n; i++){
		
		printf("\nThanh vien thu %d: ",i);
		printInfoMember(memberList[i]);
		
	}
	
}

void createMenu(){
	
	printf("\n        ********************************************************************");
	printf("\n        *                                                                  *");
	printf("\n        *     >>>>>>>---CHON CHUC NANG THUC HIEN---<<<<<<<<<               *");
	printf("\n        *                                                                  *");
	printf("\n        *             1. THEM THONG TIN THANH VIEN.                        *");
	printf("\n        *             2. TIM THONG TIN THANH VIEN THEO ID.                 *");
	printf("\n        *             3. SUA THONG TIN THANH VIEN.                         *");
	printf("\n        *             4. XOA THANH VIEN.                                   *");
	printf("\n        *             5. IN DANH SACH SINH VIEN.                           *");
	printf("\n        *             6. THOAT CHUONG TRINH.                               *");
	printf("\n        *                                                                  *");
	printf("\n        *                                                                  *");
	printf("\n        ********************************************************************\n");
	
}

void menu(int &n, node memberList[]){
	
	int chose;
	bool exit = false;
	while (!exit){ 
		system("cls");
		createMenu();
		scanf("%d", &chose);
		switch(chose){
		
			case 1: 
				addMember(&n, memberList);
				break;
			
			case 2:
				int idFind,k;
				printf("Nhap ID thanh vien can tim: ");
				scanf("%d", &idFind);
				k = findMember(n, memberList, idFind);
				printInfoMember(memberList[k]);
				getch();
				break;
			
			case 3: 
				editMember(n, memberList);
				break;
			
			case 4: 
				deleteMember(n, memberList);
				break;
			
			case 5:
				printMemberList(n, memberList);
				getch();
				break;
				
			case 6:
				char check;
				printf(" \n     Ban chac chan muon thoat? " );
				printf("\n      Muon thoat nhan Y / Khong muon thoat chon phim bat ki!");
				check = getch();
				if (check == 'y' or check == 'Y')
						exit = true;				
				break;
				
			default: 
				printf("Ban da chon sai chuc nang!");
				getch();
		}
	
	}
	
}

int main(){ 

	int  n = 0;
	node memberList[100];
	menu(n, memberList);
	
}
