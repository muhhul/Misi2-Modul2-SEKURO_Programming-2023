#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void pemilikToko();
void pelanggan();
void menu();
void beli();
void pembatas();
string listmenu[]={"Indomie Polos","Indomie Telur","Indomie Campur","Nasi Goreng","Nasi Mawud","Air Putih","Es Teh Manis","Es Kubis","Es Gooday","Es Soda Gembira"};
int harga[]={6000,9000,12000,10000,15000,1000,4000,6000,5000,8000};
int stok[]={15,12,8,15,12,20,15,10,10,7};
string listpelanggan[100];
string listbelimenu[100][1000];
int jumlahbeli[100][1000];
int hargabeli[100][1000];
int totalharga[100];
int jumlahpesanan[100];
int numberpelanggan=0;
int numberpesanan=0;
string nama;
string input;
bool buy=false;

int main(){
    pemilikToko();
    return 0;
}
void menu(){
    system("cls");
    cout<<"Menu Warung Kang Roger"<<endl;
    pembatas();
    cout<<"ID Menu\tNama Menu\t\tKategori\tHarga\tStok"<<endl;
    for(int i=0; i<5;i++){
        cout<<i+1<<"\t"<<listmenu[i]<<"\t\tMakanan\t\t"<<harga[i]<<"\t"<<stok[i]<<endl;
    }
    for(int i=5; i<10;i++){
        cout<<i+1<<"\t"<<listmenu[i]<<"\t\tMinuman\t\t"<<harga[i]<<"\t"<<stok[i]<<endl;
    }
    pembatas();
    system("pause");
    bool m = true;
    if(m){
        pelanggan();
    }
}
void pelanggan(){
    cout<<"Halo "<<nama<<" sekarang kamu berada pada tampilan awal Warung Kang Roger"<<endl;
    cout<<"1. Melihat menu"<<endl;
    cout<<"2. Keluar warung"<<endl;
    cout<<"3. Keranjang pembelian"<<endl;
    int chose;
    cout<<"Masukkan angka yang ingin anda lakukan: ";
    cin>>chose;
    if(chose==1){
        menu();
    }else if(chose==2){
        numberpelanggan++;
        pemilikToko();
    }else if(chose==3){
        beli();
    }else{
        cout<<"Maaf input anda salah, silahkan ulangi dengan benar"<<endl;
        system("pause");
        bool c=true;
        while(c){
            system("cls");
            cout<<"Halo "<<nama<<" sekarang kamu berada pada tampilan awal Warung Kang Roger"<<endl;
            cout<<"1. Melihat menu"<<endl;
            cout<<"2. Keluar warung"<<endl;
            cout<<"3. Keranjang pembelian"<<endl;
            cout<<"Masukkan angka yang ingin anda lakukan: ";
            cin>>chose;
            if(chose==1){
                menu();
                c=false;
            }else if(chose==2){
                pemilikToko();
                c=false;
            }else if(chose==3){
                beli();
                c=false;
            }else{
                cout<<"Maaf input anda salah, silahkan ulangi dengan benar"<<endl;
                system("pause");
            }
        }
    }
};
void pemilikToko(){
    system("cls");
    cout<<"Halo kamu adalah Pemilik Toko"<<endl;
    cout<<"Apakah kamu ingin membuka warung?(Y/N) ";
    cin>>input;
    if(input=="Y" || input=="y"){
        system("cls");
        cout<<"Halo selamt datang di Warung Kang Roger"<<endl;
        cout<<"silahkan masukkan nama anda: ";
        cin>>nama;
        listpelanggan[numberpelanggan]=nama;
        totalharga[numberpelanggan]=0;
        numberpesanan=0;
        system("cls");
        pelanggan();
    }else if(input=="N" || input=="n"){
        system("cls");
        if(buy){
            cout<<"Riwayat penjualan Warung Kang Roger"<<endl;
            pembatas();
            cout<<"Nama Pelanggan\t\tNama Menu\t\tJumlah\tHarga"<<endl;
            pembatas();
            for(int i=0;i<numberpelanggan;i++){
                if(totalharga[i]>0){
                    for(int j=0;j<jumlahpesanan[i];j++){
                        if(j==0){
                            cout<<listpelanggan[i]<<"\t\t\t"<<listbelimenu[i][j]<<"\t\t"<<jumlahbeli[i][j]<<"\t"<<hargabeli[i][j]<<endl;
                        }else{
                            cout<<" "<<"\t\t\t"<<listbelimenu[i][j]<<"\t\t"<<jumlahbeli[i][j]<<"\t"<<hargabeli[i][j]<<endl;
                        }
                    }
                    cout<<"Total harga: "<<totalharga[i]<<endl;
                    pembatas();
                    cout<<""<<endl;
                }
            }
        }else{
            cout<<"Tidak Ada Penjualan"<<endl;
        }

    }else{
        cout<<"Maaf input anda salah, silahkan ulangi dengan benar"<<endl;
        system("pause");
        bool p = true;
        if(p){
            pemilikToko();
        }
    }
};

void beli(){
    cout<<"Halo "<<nama<<" anda berada pada keranjang pembelian Warung Kang Roger"<<endl;
    pembatas();
    bool b=true;
    while (b){
        cout<<"Apakah anda ingin membeli?(Y/N) ";
        cin>>input;
        if(input=="Y" || input=="y"){
            int temp;
            int temp2;
            cout<<"Masukkan id menu yang ingin di beli ";
            cin>>temp;
            if(temp>10){
                cout<<"Maaf id menu tidak ditemukan, silahkan ulangi pembelian"<<endl;
            }else{
                cout<<"Masukkan jumlah yang ingin di beli ";
                cin>>temp2;
                if(temp2<=stok[temp-1]){
                    listbelimenu[numberpelanggan][numberpesanan]=listmenu[temp-1];
                    hargabeli[numberpelanggan][numberpesanan]=harga[temp-1];
                    jumlahbeli[numberpelanggan][numberpesanan]=temp2;
                    totalharga[numberpelanggan]=totalharga[numberpelanggan]+(temp2*hargabeli[numberpelanggan][numberpesanan]);
                    stok[temp-1]=stok[temp-1]-temp2;
                    numberpesanan++;
                    jumlahpesanan[numberpelanggan]++;
                    buy=true;
                }else{
                    cout<<"Maaf stok barang tidak mencukupi, silahkan ulangi pembelian"<<endl;
                }
            }
        }else if(input=="N" || input=="n"){
            cout<<"Maka total harga keseluruhan yang harus anda bayar: "<<totalharga[numberpelanggan]<<endl;
            system("pause");
            b=false;
        }else{
            cout<<"Maaf input anda salah, silahkan ulangi dengan benar"<<endl;
        }
        pembatas();
    }
    system("cls");
    pelanggan();
}

void pembatas(){
    for(int i=0;i<100;i++){
        cout<<"-";
    }
    cout<<""<<endl;
}