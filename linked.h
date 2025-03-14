/* File        : linked.h */
/* Deskripsi   : ADT linked list dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
 } ElmtList;

boolean isEmpty(address p){
	return (p == NULL);
}
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL


void Create_Node (address *p){
	*p = (address) malloc(sizeof(ElmtList));
}
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)

void Isi_Node (address *p , infotype nilai){
	if (*p != NULL){
		(*p)->info = nilai;
		(*p)->next = NULL;  // Perbaikan: Menggunakan 'next' bukan 'nilai'
	}
}
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)

void Tampil_List (address p){
	while (p != NULL){
		printf("%d -> ", p->info);
		p = p->next;
	}
	printf("NULL\n");  // Perbaikan: Menggunakan 'printf' bukan 'print'
}
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

void Ins_Awal(address *p, address PNew) {
    PNew->next = *p;
    *p = PNew;
}
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
//             PNew (input)

void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */

void InsertAfter(address *pBef, address PNew) {
    PNew->next = (*pBef)->next;
    (*pBef)->next = PNew;
}
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */

void Del_Awal(address *p, infotype *X) {
    address temp = *p;
    *X = temp->info;
    *p = temp->next;
    free(temp);
}
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

void Del_Akhir(address *p, infotype *X) {
    address temp = *p, prev = NULL;
    if (temp->next == NULL) {
        *X = temp->info;
        free(temp);
        *p = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        *X = temp->info;
        free(temp);
        prev->next = NULL;
    }
}
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

void Del_After(address *pBef, infotype *X) {
    address temp = (*pBef)->next;
    *X = temp->info;
    (*pBef)->next = temp->next;
    free(temp);
}
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

int NbElmt(address p) {
    if (p == NULL) return 0;
    return 1 + NbElmt(p->next);
}
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode

infotype Min(address p) {
    if (p->next == NULL) return p->info;
    infotype minSisa = Min(p->next);
    return (p->info < minSisa) ? p->info : minSisa;
}
/* Mengirimkan nilai Info(P) yang minimum */

infotype Rerata(address p) {
    int sum = 0, count = 0;
    address temp = p;
    while (temp != NULL) {
        sum += temp->info;
        count++;
        temp = temp->next;
    }
    return (count == 0) ? 0 : sum / count;
}
/* Mengirimkan nilai rata-rata Info(P) */

address BalikList(address p) {
    address prev = NULL, current = p, next;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;       
        current = next;       
    }
    return prev;  
}
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */

#endif