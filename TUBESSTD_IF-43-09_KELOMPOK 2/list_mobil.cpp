#include "list_mobil.h"

void createList(listmobil &L) {
    first(L) = NULL;
}

addressmobil alokasi2(infotypemobil x) {
    addressmobil P;
    P = new elmlistmobil;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(listmobil &L, addressmobil P) {
    next(P) = first(L);
    first(L) = P ;
}

void deleteFirst(listmobil &L, addressmobil &P){
    P = first(L);
    if(P!=NULL){
        first(L) = next(P);
        next(P) = NULL;
    }
}

void printInfo(listmobil L) {
    addressmobil P = first(L);
    cout<<"~~~~~~~~~~~~~~"<<endl;
    cout<<"Daftar Mobil"<<endl;
    cout<<"~~~~~~~~~~~~~~"<<endl;
    if(first(L)!=NULL) {
       while((P)!=NULL){
            cout<<info(P)<<endl;
            P = next(P);
        } ;
    }
}

addressmobil findElm3(listmobil L, infotypemobil x) {
    addressmobil P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
