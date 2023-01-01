#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

#define infoM(p) p -> infoM
#define nextJur(p) p -> nextJur
#define firstM(m) (m.firstM)
#define infoJur(q) q -> infoJur
#define nextM(q) q -> nextM
#define Mrd(q) q -> Mrd
#define firstJur(Jur) (Jur.firstJur)


struct Murid {
    string nama;
    string namaJurusan;
    int NISN;
};

struct Jurusan {
    string namaJur;
    int kelas;
};

typedef Murid infotypeM;
typedef struct ElmMurid *adrM;
typedef Jurusan infotypeJur;
typedef struct ElmJur *adrJur;

struct ElmMurid {
    infotypeM infoM;
    adrM nextM;
};

struct ElmJur{
    infotypeJur infoJur;
    adrM Mrd;
    adrJur nextJur;
};

struct ListMurid {
    adrM firstM;
};

struct ListJurusan {
    adrJur firstJur;
};

void createlistParent(ListJurusan &LJ);
adrJur createParent(infotypeJur infoJur);
void createlistChild(ListMurid &LM);
adrM createChild(infotypeM infoM);
void addParent(ListJurusan &LJ, adrJur Jurusan);
void showAllDataParent(ListJurusan LJ);
void DeleteParentsAndChild(ListJurusan &LJ, adrJur &Jurusan, string namaJ, int kelas);
adrJur findParent(ListJurusan LJ, string namaJur);
void addChild(ListJurusan &LJ, ListMurid &LM, adrM M, string namaJur);
void showAllData(ListJurusan LJ);
adrM findChild(ListMurid LM, string namaJur, string nama, ListJurusan LJ);
void deleteChild(ListMurid &LM, string namaJur, int kelas, ListJurusan &LJ, adrM &Murid);
int countchild(ListJurusan LJ, string namaJur);

int Select_Menu();

#endif // TUBES_H_INCLUDED
