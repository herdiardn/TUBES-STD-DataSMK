#include "tubes.h"
#include <iostream>

using namespace std;

int main() {

    ListMurid LM;
    ListJurusan LJ;
    infotypeM infoM;
    infotypeJur infoJur;
    adrJur J;
    adrM M;
    int pilihan, t, total;
    string namaJur, nama;
    int NISN, kelas;
    char subMenu;

    createlistChild(LM);
    createlistParent(LJ);

    pilihan = Select_Menu();
    while (pilihan!=0){
        switch(pilihan){
        case 1:
            cout<<" Banyaknya Jurusan yang ditambahkan : ";
            cin>>total;
            for(t=1 ; t <= total ; t++){
                cout<<"Masukkan Nama Jurusan : ";
                cin>>infoJur.namaJur;
                cout<<"Masukkan kelas : ";
                cin>>infoJur.kelas;

                J = createParent(infoJur);
                addParent(LJ, J);
            }
            break;
        case 2:
            cout<<"Berapa Murid yang akan Ditambahkan : ";
            cin>> total;
            for(t=1;t <= total ; t++){
                cout<<"Masukkan Nama Murid : ";
                cin>>infoM.nama;
                cout<<"Masukkan Jurusan Murid : ";
                cin>>infoM.namaJurusan;
                cout<<"Masukkan NISN Murid : ";
                cin>>infoM.NISN;

                M = createChild(infoM);
                cout<<" Jurusan yang diambil : ";
                cin>>namaJur;
                addChild(LJ, LM, M, namaJur);
            }
            break;
        case 3:
            cout<<"Masukkan Jurusan yang ingin dihapus : ";
            cin>>namaJur;
            //DeleteParentsAndChild(LJ, Jurusan, namaJur, kelas);
            break;
        case 4:
            showAllDataParent(LJ);
            break;
        case 5:
            showAllData(LJ);
            break;
        case 6:
            cout<<"Masukkan Nama Jurusan : ";
            cin>>namaJur;
            J = findParent(LJ, namaJur);
            cout<<infoJur(J).namaJur<< " " <<infoJur(J).kelas<<endl;
            break;
        case 7:
            cout<<"Masukkan Nama Murid : ";
            cin>> nama;
            cout<<"Masukkan Jurusan Murid : ";
            cin>>namaJur;
            M = findChild(LM, namaJur, nama, LJ);
            cout<<infoM(M).nama<<" "<<infoM(M).namaJurusan<<" "<<infoM(M).NISN<< endl;
            break;
        case 8:
            cout<<"Masukkan Jurusan : ";
            cin>>namaJur;
            cout<<"Jumlah Murid : "<<countchild(LJ, namaJur)<<endl;
            break;
        case 9:
            cout<<"Masukkan NISN Murid : ";
            cin>>NISN;
            cout<<"Masukkan Nama Jurusan : ";
            cin>>namaJur;
            //deleteChild(LM,namaJur, kelas, LJ, Murid);
            break;
        }
        cout<<"Kembali ke menu utama?(Y/N)";
        cin>>subMenu;
        if(subMenu=='Y'){
            pilihan = Select_Menu();
        }else{
            pilihan = 0;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;


//    cout << "Data Jurusan di SMK 1 KONTOLODON :" << endl;
//    infoJur.namaJur = "Teknik Komputer Jaringan";
//    infoJur.kelas = 12;
//    J = createParent(infoJur);
//    addParent(LJ, J);
//
//    infoJur.namaJur = "Akuntansi";
//    infoJur.kelas = 11;
//    J = createParent(infoJur);
//    addParent(LJ, J);
//
//    infoJur.namaJur = "Multimedia";
//    infoJur.kelas = 10;
//    J = createParent(infoJur);
//    addParent(LJ, J);
//
//    showAllDataParent(LJ);
//    cout << endl;
//
//    infoM.nama = "Syahran Syahputra";
//    infoM.NISN = 130221;
//    infoM.namaJurusan = "Teknik Komputer Jaringan";
//    M  =  createChild(infoM);
//    addChild(LJ, LM, M, "Teknik Komputer Jaringan");
//
//    infoM.nama = "Herdi Ardana";
//    infoM.NISN = 130271;
//    infoM.namaJurusan = "Akuntansi";
//    M  =  createChild(infoM);
//    addChild(LJ, LM, M, "Akuntansi");
//
//    infoM.nama = "Kamal Maula Azkha";
//    infoM.NISN = 130621;
//    infoM.namaJurusan = "Multimedia";
//    M  =  createChild(infoM);
//    addChild(LJ, LM, M, "Multimedia");
//
//    showAllData(LJ);

    cout << endl;

    return 0;
}
