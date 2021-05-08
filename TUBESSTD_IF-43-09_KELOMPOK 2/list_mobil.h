#ifndef LIST_MOBIL_H_INCLUDED
#define LIST_MOBIL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef string infotypemobil ;
typedef struct elmlistmobil *addressmobil;

struct elmlistmobil {
    infotypemobil info;
    addressmobil next;
};

struct listmobil {
    addressmobil first;
};

void createList(listmobil &L);
void insertFirst(listmobil &L, addressmobil P);
addressmobil alokasi2(infotypemobil x);
void deleteFirst(listmobil &L, addressmobil &P);
addressmobil findElm3(listmobil L, infotypemobil x);
void printInfo(listmobil L);

#endif // LIST_MOBIL_H_INCLUDED
