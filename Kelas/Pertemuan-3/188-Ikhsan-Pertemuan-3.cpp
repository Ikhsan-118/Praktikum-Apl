#include <iostream>
using namespace std;


int main() {
    
    struct Nilai
    {
        int uts;
        int uas;        
        
    };

    struct Data
    {
        string nama;
        long double nim;
        
    };

    struct Mahasiswa
    {
        Data data;
        Nilai nilai;
    };

    Mahasiswa mhs;
    mhs.data.nama = "Ikhsan";
    mhs.data.nim = 2409106118;
    mhs.nilai.uts = 99;
    mhs.nilai.uas = 100;

    cout << "Nama: " << mhs.data.nama << endl;
    cout << "NIM: " << mhs.data.nim << endl;
    cout << "Nilai UTS: " << mhs.nilai.uts << endl;
    cout << "Nilai UAS: " << mhs.nilai.uas << endl;

    return 0;
}