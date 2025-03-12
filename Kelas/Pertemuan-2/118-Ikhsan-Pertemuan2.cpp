#include <iostream>
using namespace std;

#define MAX_BUAH 100 // Ukuran maksimum array buah
#define INFO 2 // Kolom untuk menyimpan informasi tambahan (misal: nama dan

int main() {
    int panjang = 0; // Jumlah elemen saat ini
    string buah[MAX_BUAH][INFO]; // Array 2 dimensi

    int pilihan, index;
    do {
        system("clear");
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            // Tampilkan semua buah
            break;
        case 2:
            // Tambah buah
            break;
        case 3:
            // Ubah buah
            break;
        case 4:
            // Hapus buah
            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);
            return 0;
            }

// int main() {
    // int mahasiswa[2];
    // int mahasiswa[2];

    // string nama[4] = {"Ikhsan", "Rifqi", "Rizky"};

    // int angka[5];
    // angka[0] = 10;
    // angka[1] = 19;
    // angka[2] = 30;
    // angka[3] = 40;
    // angka[4] = 50;
    // int ukuran = sizeof(angka) / sizeof(angka[0]);

    // for (int i = 0; i < 5; i++) {
    //     cout << angka[i] << endl;
    // }

    // for (string y : nama) {
    //     cout << y << endl;
    // }

    // cout << nama[0] << endl;   
    // cout << angka[2] << endl;
    // int ukuran = sizeof(angka) / sizeof(angka[0]);

    // cout << "Bnyak elemen array angka adalah? " << ukuran << endl;

//     int matrix[3][3][3] = {
//     {
//         {1, 2, 3},
//         {3, 4, 5},
//         {6, 7, 8}
//     },{
//         {11, 12, 13},
//         {13, 14, 15},
//         {16, 17, 18}
//     },{
//         {19, 20, 21},
//         {22, 23, 24},
//         {26, 27, 28}

//     }
// };

//     cout << matrix[0][1][2] << endl;
//     cout << matrix[1][1][2] << endl;
//     cout << matrix[1][0][2] << endl;
//     cout << matrix[0][0][2] << endl;

// }