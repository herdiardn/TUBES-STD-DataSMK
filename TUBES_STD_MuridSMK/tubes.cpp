#include"tubes.h"

void createlistParent(ListJurusan &LJ){
    firstJur(LJ) = NULL;
}

adrJur createParent(infotypeJur infoJur){
    adrJur J = new ElmJur;
    infoJur(J) = infoJur;
    nextJur(J) = NULL;
    Mrd(J) = NULL;

    return J;
}

void createlistChild(ListMurid &LM){
    firstM(LM) = NULL;
}

adrM createChild(infotypeM infoM){
    adrM M = new ElmMurid;
    infoM(M) = infoM;
    nextM(M) = NULL;
    return M;
}

void addParent(ListJurusan &LJ, adrJur Jurusan){
    if(firstJur(LJ) == NULL){
        firstJur(LJ) = Jurusan;
        nextJur(Jurusan) = firstJur(LJ);
    } else {
        adrJur J = firstJur(LJ);
        while(nextJur(J) != firstJur(LJ)){
            J = nextJur(J);
        }
        nextJur(J) = Jurusan;
        nextJur(Jurusan) = firstJur(LJ);
    }
}

void showAllDataParent(ListJurusan LJ){
    adrJur J;
    if(firstJur(LJ) == NULL){
        cout << "Tidak ada Jurusan" << endl;
    } else {
        J = firstJur(LJ);
        cout << infoJur(J).namaJur << " " << infoJur(J).kelas << endl;
        J = nextJur(J);
        while(J != firstJur(LJ)){
            cout << infoJur(J).namaJur << " " << infoJur(J).kelas << endl;
            J = nextJur(J);
        }
    }
}

adrJur findParent(ListJurusan LJ, string namaJur){
    adrJur J;
    J = firstJur(LJ);
    if(infoJur(J).namaJur == namaJur){
            return J;
        }
        J = nextJur(J);
    while(J != firstJur(LJ)){
        if(infoJur(J).namaJur == namaJur){
            return J;
            break;
        }
        J = nextJur(J);
    }if(J == NULL){
        return J;
        cout << "Jurusan tersebut tidak ada" << endl;
    }
}

void addChild(ListJurusan &LJ, ListMurid &LM, adrM M, string namaJur){
    adrJur J;
    adrM M1, M2;

    J = findParent(LJ, namaJur);
    if(Mrd(J) == NULL){
         Mrd(J) = M;
        if(firstM(LM) == NULL){
            firstM(LM) = M;
        }else{
            M1 = firstM(LM);
            while(nextM(M1) != NULL){
                M1 = nextM(M1);
            }
            nextM(M1) = M;
        }
    } else {
        M2 = Mrd(J);
        while(nextM(M2) != NULL){
            M2 = nextM(M2);
        }
        nextM(M) = nextM(M2);
        nextM(M2) = M;
    }
}

void DeleteParentsAndChild(ListJurusan &LJ, adrJur &Jurusan, string namaJur, int kelas){
    adrJur R;
    R = findParent(LJ, namaJur);

    if(firstJur(LJ) == NULL){
        cout << "Jurusan sudah kosong" << endl;
    } else if ( R == firstJur(LJ)) {
        firstJur(LJ) = nextJur(R);
        nextJur(R) = NULL;
    } else {
        //R = findParent(LJ, namaJur);
        Jurusan = firstJur(LJ);
        while(nextJur(Jurusan) != R) {
            Jurusan = nextJur(Jurusan);
        }
        if(nextJur(R) == firstJur(LJ)) {
            nextJur(Jurusan) = firstJur(LJ);
            R = NULL;
        }else{
            nextJur(Jurusan) = nextJur(R);
            nextJur(R) = NULL;
            R = NULL;
        }
    }
}

void showAllData(ListJurusan LJ){
    adrJur J;
    adrM M;

    cout << "========== Data Jurusan dan Muridnya ===========" << endl;
    J = firstJur(LJ);
    cout << "Jurusan :" << endl;
    cout << infoJur(J).namaJur << " " << infoJur(J).kelas << endl;
    if(Mrd(J) != NULL){
        M = Mrd(J);
        cout << "Daftar Murid :" << endl;
        while(M != NULL){
            if(infoM(M).namaJurusan == infoJur(J).namaJur){
                cout << infoM(M).nama << " " << infoM(M).NISN << endl;
            }

            M = nextM(M);
        }
        cout << endl;
    }
    J = nextJur(J);
    while(J != firstJur(LJ)){
        cout << "Jurusan :" << endl;
        cout << infoJur(J).namaJur << " " << infoJur(J).kelas << endl;
        if(Mrd(J) != NULL){
            M = Mrd(J);
            cout << "Daftar Murid :" << endl;
            while(M != NULL){
                if(infoM(M).namaJurusan == infoJur(J).namaJur){
                    cout << infoM(M).nama << " " << infoM(M).NISN << endl;
                }
                cout << endl;
                M = nextM(M);
            }
        }
        J = nextJur(J);
    }
}

adrM findChild(ListMurid LM, string namaJur, string nama, ListJurusan LJ)
{
    adrM M;
    adrJur J;

    J = findParent(LJ, namaJur);
    M = Mrd(J);
    while(M != NULL){
        if(infoM(M).nama == nama && infoJur(J).namaJur == infoM(M).namaJurusan){
            return M;
            break;
        }
        M = nextM(M);
    }
    if( M == NULL){
        return M;
    }
}

void deleteChild(ListMurid &LM, string namaJur, string nama, int kelas, ListJurusan &LJ, adrM &M){
    adrJur J;
    adrM Murid;

    J = findParent(LJ, namaJur);
    M = findChild(LM,namaJur, nama, LJ);

    Murid = Mrd(J);
    if(Murid == M){
        if(nextM(M) == NULL){
            Mrd(J) = NULL;
        }else{
            Mrd(J) = nextM(Mrd(J));
        }
    } else {
        while(Murid != NULL) {
            if(infoM(nextM(Murid)).namaJurusan == infoM(M).namaJurusan){
                if(nextM(M) == NULL){
                    nextM(Murid) = NULL;
                    break;
                }else{
                    Mrd(J) == Murid;
                    break;
                }
            }
            Murid = nextM(Murid);
        }
    }
}

int countchild(ListJurusan LJ, string namaJur){
    adrJur J;
    adrM M;
    int i = 0;

    J = findParent(LJ, namaJur);
    if(Mrd(J) != NULL){
        M = Mrd(J);
        while(M!=NULL){
            if(infoM(M).namaJurusan == infoJur(J).namaJur){
                i++;
            }
            M = nextM(M);
        }
    }
    return i;
}

int Select_Menu(){

    int pilihan;

    cout<<"=====MENU====="<<endl;
    cout<<"1. Menambah N Jurusan di SMK"<<endl;
    cout<<"2. Menambah N Murid dan Menghubungkan ke Jurusan"<<endl;
    cout<<"3. Menghapus Jurusan dan Murid"<<endl;
    cout<<"4. Menampilkan Semua Jurusan"<<endl;
    cout<<"5. Menampilkan Semua Jurusan dan Murid"<<endl;
    cout<<"6. Mencari Jurusan N"<<endl;
    cout<<"7. Mencari Murid N"<<endl;
    cout<<"8. Menghitung Jumlah Murid yang Mengambil Jurusan N"<<endl;
    cout<<"9. Hapus Murid N pada Jurusan M"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilihan;
    return pilihan;
}
