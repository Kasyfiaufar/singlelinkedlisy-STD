#include <iostream>

#include "list_montir.h"
#include "list_mobil.h"
#include "list_relasi.h"

using namespace std;

listmobil Mobil;
listmontir Montir;
listbengkel relasi;

/*HUBUNGAN MONTIR DAN MOBIL ADA DI MENU PERBAIKAN?SERVICE
DAFTAR BENGKEL*/

int main()
{

    int menu;
    int rekmon;
    int rekbil;
    int serv, sear;
    string input,hapusM;
    string A, B;

    createList(Montir);
    insertFirst(Montir, alokasi1("kasyfi"));
    insertFirst(Montir, alokasi1("setiawan"));
    insertFirst(Montir, alokasi1("aufar"));
    insertFirst(Montir, alokasi1("rizki"));

    createList(Mobil);
    insertFirst(Mobil, alokasi2("avanza"));
    insertFirst(Mobil, alokasi2("jazz"));
    insertFirst(Mobil, alokasi2("xenia"));
    insertFirst(Mobil, alokasi2("civic"));
    insertFirst(Mobil, alokasi2("lambo"));

    connecting(relasi, Mobil, Montir, "jazz", "rizki");
    connecting(relasi, Mobil, Montir, "avanza", "setiawan");
    connecting(relasi, Mobil, Montir, "jazz", "kasyfi");
    connecting(relasi, Mobil, Montir, "avanza", "rizki");
    connecting(relasi, Mobil, Montir, "civic", "rizki");
    connecting(relasi, Mobil, Montir, "lambo", "aufar");


    while(true)
    {
        cout << "------------------------------------------------" << endl;
        cout << "       Selamat Datang Di Bengkel Kikas" << endl;
        cout << "Pelayanan Terbaik Dari Semua Bengkel di Tel-U" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Daftar Montir" << endl;
        cout << "2. Daftar Mobil" << endl;
        cout << "3. Perbaikan/Service" << endl;
        cout << "4. Reward" << endl;

        cout << "Pilih menu : ";
        cin >> menu;

        if(menu == 1)
        {
            cout<< "1. Daftar Montir " << endl;
            cout<< "2. Rekrut Montir " << endl;
            cout<< "3. Pecat Montir " << endl;
            cout << "Pilih menu : ";
            cin >> rekmon;
            if(rekmon == 1)
            {
                cout<<"==============="<<endl;
                cout<<"Montir khusus untuk mobil sport adalah montir aufar"<<endl;
                printInfo(Montir);
                cout<<"==============="<<endl;
            }
            else if (rekmon ==2 )
            {
                cout << "Masukkan nama montir : ";
                cin >> input;
                while(findElm2(Montir, input) != NULL)
                {
                    cout << "Nama montir tersebut sudah ada!" << endl;
                    cout << "Masukkan nama montir : ";
                    cin >> input;
                }
                insertFirst(Montir, alokasi1(input));
                printInfo(Montir);
            }
            else if(rekmon == 3)
            {
                cout << "|| Mobil sebelum dipecat || "<<endl;
                printRelasi(relasi, Montir);
                deletefirst(relasi, Montir);
                cout << "|| Montir setelah dipecat || "<<endl;
                printRelasi(relasi, Montir);
            }
        }
        else if (menu == 2)
        {
            cout<< "1. Daftar Mobil " << endl;
            cout<< "2. Mobil Datang " << endl;
            cout<< "3. Hapus Mobil " << endl;
            cout << "Pilih menu : ";
            cin >> rekbil;
            if(rekbil == 1)
            {
                cout<<"==============="<<endl;
                printInfo(Mobil);
                cout<<"==============="<<endl;
            }
            else if (rekbil ==2)
            {
                cout << "Masukkan merek mobil : ";
                cin >> input;
                while(findElm3(Mobil, input) != NULL)
                {
                    cout << "Nama mobil tersebut sudah ada!" << endl;
                    cout << "Masukkan merek mobil : ";
                    cin >> input;
                }
                insertFirst(Mobil, alokasi2(input));
                printInfo(Mobil);
            }
            else if(rekbil == 3)
            {
                cout << "|| Mobil sebelum diperbaiki || "<<endl;
                printRelasi(relasi, Montir);
                disconnect(relasi, "avanza", "rizki");
                disconnect(relasi, "civic", "aufar");
                disconnect(relasi, "lambo", "aufar");
                cout << "|| Mobil setelah diperbaiki || "<<endl;
                printRelasi(relasi, Montir);
            }
        }
        else if(menu==3)
        {
            cout<< "1. Daftar Bengkel " << endl;
            cout<< "2. Service " << endl;
            cout << "Pilih menu : ";
            cin >> serv;
            if(serv == 1)
            {
                cout<<"==============="<<endl;
                printRelasi(relasi, Montir);
                cout<<"==============="<<endl;
            }
            else if(serv == 2)
            {
                cout<<"Montir khusus untuk mobil sport adalah montir aufar"<<endl;
                cout<<"Masukan Nama Mobil :";
                cin>> A;
                while(findElm3(Mobil, A) == NULL)
                {
                    cout<<"Mobil Belum Didaftarkan, harap daftarkan terlebih dahulu"<<endl;
                    cout<<"di menu daftar mobil, terima kasih"<<endl;
                    cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
                    cout<<"Masukan nama mobil : ";
                    cin>>A;
                }
                insertFirst(relasi, alokasibeng(findElm3(Mobil, A), findElm2(Montir, B)));

                cout<<"Dengan Montir Siapa Yang Anda Ingingkan : ";
                cin>> B;
                while(findElm2(Montir, B) == NULL)
                {
                    cout<<"Montir Belum Didaftarkan, harap daftarkan terlebih dahulu"<<endl;
                    cout<<"di menu daftar montir, terima kasih"<<endl;
                    cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
                    cout<<"Masukan nama montir : ";
                    cin>>B;
                }
                insertFirst(relasi, alokasibeng(findElm3(Mobil, A), findElm2(Montir, B)));
                printRelasi(relasi, Montir);
            }

        }
        else if(menu==4)
        {
            cout<< "1. Montir Yang Paling Banyak Memperbaiki Mobil" << endl;
            cout<< "2. Mobil yang pernah diperbaiki oleh montir tertentu " << endl;
            cout<< "3. Mobil Yang Pernah diperbaiki lebih dari satu montir " << endl;
            cout << "Pilih menu : ";
            cin >> sear;
            if(sear == 1)
            {
                addressbengkel Q = first(relasi);
                if (Q == NULL)
                {
                    cout << "Belum ada montir yang bekerja" << endl;
                }
                else
                {
                    addressbengkel P;
                    string x;
                    addressbengkel Z;
                    int jumlah = 0;
                    do
                    {
                        int i = 1;
                        P = next(Q);
                        x = info(child(Q));
                        do
                        {
                            if (x == info(child(Q)))
                            {
                                i++;
                            }
                            P = next(P);
                        }
                        while (P != first(relasi));
                        if (i > jumlah)
                        {
                            Z = Q;
                        }
                        jumlah = i;
                        Q = next(Q);
                    }
                    while(Q != first(relasi));
                    cout << "Montir terbanyak memperbaiki: ";
                    cout << info(child(Z)) << endl << endl;
                }
            }
            else if (sear == 2)
            {
                cout << "Menampilkan mobil dengan montir khusus: " << endl;
                addressmontir p = first(Montir);
                int j = 1;
                j++;
                while(p != NULL)
                {
                    int i = 0;
                    addressbengkel q = first(relasi);
                    do
                    {
                        if (q != NULL && child(q) == p)
                        {
                            i++;
                            if(i == 1)
                            {
                                cout << info(parent(q));
                            }
                        }

                    }
                    while(q != first(relasi) && info(child(q)) == "aufar");
                    p = next(p);
                }
                cout << endl;
            }
            else if (sear == 3)
            {
                addressbengkel Q = first(relasi);
                if (Q == NULL)
                {
                    cout << "Tidak ada mobil yang diperbaiki lebih dari satu montir" << endl;
                }
                else
                {
                    addressbengkel P;
                    addressbengkel Z;
                    string M;
                    int jumlah = 0;
                    do
                    {
                        int i = 1;
                        P = next(Q);
                        M = info(parent(Q));
                        do
                        {
                            if (M == info(parent(Q)))
                            {
                                i++;
                            }
                            P = next(P);
                        }
                        while (P != first(relasi));
                        if (i > jumlah)
                        {
                            Z = Q;
                        }
                        jumlah = i;
                        Q = next(Q);
                    }
                    while(Q != first(relasi));
                    cout << "Mobil yang diperbaiki lebih dari satu montir : ";
                    cout << info(parent(Z)) << endl << endl;
                }
            }
        }
    }
    return 0;
}
