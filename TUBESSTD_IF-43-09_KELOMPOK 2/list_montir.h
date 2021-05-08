#ifndef LIST_MONTIR_H_INCLUDED
#define LIST_MONTIR_H_INCLUDED

#include <iostream>
#include "list_mobil.h"
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef string infotypemontir;
typedef struct elmlistmontir *addressmontir;

struct elmlistmontir{
    infotypemontir info;
    addressmontir next;
};

struct listmontir{
    addressmontir first;
};

void createList(listmontir &L);
void insertFirst(listmontir &L, addressmontir P);
void deleteFirst(listmontir &L, addressmontir &P);
addressmontir alokasi1(infotypemontir x);
addressmontir findElm2(listmontir L, infotypemontir x);
void printInfo(listmontir L);


#endif // LIST_MONTIR_H_INCLUDED
