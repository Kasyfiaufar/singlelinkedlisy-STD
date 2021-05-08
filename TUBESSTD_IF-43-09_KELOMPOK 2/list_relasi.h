#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_montir.h"
#include "list_mobil.h"

#include <iostream>
using namespace std;

#define first(L) L.first
#define prev(P) P->prev
#define next(P) P->next
#define child(P) P->child
#define parent(P) P->parent

typedef string infotypebengkel ;
typedef struct elmlistbengkel *addressbengkel;

struct elmlistbengkel{
    infotypebengkel info;
    addressbengkel next;
    addressbengkel prev;
    addressmontir child;
    addressmobil parent;
};

struct listbengkel{
    addressbengkel first;
    addressbengkel last;
};

void createList(listbengkel &L);
void insertFirst(listbengkel &L, addressbengkel P);
void deleteElm(listbengkel &L, addressbengkel &P);
void deletefirst(listbengkel &B, listmontir &M);
void deletefirst(listbengkel &B, listmobil &M);
addressbengkel alokasibeng(addressmobil P, addressmontir C);
addressbengkel findElmB(listbengkel L, addressmobil P, addressmontir C);
addressbengkel findElmB(listbengkel L, infotypemobil p, infotypemontir c);
void printRelasi(listbengkel R, listmontir M);
void disconnect(listbengkel &B, infotypemobil p, infotypemontir c);
void connecting(listbengkel &B, listmobil M, listmontir T, infotypemobil p, infotypemontir c);


#endif // LIST_RELASI_H_INCLUDED
