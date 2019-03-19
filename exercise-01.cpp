/*
Author 		: Bandana Irmal Abdillah
NPM 		: 140810180025
Deskripsi 	: Program ini mengkalikan dua angka
Tahun	 	: 2019
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct data{
	char nama[30];
	char bidang[30];
	int gaji;
	data* next;
};

typedef data* pointer;
typedef pointer list;

void createList(list& first);
void createElement(pointer& pBaru);
void insertFirst(list& first, pointer pBaru);
void insertLast(list& first, pointer pBaru);
void deleteFirst(list& first, pointer pHapus);
void deleteLast(list& first, pointer pHapus);
void traversal(list& first);

main(){
	list pegawai;
	pointer baru, hapus;
	int menu;
	createList(pegawai);
	do{
		cout << "No\tPilihan" << endl;
		cout << "1\tInsert First" << endl;
		cout << "2\tInsert Last" << endl;
		cout << "3\tDelete First" << endl;
		cout << "4\tDelete Last" << endl;
		cout << "5\tTraversal" << endl;
		cout << "0\tExit Program" << endl;
		cout << "Pilih : "; cin >> menu;
		system ("cls");
		switch(menu){
			case 1:
				createElement(baru);
				insertFirst(pegawai, baru);
				system("cls");
				break;
			case 2:
				createElement(baru);
				insertLast(pegawai, baru);
				system("cls");
				break;
			case 3:
				deleteFirst(pegawai,hapus);
				break;
			case 4:
				deleteLast(pegawai,hapus);
				break;
			case 5:
				traversal(pegawai);
				cout << endl;
				break;				
		}
	}while(menu!=0);
}

void createList(list& first){
	first = 0;
}

void createElement(pointer& pBaru){
	pBaru = new data;
	cout << "Nama\t: "; cin.ignore(); cin.getline(pBaru -> nama, 30);
	cout << "Bidang\t: "; cin >> pBaru -> bidang;
	cout << "Gaji\t: "; cin >> pBaru -> gaji;
	pBaru -> next = 0;
}

void insertFirst(list& first, pointer pBaru){
	if(first == 0){
		first = pBaru;
	}
	else{
		pBaru -> next = first;
		first = pBaru;
	}
}

void insertLast(list& first, pointer pBaru){
	pointer last;
	if (first == 0){
		first = pBaru;
	}
	else { 
		last = first; 	
		while (last -> next != 0){
			last = last -> next;
		} 
		last -> next = pBaru; 
	}	
}

void deleteFirst(list& first, pointer pHapus){
	if (first == 0){
		pHapus = 0;
	}
	else if (first->next == 0){
		pHapus = first;
		first = 0;
	}
	else{
		pHapus = first;
		first = first -> next;
		pHapus -> next = 0;
	}
}

void deleteLast(list& first, pointer pHapus){
	pointer precLast, last;
	if (first == 0){
		pHapus = 0;
	}
	else if(first->next == 0){
		pHapus = first;
		first = 0;
	}
	else{
		last = first;
		precLast = 0;
		while(last->next != 0){
			precLast = last;
			last = last -> next;
		}
		pHapus = last;
		precLast -> next = 0;
	}
}

void traversal(list& first){
	pointer pBantu;
	pBantu = first;
	int nomor = 1;
	cout << "No\tNama\t\tBidang\t\tGaji" << endl;
	while(pBantu != 0){
		cout << nomor << "\t" << pBantu -> nama << "\t" << pBantu -> bidang << "\t\t" << pBantu -> gaji << endl;
		nomor++;
		pBantu = pBantu -> next;
	}
}
