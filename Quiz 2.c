#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main() {
    address head = NULL;
    address newNode;
    infotype value;

    // Masukan bilangan 7 sebagai elemen pertama {insert first}
    Create_Node(&newNode);
    Isi_Node(&newNode, 7);
    Ins_Awal(&head, newNode);
    Tampil_List(head);

    // Masukan bilangan 11 sebagai elemen kedua {insert last}
    Create_Node(&newNode);
    Isi_Node(&newNode, 11);
    Ins_Akhir(&head, newNode);
    Tampil_List(head);

    // Masukan bilangan 9 di antara bilangan 7 dan 11 {insert after}
    address node7 = Search(head, 7);
    if (node7 != NULL) {
        Create_Node(&newNode);
        Isi_Node(&newNode, 9);
        InsertAfter(&node7, newNode);
    }
    Tampil_List(head);

    // Masukan bilangan 5 di awal list {insert first}
    Create_Node(&newNode);
    Isi_Node(&newNode, 5);
    Ins_Awal(&head, newNode);
    Tampil_List(head);

    // Masukan bilangan 13 di akhir list {insert last}
    Create_Node(&newNode);
    Isi_Node(&newNode, 13);
    Ins_Akhir(&head, newNode);
    Tampil_List(head);

    // Hapus elemen terakhir (bilangan 13) pada list {delete last}
    if (!isEmpty(head)) {
        Del_Akhir(&head, &value);
        printf("Deleted last element: %d\n", value);
    }
    Tampil_List(head);

    // Hapus bilangan 7 pada list
    address nodeBefore7 = Search(head, 5); // Cari node sebelum 7
    if (nodeBefore7 != NULL && nodeBefore7->next != NULL && nodeBefore7->next->info == 7) {
        Del_After(&nodeBefore7, &value);
        printf("Deleted element: %d\n", value);
    }
    Tampil_List(head);

    // Hapus elemen pertama (bilangan 5) pada list {delete first}
    if (!isEmpty(head)) {
        Del_Awal(&head, &value);
        printf("Deleted first element: %d\n", value);
    }
    Tampil_List(head);

    // Hapus semua elemen list deret bilangan ganjil
    while (!isEmpty(head)) {
        Del_Awal(&head, &value);
        printf("Deleted element: %d\n", value);
    }
    Tampil_List(head);

    return 0;
}