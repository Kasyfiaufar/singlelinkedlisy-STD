#include "list_montir.h"

void createList(listmontir &L) {
    first(L) = NULL;
}

addressmontir alokasi1(infotypemontir x) {
    addressmontir P = new elmlistmontir;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(listmontir &L, addressmontir P) {
    next(P) = first(L);
    first(L) = P ;
}

void deleteFirst(listmontir &L, addressmontir &P){
    P = first(L);
    if(P!=NULL){
        first(L) = next(P);
        next(P) = NULL;
    }
}

void printInfo(listmontir L) {
    addressmontir P = first(L);
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" Daftar Montir"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
    while(P !=NULL) {
        cout<<info(P)<<endl;
        P = next(P);
    }
}


addressmontir findElm2(listmontir L, infotypemontir x) {
    addressmontir P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
