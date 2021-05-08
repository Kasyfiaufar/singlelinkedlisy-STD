#include "list_relasi.h"

void createList(listbengkel &L)
{
    first(L) = NULL;
}

addressbengkel alokasibeng(addressmobil P, addressmontir C)
{
    addressbengkel Q = new elmlistbengkel ;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

void insertFirst(listbengkel &L, addressbengkel P)
{
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(P)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteElm(listbengkel &L, addressbengkel &P)
{
    if(next(P) == P)
    {
        first(L) = next(P);
    }
    else
    {
        if(first(L) == P)
        {
            first(L) = next(P);
        }
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
    }
    prev(P) = NULL;
    next(P) = NULL;
}

void printInfo(listbengkel L)
{
    addressbengkel P = first(L);
    while(P !=NULL)
    {
        cout<<info(parent(P))<<"->"<<info(child(P))<<endl;
        P = next(P);
    }
}


addressbengkel findElmB(listbengkel L, addressmobil P, addressmontir C)
{
    addressbengkel Q = first(L);
    if(Q != NULL)
    {
        do
        {
            if(parent(Q)==P && child(Q)== C)
            {
                return Q;
            }
            Q = next(Q);
        }
        while(Q!=first(L));
    }
    return NULL;
}

addressbengkel findElmB(listbengkel L, infotypemobil p, infotypemontir c)
{
    addressbengkel Q = first(L);
    if(Q != NULL)
    {
        do
        {
            if(info(parent(Q)) == p && info(child(Q)) == c)
            {
                return Q;
            }
            Q = next(Q);
        }
        while(Q!=first(L));
    }
    return NULL;
}

void connecting(listbengkel &B, listmobil M, listmontir T, infotypemobil p, infotypemontir c)
{
    addressmobil A = findElm3(M, p);
    addressmontir D = findElm2(T, c);
    if(A != NULL && D != NULL)
    {
        addressbengkel Q = alokasibeng(A, D);
        insertFirst(B, Q);
    }
}

void disconnect(listbengkel &B, infotypemobil p, infotypemontir c)
{
    addressbengkel Q = findElmB(B, p, c);
    if(Q!=NULL)
    {
        deleteElm(B, Q);
        delete Q;
    }
}
void deletefirst(listbengkel &B, listmontir &M)
{
    addressbengkel Q = first(B);
    addressmontir P = first(M);
    if (Q!= NULL)
    {
        do
        {
            if(child(Q)==P)
            {
                addressbengkel S = Q;
                Q = next(Q);
                deleteElm(B, S);
                delete S;
                if(first(B) == NULL)
                {
                    Q = NULL;
                }
            }
            else
            {
                Q = next(Q);
            }
        }
        while(Q != first(B));
    }
    deleteFirst(M, P);
    delete P;
}

void deletefirst(listbengkel &B, listmobil &M)
{
    addressbengkel Q = first(B);
    addressmobil P = first(M);
    if (Q!= NULL)
    {
        do
        {
            if(parent(Q)==P)
            {
                addressbengkel S = Q;
                Q = next(Q);
                deleteElm(B, S);
                delete S;
                if(first(B) == NULL)
                {
                    Q = NULL;
                }
            }
            else
            {
                Q = next(Q);
            }
        }
        while(Q != first(B));
    }
    deleteFirst(M, P);
    delete P;
}

void printRelasi(listbengkel B, listmontir M)
{
    addressmontir P = first(M);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" Daftar Mobil Yang Sedang Diperbaiki Oleh Montir"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    while(P!=NULL)
    {
        cout<<info(P)<<" - ";
        addressbengkel Q = first(B);
        if(Q!=NULL)
        {
            do
            {
                if(child(Q) == P)
                {
                    cout<<info(parent(Q))<<", ";
                }
                Q = next(Q);
            }
            while(Q!=first(B));
        }
        cout<<endl;
        P = next(P);
    }
    cout<<endl;
}
